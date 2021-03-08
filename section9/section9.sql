CREATE TABLE students(
    student_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    homeroom_number SMALLINT,
    phone VARCHAR(20) UNIQUE NOT NULL,
    email VARCHAR (250) UNIQUE,
    graduation_year integer
);

CREATE TABLE teachers(
    teacher_id SERIAL PRIMARY KEY,
    first_name VARCHAR(50) NOT NULL,
    last_name VARCHAR(50) NOT NULL,
    homeroom_number SMALLINT,
    department VARCHAR(20),
    email VARCHAR(250) UNIQUE,
    phone VARCHAR(20) UNIQUE
);

INSERT INTO students(first_name, last_name, homeroom_number, phone, email, graduation_year)
VALUES ('Mark', 'Watney', 5, '777-555-1234', '','2035');

INSERT INTO teachers(first_name, last_name, homeroom_number, department, email, phone)
VALUES('Jonas','Salk',5,'Biology','jsalk@school.org','777-555-4321');


DROP TABLE students;
DROP TABLE teachers;