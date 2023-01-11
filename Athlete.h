//##############################################################################
// The Athlete Class is used to objects of type athlete

#pragma once
#include <string>
#include <ostream>
#include <vector>


using namespace std;
class Athlete
{
	int jerseyNumber;
	string name;
	string position;
	string year;
	string height;
	string hometown;
	vector<string> years{ "Fr.", "So.", "Jr.", "Sr." };
public:
	Athlete();
	Athlete(string, int);
	Athlete(int, string, string, string, string, string);
	void setJerseyNumber(int&);
	void setName(string&);
	void setPosition(string&);
	void setYear(string&);
	void setHeight(string&);
	void setHometown(string&);

	int getJerseyNumber() const;
	string getName() const;
	string getPosition() const;
	string getYear() const;
	string getHeight() const;
	string getHometown() const;


	friend ostream &operator<<(ostream& os, const Athlete& a) {
		os << a.jerseyNumber << "\t" << a.name << "\t" << a.position << "\t" << a.year << "\t" << a.height << "\t" << a.hometown << "\t";
		return os;
	}

	bool operator>(Athlete& a) {
		if (jerseyNumber > a.jerseyNumber) {
			return true;
		}
		else {
			return false;
		}
	}
	bool operator<(Athlete& a) {
		if (jerseyNumber < a.jerseyNumber) {
			return true;
		}
		else {
			return false;
		}
	}

	bool operator==(Athlete& a) {
		if (jerseyNumber == a.jerseyNumber)
			return true;
		else
			return false;
	}

	bool operator==(int x) {
		if (jerseyNumber == x) {
			return true;
		}
		else
			return false;
	}bool operator<(int x) {
		if (jerseyNumber < x) {
			return true;
		}
		else
			return false;
	}bool operator>(int x) {
		if (jerseyNumber > x) {
			return true;
		}
		else
			return false;
	}bool operator>=(Athlete&a ) {
		if (jerseyNumber >= a.jerseyNumber) {
			return true;
		}
		else
			return false;
	}

	//Athlete operator=(Athlete& a) {
	//	jerseyNumber = a.jerseyNumber;
	//	name = a.name;
	//	position = a.position;
	//	year = a.year;
	//	height = a.height;
	//	hometown = a.hometown;
	//}
	string operator ++(int a) {
		return years[a + 2];
	}
};

