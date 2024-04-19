#include "Triangle.h"
#include <iostream>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

Triangle::Triangle(double first_1, double second_2) {
	if (first_1 < 0 || second_2 < 0) {
		throw NegativeSideLengthException("Side length cannot be negative");
	}
	first = first_1;
	second = second_2;
}

Triangle::Triangle(const Triangle& first_1)
{
	first = first_1.first;
	second = first_1.second;
}

Triangle::~Triangle()
{}

void Triangle::SetFirst(double value) {
	if (value < 0) {
		throw invalid_argument("Side length cannot be negative");
	}
	first = value;
}

void Triangle::SetSecond(double value) {
	if (value < 0) {
		throw invalid_argument("Side length cannot be negative");
	}
	second = value;
}

Triangle& Triangle::operator = (const Triangle& r)
{
	first = r.first;
	second = r.second;
	return *this;
}

Triangle::operator string () const
{
	stringstream ss;
	ss << " First: " << first << endl;
	ss << " Second: " << second << endl;
	return ss.str();
}

Triangle operator + (const Triangle& x, const Triangle& y)
{
	return Triangle(x.first + y.first, x.second + y.second);
}
Triangle operator - (const Triangle& x, const Triangle& y)
{
	return Triangle(x.first - y.first, x.second - y.second);
}
Triangle operator * (const Triangle& x, const Triangle& y)
{
	return Triangle(x.first * y.first - x.second * y.second,
		x.first * y.second + x.second * y.first);
}

Triangle operator / (const Triangle& x, const Triangle& y)
{
	double r1 = x.first;
	double i1 = x.second;
	double r2 = y.first;
	double i2 = y.second;
	return Triangle((r1 * r2 - i1 * i2) / (r2 * r2 + i2 * i2),
		(-r1 * i2 + i1 * r2) / (r2 * r2 + i2 * i2));
}
Triangle operator ^ (const Triangle& x, const unsigned n)
{
	Triangle y(1, 0);
	for (unsigned i = 1; i <= n; i++)
		y = y * x;
	return y;
}

ostream& operator << (ostream& out, const Triangle& r)
{
	out << string(r);
	return out;
}
istream& operator >> (istream& in, Triangle& r)
{
	cout << " First: "; in >> r.first;
	cout << " Second: "; in >> r.second;
	cout << endl;
	return in;
}

Triangle& Triangle::operator ++()
{
	first++;
	return *this;
}

Triangle& Triangle::operator --()
{
	first--;
	return *this;
}

Triangle Triangle::operator ++(int)
{
	Triangle t(*this);
	second++;
	return t;
}

Triangle  Triangle::operator --(int)
{
	Triangle t(*this);
	second--;
	return t;
}

double Triangle::operator()() const {
	if (first < 0 || second < 0) {
		throw invalid_argument("Side lengths cannot be negative");
	}
	return sqrt(first * first + second * second);
}

