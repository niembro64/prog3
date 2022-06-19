////////////////////////////
// Program 3
// Eric Niemeyer (800037756)
// CS240-003 Klein
////////////////////////////

#include "PieChart.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

int PieChart::pieChartNumOfPieCharts = 0;

PieChart::PieChart() 
{
	pieChartNumOfPieCharts++;
}

PieChart::~PieChart() 
{
	pieChartNumOfPieCharts--;
}

void PieChart::displayChart()
{
	calcPercents();
	calcRatios();
	pieprint();
	printStats();

}

// output piechart stuff
void PieChart::pieprint()
{
	const int MAXEAC = 10;

	// int		surveyTotal[MAXEAC];			// 0, 1, 2, 3
	double	stoogeTotal = 0.0;			// number of respondents
	double	surveyPercent[MAXEAC];		// percent respondents
	double	surveyAngle[MAXEAC] = { 0 };			// angle in radians 

	for (int i = 0; i < chartNumOfElements; i++)
	{
		stoogeTotal = stoogeTotal + Categories[i].elementValue;
	}

	angleSoFar = 0;

	for (int i = 0; i < chartNumOfElements; i++)
		calculate(Categories[i].elementValue, stoogeTotal, surveyPercent[i], surveyAngle[i]);

	outputPie(surveyAngle);
}

void PieChart::calculate(double tot, double stgTot, double &pct, double &ang)
{

	pct = tot / stgTot;
	ang = angleSoFar + 2 * PI * pct;
	angleSoFar = ang;
	return;
}

void PieChart::outputPie(double angle[])
{
	int x,                       // The horizontal and vertical coordinates
		y;                       // of the pie chart point being considered.
	double distanceFromCenter;   // The distance (in characters) from the
								 // pie chart's center to the point which
								 // is currently being considered.
	double currentAngle;         // The angle (in radians) formed by the three
								 // points: the point at the top of the pie
								 // chart, the center of the pie chart, and the
								 // point which is currently being considered.
	cout << endl;
	for (y = MAXRADIUS; y >= -MAXRADIUS; y--)
	{
		cout << '\t';
		
		
		
		
		
		
		
		// printing a line of the pie
		for (x = int(-1.5*MAXRADIUS); x <= int(1.5*MAXRADIUS); x++)
		{
			distanceFromCenter = sqrt((2.0*x / 3.0) * (2.0*x / 3.0) + y * y);
			if (distanceFromCenter > MAXRADIUS)
				cout << ' ';
			else
			{
				currentAngle = atan2(2.0*x / 3.0, y); // atan2 returns arctan of 2x/3y
				if (currentAngle < 0)               // (adjusting if y=0); 2*PI may be
					currentAngle += 2 * PI;          // added to yield angles in [0,2*PI].
				
				if (currentAngle <= angle[0])
					cout << GLYPH[0];
				else if (currentAngle <= angle[1])
					cout << GLYPH[1];
				else if (currentAngle <= angle[2])
					cout << GLYPH[2];
				else if (currentAngle <= angle[3])
					cout << GLYPH[3];
				else 
					cout << GLYPH[4];
			}
		}
		cout << endl;
	}
	return;
}