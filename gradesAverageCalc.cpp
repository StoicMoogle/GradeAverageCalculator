#include<iostream>
#include<fstream>
#include<cstdlib>
#include<iomanip>
#include<string>

using namespace std;


int main() {
	double next;
	int count = 0;
	double sum = 0;
	char choice;

	cout << "Welcome to the number-grades average calculator." << endl;
	do {
		cout << "To enter the grades manually, enter 1. To enter grades from a file, enter 2." << endl;
		cin >> choice;
		if (choice != '1' && choice != '2') {
			cout << "That is an invalid input" << endl;
		}
	} while (choice != '1' && choice != '2');


	if (choice == '1') {
		cout << "Enter all grades, then hit enter." << endl;
		while (cin >> next && next != '\n') {
				sum += next;
				count++;
		}
	}

	else if (choice == '2') {
		ifstream input_grade;
		string fileName;

		cout << "Enter the name of the file that you want to read your grades from." << endl;
		cin >> fileName;
		input_grade.open(fileName);
		if (input_grade.fail()) {
			cout << "Filename open failed!" << endl;
			exit(1);
		}

		while (input_grade >> next && next != '\n') {
			sum += next;
			count++;
		}
	}

	cout << "The total amount is " << sum << " and its average is " << (sum / count) << endl;
	char ans;
	do {
		cout << "Print results to a file? Y/N" << endl;
		cin >> ans;
		if (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n') {
			cout << "This is not a valid answer." << endl;
		}

	} while (ans != 'Y' && ans != 'y' && ans != 'N' && ans != 'n');

	if (ans == 'Y' || ans == 'y') {
		ofstream grades_output;
		string outputFile;
		cout << "Name the file to print the results on: ";
		cin >> outputFile;

		grades_output.open(outputFile);
		grades_output << "The total amount is " << sum << " and its average is " << (sum / count) << endl;
	}
	cout << "Thanks for using!" << endl;
	return 0;
}



