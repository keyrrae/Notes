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


At its core, jQuery focuses on retrieving elements from HTML pages and performing operations upon them.

To collect a group of elements, we pass the selector to the jQuery function Using

`$(selector)`

or

`jQuery(selector)`

To wrap the group of links nested inside any `<p>` elements

`$("p a")`

Hide all `<div>` elements that possess the class `notLongForThisWorld`.

`$("div.notLongForThisWorld").hide();`

*wrapper methods*:  they return the same group of elements, ready for another action.

Add a new class, removed, to each of the elements in addition to
hiding them.

`$("div.notLongForThisWorld").hide().addClass("removed");`

Selected element : an array

Achieve the same results with a selector that results in multiple
matched elements, the following two fragments would produce identical results

```
$("div.fillMeIn").html("I have added some text to a group of nodes");
```

and

```
var elements = $("div.fillMeIn");
for(var i=0;i<elements.length;i++)
  elements[i].innerHTML =
    "I have added some text to a group of nodes";
```
