// [[Rcpp::interfaces(r, cpp)]]
// [[Rcpp::depends(lamW)]]

#include <Rcpp.h>
#include <lamW.h>
using namespace Rcpp;

// [[Rcpp::export]]
NumericVector W_Cpp(const NumericVector& z, int branch) {
  NumericVector Wz(z.length());
  if (branch == 0) {
    Wz = lamW::lambertW0_C(z);
  } else if (branch == -1) {
    Wz = lamW::lambertWm1_C(z);
  } else {
    stop("Only principal (0) and non-principal branch (-1) are implemented.");
  }
  return Wz;
}
