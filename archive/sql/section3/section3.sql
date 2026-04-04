-- Aggregate
SELECT MIN(replacement_cost) 
FROM film;

SELECT MAX(replacement_cost)
FROM film;

SELECT MAX(replacement_cost), MIN(replacement_cost)
FROM film;

SELECT AVG(replacement_cost), ROUND(AVG(replacement_cost),2)
FROM film;

SELECT SUM(replacement_cost)
FROM film;

--  GROUP BY
SELECT * FROM payment;

SELECT customer_id, SUM(amount)
FROM payment
GROUP BY customer_id
ORDER BY  SUM(amount) DESC;

SELECT customer_id, COUNT(amount)
FROM  payment
GROUP BY  customer_id
ORDER BY count(amount) DESC;

SELECT  staff_id, customer_id, SUM(amount)
FROM payment
GROUP BY  staff_id, customer_id
ORDER BY customer_id, staff_id;

SELECT DATE(payment_date), SUM(amount)
FROM payment
GROUP BY DATE(payment_date)
ORDER BY  SUM(amount) DESC;

SELECT DATE(payment_date), SUM(amount)
FROM payment
GROUP BY DATE(payment_date)
ORDER BY  DATE(payment_date) DESC;

-- GROUP BY CHALLENGE
SELECT staff_id, COUNT(amount)
FROM payment
GROUP BY staff_id
ORDER BY COUNT(amount) DESC
LIMIT 1;

SELECT rating, AVG(replacement_cost)
FROM film
GROUP BY rating
ORDER BY AVG(replacement_cost) DESC;

SELECT customer_id, SUM(amount)
FROM payment
GROUP BY customer_id
ORDER BY SUM(amount) DESC
LIMIT 5;

-- HAVING
SELECT customer_id, SUM(amount)
FROM payment
WHERE customer_id NOT IN (184,87,477)
GROUP BY customer_id
HAVING SUM(amount) > 100;

SELECT store_id, COUNT(customer_id)
FROM customer
GROUP BY store_id
HAVING COUNT(customer_id) > 300;

-- HAVING CHALLENGE
SELECT customer_id, COUNT(*)
FROM payment
GROUP BY customer_id
HAVING COUNT(*) >= 40;

SELECT customer_id, staff_id, SUM(amount)
FROM payment
WHERE staff_id = 2
GROUP BY customer_id, staff_id
HAVING SUM(amount) > 100;
