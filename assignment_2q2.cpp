// c++ program to find the solution of the differential equation f`(x) = x + y + xy using modified and improved Euler's method
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

#define f(x, y) (x + y + x * y) // Derative Fuction Defined..

// Declaring GLobal Variables
double y_new = 0, y_old = 0;                      // Iterative variables for Euler's method
double x_init = 0, y_init = 1, step_size = 0.025; // Initial Conditions and the step-size.
float X_val = 0.1;                                // X - Value on which function value is required

// Improved Euler Function
double imp_Euler(double x, double y, double h)
{
    if ((X_val - x) > 0)
    {
        y_old = y;
        y_new = y + (h / 2) * (f(x, y) + f((x + h), (y + h * f(x, y))));
        y_new = imp_Euler(x + h, y_new, h);
    }
    return y_new;
}

// Modified Euler Function
double mod_Euler(double x, double y, double h)
{
    if ((X_val - x) > 0)
    {
        y_old = y;
        y_new = y + (h) * (f((x + (h / 2)), (y + (h / 2) * f(x, y))));
        y_new = mod_Euler(x + h, y_new, h);
    }
    return y_new;
}

int main()
{
    cout << " The ODE used here is dy/dx = x + y + x * y with Initial Conditions : y(" << x_init << ") = " << y_init << " and Step-Size (h) = " << step_size << endl;
    cout << " Calculating The Value of solution of ODE at x = " << X_val << endl;
    cout << setprecision(16) << " f(0.1) = " << imp_Euler(x_init, y_init, step_size) << " --- IMPROVED EULER SOLUTION \n"
         << endl;
    cout << setprecision(16) << " f(0.1) = " << mod_Euler(x_init, y_init, step_size) << " --- MODIFIED EULER SOLUTION \n"
         << endl;
    return 0;
}