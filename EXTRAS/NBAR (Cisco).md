https://www.plixer.com/blog/network-traffic-management-cisco-nbar-and-performance-monitoring/

Cisco's Network Based Application Recognition (NBAR) is an intelligent classification technology in Cisco IOS Software that can recognize a wide variety of applications, including web-based and other difficult-to-classify protocols that utilize dynamic TCP/UDP port assignments.

Here is everything you need to know about Cisco NBAR:

**Functionality**: NBAR classifies traffic on the network in real-time. It peers deep into network packets, examining aspects like port numbers, protocol types, and payload. By examining the payload of a packet, NBAR can determine the exact type of application that is sending or receiving traffic.

**Usage**: NBAR is used for network traffic management. It is integral to Quality of Service (QoS) features because it can help administrators identify which types of traffic are flowing through the network and apply policies based on this information. This can be particularly useful for bandwidth management, traffic prioritization, and security purposes.

**Protocol Discovery**: NBAR includes a Protocol Discovery feature, which provides an easy way to discover the application protocols that are operating on an interface. This can be particularly useful for network troubleshooting and capacity planning.

**Custom Protocols**: Beyond the applications that are predefined within NBAR, administrators can define custom protocols based on parameters such as IP addresses, port numbers, and host names. This provides added flexibility to meet specific needs of an organization.

**Benefits**: The use of NBAR can improve network performance and security. By identifying types of traffic, network administrators can prioritize business-critical applications, limit bandwidth for non-essential applications, or block potentially malicious traffic.

**Considerations**: While NBAR can bring many benefits, it also introduces additional processing load on the network devices it operates on because it needs to examine packet payload information. This could potentially lead to performance issues if not properly managed. However, Cisco has made continuous improvements over time to make the technology as efficient as possible.

Cisco NBAR (Network-Based Application Recognition) and NetFlow are two different technologies used in network monitoring and traffic management, but they can be used together to provide more detailed and comprehensive network analysis.

NBAR can be used to classify the applications, and then NetFlow can be used to monitor the traffic flows associated with these applications. This can give network administrators a more complete understanding of the network traffic, allowing them to manage and optimize network resources more effectively.

##### NetFlow and NBAR
---

![[latencyOnNbarApps-1.png]]