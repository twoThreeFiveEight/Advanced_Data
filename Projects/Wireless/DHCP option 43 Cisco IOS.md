### Cisco IOS® DHCP Server

#### Cisco Aironet APs (Cisco IOS)

Complete these steps in order to configure DHCP Option 43, in the embedded Cisco IOS DHCP server, for all Cisco Aironet APs that run Cisco IOS. This includes all APs except for the VxWorks 1000 Series (see the next section) and the 600 Series OEAP which does not use Option 43.

1. Enter configuration mode at the Cisco IOS CLI.
    
2. Create the DHCP pool, which includes the necessary parameters such as the default router and server name. This is an example DHCP scope:
```kotlin
    ip dhcp pool <pool name>  
    network <ip network> <netmask>  
    default-router <default-router IP address>  
    dns-server <dns server IP address>

	// HERE WE ADD DHCP OPTION 43
	option 43 hex <hexadecimal string>
``` 

The hexadecimal string in step 3 is assembled as a sequence of the TLV values for the Option 43 suboption: Type + Length + Value. Type is always the suboption code 0xf1. Length is the number of controller management IP addresses times 4 in hex. Value is the IP address of the controller listed sequentially in hex.
    
For example, suppose there are two controllers with management interface IP addresses, 192.168.10.5 and 192.168.10.20. The type is 0xf1. The length is 2 * 4 = 8 = 0x08. The IP addresses translate to c0a80a05 (192.168.10.5) and c0a80a14 (192.168.10.20). When the string is assembled, it yields f108c0a80a05c0a80a14. The Cisco IOS command that is added to the DHCP scope is:
    
```
option 43 hex f108c0a80a05c0a80a14
```


### My Config for Wireless project
---
```kotlin
// for IP 10.1.10.4
option 43 hex f1040a010a04
```