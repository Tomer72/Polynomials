#include <iostream>
#include "Rational.h"

// Setting the nom to be 0 and the denom to be 1.
Rational::Rational() : nom(), denom(0) {
	this->denom.setCoeff(0, 1);
}

// With 2 polynomials given, setting the nom to be p1 and denom to be p2 accordingly.
Rational::Rational(const Polynomial& p1, const Polynomial& p2) {

	this->nom = p1; 
	this->denom = p2;

}

// Returning nom.
Polynomial& Rational::getNom() {

	return this->nom;
}

// Returning denom.
Polynomial& Rational::getDenom() {

	return this->denom;
}

// Printing the rational fraction.

void Rational::print() {

	this->nom.print();
	cout << "--------------------------" << endl;
	this->denom.print();
}
