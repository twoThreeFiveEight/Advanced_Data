We only use a DR/BDR on a **multi-access** network. An example of a multi-access network is using a switch. There is no need to do this on a **point-to-point** link. There is only one other router on the other side so there is no reason to select a DR/BDR.

In OSPF (Open Shortest Path First), the Designated Router (DR) and Backup Designated Router (BDR) are specific roles assigned to routers on broadcast and non-broadcast multi-access networks. Their purpose is to optimize OSPF operations and reduce network overhead.

The primary reasons for having a DR and BDR are as follows:

1. Reduction of Adjacency Relationships: On multi-access networks, OSPF requires each router to establish an adjacency (neighbor relationship) with every other router. In large networks with many routers, this can result in a significant number of adjacencies, leading to increased control traffic and resource consumption. By designating a DR and BDR, routers only need to establish adjacencies with these designated routers rather than with all other routers in the network, reducing the number of adjacencies and associated overhead.
    
2. Efficient Flooding of LSAs: In OSPF, routers exchange Link-State Advertisements (LSAs) to build a consistent view of the network topology. On multi-access networks, without a designated router, every router would flood LSAs to all other routers, resulting in redundant flooding and increased network traffic. With a DR and BDR, LSAs are flooded only to the designated routers, which then distribute the LSAs to other routers on the network. This optimizes the flooding process and reduces unnecessary traffic.
    
3. Simplified Network Stability: The DR and BDR roles enhance the stability and continuity of OSPF operation. When a new router joins the network or an existing router fails, the DR and BDR ensure a smooth transition. If the DR fails, the BDR takes over as the new DR, and a new BDR is elected from the remaining routers. This avoids network disruption and minimizes the impact of topology changes.
    

By employing the

DR and BDR roles, OSPF optimizes network resources, reduces control traffic, and enhances stability in multi-access networks. This allows OSPF to scale efficiently and operate effectively in larger network deployments.