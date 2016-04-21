
//verify/validate BST
#include <limits.h>
bool isBST(struct node* root){
    return isBSThelper(root, INT_MIN, INT_MAX);
}

bool isBSThelper(struct node* node, int min, int max){
    if (node == NULL){
        return true;
    }
    if(node->data <min|| node->data> data){
        return false;
    }

    return isBSThelper(node->left, min, node->data - 1) &&
    isBSThelper(node->right, node->data+1, max);
}


//what will be output of trick program and why it is like that...
//Design malloc.

//What is the difference between process and thread?
/*
Process: an instance of a program in execution
separated address space
cannot access the variables and data structures

thread:exists inside a process
share the process resource(heap)
each has its own registers and stack

// context switching

▼
In operating systems when multiple processes are being run on a single
processor, and the user or os specifies that it wants to switch processes
its called a context switch. The old process gets its "state" saved
in memory and gets push onto a ready queue. When the OS or the user
is ready to start running it again it gets poped off the ready queue
and starts running again. Another context switch.
What is the difference between a mutex and a semaphore?  Which one would you use to protect access to an increment operation?

Both mutexes and semaphores are used to control access to a shared resource – most often in multithreading scenarios.  A mutex is used when only one thread or process is allowed to access a resource and a semaphore is used when only a certain set limit of threads or processes can access the shared resource.  Essentially a mutex is a semaphore where the limit is set to 1.

//How can processes communicate with each other?
OS allocates a shared memory
communication pipes in Linux
process A calls the kernel passing a pointer to a buffer with data to be transferred to process B, process B calls the kernel (or is already blocked on a call to the kernel) passing a pointer to a buffer to be filled with data from process A.
As you can see the cost of communication is high since it involves at least one context switch.

// What's the pure virtue function and how to use it.

// The coding portion was implementing functions of a binary search tree.
//The other questions asked by mouth were on things…
//The questions they ask were straight forward.
They first ask some concept questions about different data structure.
What is the difference between vector and linked list?
And then they asked me what did two functions do(the two functions did the same job and he showed this two on his terminal), which one is faster. The time function was already there, just call it.
//Remove nodes in a linked list having a particular integer data value.
//validate binary search tree
//There are a few questions on the details of C.

/*1' The role of fflush to flush out the strings.
2' A macro that computes a size_t number. Putting in a loop, it casts -1 to a size_t number, making the loop impossible to start.
3' Sudoku solver
4' Design a generic stack class.

Interview
I handed my resume on College's career fair and got one phone interview. basic of c programming in Linux . I did get the offer. Maybe because I take too many time on the second question(you should know how to use gettimeofday() in c). It not a difficult test. But I messed up.

Interview Questions
1.remove repeat elements from list
2.test run time
*/
//Verify BST
//Could you have malloc metadata at the end of your block ? If yes, how could you implement it ?
//What is the functional difference between these two declarations:
char * string1="string";
char string2[]="string";

//Reverse a linked list
// level order
// trie
//Had to write code to find the minimum element in a BST and also find the next largest element from the current node in the BST. Then had to explain what a function did (printed all the elements in the BST in increasing order). Also had to given the time complexities of all these functions.
If a program is forked.The parent and child have a printf   statement.What will be the order of the printf statements?
Answer   Add Tags	Flag as Inappropriate
Interview Answer

2 Answers

▲
0
▼
It will not be in any particular order as the CPU keeps on swapping between the parent and child process.

1. Java的abstract class和interface的区别
2. Java overwriting和overloading的区别
3. Java的final method有什么作用
4. 用C写binary search tree successor

1. 给了一个简单的程序
int main(int argc, char * argv){
    for (int i = 0; i < argc; i++) {
         printf("%s\n", argv[i]);
    }
}

编译执行之后出现了segmetation fault。面试官要求我用gdb打出程序的call stack，并且分析其中的错误。
然后在打出call stack之后问我print argv[i]打印出来的变量的地址是virtual address还是physical address, virtual address是在编译程序的时候分配的还是执行的时候分配的，如何通过virtual address计算physical address。

