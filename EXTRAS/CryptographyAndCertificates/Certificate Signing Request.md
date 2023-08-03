A Certificate Signing Request (CSR) is a block of encoded text that is given to a Certificate Authority (CA) when applying for an SSL (Secure Socket Layer) Certificate. It is typically generated on the server where the certificate will be installed and contains information that will be included in the certificate such as the organization name, common name (domain name), locality, and country. It also contains the public key that will be included in the certificate. A private key is also created at the same time but is not included in the CSR.

The Certificate Authority will use the CSR to create a certificate for the server that is uniquely linked to the private key that was created with the CSR. This unique linkage ensures the security of the certificate and associated transactions.

Importantly, a CSR is needed when applying for an SSL certificate because it provides the necessary details to the Certificate Authority for creating the certificate. It's part of the process for creating a secure, encrypted connection between a web server and a client. The data within the CSR is also used to validate the entity requesting the certificate and to create the final SSL certificate.

#### Process
---

The process of obtaining an intermediate certificate involves the creation and exchange of a Certificate Signing Request (CSR) between the intermediate CA and the root CA. However, it's important to note that the CSR itself is not encrypted during this process.

Here's a more detailed explanation of the steps involved:

1. **Generating the CSR**:
    
    - The intermediate CA generates a Certificate Signing Request (CSR) containing information about the intermediate CA, including its public key, and the intended usage of the certificate (e.g., issuing certificates for end entities).
    - The private key associated with the public key in the CSR is kept securely on the intermediate CA's server and is not included in the CSR.
2. **Submitting the CSR to the Root CA**:
    
    - The intermediate CA submits the CSR to the root CA. The submission is usually done through a secure process, such as an online portal or direct communication between the CAs.
    - The root CA verifies the information in the CSR to ensure that the intermediate CA meets the necessary requirements for becoming a subordinate CA.
3. **Signing the Intermediate CA Certificate**:
    
    - After verifying the CSR, the root CA signs the intermediate CA's certificate using the root CA's private key. The signing process involves creating a digital signature using the root CA's private key, which is appended to the intermediate CA's certificate.
    - The intermediate CA's certificate includes its public key, identifying information, and the digital signature from the root CA.
4. **Receiving the Signed Certificate**:
    
    - The root CA sends back the signed intermediate CA certificate to the intermediate CA. The certificate is now trusted because it has been signed by the highly trusted root CA.
5. **Chain of Trust**:
    
    - When the intermediate CA issues certificates for end entities, such as websites, it includes its own intermediate CA certificate in the certificate chain. This creates a chain of trust: the client can verify the intermediate CA certificate using the root CA's public key (which is widely trusted), and then use the intermediate CA certificate to verify the authenticity of the end entity certificate.

In summary, the CSR is not encrypted during the process of obtaining an intermediate certificate. Instead, the CSR is used to generate a certificate request that is signed by the root CA, creating a certificate that is trusted by clients because it is linked to the root CA through the chain of trust. The certificate issued to the intermediate CA contains the intermediate CA's public key, identifying information, and the digital signature from the root CA.