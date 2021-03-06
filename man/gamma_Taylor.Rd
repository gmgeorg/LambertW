% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/gamma_Taylor.R
\name{gamma_Taylor}
\alias{gamma_Taylor}
\title{Estimate gamma by Taylor approximation}
\usage{
gamma_Taylor(y, skewness.y = skewness(y), skewness.x = 0, degree = 3)
}
\arguments{
\item{y}{a numeric vector of data values.}

\item{skewness.y}{skewness of \eqn{y}; default: empirical skewness of data
\code{y}.}

\item{skewness.x}{skewness for input X; default: 0 (symmetric input).}

\item{degree}{degree of the Taylor approximation; in Goerg (2011) it just
uses the first order approximation (\eqn{6 \cdot \gamma}); a much better
approximation is the third order (\eqn{6 \cdot \gamma + 8 \cdot
\gamma^3}).  By default it uses the better \code{degree = 3}
approximation.}
}
\value{
Scalar; estimate of \eqn{\gamma}.
}
\description{
Computes an initial estimate of \eqn{\gamma} based on the Taylor
approximation of the skewness of Lambert W \eqn{\times} Gaussian RVs around
\eqn{\gamma = 0}. See Details for the formula.

This is the initial estimate for \code{\link{IGMM}} and
    \code{\link{gamma_GMM}}.
}
\details{
The first order Taylor approximation of the theoretical skewness
\eqn{\gamma_1} (not to be confused with the skewness parameter \eqn{\gamma})
of a Lambert W x Gaussian random variable around \eqn{\gamma = 0} equals
\deqn{ \gamma_1(\gamma) = 6 \gamma + \mathcal{O}(\gamma^3). }

Ignoring higher order terms, using the empirical estimate on the left hand
side, and solving \eqn{\gamma} yields a first order Taylor approximation
estimate of \eqn{\gamma} as
\deqn{
\widehat{\gamma}_{Taylor}^{(1)} = \frac{1}{6} \widehat{\gamma}_1(\mathbf{y}), 
}
where \eqn{\widehat{\gamma}_1(\mathbf{y})} is the empirical skewness of the
data \eqn{\mathbf{y}}.

As the Taylor approximation is only good in a neighborhood of \eqn{\gamma =
0}, the output of \code{gamma_Taylor} is restricted to the interval
\eqn{(-0.5, 0.5)}.

The solution of the third order Taylor approximation
\deqn{ \gamma_1(\gamma) = 6 \gamma + 8 \gamma^3 + \mathcal{O}(\gamma^5),}
is also supported.  See code for the solution to this third order polynomial.
}
\examples{

set.seed(2)
# a little skewness
yy <- rLambertW(n = 1000, theta = list(beta = c(0, 1), gamma = 0.1), 
                distname = "normal") 
# Taylor estimate is good because true gamma = 0.1 close to 0
gamma_Taylor(yy) 

# very highly negatively skewed
yy <- rLambertW(n = 1000, theta = list(beta = c(0, 1), gamma = -0.75), 
                distname = "normal") 
# Taylor estimate is bad since gamma = -0.75 is far from 0; 
# and gamma = -0.5 is the lower bound by default.
gamma_Taylor(yy) 

}
\seealso{
\code{\link{IGMM}} to estimate all parameters jointly.
}
\keyword{optimize}
