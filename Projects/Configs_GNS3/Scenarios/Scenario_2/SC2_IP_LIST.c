
California: 
net address: 10.2.29.8 	255.255.255.248
supernet: 10.2.29.0/27
--------------------------------------------
rtrCA0XXa02a01 
    toIL_ROUTER -> 10.2.XX.69/30 -> g0/0
    toCA_SWITCH -> g0/3 Vlans
        (Users) 10.2.XX.9/29: G0/3.1XX1
        (Users) 10.2.XX.17/29: G0/3.2XX1
    Loop0: 10.2.XX.1/32 

wgsCA0XXa02a01 -> VLAN 1XX1: 10.2.XX.14/29

James office: V1XX1: 10.2.XX.10/29

//**********************************************************************

Illinois:
net address: 
    joe-> 10.2.29.208 255.255.255.248
    Jared-> 10.2.29.216 255.255.255.248
    Linux-> 10.2.29.224 255.255.255.224
supernet:
--------------------------------------------
rtrIL0XXa02a01
    toNY_ROUTER -> 10.2.XX.74/30 -> g0/2
    toCA_ROUTER -> 10.2.XX.70/30 -> g0/4
    toComCast -> 63.2.XX.18/24 -> g0/1 
    Loop0: 10.2.XX.192/32

Layer3 switch: mlsIL0XXa02a01 -> 10.2.XX.201/30 -> g0/3 -> routed link
    - Loop0: 10.2.XX.194/32
    - VLAN SVI 1XX0: 10.2.XX.209/29
    - VLAN SVI 2XX0: 10.2.XX.217/29
    - VLAN SVI 3XX0: 10.2.XX.225/27
        g1/0 -> Trunk 1XX0,2XX0
        g1/2 -> Access VLAN 3XX0
        g1/1 -> Trunk 1XX0,2XX0
    
Linux DHCP Server: V3XX0: 10.2.XX.228/27

left network:
wgsIL0XXa02a01 -> VLAN 1XX0: 10.2.XX.214/29
    JOEs desk: VLAN 1XX0: 10.2.XX.212/29

Right network:
wgsIL0XXa02a02 -> VLAN 2XX0: 10.2.XX.213/29
    Jareds desk -> V2XX0: 10.2.XX.220/29

// **********************************************************************

NewYork: 
net address: Adrian 10.2.29.136 255.255.255.248
Supernet: 10.2.29.128/27
---------------------------------------------------
rtrNY0XXa02a01
    toIL_ROUTER -> 10.2.XX.73/30 -> G0/2
    to_SWITCH -> g0/3 Vlans
        (Users) 10.2.XX.137/29: G0/3.1XX2
        (Users) 10.2.XX.145/29: G0/3.2XX2
    Loop0: 10.2.XX.128/32

wgsNY0XXa02a01 -> VLAN 1XX2: 10.2.XX.142/29
    Adrian Office -> V1XX2: 10.2.XX.138/29
