/*
*FileIO.cpp
* Created by:bhdur
*Jul 11, 2024
*6:44:31 PM
*/
#include <iostream>
#include <fstream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

string reverse_text(const string& filename)
{
	string content;
	stringstream buffer;
	stack<char> stack;

	ifstream file(filename);

	if(!file.is_open())
	{
		cerr << "Unable to open file" << endl;
		return "";
	}

	//Read entire file into a stringstream
	buffer << file.rdbuf();

	//Convert stringstream into a string
	content = buffer.str();

	//Read each character in content and add to stack;
	for(char c : content)
	{
		stack.push(c);
	}

	//Clear content string
	content.clear();

	//Add characters from stack in reverse order
	while(!stack.empty())
	{
		content.push_back(stack.top());
		stack.pop();
	}

	return content;
}

int main()
{

	fstream fio;
	string line;
	string inputFile = "CSC450_CT5_mod5.txt";
	string reversedFile = "CSC450_CT5_mod5_reverse.txt";

	fio.open(inputFile, ios::in | ios::out | ios::app);

	cout << "Enter your text. Enter '-1' to when complete..." << endl;

	if(!fio.is_open())
	{
		cerr << "Unable to open file" << endl;
		return 1;
	}

	//Loop for accepting user input until '-1' is entered
	while(true)
	{
		//Read line from input
		getline(cin, line);

		if(line == "-1")
			break;

		//Write line to file
		fio << line << endl;
	}

	//Point read pointer to beginning of file
	//Must use this between input and output, per SEI CERT C++
	fio.seekg(0, ios::beg);

	cout << "Contents of: " << inputFile << endl;

	//read line from file
	while(getline(fio, line))
	{
		//Print line
		cout << line << endl;
	}

	//Close file
	fio.close();
	cout << endl;

	string reversal;
	reversal = reverse_text(inputFile);

	ofstream reverse_fio(reversedFile);

	if(!reverse_fio.is_open())
	{
		cerr << "Unable to open file" << endl;
		return 1;
	}

	cout << "Saving Reversed file to: " << reversedFile << endl;

	reverse_fio << reversal;
	reverse_fio.close();

	//Open reversed file in input mode to display content
	ifstream reversed_input(reversedFile);

	if(!reversed_input.is_open())
	{
		cerr << "Unable to open file" << endl;
		return 1;
	}

	cout << "Reversed File Content: " << endl;

	//Print reverse file
	while(getline(reversed_input, line))
	{
		cout << line << endl;
	}
	//Close reverse file
	reversed_input.close();

	return 0;
}


