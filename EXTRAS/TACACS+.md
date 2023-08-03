ISE is a TACACS+ server

TACACS+ (Terminal Access Controller Access-Control System Plus) is a network protocol used for authentication, authorization, and accounting (AAA) in network devices. It is primarily associated with Cisco devices and is a proprietary protocol developed by Cisco Systems.

TACACS+ provides a centralized authentication and access control mechanism for managing user access to network resources. It separates the AAA functions into distinct phases:

1. Authentication: TACACS+ supports various authentication methods, including username/password, digital certificates, and token-based authentication. When a user attempts to access a network device, the device sends an authentication request to the TACACS+ server. The TACACS+ server verifies the user's credentials and returns an authentication response to the device.
    
2. Authorization: After successful authentication, the TACACS+ server provides authorization based on user-specific policies and access control lists (ACLs). It determines the level of access the authenticated user has to various network resources, such as specific commands or configuration privileges.
    
3. Accounting: TACACS+ records accounting information for auditing and billing purposes. It tracks user activities, such as command execution, session duration, and data transfer, providing detailed logs for analysis and compliance.
    

TACACS+ operates on TCP/IP and supports strong encryption for secure communication between the network devices and the TACACS+ server. It offers advanced security features, such as message integrity checks and encryption of the entire payload, including authentication credentials.

While TACACS+ is primarily associated with Cisco devices, it can be used with other vendor equipment that supports the protocol. However, due to its proprietary nature, interoperability may vary between different vendors.

In summary, TACACS+ is a network protocol developed by Cisco for AAA services, providing centralized authentication, authorization, and accounting for network devices. It offers advanced security features and granular control over access to network resources.