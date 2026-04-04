SELECT * FROM cd.bookings LIMIT 1;
SELECT * FROM cd.members LIMIT 1;
SELECT * FROM cd.facilities LIMIT 1;

-- Question 1
SELECT  *
FROM cd.facilities;

-- Question 2
SELECT  name as facility_name, membercost
FROM cd.facilities;

-- Question 3
SELECT *
FROM cd.facilities
WHERE membercost > 0;

-- Question 4
SELECT facid, name as facility_name, membercost, monthlymaintenance
FROM cd.facilities
WHERE membercost > 0
    AND (membercost < monthlymaintenance/50);

-- Question 5
SELECT *
FROM cd.facilities
WHERE name LIKE '%Tennis%';

-- Question 6
SELECT *
FROM cd.facilities
WHERE facid = 1
UNION
SELECT *
FROM cd.facilities
WHERE facid = 5;

SELECT *
FROM cd.facilities
WHERE facid IN (1,5);

-- Question 7
SELECT * 
FROM cd.members
WHERE joindate >= '2012-09-01';

-- Question 8
SELECT DISTINCT(surname)
FROM cd.members
ORDER BY  surname ASC
LIMIT 10;

-- Question 9
SELECT to_char( MAX(joindate), 'YYYY-MM-DD HH24:MI:SS' )
FROM cd.members;

-- Question 10
SELECT COUNT(*)
FROM cd.facilities
WHERE guestcost >= 10;

-- Question 11
SELECT facid, sum(slots) AS "Total Number of Slots"
FROM cd.bookings
WHERE starttime >= '2012-09-01' AND starttime < '2012-10-01'
GROUP BY facid
ORDER BY sum(slots);

-- Question 12
SELECT facid, sum(slots) AS "total_slots"
FROM cd.bookings
GROUP BY facid
HAVING sum(slots) >= 1000
ORDER BY facid;

-- Question 13
SELECT to_char( cd.bookings.starttime, 'YYYY-MM-DD HH24:MI:SS' ),
        cd.facilities.name
FROM cd.bookings
INNER JOIN cd.facilities ON cd.facilities.facid = cd.bookings.facid
WHERE cd.facilities.name LIKE 'Tennis Court%'
    AND cd.bookings.starttime >= '2012-09-21'
    AND cd.bookings.starttime < '2012-09-22'
ORDER BY cd.bookings.starttime;

-- Question 14
SELECT cd.members.firstname,
        cd.members.surname,
        cd.bookings.*
FROM cd.members
INNER JOIN cd.bookings
    ON cd.bookings.memid = cd.members.memid
WHERE cd.members.firstname = 'David'
    AND cd.members.surname = 'Farrell'
ORDER BY  cd.bookings.starttime;