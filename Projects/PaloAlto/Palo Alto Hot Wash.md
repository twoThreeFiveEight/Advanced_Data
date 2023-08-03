I was tasked with installing a Palo Alto firewall between the edge router rtrIL029a01a03 and the two multi layer switches mlsIL029a02a01 and mlsIL029a02a02. This was to allow granular control over all traffic moving from a trusted zone to an untrusted zone vise versa. I will outline my process in this debrief. 

#### Step 1: 
----
- Design the IP scheme and build the new topology to accommodate the firewall. 
	- Trusted Interfaces: 
		- I Recycled the subnets10.2.129.112/30 and 10.2.129.16/30 that once bypassed the firewall and pair them with my trusted interfaces on the firewall. This allowed me to avoid reconfiguration of the corresponding interfaces inside the multi layer switches. 
		- Once configured I expanded these interfaces to participate in OSPF area 0.
	- Untrusted Interfaces:
		- Created a IP scheme that would was blackholed my network summary but would not be a duplicate. I settled on the subnet 10.2.129.20/30. 

- Redesign the diagram to represent the new plans.
	- Below you can see the larger OSPF area 0 as well all the interface subnets mentioned above. 

![[Screenshot 2023-06-29 141720.png]]

##### Multi Layer switch reconfigurations
- If you are working on the Infoblox project you must make sure that you appropriately reconfigure the devices that connect to the PA-VM-1 Palo Alto firewall so that the OSPF redistributions do not effect the network. 
	- The two multi layer switches original configurations where to have `default-information originate` set with static routes  for the default route 0.0.0.0/0 and a network summary of 10.0.0.0/8 pointing to the interfaces ***10.2.129.117, and 10.2.129.113***. We do not want these routers to own theses routes anymore rather have OSPF advertise these statics from the firewall to the multi layer switches.

- Example of this removal below:
	
##### mlsIL029a02a01
```kotlin
mlsIL029a02a01(config)# no ip route 0.0.0.0 0.0.0.0 10.2.129.113
mlsIL029a02a01(config)# no ip route 10.0.0.0 255.0.0.0 10.2.129.113

mlsIL029a02a01(config)# router ospf <ID>
mlsIL029a02a01(config-router)# no default-information originate
mlsIL029a02a01(config-router)# redistribute connected subnets
```
##### mlsIL029a02a02
```kotlin
mlsIL029a02a02(config)# no ip route 0.0.0.0 0.0.0.0 10.2.129.117
mlsIL029a02a02(config)# no ip route 10.0.0.0 255.0.0.0 10.2.129.117

mlsIL029a02a02(config)# router ospf <ID>
mlsIL029a02a02(config-router)# no default-information originate
mlsIL029a02a02(config-router)# redistribute connected subnets
```


##### rtrIL029a01a03 reconfiguration
- I had to remove the previous interfaces and then make sure to add the appropriate interface with subnet to allow communication to the Palo Alto firewall. I will leave this up to who ever reads this to decide what is best for there network.

#### Step 2:
----
After finishing the design and reconfigurations of the multi layer switches and edge router #3 its time to start the configurations on Palo Alto. Before starting download the "UbuntuDesktopGuest" Linux device inside my GNS3 environment.

###### How to Install Ubuntu Desktop Guest:
- Click the Gecko symbol in the top left corner of GNS3
- Click add new template
- Click ***Install new appliance from the GNS server***
- search for ubuntu in the on the line marked ***Filter***
- scroll down to ***Ubuntu Desktop Guest*** and click install on the box to the right.
- Click Download on the ***Ubuntu 20.04 (64bit).vmdk*** version. This will navigate you outside of GNS3 environment. Click yes to pop up stating this.
- Download the ***Ubuntu 22.04 Jammy Jellyfish*** ISO zip from http://www.osboxes.org/ubuntu/
- once downloaded navigate to the zip file inside your downloads and unzip the file. You may need to install 7z to unzip this 7zip file. 
- After unzipping the file place it anywhere that you can remember inside you documents and navigate to back to the GNS3 environment. Next to the ***Download*** button in GNS3 there is an ***Import*** button. Click the ***Import*** button and find and click on the folder you just unzipped. There will be a prompt that the hash does not match, Just click continue.
- The machine should now be available inside your regular **+** tab (add device menu) in GNS3. You will need to right click on the device and click ***configure*** to increase the CPU to a minimum of two, Increase the RAM to above 4096 and most importantly change the ***Qemu binary*** tab from ***/usr/bin/qemu-system-i386*** to the ***/usr/bin/qemu-system-x86_64*** option.

