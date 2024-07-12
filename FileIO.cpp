/*
*FileIO.cpp
* Created by:bhdur
*Jul 11, 2024
*6:44:31 PM
*/
#include <iostream>
#include <fstream>

using namespace std;

int main()
{

	fstream fio;
	string line;

	fio.open("CSC450_CT5_mod5.txt", ios::app | ios::out | ios::in);

	cout << "Enter your text. Enter '-1' to exit..." << endl;

	while(fio)
	{
		//read line from input
		getline(cin, line);

		if(line == "-1")
			break;

		//Write line to file
		fio << line << endl;

	}

	//point read pointer to beginning of file
	fio.seekg(0, ios::beg);

	while(fio)
	{
		//read line from file
		getline(fio, line);

		//Print line
		cout << line << endl;
	}

	//Close file
	fio.close();


	return 0;
}
