- [[#About|About]]
- [[#Initial CLI Configuration|Initial CLI Configuration]]
- [[#Log onto the ISE GUI|Log onto the ISE GUI]]

##### About
----
Cisco Identity Services Engine (ISE) runs on a customized Linux-based operating system specifically tailored for the ISE platform. As such, end users generally do not have direct access to the underlying OS as you would with a general-purpose operating system.

The ISE platform includes the necessary services and configurations to perform its identity and access control functions. The GUI and CLI (Command-Line Interface) provided by ISE are designed to administer these functions rather than the underlying OS.

This setup allows Cisco to maintain tight control over the security and performance of the ISE platform, ensuring it operates effectively as a network security component. But it's important to note that while the system is Linux-based, users should not expect to be able to perform typical Linux operations unless specifically provided for by the ISE interface.


##### Initial CLI Configuration
----
- Download ISE software
- Install ISE on server or inside ESXI
- Log into the CLI 
- select SETUP
- You will need to following for any initial setup
	- Hostname
	- IP address (Static IP within subnet of network segment desired)
	- IP netmask
	- Default gateway
	- default DNS domain (EX: ise.SeaIceCreamery.com)
	- primary nameserver address (EX: 10.1.10.4) (address of DNS server)
	- Secondary nameserver address
	- NTP server: (EX: pool.ntp.org)
	- Another ntp server?
	- [timezone](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FSystem%20Time%20Zones) \[UTC]:  (East: `EST5EDT` Central: `CST6CDT` West: `PST8PDT`)
	- Enable SSH Y/N [N]: Yes (default is NO)
	- Username:
	- Password:
	- Password again:

- This will make the ISE install and initialize. You should be able to ping out of the network at this point unless something is not properly set up. If you are using a VM in ESXI make sure the vSwitch NIC is configured properly. Issure found [here](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FProjects%2FISE%2FvSphereNetwork)

- double check all the services started as well as the NTP server has synchronized. ***Make sure the time does not differ from the Active directory server by more then 5 minutes.***

```kotlin
show application status ise
```

EX: 
![[Pasted image 20230720142858.png]]

- Time verification commands

```kotlin
show ntp
show clock
```

![[Pasted image 20230720142956.png]]


##### Log onto the ISE GUI
----
- ***THIS MUST BE DONE INSIDE A JUMP HOST THAT IS CONNECTED TO THE APPLIANCE AND IS WITHIN ITS OWN SUBNET.***

```kotlin
https://<hostname>.DomainName.com


Ex:
hostname  == ise-1
Domain name == ise.astontech.com 

https://ise-1.ise.astontech.com

```

- Once at the GUI log on using the same credentials added in the CLI.

![[Pasted image 20230724103956.png]]

`https://ise-1.ise.astontech.com`