##### How to install the Palo Alto Firewall PA-VM-1:
- Click on the + tab (add device tab) inside the GNS3 environment.
- Navigate down to the PA-VM-1 computer and add to the environment.
- Right click the PA-VM-1 that you added and increase the RAM to above 4096 and increase the CPU usage to a minimum of 2.

##### Make the connection
- Now connect a cable from the management port on the PA-VM-1 to the eth0 port on your ubuntu desktop

By this point you should have something that looks similar to this.
![[Screenshot 2023-06-29 153309.png]]


#### Step 3:
----
Here we need to connect to the Palo Alto Firewall. The firewall has a Management port specifically for this purpose. Through this port we can connect to the Palo Alto GUI through our web browser. Before we can access the GUI we will need to telnet into the command line of the PA-VM-1 and VNC into the Ubuntu Desktop Guest to configure these devices so they point to the same gateway and are both within each others subnet.

##### Palo alto CLI Configurations:
- Telnet into the firewall
- Wait at least 2 minutes before attempting to type any passwords. The Palo Alto VM in this lab takes a while to boot and will deny the password even if it is prompting you for it. Only when the device has fully loaded will the password work so be patient. 

	- Failed attempt because password tried before machine started completely 
	 ![[Screenshot 2023-06-29 154942.png]]
	- Successful try after waiting
	 ![[Screenshot 2023-06-29 154845.png]]
- Once the device is ready type in the username/password -> admin/admin. 
- Assign new password
	- A good suggestion is to use your first name followed by 123 where the first letter is a capital. 
	- Ex: Aaron123

- Now that you are in we will need to configure the device to use the GUI through http or https from the Management port. By default http and https is disabled you need to enable. The following commands are how you disable these.
```kotlin		
configure
set deviceconfig system type static// No DHCP requests -> Makes static
set deviceconfig system service disable-http no
set deviceconfig system service disable-https no
```
	
 - Now we need to point the managements gateway to the same gateway the ubuntu desktop will point to. The address is arbitrary as long as it is with the interface subnet of both the PA-VM-1 management interface and the IP and subnet of the Ubuntu desktop.  By default the Palo alto is using the 192.168.0.0/24 subnet. The first command is all one line so if copy and pasting separates the command then you need to edit it so it gets  installed all at once. Save the setting with commit. Remember You can assign the Gateway to what ever address that is within the 192.168.0.0/24 subnet below is just how I did it.
	
```kotlin

set deviceconfig system ip-address 192.168.1.2 netmask 255.255.255.0 default-gateway 192.168.1.1 dns-setting servers primary 8.8.8.8

// save settings with commit
commit
```

- This finishes the commands needed inside the firewall.

##### Configure the network settings on Ubuntu Desktop
- Before entering make sure you increased the RAM, CPU, and changed the processor to be the ***/usr/bin/qemu-system-x86_64*** version.
- VNC into the desktop. I used MobaXterm for this task. 
- Once inside use the password ***osboxes.org***. 
- Navigate to the ***setting*** menu select ***network***. Configure the network to have ***dns: 8.8.8.8, IP: 192.168.0.3, Netmask 255.255.255.0, Gateway: 192.168.1.1***.
	- The IP can be any address within the subnet that is not the gateway or the PA-VM-1 address.
- Navigate to the Firefox browser and type the IP address of the PA-VM-1. If you  followed these instructions IP address scheme you would type in ***192.168.1.2***. 
- The Palo Alto GUI should appear. You will access the GUI with the same password you set in the CLI.

### Step 4:
----
From this point forward we will be configuring the Firewall. Every time we wish to have a configuration overwrite 

It is now time to set up our interfaces in Palo Alto so we can have continuity with the rest of the network. 

##### !!! IMPORTANT INFO !!!
- An important note before we start is once in the palo alto GUI there is a ***?*** option in the upper right corner of every window. This will direct you to the information pertaining directly to the tab/window you are currently working in. 

Navigate to the network tab and select the interfaces item in the box on the left. 

