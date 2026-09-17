#jinhone kabhi kuch order nahi kia  unko print 


select  name as Customers from Customers where 
id NOT IN (select customerId from Orders);