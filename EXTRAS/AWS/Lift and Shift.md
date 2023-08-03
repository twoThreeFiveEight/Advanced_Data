### Feature for the Lift and shift

Upfront cost: **0.00 USD** Monthly cost: **3,896.72 USD** Total 12 months cost **46,760.64 USD**

### Public Ip subnets
---
- Using a tool called Elastic IP address. This will allow us to keep that same public IP no matter how our private IP scale and change.
	- Acts basically like a VIP
	- Static Public IP: By default, when you launch an EC2 instance or any other resource, it is assigned a dynamic public IP address. However, if you require a fixed, public IP address that persists even after stopping and starting an instance, you can associate an Elastic IP address. This is particularly useful if you need a consistent public IP for your application, network configurations, or to avoid updating DNS records
- We are running NAT to allow our network to be segmented from the public internet space.

##### Application load balancer
- The Application load balancer helps us take advantage of our resources to avoid having to scale until all instances have reached a assigned value or there max load. This Balancer is used on all private domains.


### Private IP subnets
----  
##### Auto scaling
- We are auto scaling our EC2 instances as well as the Rational DataBase systems. 

##### Subnet size
- We are only scaling to a maximum of 254 instances in each private subnet. 
- This can easily be limited and not effect the Public IP because the use of the Elastic IP Address.

##### Private route table
- We are using a private route table to allow proper routing within the private space

### Route 53
---
- We are using route 53.
	- Route 53 is able to automatically scale to the given DNS requests it is receiving automatically. 
	- A user will be directed to the route 53 service before resolving the public IP to access out network.

### Security group
----
- We have implemented a security group for our firewall. This has specific rules we can set to control inbound and outbound traffic at the instance level. Security groups are stateful, meaning they automatically allow responses to outbound traffic initiated by the instances.
- We can use the security group to allows set permissions for users accessing the RDS (Relational Database Service).
- Segmenting our network into private subnets is another security measure.

### Amazon CloudWatch
---


### Recommendations
---
- AWS Firewall Manager
	- AWS Firewall Manager is a central management service that allows you to configure and enforce firewall rules across multiple accounts and resources in your AWS Organization. It simplifies the management and enforcement of security policies, such as AWS WAF rules and AWS Shield Advanced protections.
	- 
- AWS Shield
	- AWS Shield is a managed Distributed Denial of Service (DDoS) protection service. It provides protection against common and larger-scale DDoS attacks. AWS Shield Standard is automatically included with AWS services at no additional cost, while AWS Shield Advanced provides additional protection and DDoS response services.

- CloudWatch
	- Amazon cloud watch will help us monitor all facets of our network to be able to see log files and other analytics

	- CloudWatch will also aid in monitoring for unusual activity within the database. 

- Amazon API Gateway
	- Amazon API Gateway is a fully managed service that makes it easy for developers to create, publish, maintain, monitor, and secure APIs at any scale. APIs act as the front door for applications to access data, business logic, or functionality from your backend services.


---

IAM: Identity and Access Management; centrally manages user access and permissions to AWS resources, enabling secure control and authentication.

Instance Role: An IAM role assigned to an EC2 instance, granting it specific permissions to access and interact with other AWS services and resources securely.

Target Group: A logical grouping of instances or IP addresses that receive traffic from a load balancer, allowing for efficient distribution and scaling of requests.

Elastic IP Address: A static, public IPv4 address assigned to an AWS resource, providing a fixed endpoint for accessing the resource even if it is stopped and restarted.

Elastic Application Load Balancer: A highly scalable load balancing service that automatically distributes incoming application traffic across multiple targets, such as EC2 instances, containers, and IP addresses, to ensure availability and fault tolerance.

Private Subnet (AWS): A subnet within a VPC that does not have direct internet access, providing an additional layer of network isolation and security for resources deployed in that subnet.

EC2 Instance: A virtual server in AWS Elastic Compute Cloud (EC2) that provides resizable compute capacity, allowing you to run applications and services with full control over the underlying infrastructure.

Instance Expansion: EC2 instances can automatically scale vertically by increasing their capacity, such as CPU, memory, or storage, based on predefined policies or thresholds, allowing applications to handle increased workload demands.

AMI Instance: An Amazon Machine Image (AMI) is a pre-configured template used to launch EC2 instances, encapsulating the operating system, software, and configurations required to start an instance.

RDS: Amazon Relational Database Service; a managed database service that simplifies the deployment, management, and scaling of relational databases such as MySQL, PostgreSQL, Oracle, and SQL Server.

Security Group: Acts as a virtual firewall for EC2 instances, controlling inbound and outbound traffic by specifying rules that allow or deny access based on protocols, ports, and IP addresses.

Auto Scaling: Automatically adjusts the number of EC2 instances based on predefined conditions or policies, ensuring optimal resource utilization and maintaining application availability during variable demand periods. Types of Auto Scaling include target tracking, step scaling, and scheduled scaling.

VPN Gateway: A fully managed service that enables secure and private communication between your on-premises data centers and AWS VPCs using encrypted virtual private network (VPN) connections.

S3 Bucket: Amazon Simple Storage Service (S3) provides scalable object storage for storing and retrieving any amount of data, allowing you to manage and control access permissions to the stored objects.

Route53: A scalable domain name system (DNS) web service that translates human-readable domain names into IP addresses, enabling routing of incoming internet traffic to the appropriate resources within AWS.

AWS Lambda: A serverless compute service that lets you run your code in response to events or triggers, automatically scaling and managing the underlying infrastructure for you.

AWS Trusted Advisor: An online tool that provides real-time guidance to help optimize your AWS infrastructure across multiple categories, including cost optimization, performance, security, fault tolerance, and service limits.

AWS Directory Service: A managed service that allows you to connect your AWS resources with an on-premises Microsoft Active Directory, simplifying user and resource management in hybrid environments.

AWS Firewall Manager: A centralized service that simplifies the management of AWS WAF (Web Application Firewall) rules across multiple accounts and resources, providing consistent security policy enforcement.

AWS Shield: A managed Distributed Denial of Service (DDoS) protection service that safeguards applications running on AWS against common and sophisticated DDoS attacks.

Amazon GuardDuty: An intelligent threat detection service that continuously monitors and analyzes your AWS accounts and workloads for potential security threats and malicious activity.

Amazon API Gateway: A fully managed service for creating, deploying, and managing APIs at any scale, providing features like request throttling, caching, security, and more.

A public subnet in AWS allows instances and resources to have direct internet access and communicate with the internet. It is typically used for resources that require internet connectivity, such as web servers.

Region: A geographic area where AWS data centers are located. Each region is independent and consists of multiple availability zones.

Availability Zone: A physically separate data center within an AWS region. Availability zones are designed to be isolated from each other to ensure fault tolerance and high availability of resources.

Route table in AWS: A route table is a set of rules that determines the path for network traffic within a VPC. It specifies how incoming and outgoing traffic is directed between subnets, internet gateways, NAT gateways, and virtual private gateways.

Internet Gateway: An AWS service that enables internet connectivity for resources within a VPC.

AWS Cloud: Amazon's suite of scalable and on-demand cloud services.