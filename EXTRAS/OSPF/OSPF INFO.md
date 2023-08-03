### Sections
----
[Glossary](#glossary) | [Important Info](#important%20info) | [Hello Packets](#hello%20packets%20(Init%20connection)) | [Types](#types) | [Network Architecture Types](#network%20architecture%20types)

#### Glossary
----
- [LSDB](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FOSPF%2FLSDB) = Link State Database, This is where all LSA information is stored
- [DR](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FOSPF%2FDesignated%20Router) = Designated router
- [BDR](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FOSPF%2FDesignated%20Router) = Backup Designated router
- [RID](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FOSPF%2FRouter%20ID) = Router ID
- [ABR]() = Area border router. Connects different areas
- [ASBR]() = Autonomous System border router. Connects AS to the OSPF.

### Important Info
---
- ***Backbone is Area 0

- ***All areas must be connected to area 0

- ***Areas really only exist to help lower the cpu usage of the routers. It breaks up the computation needed to run the SPF (shortest path first) algorithm.

- ***Our routers only have a full picture of the network topology within the area. ABRs will have the topology of both areas they border.

- ***ABR needs to be a more powerful router then a non border router.

- ***We only use a DR/BDR on a [multi-access network](#Multi%20Access%20network).

- ***Each OSPF router has a unique "[Router ID](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FOSPF%2FRouter%20ID)"

- ***If you have a loopback interface on your OSPF router, then this IP address will be used as the router ID even when it’s not the highest active IP address. This is because you loopback will never go down.

- ***`Default-information originate always` The `always` keyword will inject the default router into the routing table if it does not exist there yet. Otherwise you will need to be getting that default from another source. 

### Hello Packets (Init connection)
---
- To gain a neighbor relationship OSPF starts with hello packets.
	- Once you configure OSPF, your router will start sending hello packets. If you also receive hello packets from the other router, you will become neighbors.

##### Hello packet contents
- **Router ID:** Each OSPF router needs to have a unique ID which is the highest IP address on any active interface. More about this later.
- **Hello / Dead Interval:** Every X seconds, we will send a hello packet. If we don’t hear any hello packets from our network for X seconds, we declare you “dead,” and we are no longer neighbors. These values have to match on both sides to become neighbors.
- Neighbors: All other routers who are your neighbors are specified in the hello packet.
- **Area ID**: This is the area you are in. This value has to match on both sides to become neighbors.
- Router Priority: This value is used to determine who will become designated or backup designated routers.
- DR and BDR IP address: Designated and Backup Designated router.
- **Authentication password:** You can use clear text and MD5 authentication for OSPF, meaning every packet will be authenticated. Obviously, you need the same password on both routers in order to make things work.
- Stub area flag**:** Besides area numbers, OSPF has different area types. Both routers have to agree on the area type to become neighbors.

### Types
----

- LSA Type 1:            Router LSA
- LSA Type 2:            Network LSA
- LSA Type 3:            Summary LSA
- LSA Type 4:            Summary ASBR LSA
- LSA Type 5:            Autonomous system external LSA
- LSA Type 6:            Multicast OSPF LSA
- LSA Type 7:            Not-so-stubby area LSA
- LSA Type 8:            External attribute LSA for BGP

##### 1. Router LSA
- ***Stays within an area.*** 
- What is in the LSA
	- Prefix on a interface
	- [link type](obsidian://open?vault=NetworkNotes&file=AdvancedDataNotes%2FEXTRAS%2FOSPF%2FLink%20Types) 

##### 2. Network LSA
- ***Stays within an area***
- 


### Network Architecture Types
---
![[maxresdefault.jpg]]

In OSPF, there are different network types that define how routers on a particular network segment interact with each other. The two relevant network types in this context are broadcast and non-broadcast networks.

1. Broadcast Networks: A broadcast network is a network type where multiple routers are connected to a shared media segment, such as Ethernet. In a broadcast network, OSPF elects a Designated Router (DR) and a Backup Designated Router (BDR) to handle the routing updates and communication on behalf of the network. The DR and BDR are responsible for exchanging routing information with other routers within the network segment. Other routers on the network, called DROthers, establish adjacencies with the DR and BDR.
    
2. Non-Broadcast Networks: Non-broadcast networks are network types where multiple routers are connected, but they do not have a shared broadcast medium. This can include point-to-point links, Frame Relay networks, or other types of connections. In non-broadcast networks, OSPF routers do not have the ability to automatically elect a DR and BDR. Instead, routers on non-broadcast networks need to be manually configured with the IP addresses of neighboring routers to establish adjacencies.
    
Regarding the network LSAs (Type 2), they are generated by the DR on a broadcast network or the manually configured routers on non-broadcast networks. These LSAs contain information about the routers connected to the multi-access network, including the DR, BDR, and the associated prefixes with their subnet masks.

In summary, broadcast networks have a designated router (DR) and backup designated router (BDR) to handle routing updates, while non-broadcast networks require manual configuration of neighboring routers. The network LSAs (Type 2) are generated by the DR (in broadcast networks) or the manually configured routers (in non-broadcast networks) and provide information about the routers connected to the network and their associated prefixes.

#### Multi Access network
---
A multi-access network refers to a network type where multiple devices or routers can be connected simultaneously, enabling shared access to the network resources. In a multi-access network, multiple devices can communicate with each other directly without requiring a specific point-to-point connection.

Multi-access networks can include technologies such as Ethernet LANs (Local Area Networks) or wireless LANs (Wi-Fi), where multiple devices are connected to a shared network segment.

Now, within multi-access networks, OSPF distinguishes between two types: broadcast networks and non-broadcast networks.

1. Broadcast Networks: In a broadcast network, multiple routers or devices are connected to a shared broadcast medium, such as Ethernet. This type of network allows devices to broadcast packets, which are then received by all other devices on the same network segment. OSPF utilizes the broadcast network type to enable efficient routing and exchange of routing information. The election of a Designated Router (DR) and Backup Designated Router (BDR) occurs on broadcast networks to optimize OSPF operations.
    
2. Non-Broadcast Networks: Non-broadcast networks, on the other hand, do not have a shared broadcast medium. Examples include point-to-point links or Frame Relay networks. In non-broadcast networks, routers need to be manually configured with the IP addresses of neighboring routers to establish adjacencies and exchange routing information. Non-broadcast networks lack automatic DR and BDR election, requiring manual configuration of neighboring routers.
    

So, to summarize, a multi-access network refers to a network type where multiple devices can connect and communicate simultaneously. In OSPF, multi-access networks are further classified into broadcast networks (with automatic DR/BDR election) and non-broadcast networks (requiring manual configuration).