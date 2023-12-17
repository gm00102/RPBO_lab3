module;
#include <math.h>
#include <ostream>
export module Math;

export class Complex
{
private:
	double m_re;
	double m_im;
public:
	Complex(double real)
	{
		m_re = real;
		m_im = 0;
	}
	Complex()
	{
		m_re = 0;
		m_im = 0;
	}
	Complex(double real, double imag)
	{
		m_re = real;
		m_im = imag;
	}

	static Complex FromExponentialForm(double modul, double argum)
	{
		Complex exp_obj;
		exp_obj.m_re = modul * cos(argum);
		exp_obj.m_im = modul * sin(argum);
		return exp_obj;
	}
	static Complex FromAlgebraicForm(double real, double imag)
	{
		Complex alg_obj(real, imag);
		return alg_obj;
	}
	double Re() const
	{
		return m_re;
	}
	double Im() const
	{
		return m_im;
	}
	double Mod() const
	{
		return sqrt(m_re * m_re + m_im * m_im);
	}
	double Arg() const
	{
		return atan2(m_im, m_re);
	}

	explicit operator double() const {
		return m_re;
	}
	Complex operator-()
	{
		Complex obj{*this};
		obj.m_im *= -1;
		obj.m_re *= -1;
		return obj;
	}
	Complex& operator++()
	{
		m_re++;
		return *this;
	}
	Complex operator++(int _post_inc)
	{
		Complex obj{*this};
		++*this;
		return obj;
	}
	Complex& operator--()
	{
		m_re--;
		return *this;
	}
	Complex operator--(int _post_dec)
	{
		Complex obj{*this};
		--*this;
		return obj;
	}
	Complex& operator+=(Complex q)
	{
		m_re += q.m_re;
		m_im += q.m_im;
		return *this;
	}
	Complex& operator-=(Complex q) {
		m_re -= q.m_re;
		m_im -= q.m_im;
		return *this;
	}
	Complex& operator*=(Complex q) {
		double temp_re = m_re;
		double temp_im = m_im;
		m_re = temp_re * q.m_re - temp_im * q.m_im;
		m_im = temp_re * q.m_im + temp_im * q.m_re;
		return *this;
	}
	Complex& operator/=(Complex q) {
		double tre1 = m_re, tim1 = m_im;
		double tre2 = q.m_re, tim2 = q.m_im;
		m_re = (tre1 * tre2 + tim1 * tim2) / (pow(tre2, 2) + pow(tim2, 2));
		m_im = (tre2 * tim1 - tre1 * tim2) / (pow(tre2, 2) + pow(tim2, 2));
		return *this;
	}
	friend Complex operator+ (const Complex& first, const Complex& second);
	friend Complex operator- (const Complex& first, const Complex& second);
	friend Complex operator* (const Complex& first, const Complex& second);
	friend Complex operator/ (const Complex& first, const Complex& second);

	friend Complex operator ""i(long double imag);
	friend Complex operator ""i(unsigned long long imag);

	friend std::ostream& operator<<(std::ostream& stream, const Complex& q);
};
export Complex operator+(const Complex& first, const Complex& second)
{
	return Complex(first.m_re + second.m_re, first.m_im + second.m_im);
}
export Complex operator-(const Complex& first, const Complex& second)
{
	return Complex(first.m_re - second.m_re, first.m_im - second.m_im);
}
export Complex operator*(const Complex& first, const Complex& second)
{
	return Complex((first.m_re * second.m_re - first.m_im * second.m_im),
		(first.m_re * second.m_im + first.m_im * second.m_re));
}
export Complex operator/(const Complex& first, const Complex& second)
{
	return Complex((first.m_re * second.m_re + first.m_im * second.m_im) /
		(second.m_re * second.m_re + second.m_im * second.m_im),
		(second.m_re * first.m_im - first.m_re * second.m_im) /
		(second.m_re * second.m_re + second.m_im * second.m_im));
}
export Complex operator""i(long double imag)
{
	return Complex(0.0, static_cast<double>(imag));
}
export Complex operator""i(unsigned long long imag)
{
	return Complex(0.0, static_cast<double>(imag));
}
export std::ostream& operator<<(std::ostream& stream, const Complex& q)
{
	if (q.m_im < 0)
	{
		stream << q.m_re << " " << q.m_im << "i";
	}
	else
	{
		stream << q.m_re << " + " << q.m_im << "i";
	}
	return stream;
}

export int FindGreatestCommonDivisor(int a, int b)
{
	int r;
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	while (true)
	{
		if (b == 0)
			return a;
		r = a % b;
		a = b;
		b = r;
	}
}
export int FindLeastCommonMultiple(int a, int b) {
	return abs(a * b) / FindGreatestCommonDivisor(a, b);
}

export class Rational {
	int m_nominator;
	int m_denominator;
	
public:
	void normalize()
	{
		int nod = FindGreatestCommonDivisor(m_nominator, m_denominator);
		m_nominator /= nod;
		m_denominator /= nod;
		if (m_denominator < 0) {
			m_denominator *= -1;
			m_nominator *= -1;
		}
	}

