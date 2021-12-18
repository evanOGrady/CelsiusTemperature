#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int main() 
{
	ifstream file("FahrenheitTemperature.txt"); // Get the original file
	ofstream newFile; // Creat the variable for the new file that will be written to
	newFile.open("CelsiusTemperature.txt"); // Open the new file
	vector<string> names; // Create the vector that will store the conten from the original file
	string firstPart; // The first delimeter from the string
	string secondPart; // The second delimeter from the string

	string input; // string to store the lines from the original text file
	while (getline(file, input)) {
		firstPart = input.substr(0, input.find(' ')); // Split the string. Store the first part in firstPart
		secondPart = input.substr(input.find_first_of(' ') + 1); // Store the second part in secondPart

		int degree = stoi(secondPart); // Convert the secondPart to an int
		degree = (degree - 32); // Subtract the degree by 32
		degree = degree * 5; // Multiply the degree by 5
		degree = degree / 9; // Divide the degree by 9

		string celsius = to_string(degree); // Convert degree back to a string
		names.push_back(firstPart + " " + celsius); // Enter the town name, a space, and the temperature in celsius
	}

	for (string name : names) {
		cout << name << endl; // Display the town and temperature in celsius on the console
		newFile << name << endl; // Write the town and temperature in celsius in the text file
	}

	newFile.close(); // Close the newFile
	return 0;
}