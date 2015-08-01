```html
<script type="text/javascript"
        src="scripts/jquery-1.4.js"></script>
```

JavaScript code:
```JavaScript
var checkedValue;
var elements = document.getElementsByTagName('input');
for (var n = 0; n < elements.length; n++) {
  if (elements[n].type == 'radio' &&
    elements[n].name == 'someRadioGroup' &&
    elements[n].checked) {
    checkedValue = elements[n].value;
 }
}
```

Using jQuery:
`var checkedValue = $('[name="someRadioGroup"]:checked').val();`
