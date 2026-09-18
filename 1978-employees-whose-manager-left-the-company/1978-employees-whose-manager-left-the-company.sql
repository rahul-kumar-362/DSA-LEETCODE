select employee_id from Employees where salary<30000 AND manager_id IS NOT NULL AND manager_id NOT IN (select employee_id from  Employees)
ORDER BY employee_id ASC;