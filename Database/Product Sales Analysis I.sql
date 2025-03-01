/* SQL Schema for the Question */
Create table If Not Exists Sales (sale_id int, product_id int, year int, quantity int, price int);
Create table If Not Exists Product (product_id int, product_name varchar(10));

/* EQUI-JOIN */
SELECT P.product_name,S.year,S.price FROM Product P
JOIN Sales S ON S.product_id = P.product_id;