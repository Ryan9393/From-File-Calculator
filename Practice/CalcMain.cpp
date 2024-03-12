/*
Ryan McCarthy

Description: create a calculator that takes string inputs
from a file and performs orders of operation

*/

#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string problem, string delimiter);
void multiplcation(vector<string>& Vec, int pos);
void division(vector<string>& Vec, int pos);
void addition(vector<string>& Vec, int pos);
void subtraction(vector<string>& Vec, int pos);


int main() {

	//open file
	ifstream inFile("problems.txt");


	//check if file is open
	if (!inFile) {
		cout << "file opening failed";
		return 1;
	}



	//while not end of file
	while (!inFile.eof()) {

		string problemString;

		getline(inFile, problemString);

		cout << problemString << endl;

		vector<string> problemVector = split(problemString, " ");

		//find position of multiplication/division symbol if not found = size+1
		int containMultiplication = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "*"));
		int containDivision = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "/"));

		while (containMultiplication < problemVector.size() || containDivision < problemVector.size()) {

			if (containMultiplication < problemVector.size() || containDivision < problemVector.size()) {

				//less than position comes first and is then called first
				if (containMultiplication < containDivision) {
					cout << "multiplciation" << endl;
					multiplcation(problemVector, containMultiplication);
				}
				else {
					cout << "division" << endl;
					division(problemVector, containDivision);
				}
			}

			//update positions
			containMultiplication = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "*"));
			containDivision = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "/"));

		}

		//find position of addition/subtraction symbol if not found = size+1
		int containAddition = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "+"));
		int containSubtraction = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "-"));

		while (containAddition < problemVector.size() || containSubtraction < problemVector.size()) {

			if (containAddition < problemVector.size() || containSubtraction < problemVector.size()) {

				//less than position comes first and is then called first
				if (containAddition < containSubtraction) {
					cout << "addition" << endl;
					addition(problemVector, containAddition);
				}
				else {
					cout << "subtraction" << endl;
					subtraction(problemVector, containSubtraction);
				}
			}

			//update positions
			containAddition = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "+"));
			containSubtraction = distance(problemVector.begin(), find(problemVector.begin(), problemVector.end(), "-"));

		}

		cout << "Answer = " << problemVector[0] << endl;
	
	}

	return 0;
}

vector<string> split(string problem, string delimiter) {

	vector<string> V;
	size_t pos = 0;
	string token;

	//split problem string into an array along delimiter
	while ((pos = problem.find(delimiter)) != string::npos) {
		token = (problem.substr(0, pos));
		V.push_back(token);
		problem.erase(0, pos + delimiter.length());
	}
	//Append the last part of string to vector
	V.push_back(problem);
	
	return V;
}

//multiply two numbers adjacent to pos
void multiplcation(vector<string>& Vec, int pos) {
	double num1 = stod(Vec[pos - 1]);
	double num2 = stod(Vec[pos + 1]);

	num1 = num1 * num2;

	Vec[pos] = to_string(num1);

	//remove "used" values
	Vec.erase(Vec.begin() + pos - 1);
	Vec.erase(Vec.begin() + pos);

}

//divide two numbers adjacent to pos
void division(vector<string>& Vec, int pos) {
	double num1 = stod(Vec[pos - 1]);
	double num2 = stod(Vec[pos + 1]);

	num1 = num1 / num2;

	Vec[pos] = to_string(num1);

	//remove "used" values
	Vec.erase(Vec.begin() + pos - 1);
	Vec.erase(Vec.begin() + pos);

}

//add two numbers adjacent to pos
void addition(vector<string>& Vec, int pos) {
	double num1 = stod(Vec[pos - 1]);
	double num2 = stod(Vec[pos + 1]);

	num1 = num1 + num2;

	Vec[pos] = to_string(num1);

	//remove "used" values
	Vec.erase(Vec.begin() + pos - 1);
	Vec.erase(Vec.begin() + pos);

}

//subtract two numbers adjacent to pos
void subtraction(vector<string>& Vec, int pos) {
	double num1 = stod(Vec[pos - 1]);
	double num2 = stod(Vec[pos + 1]);

	num1 = num1 - num2;

	Vec[pos] = to_string(num1);

	//remove "used" values
	Vec.erase(Vec.begin() + pos - 1);
	Vec.erase(Vec.begin() + pos);

}