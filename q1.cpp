#include <iostream>

struct X{
   int i;
   X(int a): i {a} {};
   X operator+(int);
};

struct Y{
   int i;
   Y(X x){i = x.i;};
   Y operator+(X);
   operator int(){ return i; };
};

extern X operator*(X, Y);
extern int f(X);

X X::operator+(int i){
   return X(i+this->i);
}

Y Y::operator+(X x){
   Y y(X(this->i + x.i));
   return y;
}

X operator*(X x, Y y){
   return X(x.i * y.i);		
}

int f(X x)
{
   return x.i;
}
std::ostream& operator<<(std::ostream& os, X x)
{
	os << x.i << std::endl;
	return os;
}

std::ostream& operator<<(std::ostream& os, Y y)
{
	os << y.i << std::endl;
	return os;
}

X x = 1;
Y y = x;
int i = 2;

int main()
{
   std::cout << "i + 10 = " << i + 10 << std::endl; // no conversion used
   std::cout << "y + 10 = " <<  int(y) + 10 << std::endl; // y is converted to int
   std::cout << "y + 10 * y = " <<  y + X(10)*y << std::endl; // 10 is converted to X, result of
   							       // y + X*y is converted to Y

   std::cout << "x + y + i = " << x + y + i << std::endl; // y converted to int, result of x + y 								   // converted to X, result of x+y+i     								   // converted to X
   std::cout << "x * x + i = " << x * y + i << std::endl;
   /* the second x from left is converted into Y, the result of x * x is converted into X, and 
    * the final result is converted into X */
   std::cout << "f(7) = " << f(7) << std::endl; // 7 is converted into X in call to f(7).
   std::cout << "f(y) = " << f(int(y)) << std::endl; 
   // y is converted into int, the int is converted into X
   std::cout << "y + y = " << y + y << std::endl;
   /* both y's will be converted to int */
   std::cout << "106 + y = " << 106 + int(y) << std::endl; // the y is converted to int
}

