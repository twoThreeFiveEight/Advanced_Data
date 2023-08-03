Here are the simplified configurations for both Layer 2 and Layer 3 port channels, including the necessary encapsulation command:

[Layer2](#layer2%20port%20channel) | [Layer3](#layer3%20port%20channel) | [Layer 2 Port-channel that allows routing](#Layer2%20Port-channel%20that%20allows%20routing)

## Layer2 Port Channel
----

```kotlin
interface Port-channel1
  description L2-PortChannel
  switchport mode trunk
  switchport trunk encapsulation dot1q
  switchport trunk allowed vlan 10,20,30
```

Corresponding layer 2 Port Channel member interface:
```kotlin
interface GigabitEthernet0/1
  description L2-PortChannel-Member
  switchport mode trunk
  channel-group 1 mode on

interface GigabitEthernet0/2
  description L2-PortChannel-Member
  switchport mode trunk
  channel-group 1 mode on
```


## Layer3 Port Channel
----

```kotlin
interface Port-channel2
  description L3-PortChannel
  no switchport
  ip address 10.1.180.13 255.255.255.252
```

Corresponding layer 3 Port Channel member interface:

```kotlin
interface GigabitEthernet0/3
  description L3-PortChannel-Member
  no switchport
  channel-group 2 mode on

interface GigabitEthernet0/4
  description L3-PortChannel-Member
  no switchport
  channel-group 2 mode on
```

Please note that these configurations assume a Cisco IOS-style syntax. Make sure to adjust the interface names and other parameters to match your specific network equipment and operating system.


## Layer2 Port-channel that allows routing
----
##### ***NOTE: If VLAN 180 is not required to be part of the Layer 2 trunking configuration for the port channel, you can exclude it from the trunk configuration.

To configure a port channel to allow Layer 2 VLANs to traverse while also enabling Layer 3 routing for a specific VLAN (VLAN 180) with OSPF participation, you can follow these steps:

1. Create the port channel interface and enable Layer 2 trunking for VLANs 10 and 20:

```kotlin
interface Port-channel1
  description L2-PortChannel
  switchport mode trunk
  switchport trunk encapsulation dot1q
  switchport trunk allowed vlan 10,20
```

1. Create a Layer 3 interface for VLAN 180 and assign it an IP address:

```kotlin
interface Vlan180
  description L3-Routing-VLAN
  ip address 10.1.180.1 255.255.255.0
```

1. Enable OSPF on VLAN 180:

```kotlin
router ospf 1
  network 10.1.180.0 0.0.0.255 area 0
```

In this configuration:

- VLAN 10 and VLAN 20 are allowed on the Layer 2 trunk of the port channel interface.
- VLAN 180 is assigned to the Layer 3 interface (Vlan180) with the IP address 10.1.180.1/24.
- OSPF is configured with process ID 1, and the network command includes the network address of VLAN 180 (10.1.180.0/24) to enable OSPF routing for that subnet.

Make sure to adjust the VLAN IDs, IP addresses, OSPF process ID, and other parameters as per your specific network requirements.

Additionally, ensure that the member interfaces of the port channel (GigabitEthernet0/1, GigabitEthernet0/2, etc.) are properly configured and added to the port channel interface (Port-channel1) using the appropriate channel-group commands.

```kotlin
interface GigabitEthernet0/1
  description L2-PortChannel-Member
  switchport mode trunk
  channel-group 1 mode on

interface GigabitEthernet0/2
  description L2-PortChannel-Member
  switchport mode trunk
  channel-group 1 mode on
```

These commands associate the member interfaces with the port channel (Port-channel1) in static port channel mode.

Remember to adjust the interface names and other parameters according to your specific network equipment and operating system.


### Added features
----

If you have multiple non-consecutive ports that you want to configure as members of the same port channel, you can specify them in a single interface range declaration. This allows you to group the interfaces together and apply the desired configuration collectively.

Here's an example of how you can configure multiple non-consecutive ports as part of the same port channel using an interface range declaration:

```kotlin
interface range GigabitEthernet1/0/1, GigabitEthernet1/0/3, GigabitEthernet1/0/5-7
    description MyPortChannelMembers
    no switchport
    ip address 192.168.0.1 255.255.255.0
    channel-group 1 mode active
    spanning-tree portfast
    spanning-tree bpduguard enable
    no shutdown
exit
```

In the above example, interfaces GigabitEthernet1/0/1, GigabitEthernet1/0/3, and the range GigabitEthernet1/0/5-7 are grouped together using the interface range command. The configuration is then applied collectively to all the specified interfaces. In this case, they are configured with an IP address, assigned to port channel 1 in active mode, and other desired settings.

By using the interface range command, you can simplify the configuration process when dealing with multiple non-consecutive ports that require the same configuration settings.

