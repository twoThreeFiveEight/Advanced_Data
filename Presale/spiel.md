##### LAN/WAN  
I’ve been doing Staff Aug and project work for some time now, I’ve done a lot of work with Cisco products, working LAN and WAN projects, I've also worked other vendors like Aruba or HP, Juniper and Arista. A lot of my work tends to be staff augmentation, but I have been brought on in the past for the duration of a project, usually including day one and day 2 support. So things like gathering requirements, documentation, LLD’s HLD’s, leading up to implementation and then eventually handling any handoff or KT before the project is closed out.
##### Security
In addition to that I’ve also done some security work, with mostly Palo Alto, setting up things like Global protect, User-ID, URL-filtering, and App-ID, but also I’ve worked on Cisco ASAs and Fortinet. I’ve also worked to implement ISE (ice) in environments to leverage access for wired, and wireless via 802.1X.Load 
##### Balancing
I’ve also done some work with Load Balancers, mostly, F5 but I’ve done some work with netscaler. 
That work was mostly operational and consisted of things like configuring VIPs, and server pools, configuring health monitors, and SSL offload.
##### Wireless
From a wireless standpoint I’ve worked with Cisco Aironet 2500, 3800s, as well as more recently I’ve done some work with the newer Cat 9800 controllers, as well as Aruba. I’ve done greenfield and brownfield deployments doing requirements gathering, drawing up heat maps using tools like Ekahau ***(ehk -a -how)***, and Prime, as well as pre and post deployment surveys, and of course, troubleshooting and supporting those environments.

That about sums up the work i have been doing.

[Palo Alto Global Protect](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FPalo%20Alto%2FGlobal%20Protect)
[Staff Aug](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FStaff%20Augmentation)
[Ekahau](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FSSL%20offload)
[Day one and day two](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FDay%20One%20%26%20Day%20Two%20Support)
[802.1x](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2F802.1x)
[SSL offload](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FSSL%20offload)
[Green Field and Brownfield](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FGreenfield%20Brownfield%20Deployments)

KT == Knowledge transfer

##### Migration
- Port based VS App Based [link here](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FFirewall%20ASA%20VS%20Palo%20Alto%20(App%20Based%20VS%20port%20Based))
	- Palo alto is APP based
		- deep packet inspection (DPI) techniques to identify the applications and associated risks in the traffic, regardless of the port or protocol being used
	- Cisco ASA is Port based
		-  primarily relies on port numbers and protocols to manage and secure network traffic. Uses ACLs
- Palo alto Uses a tool called Expedition. This allows you to upload a config file from other venders or other palo alto firewalls and convert them into the configs we need in the new firewall in which we needed the tool. 

##### SASE
- SASE is the convergence of wide area networking, or WAN, and network security services like CASB, [FWaaS](https://www.paloaltonetworks.com/cyberpedia/what-is-firewall-as-a-service) and [Zero Trust](https://www.paloaltonetworks.com/cyberpedia/what-is-a-zero-trust-for-the-cloud), into a single, cloud-delivered service model.

Patch Panel junFW2 junWGS2 cASA2 cISR6 cMLS15 cMLS16 cMLS17 cISR14 10 AMP PDU Cable Manager cISR10 cMLS10 cMLS1 cMLS6 cMLS7 cMLS8 PAfw cISR1 cISR1 cWLC2