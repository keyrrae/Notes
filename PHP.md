```php

<!DOCTYPE html>
<html>
<body>

<?php
echo "My first PHP script!";
?>

</body>
</html>
```

What is a PHP File?
PHP files can contain text, HTML, CSS, JavaScript, and PHP code
PHP code are executed on the server, and the result is returned to the browser as plain HTML
PHP files have extension ".php"

What Do I Need?
To start using PHP, you can:

Find a web host with PHP and MySQL support
Install a web server on your own PC, and then install PHP and MySQL

PHP supports several ways of commenting:

```php
<!DOCTYPE html>
<html>
<body>

<?php
// This is a single-line comment

# This is also a single-line comment

/*
This is a multiple-lines comment block
that spans over multiple
lines
*/

// You can also use comments to leave out parts of a code line
$x = 5 /* + 15 */ + 5;
echo $x;
?>

</body>
</html>
```

PHP Case Sensitivity
In PHP, all keywords, classes, functions, and user-defined functions are NOT case-sensitive.

All legal:

```php
<!DOCTYPE html>
<html>
<body>

<?php
ECHO "Hello World!<br>";
echo "Hello World!<br>";
EcHo "Hello World!<br>";
?>

</body>
</html>
```

All variable names are case-sensitive.
`$color` and `$COLOR` are different variables.

Output variables
```php
<?php
$txt = "W3Schools.com";
echo "I love $txt!";
?>
```

Equivalent:
```php
<?php
$txt = "W3Schools.com";
echo "I love ". $txt . "!";
?>
```

function definition
```php
<?php
$x = 5; // global scope

function myTest() {
    // using x inside this function will generate an error
    echo "<p>Variable x inside function is: $x</p>";
}
myTest();

echo "<p>Variable x outside function is: $x</p>";
?>
```
`global` keyword

```php
<?php
$x = 5;
$y = 10;

function myTest() {
    global $x, $y;
    $y = $x + $y;
}

myTest();
echo $y; // outputs 15
?>
```

The global variables are stored in an array called $GLOBAL[]

```php
<?php
$x = 5;
$y = 10;

function myTest() {
    $GLOBALS['y'] = $GLOBALS['x'] + $GLOBALS['y'];
}

myTest();
echo $y; // outputs 15
?>
```

 The PHP `var_dump()` function returns the data type and value:
```php
<?php
$x = 5985;
var_dump($x);
?>
```

`int(5985)`

PHP objects
```php
<?php
class Car {
    function Car() {
        $this->model = "VW";
    }
}

// create an object
$herbie = new Car();

// show object properties
echo $herbie->model;
?>
```

`createTable`
Checks whether a table exists and, if not, create it.

`queryMysql`
Issues a query to MySQL, outputting an error message if it fails.

`destroySession`
Destroys a PHP session and clears its data to log users out.

`sanitizeString`
Removes potentially malicious code or tags from user input.

`showProfile`
Displays a user's image and "about me" message, if he has one.
