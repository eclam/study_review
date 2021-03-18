-- AS statement
SELECT COUNT(*) AS num_transactions
FROM payment;

SELECT customer_id, SUM(amount) as total_spent
FROM payment
GROUP BY customer_id;

-- NOTE: aliasing gets applied at the end
SELECT customer_id, SUM(amount) as total_spent
FROM payment
GROUP BY customer_id
HAVING  SUM(amount) > 100;

-- INNER JOIN 
SELECT payment_id, payment.customer_id, payment.amount, first_name
FROM payment
INNER JOIN customer
ON payment.customer_id = customer.customer_id;

-- FULL OUTER JOIN
SELECT * FROM customer
FULL OUTER JOIN payment
ON customer.customer_id = payment.customer_id
WHERE customer.customer_id is NULL
    OR payment.payment_id is NULL;

-- LEFT OUTTER JOIN 
SELECT film.film_id, film.title, inventory_id, store_id
FROM film
LEFT JOIN inventory
ON inventory.film_id = film.film_id
WHERE inventory.film_id is NULL;

-- Right outer join
SELECT film.film_id, film.title, inventory_id, store_id
FROM inventory
LEFT JOIN film
ON inventory.film_id = film.film_id
WHERE inventory.film_id is NULL;

-- UNIONS TEMPLATE EXAMPLE
SELECT * FROM ${table_1}
UNION
SELECT * FROM  ${table_2};
