https://www.youtube.com/watch?v=0Dp7YoR0SLE
https://www.pynetlabs.com/what-is-dhcp/
https://networkinwireshark.wordpress.com/tag/dora/

DHCP (Dynamic Host Configuration Protocol) options are additional parameters that can be configured and provided by a DHCP server to DHCP clients during the IP address assignment process. These options provide various configuration settings and additional information to clients. While there are many possible DHCP options, here are some commonly used options:

1.  Subnet Mask (Option 1): Specifies the subnet mask to be used by the DHCP client.
    
2.  Router/Gateway (Option 3): Provides the IP address of the default gateway or router to be used by the client.
    
3.  DNS Servers (Option 6): Specifies the IP addresses of DNS servers that the client should use for domain name resolution.
    
4.  Domain Name (Option 15): Provides the DNS domain name that the client should append to unqualified domain names.
    
5.  NTP Servers (Option 42): Specifies the IP addresses of Network Time Protocol (NTP) servers that the client should synchronize its time with.
    
6.  Domain Search (Option 119): Specifies a list of DNS domain names that the client can search when resolving unqualified domain names.
    
7.  Hostname (Option 12): Allows the DHCP server to assign a specific hostname to the client.
    
8.  Time Offset (Option 2): Provides the time offset from UTC (Coordinated Universal Time) for the client's time zone.
    
9.  Time Server (Option 4): Specifies the IP address of a time server that the client can synchronize its clock with.
    
10.  Boot Filename (Option 67): Specifies the filename or path of the boot file that the client should request during the boot process.
    

These are just a few examples of common DHCP options. There are many other options available, and their availability and usage may vary depending on the DHCP server software and client capabilities. DHCP options allow for flexible configuration and customization of network settings for DHCP clients, enabling the automatic provisioning of various parameters required for network connectivity.