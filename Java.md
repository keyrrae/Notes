##Modern Java
In modern java, `HashMap` is used to replace `Hashtable`, and `ArrayList` is used to replace `Stack`.

##`final`, `finally` and `finalize`
###`final`

`final` can be used to mark a variable "unchangeable"

```java
    private final String name = "foo";  //the reference name can never change
```

`final` can also make a method not "overrideable".

`final` in front of a method prevents any inheriting class from changing its meaning.

Any `private` methods in a class are implicitly `final`, because you cannot access a `private` method.

`final` classes cannot be inherited. Never need any changes or for safety reasons you don't want subclassing.


```java
    public final String toString() {  return "NULL"; }
```

`final` can also make a class not "inheritable". i.e. the class can not be subclassed.

```java
public final class finalClass {...}
public class classNotAllowed extends finalClass {...} // Not allowed
```

###`finally`

`finally` is used in a try/catch statement to "always" execute code


```java
lock.lock();
try {
    //do stuff
} catch (SomeException se) {
    //handle se
} finally {
    lock.unlock(); //always executed, even if Exception or Error or se
}
```

Java 7 has a new try with resources statement that you can use to automatically close resources that explicitly or implicitly implement java.io.Closeable or `java.lang.AutoCloseable`

###`finalize`

`finalize` is called when an object is garbage collected. You rarely need to override it. An example:

```java
    public void finalize() {
      //free resources (e.g. unallocate memory)
      super.finalize();
    }
```

##public private protected

##Constructors and polymorphism

###Order of constructor calls

1. The base-class constructor is called, followed by the next-derived class, etc.,
recursively until the most-derived class is reached.

2. Member initializers are called in the order of declaration.

3. The body of the derived-class constructor is called.

###Inheritance and cleanup

##Annotation
@Override, to indicate that a method definition is intended to override a method in
the base class. This generates a compiler error if you accidentally misspell the method
name or give an improper signature. 2
@Deprecated, to produce a compiler warning if this element is used.
@SuppressWarnings, to turn off inappropriate compiler warnings. This annotation
is allowed but not supported in earlier releases of Java SE5 (it was ignored).

# Error Handling with Exceptions
The basic philosophy of Java is that "badly formed code will not be run"

```java
if(t == null)
  throw new NullPointerException();
```

Exception arguments

```java
throw new NullPointerException("t = null")
```

Catching an exception

```java
try {
  // Code that might generate exceptions
}
```

Exception handlers
```java
try{
  // Code that might generate exceptions
} catch(Type1 id1) {
  // Handle exceptions of Type1
} catch(Type2 id2){
  // Handle exceptions of Type2
} catch(Type3 id3){
  // Handle exceptions of Type3
}
```

Creating your own exceptions

```java
class SimpleException extends Exception{}

public class InheritingExceptions {
  public void f() throws SimpleException({
    System.out.println("Throw SimpleException from f()");
    throw new SimpleException();
  }
  public static void main(String[] args) {
    InheritingExceptions sed = new InheritingExceptions();
    try {
      sed.f();
    } catch(SimpleException e){
      System.out.println("Caught it!");
    }
  }
} /* Output:
Throw SimpleException from f()
Caught it!
*/
```
# Inner classes
Creating inner classes

You create an inner class just as you’d expect—by placing the class definition inside a
surrounding class:

```java
public class Parcel1 {
class Contents {
private int i = 11;
public int value() { return i; }
}
class Destination {
private String label;
Destination(String whereTo) {
label = whereTo;
}
String readLabel() { return label; }
}
// Using inner classes looks just like
// using any other class, within Parcel1:
public void ship(String dest) {
Contents c = new Contents();
Destination d = new Destination(dest);
System.out.println(d.readLabel());
}
public static void main(String[] args) {
Parcel1 p = new Parcel1();
p.ship("Tasmania");
}} /* Output:
Tasmania
*/
```
# Strings

Objects of the **String** class are immutable.

# Type Information
Runtime type information (RTTI) allows you to discover and use
type information while a program is running.

```java
import java.util.*

abstract class Shape{
  void draw(){
    System.out.println(this + ".draw()");
  }
}

class Circle extends Shape{
  public String toString() {
    return "Circle";
  }
}

class Square extends Shape{
  public String toString() {
    return "Square";
  }
}

class Triangle extends Shape{
  public String toString() {
    return "Triangle";
  }
}

public class Shapes {
  public static void main(String[] args) {
    List<Shape> shapeList = Arrays.asList(
      new Circle(), new Square(), new Triangle()
    );
    for(Shape shape : shapeList)
      shape.draw();
    }
} /* Output:
Circle.draw()
Square.draw()
Triangle.draw()
*/
```



