
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

