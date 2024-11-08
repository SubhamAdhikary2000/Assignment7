#include <iostream>
using namespace std;

struct X {
    int i;

    // Constructor to initialize X with an integer
    X(int n) : i(n) {}

    // Overload + operator to add int to X and return a new X
    X operator+(int n) {
        return X(n + i);
    }
};

struct Y {
    int i;

    // Overload + operator to add an X object to Y and return a new Y
    Y operator+(X x) {
        Y y;
        y.i = x.i + i;
        return y;
    }

    // Conversion operator to convert Y to int by returning the value of i
    operator int() {
        return i;
    }
};

// Overload << operator for outputting X to ostream
ostream& operator<<(ostream& os, X x) {
    os << x.i;
    return os;
}

// Overload * operator for multiplying an X and a Y and returning a new X
extern X operator*(X x, Y y) {
    return X(x.i * y.i);
}

// External function that takes an X and returns its integer value
extern int f(X x) {
    return x.i;
}

// Global variable initialization
X x = 1;          // Creates an X object with i = 1
Y y = y + x;      // Calls Y::operator+ with y (default initialized) and x, assigning to y
int i = 2;        // Initializes an int with value 2

int main() {
    // Output the result of i + 10, a simple integer addition
    cout << "i + 10 = " << i + 10 << endl;

    // Output the result of y + X(10), where y is added to an X object with i = 10
    cout << "y + 10 = " << y + X(10) << endl;

    // Output the result of y + (X(10) * y), which multiplies X(10) and y, then adds to y
    cout << "y + 10 * y = " << y + X(10) * y << endl;

    // Output the result of x + y + i, where x and y are added as X, and i is added as int
    cout << "x + y + i = " << x + y + i << endl;

    // Output the result of f(x) * f(x) + i, where f(x) returns the int i of X
    cout << "x + x + i = " << f(x) * f(x) + i << endl;

    // Output the result of f(7), where 7 is implicitly converted to X via constructor
    cout << "f(7) = " << f(7) << endl;

    // Output the result of f(y), where y is converted to int, then to X for f
    cout << "f(y) = " << f(int(y)) << endl;

    // Output the result of y + y, which uses Y's overloaded + operator
    cout << "y + y = " << y + y << endl;

    // Output the result of 106 + int(y), converting y to int and adding to 106
    cout << "106 + y = " << 106 + int(y) << endl;

    return 0;
}

