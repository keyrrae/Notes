## DataFrame
A DataFrame represents a tabular, spreadsheet-like data structure containing
an ordered collection of columns, each of which can be a different value type.


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
