- [[#ISE|ISE]]
- [[#Nodes|Nodes]]
- [[#Provides Zero Trust|Provides Zero Trust]]
- [[#AAA server|AAA server]]
- [[#TACACS+|TACACS+]]
- [[#RADIUS (Remote Authentication Dial-In User Service)|RADIUS (Remote Authentication Dial-In User Service)]]
	- [[#RADIUS (Remote Authentication Dial-In User Service)#RADIUS Process|RADIUS Process]]
- [[#MAB (MAC Authentication Bypass)|MAB (MAC Authentication Bypass)]]
- [[#Difference between TACACS and RADIUS|Difference between TACACS and RADIUS]]
- [[#EAP Methods|EAP Methods]]
- [[#Glossary|Glossary]]
- [[#Certificate Signing request|Certificate Signing request]]
- [[#PEM Chain|PEM Chain]]


### ISE
---
- ISE at its core is a RADIUS server. (RADIUS == Remote Authentication Dial-In User Server)
- What sets the Cisco ISE solution apart from other radius server solutions is that ISE collects information about the endpoints that are authenticating against the ISE server.

![[356348.webp]]

### Nodes
---
- ***ISE acts as multiple Nodes in one. You can consider it as having multiple Personas***

##### Policy Administration Node (PAN)
---
**Policy Administration Node (PAN):** As mentioned in the previous response, the PAN is responsible for creating and managing network access policies. It handles the administrative operations of the system and is the central control node that all other components report to.

1. **Policy Definition and Management:** The PAN is responsible for defining and managing network access policies. It allows administrators to set rules and conditions that determine who can access the network, when, and under what conditions.
    
2. **System Configuration:** All system-wide configuration settings are defined and managed through the PAN. This includes configurations for other components in the system, like Policy Service Nodes (PSNs).
    
3. **Central Management:** The PAN serves as the central management point for all other nodes (like PSNs, MnT, pxGrid, IPN) in a distributed ISE deployment. All nodes report to the PAN and it oversees their functions.
    
4. **Monitoring and Reporting:** Although the MnT node carries out detailed monitoring and troubleshooting, the PAN also provides high-level system monitoring and reporting capabilities. It can generate reports and dashboards that give an overview of system performance and security status.
    
5. **High Availability:** You can deploy a secondary PAN for high availability and disaster recovery purposes. This helps to ensure that the ISE can continue to function even if one of the PANs becomes unavailable.
    
6. **Software Updates:** The PAN is also where software updates are managed. When a new version of the ISE software is released, it is the PAN that downloads and distributes the update to the other nodes in the system.
    
By managing and enforcing policies, the PAN plays a key role in controlling network access and maintaining network security. It is the main interface that administrators interact with when managing the ISE.

When you access the ISE through the GUI, you're typically connecting to the Policy Administration Node (PAN). The PAN is where you define and manage policies, configure system settings, and perform other administrative tasks. The GUI makes it easier to perform these tasks by providing a user-friendly, visual way to interact with the ISE, instead of having to use the command line interface (CLI).

In a distributed deployment with multiple PANs, you can connect to the primary PAN's GUI for managing the entire system, and you can also connect to the secondary PAN's GUI but only with read-only access unless the primary PAN is down.

The Policy Service Nodes (PSNs), Monitoring and Troubleshooting Node (MnT), and other nodes also have GUIs, but they are typically used for specific tasks related to those nodes, like troubleshooting specific services or viewing local logs.

When you configure the command line for an ISE server and then access the GUI, you are typically connecting to the PAN, but remember that the GUI itself is not the PAN - it's simply a way to interact with the PAN and other nodes.


##### Policy Service Node (PSN)
---
**Policy Service Node (PSN):** The PSN handles the real-time interactions between network devices and the ISE, such as user and device authentication, authorization, and accounting (AAA) services. PSNs enforce the policies that are defined by the PAN.

1. **Authentication, Authorization, and Accounting (AAA):** The PSN provides AAA services for network devices. This involves checking a user's credentials (authentication), determining what the user is allowed to do based on their role (authorization), and keeping records of the user's activities (accounting).
    
2. **Policy Enforcement:** The PSN enforces the network access policies that have been defined by the Policy Administration Node (PAN). This involves checking whether users and devices comply with these policies before they are allowed to access the network.
    
3. **Profiling and Posture Assessment:** The PSN is also responsible for profiling and posture assessment, which involves gathering and assessing information about devices attempting to connect to the network. This can include information about the type of device, its operating system, installed software, and more.
    
4. **Guest and BYOD Services:** The PSN handles services for guests and BYOD (Bring Your Own Device) scenarios. This includes managing guest access to the network, and ensuring that personal devices comply with the organization's security policies.
    
5. **Scalability and Redundancy:** Multiple PSNs can be deployed in a distributed ISE deployment for handling larger network environments and to ensure high availability and redundancy.
    

The PSN is essentially the "workhorse" of the ISE, performing the real-time operations that keep the network secure. It communicates with network devices such as switches, routers, and wireless access points, and makes decisions about network access based on the policies defined by the PAN.

##### Monitoring and Troubleshooting Node (MnT)
---
**Monitoring and Troubleshooting Node (MnT):** This node collects and stores data for reporting, monitoring, troubleshooting, and network forensics. The MnT provides real-time monitoring of endpoints as they are authenticated and authorized and can report on their behavior after they are admitted onto the network.

1. **Data Collection:** The MnT node collects and stores a wide range of data, such as user login events, endpoint profiling events, policy changes, and system error messages. This data is crucial for maintaining a complete view of network activity.
    
2. **Real-time Monitoring:** The MnT node provides real-time monitoring of endpoints as they authenticate and are authorized onto the network. This can help to detect unusual behavior or policy violations.
    
3. **Reporting:** The MnT node generates a variety of reports that administrators can use to gain insights into the network's operation. These reports can be customized to focus on specific areas of interest, such as security incidents or system performance metrics.
    
4. **Troubleshooting and Network Forensics:** The data collected by the MnT node can be used for troubleshooting purposes and network forensics. If a security incident or system issue occurs, administrators can use this data to understand what happened and why.
    
5. **Alarm and Event Management:** The MnT node also manages system alarms and events, helping administrators to prioritize and respond to issues in a timely manner.
    
6. **High Availability and Scalability:** You can deploy multiple MnT nodes in a distributed deployment for redundancy and to handle larger amounts of data.    

The MnT node is an essential component of a Cisco ISE deployment, providing the visibility and insights necessary to manage and secure a complex network environment.


##### pxGrid (Platform Exchange Grid)
---
 **pxGrid (Platform Exchange Grid) Node:** pxGrid nodes are used to share context-sensitive information from ISE to other network systems such as SIEM (Security Information and Event Management), ACS (Access Control System), and any other system that can consume this information. This allows for better, more responsive security across the entire network. 
 
 1. **Context Sharing:** pxGrid provides a framework that allows different security technologies to share information. This includes user identity, device type, access time, location, threat level, vulnerability, and more. This allows for a better understanding of the network, improving visibility and context.
    
2. **Multi-vendor Interoperability:** pxGrid supports integration with many different network systems and is designed to be vendor-neutral. This includes Security Information and Event Management (SIEM) systems, Network Access Control (NAC) solutions, threat defense systems, and more.
    
3. **Adaptive Network Control:** By sharing information between different network systems, pxGrid allows these systems to dynamically adapt their policies based on the information they receive. For example, if a SIEM system detects a threat, it can communicate this through pxGrid to the ISE, which can then take appropriate action like quarantining the affected endpoint.
    
4. **Standard-based Communication:** pxGrid uses standard protocols such as STOMP (Streaming Text Oriented Messaging Protocol) and XMPP (Extensible Messaging and Presence Protocol) for communication. This enhances its interoperability with various third-party systems.
    
5. **Scalability and Redundancy:** You can deploy multiple pxGrid nodes to handle large amounts of data and maintain high availability.
    

By effectively utilizing pxGrid, organizations can create a more connected and responsive security infrastructure, where each system is aware of the others' findings and can react accordingly. It essentially provides a more unified, collaborative approach to threat detection and mitigation.

#####  Inline Posture Node (IPN)
---
**Inline Posture Node (IPN)**: Bridges communication between NADs that do not support CoA (Change of Authorization) and the ISE server. Typically, you would use the IPN when deploying ISE with non-cisco hardware. The Inline Posture Node is designed to handle specific scenarios where a network device, such as a switch or wireless access point, is not capable of redirecting endpoints to the ISE Policy Service Node (PSN) for posture assessment. The IPN essentially sits inline between the network device and the endpoint and manages the redirection process.

Overview of what the IPN does:

1. **Posture enforcement:** The IPN enforces access policies for non-compliant endpoints. If an endpoint doesn't meet the requirements set by your organization's policies, the IPN can limit its network access.
	
2. **Traffic redirection:** The IPN handles redirection of traffic to the PSN for posture assessment. It intercepts traffic from endpoints and redirects it to the PSN for evaluation.

3. **Endpoint remediation:** If an endpoint is non-compliant, the IPN can work with the PSN to provide the endpoint with any necessary remediation resources, such as software updates or patches.
    
Please note, however, that use of the IPN is often considered as the last option because it requires more network resources and can add complexity to the network design. It is generally recommended to use the native posture redirection capabilities of the network access devices (like switches or access points) when possible.
    

In a large distributed deployment, each type of node can run on a separate physical server, and there can be multiple instances of each type of node for scalability and redundancy. In smaller deployments, a single server might run multiple node types.

Also, it's important to note that all ISE nodes in a deployment must be running the same software version to ensure compatibility and proper communication.


 
 ![[slide_19.jpg]]
 
 

##### Provides Zero Trust
---

![[Pasted image 20230717135049.png]]

##### AAA server 
---
- Authentication, Authorization, Accounting

![[Pasted image 20230717135122.png]]

##### TACACS+
---
-  [TACACS+](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FTACACS%2B)
- ISE is a TACACS+ server
- Cisco proprietary 

![[Pasted image 20230717135457.png]]

![[Pasted image 20230717141914.png]]

##### RADIUS (Remote Authentication Dial-In User Service)
---
 - Open source protocol.
 - Network access protocol for USER authentication. 
 - client/server protocol
 - The main job of a RADIUS server is to receive client requests and relay configuration information needed by the client to deliver some service to the user. It supports different methods of authenticating a user, such as CHAP, PPP, and UNIX login. The authentication and authorization happen simultaneously, with the RADIUS server sending attribute-value pairs along when it sends an ‘Access-Accept’ response.
 - The RADIUS server also provides accounting features independently. Data at the start and end of connection sessions can be provided by the RADIUS server, detailing the resources and their amounts used. A shared secret accomplishes the authentication of transactions between the client and the RADIUS server that the network never knows.

###### RADIUS Process
1. The user initiates a direct point-to-point (PPP) authentication to the network access server (NAS). The NAS is actually the RADIUS client, and the PPP authentication doesn’t involve any network in between.
2. The RADIUS client prompts the user for username and password.
3. The user replies back.
4. The RADIUS client sends the username and the encrypted password to the RADIUS server to authenticate the user using different mechanisms. The server goes through a database to locate the username and, if not found, sends an ‘Access-Reject’ message. The rejection can come with a text message explaining the refusal.
5. The server replies back with an appropriate ‘Access-Accept’ or ‘Access-Reject’ response after authentication. It can also be sent by a ‘Challenge’ if the **C**hallenge **H**andshake **A**uthentication  
	**P**rotocol (**CHAP**) is used.
6. The RADIUS client acts on the service parameters and services that come bundled with the ‘Accept’ or ‘Reject’ response.

![[Radius-Network.gif]]

![[Pasted image 20230717151458.png]]


##### MAB (MAC Authentication Bypass)
---
- For ***Invalid Supplicant Devices.***
- Used if the client or IOT device is does not have a 802.1z Authentication certificate and the 802.1x EAP-Start process times out. 
	- The ISE server will check the MAC address of the device and see if there is an entry of the devices MAC inside the Database.
 
![[Pasted image 20230717152540.png]]
 
##### Difference between TACACS and RADIUS 
---
 TACACS+ vs. RADIUS: What's the Difference? The main difference between RADIUS and TACACS+ is that **RADIUS is mainly a network access protocol for user authentication, whereas TACACS+ is predominantly used for administrating network devices like routers and switches**

##### EAP Methods
----
There are multiple EAP (Extensible Authentication Protocol) methods available, each with its unique characteristics. Some of the most common methods include:

1. **EAP-TLS (EAP-Transport Layer Security)**: This method provides strong security by using certificate-based mutual authentication.
    
2. **PEAP (Protected EAP)**: This method creates a secure TLS tunnel between the client and the server, within which a second EAP method is used. The most common inner EAP method is EAP-MSCHAPv2.
    
3. **EAP-TTLS (EAP-Tunneled TLS)**: Similar to PEAP, EAP-TTLS establishes a secure tunnel for other authentication methods. Unlike PEAP, it allows for multiple different inner authentication protocols and is not tied to MSCHAPv2.
    
4. **EAP-FAST (EAP-Flexible Authentication via Secure Tunneling)**: Cisco developed this method as a replacement for LEAP. It uses a protected access credential (PAC) which can be stored on the client and used to establish a secure tunnel.
    
5. **LEAP (Lightweight EAP)**: This Cisco proprietary protocol is considered insecure by today's standards and is not recommended for use. It uses username/password with MSCHAPv2.
    
6. **EAP-MD5**: One of the original EAP methods, it's considered insecure and isn't recommended because it only provides one-way authentication (server doesn't authenticate itself to the client) and it's vulnerable to dictionary attacks.
    
7. **EAP-SIM, EAP-AKA, EAP-AKA'**: These are used for integrating the authentication of mobile phones into WLAN authentication. They use the SIM (Subscriber Identity Module) of a mobile phone for authentication.
    

The method used for a particular session is typically determined during the initial negotiation phase of the EAP authentication process. The client and server will indicate what methods they each support, and they'll agree on the highest level of security that they both support. The precise method of negotiation can depend on the implementation of the EAP protocol, as well as any policies configured by the network administrator.

For example, in a corporate environment, the IT department might set policies on the authentication server to only accept certain EAP methods based on the security needs of the organization. The client (e.g., a laptop or smartphone) would then need to be configured to use one of those acceptable methods.

Lastly, the EAP method used could also depend on the type of network connection. For instance, some EAP methods are more common in Wi-Fi networks, while others might be more common in VPN or other types of network connections.

##### Glossary
---

- Supplicant/Client
	- In computer networking, a supplicant is **an entity at one end of a point-to-point LAN segment that seeks to be authenticated by an authenticator attached to the other end of that link**. The IEEE 802.1X standard uses the term "supplicant" to refer either to hardware or to software.

- Authenticator
	- the term "authenticator" refers to the network device that acts as the intermediary between the client and the authentication server. Typically, the authenticator is a network switch, but it can also be a wireless access point or any other network device capable of enforcing network access control.


##### Certificate Signing request
----

![[how-a-CSR-works-1024x560.jpg]]


##### PEM Chain
---

When requesting a certificate one sends a Certificate Signing Request, containing the information to be signed by a CA, to that CA. The CA responds with the resulting certificate and the chain of certificates back to a root. That chain is the CA's certificate, any intermediate CA certificate(s) that signed the CA, (possibly multiple levels), and the root certificate that signed the top-level intermediate CA certificate (if that's not the same as the CA's certificate in question). In Let's Encrypts case, there's only the CA certificate and the Root in this chain.

The CA knows everything in the chain because they in turn had requested their certificate from an intermediate CA or root, and they know who they requested it from. So they know the certificate of the intermediate or root, and can include it. Likewise back up the chain.

Root CAs have self-signed certificates. There's no other entity in their certificate chain. These certificates get imported as trusted root certificates by browser vendors (and other entities dealing with the TLS CA system), allowing verification of certificate chains starting at these roots.

Since every time anyone (including a CA) requests a certificate they get back the entire chain it's trivial for a CA to send the chain along with the resulting certificate from a request. Also, certificates are public and all major CAs publish the certificates they issue in "certificate transparency logs", so even without the chain one could (in theory) look up the certificates for each signing entity.

![[certificate-chains.png]]