2. 实现一个stack，这个题目是可以选择C++的。面试官首先问我如何写出pop function的接口，使得stack里面能够存任何数据类型。 我写了 int push(struct stack_elm_t ** top, void * value, int length),返回值是-1表示error, 0表示成功，length表示数据的长度。-google 1point3acres
因为我是用linkedlist实现的，首先我写stack中每个node的结构体：
typedef struct _stack_elm {
   void *value;
   struct _stack *prev;
} stack_elm_t;
鏉ユ簮涓€浜�.涓夊垎鍦拌鍧�.
然后面试官问我要是我们不想在pop function里面传** top的话，应该怎么办？而且我们可能在初始化stack的同时已经固定了数据的长度。 经过他的提示，大致的意思是需要写一个新的结构体存stack的基本信息，包括现在的栈顶和每个value的长度：

typedef struct _stack {
   struct _stack_elm * top;. From 1point 3acres bbs
   int length;
} stack_t;

. 鐗涗汉浜戦泦,涓€浜╀笁鍒嗗湴
之后我实现了peek, create, push三个function, 大致的代码如下（可能会有一些错误）：
.鐣欏璁哄潧-涓€浜�-涓夊垎鍦�
typedef struct _stack_elm {
   void *value;
   struct _stack_elm *prev;
} stack_elm_t;


typedef struct _stack {
   struct _stack_elm * top;
   int length;
} stack_t;


stack_t* create(int length) {
   stack_t * s = (stack_t *) malloc ( sizeof (stack_t));
   s->length = length;. From 1point 3acres bbs
   return s;. From 1point 3acres bbs
}

void pop(stack_t * s) {
   if ( s == NULL || s->top == NULL) {
      return NULL;. 1point3acres.com/bbs
   }. 鍥磋鎴戜滑@1point 3 acres
   stack_t * current = s->top;-google 1point3acres
   s->top = s->top->prev;
   free(current->value);
   free(current);
}

void * peek(stack_t * s) {
   if ( s == NULL || s->top == NULL) {
      return NULL;
   }
   return s->top->value;
}

int push(stack_t * s, void * value) {
   if ( s == NULL ) {
      return -1;. 1point 3acres 璁哄潧
   }. 鐗涗汉浜戦泦,涓€浜╀笁鍒嗗湴
   temp = ( stack_elm_t * ) malloc ( sizeof( stack_elm_t ));
   temp->val = ( void *) malloc(s->length);.鏈枃鍘熷垱鑷�1point3acres璁哄潧
   memcpy(temp->value, value, s->length);
   temp->prev = s->top;
   s->top = temp;. Waral 鍗氬鏈夋洿澶氭枃绔�,
   return 0;. visit 1point3acres.com for more.

}. more info on 1point3acres.com

C里写一个function传入二维数组长度然后返回数组的指针要用malloc。全场听大叔教学。
第二轮美国小哥C++写stack实现queue，排序数组找一个missing number用C


// Check whether linked list has a loop
int detectloop(struct node *list)
{
    struct ListNode *fast,*slow;
        if(head==NULL) return false;
        slow=head;
        fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            if(slow==fast) return true;
            slow=slow->next;
            fast=fast->next->next;
        }
        return false;
}

// Valid palindrome
bool isChar(char *ch)
{
    *ch = tolower(*ch);
    if((*ch>='a' && *ch<='z')||(*ch>='0' && *ch <='9')) return true;
    return false;
}

bool isPalindrome(char* s) {
    int len = strlen(s);
    if (len<=1) return true;
    char * ft=s,*lt = s+len-1;
    while (ft<lt)
    {
        while(!isChar(ft) && ft < lt)
        {
            ft++;
        }

        while(!isChar(lt) && ft < lt)
        {
            lt--;
        }
        //if(isChar(ft) && isChar(lt))
        //{
            if( *ft!= *lt) return false;
            ft++;
            lt--;
        //}
    }
    return true;
}


