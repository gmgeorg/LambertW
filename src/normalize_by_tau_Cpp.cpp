#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector normalize_by_tau_Cpp (const NumericVector& x, double mu_x, double sigma_x, bool inverse) {
  int nn = x.length();
  NumericVector nx(nn);
  if (Rcpp::NumericVector::is_na(mu_x) || Rcpp::NumericVector::is_na(sigma_x)) {
    stop("'mu_x' and 'sigma_x' must not be NA.  Check names of the input again.");
  }

  if (inverse) {
    nx = x * sigma_x + mu_x;
  } else {
    nx = (x - mu_x) / sigma_x;
  }
  return nx;
}