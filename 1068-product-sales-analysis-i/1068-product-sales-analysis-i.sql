# Write your MySQL query statement below
 select product_name,year,price from 
 Sales INNER JOIN Product
 ON Product.product_id = Sales.product_id;