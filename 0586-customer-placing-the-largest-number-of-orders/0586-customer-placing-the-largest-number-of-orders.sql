# Write your MySQL query statement below
# Write your MySQL query statement below
select customer_number from Orders 
group by customer_number
ORDER BY count(customer_number) DESC Limit 1;