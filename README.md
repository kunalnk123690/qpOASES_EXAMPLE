# qpOASES_EXAMPLE
This example shows how to use the qpOASES library (https://github.com/coin-or/qpOASES) to solve a simple quadratic program of the form
$$` \min_{x} x^{T}Hx + x^{T}g `$$
$$` Ax \preceq b `$$
$$` x_{\rm lb} \leq x \leq x_{\rm ub} `$$
with $`H = \begin{bmatrix} 1 & 0 \\ 0 & 0.5 \end{bmatrix}`$, $`g = \begin{bmatrix} 1.5 & 0 \end{bmatrix}`$, $`x_{\rm lb} = \begin{bmatrix} 0.5 & -2 \end{bmatrix}`$ and $`x_{\rm ub} = \begin{bmatrix} 5 & 2 \end{bmatrix}`$. Make sure you have Eigen installed.
