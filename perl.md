##Perl
```perl
$line = <STDIN>;
chomp($line);
```
`chomp($line = <STDIN>);`

```perl
while(defined($line = <STDIN>)) {
	print "I saw $line";
}
```

###Loop control
```perl
for($i=1;$i<10;$i++){
	print "I can count to $i!\n";
}
```
###Regular Expressions
```perl
$_="yabba dabba doo";
if(/abba/){
	print "I matched!\n";
}
```
