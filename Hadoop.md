HDFS
Hadoop
Distributed
File
System

mydata.txt

default block size 64MB

150 MB file mydata.txt

each block is send to one datanodes

namenode metadata

Data redundancy
Hadoop replicates each block three times, pick up three nodes, and put one
copy of the block on each of the three

under-replicated(<3 replicates) => replicates

namenode:
two namenodes

active standby

`hadoop fs -ls`

home directory on hadoop cluster

`hadoop fs -put purchases.txt`
put a file with name of purchases.txt to hadoop cluster

`hadoop fs -tail purchases.txt`

`hadoop fs -mv purchases.txt newname.txt`

`hadoop fs -rm newname.txt`

`hadoop fs -mkdir myinput`

`hadoop fs -put purchases.txt myinput`


key => value

Mapper
small programs that works small amount of data do relatively small amount of work
mappers can do things in parallel

Intermediate records

Shuffle and sort
movement of Intermediate records from mapper to reducers

Reducer
works on

final results in sorted order


Job tracker daemon

handled by task tracker daemon

By default, hadoop use HDFS block as mappers' input

Hadoop streaming

local directory:

`mapper.py`
`reducer.py`

submit a job
`$ hadoop jar [path to hadoop-streaming-2.0.0-mrl-cdh4.1.1.jar] -mapper mapper.py -reducer reducer.py -file mapper.py -file reducer.py -input myinput -output joboutput`

```
joboutput/_SUCCESS
joboutput/_logs
joboutput/part-00000
```

`hadoop fs -cat joboutput/part-00000 | less`

Get a file from HDFS:
`hadoop fs -get joboutput/part-00000 mylocalfile.txt`

The output directory must not already exist
Preventing deleting outputs accidentally

Log processing
Recommendation System

INPUT DATA
2012-01 12:01 San Jose  Music 12.99 Ames

```python
def mapper():
  for line in sys.stdin:
    data = line.strip().split("\t")
    date, time, store, item, cost, payment = data

    print "{0}\t{1}".format(store, cost)

```

what if a strange line?
`2012-01-02 There was an error trying to connect to the data. Please try agian.`

Defensive programming

```python
def mapper():
  for line in sys.stdin:
    data = line.strip().split("\t")

    if len(data)==6:
      date, time, store, item, cost, payment = data
      print "{0}\t{1}".format(store, cost)
```

Shuffle and sort

The store names are sorted


Reducer

```python
def reducer():
  salesTotal = 0
  olkKey = None

  for line in sys.stdin:
    data = line.strip().split("\t")

    if len(data) != 2:
      continue

    thisKey, thisSale = data

    if oldKey and thisKey != oldKey:
      print "{0}\t{1}".format(oldKey, salesTotal)

      salesTotal = 0

    oldKey = thisKey # just like an FSM, lol
    salesTotal += float(thisSale)
```
