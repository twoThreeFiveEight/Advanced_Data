### Tables 
---
- EIGRP Uses 3 types of tables
	- Neighbor table
		- Lists all directly connected Neighbors
		- Next hop Router
		- Interface
	- EIGRP Topology Table
		- Lists all learned routes from all EIGRP neighbors:
		- Destination
		- Metric
	- Global Routing Table
		- Best routes from EIGRP topology table will push successors into this table

### Metrics
---
- Static Metrics
	- Bandwidth
		- Giga port or fast ethernet
	- Delay
- Dynamic metrics 
	- load 
		- How busy
	- reliability 
		- How many errors an interface has had

- These metrics will be put into the DUAL algorithm to create a Advertised distance
- The advertised distance is what gets advertised in the HELLO messages.


### Advertisements
----
- Sends HELLO packets
	- Sends Advertised Distance inside the messages. This is the distance for the advertising router to reach the destination.

### Topology table

| IP | Interface | Feasible distance | Advertised Distance |
|--|--|--|--|--|
| 2.2.2.2/24 |g0/0 | 109 | 9|


### Feasible distance
----
- Feasible distance is the distance to some destination. This metric is calculated by taking the current routers distance to its neighbor plus the advertised distance to the desired destination. 

![[eigrp-feasible-distance.png]]

The advertised distance, your neighbor tells you how far it is for him to reach the destination, and the feasible distance which is your total distance to get to the destination.

Let’s continue! R2 is sending its feasible distance towards R1, which is 15. R1 will save this information in the topology table as the advertised distance. R2 is “telling” R1 the distance is 15:

![[eigrp-advertised-feasible-distance.png]]

R1 now knows how far the destination is away for R2, and since we know the metric for the link between R1 and R2, it can also calculate the total distance, which is called the feasible distance, this information is saved in the topology table.

Are you following me so far? Let me describe these terms once again but in plain English:

- Advertised distance: How far the destination is away for your neighbor.
- Feasible distance: The total distance to the destination.

The best path to the destination is called the **successor**!

The successor will be copied from the topology table to the routing table.


### Feasible Successor
----

With EIGRP, however, it’s possible to have a backup path which we call the **feasible successor**. How do we find out if we have a feasible successor? Let’s find out:

![[eigrp-path-calculation-example-1.png]]

In the example above, we have a couple of routers running EIGRP; we are sitting on the router without a name on the left side and would like to know two things:

- Which path is the successor (the best path)?
- Do we have any feasible successors? (backup paths)

Let’s fill in the following table to find out:

|   |   |   |   |
|---|---|---|---|
||**Advertised Distance**|**Feasible distance**||
|**R1**||||
|**R2**||||
|**R3**||||

If you want to try your new-learned EIGRP skills, try to fill in the advertised and feasible distance by yourself in the table above.

R1 is telling us the destination is 10 away, R2 tells us it’s 5 away, and R3 tells us it’s 9 away. We can now fill in the advertised distance part of the table:

|   |   |   |   |
|---|---|---|---|
||**Advertised Distance**|**Feasible distance**||
|**R1**|10|||
|**R2**|5|||
|**R3**|9|||

Since we know our directly connected links, we can add this to the advertised distance, and we’ll have our feasible distance.

|   |   |   |   |
|---|---|---|---|
||**Advertised Distance**|**Feasible distance**||
|**R1**|10|15||
|**R2**|5|10||
|**R3**|9|109||

The path with the lowest feasible distance will be the successor (R2), so now we answered the first question.

|   |   |   |   |
|---|---|---|---|
||**Advertised Distance**|**Feasible distance**||
|**R1**|10|15||
|**R2**|5|10|SUCCESSOR|
|**R3**|9|109||

You will find the successor in the routing table.

To answer the second question, “do we have a feasible successor (backup path)?” we need to learn another formula:

```
Advertised distance of feasible successor < Feasible distance of successor.
```

Or in plain English:

A router can become a backup path if it is closer to the destination than the total distance of your best path.

I think that sounds a bit better right? Let’s try it and see if R1 or R3 is suitable as a backup path:

The advertised distance of R1 is 10, which is equal to the feasible distance of R2, which is also 10. It has to be lower…equal is not good enough, so R1 will NOT be a feasible successor.

The advertised distance of R3 is 9, which is lower than the feasible distance of R2, which is 10. R3 will be a valid feasible successor and used as a backup path!

|   |   |   |   |
|---|---|---|---|
||**Advertised Distance**|**Feasible distance**||
|**R1**|10|15||
|**R2  <br>**|5|10|SUCCESSOR|
|**R3**|9|109|FEASIBLE SUCCESSOR|

Rule: AD of feasible successor must be < Feasible distance of successor

Excellent, so R2 is our successor, and R3 is a feasible successor. You will find both entries in the EIGRP topology, but you will only find the successor in the routing table. If you lose the successor because of a link failure, EIGRP will copy/paste the feasible successor into the routing table. This is what makes EIGRP a FAST routing protocol…but only if you have a feasible successor in the topology table.

Now look closely at the feasible distance of R3 and R1…what do you see? The metric for R3 is FAR worse than the one for R1. Does this make any sense? Did the Cisco EIGRP engineers make a horrible mistake here by using non-optimal backup paths?

Nope, this is perfectly the way it should be! Keep in mind EIGRP at heart is a distance vector protocol. It doesn’t know what the complete network looks like…it’s not a link-state routing protocol like OSPF, which DOES have a complete map of the network. Distance vector routing protocols only know which way to go (vector) and how far away the destination is (distance).

The formula you just witnessed to determine EIGRP’s feasible successors is how EIGRP can guarantee you that the backup path is 100% loop-free! I know this isn’t easy to grasp by reading text so let’s do another example: