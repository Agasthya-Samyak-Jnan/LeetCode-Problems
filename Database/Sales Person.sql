/* SQL Schema for the Question */
Create table If Not Exists SalesPerson (sales_id int, name varchar(255), salary int, commission_rate int, hire_date date);
Create table If Not Exists Company (com_id int, name varchar(255), city varchar(255));
Create table If Not Exists Orders (order_id int, order_date date, com_id int, sales_id int, amount int);

/* EQUI-JOIN + NOT EXISTS QUERY - NESTED QUERIES */
SELECT S.name from SalesPerson S
WHERE NOT EXISTS (
    SELECT * FROM Orders O
    JOIN Company C ON O.com_id = C.com_id
    WHERE O.sales_id = S.sales_id AND C.name = 'RED'
);

/* WITHOUT USING JOIN - ONLY NESTED QUERIES */
SELECT S.name from SalesPerson S
WHERE NOT EXISTS (
    SELECT O.order_id FROM Orders O
    WHERE EXISTS (
        SELECT C.name FROM Company C
        WHERE O.com_id = C.com_id AND O.sales_id = S.sales_id AND C.name = 'RED'
    )
);