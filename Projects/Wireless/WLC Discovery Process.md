## Overview of the WLC Discovery and Join Process

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

For information on how to configure DHCP option 43 on a DHCP server, refer to the [DHCP option 43 configuration example](https://www.cisco.com/c/en/us/support/docs/wireless-mobility/wireless-lan-wlan/97066-dhcp-option-43-00.html)

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