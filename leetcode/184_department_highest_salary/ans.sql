select Department.Name as Department, F.Name as Employee,Salary from (select * from Employee as e1 where not exists (select 1 from Employee e2 where (e1.DepartmentId = e2.DepartmentId AND e1.Salary < e2.Salary))) F inner join Department on F.DepartmentId = Department.Id;
