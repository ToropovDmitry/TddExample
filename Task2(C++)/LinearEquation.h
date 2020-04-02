#pragma once
#include<vector>
#include<string>
#include<list>

class LinearEquation
{
private:
	std::vector<double> coefficients;
	std::vector<std::string> resplit(const std::string&, std::string);

public:
	LinearEquation(std::string coeff);
	LinearEquation(std::list<double>);
	LinearEquation(std::vector<double>);
	LinearEquation(int n);
	~LinearEquation() { std::vector<double>().swap(coefficients); };
	int size() { return coefficients.size(); }
	void random_initialization();
	void same_initialization(double);
	bool isNull();
	double& operator[] (int index);
	LinearEquation operator+(LinearEquation&);
	LinearEquation operator-(LinearEquation&);
	LinearEquation operator-();
	operator std::string();
	operator bool();
	operator std::list<double>();
	LinearEquation operator*(const double&);	
	friend LinearEquation operator*(double, LinearEquation&);
};

bool operator==(LinearEquation&, LinearEquation&);
bool operator!=(LinearEquation&, LinearEquation&);
