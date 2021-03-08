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

-- 