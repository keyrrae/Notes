## DataFrame
A DataFrame represents a tabular, spreadsheet-like data structure containing
an ordered collection of columns, each of which can be a different value type.

Import conventions

```python
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
```


##pandas

```python
In [1]: from pandas import Series, DataFrame
In [2]: import pandas as pd
```

###Series
One-dimensional array-like object
```python
In [4]: obj = Series([4, 7, -5, 3])

In [5]: obj
Out[5]:
0   4
1   7
2   -5
3   3

In [6]: obj.values
Out[6]: array([4, 7, -5, 3])

In [7]: obj.index
Out[7]: Int64Index([0, 1, 2, 3])

In [8]: obj2 = Series([4, 7, -5, 3], index=['d', 'b', 'a', 'c'])
In [9]: obj2
Out[9]:
d   4
b   7
a   -5
c   3

In [10]: obj2.index
Out[10]: Index([d, b, a, c], dtype=object)

```


### DataFrame

```python
data = {{'state': ['Ohio', 'Ohio', 'Ohio', 'Nevada', 'Nevada'],
        'year': [2000, 2001, 2002, 2001, 2002],
        'pop': [1.5, 1.7, 3.6, 2.4, 2.9]}
frame = DataFrame(data)


In [38]: frame
Out[38]:
  pop state year
0 1.5 Ohio 2000
1 1.7 Ohio 2001
2 3.6 Ohio 2002
3 2.4 Nevada 2001
4 2.9 Nevada 2002
```

Specifying a sequence of columns:
```python
In [39]: DataFrame(data, columns=['year', 'state', 'pop'])
Out[39]:
  year state pop
0 2000 Ohio 1.5
1 2001 Ohio 1.7
2 2002 Ohio 3.6
3 2001 Nevada 2.4
4 2002 Nevada 2.9
```

If you pass a column that isn't contained in `data`, it will appear with NA values in the result.

```python
In [40]: frame2 = DataFrame(data, columns=['year', 'state', 'pop', 'debt'])
...

In [41]: frame2
Out[41]:
      year state  pop debt
one   2000 Ohio   1.5  NaN
two   2001 Ohio   1.7  NaN
three 2002 Ohio   3.6  NaN
four  2001 Nevada 2.4  NaN
five  2002 Nevada 2.9  NaN

In [42]: frame2.columns
Out[42]: Index([year, state, pop, debt], dtype=object)
```

A column in a DataFrame can be retrieved as a Series either by dict-lick notation or by attribute
```python
In [43]: frame2['state']
Out[43]:
      state
one   Ohio
two   Ohio
three Ohio
four  Nevada
five  Nevada
Name: state

In [44]: frame2.year
Out[44]:
      state
one   2000
two   2001
three 2002
four  2001
five  2002
Name: year
```

Rows can also be retrieved by position or name by a couple of methods
```python
In [45]: frame2.ix['three']
Out[45]:
year  2002
state Ohio
pop   3.6
debt  NaN
Name: three
```

Columns can be modified by assignment.
```python
In [46]: frame2['debt'] = 16.5

In [47]: frame2
Out[47]:
      year  state   pop   debt
one   2000    Ohio  1.5   16.5
two   2001    Ohio  1.7   16.5
three 2002    Ohio  3.6   16.5
four  2001  Nevada  2.4   16.5
five  2002  Nevada  2.9   16.5

In [48]: frame2['debt'] = np.arange(5.)

In [49]: frame2
Out[49]:
      year  state   pop   debt
one   2000  Ohio    1.5   0
two   2001  Ohio    1.7   1
three 2002  Ohio    3.6   2
four  2001 Nevada   2.4   3
five  2002 Nevada   2.9   4
```

Conform to DataFrame's index, inserting missing values in any holes:
```python
In [50]: val = Series([-1.2, -1.5, -1.7], index=['two', 'four', 'five'])
In [51]: frame2['debt'] = val
Out[52]:
      year   state  pop   debt
one
two
three
four
five
2000
2001
2002
2001
2002
Ohio
Ohio
Ohio
Nevada
Nevada
1.5
1.7
3.6
2.4
2.9
NaN
-1.2
NaN
-1.5
-1.7
```

### Index Objects
