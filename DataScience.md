
### Getting help

`?rnorm`

`help.search("rnorm")`

Get arguments

`args("rnorm")`

### R basics

`readLines` can be useful for reading in lines of webpages

```r
> con <- url("http://www.jhsph.edu", "r")
> x <- readLines(con)
> head(x)
[1] "<!DOCTYPE HTML PUBLIC..."
[2] ""
[3] "<html>"
[4] "<head>"
```

## Getting and Cleaning Data

Connecting and listing databases:

```r
ucscDb <- dbConnect(MySQL(), user="genome", host="genome-mysql.cse.ucsc.edu")
result <- dbGetQuery(ucscDb, "show database")
dbDisconnect(ucscDb)
result
```
Merging data - merge()

```r
mergeData2 <- merge(reviews, solutions, by.x="solution_id", by.y="id", all=TRUE)
head(mergedData2[, 1:6], 3)
reviews[1, 1:6]
```
###Loading flat files - read.table()
Important parameters file, header, sep, row.names, nrows
related read.csv() read.csv2()

```r
if (!file.exists("data")){
  dir.creat("data")
}

fileUrl <- "https://data.baltimorecity.gov/api/views/dz54-2aru/row.csv?accessType=DOWNLOAD"
download.file(fileUrl, destfile="cameras.csv", method="curl")
dateDownloaded <- date()
```

```r
cameraData <- read.table("./data/cameras.csv")
## Error: line 1 did not have 13 elements

head(cameraData)
## Error: object 'cameraData' not found
```

```r
cameraData <- read.table("./data/cameras.csv", sep=",", header=TRUE)
head(cameraData)

cameraData <- read.csv("./data/cameras.csv")
head(cameraData)
```
Some more important parameters
`quote` whether there are any quoted values `quote=""` means no quotes
`na.strings` set the character that represents a missing value
`nrows` how many lines to read
`skip` how many lines to skip

### Excel files

```r
if (!file.exists("data")){
  dir.creat("data")
}

fileUrl <- "https://data.baltimorecity.gov/api/views/dz54-2aru/row.xlsx?accessType=DOWNLOAD"
download.file(fileUrl, destfile="cameras.xlsx", method="curl")
dateDownloaded <- date()
```
`read.xlsx()`, `read.xlsx2()` xlsx package

```r
library(xlsx)
cameraData <- read.xlsx("./data/cameras.xlsx", sheetIndex=1, header=TRUE)
head(cameraData)
```

Reading specific rows and columns

```r
colIndex <- 2:3
rowIndex <- 1:4
cameraDataSubset <- read.xlsx(./data/cameras.xlsx", sheetIndex=1,colIndex=colIndex, rowIndex=rowIndex)
cameraDataSubset
```
-`write.xlsx` write out an Excel
-`read.xlsx2` much faster, but may be slightly unstable
- `XLConnect` package has more options for writing and manipulating Excel files

### Reading XML

- Extensible markup language
- frequently used to store structured data
- Particularly widely used in internet applications
- Extracting xml is the base for most web scraping
- components:
  markup - labels that give the text structure
  content - the actual text of the document

Tags, elements and attributes

start tags `<section>`
end tags `</section>`
empty tags `<line-brak />`

Elements are specific examples of tags
`<Greeting> Hello, world </Greeting>`

Attributes are components of the labels
```xml
<img src="jeff.jpg" alt="instructor"/>
<step number="3"> Connect A to B. </step>
```

```r
library(XML)
fileUrl <- "http://www.w3schools.com/cml/simple.xml"
doc <- xmlTreeParse(fileUrl, useInternal=TRUE)
rootNode <- xmlRoot(doc)
xmlName(rootNode)
```

`[1] "breakfast_menu"`

names(rootNode)

food    food    food    food    food
"food"  "food"  "food"  "food"  "food"

rootNode[[1]]

```xml
<food>
  <name> Belgian Waffles </name>
  <price> $5.95 </price>
  <description> Tow of our famous Belgian Waffles with plenty of real maple syrup</description>
  <calories> 650 </calories>
</food>
```
`rootNode[[1]][[1]]`
`<name> Belgian Waffles </name>`

`xmlSApply(rootNode, xmlValue)`


XPath

- `/node` Top level node
- `//node` node at any level
- `node[@attr-name]` Node with an attribute name
- `node[@attr-name='bob']` node with attribute name attr-name='bob'

