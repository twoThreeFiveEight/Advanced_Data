SECTIONS: [Beneficial Commands](#beneficial%20commands) | [topology](#topology) | [Missing Routes](#missing%20routes) | [Null0 route](#null0%20route) | [Summary](#summary)


### About
----
- I was trying to have BGP between the century and mls01IP. I had issues were I forgot to have specific routes in the routing tables and also had issues where the null0 route ended up being the longest match and was trashing the traffic. Below is the described.  

#### Topology
--- 
![[Screenshot 2023-06-27 101806 1.png]]


#### Missing routes
----
- When pinging loop0 10.0.0.193 in "Century2" from mls01IPSLA the source of the ping was interface 63.1.29.5. The ping was getting to the loop0 but the Century2 did not have a route back to 63.1.29.5 in its routing table 


![[Screenshot 2023-06-27 114205.png]]


### NULL0 route
----

- If the Null0 routes subnet is black holing any routes that are not included as a "longer match rule" then the traffic will prefer the the Null0 route and trash the packet.

- Here we can see the mistake was thinking that the ***Null0*** route will not be taken and the default route will, based on the fact the default has a next hop.
- In fact the null0 route will eat the traffic going to the anything that fits within the 10.0.0.128/25 subnet because it is the "***Longest Match***" 

![[Screenshot 2023-06-27 114229.png]]


### Summary
----

![[Pasted image 20230627131211.png]]![[Pasted image 20230627131211.png]]