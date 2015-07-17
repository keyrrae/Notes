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



##Linear Regression
Whenever using LR, you are making the assumption that there is a *linear*
relationship between an outcome variable(dependent variable) and a
predictor(independent variable).

Algorithm:a set of rules or steps to follow to accomplish come task

Model: an attempt to describe or capture the world

statistical models

machine learning algorithms
