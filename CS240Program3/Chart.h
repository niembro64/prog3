////////////////////////////
// Program 3
// Eric Niemeyer (800037756)
// CS240-003 Klein
////////////////////////////

#pragma once

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

const char GLYPH[10] = { '@','$','%','#','*','&','!',':','?','/' };
const int MAXEAC = 10;

class Chart 
{
private:

protected:

	static int chartNumOfCharts;

	// chart info
	char chartTypeOfChart;
	int chartNumOfElements;

	// chart elements info
	struct cat
	{
		string elementName;
		double elementValue;
	};
	cat Categories[10];

		double elementRatios[10]; // related to top #
		double elementPercents[10]; // related to whole

public:

	// setters
	void setChartTypeOfChart	(const char c);
	void setChartNumOfElements	(const int i);
	void setElementNames		(const string names[]);
	void setElementValues		(const double values[]);
	void setElementRatios		(const double ratios[]);

	// getters
	int			getNumberOfCharts();
	char		getChartTypeOfChart();
	int			getChartNumOfElements();
	string		getElementName(int i);
	double		getElementValue(int i);
	double		getElementRatio(int i);

	void calcRatios();
	void calcPercents();

	void addNewCategory(string name, double value);

	Chart();
	~Chart();


	virtual void displayChart() = 0;

	friend ostream& operator<<(ostream& otherOP, Chart& otherC)
	{
		
		otherC.displayChart();
		return otherOP;
	}
	void printStats();
};

