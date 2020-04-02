#include "stdafx.h"
#include "SystemOfLinearEquation.h"


LinearEquation& SystemOfLinearEquation::operator[](int index)
{
	if (index >= 0 && index < system.size())
		return system[index];
	else throw std::out_of_range("Out of range!");
}

int SystemOfLinearEquation::size()
{
	return system.size();
}

void SystemOfLinearEquation::add(LinearEquation& a)
{
	if (a.size() == n + 1)
		system.push_back(a);
	else throw std::invalid_argument("Invalid argument!");
}

void SystemOfLinearEquation::remove()
{
	system.pop_back();
}

void SystemOfLinearEquation::steppingUp()
{
	int c, z;
	for (int i = 0; i < size(); i++)
	{
		z = i;
		if (system[i][z] == 0)
		{
			while (system[i][z] == 0 && z < n) z++;
			c = 1;
			while ((i + c) < size() && system[i + c][z] == 0) c++;
			if ((i + c) == size())			
				return;			
			std::swap(system[i], system[i + c]);
		}
		for (int j = i + 1; j < size(); j++)
		{
			LinearEquation tmp1 = system[j] * system[i][z];
			LinearEquation tmp2 = system[i] * system[j][z];
			system[j] = tmp1 - tmp2;
		}
	}
}

std::vector<double> SystemOfLinearEquation::solveSystem()
{
	while (system[size() - 1].isNull())
		system.pop_back();
	if (system[size() - 1])
	{
		if (size() == n)
		{
			std::vector<double> solve(n);
			for (int i = size() - 1; i >= 0; i--)
			{
				solve[i] = system[i][n];
				for (int j = i + 1; j < n; j++)				
					solve[i] -= system[i][j] * solve[j];				
				solve[i] /= system[i][i];
			}
			return solve;
		}
		else throw std::invalid_argument("The system has infinitely many solutions!");
	}
	else throw std::invalid_argument("The system has no solutions!");
}

SystemOfLinearEquation::operator std::string()
{
	std::string res = "";
	for (int i = 0; i < size(); i++)
		res += (std::string)system[i] + '\n';
	return res;
}
