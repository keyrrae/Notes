```html

<!DOCTYPE HTML>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <title>My first webpage</title>
    </head>
    <body>
        <h1>Hello,world</h1>
    </body>
</html>
```
CSS:

```html
<!DOCTYPE HTML>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <title>HTML and CSS</title>
        <style type="text/css">
        h1{
            font-size:12px;
            color:#930;
            text-align:center;
        }
        </style>
    </head>
    <body>
        <h1>Hello World!</h1>
    </body>
</html>
```
Marks
```html
<!DOCTYPE HTML>
<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
        <title>html tags</title>
    </head>


    <body>
        <h1>title here</h1>
        <p>This is paragraph 1</p>
        <p>THis is paragraph 2</p>
        <img src="http://img.mukewang.com/52b4113500018cf102000200.jpg" >
    </body>


</html>
```




```bash
$ traceroute www.ucsb.edu
```
The routes might change

millitaristic goals

selector {declaration1; declaration2; ... declarationN }
selector {property: value}
h1 {color:red; font-size:14px;}

p { color: #ff0000; }

p { color: rgb(255,0,0); }
p { color: rgb(100%,0%,0%); }


# Introduction to CSS

Cascading Style Sheets(CSS)

```html
<style>
  h1 {color:red; font-size:3em; font-family:Arial;}
</style>
```

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Hello World</title>
    <style>
        h1 { color:red; font-size:3em; font-family:Arial; }
    </style>
  </head>
  <body>
    <h1>Hello there</h1>
  </body>
</html>
```

## Importing a Style Sheet

```html
<style>
  @import url('styles.css');
</style>
```

## Importing a Style Sheet from Within HTML

```html
<link rel='stylesheet' type='text/css' href='styles.css' />
```

## Embedded Style Settings
```html
<div style='font-style:italic; color:blue;'>Hello there</div>
```

## Using IDs

A better solution for setting the style of an element is to assign an ID to it in the HTML

```html
<div id='iblue'>Hello there</div>
```
In CSS:
```html
#iblue {font-style:italic; color:blue;}
```

## Using Classes

```html
<div class='iblue'>Hello</div>
```

In CSS:
```html
.iblue { font-style:italic; color:blue; }
```

## CSS Rules

```html
h1 {font-size:240%;}
```

### Using Semicolons
### Multiple Assignments

```html
h1 { font-size:240%; color:blue; }

h1 { font-size:240%;
color:blue; }

h1 {
    font-size:240%;
    color:blue;
}
```
