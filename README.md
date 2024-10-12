# Composite Quadrature Methods for Numerical Integration

## Executive Summary
This project implements three composite quadrature methods: the trapezoidal rule, Simpson’s rule, and the midpoint rule, to evaluate the integral 

```math
\int_0^3 e^x \, dx = e^3 - 1 \approx 19.08553692.
```

Each method employs a uniform interval size. The midpoint and composite midpoint rules will be implemented using a global uniform subinterval size refinement. The performance and accuracy of each method are compared based on their results.

## Key Sections
1. **Statement of the Problem**
   - Overview of the task, specifying the quadrature methods implemented and the integral being evaluated.

2. **Description of the Algorithms and Implementation**
   - Details of the three quadrature methods, including stopping conditions, algorithmic steps, and refinements used.

   2.1 **Composite Trapezoidal Rule**
   - Outlines the algorithm for the composite trapezoidal rule, emphasizing the reuse of function evaluations to refine the grid.

   2.2 **Composite Midpoint Rule**
   - Describes the algorithm for the composite midpoint rule, including its refinement strategy for improved accuracy.

   2.3 **Composite Simpson’s Rule**
   - Provides the formula for Simpson’s rule without a refinement algorithm, focusing on its implementation.

3. **Description of the Experimental Design and Results**
   - Discussion of the experiments conducted to evaluate the performance of each quadrature method.

   3.1 **Task I**
   - Analysis of the stopping criteria and the theoretical error bounds for each method, including results from both numerical and theoretical evaluations.

   3.2 **Task II**
   - Examination of the global refinement methods for the composite midpoint and trapezoidal methods, showcasing their order of convergence and efficiency.

4. **Conclusion**
   - Summary of findings, indicating that Simpson’s rule is the most accurate and efficient method, while the trapezoidal rule outperforms the midpoint rule in terms of efficiency. The conclusion suggests that other functions may require a different analysis of quadrature methods.

## Project Files  
- **Paper**: [quadraturePaper.pdf](quadraturePaper.pdf) – Describes the methods, results, and analysis in detail.  
- **Code**: [quadratureCode.cpp](quadratureCode.cpp) – Contains the implementation of the three quadrature methods.  

