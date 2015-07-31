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
JFrame frame = new JFrame();
JButton button = new JButton(“click me”);
frame.getContentPane().add(button);
frame.setSize(300,300);
frame.setVisible(true);
```
