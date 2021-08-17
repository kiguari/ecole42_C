CREATE DATABASE wordpress;
CREATE USER 'Eshakita'@'%' IDENTIFIED BY 'Eshakita';
GRANT ALL PRIVILEGES ON wordpress.* TO 'Eshakita'@'%';
FLUSH PRIVILEGES;
