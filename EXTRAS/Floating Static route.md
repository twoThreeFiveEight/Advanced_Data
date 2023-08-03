
```c
ip route 0.0.0.0/0 comcast
// The number 10 changes the AD making it less desirable then the static route with a AD
// of 1. 
ip route 0.0.0.0/0 Verizon 10 
```

- The route to Verizon is called a floating static route. It is only there on standby if something like IP SLA finds a issue with the down stream ISP routing.
	- BGP will negate the need for IP SLA because the neighbor relationships will update the routers BGP tables and make a different route. 
	- Mainly used for  static routes and not using BGP. 