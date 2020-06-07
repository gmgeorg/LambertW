# LambertW R package

This is the github repo for the **LambertW** R package [hosted on
CRAN](https://CRAN.R-project.org/package=LambertW). 

Current version on CRAN is `0.6.4`. The version here is an update to `0.6.5` --
not yet pushed to CRAN as I ran into `Rcpp` issues related to the `useDynLib`
NAMESPACE issues ([issue here](https://github.com/gmgeorg/LambertW/issues/1))

Once this is resolved I will push this to CRAN again (pending unit tests passing
after Rcpp fixes).


## Installation & usage

To install **LambertW** run

```{r}
install.packages("LambertW")
citation("LambertW")
```

See `?LambertW` for examples on how to use the **LambertW** package.

There is also an R vignette on CRAN with a brief tutorial on the main functionalities.



## Tutorials & posts

See cross-validated / stackoverflow for [a variety of **LambertW** posts](https://stats.stackexchange.com/search?q=LambertW) on how to normalize/Gaussianize data and model skewed/heavy-tailed distributions.


## References

Georg M. Goerg (2011): [*Lambert W random variables - a new family of generalized skewed distributions with applications to risk estimation*](https://projecteuclid.org/euclid.aoas/1318514301). Annals of Applied Statistics 3(5). 2197-2230.

Georg M. Goerg (2014): [*The Lambert Way to Gaussianize heavy-tailed data with the inverse of Tukey's h transformation as a special case*](http://downloads.hindawi.com/journals/tswj/2015/909231.pdf). The Scientific World Journal.
