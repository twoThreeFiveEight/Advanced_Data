### Dell Power Edge R410
----
#### Installing ESXI
- connect to display to display port on server.
- connect keyboard
- Start server and press ctrl-c when prompted to enter SAS configuration mode. 
	- Make sure that the ***adapter*** is enabled. if not enter the menu and ***Enable** it.
	- configure the sata drive into ***raid*** mode and set it to be ***Raid 1*** option.
- Download esxi 6.0 onto a usb.
	- restart the server with the usb installed and allow installation.

#### Configuring ESXI
- set the password to qwe123$!
- follow the prompt for the easy stuff. 
- once in the menu for ESXI enter the ***Configure Network*** area.
	- Set the IP to something inside your network management subnet and name the host inside the DNS area. 
		- My network management subnet is 10.1.10.0/28 where my default gateway is 10.1.10.1, I made sure to not interfere with any IPs that are reserved and ended up setting the address to 10.1.10.10/28. 
	- Set you computer you wish to use to some IP within the entire networks subnet. I am using the campus data address of 10.1.20.11/23. As long as everything in the network knows how to access vlan 10 (network management vlan) you will be able to connect to the server.

#### Signing into the server
- Install the ESXI vmSphere Client software. 
- Attach a ethernet cable to the Gb1 port on the back
	- do not attach this cable to the port with a ***wrench***.
- Enter the vmSphere client software and use the credentials username/password `root/qwe123$!` to sign in.
- once inside ***right click*** on the IP that is your server and select ***Create Virtual Machine***. 
- select ***typical*** installation
- select ok for network options
- select 40gb and thin provision 
- select the image you will install.
	- we will have to add this later
- keep select the remaining defaults and select ***Finish***

#### Installing the image
- Down load the image you wish to install.
- Once installed start the VM you created and at the top tool bar in vmShere Client click on the ***connect/disconnect CD/DVD devices on virtual machine*** tab. 
- Click on install from local
	- Find the image you installed and select it. 
	- Let the machine begin booting the image.
	- follow the prompt for installation.

#### Install mouse capabilities in the VM
- The VM must be running
- Inside the vmSphere app (Not the VM) click on ***inventory*** tab
	- Select ***virtual machine***
		- select ***guest***
			- select ***Install/Upgrade VMware tools***
- Now go into the virtual machine. 
	- Hit the ***windows key*** and push ***tab*** until you can click on ***Administrator tools***
	- ***Tab*** inside the window until you can select ***This PC***.
	- ***Tab*** until you can access the ***CD/DVD*** drive to install the guest tool kit.
	- once clicked press ***windows key*** pull up the ***task manager*** and select the installer. 
	- Follow the installer prompts. You will need to restart the guest. 
	- You are finished.

#### In 