
#### Security policy
----
 Essentially the same thing as a ACL. It is a list of rules dictating what is allowed to pass the firewall and what is not. 
 
- These are used inside firewalls

`netstat` command on windows is the security table list.

#### State Table:
---- 
State table is used by the firewall to cache conversations have already been established and is considered "trusted". 

If the firewall has never seen the connection between two devices the state table look up will finish and the firewall will then access the "Security Policy" to see if there is permissions for the traffic to flow from device A to device B.


#### NEXT GEN FIRE WALL
----
Work with layer 7 


#### STATEFUL 
---
work with layer 4
only uses security policy lists to 


### Firewall basic info
---
- Can be used for purposes other then security outside you business but also inside to set up rules that also allow you to segment different departments of the network.

- Topology can be designed to have standby functionality which is called Active/Active Failover where Active is the always UP firewall and the Active Failover is the standby Firewall incase of failure. The two firewalls can communicate to each other using hello messages to verify an UP state.

#### First slide:
In this presentation, we'll be discussing Two types of firewalls. Tradtional aka Stateful firewalls and Next-Generation Firewalls (NGFW) . Ists important to note Next Generation firewalls encapsulate stateful filtering technology so it is just a more beefed up version.

### Second slide
Lets first discuss what a firewall is. CLICK NEXT. A firewall looks at traffic before entering a network and either allows or blocks traffic based on a defined set of security rules. 

### Third slide 
The rules and technologies are dependant on the type of firewall being used. but the overal function is the same. If the packet checks off all the set criteria.

### forth slide
Then the packet is allowed through.

### Fifth slide
Read the slide 

### Six slide
Stateful filtering is able to read the outbound request header information before it is sent out. CLICK CLICK and saves the source ip and emphemeral port number as well as the destination ip and port number, sequence number and connection state SYN_SENT.  CLICK CLICK when the response is recieved by the firewall the response header sequence number, connection state SYN_ACK, source ip and port number and destination ip emphemeral port is compared to the original outbound request. CLICK if equal to the calculated expected response and CLICK allowed on the security policy the packet is sent through. CLICK 

### seven slide
GOOD TO GO -> CLICK

### eight slide
Another type of firewall we will talk about is the Next generation firewall. This type of firewalls combines layer 4 stateful filtering firewall as mentioned earlier with an application layer firewall using in-line deep packet inspection (DPI), an intrusion prevention system (IPS). Other techniques might also be employed, such as TLS/SSL encrypted traffic inspection, website filtering, QoS/bandwidth management, antivirus inspection, third-party identity management integration (i.e. LDAP, RADIUS, Active Directory)and SSL decryption. -> CLICK

### Slide nine
We'll take a deeper look into one of the technologies the next-gen firewall employs. The Intrusion Prevention System aka IPS -> CLICK

### slide ten
uses a hash signature to look for known malware programs. If a packet comes in CLICK and the signature matches one found on the IPS CLICK the packet will be disgarded.

The draw back is that it can only stop previously know malware signatures, basically the hash signature of the malware must already exist within the list -> CLICK

### Slide eleven
There are other awesome features to Next generation firewall. Some of the coolest are the ability to have live updated tables of new known malicious website and malware signatures. The security policies are dynamic and ever evolving to garentee the best protection. A deeper look into the dynamic funcitons such as the use of Active directory is a topic for another time.

### last slide
This concludes my presentation on next-gen firewalls and stateful filtering

