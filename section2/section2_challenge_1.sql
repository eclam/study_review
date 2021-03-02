SELECT * FROM customer LIMIT 1;
SELECT * FROM address LIMIT 1;
SELECT * FROM film LIMIT 1;

-- Challenge 2
SELECT COUNT(amount)
FROM payment
WHERE amount > 5;

SELECT COUNT(first_name)
FROM actor
WHERE first_name LIKE 'P%';

SELECT COUNT(DISTINCT(district))
FROM address;

SELECT DISTINCT(district)
FROM address;

SELECT COUNT(*)
FROM film
WHERE rating = 'R'
    AND replacement_cost BETWEEN  5 and 15;

SELECT COUNT(title)
FROM film
WHERE title LIKE '%Truman%';

