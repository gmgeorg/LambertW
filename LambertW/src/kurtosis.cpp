#include <Rcpp.h>
using namespace Rcpp;

//' @rdname estimate-moments
//' @description
//' \code{kurtosis} estimates the fourth central, normalized moment from data.
//' @export
//' 
// [[Rcpp::export]]
double kurtosis(const NumericVector& x) {
  int nn = x.length();
  double avg_x = mean(x);
  double kurtosis_x = nn * sum(pow(x - avg_x, 4)) / pow(sum(pow(x - avg_x, 2.0)), 2.0);
  return kurtosis_x;
}