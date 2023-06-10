# Write your MySQL query statement below
SELECT distinct 
    i1.num as ConsecutiveNums 
FROM 
    logs i1,
    logs i2,
    logs i3
WHERE 
    i1.id+1=i2.id AND 
    i2.id+1=i3.id AND 
    i1.num=i2.num AND 
    i2.num=i3.num