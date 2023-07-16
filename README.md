# qpOASES_EXAMPLE
This example shows how to use the qpOASES library (https://github.com/coin-or/qpOASES) to solve a simple quadratic program of the form
```math
\displaystyle \min_{x} x^{T}Hx + x^{T}g
```
```math
b_{\rm lb} \leq Ax \leq b_{\rm ub}
```
```math
 x_{\rm lb} \leq x \leq x_{\rm ub}
```
with $`H = \begin{bmatrix} 1 & 0 \\ 0 & 0.5 \end{bmatrix}`$, $`g = \begin{bmatrix} 1.5 \\ 0 \end{bmatrix}`$, $`A = \begin{bmatrix} 1 & 1 \end{bmatrix}`$, $`b_{\rm lb} = -1`$, $`b_{\rm ub} = 2`$, $`x_{\rm lb} = \begin{bmatrix} 0.5 \\ -2 \end{bmatrix}`$ and $`x_{\rm ub} = \begin{bmatrix} 5 \\ 2 \end{bmatrix}`$. Make sure you have Eigen installed.