// Remove duplicates
struct ListNode* deleteDuplicates(struct ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        struct ListNode* node = head;
        while (node->next != NULL) {
            if (node->val == node->next->val) {
                struct ListNode* temp = node->next;
                node->next = node->next->next;
                free(temp);
            } else {
                node = node->next;
            }
        }
        return head;
}

// Find missing element in an array
int findMissing( int* a, int len ) {
    int left = 0, right = len;
    int mid;
    while(left < right){
        mid = left + (right - left) / 2;
        if(a[mid] > a[0] + mid) right = mid;
        else left = mid+1;

    }
    return a[0] + left;
}


// compare version

int compareVersion(char* v1, char* v2) {
     while(*v1 != '\0' || *v2 != '\0'){
        int version1 = 0;
        int version2 = 0;

        //collect the version number for both;
        while((*v1 != '.' && *v1 != '\0') || (*v2 != '.' && *v2 != '\0')) {
            if(*v1 != '.' && *v1 != '\0')
            {
                version1 = 10*version1 + (*v1 - '0');
                v1++;
            }
            if(*v2 != '.' && *v2 != '\0')
            {
                version2 = 10*version2 + (*v2 - '0');
                v2++;
            }
        }

        if(version1 > version2) return 1;
        else if(version1 < version2) return -1;
        else if(*v1 == '\0' && *v2 == '\0') return 0;

        if(*v1 == '.') v1++;
        if(*v2 == '.') v2++;
    }
}

//Binary Search Tree : In order Successor O(h), where h is the height of the tree

struct node* inOrderSuccessor(struct node* root, struct node* n){
    if(n->right != NULL){
        return minValue(n->right);
    }

    struct node *successor = NULL;
    while(root != NULL){
        if(n->data < root->data){
            successor = root;
            root = root->left;
        }
        else if (x->data > root->data){
            root = root->right;
        }
        else break;
    }
    return successor;
}

/* Given a non-empty binary search tree,
return the minimum data value found in that
tree. Note that the entire tree does not need
to be searched. */
int minValue(struct node* node) {
  struct node* current = node;

  /* loop down to find the leftmost leaf */
  while (current->left != NULL) {
    current = current->left;
  }
  return(current->data);
}


int maxValue(struct node* node){
    struct node* current = node;

    while(current->right != NULL){
        current = current->right;

    }

    return (current->data);
}


# and ## operators
In function-like macros, a # operator before an identifier in the replacement-list runs the identifier through parameter replacement and encloses the result in quotes, effectively creating a string literal. In addition, the preprocessor adds backslashes to escape the quotes surrounding embedded string literals, if any, and doubles the backslashes within the string as necessary. All leading and trailing whitespace is removed, and any sequence of whitespace in the middle of the text (but not inside embedded string literals) is collapsed to a single space. This operation is called "stringification". If the result of stringification is not a valid string literal, the behavior is undefined.
When # appears before __VA_ARGS__, the entire expanded __VA_ARGS__ is enclosed in quotes:
#define showlist(...) puts(#__VA_ARGS__)
showlist();            // expands to puts("")
showlist(1, "x", int); // expands to puts("1, \"x\", int")
(since C++11)
A ## operator between any two successive identifiers in the replacement-list
runs parameter replacement on the two identifiers (which are not macro-expanded
  first) and then concatenates the result. This operation is called
  "concatenation" or "token pasting". Only tokens that form a valid token
  together may be pasted: identifiers that form a longer identifier, digits
  that form a number, or operators + and = that form a +=. A comment cannot
  be created by pasting / and * because comments are removed from text before
  macro substitution is considered. If the result of concatenation is not a valid token,
  the behavior is undefined.

Note: some compilers offer an extension that allows ## to appear after a comma and before __VA_ARGS__, in which case the ## does nothing when __VA_ARGS__ is non-empty, but removes the comma when __VA_ARGS__ is empty: this makes it possible to define macros such as fprintf (stderr, format, ##__VA_ARGS__)



12 hours
ssh programming:
1. Write a generic [template ] stack class.
1.1 write the interface, [push,pop...]
1.2 implement push
1.3 how to use it for array of stacks.
2. what's the output of the following program

