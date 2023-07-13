# Write your MySQL query statement below
select d.name as Department,e.name as Employee,e.salary as Salary from employee as e, department as d where e.departmentId=d.id 
and (e.salary)=  
(select max(salary) from employee emp where emp.departmentId=d.Id)
