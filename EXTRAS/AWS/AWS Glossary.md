### Terms:
---
[Target Group](#target%20group)
[Security Group](#security%20group)

### Target group
---
[Back to Top](#terms)
In AWS (Amazon Web Services), a target group is a component of the Elastic Load Balancing service. It is used to route incoming traffic to one or more registered targets, such as Amazon EC2 instances, containers, or IP addresses. Target groups play a crucial role in load balancing and routing traffic to ensure high availability, scalability, and fault tolerance for your applications.

Here are some key aspects of target groups in AWS:

1. Load Balancing: Target groups are associated with a load balancer (either an Application Load Balancer or a Network Load Balancer) and distribute incoming traffic across registered targets based on defined rules and algorithms.
    
2. Health Checks: Target groups continuously monitor the health of their registered targets by performing health checks. They periodically send requests to the targets and evaluate their responses to determine if they are healthy and able to handle traffic.
    
3. Routing Policies: Target groups use routing policies to determine how to distribute traffic to their registered targets. These policies can include round-robin, least outstanding requests, IP hash, or custom rules based on attributes in the request.
    
4. Target Types: Target groups support various target types, such as EC2 instances, IP addresses, or containers. This allows you to include a diverse set of resources as targets in your load balancer configuration.
    
5. Auto Scaling: By using target groups in conjunction with Auto Scaling, you can dynamically add or remove instances based on demand. As the Auto Scaling group scales in or out, the target group automatically adjusts the load balancer's routing accordingly.
    
6. Path-Based Routing: With an Application Load Balancer and target groups, you can perform path-based routing, where different paths in the application's URL can be directed to different target groups. This enables routing to specific backend services or application components based on the requested path.
    

Overall, target groups provide the flexibility and scalability required to distribute incoming traffic across multiple resources, monitor their health, and dynamically adjust routing based on demand. They are a critical component in building highly available and scalable applications on AWS.


### Security Group
---
[Back to Top](#terms)
