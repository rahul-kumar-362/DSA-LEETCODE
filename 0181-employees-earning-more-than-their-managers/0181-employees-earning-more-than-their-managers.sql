# Person Who EARNS more than his manager ...

#consider it collection of employee and manager table
#INNER JOIN

select E.name as Employee from Employee as E
INNER JOIN Employee as M
ON E.managerId = M.id
where E.salary>M.salary;


