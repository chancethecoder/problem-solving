/*
Variable_name	Value
innodb_version	5.7.17
protocol_version	10
slave_type_conversions	
tls_version	TLSv1,TLSv1.1
version	5.7.17-log
version_comment	MySQL Community Server (GPL)
version_compile_machine	x86_64
version_compile_os	Linux

X1	X2
1	2
36	37
37	38
38	39
39	40
40	41
41	42
42	43
43	44
44	45
45	46
46	47
54	53
55	54
56	55
57	56
58	57
59	58
60	59
61	60
62	61
63	62
64	63
65	64
66	65
67	66
68	67
*/

WITH    q AS 
        (
        SELECT  *
        FROM    PATHS
        UNION ALL
        SELECT  m.*
        FROM    PATHS m
        JOIN    q
        ON      m.X2 = q.X1
        )
SELECT  *
FROM    q

WITH RECURSIVE flatten(x1, x2) AS (
    SELECT x1, x2
    FROM PATHS WHERE x2 IS NULL
    UNION ALL
    SELECT u.x1, u.x2
    FROM flatten f
    INNER JOIN PATHS u ON f.x1 = u.x2
)
SELECT * FROM flatten;

SELECT * 
FROM PATHS r1
INNER JOIN PATHS r2 ON (r1.x2 = r2.x1 AND r2.x2 <> r1.x1)

SELECT * 
FROM PATHS r1
JOIN PATHS r2 ON (r1.x2 = r2.x1 AND r2.x2 <> r1.x1)


select * 
from PATHS p1
inner join (select p2.x1, p2.x2
            from PATHS p2
            where p2.x1 = p1.x2
            ) sub

select * 
from VALUES (1, 2), (36, 68)