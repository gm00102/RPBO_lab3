#include <iostream>
#include <complex>
//#define _SILENCE_NONFLOATING_COMPLEX_DEPRECATION_WARNING
import Math;
using namespace std;
int main()
{
	Complex a(5, -5);
	Complex b(2, -2);
	Rational rat1(7, 1);
	Rational rat2(6, 2);
	double c = 4.0;
	cout << "My complex: a = " << a << " re = " << a.Re() << " im = " << a.Im() << " mod = " << a.Mod() << " arg = " << a.Arg() << endl;
	cout << "My complex: a+b = " << a << " + " << b << " = " << a + b << endl;
	cout << "My complex: a-b = " << a << " + " << b << " = " << a - b << endl;
	cout << "My complex: a*b = " << a << " + " << b << " = " << a * b << endl;
	cout << "My complex: a/b = " << a << " + " << b << " = " << a / b << endl;
	cout << "My complex: a+c = " << a << " + " << c << " = " << a + c << endl;
	cout << "My Rational: a = " << rat1 << " = " << rat1.Nominator() << " / " << rat1.Denominator() << " double = " << double(rat1) << endl;
	cout << "My Rational: a+b = " << rat1 << " + " << rat2 << " = " << rat1 + rat2 << endl;
	cout << "My Rational: a-b = " << rat1 << " - " << rat2 << " = " << rat1 - rat2 << endl;
	cout << "My Rational: a*b = " << rat1 << " * " << rat2 << " = " << rat1 * rat2 << endl;
	cout << "My Rational: a/b = " << rat1 << " / " << rat2 << " = " << rat1 / rat2 << endl;

	cout << "f(" << a << ") = " << f(a) << endl;
	cout << "f(" << rat1 << ") = " << f(rat1) << endl;
	cout << "f(" << c << ") = " << f(c) << endl;

	return 0;
}