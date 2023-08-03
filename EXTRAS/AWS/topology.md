Based on the provided requirements, here is a breakdown of where each service should live within the AWS architecture for Sea Ice Creamery:

1. Launched Instances: The launched instances should be placed within one or more private subnets. Private subnets are not directly accessible from the internet, providing an additional layer of security. Instances in the private subnets can communicate with the internet through a NAT gateway placed in a public subnet.
    
2. Web Servers: The web servers, which require a minimum of 1 vCPU and 1GB RAM, should be hosted on the launched instances within the private subnets.
    
3. Database: The database, which requires a minimum of 1 Core, 1vCPU, 2GB RAM, and a 3.3 GHz Processor, can be hosted on a managed database service like Amazon RDS (Relational Database Service). The RDS instance should be placed within a private subnet.
    
4. Load Balancer: To handle up to 100 requests per second and provide high availability, you can use an Application Load Balancer or Network Load Balancer. The load balancer should be placed in one or more public subnets to distribute incoming traffic to the web servers hosted on the instances in the private subnets.
    
5. DNS Web Service: The highly available and scalable DNS web service can be achieved using Amazon Route 53. Route 53 integrates with the load balancer and should be configured to handle up to 10 million standard queries per month.
    
6. Relational Database Service: The minimum required relational database service can be fulfilled using Amazon RDS. It should be placed within a private subnet and should support up to 30 GB of data transferred out per month and 5 GB of data transferred in.
    
7. AWS Support: AWS Support can be subscribed to at the AWS account level. The appropriate support plan can be selected based on Sea Ice Creamery's requirements.
    

Regarding the future system requirements, additional AWS services and resources can be considered based on the specific needs of Sea Ice Creamery. Some possibilities include:

- CloudWatch: To monitor the health of resources, CloudWatch can be utilized to collect and track metrics, create alarms, and monitor logs.
    
- AWS Identity and Access Management (IAM): Implementing security at each architectural layer can be achieved using IAM to manage access and permissions for AWS resources.
    
- AWS Trusted Advisor: Trusted Advisor is an AWS tool that can improve security, optimize costs, and monitor service limits. It can be used to enhance the security and performance of the architecture while reducing overall costs.
    
- Auto Scaling: To automate resource scaling, Auto Scaling can be used to adjust capacity based on demand, ensuring steady and predictable performance.
    
- Fast and Flexible Database Solution: Depending on specific requirements, services like Amazon DynamoDB (NoSQL) or Amazon Aurora (relational) can be considered for a fast and flexible database solution.
    
- Object-Based Storage: Amazon S3 (Simple Storage Service) provides object-based storage and can be used to store and retrieve data from anywhere.
    
- Expanding Architectural Layers: To handle an increased workload and process business logic, scaling resources horizontally and vertically can be considered, along with distributed computing frameworks like AWS Lambda, Amazon ECS (Elastic Container Service), or Amazon EKS (Elastic Kubernetes Service).
    

The specific implementation details and configuration settings of these services will depend on the exact use case, workload patterns, and design choices made for Sea Ice Creamery.