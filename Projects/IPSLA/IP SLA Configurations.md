
#### The problem
----
static route will always remain in the routing table unless the interface goes down. It’s possible that the link towards ISP1 is up and running but that the ISP1 router itself is unreachable or that ISP1 has problems on their network that prevents us from reaching the Internet through them. This is why we’ll use IP SLA to make our default route more reliable.

###### OPTIONS:
  - dhcp         DHCP Operation
  - dns          DNS Query Operation
  - ethernet     Ethernet Operations
  - exit         Exit Operation Configuration
  - ftp          FTP Operation
  - http         HTTP Operation
  - icmp-echo    ICMP Echo Operation
  - icmp-jitter  ICMP Jitter Operation
  - mpls         MPLS Operation
  - path-echo    Path Discovered ICMP Echo Operation
  - path-jitter  Path Discovered ICMP Jitter Operation
  - tcp-connect  TCP Connect Operation
  - udp-echo     UDP Echo Operation
  - udp-jitter   UDP Jitter Operation
  - voip         Voice Over IP Operation

### Configuration
---
```kotlin

// ! icmp-echo option.
// ! "track" tracking number and "ip sla" numbers are arbitrary
ip sla <ip sla ID#>
	icmp-echo <ip address to ping> source-ip <IP>
	frequency <# in Seconds (10 is normal)>
exit

ip sla schedule <ip sla ID#> life forever start-time now

track <Track ID#> ip sla <ip sla ID#> reachability

ip route 0.0.0.0 0.0.0.0 63.1.29.2 track <Track ID#>
```

#### Verifications
-----

```kotlin
show ip sla statistics

show ip route static
```

##### Example output
```kotlin
R1# show ip sla statistics

Round Trip Time (RTT) for	Index 1
	Latest RTT: 4 milliseconds
Latest operation start time: *00:09:07.235 UTC Fri Mar 1 2002
Latest operation return code: OK
Number of successes: 43
Number of failures: 1
Operation time to live: Forever



R1# show ip route static   
	S*   0.0.0.0/0 [2/0] via 192.168.13.3
```
