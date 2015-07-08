
Time Series

Data obtained from observations collected sequentially over time

```R
> library(TSA)
> win.graph(width=4.875, height=2.5, pointsize=8)
> data(larain);plot(larain, ylab="Inches", xlab="Year", type='o')
```

```R
> win.graph(width-3, height=3, pointsize=8)
> plot(y=larain,z=zlag(larain),ylab='Inches',xlab='Previous Year Inches')
>
```


## Examples of Time Series

### An Industrial Chemical Process


The sequence of random variables {Y_t : t = 0, ±1, ±2, ±3, ...} is called a
**stochastic process** and serves as a model for an observed time series.