![[Pasted image 20230629170503.png]]

- Click on the interface number you wish to configure.
- Follow the prompts for what you wish to add. A yellow tint to the option box means that option is required.
-  Add the type of interface. 
- Ignore the Virtual Router and Security Zone for now. We will cover it later on.


![[Screenshot 2023-06-29 172613.png]]

- Add the IPv4 address associated to that interface
- Click OK.

![[Screenshot 2023-06-29 173002.png]]

- Do this for all interfaces.

- Now Lets create Zones.
	- Security zones are a logical way to group physical and virtual interfaces on the firewall to control and log the traffic that traverses specific interfaces on your network. An interface on the firewall must be assigned to a security zone before the interface can process traffic. A zone can have multiple interfaces of the same type assigned to it (such as tap, layer 2, or layer 3 interfaces), but an interface can belong to only one zone.
	- Policy rules on the firewall use security zones to identify where the traffic comes from and where it is going. Traffic can flow freely within a zone but traffic cannot flow between different zones until you define a Security policy rule that allows it. To allow or deny inter-zone traffic, Security policy rules must reference a source zone and destination zone (not interfaces) and the zones must be of the same type; that is, a Security policy rule can allow or deny traffic from one Layer 2 zone only to another Layer 2 zone.

- Click on the Zone option in the box on the left.

![[Pasted image 20230629173610.png]]

- Click on the ***Add*** button on the bottom left to create a Zone. 
- Make a logical grouping of all interfaces you wish to participate in this zone. Here I have my ***L3-Trust*** zone. Every interface in this zone in ***inside*** my network area and it trusted. 

![[Screenshot 2023-06-29 173632.png]]

- Do this for how ever many zones you feel is best for your needs. 
	- I only use two zones for this project. Trusted zone and an untrusted zone.

- Now lets create Interface management.
	- NOTE: This is strictly to assign what services we wish to allow through these interfaces to manage our firewall. This is not for traffic going to the internet but merely what technique an administrator will use to access the firewall to change any settings.
	- An Interface Management profile protects the firewall from unauthorized access by defining the services and IP addresses that a firewall interface permits. You can assign an Interface Management profile to Layer 3 Ethernet interfaces (including subinterfaces) and to logical interfaces (aggregate group, VLAN, loopback, and tunnel interfaces).
	
- Do not attach an interface management profile that allows Telnet, SSH, HTTP, or HTTPS to an interface that allows access from the internet or from other untrusted zones inside your enterprise security boundary. This includes the interface where you have configured a GlobalProtect portal or gateway; GlobalProtect does not require an interface management profile to enable access to the portal or the gateway.

- Select Interface Mgmt option from the table on the left.

![[Pasted image 20230629174935.png]]

- Click on the ***Add*** button on the bottom left to create a profile
- Here you can assign ways to communicate with you firewall and what addresses are allowed. In my case I am allowing every checked box service and the entire network to be able to access my firewall. We will assign this to my interfaces that are in the ***Trusted*** zone.

![[Pasted image 20230629175109.png]]

- I also created an outside interface management profile and only allow my edge route to have the ability to ping the firewall.

![[Pasted image 20230629175409.png]]


- Lets attach these zones and management profiles to the interfaces now.
- Navigate back to the ***interface*** option in the left hand table. 
- NOTICE we do not have to assign our zone to the interface because when we associated the interface with the zone while creating the zone it linked the items together.
- We will have to manually attach our management profiles to the interfaces. Click on each interface then select the ***Advanced*** tab. Click on the ***Management Profile*** tab and select the Profile you want for this interface. 
- WARNING, take note to not assign a outside interface a management profile that allows a intruder to access the firewall and change the configurations. 

![[Pasted image 20230629175926.png]]

- Create a Loopback
	- Click on the ***Loopback*** tab in the ***interface*** options.
	- Click ***Add*** button.

![[Pasted image 20230629180354.png]]

- Fill out the information you will need. This loopback is available to your network so be cautious not to assign it a IP that is a duplicate to any IP within the networks subnets. 
- Attach the security zone to loopback.
- fill out the IPv4 section and press ***OK

![[Pasted image 20230629180738.png]]


