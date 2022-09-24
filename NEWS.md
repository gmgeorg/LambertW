# LambertW Release Notes

* only complete starting with version 0.2.9.7

## Future TODOs

* **knitr** more vignettes will be added in upcoming releases.
* always: add more distributions by default
* convert Lambert W toolkit to reference classes, rather than S3 classes

## 0.6.7-1

* minor fix on HTML formatting to be compliant with CRAN.

## 0.6.7

* renamed `ks.test.t` to `ks_test_t` to avoid CRAN complaining about misuse of `S3method`

## 0.6.6

* fixed link issues with new way of parsing URLs in `Rd` files for R
* updated vignette (added `markdown` to `Suggests`)

## v0.6.5

* moved code to
  [https://github.com/gmgeorg/LambertW](https://github.com/gmgeorg/LambertW)
* fixed CRAN check `WARNINGS` (thanks to Kurt Hornik for help on resolving Rcpp
  build errors)
* fixed zero-division bug in `get_initial_tau()` (happened when `mad(y) = 0` --
  which can happen for data with majority of values fall on the same exact
  value)
* added a introduction vignette

## v0.6.4

### Minor changes

* updated test files to upcoming version of **testthat** package
* added a couple of unit tests
* removed unused variable in `skewness.cpp`

## v0.6.2

### New

* rewrote a couple of functions in C++ using the amazing (!) **Rcpp** package.
  3-4x speed up for `W` related functions; also for `IGMM` and `MLE_LambertW`

* added bootstrap functions for users to easily check if a Lambert W x F
  distribution with finite mean and variance input makes sense:
  * `bootstrap.LambertW_fit`
  * `analyze_convergence`

* added `use.mean.variance` argument to distinguish between mean-variance
  Lambert W x F distributions and general location-scale Lambert W x F
  distributions. See also Goerg (2015b).  See the help file on these functions
  for references on why they were included.

* added more unit tests (moving code from "Examples" to unit tests)

### Minor changes

* revised the manual to reflect changes in recent R package dependencies 
* `theta` argument in the `dpqr` function becomes the recommended argument to
  specify the distribution.  `alpha`, `beta`, `gamma`, `delta` now give warnings
  and will be deprecated in future versions.
* added third order approximation in `gamma_Taylor` for better initial
  estimates.
* added dependency on **Rcpp**
* removed dependency of **moments** package, and made **Rcpp** versions of
  `skewness()` and `kurtosis()` instead directly in **LambertW**.

## v0.6.0

### New

* moved from **gsl** to **lamW** R package: the Lambert W implementation is ~4x
  faster than for **gsl**. Needless to say that this will also speed up many
  computations in the **LambertW** package. Thank you [Avraham
  Adler](https://www.avrahamadler.com/2015/05/26/lamw-package-cran/) for the
  **lamW** package.

* new functions:
  * `deriv_xexp()`
  * `normalize_by_tau()`
  * `log_deriv_W()`

* lots of performance improvements (not only due to **lamW** package). Leads to
  2-3x faster estimation via IGMM or MLE overall.

* added (first iteration) of unit tests using the **testthat** package

### Minor changes

* added recommended packages to `NAMESPACE` following new CRAN policies
* set `from = 0` in `plot.LambertW_fit` for scale families with all positive
  values.
* `get_distname_family` returns a third logical entry `non.negative` to check
  whether a distribution is for non-negative random variables (e.g., exponential
  or Gamma).
* `loglik_penalty` loses the "distname" argument, but gains the
  "is.non.negative" argument.
* replaced all `any(is.na(...))` with `anyNA(...)` (small speedups)
* made `deriv_W` faster and more precise using a log transform first and using
  mathematial identities of the derivative of W, its derivative, and logarithm.
* made "optimize" the default optimizer in `delta_GMM` and `gamma_GMM` (it's
  about 30% faster than "nlm")

### Bug fixes

* `delta_GMM`: for `delta` too large (`>1e100`) the backtransformed data `u`
  would become negligibly small and numerically a constant (`1e-100`); thus
  `kurtosis()` estimate would be `NaN`, which resulted in stop of `nlm` function
  in `delta_GMM`. Added an `NA` check and returned large value for objective
  function, for `nlm()` to search for a better `delta`. backtransformed
* `get_initial_theta`: if initial estimates of `gamma` are too extreme, then the
  backtransformed input data for X contains `NA`. This caused an error in
  `estimate_beta()`.  Now `NA`s are removed before passing `x.init` to
  `estimate_beta()` 
* `log_W(Inf)` returned `NA`; fixed to return `Inf`.
* `qLambertW()` didn't compute correct quantiles for non-negative distributions
  (e.g., `"exp"` or `"gamma"`) and `type = "s"`; replaced now with closed form
  expressions.

### Deprecated

See also `?deprecated-function`:

* `H()`: use `xexp()` instead

## v0.5.1

### New

### Bug fixes

- `data` input to `Gaussianize()` does not have to have `colnames`; will be
  assigned by default if `colnames(data) = NULL`
- fixed bug in `mLambertW` which ignored `delta` values passed via `theta`

### Deprecated

Several deprecated functions (see also `?deprecated-function`):

* `normfit()`: use `test_normality()` (or short `test_norm()`) instead

### Minor changes

- Updated citation with "The Scientific World Journal: Probability and
  Statistics with Applications in Finance and Economics. Available at
  [https://www.hindawi.com/journals/tswj/2015/909231/](https://www.hindawi.com/journals/tswj/2015/909231/)"
- added `grid` to `test_normality` (previously known as `normfit`)
- added a "^2" to the N(mu, sigma^2) of the legend; now its clear that the
  displayed value is the standard deviation, not the variance.

## v0.5

Version 0.5 is a long awaited - big - update to the **LambertW** package. That's
why it's a big bump from 0.2.9.9 to 0.5.

It has lots of improved code, bug fixes, more user friendly function (names) and
implementation, more explicit error checking and meaningful error messages, etc.

Definitely check out the new manual - it has been reviewed *very* thoroughly.

### New

* code and documentation is now in Roxygen style (thanks **Rd2roxygen** and
  **roxygen2**!)
* `W()` (and related functions) gained a `branch` argument (see also deprecated
  functions below).
* `Gaussianize()` gained several new arguments that allow to do the inverse
  ''DeGaussianization'' as well. See `?Gaussianize` for details.
* several new functions (I probably forgot some):
    * `check_beta()`
    * `check_distname()`
    * `check_tau()`
    * `deriv_W_gamma()`
    * `estimate_beta()`
    * `get_distname_family()`
    * `get_distnames()`
    * `get_gamma_bounds()`
    * `get_initial_tau()`
    * `get_output()` (due to popular demand)
    * `log_W()`
    * `tau2theta()`
* added - this very - `NEWS` file
* added `CITATION` file.  See citation information with `citation("LambertW")`
* added F distribution; called "f", not "F" (to avoid confusion with `FALSE`).
* Use list `theta` as argument in functions instead of `alpha`, `beta`, `gamma`,
  or `delta`. Passing the elements as single arguments still works, but using
  `theta = list(beta = ..., gamma = ..., delta = ..., alpha = ...)` is
  preferred. In future versions the `alpha`, `beta`, `gamma`, and `delta`
  arguments will be deprecated.

### Bug fixes, minor changes & minor improvements

* `normfit()`:
    * produces less ink plots
    * ACF plot does not show the non-informative lag 0 estimate (it's always
      $\hat{\rho}(0) = 1$); improves y-axis scale for higher-order lags.
    * if sample size $>5,000$ it will subsample it so Normality tests still
      work.
* more error checking and much more meaningful error messages.
* following more closely [Google's R style
  guide](https://google.github.io/styleguide/Rguide.html) (with some of [Hadley
  Wickham's tidyverse guide](https://style.tidyverse.org/) too)
     * use underscore `_` as separator in function names
     * changed assignments from `=` to `<-`
     * changed variable names with underscore `_` to `.` (unless it `_` helps
       understanding; e.g.,  
       `mu_y` reminds of `mu` with the `y` subscript in LaTeX / pdf)
     * start function names with verbs as much as possible (e.g.,
       `get_initial_theta()` instead of `starting_theta()`; `get_support()`
       instead of `support()`)
* Removed **nortest** package dependency; *suggest* only. Since `normfit` is
  often called for visual checks only, I made the normality tests optional. They
  are called if the **nortest** package is available (`require(nortest) ==
  TRUE`); otherwise it just returns `NA`.  This is useful in case users do not
  have the **nortest** package available in their R installation.
* fixed bug in `qU()` and `pU()`: incorrect usage of standard deviation vs scale
  in t distribution (`dU()` and thus log-likelihood was correct).
* `ks.test.t` now uses the scale parameter, rather than standard deviation.
  This now allows to test also if degrees of freedom < 2.
* `MLE_LambertW` changed the `estimate.only` argument to `return.estimate.only`.

### Deprecated

Several deprecated functions (see also `?deprecated-function`):

* `beta_names()`: use `get_beta_names()`
* `bounds_theta()`: use `get_theta_bounds()`
* `d1W()` and `d1W_1()`: use `deriv_W(..., branch)`.
* `d1W_delta()`, `d1W_delta_alpha()`: use `deriv_W_delta()` and `deriv_W_delta_alpha()`.
* `get.input()`: use `get_input()`
* `p_1()`: use `p_1m()` 
* `params2theta()`: use `unflatten_theta()`
* `skewness_test()`: use `test_symmetry()`
* `starting_theta()`: use `get_initial_theta()`
* `support()`: use `get_support()`
* `theta2params()`: use `flatten_theta()`
* `vec.norm()`: use `lp_norm()`
* `W_1()`: use `W(z, branch = -1)`; similarly for `W_gamma_1()`
* `W_2delta_alpha()`: use `W_2delta_2alpha()`.
* `W_gamma_1()`: use `W_gamma(..., branch = -1)`.

### Removed

* `G()` since it was never used. If you need it use `G_delta(z, delta = 0)`.
* `MLE_LambertW_new()` and (`MLE_LambertW_new.default()`); `MLE_LambertW` now
  works also for unbounded optimziation.
* `.default` methods for `IGMM` and `MLE_LambertW`. They just work one way on a
  numeric vector.
* dependency on **maxLik** package for numerical Hessian computation.  Use
  `optim(..., hessian = TRUE)` instead.
* **Rsolnp**, **numDeriv**, and **nortest** are only suggested packages; not
  required anymore.

## v0.2.9.9

* changed email to `im@gmge.org`

## v0.2.9.7

### New Features

* SolarFlares dataset

### Bug fixes & minor improvements

* `get.input()` had the wrong variable for `nu > 2` (`u` instead of `uu`)
* `loglik_penalty()` returned `NA` for `0/0` when computing inverse
  transformation. Replaced this term with equivalent expression avoiding `0/0`.

## v0.2.9.5
- bug fixes to version 0.2.9

## v0.2.9
- bug fixes to version 0.2.6

## v0.2.6
- bug fixes to version 0.2.5

## v0.2.5
- new toolkit version of Lambert W x F distributions
- bug fixes to previous versions

## v0.1.0

* first version submitted March 23, 2009 by Georg M. Goerg (`im@gmge.org`)
