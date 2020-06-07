#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
double lp_norm_Cpp(const NumericVector& x, double p) {
  if (p < 0) {
    stop("p must be non-negative.");
  }
  
  double norm_x = 0;
  
  if (p == 0.0) {
    // number of non-zero elements
    norm_x += sum(x != 0);
  } else if (p == R_PosInf) {
    // max_i(|x_i|)
    norm_x += max(abs(x));
  } else if (p == 1.0) {
    // use L1 norm directly
    norm_x += sum(abs(x));
  } else if (p == 2.0) {
    // for p = 2 use multiplication and square root directly for 
    // faster computations than pow() in C++
    norm_x += sqrt(sum(x * x));
  } else {
    // basic definition
    norm_x += pow(sum(pow(abs(x), p)), 1.0 / p);
  }
  return norm_x;
}


// [[Rcpp::export]]
double lp_norm_complex_Cpp(const ComplexVector& x, double p) {
  if (p < 0) {
    stop("p must be non-negative.");
  }
  double norm_x = 0;
  int nn = x.size();
  NumericVector abs_x(nn);
  for( int ii=0; ii<nn; ii++) {
    abs_x[ii] = sqrt(pow(x[ii].r, 2) + pow(x[ii].i, 2));
  }
  if (p == R_PosInf) {
    norm_x += max(abs_x);
  } else if (p == 0) {
    norm_x += sum(abs_x != 0);
  } else {
    norm_x += pow(sum(pow(abs_x, p)), 1.0 / p);
  }
  return norm_x;
}
