- When you have a static route from the Firewall and the Edge router or any router that contains the default route you will have to make sure to add the next hop interface of where that default route lives to the OSPF you wish to `default-information originate` the route to. You must then make sure the interface is set to `enable`. ***Without this the default route or any statics on this interface will not redistribute.

#### Topology
--- 
#### - The interface g1/3 needs to be inside the Palo Alto Firewall and needs to be enabled.

![[Screenshot 2023-06-24 000413.png]]


- #### Adding all participating interfaces to the Virtual router
![[Screenshot 2023-06-23 142101.png]]

- #### Adding static routes. We attach the "Objects" to the static route.
![[Screenshot 2023-06-23 142114.png]]

- #### Adding the interfaces to the redistribution table for 02
![[Screenshot 2023-06-23 142128.png]]

- #### Creation of the OSPF area (`router ospf <id#>`)
![[Screenshot 2023-06-23 142145.png]]

- #### Once in the Area creation tab you need to MAKE SURE that you add all interfaces that contain information pertaining to variables we'll need for our network statements and advertisement are included and ENABLED inside the interface section tab.
![[Screenshot 2023-06-23 142204.png]]

#### Here we are setting up this interface that holds the path to our default route but is not going to participate in LSA. We still NEED to ENABLE the interface to allow `default-information originate`
![[Screenshot 2023-06-23 142216.png]]