2.1
int main() {
char * s="12345";
printf("%d\n",s);
}
what is the output?
//random

what is the value in memory of the byte that is pointed by s?
0x34333231

2.2
int get() {
static int n = 0;
return ++n;
}
int printf( char const * fmt, ... ) {
// breakpoint
...
}


int main() {
printf ( "%d %d\n", get(), get());
}


//1 2



bool isChar(char *ch)
{
    *ch = tolower(*ch);
    if((*ch>='a' && *ch<='z')||(*ch>='0' && *ch <='9')) return true;
    return false;
}

bool isPalindrome(char* s) {
    int len = strlen(s);
    if (len<=1) return true;
    char * ft=s,*lt = s+len-1;
    while (ft<lt)
    {
        if(!isChar(ft))
        {
            ft++;
        }

        if(!isChar(lt))
        {
            lt--;
            continue;
        }
        if(isChar(ft) && isChar(lt))
        {
            if( *ft!= *lt) return false;
            ft++;
            lt--;
        }
    }
    return true;
}


Basically, your base class is a struct; derived structs must include the base struct at the first position, so that a pointer to the "derived" struct will also be a valid pointer to the base struct.

typedef struct {
   data member_x;
} base;

typedef struct {
   struct base;
   data member_y;
} derived;

void function_on_base(struct base * a); // here I can pass both pointers to derived and to base

void function_on_derived(struct derived * b); // here I must pass a pointer to the derived class
The functions can be part of the structure as function pointers, so that a syntax like p->call(p) becomes possible, but you still have to explicitly pass a pointer to the struct to the function itself.


A question about what the main function in C does and why it is important to
know the difference between char, char pointer, char array, and a pointer
to char pointer.

Print a string and print a string in reverse order?
In-order traverse a binary search tree.



Implement a stack in my favorite language
2) OS and computer systems questions: x86 stack frame, Linux kernel (?)

double read_timer(){
  static bool initialized = false;
  static struct timeval start;
  struct timeval end;
  if(!initialized){
    gettimeofday(&start, NULL);
    initialized = true;
  }
  gettimeofday(&end, NULL);

  return (end.tv_sec - start.tv_sec) + 10e6 *(end.tv_usec - start.tv_ucsec);
}


#include <stdio.h>

/* Write a quick program to tell me the size of this structure: */

struct s {
   double f;
   int i;
   char c[3];
   void *p;
   int x[0];
}

int main( int argc, char ** argv ) {

}

============================================================================
/* What does this do?
#define ABC(x) aaa ## x

ABC(b)
*/

============================================================================
/* Find the size */
int main() {
   const char *s1 = "hello";
   char s2[] = "world";

   printf( "sizeof s1 : %d sizeof s2 : %d\n", sizeof(s1), sizeof(s2) );
   printf( "lenof s2 : %d\n", strlen(s2) );
}

============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main( int argc, char* argv[] ){
    char* s1 = "STRING1";
    char s2[] = "STRING2";
    char *s3 = NULL;

    s1[ 1 ] = 'P';
    s2[ 1 ] = 'P';

    s3 = malloc(5);
    strcpy(s3, "test");
    s3[1]= 'P';
}

============================================================================
/* What is the difference between these variables? */

int i1;
int j=0;

int main() {
   const char *s1 = "hello world";
   char s2[] = "hellow world";
   static int i2;
   static int k=1;
}

AVL TREE, B TREE, RED BLACK TREE, TRIE，还一个我不认识的（大概也是一种BST?），
选一个自己最了解的进行介绍。我先说了一会Trie,然后说了一会B TREE。