Get the items on the menu and prices

`xpathSApply(rootNode,"//name",xmlValue)`

`xpathSapply(rootNode,"//price",xmlValue)`


### Reading JSON

JSON
- Javascript Object Notation
- Lightweight data storage
- Common format for data from application programming interfacess(APIs)
- Similar structure to XML but different syntax/format
- Data stored as
- Numbers(double)
- Strings(double quoted)
- Boolean(true or false)
- Array(ordered, comma separated enclosed in square brackets [])
- Object(unordered, comma separated collection of key:value pairs in curley brackets{})

```r
library(jsonlite)
jsonData <- fromJSON("https://api.github.com/users/jtleek/repos")
names(jsonData)
```

Writing data frames to JSON:

```r
myjson <- toJSON(iris, pretty=TRUE)
cat(myjson)
```

```json
[
  {
      "Sepal.Length":5.1,
      "Sepal.Width":3.5,
      "Petal.Length":1.4,
      "Petal.Width":0.2,
      "Species":"setosa"
  },
  {
      "Sepal.Length":4.9,
      "Sepal.Width":3.0,
      "Petal.Length":1.4,
      "Petal.Width":0.2,
      "Species":"setosa"
  }
]
```

Convert back to JSON

```r
iris2 <- fromJSON(myjson)
head(iris2)
```

```
  Sepal.Length  Sepal.Width Petal.Length  Petal.Width Species
1
2
....
```

### Using data.table

data.table
- Inherets from data.frame
-- All functions that accept data.frame work on data.table
- Written in C so it is much faster
- Much, much faster at sub setting, group, and updating

```r
library(data.table)
DF <- data.frame(x=rnorm(9), y=rep(c("a", "b", "c"), each=3), z=rnorm(9))
head(DF,3)

      x     y      z
1   0.4159  a   -0.05855
2   0.8433  a   0.13732
3   1.0585  a   2.16448
```


```r
DT <- data.table(x=rnorm(9), y=rep(c("a", "b", "c"), each=3), z=rnorm(9))
head(DT, 3)


      x     y      z
1   -0.2772  a   0.2530
2   1.0016   a   1.5093
3   -0.0338  a   0.4844
```
See all the data tables in memory

```r
tables()

    NAME  NROW MB COLS  KEY
[1,]  DT    9  1  x,y,z
Total: 1MB
```

Subsetting rows

```
DT[c(2, 3)]

      x     y      z
1   1.0016   a   1.5093
2   -0.0338  a   0.4844
```

### Reading mySQL

mySQL
- Free and widely used open source database software
- Widely used in internet based applications
- Data are structured in
-- databases
Tables within databases
Fields within tables
Each row is called a record

`install.packages("RMySQL")`

Connecting and listing databases

```r
ucscDb <- dbConnect(MySQL(), user="genome", host="genome-mysql.cse.ucsc.edu")
result <- dbGetQuery(ucscDb, "show databases;"); dbDisconnect(ucscDb);

[1] TRUE

result

      Database
1 information_schema
2       ailMel1
3       ailMis1
```

Connecting to hg19 and listing tables

```r
ucscDb <- dbConnect(MySQL(), user="genome", db="hg19", host="genome-mysql.cse.ucsc.edu")
allTables <- dbListTables(hg19)
length(allTables)

[1] 10949

allTables[1:5]

[1] "HInv"  "HInvGeneMrna"  "acembly" "acemblyClass"  "acemblyPep"
```

Get dimensions of a specific table
```r
dbListFields(hg19, "affyU133Plus2")


dbGetQuery(hg19, "select count(*) from affyU133Plus2")
  count(*)
1 58463
```

Read from the table

```r
affyData <- dbReadTable(hg19, "affyU133Plus2")
head(affyData)

```

Select a specific subset

```r
query <- dbSendQuery(hg19, "select * from affyU133Plus2 where misMatches between 1 and 3")
affyMis <- fetch(query); quantile(affyMis$misMatches)

0%  25% 50% 75% 100%
1     1   2   2   3

affyMisSmall <- fetch(query, n=10); dbClearResult(query)

[1] TRUE
```

Don't forget to close the connection

```r
dbDisconnect(hg19)

[1] TRUE
```
### Reading HDF5

HDF5
- Used for storing large data setosa
- Supports storing a range of data types
- Heirachical data format
- groups containing zero or more data sets and metadata
    Have a group header with group name and list of attributes
    Have a group symbol table with a list of objects in group
