
Today I am going to talk about the BGP attributes.

unlike an interior gateway protocol we want to have more granular control over the flow of traffic from one autonomous system to another. The solution was to give BGP more attributes that can be leveraged to make these explicit path selections.

Were going to be talking about 11 different BGP attributes. You can think of these as tie breakers 

The BGP attributes are evaluated in the following order:

|Priority |Attribute|
|---|---|
|1|Weight|
|2|Local Preference|
|3|Originate|
|4|AS path length|
|5|Origin code|
|6|MED|
|7|eBGP path over iBGP path|
|8|Shortest IGP path to BGP next hop|
|9|Oldest path|
|10|Router ID|
|11|Neighbor IP address|


#### weight
Weight is a Cisco proprietary BGP attribute that can be used to select a certain path. Here’s what you need to know about weight:

- **Weight** is the first BGP attribute in the list.
- **Cisco proprietary** so you won’t find it on other vendor routers.
- Weight is not exchanged between BGP routers.
- Weight is only **local** on the router.
- The path with the **highest** weight is preferred.
- Default value is 0

```kotlin
router bgp 1
neighbor 192.168.13.3 weight 500
```

#### Local preference
- **Local preference** is the second BGP attribute.
- You can use local preference to **choose the outbound external BGP path**.
- Local preference is sent to **all internal BGP** routers in your autonomous system.
- Not exchanged between external BGP routers.
- Local preference is a **well-known** and **discretionary** BGP attribute.
- The default value is 100.
- The path with the **highest** local preference is preferred

The local preference value is advertised to the other router inside a network using iBGP. It is set via
```kotlin
router bgp <as_number>
bgp default local-preference <Value> // Highest value wins
```


### Originate 
- prefer the path that the local router originated.
	- This means that if the Path was learned explicitly rather than dynamically from some Interior gate protocol like OSPF the path will opt to use the explicitly injected path.

### AS path length
- prefer the path with the **shortest AS path length**. For example, AS path 1 2 3 is preferred over AS path 1 2 3 4 5
	- You can manipulate this by using "AS path prepending"
		- We can add our own autonomous system number multiple times, so the as-path becomes longer. Since BGP prefers a shorter AS path, we can influence our routing. 
- If a we have two routers inside a single AS we can AS path prepend to make the AS path length loner to make that path less desirable. 

```kotlin
(config)#route-map PREPEND permit 10
(config-route-map)#set as-path prepend 1 1 1 1 1
(config-route-map)#exit
(config)#router bgp 1
(config-router)#neighbor 192.168.12.2 route-map PREPEND out

// OUTPUT
-------------------------------------------------------------------------------
   Network          Next Hop            Metric LocPrf Weight Path
*> 1.1.1.0/24       192.168.23.3             0             0 1 i
*                   192.168.12.1             0             0 1 1 1 1 1 1 i
```



### Origin code 

- Prefer the **lowest origin code**. There are three origin codes:
	- IGP
	- EGP
	- INCOMPLETE

You will see IGP when you use the `**network**` command for BGP. It means you advertised the network yourself in BGP. EGP is historical, and you won’t see it in the BGP table anymore.. Incomplete means you have redistributed something **into** BGP.

read off the slide

### eBGP path over iBGP path
- Prefer eBGP (external BGP) over iBGP (internal BGP) paths. That's all there is too it.


### Shortest IGP path to BGP next hop
- Prefer the path within the autonomous system with the **lowest IGP metric** to the BGP next hop.

### Oldest Path
- Prefer the path that **we received first,** in other words, the oldest path.


### Router ID
- Prefer the path with the **lowest BGP neighbor router ID**. The router ID is based on the highest IP address. If you have a loopback interface, then the IP address on the loopback will be used. The router ID can also be manually configured.

### Neighbor IP address
- Prefer the path with the **lowest neighbor IP address**. If you have two eBGP routers and two links in between then the router ID will be the same. In this case, the neighbor IP address is the tiebreaker.
