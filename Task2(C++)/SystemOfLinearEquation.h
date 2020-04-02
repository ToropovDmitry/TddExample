#pragma once
#include"LinearEquation.h"

class SystemOfLinearEquation
{
private:
	std::vector<LinearEquation> system;
	int n;
public:
	SystemOfLinearEquation(int _n) :n(_n) {}
	~SystemOfLinearEquation() { std::vector<LinearEquation>().swap(system); }
	LinearEquation& operator[] (int index);
	int size();
	void add(LinearEquation&);
	void remove();
	void steppingUp();
	std::vector<double> solveSystem();
	operator std::string();
};

