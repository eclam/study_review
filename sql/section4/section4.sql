-- Assessment test

-- Question 1
SELECT customer_id, staff_id, SUM(amount)
FROM payment
WHERE staff_id = 2
GROUP BY customer_id, staff_id
HAVING SUM(amount) >= 110;

-- Question 2
SELECT COUNT(title)
FROM film
WHERE title LIKE 'J%';

-- Question 3
SELECT customer_id, first_name, last_name address_id
FROM customer
WHERE first_name LIKE 'E%'
    AND address_id < 500
ORDER BY customer_id DESC
LIMIT 1;