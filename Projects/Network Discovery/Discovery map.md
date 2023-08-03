Hosts:                [OVI](#ovi)
Switches            [SW dc-acc-01a](#sw%20dc-acc-01a) | [SW dc-acc-02a](#sw%20dc-acc-02a)
L3 Switches:      [L3SW dc-core-sw-01b](#L3SW%20dc-core-sw-01b)
Routers:            [Internet Edge](#internet%20edge)

### How did I find the networks
---
#### dc-core-sw-02b:
- used cmd to find default gateway
```
ipconfig
```
- found through luck pinging from .1 up to .5 
- found out was a L3 switch via Vlans and switchport interfaces.
```c
show ip int bri    
show arp
show ip protocols  
show ip ospf neighbor  
```

### slp-rt-01
```c
show ip int bri          // Looking for other subnets
show cdp neighbors       // found stp-rt-01 and slp-acc-
show int swithport g0/1  // checking interface mode access/trunk 
show arp                 // looking for IP of switch
```

show ip int brief

### dc-acc-01a:
```c
show ip int brief       // Found all Active ports
show int switchport     // Connected each port to Mode Access/Trunk
show arp                // Found device 
show mac address-table  // associated OVI 2  mac to port G3/3
```

```c
show cdp neighbors
```


#### Internet-edge:
- Found edge router via the L3 switch. using the following commands
```
show ip int brief 
show int g0/0
```
- using OVERLOADED nat translation.
- found access-list 1 is being used by interface g0/0
```
show ip nat statistics
```
- Can ping 8.8.8.8 so we know there is internet

### slp-acc- 01
- found using cdp
```
show cdp neighbors
```
- found address using arp
```
show arp
```
- found interfaces 
```
show ip int brie 
show int  g0/0 switchport
```

### OVI .70
- arp to confirm mac address is unique.
- tracert from OVI 

### 





### OVI
---
### 172.16.8.10/24 
#### 0C7F.8BF3.0000

```
netsh interface ip set address name="ethernet" static 172.16.8.10 255.255.255.0 172.16.8.1
```
Note: defualt gateway maybe HSRP 



ARP:
| IP | MAC | INTERFACE |
| -- | --| --|
| 224.0.0.22  | 01-00-5e-00-00-16 | |
| 224.0.0.251 | 01-00-5e-00-00-fb ||
| 224.0.0.252 | 01-00-5e-00-00-fc| |
| 239.255.255.250 | 01-00-5e-7f-ff-fa |  |  


#### IPconfig
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/OVI 172.16.8.10 255.255.255.0/Screenshot (76).png]]


#### MAC Table
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/OVI 172.16.8.10 255.255.255.0/Screenshot (72).png]]

### ARP
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (113).png]]


## SW dc-acc-01a
----
### 172.16.8.4

Vlan 8
vlan 10
This is the ROOT BRIDGE
MAC: 0c91.c83f.8008

- g2/0  -> Access to OVI
- Vlan8 : SVI rmtManagment

#### Interfaces
![[Screenshot (89) 1.png]]

#### Route Table
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (97).png]]

#### Trunk
![[Screenshot (88) 1.png]]

#### Switchports
##### G0/0
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (90).png]]
##### G0/1
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (91).png]]
##### G0/2
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (92).png]]


#### ARP/MAC
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (93).png]]


#### Spanning-tree
VLAN 10
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (94).png]]

VLAN 8
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (95).png]]

VLAN 01
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (96).png]]



## SW dc-acc-02a  
----
###  172.16.8.5


#### Interfaces:
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (89).png]]

#### Routing Table
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (73).png]]

#### Arp/ MAC
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (84).png]]

#### Trunk:
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (83).png]]


#### Spanning tree info

VLAN10
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (85).png]]

VLAN8
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (87).png]]


VLAN01
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-01a/Screenshot (88).png]]


#### Switchport overview
##### G0/0
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (108).png]]

##### G0/1
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (109).png]]

##### G0/2
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (110).png]]

##### G3/3
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-acc-02a/Screenshot (111).png]]





## L3SW dc-core-sw-01b
---
#### ospf interfaces: 
- 172.16.1.5 
- 10.0.1.6

### 172.16.8.1 VIP
### 172.16.8.3

#### Protocols: 
OSPF:
- BACKBONE area 0
- PID: 12
- Neighbors:
	- Neighbor ID: 172.16.1.6 Address: 172.16.1.6  g0/0
	- Neighbor ID: 10.112.99.1 Address: 10.0.1.4  g0/1

HSRP -> PRIORITY router

#### Interfaces:
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (99).png]]

### Standby

#### Trunk
![[Screenshot (97) 1.png]]

#### Switchport
##### G0/2
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (98).png]]

##### G0/3
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (100).png]]

##### G1/0
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (101).png]]


#### ARP/MAC
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (102).png]]

#### IP route
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (103).png]]

#### OSPF Area0

![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (104).png]]

##### OSPF Neighbors
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (112).png]]

#### Protocols
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (114).png]]

#### Spanning Tree
VLAN 01
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (105).png]]

VLAN 8
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (106).png]]


VLAN 10
![[AdvancedDataNotes/Projects/Network Discovery/NetworkDiscoveryPictures/dc-core-sw-01b/Screenshot (107).png]]


### dc-core-sw-01b
----
##### 172.16.1.6


### Internet Edge
----
##### 172.16.1.6

NEIGHBOR: 172.16.10.3




### dc-wan-rt-01
----
#### 10.110.99.1

This is a router with subinterfaces

##### ospf interfaces:
- 10.110.99.1 G0/2
- 10.0.1.1 G0/0

NEIGHBOR: 
- 10.112.99.1 
	- SUB INT:
		- 0/2.112 
		- 0/2.110
- 172.16.10.3 ->dc-core-sw-01b


### slp-rt-01
----
### 10.110.99.2

CDP is enabled





Transparacy and invisible devices.