# Write your MySQL query statement below
 (select e.name as Employee  from employee e join employee s 
on s.id=e.managerid and e.salary>s.salary);