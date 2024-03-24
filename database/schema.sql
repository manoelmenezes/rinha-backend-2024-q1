CREATE DATABASE rinha;
CREATE USER rinha_user WITH PASSWORD '123456';
grant all privileges on database rinha to rinha_user;

CREATE TABLE clients (id SERIAL PRIMARY KEY, bound INTEGER NOT NULL, balance INTEGER NOT NULL);

INSERT INTO clients(bound, balance) VALUES(100000, 0);
INSERT INTO clients(bound, balance) VALUES(80000, 0);
INSERT INTO clients(bound, balance) VALUES(1000000, 0);
INSERT INTO clients(bound, balance) VALUES(10000000, 0);
INSERT INTO clients(bound, balance) VALUES(500000, 0);

CREATE TABLE transactions (id SERIAL PRIMARY KEY, value INTEGER NOT NULL, type CHAR(1) NOT NULL, description VARCHAR(10) NOT NULL, client_id INTEGER NOT NULL, CONSTRAINT fk_client FOREIGN KEY(client_id) REFERENCES clients(id) ON DELETE CASCADE);


GRANT ALL PRIVILEGES ON TABLE clients TO rinha_user;

GRANT ALL PRIVILEGES ON TABLE transactions TO rinha_user;
