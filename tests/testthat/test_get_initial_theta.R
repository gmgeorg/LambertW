context("Testing get_initial_theta and related functions \n")
set.seed(40)
nobs <- 1e3
yy <- rnorm(n = nobs, mean = 3, sd = 0.2)

test_that("delta_GMM correctly respects lower bound", {
  res_hh = delta_GMM(yy, type="hh", lower=0.1, upper=.3)
  expect_gte(res_hh$delta[1], 0.1)
  expect_gte(res_hh$delta[2], 0.1)
  
  res_h = delta_GMM(yy, type="h", lower=0.1, upper=.3)
  expect_gte(res_h$delta[1], 0.1)
})


yy_cauchy <- rcauchy(n=nobs)

test_that("delta_GMM correctly respects upper bound", {
  res_hh = delta_GMM(yy_cauchy, type="hh", lower=0.1, upper=.3)
  expect_lte(res_hh$delta[1], 0.3)
  expect_lte(res_hh$delta[2], 0.3)

  res_h = delta_GMM(yy_cauchy, type="h", lower=0.1, upper=.3)
  expect_gte(res_h$delta[1], 0.1)
})
