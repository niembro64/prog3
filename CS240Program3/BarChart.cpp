////////////////////////////
// Program 3
// Eric Niemeyer (800037756)
// CS240-003 Klein
////////////////////////////

#include "BarChart.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

int BarChart::barChartNumOfBarCharts = 0;

BarChart::BarChart() 
{
	barChartNumOfBarCharts++;
}

BarChart::~BarChart() 
{
	barChartNumOfBarCharts++;
}

void BarChart::setElementHeights() 
{
	for (int i = 0; i < getChartNumOfElements(); i++) 
	{
		elementHeights[i] = (int) (elementRatios[i] * 20);
	}
}


void BarChart::displayChart()
{
	calcPercents();
	calcRatios();
	barprint();
	printStats();
}

void BarChart::barprint() 
{
	int MAXPARAM = 22;

	// grid for storing wrong chart to use for the right chart
	char grid[22][22];

	// initialize grid to spaces
	for (int i = 0; i < MAXPARAM; i++)
	{
		for (int j = 0; j < MAXPARAM; j++)
		{
			grid[i][j] = ' ';
		}
	}

	// populate grid
	for (int i = 0; i < chartNumOfElements; i++)
	{
		grid[2 * i][0] = '-';
		grid[(2 * i) + 1][0] = '-';
		for (int j = 0; j < elementRatios[i]*20; j++)
		{
			grid[2 * i][j+1] = ' ';
			grid[(2 * i) + 1][j+1] = GLYPH[i];
		}
		grid[2 * i][MAXPARAM-1] = '-';
		grid[(2 * i) + 1][MAXPARAM-1] = '-';
	}
	grid[chartNumOfElements*2][0] = '-';
	grid[chartNumOfElements*2][MAXPARAM-1] = '-';
	
	cout << endl;

	// print grid transposed
	for (int i = 0; i < MAXPARAM; i++)
	{
		cout << "            ";
		for (int j = 0; j < MAXPARAM; j++)
		{
			cout << grid[j][(MAXPARAM-1)-i];
		}
		cout << endl;
	}
}