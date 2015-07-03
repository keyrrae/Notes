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
