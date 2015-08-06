##Print contents to files
```python
log = open('logfile.txt', 'w')

print >> log, ('Downloading file from URL %s' % url)
text = urllib.urlopen(url).read()
print >> log, 'File successfully downloaded'
log.write("WTF\n")
```


##Comman Line Arguments
Python provides a getopt module that helps you parse command-line options and arguments.

`$ python test.py arg1 arg2 arg3`

The Python `sys` module provides access to any command-line arguments via the `sys.argv`. This serves two purposes −

`sys.argv` is the list of command-line arguments.

`len(sys.argv)` is the number of command-line arguments.

Here `sys.argv[0]` is the program ie. script name.

Example
Consider the following script test.py −

```python
#!/usr/bin/python

import sys

print 'Number of arguments:', len(sys.argv), 'arguments.'
print 'Argument List:', str(sys.argv)
```

Now run above script as follows −

`$ python test.py arg1 arg2 arg3`

This produce following result −

```
Number of arguments: 4 arguments.
Argument List: ['test.py', 'arg1', 'arg2', 'arg3']
```

NOTE: As mentioned above, first argument is always script name and it is also being counted in number of arguments.

Parsing Command-Line Arguments
Python provided a `getopt` module that helps you parse command-line options and arguments. This module provides two functions and an exception to enable command line argument parsing.

`getopt.getopt` method
This method parses command line options and parameter list. Following is simple syntax for this method −

`getopt.getopt(args, options[, long_options])`
Here is the detail of the parameters −

`args`: This is the argument list to be parsed.

`options`: This is the string of option letters that the script wants to recognize, with **options that require an argument should be followed by a colon (:)**.

`long_options`: This is optional parameter and if specified, must be a list of strings with the names of the long options, which should be supported. Long options, which require an argument should be followed by an equal sign ('='). To accept only long options, options should be an empty string.

This method returns value consisting of two elements: the first is a list of (option, value) pairs. The second is the list of program arguments left after the option list was stripped.

Each option-and-value pair returned has the option as its first element, prefixed with a hyphen for short options (e.g., '-x') or two hyphens for long options (e.g., '--long-option').

Exception `getopt.GetoptError`
This is raised when an unrecognized option is found in the argument list or when an option requiring an argument is given none.

The argument to the exception is a string indicating the cause of the error. The attributes msg and opt give the error message and related option

Example
Consider we want to pass two file names through command line and we also want to give an option to check the usage of the script. Usage of the script is as follows −

usage: `test.py -i <inputfile> -o <outputfile>`
Here is the following script to test.py −

```python
#!/usr/bin/python

import sys, getopt

def main(argv):
   inputfile = ''
   outputfile = ''
   try:
      opts, args = getopt.getopt(argv,"hi:o:",["ifile=","ofile="])
   except getopt.GetoptError:
      print 'test.py -i <inputfile> -o <outputfile>'
      sys.exit(2)
   for opt, arg in opts:
      if opt == '-h':
         print 'test.py -i <inputfile> -o <outputfile>'
         sys.exit()
      elif opt in ("-i", "--ifile"):
         inputfile = arg
      elif opt in ("-o", "--ofile"):
         outputfile = arg
   print 'Input file is "', inputfile
   print 'Output file is "', outputfile

if __name__ == "__main__":
   main(sys.argv[1:])
```

Now, run above script as follows −

```
$ test.py -h
usage: test.py -i <inputfile> -o <outputfile>
```

```
$ test.py -i BMP -o
usage: test.py -i <inputfile> -o <outputfile>
```

```
$ test.py -i inputfile
Input file is " inputfile
Output file is "
```

##Interface

```
#include <string.h>
int is_palindrome(char *text) {
  int i, n=strlen(text);for (i=0; i<=n/2; ++i) {
    if (text[i] != text[n-i-1]) return 0;
  }
  return 1;
}

```

```
%module palindrome
%{
#include <string.h>
%}

extern int is_palindrome(char *text);
```
`$ swig -python palindrome.i`

After this, you should have two new files—one called palindrome_wrap.c and one called
palindrome.py

Compiling, linking and using:
```bash
gcc -c palindrome.c
gcc -I$PYTHON_HOME -I$PYTHON_HOME/Include -c palindrome_wrap.c
gcc -shared palindrome.o palindrome_wrap.o -o _palindrome.so
```

After these darkly magical incantations, you should end up with a highly useful file called
\_palindrome.so. This is your shared library, which can be imported directly into Python.

```python
>>> import _palindrome
>>> dir(_palindrome)
['__doc__', '__file__', '__name__', 'is_palindrome']
>>> _palindrome.is_palindrome('ipreferpi')
1
>>> _palindrome.is_palindrome('notlob')
0
```

