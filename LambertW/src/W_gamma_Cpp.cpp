// [[Rcpp::interfaces(r, cpp)]]

#include <Rcpp.h>
using namespace Rcpp;

NumericVector W_Cpp(const NumericVector& z, int branch);

// [[Rcpp::export]]
NumericVector W_gamma_Cpp(const NumericVector& z, double gamma, int branch) {
  if (gamma == 0.0) {
    return z;
  } else {
    return W_Cpp(gamma * z, branch) / gamma;
  }
}