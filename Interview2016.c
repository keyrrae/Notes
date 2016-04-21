
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

Interview Questions
Here is an implementation of a BST. Write a function in C to find the minimum node of the tree.
Answer Question
Write a function to find the next in-order successor of any given node in a BST.
Answer Question
A question about what the main function in C does and why it is important to know the difference between char, char pointer, char array, and a pointer to char pointer.

Print a string and print a string in reverse order?
In-order traverse a binary search tree.



Implement a stack in my favorite language
2) OS and computer systems questions: x86 stack frame, Linux kernel (?)



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
