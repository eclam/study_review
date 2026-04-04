-- Join challenge tasks
SELECT * from address;
SELECT * from customer;

-- Challenge 1
SELECT address.district, customer.email
FROM address
INNER JOIN customer
    ON address.address_id = customer.address_id
WHERE address.district = 'California';

-- Challenge 2 version 1
SELECT * FROM film_actor;

SELECT film.title,
        starred_in.first_name,
        starred_in.last_name
FROM
    (
        SELECT actor.actor_id,
                actor.first_name,
                actor.last_name,
                film_actor.film_id 
        FROM actor
        INNER JOIN film_actor
            ON actor.actor_id = film_actor.actor_id
        WHERE first_name = 'Nick'
            AND last_name = 'Wahlberg'
    ) as starred_in
INNER JOIN film
    ON film.film_id = starred_in.film_id;


-- Challenge 2 version 2
SELECT film.title,
        actor.first_name,
        actor.last_name
FROM actor
INNER JOIN film_actor
    ON actor.actor_id = film_actor.actor_id
INNER JOIN film ON film.film_id = film_actor.film_id
WHERE actor.first_name = 'Nick'
    AND actor.last_name = 'Wahlberg';

