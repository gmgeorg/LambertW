// [[Rcpp::interfaces(r, cpp)]]

#include <Rcpp.h>
using namespace Rcpp;

NumericVector W_Cpp(const NumericVector& z, int branch);

// [[Rcpp::export]]
NumericVector W_delta_Cpp(const NumericVector& z, double delta) {
  int nn = z.length();
  NumericVector Wdeltaz(nn);
  
  if (delta == 0.0) {
    Wdeltaz = z;
  } else {
    Wdeltaz = Rcpp::sqrt(W_Cpp(delta * z * z, 0) / delta);
    IntegerVector signz = Rcpp::sign(z);
    for (int ii = 0; ii < nn; ii++) {
      if (signz[ii] == -1) {
        Wdeltaz[ii] *= -1;
      }
    }
  }
  return Wdeltaz;
}


// [[Rcpp::export]]
NumericVector W_delta_alpha_Cpp(const NumericVector& z, double delta, double alpha) {
  int nn = z.length();
  NumericVector Wdaz(nn);

  if (delta == 0.0) {
    Wdaz = z;
  } else {
    if (alpha == 1.0) {
      Wdaz = W_delta_Cpp(z, delta);
    } else {
      Wdaz = Rcpp::pow(W_Cpp(alpha * delta * pow(abs(z), 2 * alpha), 0) / (delta * alpha), 
                             1.0 / (2.0 * alpha));
      IntegerVector signz = Rcpp::sign(z);
      for (int ii = 0; ii < nn; ii++) {
        if (signz[ii] == -1) {
          Wdaz[ii] *= -1;
        }
      }
    }
  }
  return Wdaz;
}

/*
// slower than R; needs proper as<double> conversion 
// [[Rcpp::export]]
NumericVector W_2delta_Cpp(NumericVector z, double delta_l, double delta_r, Function W0, Function Wm1) {
  int nn = z.length();
  NumericVector W2deltaz(nn);
  if (delta_l == 0.0 & delta_r == 0.0) {
    W2deltaz = z;
  } else {
    IntegerVector signz = Rcpp::sign(z);
    for (int ii = 0; ii < nn; ii++) {
      if (signz[ii] == -1) {
        // use left delta for negative sign
        W2deltaz[ii] = W_delta_Cpp(z[ii], delta_l, W0, Wm1)[0];
      } else if (signz[ii] == 1) {
        // use right delta for positive sign
        W2deltaz[ii] = W_delta_Cpp(z[ii], delta_r, W0, Wm1)[0];
      }
    }
  }
  return W2deltaz;
}
*/