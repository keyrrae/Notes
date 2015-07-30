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

Values are **constants**.

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

## Variables

**var** *name* : *type* = *initialization*

## Expressions

*A statement changes state*

*An expression express*

It produces a result

```scala
scala> val i = 1; val j = 2
i: Int = 1
j: Int = 2

scala> i + j
res1: Int = 3
```

```scala
// Expressions.scala
val c = {
  val i1 = 2
  val j1 = 4/i1
  i1 * j1
}
println(c)

/* Output:
4
*/
```

## Conditional Expressions

```
// If.scala
if(1 > 0) {
  println("It's true!")
}

/* Output:
It's true!
*/
```

Create a boolean expression
```
// If2.scala
val x:Boolean = { 1 > 0 }
if(x) {
  println("It's true!")
}

/* Output:
It's true!
*/
```

not:`!`

```
// If3.scala
val y:Boolean = { 11 > 12 }
if(!y) {
  println("It's false")
}

/* Output:
It's false
*/
```