The first round was quite basic where they gauge your understanding of the C language.
It starts off my some questions such as explain what malloc does.
Then it goes into more detail like how would you malloc over a PCI-e.
Then there were some terms and they ask you if you know what it means and explain them.
Terms such as traceroute, ifconfig, ping, wireshark, ip, etc.
Wireshark to Capture, Filter and Inspect Packets

 traceroute is a computer network diagnostic tool for displaying the route (path)
 and measuring transit delays of packets across an Internet Protocol (IP) network.
 The history of the route is recorded as the round-trip times of the packets received
 from each successive host (remote node) in the route (path); the sum of the mean times
 in each hop is a measure of the total time spent to establish the connection.

  Traceroute proceeds unless all (three) sent packets are lost more than twice,
  then the connection is lost and the route cannot be evaluated.

  Ping, on the other hand, only computes the final round-trip times from the destination point.

  ifconfig is a system administration utility in Unix-like operating systems for network interface configuration.

  The utility is a command line interface tool and is also used in the system startup scripts of many operating systems.
   It has features for configuring, controlling,
  and querying TCP/IP network interface parameters. Ifconfig originally appeared in 4.2BSD as part of the BSD TCP/IP suite.

You might also be asked some other basic questions around unix such as
what does fork do, what would kill -11 do,
what does select do, what will happen if I type this and so on.

After this they moved to some code.
The first of this was involving two strings inside the main function.
Something like this:
int main( int argc, char* argv[] ){
  char* string1 = "string";
  char string2[] = "string";
}
Then you will be asked to modify a certain position in each string, say index 1.
You might get thrown off by string1 since it's a string literal and therefore is read-only.
You can't modify it. String2 will work fine in this case.

After this I was asked to write a palindrome function in C. This should be easy.
I was also asked to write a Python script that reads in a file containing numbers separated by spaces on multiple lines.
Treat the first number in each line as column1 and so on. I was asked to add all the numbers in column3. This should be easy again.

Make sure you can easily write code in a command line editor such as Vi or Emacs.
Also make sure you know how to compile C code and run python script from the terminal.
You should also have the basic knowledge of how to debug a file using GDB on the command line in case you get a segfault.

The second round was more thorough:
I was asked first to write up a stack API that a client would use.
The client should be given the freewill to add any type of data that he/she wants.
For example, they can push 1byte of data at a time or 1MB of data.
The interviewer gave me three requirements that had to be fulfilled.
I don't quite remember these off the top of my head.
As you design your API you will be asked to demonstrate how the push and pop will be coded.
 Also, be open to changing your design as the interviewer will thrown in more conditions.
 I felt for this part you should be aware of size_t, and void *.
  These came in handy when writing the function signature.

The second hour of this interview was to compare to version strings. Here's how the docstring of the function looked like:
/*
  vercmp compares two software version strings and returns the following:
      if v1 > v2 : return 1
      if v1 == v2 : return 0
      if v1 < v2 : return -1
  input strings are in the form "1.0.3", "2.10", "6.0.0.3", etc...
  "1.0" is considered bigger than "1"
*/
int vercmp( char * v1, char * v2 ) {

}

I think the only way to do this is to keep track of the periods in each string and compare the corresponding numbers.


Physical addressing means that your program actually knows the real layout of RAM. When you access a variable at address 0x8746b3, that's where it's really stored in the physical RAM chips.

With virtual addressing, all application memory accesses go to a page table, which then maps from the virtual to the physical address. So every application has its own "private" address space, and no program can read or write to another program's memory. This is called segmentation.

Virtual addressing has many benefits. It protects programs from crashing each other through poor pointer manipulation, etc. Because each program has its own distinct virtual memory set, no program can read another's data - this is both a safety and a security plus. Virtual memory also enables paging, where a program's physical RAM may be stored on a disk (or, now, slower flash) when not in use, then called back when an application attempts to access the page. Also, since only one program may be resident at a particular physical page, in a physical paging system, either a) all programs must be compiled to load at different memory addresses or b) every program must use Position-Independent Code, or c) some sets of programs cannot run simultaneously.

The physical-virtual mapping may be done in software (with hardware support for memory traps) or in pure hardware. Sometimes even the page tables themselves are on a special set of hardware memory. I don't know off the top of my head which embedded system does what, but every desktop has a hardware TLB (Translation Lookaside Buffer, basically a cache for the virtual-physical mappings) and some now have advanced Memory Mapping Units that help with virtual machines and the like.
