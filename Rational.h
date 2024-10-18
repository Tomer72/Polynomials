#ifndef RATIONAL_H_
#define RATIONAL_H_

#include "Polynomial.h"

class Rational {

private:

	Polynomial nom, denom;

public:

	// Constructors
	Rational();
	Rational(const Polynomial&, const Polynomial&);

	// Getters
	Polynomial& getNom();
	Polynomial& getDenom();

	// Other member functions
	void print();
};

#endif

