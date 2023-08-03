
### Ethernet passthrough aka Ethernet bridging
---
It involves connecting a computer to a VoIP phone, which acts as a network hub, allowing the computer to share the same network connection as the phone. By doing so, you eliminate the need for separate dedicated ports for the phone and computer.

### Switch port mode
----
The interface from the switch to the phone is typically configured in "access" mode.

In networking terminology, "access" mode is used when connecting an end device (such as a phone or computer) to a switch port. Access mode assigns a specific VLAN (Virtual Local Area Network) to the port, allowing traffic to flow only within that VLAN.

On the other hand, "trunk" mode is used when connecting switches together to carry multiple VLANs over a single link. Trunk mode allows the transmission of traffic from multiple VLANs over the same physical connection, using VLAN tagging to differentiate between the VLANs.

In the context of connecting a phone to a switch, the interface is typically set to access mode to ensure that the phone is placed in the appropriate VLAN and can communicate within that VLAN.

### Configuration
----
Here's an example of the configuration you can use on a Cisco switch to have VLAN 100 and VLAN 200 share the same line for Ethernet passthrough through a Cisco IP Phone 7965:

```c
interface FastEthernet0/1
 switchport mode access
 switchport access vlan 100
 switchport voice vlan 200
 spanning-tree portfast

```

In the above configuration:

- The interface FastEthernet0/1 is the switchport to which the IP phone is connected.
- `switchport mode access` sets the interface to access mode.
- `switchport access vlan 100` assigns VLAN 100 to the access port for the computer.
- `switchport voice vlan 200` assigns VLAN 200 to the access port for the IP phone.
- `spanning-tree portfast` enables fast spanning tree protocol on the port for quicker network convergence.

Please note that the exact interface designation may vary depending on the specific switch model and configuration. Make sure to adjust the interface identifier accordingly.