-   datasets multidimentional array of data elements with metatdata
    Have a header with name, datatype, dataspace, and storage layout
    Have a data array with the data

R HDF5 package

```r
source("http://biconductor.org/biocLite.R")
biocLite("rhdf5")

library(rhdf5)
created <- h5createFile("example.h5")
created

[1] TRUE
```

Packages from Biconductor http://bioconductor.org/. primarily used for genomics
but also has good "big data" packages

Can be used to interface with hdf5 dta sets

Create groups

```r
created <- h5createGroup("example.h5", "foo")
created <- h5createGroup("example.h5", "baa")
created <- h5createGroup("example.h5", "foo/foobaa")
h5ls("example.h5")
```



### Reading data from the web

### Reading data from APIs

### Subsetting and sorting

###


## Exploratory Analysis
Principles of Analytic Graphics

Principle 1: show comparisons
evidence for a hypothesis is always relative to another competing hypothesis
Always ask compared to what


Principle 2 : show causulity , mechanism, explanation, systematic structure

what is your causal framework for thinking about a question?

Principle 3: show multivariate data
- multivariate = more than 2 variables
- the real world is multivariate
- Need to "escape flatland"


Principle 4: Integration of evidence
- Completely integrate words, numbers, images, diagrams
- Data graphics should make use of many modes of data presentation
- Don't let the tool drive the analysis

Principle 5: Describe and document the evidence with appropriate labels, scales, sources, etc.

- A data graphic should tell a complete story that is credible

Principle 6: Content is king
- analytical presentations ultimately stand or fall depending on the quality,
relevance, and integrity of their content


Exploratory Graphics
```r

library(datasets)
hist(airquality$Ozone)
## Draw a new plot
```

```r
library(datasets)
with(airquality, plot(Wind, Ozone))
```

```r
library(datasets)
airquality <- transform(airquality, Month = factor(Month))
boxplot(Ozone ~ Month, airquality, xlab = "Month", ylab = "Ozone (ppb)")
```
Some Important Base Graphics Parameters
Many base plotting functions share a set of parameters. Here are a few key ones:
· pch : the plotting symbol (default is open circle)
· lty : the line type (default is solid line), can be dashed, dotted, etc.
· lwd : the line width, specified as an integer multiple
· col : the plotting color, specified as a number, string, or hex code; the colors() function gives
you a vector of colors by name
· xlab : character string for the x-axis label
· ylab : character string for the y-axis label

The par() function is used to specify global graphics parameters that affect all plots in an R
session. These parameters can be overridden when specified as arguments to specific plotting
functions.
· las : the orientation of the axis labels on the plot
· bg : the background color
· mar : the margin size
· oma : the outer margin size (default is 0 for all sides)
· mfrow : number of plots per row, column (plots are filled row-wise)
· mfcol : number of plots per row, column (plots are filled column-wise)

Default values for global graphics parameters
```r
par("lty")
## [1] "solid"
par("col")
## [1] "black"
par("pch")
## [1] 1
par("bg")
## [1] "transparent"
par("mar")
## [1] 5.1 4.1 4.1 2.1
par("mfrow")
## [1] 1 1
```
Base Plotting Functions
· plot : make a scatterplot, or other type of plot depending on the class of the object being plotted
· lines : add lines to a plot, given a vector x values and a corresponding vector of y values (or a 2-
column matrix); this function just connects the dots
· points : add points to a plot
· text : add text labels to a plot using specified x, y coordinates
· title : add annotations to x, y axis labels, title, subtitle, outer margin
· mtext : add arbitrary text to the margins (inner or outer) of the plot
· axis : adding axis ticks/labels
Base Plot with Annotation
```r
library(datasets)
with(airquality, plot(Wind, Ozone))
title(main = "Ozone and Wind in New York City")
## Add a title
```
```r
with(airquality, plot(Wind, Ozone, main = "Ozone and Wind in New York City"))
with(subset(airquality, Month == 5), points(Wind, Ozone, col = "blue"))
```

```r
with(airquality, plot(Wind, Ozone, main = "Ozone and Wind in
type = "n"))
with(subset(airquality, Month == 5), points(Wind, Ozone, col
with(subset(airquality, Month != 5), points(Wind, Ozone, col
legend("topright", pch = 1, col = c("blue", "red"), legend =
New York City",
= "blue"))
= "red"))
c("May", "Other Months"))
```