##Exception

```python
(x,y) = (5,0)
try:
  z = x/y
except ZeroDivisionError, e:
  z = e # representation: "<exceptions.ZeroDivisionError instance at 0x817426c>"
print z # output: "integer division or modulo by zero"
```

*exception* TimeoutError

Raised when a system function timed out at the system level. Corresponds to errno ETIMEDOUT.

##Test

###doctest:

```python
def square(x):
     '''
     Squares a number and returns the result.
     >>> square(2)
     4
     >>> square(3)
     9
     '''
     return x*x

if __name__=='__main__':
import doctest, my_math
doctest.testmod(my_math) #testmodule
```

```python
$ python my_math.py
$
```
Nothing seems to have happened

```python
$ python my_math.py -v
Running my_math.__doc__
0 of 0 examples failed in my_math.__doc__
Running my_math.square.__doc__
Trying: square(2)
Expecting: 4
ok
Trying: square(3)
Expecting: 9
ok
0 of 2 examples failed in my_math.square.__doc__
1 items had no tests:
test
1 items passed all tests:
2 tests in my_math.square
2 tests in 2 items.
2 passed and 0 failed.
Test passed.
```

###unittest
Based on the popular test framework JUnit, for Java
http://python.org/doc/lib/module-unittest.html

```python
import unittest, my_math

class ProductTestCase(unittest.TestCase):
     def testIntegers(self):
         for x in xrange(-10, 10):
             for y in xrange(-10, 10):
                 p = my_math.product(x, y)
                 self.failUnless(p == x*y, 'Integer multiplication failed')

     def testFloats(self):
         for x in xrange(-10, 10):
             for y in xrange(-10, 10):
                 x = x/10.0
                 y = y/10.0
                 p = my_math.product(x, y)
                 self.failUnless(p == x*y, 'Float multiplication failed')

if __name__ == '__main__': unittest.main()
```
##Profiling
Premature optimization is the root of all evil.
--Professor Sir Charles Anthony Richard Hoare, inventor of QuickSort

```python
>>> import profile
>>> from my_math import product
>>> profile.run('product(1, 2)')
```

```python
>>> import pstats
>>> p = pstats.Stats('my_math.profile')
```
### Packaging Program
```python
from distutils.core import setup
setup(name='Hello',
version='1.0',
description='A simple example',
author='Magnus Lie Hetland',
py_modules=['hello'])
```
`$ python setup.py`

usage:
or:
or:
or:
setup.py
setup.py
setup.py
setup.py
[global_opts] cmd1 [cmd1_opts] [cmd2 [cmd2_opts] ...]
--help [cmd1 cmd2 ...]
--help-commands
cmd --help
error: no commands supplied

python setup.py build

running build
running build_py
creating build
creating build/lib
copying hello.py -> build/lib

python setup.py install

running install
running build
running build_py
running install_lib
copying build/lib/hello.py -> /path/to/python/lib/python2.4/site-packages
byte-compiling /path/to/python/lib/python2.4/site-packages/hello.py to hello.pyc

To build an archive file

`python setup.py sdist`

writing manifest file 'MANIFEST'
creating Hello-1.0
making hard links in Hello-1.0...
hard linking hello.py -> Hello-1.0
hard linking setup.py -> Hello-1.0
tar -cf dist/Hello-1.0.tar Hello-1.0
gzip -f9 dist/Hello-1.0.tar
removing 'Hello-1.0' (and everything under it)

python setup.py bdist --formats=wininst

dist/Hello-1.0.win32.exe

###Compiling Extensions

```python
from distutils.core import setup, Extension
setup(name='palindrome',
version='1.0',
ext_modules = [
Extension('palindrome', ['palindrome2.c'])
])
```

`$ python setup.py build_ext --inplace`

## Random Number Generation
```python
import random, sys, getopt

def _print_gauss():
  g = random.Random(1234)
  print [g.gauss(mu = 0, sigma=1) for i in range(100)]

def _usage():
  print "usage: %s" % sys.argv[0]
  print "Try 'python %s -h' for more information." % sys.argv[0]

  def _help():
    print "usage: %s" %sys.argv[0]
    print "-h (--help)"
    print "-v (--version)"

  if _name_ == '_main_':
    try:
      opts, args, = getop.getopt(sys.argv[1:], "vh", ["version", "help", ])
    except getopt.GetoptError:
      _usage()
      sys.exit(2)
for o, a in opts:
  if o in ("-h", "--help") :
    _help()
    sys.exit()
  if o in ("-v", "--version"):
    print "`%s`, Version 0.0.0" % sys.argv[0]
    sys.exit()
_print_gauss()
_print_lognormal_variate()
```
