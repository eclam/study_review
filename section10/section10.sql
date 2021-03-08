-- CASE
SELECT customer_id,
CASE
    WHEN (customer_id <= 100) THEN 'Premium'
    WHEN (customer_id BETWEEN 100 and 200) THEN 'Plus'
    ELSE 'Normal'
END AS customer_class
FROM customer
ORDER BY customer_id;

SELECT customer_id,
CASE customer_id
    WHEN 2 THEN 'Winner'
    WHEN 5 THEN 'Second Place'
    ELSE 'Loser'
END AS raffle_results
FROM customer;

SELECT rental_rate,
CASE rental_rate
    WHEN 0.99 THEN 1
    ELSE 0
END
FROM film;

SELECT 
SUM(
    CASE rental_rate
        WHEN 0.99 THEN 1
        ELSE 0
    END
) as number_of_bargains
FROM film;

SELECT 
SUM(
    CASE rental_rate
        WHEN 0.99 THEN 1
        ELSE 0
    END
) as bargains,
SUM(CASE rental_rate
        WHEN 2.99 THEN 1
        ELSE 0
    END
) as regular,
SUM(CASE rental_rate
        WHEN 4.99 THEN 1
        ELSE 0
    END
) as premium
FROM film;


-- Case Challenge
SELECT * FROM film;

SELECT
SUM(
    CASE rating
        WHEN 'R' THEN 1
        ELSE 0
    END
) AS r,
SUM(
    CASE rating
        WHEN 'PG' THEN 1
        ELSE 0
    END
) AS pg,
SUM(
    CASE rating
        WHEN 'PG-13' THEN 1
        ELSE 0
    END
) AS pg13
FROM film;

-- COALESCE
---- EXAMPLE: IF discount == NULL => 0 (Coalesce looks for the next NON null val)
SELECT item, (price - coalesce(discount,0)) AS final
FROM table;

-- CAST
SELECT CAST('5' AS INTEGER) AS new_int;

----Postgresql cast shorthand:
SELECT '5'::INTEGER as new_int;
----

SELECT inventory_id, CHAR_LENGTH( CAST(inventory_id AS VARCHAR)) FROM rental;

-- NULLIF
CREATE TABLE depts(
    first_name VARCHAR(50),
    department VARCHAR (50)
);
INSERT INTO depts(
    first_name,
    department
)
VALUES('Vinton', 'A'),('Lauren','A'),('Claire','B');

SELECT (
    SUM(CASE WHEN department = 'A' THEN 1 ELSE 0 END)/
    SUM(CASE WHEN department = 'B' THEN 1 ELSE 0 END)
) AS department_ratio
FROM depts;

DELETE FROM depts
WHERE department = 'B';

SELECT (
    SUM(CASE WHEN department = 'A' THEN 1 ELSE 0 END)/
    NULLIF(SUM(CASE WHEN department = 'B' THEN 1 ELSE 0 END),0)
) AS department_ratio
FROM depts;

-- VIEWS
CREATE VIEW customer_info AS
SELECT first_name, last_name, address FROM customer
INNER JOIN address
ON customer.address_id = address.address_id;

SELECT * FROM customer_info;

CREATE OR REPLACE VIEW customer_info AS
SELECT first_name, last_name, address, district FROM customer
INNER JOIN address
ON customer.address_id = address.address_id;

ALTER VIEW customer_info RENAME to c_info;
SELECT * FROM c_info;

DROP VIEW IF EXISTS c_info;