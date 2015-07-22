```shell
mkdir mongodb_simple
cd mongodb_simple/
mkdir data
mkdir Log
mkdir conf
mkdir bin
cp ../mongo-r2.6.5/mongod bin/
cd conf/
vim mongod.conf
```

mongod.conf:

```
port = 12345
dbpath = data
logpath = log/mongod.log
fork = TRUE
```
`./bin/mongod -f conf/mongod.conf`

Accessing mongo database
```
cp ../mongo-r2.6.5/mongo bin/
./bin/mongo [options]
```
