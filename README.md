# Composite Quadrature Methods for Numerical Integration 

This project implements and compares three **numerical quadrature methods**:  
- **Trapezoidal rule**  
- **Midpoint rule**  
- **Simpson’s rule**  

The goal is to approximate the integral:  
\[
\int_0^3 e^x \, dx = e^3 - 1 \approx 19.0855
\]

## Key Features
- **Global Refinement**:  
  - Trapezoidal rule: α = 1/2  
  - Midpoint rule: α = 1/3  
- **Stopping Criteria**:  
  Stops when the error is below a given tolerance (10⁻² or 10⁻⁴).  

## Results Summary
- **Simpson's rule** outperforms the other methods in both accuracy and efficiency.  
- **Global refinement** makes the trapezoidal method more efficient than the midpoint method.  

## Project Files  
- **Paper**: [quadraturePaper.pdf](quadraturePaper.pdf) – Describes the methods, results, and analysis in detail.  
- **Code**: [quadratureCode.cpp](quadratureCode.cpp) – Contains the implementation of the three quadrature methods.  

