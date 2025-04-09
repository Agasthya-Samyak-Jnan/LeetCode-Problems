/* SQL Schema for the Question */
Create table If Not Exists Person (Id int, Email varchar(255))
Truncate table Person
insert into Person (id, email) values ('1', 'john@example.com')
insert into Person (id, email) values ('2', 'bob@example.com')
insert into Person (id, email) values ('3', 'john@example.com')

-- Write your MySQL query statement below
with UniqueEmails as (
    select MIN(id) as keep_id
    from Person p
    group by p.email
    having COUNT(p.email) >= 1
)

delete from Person 
where id not in (select keep_id from UniqueEmails);

/* Explanation :
    * Create a Common Table Expression (You can think it of as a variable of type 'table' , here of type 'Person').
    * Then fill this table with Minimum ids in ascending order into the table whose emails have appeared in table 'Person'.
      This query essentially keeps IDs of first occurence of each email if you think it deeply.
    * The id in this new table is named as 'keep_id'.
    * Then delete row entries from Person whose 'id' is not in list of IDs in 'UniqueEmails' table.