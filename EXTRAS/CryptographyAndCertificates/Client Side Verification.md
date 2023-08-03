- [[#Process overview|Process overview]]
- [[#Signature Verification Details|Signature Verification Details]]

### Process overview
---

The validation step in the SSL/TLS handshake involves the client using the preinstalled root certificates to establish the chain of trust and verify the authenticity of the server's certificate. Here's how it works:

1. **Certificate Chain**: When the server sends its digital certificate to the client during the handshake, it also sends any necessary intermediate certificates (if applicable). These intermediate certificates form a chain between the server's certificate and a trusted root certificate.
    
2. **Certificate Chain Validation**: The client performs a chain of trust verification by checking each certificate in the chain, starting from the server's certificate and moving up to the root certificate. It ensures that each certificate is valid and has not expired.
    
3. **Root Certificates**: The client already has a set of trusted root certificates preinstalled in its trust store. These root certificates belong to well-known Certificate Authorities (CAs) and are used to establish trust in the certificates issued by these CAs.
    
4. **Verification Process**: The client checks the authenticity of each certificate in the chain using the following steps:
    
    a. [[#Signature Verification Details|Signature Verification]]**: The client verifies the digital signature of each certificate to ensure it was issued by the next certificate in the chain. It uses the public key of the issuing certificate to validate the signature.
    
    b. **Certificate Expiration**: The client checks the validity period of each certificate to ensure it has not expired. If a certificate is expired, it is considered invalid.
    
    c. **Revocation Checking (Optional)**: The client may also check the certificate revocation status to see if any of the certificates in the chain have been revoked by the issuing CA. This process involves checking Certificate Revocation Lists (CRLs) or using Online Certificate Status Protocol (OCSP) to obtain real-time revocation status.
    
    d. **Common Name (CN) Verification**: The client verifies that the Common Name (CN) or Subject Alternative Names (SANs) in the server's certificate match the server's hostname to prevent man-in-the-middle attacks.
    
5. **Chain Termination**: The chain validation continues until the client reaches a trusted root certificate in its preinstalled trust store. If the chain can be successfully validated up to a trusted root certificate, the client considers the server's certificate to be valid and trusted.
    
6. **Alerts and Warnings**: If any validation checks fail, the client may reject the connection or display a warning to the user indicating that the server's certificate cannot be trusted. The user can then decide whether to proceed with the connection or terminate it.
    

Once the client has successfully validated the server's certificate, it can proceed with the SSL/TLS handshake to establish an encrypted and secure connection with the server. The chain of trust ensures that the server's identity has been verified by a trusted CA, thereby providing assurance to the client that it is communicating with the intended and legitimate server.

###  Signature Verification Details
---

The purpose of signing certificates is to provide a means of verifying the authenticity and integrity of the certificate without needing to decrypt it.

Here's a simplified explanation of how the signing process works:

1. **Certificate Signing**: When a CA issues a certificate, it generates a cryptographic hash of the certificate's content (including the public key, subject information, validity dates, etc.).
    
2. **Signing Process**: The CA then encrypts the hash using its private key, creating a digital signature unique to that specific certificate.
    
3. **Signature Attachment**: The digital signature is appended to the certificate itself, along with information about the CA that issued the certificate. This entire package, including the certificate data and the digital signature, is what gets sent to the client during the SSL/TLS handshake.
    
4. **Verification**: Upon receiving the certificate, the client can use the CA's public key (which is preinstalled in the client's trust store) to decrypt the digital signature and obtain the original hash value.
    
5. **Hash Comparison**: The client then recalculates the hash of the received certificate's content (excluding the signature) using the same hash function that the CA used. If the recalculated hash matches the decrypted hash from the digital signature, the certificate is considered valid and authentic. If the hashes don't match, it indicates that the certificate has been tampered with or is not issued by the claimed CA.

Let's go into more detail about the signature verification step during the certificate chain validation in an SSL/TLS handshake:

1. **Certificates and Digital Signatures**: In the SSL/TLS handshake, the server sends its digital certificate to the client, and this certificate contains the server's public key, along with other information, such as the certificate's validity period and the server's identity (usually in the form of a Common Name or Subject Alternative Names).
    
2. **Certificate Issuance**: The server's certificate is typically issued by an intermediate certificate authority (CA), which, in turn, has its own certificate issued by a higher-level CA. This chain of certificates continues until reaching a trusted root certificate, which is the ultimate authority in the certificate hierarchy.
    
3. **Public Key Infrastructure (PKI)**: The foundation of the certificate verification process lies in the concept of Public Key Infrastructure (PKI). In PKI, certificates are signed using digital signatures. A digital signature is generated using the private key of the signing entity (e.g., the CA) and can only be verified using the corresponding public key.
    
4. **Digital Signature Verification**: To verify the digital signature of a certificate, the client performs the following steps:
    
    a. **Retrieve Issuer's Public Key**: The client extracts the issuer's public key from the issuer's certificate, which was sent as part of the certificate chain by the server.
    
    b. **Extract Signature**: The client extracts the digital signature from the certificate being verified. This signature is typically found in the "Signature" field of the certificate.
    
    c. **Hash Function**: The client then applies a hash function (e.g., SHA-256) to the certificate's content, excluding the signature itself. This hash represents a unique fingerprint of the certificate data.
    
    d. **Signature Decryption**: Using the issuer's public key, the client decrypts the digital signature to obtain a value that should match the hash obtained in the previous step. This step uses the mathematics of asymmetric encryption to reverse the signing process.
    
    e. **Signature Comparison**: The client compares the decrypted signature with the computed hash of the certificate's content. If the two values match, it indicates that the signature is valid, and the certificate has not been tampered with since it was signed by the issuer.
    
5. **Chain of Trust**: The verification process continues for each certificate in the chain, from the server's certificate up to the trusted root certificate. Each certificate in the chain is validated using its respective issuer's public key.
    
6. **Trusted Root Certificate**: The process is complete when the client successfully verifies the signature of the server's certificate using the public key of the issuing certificate. If the chain can be traced back to a trusted root certificate, the server's certificate is considered valid and trusted.
    

This digital signature verification process ensures the integrity and authenticity of the certificates in the chain. If the signatures do not match or the chain cannot be validated up to a trusted root certificate, the client will not consider the server's certificate valid, and the SSL/TLS handshake will not proceed, preventing potential security risks.