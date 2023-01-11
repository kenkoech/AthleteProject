#include "Athlete.h"

Athlete::Athlete()
{
	jerseyNumber = 0;
}

Athlete::Athlete(string name, int num)
{
	this->name = name;
	this->jerseyNumber = num;
}

Athlete::Athlete(int num, string name, string position, string year, string height, string hometown)
{
	this->jerseyNumber = num;
	this->name = name;
	this->position = position;
	this->year = year;
	this->height = height;
	this->hometown = hometown;
}

void Athlete::setJerseyNumber(int& num)
{
	this->jerseyNumber = num;
}

void Athlete::setName(string& name)
{
	this->name = name;
}

void Athlete::setPosition(string& pos)
{
	this->position = pos;
}

void Athlete::setYear(string& year)
{
	this->year = year;
}

void Athlete::setHeight(string& height)
{
	this->height = height;
}


void Athlete::setHometown(string& hometown)
{
	this->hometown = hometown;
}

int Athlete::getJerseyNumber() const
{
	return jerseyNumber;
}

string Athlete::getName() const
{
	return name;
}

string Athlete::getPosition() const
{
	return position;
}

string Athlete::getYear() const
{
	return year;
}

string Athlete::getHeight() const
{
	return height;
}

string Athlete::getHometown() const
{
	return hometown;
}
