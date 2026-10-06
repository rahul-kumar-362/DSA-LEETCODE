# ROUND FUNCTION... 
#ROUND(VAL,2)--> here it is rounded till 2 decimal nos

#AVG(rating/position)--> Ek group mai

select query_name,

ROUND(AVG(rating/position),2) as quality,

ROUND(100* AVG(
CASE
    WHEN rating <3 THEN 1 
    ELSE 0
END
),2)

as poor_query_percentage

From Queries
Group By query_name;