# I/O

## The **File** class

A directory lister

```java
import java.util.regex.*;
import java.io.*;
import java.util.*;

public class DirList {
  public static void main(String[] args) {
    File path = new File(".");
    String[] list;
    if(args.length == 0)
      list = path.list();
    else
      list = path.list(new DirFilter(args[0]));
    Arrays.sort(list, String.CASE_SENSITIVE_ORDER);
    for(String dirItem : list)
      System.out.println(dirItem);
  }
}

public class DirFilter implements FilenameFilter{
  private Pattern pattern;
  public DirFilter(String regex){
    pattern = Pattern.compile(regex);
  }
  public boolean accept(File dir, String name){
    return pattern.matcher(name).matches();
  }
}

```
The **FilenameFilter** interface:

```java
public interface FilenameFilter {
  boolean accept(File dir, String name);
}
```

# Enumerated Types

```java
 import static net.mindview.util.Print.*;
enum Shrubbery { GROUND, CRAWLING, HANGING }enum Shrubbery { GROUND, CRAWLING, HANGING }
public class EnumClass {
public static void main(String[] args) {
for(Shrubbery s : Shrubbery.values()) {
print(s + " ordinal: " + s.ordinal());
printnb(s.compareTo(Shrubbery.CRAWLING) + " ");
printnb(s.equals(Shrubbery.CRAWLING) + " ");
print(s == Shrubbery.CRAWLING);
print(s.getDeclaringClass());
print(s.name());
print("----------------------");
}
// Produce an enum value from a string name:
for(String s : "HANGING CRAWLING GROUND".split(" ")) {
Shrubbery shrub = Enum.valueOf(Shrubbery.class, s);
print(shrub);
}
}
} /* Output:
GROUND ordinal: 0
-1 false false
class Shrubbery
GROUND
----------------------
CRAWLING ordinal: 1
0 true true
class Shrubbery
CRAWLING
----------------------
HANGING ordinal: 2
1 false false
class Shrubbery
HANGING
----------------------
HANGING
CRAWLING
GROUND
*///:~
```


Using static imports with enums
Consider a variation of Burrito.java from the Initialization & Cleanup chapter:
```java

package enumerated;
public enum Spiciness {
NOT, MILD, MEDIUM, HOT, FLAMING
}


package enumerated;
import static enumerated.Spiciness.*;
public class Burrito {
Spiciness degree;
public Burrito(Spiciness degree) { this.degree = degree;}
public String toString() { return "Burrito is "+ degree;}
public static void main(String[] args) {
System.out.println(new Burrito(NOT));
System.out.println(new Burrito(MEDIUM));
System.out.println(new Burrito(HOT));
}
} /* Output:
Burrito is NOT
Burrito is MEDIUM
Burrito is HOT
*/
# Concurrency

## Defining tasks

To define a task, simply implement `Runnable` and write a  `run()` method to make the task do your bidding

```java
public class LiftOff implements Runnable {
  protected int countDown = 10;
  private static int taskCount = 0;
  private final int id = taskCount++;
  public LiftOff() {}
  public LiftOff(int countDown) {
    this.countDown = countDown;
  }  
  public String status() {
    return "#" + id + "(" +
      (countDown > 0 ? countDown : "LiftOff!") + "), ";
  }
  public void run() {
    while(countDown-- > 0){
      System.out.println(status());
      Thread.yield();
    }
  }  
}
```


## The Thread class

```java
public class BasicThreads {
  public static void main(String[] args) {
    Thread t = new Thread(new LiftOff());
    t.start();
    System.out.println("Waiting for LiftOff");
  }
}

```

### Building GUI with JFrame

```java
import javax.swing.*; //Dont't forget to import this swing package

public class SimpleGui1 {
    public static void main (String[] args) {
        JFrame frame = new JFrame();
        JButton button = new JButton(“click me”);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        frame.getContentPane().add(button);
        frame.setSize(300,300);
        frame.setVisible(true);
    }
}
```

`JButton`

`JCheckBox`

`JTextField`

```java
JPanel panelA = new JPanel();
JPanel panelB = new JPanel();
panelB.add(new JButton(“button 1”));
panelB.add(new JButton(“button 2”));
panelB.add(new JButton(“button 3”));
panelA.add(panelB);
```
