#include <Rcpp.h>
using namespace Rcpp;

//' @title Skewness and kurtosis
//' @rdname estimate-moments
//' @description
//' \code{skewness} estimates the third central, normalized moment from data.
//' 
//' @param x a numeric vector.
//' @seealso Corresponding functions in the \pkg{moments} package.
//' @export
// [[Rcpp::export]]
double skewness(const NumericVector& x) {
  double avg_x = mean(x);
  double skewness_x = mean(pow(x - avg_x, 3)) / pow(mean(pow(x - avg_x, 2.0)), 1.5);
  return skewness_x;
}
