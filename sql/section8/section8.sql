-- CREATRE TABLE
CREATE  TABLE  players(
    player_id SERIAL PRIMARY KEY,
    age TYPE smallint NOT NULL
);

CREATE TABLE account( 
    user_id SERIAL NOT NULL primary key,
    username VARCHAR(50) UNIQUE NOT NULL,
    PASSWORD VARCHAR (50) NOT NULL,
    email varchar(255) UNIQUE NOT NULL,
    created_on TIMESTAMP  NOT NULL,
    last_login TIMESTAMP
);

SELECT * FROM account;

CREATE TABLE job(
    job_id SERIAL PRIMARY  KEY ,
    job_name VARCHAR (200) UNIQUE NOT NULL 
);

CREATE TABLE account_job(
    user_id INTEGER REFERENCES account(user_id),
    job_id INTEGER  REFERENCES job(job_id),
    hired_date TIMESTAMP 
);

-- INSERTION
INSERT INTO account(username, password, email, created_on)
VALUES
('Jose','password', 'jose@mail.com', CURRENT_TIMESTAMP);


INSERT INTO job(job_name)
VALUES('Astronaut');

INSERT INTO account_job(user_id, job_id, hired_date)
VALUES(1, 1, CURRENT_TIMESTAMP);

SELECT * FROM account_job;

-- UPDATE
UPDATE account
SET last_login = CURRENT_TIMESTAMP;
SELECT * FROM account;

UPDATE account
SET last_login = created_on;

UPDATE account_job
SET hired_date = account.created_on
FROM account
WHERE account_job.user_id = account.user_id;

SELECT * FROM account_job;

UPDATE account
SET last_login = CURRENT_TIMESTAMP
RETURNING email, created_on, last_login;

-- DELETE

INSERT INTO job(job_name)
VALUES
('Cowboy');
DELETE FROM job
WHERE job_name = 'Cowboy'
RETURNING job_id, job_name;

-- ALTER
CREATE TABLE  information(
    info_id SERIAL PRIMARY KEY ,
    title VARCHAR (500) NOT NULL,
    person VARCHAR (50) NOT  NULL UNIQUE
);

ALTER TABLE information
RENAME TO new_info;

ALTER TABLE new_info
RENAME COLUMN person TO people;

SELECT * FROM new_info;

INSERT INTO new_info(title)
VALUES('some new title');

ALTER  TABLE new_info
ALTER COLUMN people DROP NOT NULL;

INSERT INTO new_info(title)
VALUES('some new title');

-- DROP
ALTER TABLE new_info
DROP COLUMN people;
SELECT  * FROM new_info;

ALTER TABLE new_info
DROP COLUMN IF EXISTS people;

-- CHECK CONSTRAINT
CREATE TABLE employees(
    emp_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    birthdate DATE CHECK (birthdate > '1900-01-01'),
    hire_date DATE CHECK (hire_date > birthdate),
    SALARY INTEGER CHECK (SALARY > 0)
);

INSERT INTO employees(
    first_name,
    last_name,
    birthdate,
    hire_date,
    salary
)
VALUES('Jose', 'Portilla', '1990-11-03','2010-01-01', 100);

SELECT * FROM employees;


