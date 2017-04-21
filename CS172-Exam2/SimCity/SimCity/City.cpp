//I affirm that all code given below was written solely by me, Kelsey Segren, and that any help 
//I received adhered to the rules stated for this exam.

#include "City.h"
#include "Citizen.h"
#include <fstream>
#include <vector>


//creates new city and restores the population from a file
City::City(string cityName) 
{
	_cityName = cityName;
	fstream infile(cityName + ".txt", ios::in);
	int id;
	string firstName, lastName, color;
	if (infile.is_open()) 
	{
		while (infile >> id >> firstName >> lastName >> color)
		{
			Citizen* s = new Citizen(id, firstName, lastName, color);
			citizenVec.push_back(s);

		}
	}
}

//destructor for the city, save population of city when city is destroyed
City::~City() 
{

	fstream outfile(_cityName, ios::out);
	if (outfile.is_open()) {
		for (int i = 0; i < citizenVec.size(); i++)
		{
			outfile << citizenVec[i]->getId() << " "
				<< citizenVec[i]->getFirstName() << " "
				<< citizenVec[i]->getLastName() <<  " " 
				<< citizenVec[i]->getFavoriteColor() << endl;
			delete citizenVec[i];
		}
	}
	else {
		for (int i = 0; i < citizenVec.size(); i++)
		{
			delete citizenVec[i];
		}
	}
}

//returns name of city
string City::getCityName() 
{
	return _cityName;
}

//returns population of city
int City::populationSize() 
{
	return _population;
}

//returns the citizen at a given index
Citizen* City::getCitizenAtIndex(int index) 
{
	if (index >= 0 && index < citizenVec.size()) {
		return citizenVec[index];
	}
	return NULL;
}

//adds a citizen to the city
void City::addCitizen(Citizen* citizen) 
{
	Citizen* s = new Citizen(citizen);
	citizenVec.push_back(s);
}

//returns citizen with a given id
Citizen* City::getCitizenWithId(int id) 
{
	for (int i = 0; i < citizenVec.size(); i++) {
		if (citizenVec[i]->getId() == id)
		{
			return citizenVec[i];
		}
	}
	return NULL;
}

//returns a vector if each citizen have that color as their given color
vector<Citizen*> City::getCitizensForFavoriteColor(string color)
{
	for (int i = 0; i < citizenVec.size(); i++) {
		citizenVec[i]->getFavoriteColor() == color;
		return vector<Citizen*>();
	}
}



