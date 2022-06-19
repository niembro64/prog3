////////////////////////////
// Program 3
// Eric Niemeyer (800037756)
// CS240-003 Klein
////////////////////////////

#include "Chart.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

int Chart::chartNumOfCharts = 0;

Chart::Chart() 
{
	chartNumOfCharts++;
}

Chart::~Chart() 
{
	chartNumOfCharts--;
}


// setters
void Chart::setChartTypeOfChart(const char c)
{
	chartTypeOfChart = c;
}
void Chart::setChartNumOfElements(const int i)
{
	chartNumOfElements = i;
}
void Chart::setElementNames(const string names[]) 
{
	for (int i = 0; i < getChartNumOfElements(); i++) 
	{
		Categories[i].elementName = names[i];
	}
}
void Chart::setElementValues(const double values[]) 
{
	for (int i = 0; i < getChartNumOfElements(); i++) 
	{
		Categories[i].elementValue = values[i];
	}
}
void Chart::setElementRatios(const double ratios[]) 
{
	for (int i = 0; i < getChartNumOfElements(); i++) 
	{
		elementRatios[i] = ratios[i];
	}
}




// getters
int	Chart::getNumberOfCharts()
{
	return chartNumOfCharts;
}
char Chart::getChartTypeOfChart() 
{
	return chartTypeOfChart;
}
int Chart::getChartNumOfElements() 
{
	return chartNumOfElements;
}
string Chart::getElementName(int i) 
{
	return Categories[i].elementName;
}
double Chart::getElementValue(int i)
{
	return Categories[i].elementValue;
}
double Chart::getElementRatio(int i) 
{
	return elementRatios[i];
}



// calculators
void Chart::calcRatios() 
{

	double max = 0;

	// find max
	for (int i = 0; i < chartNumOfElements; i++) 
	{
		if (max < Categories[i].elementValue)
			max = Categories[i].elementValue;
	}

	// find each ratio
	for (int j = 0; j < chartNumOfElements; j++) 
	{
		elementRatios[j] = (Categories[j].elementValue / max);
	}

}

void Chart::calcPercents() 
{

	double total = 0;

	// find total
	for (int i = 0; i < chartNumOfElements; i++) 
	{
		total = total + Categories[i].elementValue;
	}

	// find each percent
	for (int j = 0; j < chartNumOfElements; j++) 
	{
		elementPercents[j] = (Categories[j].elementValue / total);
	}

}

void Chart::addNewCategory(string name, double value)
{
	setChartNumOfElements(getChartNumOfElements() + 1);
	Categories[getChartNumOfElements()-1].elementName = name;
	Categories[getChartNumOfElements()-1].elementValue = value;
	calcRatios();
	calcPercents();
}


void Chart::displayChart()
{
	// pure virtual
}

void Chart::printStats() 
{
	for (int i = 0; i < chartNumOfElements; i++) 
	{
		cout << "       " << GLYPH[i] << " -";

		for (int j = 0; j < 17 - (int)(Categories[i].elementName.size()); j++)
			cout << " ";

		cout << Categories[i].elementName << " : " << ((elementPercents[i]<.1) ? " " :"" );
		cout << fixed << setprecision(3) << elementPercents[i]*100 << "%" << " ";
		
		int b; 
		int mult = 1;
		for (int a = 0; a < 10; a++)
		{
			b = a; 
			while (b)
			{
				mult = mult * 10;
				b--;
			}
			if (Categories[i].elementValue < (mult))
				cout << " ";
		}

		cout << Categories[i].elementValue;
		cout << endl;
	}
	cout << "------------------------------------------------";

}

