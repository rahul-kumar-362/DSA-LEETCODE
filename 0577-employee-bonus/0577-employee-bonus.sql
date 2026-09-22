-- Inner Join Lagakar dekhta hu

select E.name,B.bonus
from Employee as E LEFT JOIN Bonus as B
ON E.empId = B.empId
where bonus<1000 OR bonus IS NULL ;
