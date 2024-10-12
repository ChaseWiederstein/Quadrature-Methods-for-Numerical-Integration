// fcm2_proj3.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
using namespace std;

double func(double x) {
    return exp(x); 
}

std::vector<double> func(const std::vector<double>& x) {
    std::vector<double> result(x.size());
    for (int i = 0; i < x.size(); ++i) {
        result[i] = exp(x[i]); 
    }
    return result;
}

void GlobalRefinementCTR(double a, double b, int n) {
    int m = 1;
    double actual = exp(3) - 1;
    double h;
    int eval = 0;
    double r = 0.0;
    double prev_I_2m = 0.0;

    while (true) {
        double I_2m = 0.0;
        h = (b - a) / m;
        double sum = 0.0;

        for (int i = 1; i < m; ++i) {
            double xi = a + i * h;
            sum += func(xi);
            eval++;
        }
        sum = 0.5 * (func(a) + func(b)) + sum;
        eval += 2;
        sum *= h;

        I_2m = sum;
        double frac = (I_2m - prev_I_2m) / (actual - I_2m);
        r = log(frac + 1) / log(2);

        double error = abs(actual - I_2m);
        std::cout << "m: " << m << ", approx: " << I_2m << ", error: " << error << ", function eval: " << eval << ", r: " << r << std::endl;

        if (error <= pow(10, -n)) {
            break;
        }

        prev_I_2m = I_2m;
        m *= 2;
        eval = 0;
    }
}

void CompTrapRule(double a, double b, int n) {
    int m = 1;
    double actual = exp(3) - 1;
    double sum = 0.0;
    double h;
    int eval = 0;
    
    while (true) {
        h = (b - a) / m;
        sum = 0.5 * (func(a) + func(b)); //endpoints
        eval += 2;

        for (int i = 1; i < m; ++i) { //in sum 
            double xi = a + i * h;
            sum += func(xi);
            eval++;
        }

        sum *= h;
        double error = abs(actual - sum);
        std::cout << "m: " << m << ", approx: " << sum << ", error: " << error << ", function eval: " << eval << std::endl;

        if (error <= pow(10, -n)) {
            break;
        }

        m += 1;
        eval=0;
    }
}

void CompMidpointRule(double a, double b, int n) {
    int m = 1;
    double actual = exp(3) - 1;
    double sum = 0.0;
    double h;
    int eval = 0;

    while (true) {
        h = (b - a) / m;
        sum = 0.0;

        for (int i = 0; i < m; ++i) {
            double xi = a + h / 2 + i * h;
            sum += func(xi);
            eval++;
        }

        sum *= h;
        double error = abs(actual - sum);
        std::cout << "m: " << m << ", approx: " << sum << ", error: " << error << ", function evaluations: " << eval << std::endl;

        if (error <= pow(10, -n)) {
            break;
        }

        m += 1;
        eval = 0;
    }
}

void GlobalRefinementCMR(double a, double b, int n) {
    int m = 1;
    double actual = exp(3) - 1;
    double h;
    int eval = 0;
    double r = 0.0;

    while (true) {
        r = 0;
        double I_3m = 0.0;
        h = (b - a) / m;
        double sum = 0.0;
        for (int i = 0; i < m; ++i) {
            double xi = a + h / 2 + i * h;
            sum += func(xi);
            eval++;
        }
        sum *= h;

        double hfine = h / 3;
        double sum_fine = 0.0;
        for (int i = 0; i < 3 * m; ++i) {
            double xi = a + hfine / 2 + i * hfine;
            sum_fine += func(xi);
           // eval++;
        }
        eval++;
        sum_fine *= hfine;
        I_3m = sum_fine;
        double frac = (I_3m - sum) / (actual - I_3m);
        r = log(frac + 1) / log(3);

        double error = abs(actual - sum_fine);
        std::cout << "m: " << m << ", approx: " << sum_fine << ", error: " << error << ", function eval: " << eval << ", r: " << r << std::endl;
        if (error <= pow(10, -n)) {
            break;
        }
        m *= 3;
        eval = 0;
    }
}

void CompSimpRule(double a, double b, int n) {
    int m = 1;
    double actual = exp(3) - 1;
    double sum = 0.0;
    double h;
    int eval = 0; 
    while (true) {
        h = (b - a) / m;
        sum = func(a) + func(b); // Endpoints
        eval += 2;
        for (int i = 1; i < m; i++) { // Odds
            double bi = a + i * h;
            sum += 2 * func(bi);
            eval++;
        }

        for (int i = 0; i < m; i++) { // Evens
            double ci = a + (i + 0.5) * h;
            sum += 4 * func(ci);
            eval++;
        }

        sum *= h / 6;
        double error = abs(actual - sum);
        std::cout << "m: " << m << ", approx: " << sum << ", error: " << error << ", function eval: " << eval << std::endl;

        if (error <= pow(10, -n)) {
            break;
        }
        m += 1;
        eval = 0;
    }

}

int main()
{
    int n; 
    std::cout << "Enter your n for your tolerance (10^-n): ";
    std::cin >> n;
    double a = 0;
    double b = 3;
    
    std::cout << "COMPOSITE TRAPEZOIDAL: " << std::endl; 
    CompTrapRule(a, b, n);
    std::cout << "COMPOSITE MIDPOINT: " << std::endl;
    CompMidpointRule(a, b, n);
    std::cout << "COMPOSITE SIMPSONS: " << std::endl;
    CompSimpRule(a, b, n);
    std::cout << "GLOBAL REFINEMENT COMPOSITE TRAPEZOIDAL: " << std::endl;
    GlobalRefinementCTR(a, b, n);
    std::cout << "GLOBAL REFINEMENT COMPOSITE MIDPOINT: " << std::endl;
    GlobalRefinementCMR(a, b, n);
}

