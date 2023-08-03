
###  Distance Vectors Prototcols
----
- RIP
- EIGRP

### RIP 
---
- To understand EIGRP we need to know how the distance vector works and where it came from.
- RIP is a distance vector protocol.
	- Distance is the numbers of hop counts
	- vector (direction) is the port in which the subnet is found on.
- RIP gets updates every 3 seconds from its directly connected interface subnets.
	- It will copy the contents of the other routers routing table only if it does not exist in the routing table.
- AD = 120

### RIP Metric
---
- Hop Count
	- The update received from the directly connected neighbors routing table will keep a record of how many hops a curtain subnet is from the current router. 

	- If router 1 with a subnet of 10.2.2.2/24 has a directly connected subnet of 10.1.1.1/24 on interface g0/0 then in its routing table will have a hop count of 1 because that subnet is one hop in the vector (direction) of the g0/0 but router 2 on g0/1 will receive and update from router 1 at 10.2.2.2 on its interface g0/0 will then see that it does not have the route 10.1.1.1 in its table but will see that it has router 1 at 10.2.2.2 on g0/0. So router 2 will add 10.1.1.1 to its table and increment the metric found in router 1 table by 1 so now 10.1.1.1 will be inside router 2 table as 10.1.1.1 on interface (vector/direction) with a hop count of 2.


### Example: (NOTE MY NOTES, THIS IS NetworkLesson.com work)
-----

![[three-cisco-routers-routing-tables-1.png]]

In this picture, we have three routers and we are running a distance vector routing protocol (RIP). As we start our routers they build a routing table by default but the only thing they know is their directly connected interfaces. You can see that this information is in their routing table. In **red,** you can see which interface, and in **green,** you can see the metric. RIP uses hop count as its metric which is nothing more than counting the number of routers (hops) you have to pass to get to your destination.

Now I’m going to enable distance vector routing. What will happen is that our routers will **copy their routing table** to their directly connected neighbor. R1 will copy its routing table to R2. R2 will copy its routing table to R3 and the other way around.

If a router receives information about a network it doesn’t know about yet, it will add this information to its routing table:

![[distance-vector-copy-rt.png]]

Take a look at R1, and you will see that it has learned about the 192.168.23.0 /24 and 3.3.3.0 /24 networks from R2. You see that it has added these two items:

- Interface (Fa1/0. This is the vector part, we know in what direction we have to go.
- Metric (hop count). This is the distance part, we know how far away the network is.

192.168.23.0 /24 is one hop away, and 3.3.3.0 /24 is two hops away.

Awesome! You also see that R2 and R3 have filled their routing tables.

Every 30 seconds our routers will send a full copy of their routing table to their neighbors who can update their own routing table.

So far so good, our routers are working, and we know the destination to all of our networks…distance vector routing protocols are vulnerable to some problems, however. Let me show you what can go wrong:

![[distance-vector-link-failure.png]]

The FastEthernet 1/0 link on R3 is going down, so it will change its routing table. Its status went from 0 to Down.

Every 30 seconds our routers send a full copy of their routing table to their neighbors, and it just happens to be that it’s time for R2 to send a copy. R2 sends his full routing table toward R3. What do you think will happen?

![[distance-vector-routing-update.png]]

R3 gets the routing table from R2 and will see that R2 is advertising the 3.3.3.0 /24 network with a hop count of 1. That’s excellent is what R3 thinks….a hop count of 1 is better than having a network that is down. R3 will add this information to its routing table.

![[distance-vector-routing-update-back.png]]


A few seconds later, it’s time for R3 to send its routing table to its neighbor R2. R2 will come to the following conclusion:

“I can reach 3.3.3.0 /24 by going to R3 and my hop count used to be 1. I’m receiving a routing table from R3 now, and it now says that the hop count is 2…I need to update myself to include this change”.

The hop count on R2 is now 3, it received two from R3 and adds the hop towards R3.

R2 will also send a copy of its routing table to R1 which will update itself as well.

Do you see where this is going? These routers are going to keep **updating themselves** **to infinity.**

What will happen when we send an IP packet to the 3.3.3.0 /24 network?

![[distance-vector-routing-loop.png]]


Look at the routing table of R2 and R3. They are pointing to each other. Ladies and Gentleman…we have a routing loop! That’s not a good thing, IP packets have a TTL (Time to Live) field however so they won’t loop around forever as Ethernet Frames do.

![[distance-vector-max-hop-count.png]]

To prevent routers from updating themselves over and over again, we have a **maximum**. For RIP, this is a **hop count of 16**. 16 is considered unreachable, so the maximum number of hops you can have is 15.

This problem is called **counting to infinity**.

There is something else we use to counter the counting to infinity problem. In our example, R3 advertised the 3.3.3.0 /24 network to R2. How useful is it that R2 advertises this network to R3?

That’s like telling someone a joke that you just learned from that person…not very effective (unless the joke is extremely good/lame 🙂

In routing, it’s not very effective, so whatever you learn from your neighbor, you will not advertise back to him. We call this **split horizon**.

![[distance-vector-route-poison.png]]

Something else we do is that once a network goes down (3.3.3.0 /24 in our example), the router will send a **triggered update** immediately to update its neighbors.

The triggered update will contain the network that is down and an infinite metric (16 in the case of RIP). Sending an update for this network with an infinite metric is called **route poisoning.**

![[distance-vector-poison-reverse.png]]


To make sure R3 does not update itself via some other router/path in the network, R2 will send a **poison reverse** in response to the **route poison** it received from R3.

I just explained to you what split horizon is…” don’t advertise whatever you learned from your neighbor back to them.”

“Route poisoning overrules split horizon.”

![[distance-vector-holddown-timer.png]]



There is one more thing we use with distance vector routing protocols. When R2 and R1 find out that our 3.3.3.0 /24 network is down they will also start a hold-down **timer**. This hold-down timer will run for 180 seconds and it does the following:

- If we receive information about the 3.3.3.0 /24 network from another router with the same or worse metric than we currently have, we ignore this information.
- If we receive information about the 3.3.3.0 /24 network from another router with a better metric, we stop the hold-down timer and update our routing table with this new information.
- If we don’t receive anything and the hold-down timer elapses we remove this network from the routing table.

What do you think? That’s plenty of information about RIP and distance vector routing protocols, right?

Let me finish this lesson by giving you an overview between RIP version 1 and version 2. They are similar with a few differences:

|   |   |   |
|---|---|---|
|**RIP**|**Version 1**|**Version 2**|
|**Class**|Classful|Classless|
|**Addressing Type**|Broadcast|Multicast|
|**Support manual summaries**|No|Yes|
|**Authentication support**|No|Yes|


RIP version 1 is classful, so it does not send a subnet mask along with its routing updates, version 2 is classless so it will send the subnet mask along. RIP version 1 sends everything using broadcasts compared to RIP version 2, which uses multicast (you can also use unicast, btw).

That’s all I have for you now. In another lesson, I will show you all the RIP commands you need to know for CCNA! I hope you enjoyed this lesson. If it was helpful to you, please leave a comment!