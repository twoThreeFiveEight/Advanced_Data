### Static routes
----
Next Hop needs to be the loopback of that router. Therefor the address ***Needs to have a subnet mask of /32

### OSPF Ranges
--- 
Palo Alto Networks refers to the option to aggregate LSA (Link State Advertisement) destination addresses into subnets when configuring OSPF ranges. ***When you enable the "Add" option for a range, it means that OSPF will summarize or aggregate the subnets specified within that range into a single subnet for advertisement in OSPF LSAs.

In OSPF, summarization or aggregation allows the reduction of the number of LSAs and routing table entries by representing a group of contiguous subnets as a single summarized route. This helps in optimizing OSPF routing and reducing the size of the routing tables.

When you enable the "Add" option for a range in Palo Alto Networks firewall, it aggregates the specified subnets within that range into a summary route (subnet) that will be advertised as part of OSPF LSAs. This summarized route represents the combined address space of the subnets within the range.

***By aggregating the subnets, it allows OSPF to advertise a more compact representation of the network, making OSPF routing more efficient and reducing the number of LSAs and routing table entries required.

It's important to note that summarization or aggregation should be done carefully to ensure that the summarized routes do not cause any routing or connectivity issues. It is recommended to design the summarization based on the network topology and requirements to ensure proper routing and reachability.