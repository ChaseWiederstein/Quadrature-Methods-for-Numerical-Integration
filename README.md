# Composite Quadrature Methods for Numerical Integration 

This project implements **three composite quadrature methods**—the **trapezoidal rule**, **midpoint rule**, and **Simpson’s rule**—to approximate the integral:  
\[
\int_0^3 e^x \, dx = e^3 - 1 \approx 19.08553692
\]
The goal is to compare the **accuracy and efficiency** of these methods, with a focus on global refinement for the trapezoidal and midpoint rules. The code also explores **convergence rates** through different levels of interval subdivision.

---

## Contents  
- **`src/`**: C++ code for the quadrature algorithms  
- **`paper.pdf`**: Detailed report with results and analysis  

---

## 1. Quadrature Methods Implemented  

### 1.1 Composite Trapezoidal Rule  
The trapezoidal rule estimates the integral by evaluating the function at the endpoints of each interval.  
- **Global refinement factor**: \( \alpha = \frac{1}{2} \)  
- **Algorithm**:  
  \[
  I_m^{\text{ctr}} = \frac{H_m}{2} \left(f_0 + f_m + 2 \sum_{i=1}^{m-1} f_i\right)
  \]
- **Function Reuse**: In refinement, previously computed points are reused to build a fine grid.

---

### 1.2 Composite Midpoint Rule  
The midpoint rule uses the center of each interval for evaluation.  
- **Global refinement factor**: \( \alpha = \frac{1}{3} \)  
- **Algorithm**:  
  \[
  I_m^{\text{cmp}} = H_m \sum_{i=1}^{m-1} f\left(x_i + \frac{H_m}{2}\right)
  \]

---

### 1.3 Composite Simpson’s Rule  
Simpson’s rule uses both endpoints and the midpoints of each interval but does not apply global refinement in this project.  
- **Algorithm**:  
  \[
  I_m^{\text{csf}} = \frac{H_m}{6} \left(f(a) + f(b) + 2 \sum_{i=1}^{m-1} f(b_i) + 4 \sum_{i=1}^{m} f(c_i)\right)
  \]

---

## 2. Experimental Design and Results  

### 2.1 Stopping Criteria  
Each method stops when the **error tolerance** is satisfied:  
\[
|I - \tilde{I}| < \text{tol}
\]
Two tolerances are used:  
- **tol** = \(10^{-2}\)  
- **tol** = \(10^{-4}\)  

We increase the number of subintervals \(m\) iteratively until convergence.

---

### 2.2 Error Bounds  
Theoretical error bounds for each method:
- **Trapezoidal Rule**: \(E_m^{\text{ctr}} = -\frac{(b - a) H_m^2}{12} f''(\xi)\)  
- **Midpoint Rule**: \(E_m^{\text{cmp}} = \frac{(b - a) H_m^2}{12} f''(\xi)\)  
- **Simpson’s Rule**: \(E_m^{\text{csf}} = -\frac{(b - a) H_m^4}{2880} f^{(4)}(\xi)\)  

Results show that **Simpson’s rule** has the best convergence rate.

---

### 2.3 Global Refinement Comparison  
- **Midpoint rule refinement**: \(m = 3^k\)  
- **Trapezoidal rule refinement**: \(m = 2^k\)  
Both methods converge to **order 2** as expected, but the trapezoidal rule is more efficient due to fewer function evaluations.

---

## 3. Conclusion  
- **Simpson’s rule** provides the highest accuracy and efficiency among the three methods.  
- For global refinement, the **trapezoidal rule** outperforms the midpoint rule in terms of function reuse and efficiency.  
- While all methods performed well with the chosen function, results may vary for non-smooth functions, requiring further analysis.

---
