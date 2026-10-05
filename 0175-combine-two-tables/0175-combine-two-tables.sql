# Write your MySQL query statement below
#bruhh i just forgot to join 

select firstName,lastName,city,state 
from Person as P LEFT JOIN Address as A
ON P.personId = A.personId;