	Rational()
	{
		m_nominator = 0;
		m_denominator = 1;
	}
	Rational(int _nominator, int _denominator) {
		m_denominator = _denominator;
		m_nominator = _nominator;
		normalize();
	}
	Rational(int _nominator) {
		m_nominator = _nominator;
		m_denominator = 1;
	}
	int Nominator() const {
		return m_nominator;
	}
	int Denominator() const {
		return m_denominator;
	}
	explicit operator double() const {
		return double(m_nominator) / m_denominator;
	}
	Rational operator-() {
		Rational obj{*this};
		obj.m_nominator *= -1;
		return obj;
	}
	Rational& operator++ () {
		m_nominator += m_denominator;
		return *this;
	}
	Rational operator++ (int _param) {
		Rational obj{*this};
		(*this).m_nominator += m_denominator;
		return obj;
	}
	Rational& operator-- () {
		m_nominator -= m_denominator;
		return *this;
	}
	Rational operator-- (int _param) {
		Rational obj{*this};
		(*this).m_nominator -= m_denominator;
		return obj;
	}
	Rational& operator+=(Rational q) {
		int new_den = FindLeastCommonMultiple(m_denominator, q.m_denominator);
		m_nominator = new_den / m_denominator * m_nominator;
		m_nominator += new_den / q.m_denominator * q.m_nominator;
		m_denominator = new_den;
		normalize();
		return *this;
	}
	Rational& operator-=(Rational q) {
		int new_d = FindGreatestCommonDivisor(m_denominator, q.m_denominator);
		m_nominator = new_d / m_denominator * m_nominator;
		m_nominator -= new_d / q.m_denominator * q.m_nominator;
		m_denominator = new_d;
		normalize();
		return *this;
	}
	Rational& operator*=(Rational q) {
		m_denominator *= q.m_denominator;
		m_nominator *= q.m_nominator;
		normalize();
		return *this;
	}
	Rational& operator/=(Rational q) {
		m_denominator *= q.m_nominator;
		m_nominator *= q.m_denominator;
		normalize();
		return *this;
	}
	friend Rational operator+ (const Rational& first, const Rational& second);
	friend Rational operator- (const Rational& first, const Rational& second);
	friend Rational operator* (const Rational& first, const Rational& second);
	friend Rational operator/(const Rational& first, const Rational& second);

	friend bool operator==(const Rational& first, const Rational& second);
	friend bool operator>(const Rational& first, const Rational& second);
	friend bool operator<(const Rational& first, const Rational& second);
	friend bool operator>=(const Rational& first, const Rational& second);
	friend bool operator<=(const Rational& first, const Rational& second);

	friend std::ostream& operator<<(std::ostream& stream, const Rational& q);
};

export Rational operator+ (const Rational& first, const Rational& second) {
	int denominator = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
	int nominator = denominator / first.m_denominator * first.m_nominator;
	nominator += denominator / second.m_denominator * second.m_nominator;
	return Rational{ nominator, denominator };
}

export Rational operator-(const Rational& first, const Rational& second)
{
	int denominator = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
	int nominator = denominator / first.m_denominator * first.m_nominator;
	nominator -= denominator / second.m_denominator * second.m_nominator;
	return Rational{ nominator, denominator };
}

export Rational operator*(const Rational& first, const Rational& second)
{
	return Rational{ first.m_nominator * second.m_nominator, second.m_denominator * first.m_denominator };
}

export Rational operator/(const Rational& first, const Rational& second)
{
	return Rational{ first.m_nominator * second.m_denominator,first.m_denominator * second.m_nominator };
}

export bool operator==(const Rational& first, const Rational& second)
{
	return first.m_nominator == second.m_nominator && first.m_denominator == second.m_denominator;
}

export bool operator>(const Rational& first, const Rational& second)
{
	int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
	return den / first.m_denominator * first.m_nominator > den / second.m_denominator * second.m_nominator;
}
export bool operator<(const Rational& first, const Rational& second)
{
	int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
	return den / first.m_denominator * first.m_nominator < den / second.m_denominator * second.m_nominator;
}
export bool operator>=(const Rational& first, const Rational& second)
{
	int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
	return den / first.m_denominator * first.m_nominator >= den / second.m_denominator * second.m_nominator;
}
export bool operator<=(const Rational& first, const Rational& second)
{
	int den = FindLeastCommonMultiple(first.m_denominator, second.m_denominator);
	return den / first.m_denominator * first.m_nominator <= den / second.m_denominator * second.m_nominator;
}

export std::ostream& operator<<(std::ostream& stream, const Rational& q) {
	stream << q.m_nominator << "|" << q.m_denominator;
	return stream;
}

export Complex f(const Complex& z)
{
	Complex a(2, 0);
	Complex result = a * z + pow(2.71828,5) * (1 + z);
	return result;
}

export Rational f(const Rational& r) 
{
	Rational a(2, 1);
	Rational result = a * r + pow(2.71828,5) * (1 + r);
	return result;
}

export double f(const double& d) 
{
	double a = 2.0;
	double result = a * d + pow(2.71828, 5) * (1 + d);
	return result;
}