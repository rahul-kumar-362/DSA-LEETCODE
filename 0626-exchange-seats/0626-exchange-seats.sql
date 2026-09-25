SELECT
    E.id,
    COALESCE(O.student, E.student) AS student
FROM Seat AS E
LEFT JOIN Seat AS O
ON (
      (E.id % 2 = 1 AND O.id = E.id + 1)
   OR (E.id % 2 = 0 AND O.id = E.id - 1)
)
ORDER BY E.id;