- Lets now create some ***Objects***. 
	- An address object can include either IPv4 or IPv6 addresses (a single IP address, a range of addresses, or a subnet), an FQDN, or a wildcard address (IPv4 address followed by a slash and wildcard mask). An address object allows you to reuse that same address or group of addresses as a source or destination address in policy rules, filters, and other firewall functions without adding each address manually for each instance. You create an address object using the web interface or CLI; changes require a commit operation to make the object a part of the configuration.
- You are allowed to be creative here and I would suggest making every prefix you will ever reference a object so that you can reference the object instead of possibly making a mistake by manually imputing the wrong IP. Just be sure the IP you use here is absolutely correct. A cool thing is that if you made a mistake you can fix the issue in a single place (here at the object tab) and it will fix the address in every place it was referenced

- Navigate to the ***Objects*** tab up top.
- Click ***Add*** button to create the object

![[Pasted image 20230629181054.png]]

- Add your default route and any other address you will need to make a static route for.

![[Screenshot 2023-06-29 181534.png]]

- Lets now create a Virtual Router
	- The firewall requires a virtual router to obtain routes to other subnets either using static routes that you manually define, or through participation in Layer 3 routing protocols (dynamic routes). Each Layer 3 interface, loopback interface, and VLAN interface defined on the firewall must be associated with a virtual router. Each interface can belong to only one virtual router.

- Navigate back to the ***Network*** tab at the up bar.
- Click on the ***Virtual Router*** option in the left hand table.

![[Screenshot 2023-06-29 181732.png]]

- Click on ***Add***
- On the ***Router Settings*** tab click associate all active interfaces to this menu. 

![[Pasted image 20230629182153.png]]

- Click on the ***Static Routes*** tab 
- Click ***Add***

![[Pasted image 20230629182316.png]]

- We will now associate the ***Objects*** we created to the static route.
- Add a name then for the ***Destination*** add the object you wish to install into the routing table as a static route.

 ![[Screenshot 2023-06-29 182529.png]]

- Add the ***Interface*** that the static route can be found on.

![[Pasted image 20230629182720.png]]

- Finally add the next hop 
- Click OK
- Repeat these steps for all the statics you wish to have and wish to redistribute.
 
![[Screenshot 2023-06-29 182805.png]]

- Click on the ***Redistribution Profile*** tab
- Click ***Add***

![[Screenshot 2023-06-29 182951.png]]

- If you are redistributing anything it is imperative that you select the ***Redist*** tab 
- IMPORTANT add all the interfaces that are associated with statics even if you are not redistributing information through these ports. They need to be there for the static to be redistributed from them to another interface.
	- Interface 1/3 will not be redistributing any information but the static default route lives here so I needed to include it in the list.

![[Pasted image 20230629183159.png]]

- Click OK

- Click on the ***OSPF*** tab
- Click ***ENABLE*** to enable OSPF
- MAKE SURE ***Reject Default Route*** in unchecked
- Click ***Add***

![[Pasted image 20230629183621.png]]

- Add the area that you have the firewall in for OSPF. The labeling method is different then Cisco in that the area is a 4 octet numbering system. 
	- Area 0 == 0.0.0.0
	- Area 1 == 0.0.0.1
	- Area 2 == 0.0.0.2
	- and so forth ......
- Keep the ***Type*** as ***Normal*** unless you have a crazy old router that cannot handle a large Link State Database (LSDB)

![[Pasted image 20230629184111.png]]

- Click on the ***interface*** tab
- add all interfaces to this tab I mean **ALL** 

![[Pasted image 20230629184348.png]]

- **CRITICAL:**  In this next example I am going to show interface 1/3 as my example. This interface is not directly participating in OSPF but it has the default static route attached to its from the next hop. 
	- **YOU MUST ENABLE THIS INTERFACE**
	- If you do not include and **ENABLE** this interface and even if you do not plan to send LSAs through it then the default will not be redistributed. Palo Alto has most of their parameters as implicit denies. This is no exception.
- I am selecting ***Passive*** as well because I do not wish to advertise my private IP addresses to the internet if ***NAT*** is set up.
- ***Enable*** all interface that you have in this area and configure them accordingly. The ones that are not participating in LSAs make passive but also ***Enable***.

![[Pasted image 20230629184741.png]]

