
- Need to include the routing VLAN inside the port channel. otherwise your OSPF relationship will not form.
	- I didn't include VLAN 180 in the po9 port-channel and was not able to create a relationship.
	
- Do not make routed port channels to be in `spanning-tree portfast` mode. This makes an issue the port channel loop. 

### Layer 3 port-channel
- a layer 3 port-channel must be labeled `no switchport` on both the port-channel interface and actual interface you are programming the channel-group to.

- MUST NO PASSIVE INTERFACE THE INTERFACES AND THE PORT CHANNEL THEY ARE ASSOCIATED WITH FOR A OSPF NEIGHBOR RELATIONSHIP TO FORM
	- If you are having issues remove the restriction to test the functionality. 
		- In this case the restriction was to remove ***`passive-interface default`*** to see if that was causing the issue. It was to we have to make sure the right ports where made passive.
