#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <random>

using namespace std;

int RandomNumberGen() {
	string text;
    int random_number = rand();

	ifstream readFile("Book_database.txt");
	if (readFile.good()) {
		while (getline(readFile, text)) { // read eberyline in the file, checks if radndom nunmber is already exist
			if (text.find(to_string(random_number)) != string::npos) {
                random_number = rand();
            } else {
            	return random_number;
            }
        }
	}
	return 0;
}

void Get_Book(string book_name) {
	string text;

	ifstream readFile("Book_database.txt");
	if (readFile.good()) {
		while (getline(readFile, text)) {
			if (text.find(book_name) != string::npos) {
                cout << "Book: " << text << endl;
            }		
        }
	} else {
		cout << "Not found" << endl;
	}
	readFile.close();
}

void Store_Book(string book_name, int book_number) { // store the name of the book and its book number in a text file
	ofstream writeFile("Book_database.txt", ios::app);	
	writeFile << book_name << " " << book_number << endl;
	writeFile.close();
	cout << "Successfuly stored the book";
}

void Main() {
	int operation, number;
	string name;

	cout << "1. Get Book 2. Store Book: ";
	cin >> operation;
	cin.ignore();

	switch(operation) {
		case 1:
			cout << "Book name or number: ";
			cin >> name;
			Get_Book(name);
			break;
		case 2:
			cout << "Book name:  ";
			getline(cin, name);
			number = RandomNumberGen();
			Store_Book(name, number);
			break;
		default:
			cout << "Error input" << endl;
			Main();
			break;
	}
}

int main()	{
	Main();
	return 0;
}