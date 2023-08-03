#!/bin/bash
sudo su
sudo yum install httpd -y
sudo yum update -y
sudo service httpd start
sudo chkconfig httpd on
sudo echo "Hello World from $(hostname -f)" > /var/www/html/index.html/var/www/html/index.html
sudo chmod 644 /var/www/html/index.html


# created link
# s3://bucketformyfirstastondeployment/AWSLabscript.sh