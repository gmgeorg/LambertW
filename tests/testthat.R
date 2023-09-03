library(testthat)

set.seed(10231)

.on_cran <- function() !identical(Sys.getenv("NOT_CRAN"), "true")

if (!.on_cran()) {
  cat("Starting tests for 'LambertW' package ...")
  test_check("LambertW")
} else {
  cat("Skipping tests on CRAN.")
}