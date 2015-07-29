`SELECT LastName FROM Persons;`

`SELECT title FROM publications WHERE author = 'Charles Dickens';`

*Database*
The overall container for a collection of MySQL data

*Table*
A subcontainer within a database that stores the actual data.

*Row*
A single record within a table, which may contain several fields

*Column*
The name of a field within a row.

`$ mysql -u root -p`

Login as root user without a password.

`mysql> SHOW databases;`

**Don't press Ctrl-C to cancel a command**, it will close the program

Cancel: `\c`

`meaningless gibberish to mysql \c`

Don't use `\c` inside a string or after a semicolon, it won't work


- SQL commands and keywords are case-insensitive
- the recommended style is to use uppercase
- Table names are case-sensitive on Linux and OS X
- the recommended style is to use lowercase or mixed for table names

###Creating a database
`CREATE DATABASE publications;`
`USE publications`

### Creating users

`GRANT` : create a user

`GRANT PRIVILEGES ON database.object TO 'username'@'hostname' IDENTIFIED BY 'password';`

| Arguments      |  Meaning |
| :------------- | :---------------------------------------- |
| \*.\*          | All databases and all their objects       |
| database.\*    | Only the database called *databse* and all its objects       |
| database.object| Only the database called *databse* and its object called *object*       |


`CRANT ALL ON publications.* TO 'jim'@'localhost' IDENTIFIED BY 'mypassword';`

login as jim:

`mysql -u jim -p`

### Creating a table

```SQL
CREATE TABLE classics(
  author VARCHAR(128),
  title VARCHAR(128),
  type VARCHAR(16),
  year CHAR(4)
) ENGINE MyISAM;
```

To check whether new table has been created:

`DESCRIBE classics;`

```MySQL
mysql> USE publications;
Database changed

mysql> CREATE TABLE classics (
 -> author VARCHAR(128),
 -> title VARCHAR(128),
 -> type VARCHAR(16),
 -> year CHAR(4)) ENGINE MyISAM;
Query OK, 0 rows affected (0.03 sec)

mysql> DESCRIBE classics;
+--------+--------------+------+-----+---------+-------+
| Field | Type | Null | Key | Default | Extra |
+--------+--------------+------+-----+---------+-------+
| author | varchar(128) | YES | | NULL | |
| title | varchar(128) | YES | | NULL | |
| type | varchar(16) | YES | | NULL | |
| year | char(4) | YES | | NULL | |
+--------+--------------+------+-----+---------+-------+
4 rows in set (0.00 sec)

```

### Datatypes
`VARCHAR`: VARiable length CHARacter string

`VARCHAR(128)`: maximum length 128

`CHAR(4)`:  fixed length character string

Data type Bytes used Examples
CHAR(n) Exactly n (<= 255) CHAR(5): “Hello” uses 5 bytes
CHAR(57): “New York” uses 57 bytes
VARCHAR(n) Up to n (<= 65535) VARCHAR(100): “Greetings” uses 9 bytes plus 1 byte overhead
VARCHAR(7): “Morning” uses 7 bytes plus 1 byte overhead

Data type Bytes used Examples
BINARY(n) or BYTE(n) Exactly n (<= 255) As for CHAR, but contains binary data
VARBINARY(n) Up to n (<= 65535) As for VARCHAR, but contains binary data

Data type Bytes used Attributes
TINYTEXT(n) Up to n (<= 255) Treated as a string with a character set
TEXT(n) Up to n (<= 65535) Treated as a string with a character set
MEDIUMTEXT(n) Up to n (<= 16777215) Treated as a string with a character set
LONGTEXT(n) Up to n (<= 4294967295) Treated as a string with a character set


BLOB: Binary Large object

Data type Bytes used Attributes
TINYBLOB(n) Up to n (<= 255) Treated as binary data—no character set
BLOB(n) Up to n (<= 65535) Treated as binary data—no character set
MEDIUMBLOB(n) Up to n (<= 16777215) Treated as binary data—no character set
LONGBLOB(n) Up to n (<= 4294967295) Treated as binary data—no character set

Numeric data types

Table 8-10. MySQL’s numeric data types
Data type
Bytes
used
Minimum value
(signed/unsigned)
Maximum value
(signed/unsigned)
TINYINT 1 −128
0
127
255
SMALLINT 2 −32768
0
32767
65535
MEDIUMINT 3 −8388608
0
8388607
16777215
INT or INTEGER
4 −2147483648
0
2147483647
4294967295
BIGINT 8 −9223372036854775808
0
9223372036854775807
18446744073709551615
FLOAT 4 −3.402823466E+38
(no unsigned)
3.402823466E+38
(no unsigned)
DOUBLE or REAL 8 −1.7976931348623157E+308
(no unsigned)
1.7976931348623157

SIGNED vs UNSIGNED
```MySQL
CREATE TABLE tablename (fieldname INT UNSIGNED);
CREATE TABLE tablename (fieldname INT(4) ZEROFILL);
CREATE TABLE tablename (fieldname INT(4) ZEROFILL);
```

DATE and TIME

Data type Time/date format
DATETIME '0000-00-00 00:00:00'
DATE '0000-00-00'
TIMESTAMP '0000-00-00 00:00:00'
TIME '00:00:00'
YEAR 0000 (Only years 0000 and 1901 - 2155)
