#### RIB Tiebreakers and ECMP

#### Routing Information Base speech

- The routing information base primary function is for storing and managing routing information. 

- #### What is a tie breaker? 
	- A way to find prefered routes
	- When multiple routing paths with the same cost exist, a tiebreaker is necessary to determine the preferred path among them. The tiebreaker can be based on various criteria, such as administrative distance, route origin, or the order in which the routes were learned
	
	- The purpose of the RIB tiebreaker is to select a single route among the candidates and install it into the forwarding table. The forwarding table is then used by the router or network device to make forwarding decisions for incoming packets
	
- The RIBs database is leveraged to compare like metrics from one routing path to another routing path to find that single routing path

- #### What are some metrics used?
	- Admin distance 
		- Lowest distance wins
	- Route Origin
	- hop count
- The RIB will be leveraged for information until a tiebreaker is found and one single path wins.

#### ECMP Equal-cost Multipath


Equal-Cost Multipath (ECMP) is a routing technique that allows for the simultaneous use of multiple paths with the same cost or metric to reach a destination network. In ECMP, traffic is load-balanced across these multiple paths, distributing the network load evenly and maximizing available bandwidth.

- #### How does it work?

	-  Obviously we need Multiple Paths: 
		- ECMP is employed when a router has multiple next-hop options with the same routing metric or cost to reach a specific destination network. These paths can be obtained from different routing protocols, learned dynamically, or configured manually.
	
	- Load Balancing: 
		- Instead of selecting a single "best" path, ECMP distributes traffic across all available paths with equal cost. This is achieved by using a hashing algorithm that takes packet characteristics (e.g., source/destination IP address, port numbers) and assigns packets to specific paths. The goal is to balance the traffic load among the available paths, improving network utilization and performance.
			- When the paths have different costs, the load balancing algorithm takes into account the relative costs of the paths while distributing traffic. The traffic is still spread across the available paths, but the distribution may not be perfectly equal due to the varying costs.

	- Path independence: 
		- Its important to note that Each path within an ECMP group is considered independent and can have its own forwarding decisions. This means that packets from the same flow can be transmitted over different paths, potentially arriving at the destination out of order. The receiving end should be able to handle out-of-order packets and reassemble them correctly.

	- Path Selection: 
		- When a router has multiple paths with the same cost, the decision of which path to use for forwarding is typically based on the hashing algorithm and the characteristics of the packets being transmitted. Router applies the hash function to the packet attributes, which determines the path to bhe re used for that packet.

### What protocols use ECMP?
 read slide

- It's worth noting that ECMP is a feature that can be enabled or configured within these routing protocols, and its availability might vary based on the specific implementation or version of the routing protocol being used. Additionally, network devices such as routers or switches need to support ECMP for it to be effectively used in the network.

### in conclusion

I want to add That you do not need to disable the tiebreaker mechanism. The tiebreaker determines the preferred route from the available options, and ECMP then distributes traffic across those preferred routes.
