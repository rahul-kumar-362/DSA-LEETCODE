# WOW OMG ...So difficult

#PELE join krleta hu

select customer_id, count(customer_id) as count_no_trans
from Visits as V LEFT JOIN Transactions as T
ON V.visit_id = T.visit_id
where transaction_id IS NULL
group by customer_id 


