// poly.cpp
// Thomas King and Manoj Adhikari
// 2016-10-11
// Implementation for a polynomial
//
// Invariants:
// 	current_degree must be equal to the highest exponent with a non-zero coefficient

#include "poly.h"
#include <cassert>
#include <cmath>
#include <climits>
#include <iostream>
#include <iomanip>

using namespace std;

namespace coen70_lab4
{
    //The current degree is set to the highest exponent with a non-zero coeficient.
	void polynomial::update_current_degree()
	{
		for (int i = MAXIMUM_DEGREE; i >= 0; --i)
		{	
			if (coef[i] != 0)
			{
				current_degree = i;
				return;
			}
		}
		current_degree = 0;
	}
    
    /*
     Create a polynomial with all zero coefficients.
     Except for coefficient c for the specified exponent.
     if used as a default constructor (using default values forboth arguments), 
     the result is a polynomial with all zero coefficients.
     */
	polynomial::polynomial(double c, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);

		for (unsigned int i  = 0; i <= MAXIMUM_DEGREE; ++i)
		{
			if (i == exponent)
			{
                //set the specified coefficient to c
				coef[i] = c;
			} else {
				coef[i] = 0;
			}
		}
		update_current_degree();
	}

    //Sets the coefficient for the specified exponent.
	void polynomial::assign_coef(double coefficient, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);

		coef[exponent] = coefficient;
		update_current_degree();
	}

    //Adds the given amount to the coefficient of the specified exponent.
	void polynomial::add_to_coef(double amount, unsigned int exponent)
	{
		assert(exponent <= MAXIMUM_DEGREE);

		coef[exponent] += amount;
		update_current_degree();
	}

    //Sets all the coefficient equal to zero
	void polynomial::clear()
	{
		for (unsigned int i = 0; i <= MAXIMUM_DEGREE; ++i)
		{
			coef[i] = 0;
		}
		update_current_degree();
	}

    //Calculates the integral of the current polynomial, stores it in a new polynomial and returns it.
	polynomial polynomial::antiderivative() const
	{
		assert(degree() < MAXIMUM_DEGREE);

		polynomial anti;

		for (unsigned int i = 0; i < MAXIMUM_DEGREE; ++i)
		{
			anti.coef[i + 1] = coef[i]/(i + 1);
		}
		anti.update_current_degree();

		return anti;
	}

    //Returns coefficient at specified exponent of this polynomial
	double polynomial::coefficient(unsigned int exponent) const
	{
		if (exponent <= MAXIMUM_DEGREE) {
			return coef[exponent];
		} else {
			return 0;
		}
	}

    //Returns the value of the definite integral computed from x0 to x1. Utilizes the eval() function.
	double polynomial::definite_integral(double x0, double x1) const
	{
		polynomial anti = antiderivative();

		return anti.eval(x1) - anti.eval(x0);
	}
    
    //Calculates and returns the first derivative of this polynomial
	polynomial polynomial::derivative() const
	{
		polynomial deriv;

		for (unsigned int i = 0; i < MAXIMUM_DEGREE; ++i)
		{
			deriv.coef[i] = coef[i+1] * (i + 1);
		}

		return deriv;
	}

    //Calculates and returns the value of this polynomial with the given value for the variable x.
	double polynomial::eval(double x) const
	{
		double solution = 0;

		for (unsigned int i = 0; i <= MAXIMUM_DEGREE; ++i)
		{
            //Add the result of x evaluated at all instances of this polynomial
			solution += coef[i]*pow(x, i);
		}

		return solution;
	}

    //Determines wheather this is a zero polynomial (if it has any nonzero coefficient)
	bool polynomial::is_zero() const
	{
		for (unsigned int i = 0; i <= MAXIMUM_DEGREE; ++i)
		{
			if (coef[i] != 0) return false;
		}
		return true;
	}
    
    /*
     The return value is the next exponent n which is LARGER than e such that coefficient(n) != 0.
     If there is no such term, then the return value is zero.
     */
	unsigned int polynomial::next_term(unsigned int e) const
	{
		for (unsigned int i = e + 1; i <= MAXIMUM_DEGREE; ++i)
		{
			if (coef[i] != 0) return i;
		}
		return 0;
	}

    /*
     The return value is the previous exponent n which is SMALLER than e such that coefficient(n) != 0.
     If there is no such term, then the return value is zero.
     */
	unsigned polynomial::previous_term(unsigned int e) const
	{
		for (int i = e - 1; i >= 0; --i)
		{
			if (coef[i] != 0) return i;
		}

		return UINT_MAX;
	}

    //returns a third polynomial with each coefficient equal to the sum of the coefficients of p1 & p2.
	polynomial operator +(const polynomial& p1, const polynomial& p2)
	{
		polynomial p3;
        
        //using the scope operator on MAXIMUM_DEGREE to show that the variable belongs to the polynomial class
		for (unsigned int i = 0; i <= polynomial::MAXIMUM_DEGREE; ++i)
		{
			p3.add_to_coef(p1.coefficient(i) + p2.coefficient(i), i);
		}

		return p3;
	}

    //returns a third polynomial with each coefficient equal to the difference of the coefficients of p1 & p2.
	polynomial operator -(const polynomial& p1, const polynomial& p2)
	{
		polynomial p3;

		for (unsigned int i = 0; i <= polynomial::MAXIMUM_DEGREE; ++i)
		{
			p3.add_to_coef(p1.coefficient(i) - p2.coefficient(i), i);
		}

		return p3;
	}

    
    //Each term of p1 has been multiplied by each term of p2, and the answer is the sum of all these products.
	polynomial operator *(const polynomial& p1, const polynomial& p2)
	{
		assert(p1.degree() + p2.degree() <= polynomial::MAXIMUM_DEGREE);
		
		polynomial p3;
        //double loop to multiply each components of p1 by p2
		for (unsigned int i = 0; i <= polynomial::MAXIMUM_DEGREE / 2; ++i)
		{
			for (unsigned int j = 0; j <= polynomial::MAXIMUM_DEGREE / 2; ++j)
			{
				p3.add_to_coef(p1.coefficient(i) * p2.coefficient(j), i + j);
			}
		}

		return p3;
	}

	ostream& operator << (ostream& out, const polynomial& p)
	{
	
		// Set precision for coefficients
		out << setprecision(2);

		// Largest degree term is printed first, outside of the loop
		// since the sign is printed differently than the rest of the terms
		double coef = p.coefficient(p.degree());
		
		if (coef != 0) // Polynomial has terms
		{	
			if (coef < 0) out << "-"; // Negative sign
			if (abs(coef) > 1) // coefficient is only printed if not 1
			{
				out << abs(coef);
			} 
			if (p.degree() > 1) out << "x^" << p.degree() << " "; // print with exponent
			else if (p.degree() == 1) out << "x "; // if exponent is 1 don't print exponent
		}
		else
		{
			out << 0; // Print 0 if polynomial is empty
		}
		
		// Print the rest of the terms
		for (int i = p.degree() - 1; i >= 0; --i)
		{
			coef = p.coefficient(i);
			if (coef != 0) // only print nonzero terms
			{
				// print addition/subtraction operators
				if (coef > 0)
				{
					out << "+ ";
				}
				else
				{
					out << "- ";
				}

				// don't print x or exponent for constant values
				if (i != 0)
				{
					if(abs(coef) > 1) out << abs(coef);
					out << "x";

					if (i > 1) out << "^" << i;
				}
				// print constant value
				else
				{
					out << coef;
				}
				out << " ";
			}
		}
		return out;
	}
}
		
