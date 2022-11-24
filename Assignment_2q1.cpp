// c++ program to find the root of the non-linear equation cos(x) - 3x + 1 using the fixed point iteration method....
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

// defining the global variables
long double x_new = 0, x_old = 0;
int flag = 0; // counter for keeping the track of iterations.

// defining the fixed point iteration function.g_x..

long double g_x(long double x, long double epsilon, int n_max)
{

    if (fabs(x_old - x) > epsilon && flag < n_max)
    {
        x_old = x;
        x_new = ((1 + cos(x)) / 3.0);
        flag += 1;
        x_new = g_x(x_new, epsilon, n_max);
        // cout << setprecision(20) << fabs(x_old - x) << endl; // displays the absolute difference between succesive iterations..
    }
    return x_new;
}

int main()
{
    long double epsilon; // max_value of epsilon = 10e-20;
    int n_max;
    long double init_guess, x;

    // taking inputs
    cout << "#Caution!! In case of invalid input the program will run on default set of parameter values: \n Initial Guess = Same as given, Tolerance Epsilon = 10e-15, Max Iterations = 20" << endl;
    cout << "Enter initial Guess : ";
    cin >> init_guess;
    cout << "Enter the Tolerance Epsilon (Maximum allowed value is 10e-20) : ";
    cin >> epsilon;
    cout << "Enter the maximum number of iterations (Maximum allowed value is 35) :";
    cin >> n_max;

    // invalid input check/ default reset ..
    if (epsilon < 10e-20)
    {
        epsilon = 10e-15;
        cout << " The program ran on Tolerance = '10e-15'" << endl;
    }
    if (n_max > 35)
    {
        n_max = 20;
        cout << " The program ran on Max Iterations = '20'" << endl;
    }

    // initializing the function....
    x = g_x(init_guess, epsilon, n_max);

    // printing the approximate solution...
    cout << setprecision(20) << endl
         << "The approximate root of cos(x)-3x+1 is : " << x << endl;

    return 0;
}