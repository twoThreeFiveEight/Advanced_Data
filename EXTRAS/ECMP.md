- Built in feature
- need to have multipath configured inside the BGP to allow ECMP
- static routes with no AD added will both be analyzed as equal costs so ECMP will load balance between both
- BGP uses AS path as the metric for deciding if the paths are equal cost. 
	- if the paths are not equal you would need to do "AS path Prepend" and add the difference of AS hops to the path that has a lower AS hop number to make ECMP automatically start load balancing.