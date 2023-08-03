- [[#Native VLAN|Native VLAN]]
- [[#Methods for tagging traffic|Methods for tagging traffic]]
- [[#Native VLAN security risks|Native VLAN security risks]]

##### Native VLAN
---
The native VLAN is a concept in networking that designates a particular VLAN on a trunk port to handle untagged traffic. A trunk port on a switch carries traffic for multiple VLANs, but the switch needs to know what to do with any traffic it receives that does not have a VLAN tag. This is where the native VLAN comes in.

When a switch receives untagged traffic on a trunk port, it will automatically associate that traffic with the native VLAN. Essentially, the native VLAN serves as the default VLAN for untagged traffic on a trunk port.

Here's an example to illustrate this: If you have a switch with a native VLAN of 1 (the default setting on many switches), and it receives untagged traffic on a trunk port, the switch will associate that traffic with VLAN 1.

Note that the native VLAN's ID should be the same on both ends of a trunk link to ensure consistent behavior and to prevent potential networking issues. Also, for security reasons, it's a good practice to change the native VLAN from its default setting (usually VLAN 1), or disable it if it's not used, as it could potentially be exploited for VLAN hopping attacks.


##### Methods for tagging traffic
---

The mechanism for assigning traffic to the correct VLAN involves the configuration settings on the switch, often based on the ingress port the frame was received on, or the MAC address of the device sending the frame.

1. **Port-based VLANs:** This is the most common way to assign VLANs. Each port on the switch is manually assigned to a specific VLAN. When an untagged frame comes into the port, the switch will automatically tag it with the VLAN ID associated with that port. In a port-based VLAN, any device plugged into a certain port is automatically assigned to the VLAN associated with that port.
    
2. **MAC address-based VLANs:** This is a more advanced setup, in which a switch can be configured to assign VLAN tags based on the MAC address of the sending device. This allows for more flexibility, as the VLAN for a device can stay the same even if the device is plugged into a different port.
    
3. **Protocol-based VLANs:** In this setup, the VLAN assignment can be based on the protocol used in the traffic, such as IP or IPv6.
    
4. **Policy-based VLANs:** This is another advanced setup. Rules can be set up that assign VLANs based on factors like the incoming port, MAC address, and protocol, all at the same time. This allows for very granular control over VLAN assignments.
    

For traffic coming into a trunk port, the VLAN tag should already be attached to the frame (unless it belongs to the native VLAN). The switch does not assign a VLAN in this case; it simply reads the tag and forwards the frame onto the correct VLAN. If the traffic is untagged, it is assigned to the native VLAN.


##### Native VLAN security risks
---

In certain scenarios, the native VLAN could potentially become a security risk. One of the most commonly mentioned risks is a form of network attack known as "VLAN hopping."

VLAN hopping is a network attack where an attacker sends packets to or from a VLAN that they shouldn't have access to. This is usually accomplished by taking advantage of the native VLAN configuration on trunk ports.

If an attacker can gain access to a port configured to the native VLAN, they can send packets that, when passed over the trunk link, will be treated as belonging to different VLANs. This is because switches usually do not tag frames from the native VLAN when sent over a trunk link. When these untagged packets reach the other switch, they get tagged with the native VLAN ID of the receiving switch. If the native VLAN ID differs between the switches, this can be used to "hop" from one VLAN to another.

To mitigate this, it's recommended to match the native VLAN configuration across trunk links and to avoid using the default VLAN (VLAN 1 on most switches) as the native VLAN. Additionally, if the native VLAN is not being used for any specific purpose, it can be set to an unused VLAN number.

Beyond these measures, security best practices such as using Private VLANs, implementing robust access control lists (ACLs), and regularly patching and updating network device software can also contribute to reducing the risk of such attacks.