Base Plot with Regression Line
```r
with(airquality, plot(Wind, Ozone, main = "Ozone and Wind in New York City",
pch = 20))
model <- lm(Ozone ~ Wind, airquality)
abline(model, lwd = 2)
```

Multiple Base Plots
```r
par(mfrow = c(1, 2))
with(airquality, {
plot(Wind, Ozone, main = "Ozone and Wind")
plot(Solar.R, Ozone, main = "Ozone and Solar Radiation")
})
```

```r
par(mfrow = c(1, 3), mar = c(4, 4, 2, 1), oma = c(0, 0, 2, 0))
with(airquality, {
plot(Wind, Ozone, main = "Ozone and Wind")
plot(Solar.R, Ozone, main = "Ozone and Solar Radiation")
plot(Temp, Ozone, main = "Ozone and Temperature")
mtext("Ozone and Weather in New York City", outer = TRUE)
})
```


### Graphics Devices in R

#### What is a Graphics Device?

A graphics device is something where you can make a plot appear
- A window on your computer (screen device)
- A PDF file (file device)
- A PNG or JPEG file (file device)
- A scalable vector graphics (SVG) file (file device)
· When you make a plot in R, it has to be "sent" to a specific graphics device
· The most common place for a plot to be "sent" is the screen device
- On a Mac the screen device is launched with the quartz()
- On Windows the screen device is launched with windows()
- On Unix/Linux the screen device is launched with x11()
When making a plot, you need to consider how the plot will be used to determine what device the
plot should be sent to.
- The list of devices is found in ?Devices ; there are also devices created by users on CRAN
· For quick visualizations and exploratory analysis, usually you want to use the screen device
- Functions like plot in base, xyplot in lattice, or qplot in ggplot2 will default to sending a
plot to the screen device
- On a given platform (Mac, Windows, Unix/Linux) there is only one screen device
· For plots that may be printed out or be incorporated into a document (e.g. papers/reports, slide
presentations), usually a file device is more appropriate
- There are many different file devices to choose from
· NOTE: Not all graphics devices are available on all platforms (i.e. you cannot launch the
windows() on a Mac)



#### How Does a Plot Get Created?
There are two basic approaches to plotting. The first is most common:
1. Call a plotting function like plot , xyplot , or qplot
2. The plot appears on the screen device
3. Annotate plot if necessary
4. Enjoy

```r
library(datasets)
with(faithful, plot(eruptions, waiting))
title(main = "Old Faithful Geyser data")
## Make plot appear on screen device
## Annotate with a title
```

The second approach to plotting is most commonly used for file devices:
1. Explicitly launch a graphics device
2. Call a plotting function to make a plot (Note: if you are using a file device, no plot will appear on
the screen)
3. Annotate plot if necessary
4. Explicitly close graphics device with dev.off() (this is very important!)

```r
pdf(file = "myplot.pdf") ## Open PDF device; create 'myplot.pdf' in my working directory
## Create plot and send to a file (no plot appears on screen)
with(faithful, plot(eruptions, waiting))
title(main = "Old Faithful Geyser data") ## Annotate plot; still nothing on screen
dev.off() ## Close the PDF file device
## Now you can view the file 'myplot.pdf' on your computer
```


`boxplot(pollution$pm25, col="blue")`

`hist(pollution$pm25, col="green")`

```r
hist(pollution$pm25, col="green")
rug(pollution$pm25)
```

```r
hist(pollution$pm25, col="green", breaks=100)
rug(pollution$pm25)
```

```r
boxplot(pollution$pm25, col="blue")
albine(h=12)
```

Overlaying Features
```r
hist(pollution$pm25, col="green")
abline(v=12,lwd=2)
abline(v=median(pollution$pm25),col="magenta",lwd=4)
```

```r
barplot(table(pollution$ragion), col="wheat", main="Number of Counties in Each Region")
```

Multiple Boxplot
```r
boxplot(pm25 ~ region, data = pollution, col = "red")
```
Multiple Histograms

```r
par(mfrow = c(2, 1), mar = c(4, 4, 2, 1))
hist(subset(pollution, region == "east")$pm25, col = "green")
hist(subset(pollution, region == "west")$pm25, col = "green")
```

