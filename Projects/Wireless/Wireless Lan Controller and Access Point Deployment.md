##### Creature: Aaron Carroll

### Table of Contents
---
[[#Section 1 Topology and Device references]]
[[#Section 2 Establish Serial Connection]]
[[#Section 3 Reset WLC to Factory settings]]
[[#Section 4 Connect and configure the switchs]]
[[#Section 5 Connect to Web GUI and configure]]
[[#Section 6 DHCP Info]]
[[#Section 7 Overview of the WLC Discovery and Join Process]]


### Section 1: Topology and Device references
----
NOTE: 
- In this article I will be referencing the Wireless Lan Controller as ***WLC*** and the Access Points as ***APs*** or singular as ***AP***.
- There are references to Cisco documentation at the bottom of this Method of Proceedure.

- In the following Wireless Lan Controller and Access Point Deployment we will need the following.
	- Cisco 5500 Series Wireless Lan Controller.
	- Two Cisco Catalyst 3750 Series Switch. (Core MDF switch for WLC, Access IDF switch for APs)
	- Cisco AIR-CAP-36021-A-K9 Access point.
	- Console Cable. (For accessing devices CLI)
	- Two Ethernet SFPs. (***See Figure 0-2 for IMPORTANT considerations***)
	- Cat6 Ethernet Cable. (Length and amount are dependent on your requirements)
	- Computer with ethernet port.                       

##### Network topology for this example
![[Pasted image 20230709203538.png]]

Figure 0-1

##### Wireless Lan controller and ports used in example
![[Pasted image 20230707210836.png]]
Figure 0-2

##### Cisco Switchs and associated ports in example
![[Pasted image 20230707211001.png]]
Figure 0-2


### Section 2: Establish Serial Connection
---

- Plug console cable from PC into console port on WLC. Wait before starting WLC

![[Pasted image 20230707194017.png]]
Figure 1-1

- We will be using MobaXterm for this example. 
	- Enter MobaXterm
	- Click on session in the top left corner

![[Pasted image 20230707194618.png]]
Figure 1-2

- Select Serial Connection 
- Click OK

![[Pasted image 20230707200355.png]]
Figure 1-3

- Select 9600 baud rate (Speed (bps))
- Select COM port number your USB console cable is plugged into. Maybe different then ***COM5*** as in example.

![[Pasted image 20230707193636.png]]
Figure 1-4

- You should now see a COM session in the left table

![[Pasted image 20230707194944.png]]
Figure 1-5


### Section 3: Reset WLC to Factory settings
---
- Turn the WLC on and double click on the COM session you created. (Refer to Figure 1-4)
- Click in the session terminal then continuously press ESC key to access Boot Menu.

![[Pasted image 20230707195851.png]]
Figure 2-1

- Type number 4 to reset to erase current running configuration.

![[Pasted image 20230707201238.png]]
Figure 2-2

- WAIT until reset is done............ 
- When finished press enter.
- Refer to Systems Administrator for password. 
- Follow the prompts for your systems requirements.
- The topology used in this example configurations are below.
	- Refer to SIC LLD to reference IP scheme to better understand requirements. (See Figure 0-1)
	
![[Pasted image 20230707205801.png]]
Figure 2-3

- After completion Log into the CLI with your new credentials. 
- Once signed in we need to enable the Web GUI for further configuration.
	- Type the following commands:
![[Pasted image 20230707210543.png]]


### Section 4: Connect and configure the switchs
--- 
- We are now ready to connect to the web GUI but first we will need to configure the Cisco switches.
	- We will configure the WLC on the ***Core*** switch in ***MDF 1*** and APs on the ***Access*** switch in ***IDF 1***
- Unplug ***Console cable*** from the WLC ***Console*** port.
- Connect the SFPs into ***Port 1*** on the WLC and Giga port ***G1/0/1*** on the Cisco Catalyst 3750 switch. 
	- Remember: when you connect the WLC gigabit port, make sure it is connected to the switch gigabit port only. If you connect the WLC gigabit Ethernet to the Switch FastEthernet port then it does not work.

#### MDF 1 Multilayer Switch mlsMDFSeaIceHQ01 Config
- Connect the WLC from ***Port 1*** of the WLC to ***MDF 1 Core Switch mlsMDFSeaIceHQ01*** port  ***G1/0/1***.

![[Pasted image 20230707214458.png]]
Figure 3-1

- Connect the connect the ***Console Cable*** to ***MDF 1 Core Switch mlsMDFSeaIceHQ01 Console Port*** on the back of the switch.

![[Pasted image 20230707223100.png]]
Figure 3-2

- Turn on the switch and access the devices CLI per instructions in Figure 1-4 "***Section 2: Establish Serial Connection***". If you closed the COM session re-follow all steps in ***Section 2***.
- The following configurations assumes you already have the core switch configured and are just adding the WLC to the network management VLAN.
- Once connected configure a dedicated port as a trunk to the WLC as follows. (you can use any port that works for you)

NOTE: For more information about the DHCP configurations we made see ***section DHCP Info***.

```kotlin
// Change the port to your respected available port

interface g1/0/1
    description toWLC
    switchport trunk encapsulation dot1q
    switchport mode trunk
    switchport trunk allowed vlan 10,60
    shutdown
    no shutdown
exit 

// DHCP 
ip dhcp pool WireLessAP10.1.60.0/22
	network 10.1.60.0 255.255.252.0
	default-router 10.1.60.1
	address 10.1.60.1 client-id 11
	address 10.1.60.2 client-id 12
	address 10.1.60.3 client-id 13
	address 10.1.60.4 client-id 13
	option 43 hex f1040a010a04

end 
write memory

```
CONFIG 3-1

- Make sure configurations where successful.
- Unplug the ***Console Cable*** from ***MDF 1 Core Switch mlsMDFSeaIceHQ01***.

#### IDF Access Switch wgsIDFSeaIceHQ01 Config
- Connect AP to port of choice. I used interface  ***fa3/0/45*** on the ***IDF Access Switch wgsIDFSeaIceHQ01*** .

![[Pasted image 20230707223536.png]]
Figure 3-3

- Make sure ***IDF Access Switch wgsIDFSeaIceHQ01*** is turned on and console into the back of  ***IDF Access Switch wgsIDFSeaIceHQ01***  per instructions in Figure 1-4 "***Section 2: Establish Serial Connection***". If you closed the COM session re-follow all steps in ***Section 2***.

![[Pasted image 20230707223019.png]]
Figure 3-4

- Configure the AP ports as follows.
	- This IDF only uses one AP but you can configure a range of interfaces depending on amount of APs needed.


```kotlin

// Single Interface 

interface fa3/0/45
    description wifi_AP
    switchport access vlan 60
    switchport mode access
    spanning-tree portfast
    spanning-tree bpduguard enable
    shutdown
    no shutdown
end 
write memory


// Multiple Interfaces

interface range fa3/0/45-46
    description wifi_AP
    switchport access vlan 60
    switchport mode access
    spanning-tree portfast
    spanning-tree bpduguard enable
    shutdown
    no shutdown
end 
write memory

```
CONFIG 3-2

- Make sure configurations where successful.
- Unplug the ***Console Cable*** from the ***IDF Access Switch wgsIDFSeaIceHQ01***.


### Section 5: Connect to Web GUI and configure
----

- Over view of web GUI configurations we will perform. Move on if this doesnt make sense and refer back to image after the final process for a better understanding of what was done. (Figure 4-1)

![[Pasted image 20230709163741.png]]
Figure 4-1

- Install an ethernet cable from PC to the ***SP*** connector on the Wireless Access Controller. (Figure 4-2)

![[Pasted image 20230707224547.png]]
Figure 4-2

- Change your PC ethernet IP address settings to any IP in the subnet you set the Service Port (SP) of the WLC to as long as it is not the same address of the Service port, network address or the broadcast address.
	- WLC Service Port Address: 192.168.0.2/24
	- Gateway: 192.168.0.1/24
	
 - EX:

![[Pasted image 20230707225028.png]]
Figure 4-3

- In your web browser type in the IP address you set the Service Port (SP) IP address to. 

![[Pasted image 20230707225443.png]]
Figure 4-4

- Login
- Verify the ***Port 1*** is green.
	- Troubleshoot CLI or Switch configurations as well as Cable integrity if port is not active. 

![[Pasted image 20230707225636.png]]
Figure 4-5

- Navigate to  ***Statistics*** in left option table. 
- Click ***AP Join*** 
- Double check the AP has joined. 
	- This may take a second for the AP to become active. If after some time the AP does not join check you port configurations on the switches.
	
![[Pasted image 20230707225936.png]]
Figure 4-6

#### Create Virtual interface
- We will now create a virtual interface to allow on our port 1 the ability to receive trunk encapsulated traffic on VLAN 60. We will later attach this interface object to a WLAN we create.
- Navigate to the ***CONTROLLER*** tab on the top bar. 
- Select ***New*** button in upper right corner.

![[Pasted image 20230709164942.png]]
Figure 4-7

- Name the interface and add the ***VLAN_ID*** click ***APPLY***. 

![[Pasted image 20230707233304.png]]
Figure 4-8

- Select the port number you wish to attach the Virtual interface to. We used ***Port 1*** for our configurations. (If following step by step do what we do)
- Fill out the ***Interface Address*** & ***DHCP Information***. 
	- The address used here will be a static IP from VLAN 60. (refer to CONFIG 3-1 to see static IP for DHCP pool)

![[Pasted image 20230709165347.png]]

- Click Apply in the right corner.![[Pasted image 20230707230629.png]]

#### Create a WLAN
- Navigate to ***WLAN*** on top bar
- Select option ***Create New*** Click ***Go***
![[Pasted image 20230707231131.png]]
Figure 4-9

- Type Wireless Local Area Network Name & SSID name you wish to advertise.

![[Pasted image 20230707230352.png]]
Figure 4-10

- Click Apply in the right corner.![[Pasted image 20230707230629.png]]
- Under the ***General*** tab select ***Status: [X]Enable*** 
- leave everything else the same. (make sure broadcast SSID is checked)

![[Pasted image 20230707234238.png]]
Figure 4-11

- Navigate to the ***Security*** tab if you wish to assign a password. Skip otherwise.
- Click the ***[X] PSK*** box if you want a Wi-Fi Protected Access Pre-Shared Key or WPA-PSK also know as a password for access to the network. (Figure 4-9)

![[Pasted image 20230707230517.png]]
Figure 4-12

- Click Apply![[Pasted image 20230707230629.png]]

NOTE: The menu will not change after the changes are applied.


#### Associate AP group to WLAN
- Navigate to the ***Advanced*** tab on the in the left table.
- Click on ***AP Groups*** 
- Select ***Add Group***

![[Pasted image 20230707232411.png]]
Figure 4-13

- Add name for a grouping of APs that we will attach to the WLAN created (Figure 4-11)
- Click ***Add***

![[Pasted image 20230707232755.png]]
Figure 4-14

- Click ***Add Group*** far right button.

- Navigate to the ***AP Groups/WLANs*** tab Verify the SSID and Virtual Interface is selected.
- Click ***Add New*** 
- Select interface and SSID
- Click ***Add***

![[Pasted image 20230707234428.png]]
Figure 4-15

- Figure 4-16 illustrates successful WLAN association to AP Group. Move to next instruction.

![[Pasted image 20230707234523.png]]
Figure 4-16

- Navigate to ***AP Groups/APs*** tab.
- Check the associated with the AP you wish to add to this new group. 
	-  [ X ] AP7c69.f660.10a0 default group 
	- Click add APs

![[Pasted image 20230707234635.png]]
Figure 4-17

- Associating the AP to the WLAN will cause the AP to auto configure. The AP will flash through a range of colors (yellow, blue, green. May not be in that exact order). 
- Once successful the AP should be green.  

![[Pasted image 20230709185112.png]]

- Figure 4-18 illustrates the AP group was added. 

![[Pasted image 20230707235335.png]]
Figure 4-18

- We have now successfully associated the APs to the WLAN of our choice.
- EXTRA VERIFICATION: You can verify that the AP has ***Joined*** in the ***Monitor*** tab on the top bar. 
	- Navigate to ***Statistic/AP join*** tab in the left table. 
	- The AP should be green and show ***Joined***.

![[Pasted image 20230709185443.png]]
Figure 4-19

#### Disable DHCP Proxy
- Navigate to ***CONTROLLER*** tab in the upper bar.
- Select ***Advanced*** option in the table to the left.
- Select DHCP
- Disable DHCP Proxy (uncheck the box)

![[Pasted image 20230709182659.png]]
Figure 4-20

#### Save Configurations
- Click ***Save Configurations*** selection in the upper right hand side of the GUI.

![[Pasted image 20230707235710.png]]


### Test The configurations.
---

- On your PC turn the WI-FI on.
- Look for the SSID name you configured 
- Select the network.
- Enter password. (PKE ASCII string we configured)

![[Pasted image 20230707235811.png]]

- Ping a device inside Terminal. 
	- We are pinging the mlsMDFSeaIceHQ01 in this example. This is our priority core switch.

![[Pasted image 20230709185901.png]]

#### CONGRADULATIONS YOU HAVE CONFIGURED THE WLC!

##### Creature: Aaron Carroll


### Section 6: DHCP Info
--- 

#### Cisco IOS® DHCP Server 

##### Cisco Aironet APs (Cisco IOS)
The following Section is not my work. Reference to the Cisco article can be found in the link below.
https://www.cisco.com/c/en/us/support/docs/wireless-mobility/wireless-lan-wlan/97066-dhcp-option-43-00.html

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

The hexadecimal string in step 3 is assembled as a sequence of the TLV values for the Option 43 sub option: Type + Length + Value. Type is always the sub option code 0xf1. Length is the number of controller management IP addresses times 4 in hex. Value is the IP address of the controller listed sequentially in hex.
    
For example, suppose there are two controllers with management interface IP addresses, 192.168.10.5 and 192.168.10.20. The type is 0xf1. The length is 2 * 4 = 8 = 0x08. The IP addresses translate to c0a80a05 (192.168.10.5) and c0a80a14 (192.168.10.20). When the string is assembled, it yields f108c0a80a05c0a80a14. The Cisco IOS command that is added to the DHCP scope is:
    
```
option 43 hex f108c0a80a05c0a80a14
```

##### Our Example 
```kotlin
// for IP 10.1.10.4
option 43 hex f1040a010a04
```



### Section 7: Overview of the WLC Discovery and Join Process
----

The following Section is not my work. Reference to the Cisco article can be found in the link below.
https://www.cisco.com/c/en/us/support/docs/wireless/5500-series-wireless-controllers/119286-lap-notjoin-wlc-tshoot.html

In a Cisco Unified Wireless network, the LAPs must first discover and join a WLC before they can service wireless clients.

However, this presents a question: how did the LAPs find the management IP address of the controller when it is on a different subnet?

If you do not tell the LAP where the controller is via DHCP option 43, Domain Name System (DNS) resolution of **`` 'Cisco-capwap-controller.local_domain` ``**, or statically configure it, the LAP does not know where in the network to find the management interface of the controller.

In addition to these methods, the LAP does automatically look on the local subnet for controllers with a 255.255.255.255 local broadcast. Also, the LAP remembers the management IP address of any controller it joins across reboots. Therefore, if you put the LAP first on the local subnet of the management interface, it finds the controller management interface and remembers the address. This is called priming. This does not help find the controller if you replace a LAP later on. Therefore, Cisco recommends use of the DHCP option 43 or DNS methods.

The LAPs always connect to the management interface address of the controller first with a discovery request. The controller then tells the LAP the Layer 3 AP-manager interface (which can also be the management by default) IP address so the LAP can send a join request to the AP-manager interface next.

The AP goes through this process on startup:

1. The LAP boots and DHCPs an IP address if it was not previously assigned a static IP address.
2. The LAP sends discovery requests to controllers through the various discovery algorithms and builds a controller list. Essentially, the LAP learns as many management interface addresses for the controller list as possible via:
    
    1. DHCP option 43 (good for global companies where offices and controllers are on different continents).
    2. DNS entry for `cisco-capwap-controller` (good for local businesses - can also be used to find where brand new APs join) If you use CAPWAP, make sure there is a DNS entry for `cisco-capwap-controller`.
    3. Management IP addresses of controllers the LAP remembers previously.
    4. A Layer 3 broadcast on the subnet.
    5. Statically configured information.
    6. Controllers present in the mobility group of the WLC the AP last joined.
    
    From this list, the easiest method to use for deployment is to have the LAPs on the same subnet as the management interface of the controller and allow the LAPs Layer 3 broadcast to find the controller. This method must be used for companies that have a small network and do not own a local DNS server.
    
    The next easiest method of deployment is to use a DNS entry with DHCP. You can have multiple entries of the same DNS name. This allows the LAP to discover multiple controllers. This method must be used by companies that have all of their controllers in a single location and own a local DNS server. Or, if the company has multiple DNS suffixes and the controllers are segregated by suffix.
    
    DHCP option 43 is used by large companies to localize the information by the DHCP. This method is used by large enterprises that have a single DNS suffix. For example, Cisco owns buildings in Europe, Australia, and the United States. In order to ensure that the LAPs only join controllers locally, Cisco cannot use a DNS entry and must use DHCP option 43 information to tell the LAPs what the management IP address of their local controller is.
    
    Finally, static configuration is used for a network that does not have a DHCP server. You can statically configure the information necessary to join a controller by the console port and the APs CLI. For information on how to statically configure controller information by use of the AP CLI, use this command:
    
```
    AP# capwap ap primary-base <WLCName> <WLCIP>
```  

For information on how to configure DHCP option 43 on a DHCP server, refer to ***Section 6: DHCP Info***

3. Send a discovery request to every controller on the list and wait for the controller discovery reply which contains the system name, AP-manager IP addresses, the number of APs already attached to each AP-manager interface, and overall excess capacity for the controller.
4. Look at the controller list and send a join request to a controller in this order (only if the AP received a discovery reply from it):
    1. Primary Controller system name (previously configured on LAP).
    2. Secondary Controller system name (previously configured on LAP).
    3. Tertiary Controller system name (previously configured on LAP).
    4. Primary controller (if the LAP has not been previously configured with any Primary, Secondary, or Tertiary controller names. Used to always know which controller is a brand new LAPs join).
    5. If none of the previous conditions are seen, load balance across controllers by use of the excess capacity value in the discovery response.
        
        If two controllers have the same excess capacity, then send the join request to the first controller that responded to the discovery request with a discovery response. If a single controller has multiple AP-managers on multiple interfaces, choose the AP-manager interface with the least number of APs.
        
        The controller responds to all discovery requests without a certificate chec or AP credentials. However, join requests must have a valid certificate to get a join response from the controller. If the LAP does not receive a join response from its choice, the LAP tries the next controller in the list, unless the controller is a configured controller (Primary/Secondary/Tertiary).
        
5. When it receives the join reply, the AP checks to make sure it has the same image as that of the controller. If not, the AP downloads the image from the controller and reboots to load the new image and starts the process all over again from Step 1.
6. If it has the same software image, it asks for the configuration from the controller and moves into the registered state on the controller.
    
    After you download the configuration, the AP can reload again to apply the new configuration. Therefore, an extra reload can occur and is a normal behavior.