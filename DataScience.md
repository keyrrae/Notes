
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
