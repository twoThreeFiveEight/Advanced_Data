**Is there a standard best practice for assigning IP addresses to devices when you are designing a topology from scratch?**

There is no one size fits all answer for IP address schemes, but some general guidelines that I like to follow are these: When practicable use /24s, and make the VLAN number for that subnet match the 3rd octet of the IP address, additionally make the first available IP address in the subnet the default gateway.  The key is to be consistent, if all the subnets are designed the same then there are fewer variables when you are trying to troubleshoot issues in the future.


