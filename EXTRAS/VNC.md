SECTIONS: [VNC Viewer startup](#vnc%20viewer%20startup) | [reset VNC passwd](#reset%20vnc%20passwd) | [Finding VNCs using Nmaps](#nmap&vnc)

### About
----
VNC (Virtual Network Computing) is a system that allows you to remotely access and control a computer over a network. There are two main components of VNC: the VNC server and the VNC viewer. 

The VNC server is the software that runs on the remote computer and allows you to access its desktop environment from another computer. When you start the VNC server, it creates a virtual display that you can connect to using a VNC viewer. 

The VNC viewer is the software that runs on your local computer and allows you to connect to the remote computer running the VNC server. When you connect to the VNC server using the viewer, you can see and interact with the remote computer's desktop environment as if you were sitting in front of it. 

In summary, the VNC server is the software that runs on the remote computer to allow remote access, while the VNC viewer is the software that runs on your local computer to connect to the remote computer and display its desktop environment.

[Back to top](#about)
### VNC Viewer startup
-----

If the VNC server requires both a username and a password to access the remote device, you will need to provide both when you start the VNC viewer. To do this, you can use the following command:

```
vncviewer <ip-address>:<port-number> -username <username> -passwd /path/to/password/file
```

Replace `<ip-address>` and `<port-number>` with the IP address and port number of the VNC server, `<username>` with the username required to access the device, and `<path/to/password/file>` with the path to the file containing the VNC server password. 

When you run this command, you will be prompted to enter the password for the VNC server. Once you have entered the password, the TigerVNC viewer will connect to the remote computer and display its desktop environment

[Back to top](#about)
#### NO PASSWD needed startup
-----
Enter the following command to start the TigerVNC viewer:

```
   vncviewer <ip-address>:<port-number>
   
```

Replace `<ip-address>` with the IP address of the remote computer, and `<port-number>` with the port number that the VNC server is running on. For example:

```
   vncviewer 192.168.0.100:5901
   
```

4. When prompted, enter the password for the VNC server. Note: If you haven't set a password for the VNC server yet, you will need to do so before you can connect. 

5. Once you have entered the password, the TigerVNC viewer will connect to the remote computer and display the desktop environment. 

Note: Depending on the VNC server configuration, you may need to specify the display number as well as the IP address and port number. For example:

```
   vncviewer 192.168.0.100:1:5901
```

[Back to top](#about)
### VNC Server startup
-----

To start a VNC server, you can use the following command:

```
vncserver :<display-number>
```

Replace `<display-number>` with the number of the VNC display you want to start (e.g. ":1"). If this is your first time starting the VNC server, it will prompt you to set a password for the server. 

Once the server is started, you can connect to it using a VNC client on another device. The exact steps for connecting to the server will depend on the client you are using, but typically you will need to enter the IP address or hostname of the server, along with the port number and display number that the server is running on. You will also need to authenticate with the server using the password you set during the server setup

[Back to top](#about)
### Device with a passwd
----

if there is a password required to access the device, you will need to provide that password when you start the VNC viewer. When you enter the command to start the TigerVNC viewer, you should be prompted to enter the password for the VNC server. Simply enter the password and press Enter to connect to the remote computer. If you are not prompted to enter the password, you may need to specify it in the command using the `-passwd` option. For example:

```
vncviewer <ip-address>:<port-number> -passwd /path/to/password/file
```

Replace `<ip-address>` and `<port-number>` with the IP address and port number of the VNC server, and `<path/to/password/file>` with the path to the file containing the VNC server password.

[Back to top](#about)
### Reset VNC passwd
----

To reset the password for a VNC server, you can follow these steps: 1. Stop the VNC server:

```
   vncserver -kill :<display-number>
   
```

Replace `<display-number>` with the number of the VNC display you want to reset the password for (e.g. ":1"). 2. Remove the VNC password file:

```
   rm ~/.vnc/passwd
   
```

3. Start the VNC server:

```
   vncserver :<display-number>
   
```

This will start the VNC server on the specified display and prompt you to enter a new password. 4. Enter a new password when prompted. Note: The password must be at least 6 characters long and can only contain alphanumeric characters. 5. Restart the VNC server:

```
   vncserver -kill :<display-number>
   vncserver :<display-number>
   
```

This will restart the VNC server with the new password. Once you have completed these steps, you should be able to connect to the VNC server using the new password.

### Nmap&VNC
----
1.  To discover devices on a network using VNC, you can use a tool like Nmap, which is a free and open-source network scanner. Here are the general steps to discover devices on a network using Nmap: 

2. Type the following command to scan the network for VNC servers:

```sh
nmap -p 5900-5999 -sV -O <network-address>
```

Replace `<network-address>` with the IP address or range of IP addresses for the network you want to scan. This command will scan the network for devices running VNC on ports 5900-5999 and attempt to identify the software and operating system running on each device. 

Once the scan is complete, you should see a list of devices that have VNC servers running on them. You can then use the TigerVNC viewer to connect to each device and access its desktop environment. 

Note that network scanning can be a sensitive activity, and you should only perform it on networks that you have permission to scan. Additionally, some networks may have security measures in place to prevent network scanning, so you should be aware of any relevant policies or regulations before performing a network scan. (edited)