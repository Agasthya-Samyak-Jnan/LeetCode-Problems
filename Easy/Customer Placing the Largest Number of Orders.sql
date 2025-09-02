/* SQL Schema */
Create table If Not Exists orders (order_number int, customer_number int)
Truncate table orders
insert into orders (order_number, customer_number) values ('1', '1')
insert into orders (order_number, customer_number) values ('2', '2')
insert into orders (order_number, customer_number) values ('3', '3')
insert into orders (order_number, customer_number) values ('4', '3')

/* 
    Query 1 - Using GROUP BY and Aggregate Functions 
    1. Find Count of Orders by each Customer.
    2. Get the Maximum Count of Orders out of all Order Counts.
    3. Find the Customer who has Order Count same as Maximum Count of Orders.
*/
select customer_number from Orders
group by customer_number 
having COUNT(*) = (
        select MAX(orders) from (
            select COUNT(*) as orders from Orders
            group by customer_number
        ) 
        as max_count
);

/* Query 2 - Using ORDER BY and LIMIT */
select customer_number from Orders
group by customer_number
order by COUNT(order_number) desc
limit 1;