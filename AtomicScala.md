`println("Hello, Scala!")`

#Values
Initialize a value:

**val** *name* = *initialization*

Verbose version, specifying the type:

**val** *name* : *type* = *initialization*

```Scala
val whole = 11
val fractional = 1.4
val words = "A value"

println(whole, fraction, words)

/* Output
(11, 1.4, A value)
*/
```

Once you initialize a **val**, you can't change it.


Specifying the type:
```scala
val n = 1
val p:Double = 1.2
```

Basic types:
```scala
val whole:Int = 11
val fractional:Double = 1.4

// true or false:
val trueOrFalse:Boolean = true

val words:String = "A value"
val lines:String = """Triple quotes let
you have many lines
in your string"""

println(whole, fractional,
  trueOrFalse, words)

println(lines)
/* Output:
(11,1.4,true,c,A value)
Triple quotes allow
you to have many lines
in your string
*/
```
