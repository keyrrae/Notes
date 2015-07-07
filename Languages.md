
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
