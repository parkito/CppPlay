CREATE TABLE users
(
    id       SERIAL PRIMARY KEY,
    email    VARCHAR(255),
    password TEXT NOT NULL
);