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
