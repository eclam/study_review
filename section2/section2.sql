-- SELECT 
SELECT * 
FROM actor;
-- challenge select
SELECT first_name, last_name, email 
FROM customer;
-- Challenge select distinct
SELECT *  DISTINCT (rating) 
FROM film;

-- Count
SELECT COUNT(first_name) 
FROM customer;
SELECT COUNT(DISTINCT first_name) 
FROM customer;
SELECT COUNT(payment_id) 
FROM payment;
SELECT COUNT(DISTINCT customer_id) 
FROM payment;
SELECT COUNT(DISTINCT amount) 
FROM payment;

-- SELECT WHERE part 1
SELECT * 
FROM actor 
WHERE first_name = 'Jennifer';

-- SELECT WHERE part 2
SELECT title 
FROM film
WHERE rental_rate > 4 
    AND replacement_cost >= 19.99
    AND rating = 'R';

SELECT count(*) 
FROM film
WHERE rental_rate > 4 
    AND replacement_cost >= 19.99
    AND rating = 'R';

SELECT count(*) 
FROM film
WHERE rating = 'PG-13' 
    OR  rating = 'R';

SELECT * 
FROM film
WHERE  rating != 'R';

-- Challenge SELECT WHERE no.1
SELECT email 
FROM customer
WHERE first_name = 'Nancy' 
    AND last_name = 'Thomas';

-- Challenge SELECT WHERE no.2
SELECT description 
FROM film
WHERE title = 'Outlaw Hanky';

-- Challenge SELECT WHERE no.3
SELECT phone 
FROM address
WHERE address = '259 Ipoh Drive';

-- ORDER BY 
SELECT store_id, first_name, last_name 
FROM customer
ORDER BY store_id, first_name ASC;

-- LIMIT 
SELECT * 
FROM  payment
ORDER BY  payment_date DESC
LIMIT 5;

SELECT *
FROM payment
WHERE  amount != 0.00
ORDER BY payment_date DESC 
LIMIT 5;

-- challenge - order by & LIMIT 
SELECT customer_id 
FROM payment
ORDER BY payment_date ASC 
LIMIT 10;

SELECT title, length
FROM film
ORDER BY length ASC 
LIMIT 5;

SELECT COUNT(title)
FROM film
WHERE length <= 50;

-- BETWEEN 
SELECT * FROM payment
limit 1;
SELECT count(*)
FROM payment
WHERE amount BETWEEN  8 AND  9;
SELECT count(*)
FROM payment
WHERE amount NOT BETWEEN  8 AND  9;


SELECT  * 
FROM payment
WHERE payment_date 
    BETWEEN '2007-02-01' AND  '2007-02-15';

-- IN operator
SELECT DISTINCT(amount) 
FROM payment
WHERE amount IN (0.99,1.98, 1.99);

SELECT count(amount) 
FROM payment
WHERE amount NOT IN (0.99,1.98, 1.99);

-- LIKE AND ILIKE
SELECT first_name
FROM customer
WHERE first_name LIKE '_e%';

SELECT COUNT(*)
FROM customer
WHERE first_name LIKE 'J%' 
    AND last_name LIKE 'S%';
SELECT *
FROM customer
WHERE first_name LIKE 'J%' 
    AND last_name LIKE 'S%';

SELECT *
FROM customer
WHERE first_name NOT ILIKE 'j%'
    AND last_name NOT ILIKE 's%';

