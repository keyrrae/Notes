
## Introduction

###Typing Model
Strong(Java) or weak(C)

Static(Java) or dynamic(Ruby)


###Programming Model
Object-oriented: Ruby Scala

Functional:Scala, Erlang, Clojure, Haskell

Procedural

hybrid: Scala

logic-based: Prolong

###Interaction
Compiled
Interpreted
Virtual Machines


###Decision and Data Structures
Pattern matching in Erlang

unification in Prolog

Collections



## Ruby

EncapsulationL data and behaviro are packaged together

Inheritance: object types are organized in a class tree

polymophism: objects can take many forms

```Ruby
>> properties = ['object oriented', 'duck typed', 'productive', 'fun']
>> properties.each {|| puts "Ruby is #{property}"}

```

```Ruby
>> puts 'hello, world'
>> language = 'Ruby'
>> puts "hello, #{language}"
```

One quote around a string means interpreted literally

Two quotes leads to string evaluation.

Pure OO language
```Ruby
>> 4.class
=> Fixnum
>> 4.methods
=> ["inspect", "%", "<<", ...]
>> 4 < 5
=> true
>> true.class
=> TrueClass
>> false.class
=> FalseClass

>> puts '...' unless x == 4
>> puts '...' if x == 4
>> if x == 4
>> 	puts '...'
>> end


>> unless x == 4
>>	puts '...'
>> else
?>	puts '...'
>> end
>>
>> not true
=> false
>> !true
=> false
>> x = x + 1 while x < 10
>> x = x - 1 until x = 1
>> while x < 10
>>	x = x + 1
>>	put x
>> end
```

Everything but `nil` and `false` evaluate to `true`.

0 is `true` !!!

`and`  `&&`

`or`  `||`

`not`  `!`

### Duck Typing
Ruby is strong typed.

Get an error message when types collide at run time.

*Dynamic Typing*

Ruby does not do type checking until execution.


```Ruby
>> 4.class
=> Fixnum
>> (4.0).class
=> Float

>> 4 + 4.0
=> 8.0

>> 4 + 'four'
TypeError: ...

```

*Duck Typing*

```Ruby
i = 0
a = ['100', 100.0]
while i < 2
	puts a[i].to_i
	i = i + 1
end

100
100
```

Duck typing doesn't care what the underlying type might be

###Defining Functions

We don't have to build a whole class to define a function(Unlike in Java).

Every function returns something. If we do not explicitly return something,
the function will return the value of the last expression.

Function is an object. Functions can be passed to other functions as parameters.

```Ruby
>> def tell_the_truth
>> 		true
>> end
```

###Arrays

```Ruby
>> animals = ['lions', 'tigers', 'bears']
=> ['lions', 'tigers', 'bears']

>> puts animals
lions
tigers
bears
=> nil

>> animals[0]
=> "lions"

>> animals[10]
=> nil

>> animals[-1]
=> "bears"

>> animals[0..1]
=> ['lions','tigers']

>> (0..1).class
=> Range
```
Arrays don't need to be homogeneous:
```Ruby
>> a = ["zero", 1, ["two", "thins"]]
=> ["zero", 1, ["two", "thins"]]
```

Multidimentional array:
```Ruby
>> a = [[1, 2, 3], [10, 20, 30], [40, 50, 60]]
=> [[1, 2, 3], [10, 20, 30], [40, 50, 60]]

>> a[0][0]
=> 1

>> a[1][2]
=> 30
```

###Hashes
```Ruby
>> numbers = {1 => 'one', 2 => 'two'}
=> {1 => 'one', 2 => 'two'}

>> numbers[1]
=> 'one'

>> stuff = {:array => [1, 2, 3], :string => 'Hi, mom!'}
=> {:array => [1, 2, 3], :string => "Hi, mom!"}

>> stuff[:string]
=> "Hi, mom!"
```

## Clojure
*s-expressions*

```Clojure
(max 3 5)
5
(+ 1 (* 2 3))
7
(def meaning-of-life 42)
(if (< meaning-of-life 0) "negative" "non-negative")
"non-negative"
```
Vector:[]

Starts with index 0
```Clojure
(def droids ["Huey","Dewey","Louie"])
(count droids)
3
(droids 0)
"Huey"
(droids 2)
"Louie"
```

Map:{}

```Clojure
(def me {:name "Paul" :age 45 :sex :male})
(:age me)
45
```

function `defn`, with arguments specified as a vector:

```Clojure
(defn percentage [x p] (* x (/ p 100.0)))
(percentage 200 10)
20.0
```
```java
public int sum(int[] numbers){
	int accumulator = 0;
	for (int n:numbers)
		accumulator += n;
	return accumulator;
}
```

```clojure
(defn recursive-sum [numbers]
	(if (empty? numbers)
		0
		(+ (first numbers) (recursive-sum (rest numbers)))))
```
##Haskell

Concatenate with ++ instead of +

```Haskell

Prelude> "Hello"
"Hello"
Prelude> "Hello" + "world"

<interactive>:1:0:
No instance for (Num [Char])
arising from a use of `+' at <interactive>:1:0-17
Possible fix: add an instance declaration for (Num [Char])
In the expression: "hello" + " world"
In the definition of `it': it = "hello" + " world"

Prelude> "Hello" ++ "world"
"Hello world"
```

Chars and string

A string is just a list of characters

```Haskell
Prelude> 'a'
'a'
Prelude> ['a','b']
"ab"
```

Booleans

`True` and `False`

In Haskell, `if` is a function, not a control structure. It returns a value just like any other function.

```Haskell
Prelude> if (5 == 5) then "true"

<interactive>:1:23: parse error (possibly incorrect indentation)

Prelude> if (5 == 5) then "true" else "false"
"true"
```

Haskell is strong typed, `if` takes strictly boolean types.
```Haskell
Prelude> if 1 then "true" else "false"

<interactive>:1:3:
No instance for (Num Bool)
arising from the literal `1' at <interactive>:1:3
...

Prelude> "one" +1

<interactive>:1:0:
No instance for (Num [Char])
arising from a use of `+' at <interactive>:1:0-8
...
```

Type inference `:t`
```Haskell
Prelude> :t 5
5 :: (Num t) =>t
```

Turn on the type inference option
```Haskell
Prelude> :set +t

Prelude> 5
5
it :: Integer

Prelude> 5.0
5.0
it :: Double

Prelude> "hello"
"hello"
it :: [Char]

Prelude> (5 == (2 + 3))
True
it :: Bool
```

`let`: binds a variable to a function in a local scope
```Haskell
Prelude> let x = 10

Prelude> x
10

Prelude> let double x = x * 2

Prelude> double 2
4
```

Specifying type
```Haskell
module Main where
	double :: Integer -> Integer
	double x = x +x
```
```Haskell
Prelude> :load double.hs
[1 of 1] Compiling Main ( double.hs, interpreted)
Ok, modules loaded: Main.
*Main> double 5
10

*Main> :t double
double :: Integer -> Integer
```

Recursion
```Haskell
Prelude> let fact x = if x == 0 then 1 else fact (x - 1) * x
Prelude> fact 3
6
```

```Haskell
module Main where
	factorial :: Integer -> Integer
	factorial 0 = 1
	factorial x = x * factorial (x - 1)
```