- Once finished click ***OK*** 
- Click OK to Exit the ***Area*** creation.
- Click the tab ***Export Rules*** while still inside the ***OSPF*** portion of the ***Virtual Router (Image Below)
- Click ***Enable*** box and the ***Allow Redistribution Default Route*** box. 
- Click ***Add***

![[Pasted image 20230629185439.png]]

 - Add the ***Redistribution Profile*** you made for the default route earlier and press ***OK***

![[Pasted image 20230629185819.png]]

- Click ***OK*** until you exit the Virtual Router completely. 
- Now we will create our Security policies.
	- Security policy rules reference security zones and enable you to allow, restrict, and track traffic on your network based on the application, user or user group, and service (port and protocol). By default, the firewall includes a security rule named [rule1](https://docs.paloaltonetworks.com/pan-os/9-1/pan-os-web-interface-help/policies/policies-security#) that allows all traffic from the Trust zone to the Untrust zone.
- Navigate to the ***Policies*** tab on top bar.
- Click the ***Security*** tab option in the left table.

![[Screenshot 2023-06-29 185116.png]]

- Click ***Add*** 
- Ignore my configurations 
- Create a policy that allows everything and is universal. This is to test our router configurations. 
- The next three images shows the process. in each tab all the way up to the ***Actions*** tab just select ***Any*** option for all tabs. An example is the second picture in this sequence.

![[Pasted image 20230629190326.png]]

![[Pasted image 20230629190348.png]]

- Click the ***Allow*** in the ***Actions*** tab.
- Then press OK.

![[Pasted image 20230629190422.png]]


- Now we will test our routing. 
- Telnet into the mlsIL029a02a01 and mlsIL029a02a02 and the PA-VM-1

### Step 5: Verify Routing tables
----

- Make sure that the firewall is advertising our 10.0.0.0/8 and 0.0.0.0/0 routes. The first line illustrated success in the picture below. I will not show the other Multi layer switch but make sure you are receiving these routes otherwise the network will have issues.

##### mlsIL029a02a02
![[Pasted image 20230629191113.png]]

- Check the routing table for the PA-VM-1
- You may need to power the machine down in GNS3 and start it up again.
```kotlin
show routing route
```

###### PA-VM-1
![[Pasted image 20230629192516.png]]

### Ping from a client
- the next step is to install another Ubuntu Desktop as described earlier to some VLAN location within Infoblox. 
- Once installed set up the DNS to be 8.8.8.8 and set the IP to some address within the VLAN subnet you installed the machine. 
- I assigned the IP a static IP that is in the subnet of VLAN 1XX0.

![[Pasted image 20230629192848.png]]

- Verify you can access https://www.google.com from the Ubuntu Desktop client.
  
  ![[Pasted image 20230629193053.png]]

- Now that we are successful lets move on to the Security policies.

### Step 6: Security Policies.
----
We will need to enter back into the Palo Alto GUI and navigate to the ***Policies*** tab to start shutting down services to help protect our network. Do not forget about the implicit deny at the end of the Policy list. 

- Important note:
	- To allow pinging you MUST make a security policy explicitly allowing ***Application Ping and ICMP*** the best zone is universal for testing but shutting down ping for actual practice. 

- before we start adding policies lets take a look at definition of the ***Rule Types***
	- Three exist
		- Universal (default)
		- Interzone
		- Intrazone

#### The following illustrations should help with the understanding of these ***Rule types

#### Universal (Default)
----
![[Screenshot 2023-06-28 190810.png]]


#### Int***er***zone
---
![[Screenshot 2023-06-28 190727.png]]

#### Int***ra***zone
----
![[Screenshot 2023-06-28 190746.png]]


#### Creation of a Security policy
----
- Once inside the firewalls GUI and in the ***Policies*** tab under the ***Security Policy*** section  Click ***Add*** 
- Here you will select any options that apply to your rule. 
- Below is an example denying ***All*** ***http*** requests from within the zones and in-between the zones.
- Play around and click on the drop down menus to find different ***Applications*** you can allow or deny and well as ***Services*** 



![[Screenshot 2023-06-29 191731.png]]
![[Screenshot 2023-06-29 191743.png]]
![[Screenshot 2023-06-29 191836.png]]

![[Screenshot 2023-06-29 191803.png]]

#### Summary
----
This Mop illustrate all the steps I took to configure and test the network with the new security appliance installed. 