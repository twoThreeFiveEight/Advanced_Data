
SECTIONS: [Power Supplies](#power%20supplies) | [Calculating Size of UPS](#ups)

Here's an updated cheat sheet with Cisco-specific terminology to navigate the buying process of a Cisco switch:

1. Model Number: Look for the specific product model number provided by Cisco. It is typically mentioned at the beginning of the data sheet or product description.
    
2. Form Factor: Check the form factor details in the data sheet, typically mentioned under the "Physical Specifications" or "Form Factor" section.
    
3. Port Density: Find information on port density under the "Port Specifications" or "Interface Options" section of the data sheet.
    
4. Power Supply Options: Look for details on power supply options in the "Power Specifications" or "Power Supply" section of the data sheet. Cisco may refer to it as the "Power Supply Matrix" or "Power Options."
    
5. Switching Capacity and Performance: Find details about switching capacity, forwarding rate, packet buffer size, and switching fabric under the "Performance" or "Switching Specifications" section of the data sheet.
    
6. Features and Capabilities: Check the data sheet for a section related to "Features" or "Capabilities." Look for specific features such as Layer 3 routing, VLAN support, multicast, security features, and management options.
    
7. Licensing: Look for information on licensing options and requirements under the "Licensing" or "Software Features" section of the data sheet. Cisco may mention different license levels and their associated feature sets.
    
8. Compatibility and Integration: Look for compatibility information under the "Compatibility" or "Interoperability" section of the data sheet. It should provide details on supported network protocols, management systems, and integration with other Cisco products or third-party solutions.
    
9. Support and Warranty: Check for details regarding support, maintenance services, and warranty in the "Support" or "Warranty" section of the data sheet. Cisco may outline support options, software updates, documentation access, and warranty coverage.
    
10. Price and Budget: Data sheets usually don't include pricing information. For pricing details, it's best to consult with authorized Cisco resellers or reach out to Cisco sales representatives.
    

When reviewing the data sheet, familiarize yourself with its structure and headings, as the specific location of information may vary. Use the provided Cisco-specific terminology to quickly navigate to the relevant sections that correspond to the items mentioned above.

### Power Supplies
---
Cisco offers different power supply options, including both WAC (Wide AC) and WDC (Wide DC) power supplies, to cater to the diverse power requirements and preferences of their customers. The availability of different power supply options allows customers to choose the appropriate type based on their specific deployment scenarios and power infrastructure.

1. Wide AC (WAC) Power Supplies:
    
    - WAC power supplies are designed to operate with AC (alternating current) power input.
    - They are suitable for deployments where AC power sources are readily available, such as standard electrical outlets commonly found in office buildings or data centers.
    - WAC power supplies offer compatibility with the existing AC power infrastructure, making them a convenient choice for many customers.
2. Wide DC (WDC) Power Supplies:
    
    - WDC power supplies are designed to operate with DC (direct current) power input.
    - They are suitable for deployments where DC power sources are prevalent, such as telecom environments or remote sites powered by batteries or DC power systems.
    - WDC power supplies provide compatibility with DC power infrastructure, enabling seamless integration into specific power setups.

The availability of both WAC and WDC power supplies allows Cisco customers to select the power supply type that aligns with their existing power infrastructure or preferences. It provides flexibility for various deployment scenarios and ensures that customers can power their Cisco equipment using the most suitable and efficient power source available to them.

It's important to note that the availability of WDC power supplies may vary depending on the specific Cisco switch model or series. Cisco offers a range of power supply options to accommodate diverse customer requirements and power environments, allowing customers to select the optimal solution for their networking needs.


### UPS
---
To calculate the size of a UPS (Uninterruptible Power Supply) for your switches, you need to consider the power requirements of your switches and the desired backup runtime during a power outage. Here's how you can calculate the size of the UPS:

1. Determine the power requirements: Find the power consumption rating of your switches. You mentioned they have a 1900W power supply, so assume that each switch consumes approximately 1900W.
    
2. Determine the number of switches: Determine the number of switches you want to connect to the UPS.
    
3. Calculate the total power consumption: Multiply the power consumption rating of one switch by the number of switches to get the total power consumption. For example, if you have 3 switches, the total power consumption would be 3 * 1900W = 5700W.
    
4. Determine the desired backup runtime: Decide how long you want the UPS to provide backup power during a power outage. This duration is usually measured in minutes.
    
5. Calculate the VA rating: VA (Volt-Ampere) is the unit used to rate the capacity of a UPS. To calculate the VA rating, divide the total power consumption (in watts) by the power factor of the UPS. The power factor typically ranges from 0.6 to 1.0, representing the efficiency of the UPS. For example, if you assume a power factor of 0.8, the VA rating would be 5700W / 0.8 = 7125VA.
    
6. Select an appropriate UPS: Look for a UPS model that has a VA rating equal to or higher than the calculated value. Consider factors such as brand, reliability, additional features, and budget when choosing a UPS.
    

It's worth noting that selecting a UPS with a slightly higher VA rating than the calculated value can provide some headroom for future expansions or additional power requirements.

Remember to consult the manufacturer's specifications and guidelines for both the switches and the UPS to ensure compatibility and optimal performance.