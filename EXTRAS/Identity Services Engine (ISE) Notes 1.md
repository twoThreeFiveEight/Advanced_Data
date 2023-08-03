- [[#ISE|ISE]]
- [[#Provides Zero Trust|Provides Zero Trust]]
- [[#AAA server|AAA server]]
- [[#TACACS+|TACACS+]]
- [[#RADIUS (Remote Authentication Dial-In User Service)|RADIUS (Remote Authentication Dial-In User Service)]]
	- [[#RADIUS (Remote Authentication Dial-In User Service)#RADIUS Process|RADIUS Process]]
- [[#MAB (MAC Authentication Bypass)|MAB (MAC Authentication Bypass)]]
- [[#Difference between TACACS and RADIUS|Difference between TACACS and RADIUS]]
- [[#EAP Methods|EAP Methods]]
- [[#Glossary|Glossary]]

##### ISE
---
- ISE at its core is a RADIUS server. (RADIUS == Remote Authentication Dial-In User Server)
- What sets the Cisco ISE solution apart from other radius server solutions is that ISE collects information about the endpoints that are authenticating against the ISE server.
- ISE acts as multiple Nodes in one. You can consider it as having multiple Personas
	- Types of nodes
		- Policy Administration Node: Used to configure all other node and policies on the ISE server
		- PAN: This is the centralized GUI or single pane of glass
		- MnT (Monitoring and Troubleshooting): Responsible for collecting all the logs from other nodes and NADs (Network Access Devices).
		- PSN (Policy Service Node): Responsible for collection of all ISE based probes and issuing authorization results to the NADs. This node is also responsible for all BYOD and Guest services.
		- IPN (Inline Posture Node): Bridges communication between NADs that do not support CoA (Change of Authorization) and the ISE server. Typically, you would use the IPN when deploying ISE with non-cisco hardware.
 ![[356348.webp]]

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

