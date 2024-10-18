#include <iostream>
#include "Polynomial.h"

int Polynomial::maxDegree = 0;

// Defualt constructor - setting the degree to 0 and coeff to 0.
Polynomial::Polynomial() : coeff(NULL), degree(0) {}

// Constructor with an input degree, callocing the new polynomial's coeffs.
Polynomial::Polynomial(int input) : degree(input) {

	int i;
	this->coeff = new double[input + 1];
	for (i = 0; i <= input; i++) {
		this->coeff[i] = 0;
	}
}

// Constructor with given array of coeffs and input degree.
Polynomial::Polynomial(double* arr, int input) : degree(input) {

	int i;
	this->coeff = new double[input + 1];

	// Copying the coeffs from the given array.
	for (i = 0; i <= input; i++) {
		this->coeff[i] = arr[i];
		if (arr[i] && i > maxDegree) { // Checking if we need to update the max degree.
			maxDegree = i;
		}
	}
}

// Copy constructor.
Polynomial::Polynomial(const Polynomial& p) {

	this->degree = p.degree;

	// Checking if the polynomial is 0.
	if (!p.coeff) {
		this->coeff = NULL;
	}
	else { 
		this->coeff = new double[this->degree + 1];
		for (int i = 0; i <= this->degree; i++) {
			this->coeff[i] = p.coeff[i];
		}
	}
}

// Destructor
Polynomial::~Polynomial() {

	if (this->coeff){ // Checking if different from 0.
		delete [] this->coeff;
		this->coeff = NULL;
	}
}

// Setting a coeff given by degree and number input.
Polynomial& Polynomial::setCoeff(int degree, double input) {

	this->coeff[degree] = input;
	return *this;
}

// Returning the coeff with a given input index.
double Polynomial::getCoeff(int index) const {

	// Checking the validity of the index given.
	if (index < 0) {
		return 123456;
	}
	if (index > this->degree) {
		return 123456;
	}

	// Everything is valid, returning the desired coeff.
	return this->coeff[index];

}

// By given a bool true or false input, we determine if we need to return the curr degree or if we need to check the last coeff who is different from zero and return it.
int Polynomial::getDegree(bool curr) const {

	if (!curr) {
		return this->degree;
	}
	else {
		return getDegree();
	}
}

// Getting the polynomial degree which the last coeff is different from 0.
int Polynomial::getDegree() const {

	int i, curr = 0;
	for (i = 0; i <= this->degree; i++) {
		if (this->coeff[i]) {
			curr = i;
		}
	}
	return curr;
}

// Returning max degree.
int Polynomial::getMaxDegree() {

	return maxDegree;
}

// Printing the polynomial.
void Polynomial::print() const {

	int i, max = 0;
	cout << "polynomial = ";

	// Checking if we need to print the 0 polynomial.
	if (!this->coeff && !this->degree) {
		cout << "0" << endl;
		return;
	}

	// Checking the last coeff that is different from 0 to determine the real degree.
	for (i = 0; i <= this->degree; i++) {
		if (this->coeff[i] && i > max) {
			max = i;
		}
	}
	for (i = 0; i <= max; i++) {
		if (i == 0) {
			if (!this->coeff[i]) {
				cout << "0";
			}
			else {
				cout << this->coeff[i];
			}
		}
		else {
			cout << "+";
			if (!this->coeff[i]) {
				cout << "0";
			}
			else {
				cout << this->coeff[i];
			}
			cout << "X^" << i;
		}
	}
	cout << endl;
}
