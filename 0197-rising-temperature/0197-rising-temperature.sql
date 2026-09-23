# Write your MySQL query statement below
select N.id from Weather as P# next ki id in O/P
INNER JOIN Weather as N
ON DATEDIFF(N.recordDate, P.recordDate) = 1#ITS used for correct difference
where  P.temperature<N.temperature;
