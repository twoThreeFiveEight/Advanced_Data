PoE (Power over Ethernet) technology delivers power along with data over standard Ethernet cables, eliminating the need for separate power cables for certain network devices. There are two common standards for PoE: PoE and PoE+ (also known as PoE Plus). Here's a breakdown of the voltage levels used in each standard:

1. PoE (802.3af): This standard delivers a maximum of 15.4 watts of power to powered devices (PDs). The voltage used for PoE is typically 48 volts (V), but due to power loss over Ethernet cables, the actual voltage delivered to the device is around 44-57 volts.
    
2. PoE+ (802.3at): PoE+ is an updated standard that provides higher power delivery. It can deliver a maximum of 30 watts of power to PDs. PoE+ operates at a voltage range of 50-57 volts to compensate for power loss over Ethernet cables.
    

It's worth noting that while these voltage levels are commonly used, the actual voltage delivered to a specific device may vary based on factors like cable length, quality, and power negotiation between the Power Sourcing Equipment (PSE) and the PD. It's always recommended to consult the manufacturer's specifications and guidelines for precise details on the voltage requirements and compatibility of PoE devices.


### Type comparison
---

Here's a comprehensive overview of the different types of Power over Ethernet (PoE) standards, including UPoE, along with their specifications and a brief comparison:

1. PoE (802.3af):

- Power Delivery: Up to 15.4 watts
- Wire Utilization: Uses two pairs of wires (pins 1-2 and 3-6)
- Compatibility: Backward compatible with PoE+ and UPoE
- Common Applications: IP phones, wireless access points, basic security cameras

2. PoE+ (802.3at):

- Power Delivery: Up to 30 watts
- Wire Utilization: Uses two pairs of wires (pins 1-2 and 3-6)
- Compatibility: Backward compatible with PoE and UPoE
- Common Applications: High-performance Wi-Fi access points, advanced IP cameras, VoIP phones

3. UPoE (Universal Power over Ethernet):

- Power Delivery: Up to 60 watts
- Wire Utilization: Uses all four pairs of wires (pins 1-2, 3-6, 4-5, and 7-8)
- Compatibility: Backward compatible with PoE and PoE+
- Common Applications: Large displays, virtual desktop infrastructure (VDI) endpoints, specialized IP phones

4. PoE++ Type 3 (802.3bt Type 3):

- Power Delivery: Up to 60 watts
- Wire Utilization: Uses all four pairs of wires (pins 1-2, 3-6, 4-5, and 7-8)
- Compatibility: Backward compatible with PoE, PoE+, and Type 4 PoE++
- Common Applications: High-performance Wi-Fi access points, PTZ cameras, small displays

5. PoE++ Type 4 (802.3bt Type 4):

- Power Delivery: Up to 90 watts
- Wire Utilization: Uses all four pairs of wires (pins 1-2, 3-6, 4-5, and 7-8)
- Compatibility: Backward compatible with PoE, PoE+, and Type 3 PoE++
- Common Applications: High-power IP cameras, video conferencing systems, industrial equipment

Comparative Summary:

- PoE and PoE+ offer lower power delivery suitable for basic to moderate power requirements.
- UPoE provides higher power delivery than PoE+ (60W), making it suitable for devices with increased power demands.
- PoE++ Type 3 offers the same power delivery as UPoE (60W) but follows the IEEE standard.
- PoE++ Type 4 delivers the highest power (90W) among the standard PoE types.
- Compatibility is ensured within the same or lower power standards, allowing devices to work across different PoE versions.

When selecting the appropriate PoE standard, consider the power requirements of your devices, compatibility with existing equipment, and specific vendor support, such as Cisco for UPoE.