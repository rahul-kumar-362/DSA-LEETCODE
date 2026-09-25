#jinhone kabhi kuch order nahi kia  unko print 

select  C.name as Customers from Customers as C LEFT JOIN Orders as O
ON C.id = O.customerId
where customerId IS NULL;