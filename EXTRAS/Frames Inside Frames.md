
1. **Ethernet Frame**: This is the outermost layer of the packet structure in most LAN (Local Area Network) environments. The Ethernet frame consists of:
    - Preamble and Start Frame Delimiter (SFD)
    - Destination MAC Address
    - Source MAC Address
    - EtherType (this indicates the protocol of the payload, e.g. IPv4, IPv6)
    - Payload (This is where the IP packet will be located)
    - Frame Check Sequence (FCS)

1. **IP Packet**: The payload of the Ethernet frame will typically be an IP packet in many modern networks. The IP packet consists of:
    - IP Header (Version, Header Length, Differentiated Services Code Point (DSCP), Explicit Congestion Notification (ECN), Total Length, Identification, Flags, Fragment Offset, Time to Live (TTL), Protocol, Header Checksum, Source IP Address, Destination IP Address)
    - Payload (This is where the TCP segment or UDP datagram will be located, depending on the protocol mentioned in the IP header)

1. **TCP Segment**: If we're dealing with a TCP-based protocol like HTTPS, then the payload of the IP packet is a TCP segment. The TCP segment consists of:
    - TCP Header (Source Port, Destination Port, Sequence Number, Acknowledgment Number, Data Offset, Reserved, Flags, Window Size, Checksum, Urgent Pointer, Options)
    - Payload (This is where the HTTPS data will be located)

1. **HTTPS**: Inside the TCP segment, you will find the HTTPS data. HTTPS is essentially HTTP over SSL/TLS, so the HTTPS payload actually contains the HTTP data, but encrypted. The encrypted HTTPS payload would be decrypted by the receiver using the agreed upon SSL/TLS keys. The decrypted HTTPS payload contains:
    - HTTP Header (This includes items such as the GET/POST method, URL, HTTP Version, Host, etc.)
    - HTTP Body (This is the actual content of the HTTP request or response)

So, in order, the IP packet is located within the Ethernet frame, the TCP segment is located within the IP packet, and the HTTPS data is located within the TCP segment. This process of encapsulation is a key aspect of how networked systems communicate.