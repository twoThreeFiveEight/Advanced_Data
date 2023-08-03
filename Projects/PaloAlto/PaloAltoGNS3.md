- Download Ubuntu inside GNS for 20.04 
	- Unzip using 
	```sh
	# done on command line.
	7z 64Lib.7z
	```
	- Import unzipped downloaded ubuntu image. 
	- add UbuntuDesktopGuest to GNS3
		- Increase environment CPU usage to 2cpu's and 2gb RAM
- VNC into Ubuntu computer
	- set the network settings to manual. 
		- Ip to something within the subnet of the PA firewall. Default gateway point the common default gateway you will have the firewall point to.
```kotlin
ip: 192.168.1.2
subnet: 255.255.255.0
default-gateway: 192.168.1.1
```

- Add PA-VM-1 to GNS3 environment
	- Increase specs to 2cpu's and 4gb RAM
	- telnet into the environment
	- WAIT for it to load a long time
	- sign in 
		- Username/Password: admin/admin
	- Assign new password
		- password: Aaron123
	- Default http and https is disabled you need to enable
	```kotlin
		configure
		set deviceconfig system service disable-http no
		set deviceconfig system service disable-https no
	```
	- Set IP, netmask, default-gateway, dns. The below is all one line.
	```kotlin
	set deviceconfig system ip-address 192.168.1.3 netmask 255.255.255.0 default-gateway 192.168.1.1 dns-setting servers primary 8.8.8.8

	// save settings with commit
	commit
	```

- Go into the Linux VM and type the address of Palo Alto firewall you set inside the firewall into the browser.  YOU ARE NOW SIGNED INTO THE FIREWALL