
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

``
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
