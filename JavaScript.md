JavaScript is a client-side scripting language that runs entirely inside the web browser.

Place JavaScript code between `<script>` and `</script>` HTML tags

```html
<html>
  <head><title>Hello World</title></head>
  <body>
      <script type="text/javascript">
          document.write("Hello World")
      </script>
      <noscript>
        Your browser doesn't support or has disabled JavaScript
      </noscript>
  </body>
</html>
```



```javascript
<!DOCTYPE html>
<html>
<body>

<h1>My First JavaScript</h1>

<button type="button"
onclick="document.getElementById('demo').innerHTML = Date()">
Click me to display Date and Time.</button>

<p id="demo"></p>

</body>
</html>
```
