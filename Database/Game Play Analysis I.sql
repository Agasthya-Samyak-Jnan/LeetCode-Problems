/* SQL Schema for the Question */
Create table If Not Exists Activity (player_id int, device_id int, event_date date, games_played int)
Truncate table Activity
insert into Activity (player_id, device_id, event_date, games_played) values ('1', '2', '2016-03-01', '5')
insert into Activity (player_id, device_id, event_date, games_played) values ('1', '2', '2016-05-02', '6')
insert into Activity (player_id, device_id, event_date, games_played) values ('2', '3', '2017-06-25', '1')
insert into Activity (player_id, device_id, event_date, games_played) values ('3', '1', '2016-03-02', '0')
insert into Activity (player_id, device_id, event_date, games_played) values ('3', '4', '2018-07-03', '5')

-- Write your MySQL query statement below
select player_id,MIN(event_date) as first_login 
from Activity 
group by player_id;

/* Explanation :
   - Select player_id and MIN = minimum of (event_date) with minimum date named as "first_login"
   - get them from Activity Table of data
   - you should select minimum event_date for group of login data rows for each unqiue id - group by player_id