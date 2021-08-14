CREATE DATABASE IF NOT EXISTS test;
use test;
CREATE TABLE `Person` (
  Id int AUTO_INCREMENT,
  Email VARCHAR(256) NOT NULL DEFAULT '',
  PRIMARY KEY `Id`(Id)
);

INSERT INTO Person (Email) values ("john@exmaple.com"), ("bob@exmaple.com"), ("john@exmaple.com");

