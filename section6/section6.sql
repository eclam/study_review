SHOW ALL;

SHOW TIMEZONE;

SELECT NOW();

SELECT TIMEOFDAY();

SELECT CURRENT_TIME;
SELECT CURRENT_DATE;

-- Timestamps & extract
SELECT * FROM payment;

SELECT EXTRACT(YEAR FROM payment_date) AS pay_month
FROM payment;


SELECT  AGE(payment_date)
FROM payment;

SELECT TO_CHAR(payment_date, 'mm-dd-yyyy')
FROM payment;

SELECT TO_CHAR(payment_date, 'MONTH YYYY')
FROM payment;

SELECT TO_CHAR(payment_date, 'mon/dd/YYYY')
FROM payment;

SELECT TO_CHAR(payment_date, 'dd/MM/YYYY')
FROM payment;


-- Timestamps and Extract Challenge Tasks
SELECT DISTINCT(TO_CHAR(payment_date, 'month'))
FROM payment;


SELECT COUNT(*)
FROM payment
WHERE EXTRACT(DOW FROM payment_date) = 1;

-- Math functs
SELECT ROUND(rental_rate/replacement_cost, 4)*100 AS precent_cost
FROM film;

-- string functs
SELECT LENGTH(first_name) FROM customer;

SELECT first_name || ' ' || last_name as full_name
FROM customer;

SELECT lower(left(first_name, 1)) || lower(last_name) || '@gmail.com'
FROM customer;

-- Subquery
SELECT title, rental_rate
FROM film
WHERE rental_rate > (SELECT AVG(rental_rate) FROM film);

SELECT * FROM rental;
SELECT * FROM inventory;

SELECT film_id, title
FROM film
WHERE  film_id IN
(SELECT inventory.film_id
FROM rental
INNER JOIN inventory 
    ON inventory.inventory_id = rental.inventory_id
WHERE return_date BETWEEN '2005-05-29' AND '2005-05-30')
ORDER BY film_id;

SELECT first_name, last_name
FROM customer AS c
WHERE EXISTS
(SELECT * FROM payment as p
WHERE p.customer_id = c.customer_id
    AND amount > 11);

-- SELF JOIN
SELECT film_a.title as og_title,
        film_b.title as similar_film_length,
        film_a.length as film_length
FROM film as film_a
INNER JOIN film as film_b
    ON film_a.length = film_b.length
        AND film_a.film_id != film_b.film_id
ORDER BY film_a.title ASC, film_b.title ASC;

