////////////////////////////
// Program 3
// Eric Niemeyer (800037756)
// CS240-003 Klein
////////////////////////////

#include "Chart.h"
#include "BarChart.h"
#include "PieChart.h"

#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <string>
#include <sstream>
#include <cassert>

using namespace std;

const int MAXDATA = 230;
typedef Chart* chartPtr;

void splash();
void printMainOptions(chartPtr x[]);
char getOption(chartPtr x[]);
void doAnOption(chartPtr myCharts[], char choice);
void viewAChart(chartPtr myCharts[]);
void addACategory(chartPtr myCharts[]);


void main() 
{
	splash();

	////////////////// reading file and storing //////////////////
	ifstream inFile;
	inFile.open("ChartData.txt");

	if (inFile.fail()) 
	{
		cerr << "INPUT KAPUT.";
		system("pause");
		exit(1);
	}

	string allInitialData[MAXDATA]; // all stuff
	int numData = 0;

	// all data into allData (lines stored as strings)
	while (getline(inFile, allInitialData[numData])) 
		numData++;

	// temp vars to store data
	int		numOfCharts = 0;
	char	chartType[MAXEAC] = {};				// holding chart type
	int		numOfElements[MAXEAC] = {};			// holding num of elem
	string	elementName[MAXEAC][MAXEAC] = {};	// holding elem names
	double	elementValue[MAXEAC][MAXEAC] = {};	// holding elem values

	numData = 0;

	// reading from massive data dump array "all initial data"
	for (int i = 0; i < MAXEAC; i++) 
	{
		chartType[i] = allInitialData[numData][0];					// string to char
		numData++;

		if (chartType[i] != 0)
			numOfCharts++;

		stringstream stringToInt(allInitialData[numData]);			// string to int
		stringToInt >> numOfElements[i];
		numData++;

		for (int j = 0; j < numOfElements[i]; j++) 
		{

			elementName[i][j] = allInitialData[numData];			// string to string
			numData++;

			stringstream stringToDouble(allInitialData[numData]);	// string to double
			stringToDouble >> elementValue[i][j];
			numData++;
		}
		numData++; // skip the extra newline
	}


	////////////////// making and populting charts that were in file //////////////////
	Chart* myCharts[10];
	for (int i = 0; i < numOfCharts; i++) 
	{
		if (chartType[i] == 'P') 
		{
			myCharts[i] = new PieChart;
			myCharts[i]->setChartTypeOfChart('P');
			myCharts[i]->setChartNumOfElements(numOfElements[i]);
			for (int j = 0; j < numOfElements[i]; j++) 
			{
				myCharts[i]->setElementNames(elementName[i]);
				myCharts[i]->setElementValues(elementValue[i]);
			}
		} 
		else if (chartType[i] == 'B') 
		{
			myCharts[i] = new BarChart;
			myCharts[i]->setChartTypeOfChart('B');
			myCharts[i]->setChartNumOfElements(numOfElements[i]);
			for (int k = 0; k < numOfElements[i]; k++) 
			{
				myCharts[i]->setElementNames(elementName[i]);
				myCharts[i]->setElementValues(elementValue[i]);
			}
		} 
		else assert(false);
	}

	////////////////// printing options and charts //////////////////
	char choice = getOption(myCharts);
	while (choice != 'Q' && choice != 'q')
	{
		doAnOption(myCharts, choice);
		choice = getOption(myCharts);
	}


	// printing charts
	for (int i = 0; i < myCharts[0]->getNumberOfCharts(); i++)
	{
		cout << *(myCharts[i]) << endl;
	}

	
	system("pause");
}// end main

void splash()
{
cout << "                   Welcome to the charting program!" << endl << endl;
}

void printMainOptions(chartPtr x[])
{
	cout << "There are " << x[0]->getNumberOfCharts() << " charts." << endl;
	cout << "What would you like to do?" << endl;
	cout << "V)iew a chart" << endl;
	cout << "A)dd a category to a chart" << endl;
	cout << "Q)uit" << endl;
	cout << "?: ";
}

char getOption(chartPtr x[])
{
	char option;
	printMainOptions(x);
		cin >> option;
		while (option != 'Q' && option != 'q' && option != 'V' && option != 'v' &&option != 'A' && option != 'a')
		{
			cout << endl << endl << "*** '";
			cout << option << "' is not a listed choice. Try again. ***" << endl << endl;
			printMainOptions(x);
			cin >> option;
		}
	return option;
}

void doAnOption(chartPtr myCharts[], char choice)
{
	if (choice == 'v' || choice == 'V')
	{
		viewAChart(myCharts);

	}
	else if (choice == 'a' || choice == 'A')
	{
		addACategory(myCharts);
	}
}

void viewAChart(chartPtr myCharts[])
{
	int desire;
	cout << "Which chart would you like? (1..";
	cout << myCharts[0]->getNumberOfCharts() << "): ";
	cin >> desire;

	while (desire < 1 || desire > myCharts[0]->getNumberOfCharts())
	{
		cout << "Out of range. Choose another: (1..";
		cout << myCharts[0]->getNumberOfCharts() << "): ";
		cin >> desire;
	}

	cout << *myCharts[desire-1] << endl;
}

void addACategory(chartPtr myCharts[])
{
	int scelta;
	cout << "Which chart would you like? (1..";
	cout << myCharts[0]->getNumberOfCharts() << "): ";
	cin >> scelta;

	while (scelta < 1 || scelta > myCharts[0]->getNumberOfCharts())
	{
		cout << "Out of range. Choose another: (1..";
		cout << myCharts[0]->getNumberOfCharts() << "): ";
		cin >> scelta;
	}
	double caricareDue;
	string caricareUno;
	cout << "What is the title of the chart's new category? " ;
	cin >> caricareUno;
	cout << "What is the value of the chart's new category? ";
	cin >> caricareDue;

	// add new element
	// populate new element

	myCharts[scelta-1]->addNewCategory(caricareUno, caricareDue);
	cout << "New category added." << endl;
	cout << *myCharts[scelta - 1] << endl;
}
