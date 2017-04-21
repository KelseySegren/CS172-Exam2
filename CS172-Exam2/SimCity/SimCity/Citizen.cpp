//I affirm that all code given below was written solely by me, Kelsey Segren, and that any help 
//I received adhered to the rules stated for this exam.

#include "Citizen.h"


//constructor id, firstName, lastName, color
Citizen::Citizen(int id, string firstName, string lastName, string color) 
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_color = color;
}

//copies data from passed in citizen to a new citizen
Citizen::Citizen(Citizen* citizen) 
{
	if (citizen != NULL)
	{
		_id = citizen->getId();
		_firstName = citizen->getFirstName();
		_lastName = citizen->getLastName();
		_color = citizen->getFavoriteColor();
	}
}

//returns first name of citizen
string Citizen::getFirstName() 
{
	return _firstName;
}

//returns last name of citizen
string Citizen::getLastName() 
{
	return _lastName;
}

//returns id of citizen
int Citizen::getId() 
{
	return _id;
}

//returns favorite color of citizen
string Citizen::getFavoriteColor() 
{
	return _color;
}

//sets favorite color of citizen
void Citizen::setFavoriteColor(string color) 
{
	_color = color;
}
