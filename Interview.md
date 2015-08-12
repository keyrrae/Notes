Why Behavioral Questions
As stated earlier, interviews usually start and end with “chit chat” or “soft skills.” This is a time
to answer questions about your resume or general questions, and also an opportunity for
you to ask questions. This part of the interview is targeted not only at getting to know you,
but also at relaxing you.
Be Specific, Not Arr


public HashMap<Integer, Student> buildMap(Student[] students) {

HashMap<Integer, Student> map = new HashMap<Integer, Student>();

for (Student s : students) map.put(s.getId(), s);

return map;
}


public String makeSentence(String[] words) {

StringBuffer sentence = new StringBuffer();

for (String w : words) sentence.append(w);

return sentence.toString();
}


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
