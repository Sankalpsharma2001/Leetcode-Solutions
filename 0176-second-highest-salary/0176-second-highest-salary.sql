
select max(salary) as SecondHighestSalary from employee e1 where 1=(select count(distinct salary) from employee e2 where e2.salary>e1.salary)