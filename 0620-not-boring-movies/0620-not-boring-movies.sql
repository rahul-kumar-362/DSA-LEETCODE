# Write your MySQL query statement below

select * from Cinema
where description != "boring"
AND id%2!=0
-- group by Cinema     GROUP BY IS used when AGGREgate functions
order by rating desc
