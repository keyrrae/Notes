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