Scatterplot
```r
with(pollution, plot(latitude, pm25))
abline(h = 12, lwd = 2, lty = 2)
```

Scatterplot - Using Color
```r
with(pollution, plot(latitude, pm25, col = region))
abline(h = 12, lwd = 2, lty = 2)
```

Multiple Scatterplots
```r
par(mfrow = c(1, 2), mar = c(5, 4, 2, 1))
with(subset(pollution, region == "west"), plot(latitude, pm25, main = "West"))
with(subset(pollution, region == "east"), plot(latitude, pm25, main = "East"))
```

Plotting Systems in R

Base Plot
```r
library(datasets)
data(cars)
with(cars, plot(speed, dist))
```

The Lattice System

- Plots are created with a single function call ( xyplot , bwplot , etc.)
- Most useful for conditioning types of plots: Looking at how y changes with x across levels of z
- Things like margins/spacing set automatically because entire plot is specified at once
- Good for puttng many many plots on a screen
- Sometimes awkward to specify an entire plot in a single function call
- Annotation in plot is not especially intuitive
- Use of panel functions and subscripts difficult to wield and requires intense preparation
- Cannot "add" to the plot once it is created

```r
library(lattice)
state <- data.frame(state.x77, region = state.region)
xyplot(Life.Exp ~ Income | region, data = state, layout = c(4, 1))
```

