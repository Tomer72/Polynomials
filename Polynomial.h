#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

using namespace std;

class Polynomial {

private:

	double* coeff;
	int degree;
	static int maxDegree;

public:

	// Constructors
	Polynomial();
	Polynomial(int);
	Polynomial(double*, int);
	Polynomial(const Polynomial&);

	// Destructor
	~Polynomial();

	//Getters and setters
	Polynomial& setCoeff(int, double);
	double getCoeff(int) const;
	int getDegree(bool) const;
	int getDegree() const;
	static int getMaxDegree();
	

	// Other member functions
	void print() const;
};

#endif
