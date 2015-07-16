`subprocess.call(["some_command", "some_argument", "another_argument_or_path"])`

```python
#!/usr/bin/env python
#Python wrapper for the ls command

import subprocess
import os

subprocess.call(["ls","-l"])
os.system("ls -l")
```
Anycode underneath this statement gets run only it is executed from
the command line.
Reusing the codes

```python
if __name__ == "__main__":
    main()

```  

```python
>>> class DoubleRep(object):
...    def __str__(self):
...        return "Hi, I'm a __str__"
...    def __repr__(self):
...        return "Hi, I'm a __repr__"
...
>>>
>>> dr = DoubleRep()
>>> print dr
Hi, I'm a __str__
>>> dr
Hi, I'm a __repr__
```


```python
import rlcompleter, readline
>>> readline.parse_and_bind('tab: complete')

```
