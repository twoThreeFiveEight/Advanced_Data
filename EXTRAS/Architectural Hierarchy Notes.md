### 3 tier architecture
----
- A data center needs to be designed with the default gateway on the CORE layer of network design
	- This is solely to allow full modularity and a random placement of servers. This is to allow all servers to remain L2 adjacency
	- This is not the best design as far as taking advantage of all the bandwidth from the interface design. Spanning tree limits the load balancing possible compared to if you had the same design but use routing protocols like ECMP where loops are not possible and allow balancing.

### spine and leaf
----
- VXLAN is used here to allow layer 2 routing using layer 3 protocols to give added performance regarding to load balancing to utilize all ports with the same cost.


#### ECMP 
---
- Better then Port channels 