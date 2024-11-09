#include "complex.h"

TComplex::TComplex()
{
	re = 0.0;
	im = 0.0;
	r_abs = re * re + im * im;
	phi = asin(im / r_abs);
}

TComplex::TComplex(double r, double i)
{
	re = r;
	im = i;
	r_abs = re * re + im * im;
	phi = asin(im / r_abs);
}

TComplex::TComplex(int r)
{
	re = r;
	im = 0;
	r_abs = re * re + im * im;
	phi = asin(im / r_abs);
}

TComplex TComplex::operator* (TComplex c) 
{
	TComplex c1;
	c1.re = re * c.re - im * c.im;
	c1.im = re * c.im + im * c.re;
	return c1;
}

TComplex TComplex::operator+ (TComplex c)
{
	TComplex c1;
	c1.re = re + c.re;
	c1.im = im + c1.im;
	return c1;
}

TComplex TComplex::operator- (TComplex c)
{
	TComplex c1;
	c1.re = re - c.re;
	c1.im = im - c.im;
	return c1;
}

TComplex TComplex::operator/ (TComplex c)
{
	TComplex c1;
	double complexAbs = c.re * c.re + c.im * c.im;
	c1.re = (re * c.re + im * c.im) / complexAbs;
	c1.im = (im * c.re - re * c.im) / complexAbs;
	return c1;
}

TComplex& TComplex::operator= (TComplex c)
{
	re = c.re;
	im = c.im;
	r_abs = c.r_abs;
	phi = c.phi;
	return *this;
}

TComplex& TComplex::operator+= (TComplex c)
{
	re = re + c.re;
	im = im + c.im;
	r_abs = c.r_abs;
	phi = c.phi;
	return *this;
}

bool TComplex::operator== (TComplex c)
{
	return (re = c.re) && (im = c.im);
}

bool TComplex::operator!= (TComplex c)
{
	return !((re = c.re) && (im = c.im));
}

bool TComplex::operator> (TComplex c)
{
	if (r_abs >= c.r_abs)
	{
		if (r_abs > c.r_abs)
		{
			return true;
		}
		else
		{
			if (phi > c.phi)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

bool TComplex::operator< (TComplex c)
{
	if (r_abs <= c.r_abs)
	{
		if (r_abs < c.r_abs)
		{
			return true;
		}
		else
		{
			if (phi < c.phi)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	return false;
}

TComplex sqrt(TComplex c)
{
	TComplex c1;
	c1.re = pow(pow(c.re * c.re + c.im * c.im, 0.5) + c.re, 0.5) / 2;
	c1.im = pow(pow(c.re * c.re + c.im * c.im, 0.5) - c.re, 0.5) / 2;
	return c1;
}

ostream& operator <<(ostream& os, TComplex c)
{
	os << c.re << "+" << c.im << "i";
	return os;
}

istream& operator >>(istream& is, TComplex& c)
{
	is >> c.re >> c.im;
	c.r_abs = c.re * c.re + c.im * c.im;
	c.phi = asin(c.im / c.r_abs);
	return is;
}

QString& operator <<(QString& s, TComplex c)
{
    s += "(";
    s += QString().setNum(c.re);
    s += "+";
    s += QString().setNum(c.im);
    s += "i)";
    return s;
}
