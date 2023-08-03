#### Resources:
----
- What is?
	- https://www.youtube.com/watch?v=mpQZVYPuDGU
- Types of Records:
	- https://www.youtube.com/watch?v=HnUDtycXSNE

### Commands
----


### Sections
----
[DNS setup](#dns%20setup) | [Types of Records](#types%20of%20records) | [Setting up a device for DNS](#device%20setup) | [Linking DHCP and DNS](#Linking%20DHCP%20and%20DNS%20(DDNS)) | [Link Windows and Infoblox servers](#Link%20Windows%20and%20Infoblox%20servers) | [HA Pairs](#ha%20pairs) | [Setting up A Domain Name](#Domain%20Name)

DNS stands for Domain Name System, and it is responsible for translating domain names (e.g., example.com) into IP addresses (e.g., 192.0.2.1) that computers use to communicate over the internet. Setting up DNS involves configuring a DNS server to provide name translations for your business.

### DNS setup
----

1.  Choose a DNS Server Software: There are several DNS server software options available, such as BIND (Berkeley Internet Name Domain), Microsoft DNS Server, and PowerDNS. Choose the one that best suits your needs and operating system.
    
2.  Install and Configure the DNS Server Software: Install the chosen DNS server software on your server. The installation process may vary depending on the software you selected. Once installed, you'll need to configure the DNS server by specifying various settings such as listening IP addresses, port numbers, and other options.
    
3.  Set Up Forward and Reverse Zones: A DNS zone is a portion of the DNS namespace that is managed by a specific DNS server. In simple terms, it represents a domain for which the DNS server will provide name translations. You'll need to set up at least two types of zones: forward zones and reverse zones.
    
    -   Forward Zone: This zone maps domain names to IP addresses. It allows clients to look up the IP address associated with a given domain name. Configure the forward zone by adding resource records, such as A (address) records for IPv4 addresses or AAAA (IPv6 address) records.
        
    -   Reverse Zone: This zone maps IP addresses to domain names. It allows reverse lookups, where clients can find the domain name associated with a given IP address. Configure the reverse zone by adding PTR (pointer) records.
        
4.  Set Up Name Server (NS) Records: NS records specify the authoritative name servers for a domain. They indicate which DNS server is responsible for providing name translations for your domain. Add NS records for your domain in the appropriate zone configuration.
    
5.  Register Your Name Servers: If you're setting up DNS for your business, you'll typically need to register your name servers with your domain registrar. This process involves providing the IP addresses of your DNS servers to the registrar so that they can delegate DNS queries for your domain to your servers.
    
6.  Test and Monitor: After configuring your DNS server and registering your name servers, it's crucial to test the setup to ensure proper functionality. Use DNS lookup tools or commands to query your DNS server for domain name translations and verify that the correct IP addresses are returned.
    

Remember to regularly monitor your DNS server's performance and security, ensuring that it's up-to-date with patches and updates to protect against vulnerabilities.

Please note that setting up DNS involves technical expertise, and it may be beneficial to consult a network administrator or a professional with experience in DNS configuration to ensure a smooth setup process.


### Types of Records
----
Here are some of the most common types of DNS records and their purposes:

1.  A (Address) Record: An A record maps a domain name to an IPv4 address. It is used to translate a domain name into the corresponding IP address.
    
2.  AAAA (IPv6 Address) Record: Similar to an A record, an AAAA record maps a domain name to an IPv6 address. It is used for translating domain names to IPv6 addresses.
    
3.  CNAME (Canonical Name) Record: A CNAME record creates an alias for a domain name. It points one domain name to another domain name. For example, if you have multiple subdomains that all point to the same IP address, you can create a CNAME record for each subdomain, pointing them to the main domain.
    
4.  MX (Mail Exchanger) Record: MX records specify the mail servers responsible for accepting incoming email for a domain. They specify the domain names of the mail servers and their priority. When someone sends an email to your domain, the sending server looks up the MX records to determine where to deliver the email.
    
5.  TXT (Text) Record: A TXT record allows you to store arbitrary text data associated with a domain. It is commonly used for various purposes such as domain verification for email services, SPF (Sender Policy Framework) records for email authentication, and DKIM (DomainKeys Identified Mail) verification.
    
6.  PTR (Pointer) Record: A PTR record is used in reverse DNS lookups. It maps an IP address to a domain name. PTR records are commonly used to verify the reverse DNS mapping for email servers and to help prevent spam.
    
7.  NS (Name Server) Record: NS records identify the authoritative name servers for a particular domain. They specify which DNS servers are responsible for providing name resolution for the domain.
    
8.  SOA (Start of Authority) Record: The SOA record contains administrative information about a DNS zone. It includes details such as the primary name server for the zone, the contact email address of the administrator, and various timing parameters for the zone.
    
9.  SRV (Service) Record: SRV records define the location of specific services within a domain. They are commonly used for protocols like SIP (Session Initiation Protocol) for VoIP services and Microsoft Active Directory for locating domain controllers.
    
10.  SPF (Sender Policy Framework) Record: SPF records are used to prevent email spoofing and verify that an email server is authorized to send email on behalf of a domain. SPF records list the authorized IP addresses or hostnames that can send email for a domain.
    

These are just a few examples of DNS record types. There are additional specialized record types such as NAPTR, SSHFP, TLSA, and more, which serve specific purposes depending on your needs.


### Device Setup
---
To specify the DNS server on a Cisco device, you need to configure the DNS settings within the device's configuration. Here's how you can do it:

1.  Access the Cisco device: Connect to the Cisco device using a console cable or through a remote management interface, such as SSH or Telnet.
    
2.  Enter privileged EXEC mode: Log in to the device and enter the privileged EXEC mode by typing the following command and providing the enable password if prompted:
    

bash

```c
enable
```

3.  Enter global configuration mode: Enter global configuration mode to make configuration changes by typing the following command:

```c
configure terminal
```

4.  Specify the DNS server: To configure the DNS server on a Cisco device, you can use the `ip name-server` command followed by the IP address of the DNS server. You can specify multiple DNS servers by entering this command multiple times. For example, to specify a primary and secondary DNS server, use the following commands:

```c
ip name-server 192.0.2.1 
ip name-server 203.0.113.1
```

5.  (Optional) Specify domain name lookup: By default, Cisco devices perform domain name lookup for unqualified names. You can configure the device to disable this behavior by using the `no ip domain-lookup` command. This prevents the device from attempting to resolve unqualified names as hostnames. If you want to enable it, use the `ip domain-lookup` command.
    
6.  Exit configuration mode and save the configuration: Once you have made the necessary changes, exit global configuration mode by typing `exit`. To save the configuration, issue the `write` or `copy running-config startup-config` command to save the changes to the device's configuration file.
    

By specifying the DNS server on a Cisco device, you ensure that the device uses the specified DNS server for name resolution when resolving domain names to IP addresses.

### Linking DHCP and DNS (DDNS)
---


DHCP (Dynamic Host Configuration Protocol) can be linked with DNS (Domain Name System) to provide dynamic DNS updates. This integration allows DHCP clients to automatically register their hostnames and IP addresses with the DNS server, ensuring that DNS records are kept up-to-date.

When a DHCP client receives an IP address lease from a DHCP server, it can send a DNS update request to add or update the corresponding DNS records. This process is commonly referred to as Dynamic DNS (DDNS) or DHCP-DNS integration.

To enable DHCP-DNS integration, you typically need to configure both the DHCP server and the DNS server. Here's a general overview of the steps involved:

1.  DHCP Server Configuration:
    
    -   Enable the DHCP server to accept and process DNS update requests from clients.
    -   Configure the DHCP server to include the appropriate DHCP options related to DNS updates. These options may vary depending on the DHCP server software you are using.
    -   Specify the DNS server IP address(es) in the DHCP server configuration, allowing clients to receive this information during the DHCP lease process.
2.  DNS Server Configuration:
    
    -   Configure the DNS server to accept and process dynamic DNS update requests from DHCP clients.
    -   Enable dynamic DNS updates on the DNS server to allow clients to register and update their DNS records.
    -   Set up appropriate access controls and security measures to ensure that only authorized clients can update DNS records.
3.  DHCP Client Behavior:
    
    -   DHCP clients need to be configured to request DNS updates when obtaining an IP address lease.
    -   When a client receives a lease from the DHCP server, it sends a DNS update request to the DNS server, providing its hostname and IP address.
    -   The DNS server processes the update request and adds or updates the corresponding DNS records.

By integrating DHCP with DNS, you can ensure that the DNS records are automatically updated when IP address assignments change. This helps to maintain accurate and up-to-date DNS information for devices on your network.

Please note that the exact configuration steps may vary depending on the specific DHCP and DNS server software you are using. It's recommended to refer to the documentation or user guides of your DHCP and DNS servers for detailed instructions on configuring the integration between the two.

### Link Windows and Infoblox servers
----
To link a Windows Server acting as your DHCP server with an Infoblox server running your DNS, you can follow these steps:

1.  Configure DHCP on Windows Server:
    
    -   Install and configure the DHCP server role on your Windows Server.
    -   Configure the DHCP scope(s) with the appropriate IP address range, subnet mask, default gateway, and other DHCP options.
    -   Ensure that the DHCP server is authorized in the Active Directory domain if required.
2.  Obtain the Infoblox DNS Server IP Address:
    
    -   Identify the IP address of your Infoblox DNS server. You can obtain this information from your network administrator or by accessing the Infoblox Management Console.
3.  Configure DNS Dynamic Update Credentials:
    
    -   In the Windows Server DHCP console, right-click on the DHCP server and select "Properties."
    -   Go to the "Advanced" tab and click on "Credentials."
    -   Specify the credentials (username and password) with sufficient permissions to perform dynamic DNS updates on the Infoblox DNS server. These credentials will be used by the DHCP server to send DNS update requests.
4.  Enable DNS Dynamic Updates:
    
    -   In the Windows Server DHCP console, right-click on the DHCP server and select "Properties."
    -   Go to the "DNS" tab.
    -   Select the option "Enable DNS dynamic updates according to the settings below."
    -   Choose either "Always dynamically update DNS A and PTR records" or "Dynamically update DNS A and PTR records only if requested by the DHCP clients" based on your requirements.
    -   Check the box for "Discard A and PTR records when lease is deleted."
5.  Specify the Infoblox DNS Server:
    
    -   In the Windows Server DHCP console, right-click on the DHCP server and select "Properties."
    -   Go to the "DNS" tab.
    -   Enter the IP address of your Infoblox DNS server in the "DNS server" field.
6.  Verify DNS Dynamic Updates:
    
    -   To verify that dynamic DNS updates are working correctly, you can create a new DHCP reservation for a client.
    -   Verify that the client's hostname and IP address are correctly registered in the Infoblox DNS server.

By configuring the Windows Server DHCP server to perform dynamic DNS updates and specifying the Infoblox DNS server as the target, you can ensure that DNS records are automatically updated as DHCP leases are assigned or renewed.

Please note that the exact steps may vary slightly depending on the specific versions of Windows Server and Infoblox DNS server you are using. It's recommended to refer to the documentation or user guides of your DHCP and DNS servers for detailed instructions and any additional considerations specific to your environment.

### HA pairs
---


Implementing high availability (HA) failover for a DNS server involves setting up redundant DNS servers to ensure continuous service in the event of a failure. Here's an overview of the steps involved:

1.  Designate Primary and Secondary DNS Servers: Determine which DNS server will act as the primary and which one will be the secondary server. The primary server will handle DNS requests under normal circumstances, while the secondary server will serve as a backup.
    
2.  Configure Zone Replication: Configure zone replication between the primary and secondary DNS servers. This ensures that both servers have the same zone data, allowing the secondary server to serve DNS requests if the primary server becomes unavailable. The method of zone replication depends on the DNS server software you're using.
    
3.  Set Up IP Address Failover: Configure IP address failover between the primary and secondary DNS servers. This involves assigning a virtual IP (VIP) address that will be associated with the DNS service. In the event of a failure on the primary server, the VIP will automatically move to the secondary server, allowing it to take over the DNS service.
    
4.  Implement DNS Monitoring: Deploy a monitoring system to regularly check the availability and responsiveness of the primary DNS server. If the primary server fails, the monitoring system will detect it and initiate the failover process.
    
5.  Configure DNS Failover Script: Create a failover script that triggers the necessary actions when the primary server fails. The script should handle tasks such as updating DNS records, initiating IP address failover, and starting the DNS service on the secondary server.
    
6.  Test and Monitor: Regularly test the failover setup to ensure its effectiveness. Simulate failures on the primary server and verify that the secondary server takes over seamlessly. Monitor the health and performance of both DNS servers to identify any potential issues.
    
7.  Documentation and Documentation: Document the HA failover configuration, including the steps for failover, IP addresses, DNS settings, and any other relevant information. This documentation will be valuable for troubleshooting and future reference.
    

Remember to consider the specific requirements and capabilities of your DNS server software and network infrastructure when implementing HA failover. It's also recommended to consult the documentation or seek assistance from a network administrator or IT professional experienced in DNS and high availability setups.

### Domain Name
----
The domain name for DNS (Domain Name System) refers to the hierarchical naming system used to identify and locate resources on the internet. It is not something you can simply make up; it follows a specific structure and requires registration to ensure uniqueness and proper resolution.

When you want to set up DNS, you typically need to register a domain name through a domain registrar or a hosting provider that offers domain registration services. During the registration process, you choose a domain name that aligns with your branding, business, or personal needs. The domain name must be unique and not already registered by someone else.

A domain name consists of two main parts: the actual name (e.g., "example") and the top-level domain (TLD) (e.g., ".com," ".org," ".net," etc.). The TLD is often associated with the purpose or type of organization using the domain. For example, ".com" is commonly used for commercial entities, ".org" for non-profit organizations, and ".edu" for educational institutions.

Once you register a domain name, you gain control over that specific namespace, and you can configure the DNS settings for that domain. These DNS settings define how the domain name is associated with IP addresses, mail servers, subdomains, and other DNS records. By setting up DNS correctly, you enable the translation of human-readable domain names (e.g., example.com) into IP addresses (e.g., 192.0.2.1) or other resource records.

The role of the domain name in DNS is significant. It serves as a unique identifier for your website, email services, and other resources associated with your online presence. It allows users to access your services using a memorable and meaningful name rather than relying solely on numerical IP addresses. The DNS system, with the help of the domain name, ensures that requests for your domain are correctly resolved and directed to the appropriate servers or services associated with that domain.

In summary, the domain name for DNS must be registered through a domain registrar, and it plays a crucial role in identifying and accessing resources on the internet by providing a user-friendly naming system that maps to IP addresses and other DNS records.