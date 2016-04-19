


'''c
// Check whether linked list has a loop

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
'''

# and ## operators
In function-like macros, a # operator before an identifier in the replacement-list runs the identifier through parameter replacement and encloses the result in quotes, effectively creating a string literal. In addition, the preprocessor adds backslashes to escape the quotes surrounding embedded string literals, if any, and doubles the backslashes within the string as necessary. All leading and trailing whitespace is removed, and any sequence of whitespace in the middle of the text (but not inside embedded string literals) is collapsed to a single space. This operation is called "stringification". If the result of stringification is not a valid string literal, the behavior is undefined.
When # appears before __VA_ARGS__, the entire expanded __VA_ARGS__ is enclosed in quotes:
#define showlist(...) puts(#__VA_ARGS__)
showlist();            // expands to puts("")
showlist(1, "x", int); // expands to puts("1, \"x\", int")
(since C++11)
A ## operator between any two successive identifiers in the replacement-list runs parameter replacement on the two identifiers (which are not macro-expanded first) and then concatenates the result. This operation is called "concatenation" or "token pasting". Only tokens that form a valid token together may be pasted: identifiers that form a longer identifier, digits that form a number, or operators + and = that form a +=. A comment cannot be created by pasting / and * because comments are removed from text before macro substitution is considered. If the result of concatenation is not a valid token, the behavior is undefined.
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
random

what is the value in memory of the byte that is pointed by s?
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

1 2



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

nterview Questions
Here is an implementation of a BST. Write a function in C to find the minimum node of the tree.  
Answer Question
Write a function to find the next in-order successor of any given node in a BST.  
Answer Question
A question about what the main function in C does and why it is important to know the difference between char, char pointer, char array, and a pointer to char pointer.  

Print a string and print a string in reverse order?
In-order traverse a binary search tree.  

Implement a stack in my favorite language
2) OS and computer systems questions: x86 stack frame, Linux kernel (?)  

I applied online and had an on-campus interview. It is not very hard though something I cannot answer. What is the difference between process and thread? How can processes communicate with each other? BST find the minimum node. BST find the node with next larger value of a given value.
