Creating a domain name and associating it with your server involves several steps:

1. **Register a Domain Name**: First, you need to register your domain name (`ise.astontech.com`) with a domain registrar. The registrar is a company accredited by ICANN (the Internet Corporation for Assigned Names and Numbers) or a national equivalent. During the registration process, you're essentially booking the rights to use that domain name for a specified period of time.
    
2. **Set up DNS server**: Next, you need to set up your locally significant DNS server. This involves installing DNS server software on your server and configuring it correctly. The specifics of how you do this depend on the DNS server software you're using and the operating system your server is running.
    
3. **Create DNS Records**: Once your DNS server is set up, you will need to create DNS records. At the very least, you will need an "A" record that associates `ise.astontech.com` with the IP address of your server.
    
4. **Delegate Domain to DNS server**: Finally, you'll have to tell your domain registrar to delegate the domain to your DNS server. This typically involves creating NS (Name Server) records in the control panel of the domain registrar that point to your DNS server.
    

With these steps, any device that uses your DNS server for resolution will be able to resolve `ise.astontech.com` to your server's IP address.

Keep in mind, if you want this DNS resolution to be globally applicable (i.e., resolvable from any location on the internet), you'll need to set up your DNS server so that it's publicly accessible, and your domain registrar must support delegating to your DNS server.

If you want your DNS server to be locally significant only (i.e., the domain is only resolvable from within your network), you can skip the delegation step, and simply configure the devices on your network to use your DNS server. The domain name, in this case, would not be registered with a registrar. It would only be defined on your local DNS server and resolvable by machines that use that DNS server for DNS lookups.