The ggplot2 System
- Splits the difference between base and lattice in a number of ways
- Automatically deals with spacings, text, titles but also allows you to annotate by "adding" to a plot
- Superficial similarity to lattice but generally easier/more intuitive to use
- Default mode makes many choices for you (but you can still customize to your heart's desire)

```r
library(ggplot2)
data(mpg)
qplot(displ, hwy, data = mpg)
```

The Process of Making a Plot
When making a plot one must first make a few considerations (not necessarily in this order):
· Where will the plot be made? On the screen? In a file?
· How will the plot be used?
- Is the plot for viewing temporarily on the screen?
- Will it be presented in a web browser?
- Will it eventually end up in a paper that might be printed?
- Are you using it in a presentation?
· Is there a large amount of data going into the plot? Or is it just a few points?
· Do you need to be able to dynamically resize the graphic?
· What graphics system will you use: base, lattice, or ggplot2? These generally cannot be mixed.
· Base graphics are usually constructed piecemeal, with each aspect of the plot handled
separately through a series of function calls; this is often conceptually simpler and allows plotting
to mirror the thought process
· Lattice graphics are usually created in a single function call, so all of the graphics parameters
have to specified at once; specifying everything at once allows R to automatically calculate the
necessary spacings and font sizes.
· ggplot2 combines

Hierarchical clustering

K-Means clustering

Dimension reduction

Adding a genome
`qplot(displ, hwy, data=mpg, geom=c("point","smooth"))`


### Principles of Analytic Graphics
1. Show comparisons
2. Show causality, mechanism, explanation
3. Show multivariate data
4. Integrate multiple modes of evidence
5. Describe and document the evidence
6. Content is king

testing SGit

K-means clustering - example
```r
set.seed(1234)
par(mar=c(0,0,0,0))
x <- rnorm(12, mean=rep(1:3, each=4), sd=0.2)
y <- rnorm(12, mean=rep(c(1, 2, 1), each=4), sd=0.2)
plot(x, y, col="blue", pch=19, cex=2)
text(x+0.5, y+0.5, labels = as.character(1:12))
```
## Reproducible Research
- Structure of a Data Analysis
- Organizing a Data Analysis
- Markdown
- LaTex
- R Markdown
- Evidence based data Analysis
- RPubs

# Machine Learning/Prediction

## Who predicts
- Local government -> pension payments
- Google -> whether you will click on an AD
- Amazon -> what movies you will watch
- Insurance -> what your risk of death is
- Johns Hopkins -> who will succeed in their programs

## What is prediction

The central dogma of prediction:

`Probability/Sampling -> Training Set -> Prediction function`

### Components of a predictor

question -> input data -> features -> algorithm -> parameters -> evaluation

#### Question:

**Start with a general question**

Can I automatically detect emails that are SPAM that are not?

**Make it concrete**

Can I use quantitative characteristics of the emails to classify them as SPAM/HAM

#### Input Data:

```r
library(kernlab)
data(spam)
head(spam)
```

#### Features:

```
Dear Jeff,

Can you send me your address so I can send you the invitation?

Thanks,

Ben
```

Frequency of `you` = 2/17 = 0.118

#### Algorithm:
```
plot(density(spam$your[spam$type=="nonspam"]),
    col="blue", main="", xlab="Frequency of 'your'")
lines(density(spam$your[spam$type=="spam"]), col="red")
```

Our algorithm:
- find a value C
- **frequency of 'your' > C** predicts "spam"

#### Parameters

```
plot(density(spam$your[spam$type=="nonspam"]),
    col="blue", main="", xlab="Frequency of 'your'")
lines(density(spam$your[spam$type=="spam"]), col="red")
abline(v=0.5, col="black")
```

#### Evaluation

```
prediction <- ifelse(spam$your>0.5, "spam", "nonspam")
table(prediction, spam$type)/length(spam$type)

prediction    nonspam    spam
    nonspam     0.4590  0.1017
    spam        0.1469  0.2923
```

Accuracy ~= 0.459 + 0.292 = 0.751

True Positive + True Negative

## Relative importance of steps

question > data > features > algorithms

### INPUT DATA: Garbage in = Garbage out

- May be easy (movie ratings -> new movie ratings)
- May be harder (gene expression data -> disease)
- Depends on what is a "good prediction"
- Often **more data > better models**
- The most important!

### Features matter
**Property of good features**

- lead to data compression
- retain relevant information
- are created based on expert application knowledge

**Common mistakes**
- trying to automate feature selection
- not paying attention to data-specific quirks
- Throwing away information unnecessarily

Issue to consider
- Interpretable
- Simple
- Accurate
- Fast (to train and test)
- Scalable

Prediction is about accuracy tradeoffs
- Interpretability vs. Accuracy
- Speed vs. Accuracy
- Simplicity vs. Accuracy
- Scalability vs. Accuracy

## In sample and out of sample error
**In sample error:**

The error rate you get on the same data set you used to build your predictor.
Sometimes called resubstitution error.

**Out of sample error:**

The error rate you get on a new data set. generalization error

**Key ideas:**
- out of sample error is what you care about
- in sample error < out of sample error
- matching your algorithm to the data you have


Sampling:

```r
library(kernlab)
data(spam)
set.seed(333)
smallSpam <- spam[sample(dim(spam)[1], size=10), ]
spamLabel <- (smallSpam$type=="spam")*1+1
plot(smallSpam$capitalAve, col=spamLabel)
```

### Prediction rule 1

capitalAve > 2.7 => "spam"

capitalAve < 2.40 => "nonspam"

capitalAve [2.40 2.45] = "spam"

capitalAve [2.45 2.7] = "nonspam"

```r
rule1 <- function(x) {
    prediction <- rep(NA, length(x))
    prediction[x > 2.7] <- "spam"
    prediction[x < 2.40] <- "nonspam"
    prediction[(x >= 2.40 & x <= 2.45)] <- "spam"
    prediction[(x >= 2.45 & x <= 2.70)] <- "nonspam"
    return(prediction)
}
table(rule1(smallSpam$capitalAve), smallSpam$type)
```

```
        nonspam     spam
nonspam    5    0
spam       0    5
```

### Prediction rule 2

capitalAve > 2.4 => "spam"

capitalAve <= 2.4 => "nonspam"

```r
rule2 <- function(x) {
    prediction <- rep(NA, length(x))
    prediction[x > 2.8] <- "spam"
    prediction[x <= 2.8] <- "nonspam"
    return(prediction)
}
table(rule2(smallSpam$capitalAve), smallSpam$type)
```

```
        nonspam     spam
nonspam    5    1
spam       0    4
```

### Apply to complete spam data

`table(rule1(spam$capitalAve), spam$type)`

```
        nonspam     spam
nonspam    2141    588
spam       647    1225
```

`table(rule2(spam$capitalAve), spam$type)`

```
        nonspam     spam
nonspam    2224    642
spam       564    1171
```

`sum(rule1(spam$capitalAve)==spam$type)`

`[1] 3366`

`sum(rule2(spam$capitalAve)==spam$type)`

`[1] 3395`

Perfect in-sample predictor won't perform as well on new samples

prediction study design
1. define your error rate
2. Split data into: training, testing, validation
3. on the training set pick features: use cross-validation
4. on the training set pick prediction function: use cross-validation
5. If no validation, apply 1x to test set
6. if valid, apply to test set and refine, apply 1x to validation

`http://www.kaggle.com`

Avoid small sample sizes
- Suppose a binary outcome
- flipping a coin
- probability of perfect classification is approx. (1/2)^(sample size)
n=1 50% of 100% accuracy
n=2 25% of 100% accuracy
n=10 0.10% of 100% accuracy

Rules of thumb for prediction study design
- Large sample size
-- 60% training
-- 20% testing
-- 20% validation

- Medium sample size
-- 60% training
-- 40% testing

- Small sample size
-- do cross validation
-- report caveat of small sample size

Types of errors




## Statistical Inference
- Basic probability
- Likelihood
- Common distribution
- Asymptotics
- Confidence intervals
- Hypothesis tests
- Power
- Bootstrapping
- Non-parametric tests
- Basic Bayesian statistics

Example Bootstrapping
```r
B <- 1000
n <- length(gmVol)
resamples <- matrix(sample(gmVol, n*B, replace=TRUE), B, n)
medians <- apply(resamples, 1, median)
sd(medians)

[1] 3.148706

quantile(medians, c(0.25,0.975))
    2.5%      97.5%
  582.6384  595.3553
```

Regression Models

- Linear Regression
- Multiple Regression
- Confounding
- Residuals and diagnostics
- Prediction using linear Models
- Model misspecification
- Scatterplot smoothing/spines
- Machine learning via Regression
- Resampling inference in regression, bootstrapping, permutarion tests
- Weighted regression
- Mixed models(random intercepts)

Basic regression model

$Y = \beta_0+\beta_1X_i+/epsilon$

N(0, \delta^2)

Practical Machine learning

Positive = identified

negative = rejected

True Positive = correctly dentified

False positive = incorrectly identified

True negative = correctly rejected

False negative = incorrectly rejected


###Correlated predictors

```r
library(caret)
library(kernlab)

data(spam)
inTrain <- creatDataPartition(y=spam$type, p=0.75, list=False)
training <- spam[inTrain,]
testing <- spam[-inTrain,]

M <- abs(cor(training[,-58]))
diag(M) <- 0
which(M > 0.8, arr.ind = T)

```


### Data Products
- R packages : devtools, roxygen, testthat
- rCharts
marketing applications
- Slidify
- Shiny
web applications

## Shiny

creating interactive R programs embedded into a web page

```r
install.packages("shiny")
library(shiny)
```

- rstudio manipulate
- rCharts

A shiny project is a directory containing at least two parts:
- `ui.R` controls how it looks
- `server.R` controls what it does

`ui.R`:

```
library(shiny)
shinyUI(pageWithSidebar(
    headerPanel("Data science FTW"),
    sidebarPanel(
        h3('Sidebar text')
    ),
    mainPanel(
        h3('Main Panel text')
    )
))
```

`server.R`:
```
library(shiny)
shinyServer(
    function(input, output){
    ...
    }
)

`setwd()` to the directory and type `runApp()`

It should open an browser window with the app running


Data Science questions in Approximate Order of Difficulty
- Descriptive
- Exploratory
- Inferential
- Predictive
- Causal
- Mechanistic

Descriptive analysis
- Census data
- cannot be generalized without additional statistical modeling

Exploratory analysis
- find relationships
- good for discovering new connections
- useful for defining future studies
- usually not the final say
- EA alone should not be used for generalizing/predicting
- **Correlation does not imply causation**

Inferential analysis

*Use a relatively small sample of data to say something about a bigger population*
- commonly the goal of statistical models
- involves estimation both the quantity and uncertainty about the estimation
- depends heavily on both the population and the sampling scheme

*Example: Effect of Air Pollution Control on Life Expectancy in United States:
An Analysis of 545 U.S. Counties for the Period from 2000 to 2007*


Predictive analysis

*use the data on some objects to predict values for another object*

- If X predicts Y, it does not mean that X causes Y
- depends heavily on measuring the right variables
- more data and a simple model works well
- Prediction is very hard, especially for the future references

*Voting results, stock market*

Causal analysis

*find out what happens to one variable when you make another variable change*

- randomized studies
- usually identified as average effects but may not apply to every individual
- "gold standard" for data analysis

Mechanistic analysis
understand the exact changes invariables that lead to changes in other variables for individual objects
- Incredibly hard to infer, except in simple situations
- usually modeled by a deterministic set of equations
- Generally the random component of the data is measurement error
- If the equations are known but the parameters are not, they may be inferred with data analysis

Set of items: the set of objects you are interested in

sometimes called the population

Sharing data:

http://figshare.com/


## Managing workspace

| `getwd()` | List the current working directory. |

| `setwd("mydirectory")` | Change the current working directory to mydirectory. |

| `ls()` | List the objects in the current workspace. |

| `rm(objectlist)` | Remove (delete) one or more objects. |

| `help(options)` | Learn about available options. |

| `options()` | View or set current options. |

| `history(#)` | Display your last # commands (default = 25). |

| `savehistory("myfile")` | Save the commands history to myfile ( default =.Rhistory). |

| `loadhistory("myfile")` | Reload a command’s history (default = .Rhistory). |

| `save.image("myfile")` | Save the workspace to myfile (default = .RData). |

| `save(objectlist,file="myfile")` | Save specific objects to a file. |

| `load("myfile")` | Load a workspace into the current session (default = .RData). |

| `q()` | Quit R. You’ll be prompted to save the workspace. |

```r
setwd("C:/myprojects/project1")
options()
options(digits=3)
x <- runif(20)
summary(x)
hist(x)
savehistory()
save.image()
q()
```

The `source("filename")` function submits a script to the current session.

`source("myscript.R)`

The `sink("filename")` function redirects output to the file filename .

Append output to file

`append = TRUE`

Output to both screen and file

`split = TRUE`

pdf("filename.pdf") PDF file
win.metafile("filename.wmf") Windows metafile
png("filename.png") PBG file
jpeg("filename.jpg") JPEG file
bmp("filename.bmp") BMP file
postscript("filename.ps") PostScript file

```r
sink("myoutput", append=TRUE, split=TRUE)
pdf("mygraphs.pdf")
source("script2.R")
```
The R code from file `script2.R` will be submitted, and the results will again appear on
the screen. In addition, the text output will be appended to the file `myoutput` , and the
graphic output will be saved to the file `mygraphs.pdf` .

### Packages
install.packages()

```r
help.start()
install.packages("vcd")
help(package="vcd")
library(vcd)
help(Arthritis)
Arthritis
example(Arthritis)
q()
```

## Data Structures
Vector

Matrix

Array

Data frame

List: Vectors Arrays Data frames Lists

### Vectors
```r
a <- c(1, 2, 5, 3, 6, -2, 4)
b <- c("one", "two", "three")
c <- c(TRUE, TRUE, TRUE, FALSE, TRUE, FALSE)
```
scalars:

```r
f <- 3
g <- "US"
h <- TRUE
```

```r
a <- c(1, 2, 5, 3, 6, -2, 4)
a[3]
a[c(1, 3, 5)]
a[2:6]
```

`a <- c(2:6)` <=> `a <- c(2, 3, 4, 5, 6)`

### Matrices
Two dimensional array where each element has the same mode(numeric, character, or logic)

`mymatrix <- matrix(vector, nrow=number_of_rows, ncol=number_of_columns,
  by_row=logic_value, dimnames=list(char_+vector_rownames, char_vector_colnames))`

`y <- matrix(1:20, nrow=5, ncol=4)`

`x <- matrix(1:10, nrow=2)`



### Arrays

Arrays are similar to matrices but can have more than two dimensions

`myarray <- array(vector, dimensions, dimnames)`

```r
dim1 <- c("A1", "A2")
dim2 <- c("B1", "B2", "B3")
dim3 <- c("C1" ,"C2", "C3", "C4")
z <- arrya(1:24, c(2, 3, 4), dimnames=list(dim1, dim2, dim3))
```
### Data frames

`mydata <- data.frame(col1, col2, col3, ...)`

where `col1`, `col2`, `col3`, ... are column vectors of any type

```r
patientID <- c(1, 2, 3, 4)
age <- c(25, 34, 28, 52)
diabetes <- c("Type1", "Type2", "Type1", "Type1")
status <- c("Poor", "Improved", "Excellent", "Poor")

```

## Running R script in Batch mode
`R CMD BATCH options infile outfile`


##Linear Regression
Whenever using LR, you are making the assumption that there is a *linear*
relationship between an outcome variable(dependent variable) and a
predictor(independent variable).

Algorithm:a set of rules or steps to follow to accomplish come task

Model: an attempt to describe or capture the world

statistical models

machine learning algorithms
