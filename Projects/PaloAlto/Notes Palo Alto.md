#### Notes about security policies
---
- A packet is matched against the first rule that meets the defined criteria and, after a match is triggered, subsequent rules are not evaluated
	- Therefore, the more specific rules must precede more generic ones in order to enforce the best match criteria.
- The default rules—displayed at the bottom of the security rulebase—are predefined to allow all intrazone traffic (within a zone) and deny all interzone traffic (between zones).
- Implicit deny at the bottom.

#### Universal (default)
----
![[Screenshot 2023-06-28 190810.png]]

#### Int***er***zone
---
![[Screenshot 2023-06-28 190727.png]]

#### Int***ra***zone
----
![[Screenshot 2023-06-28 190746.png]]



#### Components of a rule
---
- Required
	- Name
	- UUID -> universal unique Identifier.
	- Rule type
		- Universal
		- intrazone
		- interzone
	- source zone -> zone where traffic originates
	- destination zone -> zone where traffic terminates. 
		- If NAT is used make sure to reference the POST-NAT zone.
	- Application -> uses App-ID 
	- Action 
		- Allow
		- Deny

- Optional 
	- Tag -> helps filter rules
	- Description
	- Source address -> Define host IP addresses, subnets, address objects, address groups.
		- If you use NAT, make sure to always refer to the original IP addresses in the packet (i.e. the pre-NAT IP address).
	- Destination address -> The location or destination for the packet
		- If you use NAT, make sure to always refer to the original IP addresses in the packet (i.e. the pre-NAT IP address
	- User -> user group whom policies apply
	- URL Category -> 



### Security types
---
- Security
	- Determine whether to block or allow a session based on traffic attributes such as the ***source and destination security zone, the source and destination IP address, the application, user, and the service.*** For more details, see [Security Policy](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/policy/security-policy.html#id5ce38113-7e3b-4557-a31e-69cabb19b3f4).
	
- NAT
	- Instruct the firewall ***which packets need translation and how to do the translation.*** The firewall supports both source address and/or port translation and destination address and/or port translation. For more details, see [NAT](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/networking/nat.html#idd3b02419-4fd3-46e8-b100-6490442cd450).
	
- QoS
	- ***Identify traffic requiring QoS treatment*** (either preferential treatment or bandwidth-limiting) using a defined parameter or multiple parameters and assign it a class. For more details, see [Quality of Service](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/quality-of-service.html#id24fc2b5b-3a8f-4743-b1da-ebc9e684ffe8).
	
- Policy Based Forwarding
	- Identify traffic that should use a different egress interface than the one that would normally be used based on the routing table. For more details, see [Policy-Based Forwarding](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/policy/policy-based-forwarding.html#id4c4e9cde-244f-45fb-af74-b7d136af4caa).
	
- Decryption
	- Identify encrypted traffic that you want to inspect for visibility, control, and granular security. For more details, see [Decryption](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/decryption.html#id3794a0c0-88b3-49df-a63d-faa63ff764cb).
	
- Application Override
	- Identify sessions that you want to bypass App-ID layer 7 processing and threat inspection. Traffic that matches an application override policy forces the firewall to handle the session as a stateful inspection firewall at layer 4. Only use Application Override when you must and in the most highly trusted environments where you can apply the principle of least privilege strictly. For more details, see [Application Override](https://docs.paloaltonetworks.com/pan-os/9-1/pan-os-admin/policy/application-override-policy).
	
- Authentication
	- Identify traffic that requires users to authenticate. For more details, see [Authentication Policy](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/authentication/authentication-policy.html#id7ff2779e-e507-4c14-ae54-43d3be101cfc).
	
- DoS Protection
	- Identify potential denial-of-service (DoS) attacks and take protective action in response to rule matches. For more details, see [DoS Protection Profiles](https://docs.paloaltonetworks.com/content/techdocs/en_US/pan-os/9-1/pan-os-admin/zone-protection-and-dos-protection/zone-defense/dos-protection-profiles-and-policy-rules/dos-protection-profiles.html#ida42d52fa-3366-4695-bb4a-d39ebf3b6a5f).