////////////////////////////
// Program 3
// Eric Niemeyer (800037756)
// CS240-003 Klein
////////////////////////////

#pragma once

#include "Chart.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

const int MAXRADIUS = 8;             // Pie chart radius (in characters)
const double PI = 3.141592653589793; // Extremely precise approximation


class PieChart : public Chart 
{
private:

public:
	static int pieChartNumOfPieCharts;
	double angleSoFar = 0;

	PieChart();
	~PieChart();

	void displayChart();
	void pieprint();
	void calculate(double tot, double stgTot, double &pct, double &ang);
	void outputPie(double angle[]);
};

