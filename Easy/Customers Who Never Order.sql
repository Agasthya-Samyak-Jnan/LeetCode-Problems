/* SQL Schema for the Question */
Create table If Not Exists Customers (id int, name varchar(255))
Create table If Not Exists Orders (id int, customerId int)
Truncate table Customers
insert into Customers (id, name) values ('1', 'Joe')
insert into Customers (id, name) values ('2', 'Henry')
insert into Customers (id, name) values ('3', 'Sam')
insert into Customers (id, name) values ('4', 'Max')
Truncate table Orders
insert into Orders (id, customerId) values ('1', '3')
insert into Orders (id, customerId) values ('2', '1')

-- Write your MySQL query statement below

-- Using LEFT JOIN Query
select c.name as Customers
from Customers c
left join Orders o on c.id = o.customerId
where o.customerId is null;

-- Using NOT EXISTS Query
select c.name as Customers
from Customers c
where not exists (
    select 1
    from Orders o 
    where o.customerId = c.id
);