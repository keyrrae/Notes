Why Behavioral Questions
As stated earlier, interviews usually start and end with “chit chat” or “soft skills.” This is a time
to answer questions about your resume or general questions, and also an opportunity for
you to ask questions. This part of the interview is targeted not only at getting to know you,
but also at relaxing you.
Be Specific, Not Arr

```java
public HashMap<Integer, Student> buildMap(Student[] students) {

HashMap<Integer, Student> map = new HashMap<Integer, Student>();

for (Student s : students) map.put(s.getId(), s);

return map;
}
```

```java
public String makeSentence(String[] words) {

StringBuffer sentence = new StringBuffer();

for (String w : words) sentence.append(w);

return sentence.toString();
}
```


```java
class Node {

Node next = null;

int data;

public Node(int d) { data = d; }

void appendToTail(int d) {

Node end = new Node(d);

Node n = this;

while (n.next != null) { n = n.next; }

n.next = end;

}
}
```


```java
class Stack {

Node top;

Node pop() {

if (top != null) {

Object item = top.data;

top = top.next;

return item;

}

return null;

}

void push(Object item) {

Node t = new Node(item);

t.next = top;

top = t;

}
}
```
C++ pointer syntax

```cpp
int
p =
v =
Foo
int
*p; // Defines pointer.
&q; // Sets p to address of q.
*p; // Set v to value of q.
*f = new Foo(); // Initializes f.
k = f->x; // Sets k equal to the value of f’s member variable.
```


A very common question in an interview is “describe the differences between C++ and Java.”
If you aren’t comfortable with any of these concepts, we recommend reading up on them.
1.	 Java runs in a virtual machine.
2.	 C++ natively supports unsigned arithmetic.
3.	 In Java, parameters are always passed by value (or, with objects, their references are
passed by value). In C++, parameters can be passed by value, pointer, or by reference.
4.	 Java has built-in garbage collection.
5.	 C++ allows operator overloading.
6.	 C++ allows multiple inheritance of classes.


final:
» » Class: Can not be sub-classed
» » Method: Can not be overridden.
» » Variable: Can not be changed.
static:
» » Method: Class method. Called with Foo.DoIt() instead of f.DoIt()
» » Variable: Class variable. Has only one copy and is accessed through the class name.
abstract:
» » Class: Contains abstract methods. Can not be instantiated.
» » Interface: All interfaces are implicitly abstract. This modifier is optional.
» » Method: Method without a body. Class must also be abstract.

14.1	 In terms of inheritance, what is the effect of keeping a constructor private?

SOLUTION
Declaring the constructor private will ensure that no one outside of the class can directly in-
stantiate the class. In this case, the only way to create an instance of the class is by providing
a static public method, as is done when using the Factory Method Pattern.
Additionally, because the constructor is private, the class also cannot be inherited.

In Java, does the finally block gets executed if we insert a return statement inside the
try block of a try-catch-finally?

SOLUTION
Yes, it will get executed.
The finally block gets executed when the try block exists. However, even when we attempt
to exit within the try block (normal exit, return, continue, break or any exception), the finally
block will still be executed.
Note: There are some cases in which the finally block will not get executed: if the
virtual machine exits in between try/catch block execution, or the thread which
is executing try/catch block gets killed.


14.3	 What is the difference between final, finally, and finalize?

pg 78
SOLUTIONS
Final
When applied to a variable (primitive): The value of the variable cannot change.
When applied to a variable (reference): The reference variable cannot point to any other ob-
ject on the heap.
When applied to a method: The method cannot be overridden.
When applied to a class: The class cannot be subclassed.
Finally
There is an optional finally block after the try block or after the catch block. Statements in the
finally block will always be executed (except if JVM exits from the try block). The finally block
is used to write the clean up code.
Finalize
This is the method that the JVM runs before running the garbage collector.


14.5	 Explain what object reflection is in Java and why it is useful.

pg 78
SOLUTION
Object Reflection is a feature in Java which provides a way to get reflective information about
Java classes and objects, such as:
1.	 Getting information about methods and fields present inside the class at run time.
2.	 Creating a new instance of a class.
3.	 Getting and setting the object fields directly by getting field reference, regardless of
what the access modifier is.

```java
	 import java.lang.reflect.*;
public class Sample {

public static void main(String args[]) {

try {

Class c = Class.forName(“java.sql.Connection”);

Method m[] = c.getDeclaredMethods();

for (int i = 0; i < 3; i++) {

System.out.println(m[i].toString());

}

} catch (Throwable e) {

System.err.println(e);

}

}
}
```

This code’s output is the names of the first 3 methods inside the “java.sql.Connection” class
(with fully qualified parameters).
Why it is useful:
1.	 Helps in observing or manipulating the runtime behavior of applications.
2.	 Useful while debugging and testing applications, as it allows direct access to methods,
constructors, fields, etc.


14.6	 Suppose you are using a map in your program, how would you count the number of
times the program calls the put() and get() functions?

pg 78
SOLUTION
One simple solution is to put count variables for get() and put() methods and, whenever they
are called, increment the count. We can also achieve this by extending the existing library
map and overriding the get() and put() functions.
At first glance, this seems to work. However, what if we created multiple instances of the
map? How would you sum up the total count for each map object?
The simplest solution for this is to keep the count variables static. We know static variables
have only one copy for all objects of the class so the total count would be reflected in count
variables.


19.1	 Write a function to swap a number in place without temporary variables.

pg 89
SOLUTION
This is a classic interview problem. If you haven’t heard this problem before, you can ap-
proach it by taking the difference between a and b:
1
2
3
4
5
6
7
8
public static void swap(int a, int b) {

a = b - a; // 9 - 5 = 4

b = b - a; // 9 - 4 = 5

a = a + b; // 4 + 5 = 9


System.out.println(“a: “ + a);

System.out.println(“b: “ + b);
}
You can then optimize it as follows:
1
2
3
4
5
6
7
8

public static void swap_opt(int a, int b) {

a = a^b;

b = a^b;

a = a^b;


System.out.println(“a: “ + a);

System.out.println(“b: “ + b);
}
