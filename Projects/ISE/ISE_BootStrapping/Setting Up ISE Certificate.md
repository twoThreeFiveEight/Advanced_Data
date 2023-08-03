

#### Generate Certificates Signing Request
---
-  [Video about CSR. Check out 16:15 time stamp](https://www.youtube.com/watch?v=77N_tUc0-Ng)

- In [public key infrastructure](https://en.wikipedia.org/wiki/Public_key_infrastructure "Public key infrastructure") (PKI) systems, a **certificate signing request** (also **CSR** or **certification request**) is a message sent from an applicant to a [certificate authority](https://en.wikipedia.org/wiki/Certificate_authority "Certificate authority") of the [public key infrastructure](https://en.wikipedia.org/wiki/Public_key_infrastructure "Public key infrastructure") in order to apply for a [digital identity certificate](https://en.wikipedia.org/wiki/Public_key_certificate "Public key certificate").
	- [PKI Video](https://www.youtube.com/watch?v=i-rtxrEz_E8) 
	- [Wiki Certificate Signing Request](https://en.wikipedia.org/wiki/Certificate_signing_request) / [Obisidian CSR](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FCertificate%20Signing%20Request)
	- Certificate Signing Request (CSR) is a block of encoded text that is given to a Certificate Authority (CA) when applying for an SSL (Secure Socket Layer) Certificate.
		- The Certificate Authority will use the CSR to create a certificate for the server that is uniquely linked to the private key that was created with the CSR.

 - When you generate a Certificate Signing Request (CSR), the key pair (comprising of a public key and a private key) is created locally, on your own system. The CSR itself contains the public key and some additional identifying information about the entity requesting the certificate, such as a domain name or organization details.

	After you generate the CSR, you would send it to the Certificate Authority (CA). The CSR does not contain your private key; you keep that secure. When the CA receives your CSR, it will create a certificate for you, sign it using their private key, and send it back. You then install that certificate on your system, and it pairs up with your private key.

	The private key never leaves your system during this process; it's only the CSR that gets sent to the CA, and the certificate that gets sent back from the CA. The private key should always be kept secure and private; if anyone else gets access to it, they could potentially impersonate your server.

	Therefore, no request for key creation is sent to the CA, and no key is sent back. The key pair is generated and resides on your local system, where the private key should remain. Only the CSR, containing the public key and identifying information, is sent to the CA for certificate creation and signing.

- The Certificate Signing Request (CSR) contains the following information:

1. **Public Key**: The CSR includes the public key of the entity (server, device, etc.) requesting the certificate. This is the key that will be embedded in the certificate by the Certificate Authority (CA) and used for encrypting data and validating signatures.
    
2. **Subject**: This includes details about the entity for which the certificate is being requested. For a server, this might include the Fully Qualified Domain Name (FQDN), and for an organization, it might include details such as the organization's name, location (city, state, country), and so on. These details are used to identify the owner of the certificate.
    
3. **Signature Algorithm**: This is the algorithm used to create a digital signature of the CSR. This is used by the CA to verify the CSR hasn't been tampered with during transit.
    
4. **Signature**: This is a digital signature created by hashing the CSR data and then encrypting the hash with the private key of the entity requesting the certificate. This ensures the integrity of the CSR and proves that it was created by an entity that holds the private key corresponding to the public key in the CSR.
    

So, in essence, the CSR contains the public key and the digital signature, which itself is a hashed version of the CSR data (including the public key), encrypted with the private key.

###### Generation steps in ISE GUI
----
###### Steps:
- In ISE Navigate to ***Administration > Certificates > Certificate Signing Requests > Generate Certificate Signing Request***

![[Pasted image 20230724132252.png]]
figure 0-1 (shows location of Certificate Signing request in ISE Version 2.7)

- Information for the ISE Certificate

![[Pasted image 20230724133736.png]]
Figure 0-2

- CN (Common Name)
	- Normally domain of trusted source. In the example 
![[Screenshot 2023-07-25 143909.png]]

##### Receiving the CAs certificate
---

- In new browser tab. Connect to domain name of you Windows Active Directory Certificate Authority web page.
	- Below was the domain name for my CA 
		- https://ad-dc.ise.astontech.com/certsrv

- Click Download a CA certificate, certificate chain, or CRL

![[Pasted image 20230724153236.png]]

![[Pasted image 20230728143038.png]]

- The "***Current [ise-AD-DC-CA]***"  is the Root Cert that the AD-DC server has created.

![[Pasted image 20230728135910.png]]


##### Submit a Certificate Request for signing from CA
---
- Now we will have our Cert signed by the CA
- Navigate to the main certsrv page. Click on ***Request Certificate*** 

![[Pasted image 20230724153236.png]]

- We will need to submit an ***advanced certificate request***

![[Pasted image 20230728142957.png]]

- Copy and paste our CSR that we generated locally inside ISE so the CA can sign it with its PRIVATE key and we can verify it by decrypting the encrypted cert with the CAs public key.

![[Pasted image 20230728142543.png]]

[pxGrid](https://developer.cisco.com/docs/pxgrid/#!what-is-pxgrid) == Cisco pxGrid provides a unified framework that enables ecosystem partners to integrate to pxGrid once, then share context either unidirectionally or bidirectionally with many platforms without the need to adopt platform-specific APIs

- Download the Signed Certificate as [Base 64](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FBase%2064%20Encoding)

![[Pasted image 20230728141620.png]]


##### Import the Root CA Cert into ISE trusted Certificates (Avoids Authentication warnings)
---

- On ISE website GUI navigate to  ***Administration > Certificates > Trusted Certificates*** 
- Select ***import***

![[Pasted image 20230728151831.png]]

- Click browse and install the CAs Root cert created in section [[#Receiving the CAs certificate]]

![[Pasted image 20230728152214.png]]


- Select the boxes that apply. If this cert is trusted and you wish to use for all authentication purposes then click all boxes as the option. CLICK submit.

![[Pasted image 20230728152739.png]]

##### Bind The ***"Signed CSR cert"*** to our original CSR 
---
- Navigate to  ***Administration > Certificates > Certificate Signing Requests*** inside ISE web GUI.
- Click on the CSR that we generated in our first step.
- Click ***Bind Certificate*** 
- Name the Cert 
- Select boxes you wish to use the CERT with. 
	- Only one cert can be used per instance of the selections. This means if another CERT is already being used for the selections it will override the other cert and attach this one we are binding now. If this is OK then select ok on the warning.

- System will most likely restart after this step.

![[Pasted image 20230728153707.png]]


##### Checking the Validity
---
- Notice the CA is the ***ise-AD-DC-CA*** server.

![[Pasted image 20230731145542.png]]
![[Pasted image 20230731145516.png]]
###### The CSR Juggle
- Generate the CSR
- Receive the CAs Root certificate to obtain the CAs public key
- Get the CRS signed from the CA using the CAs Private key
- Import key to ISE trusted certificates.
- bind our newly signed cert to our CSR  (This step decrypts the CAs certificate with the newly acquired public key)


1. **Generate the CSR**: To obtain an SSL/TLS certificate from a CA, you first need to create a CSR. The CSR contains information about your organization and the domain name for which you want to obtain the certificate. It also includes a public key that will be used to encrypt data.
    
2. **Submit the CSR to the CA**: Once the CSR is generated, you need to submit it to a trusted CA for verification. The CA will review the CSR and verify the ownership of the domain and the information provided in the CSR.
    
3. **CA Verification**: The CA performs various checks to validate the domain ownership and organization information provided in the CSR. This process ensures that the certificate is only issued to the legitimate owner of the domain.
    
4. **Receive the Certificate**: After successful verification, the CA issues an SSL/TLS certificate. This certificate contains the domain name, the public key from the CSR, and other information about the certificate, such as the issuer's details and the certificate's expiration date.
    
5. **Binding the Certificate to the CSR**: At this point, the CA's system automatically links the issued certificate to the original CSR. This means that the certificate is now associated with the specific public key that was generated when the CSR was created. The binding process ensures that the certificate and the private key (associated with the public key in the CSR) can work together correctly to secure communication for the domain.
    
6. **Install the Certificate**: Once the certificate is bound to the CSR, you need to install it on your web server or application. During the installation process, you usually combine the certificate with the private key (which was generated when the CSR was created) to complete the certificate chain. This allows the server to use the certificate for secure connections.