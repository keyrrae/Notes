
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


### Reading JSON

### Using data.table

### Reading MySQL

### Reading HDF5

### Reading data from the web

### Reading data from APIs

### Subsetting and sorting

###


## Exploratory Analysis
Principles of Analytic Graphics

Exploratory Graphics

Plotting Systems in R

base

lattice

ggplot2

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
