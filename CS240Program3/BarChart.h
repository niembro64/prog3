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

class BarChart : public Chart 
{
private:

public:
	static int barChartNumOfBarCharts;

	int elementHeights[10];

	void setElementHeights();

	BarChart();
	~BarChart();

	void barprint();
	void displayChart();

};