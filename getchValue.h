#pragma once
#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "Headers.h"
#include <algorithm>
//#include "help.h"


using namespace std;

int getchVal(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[100] = {};

	int num = 1;
	int nm = 1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) {
				return  101;
			}
			else if (a == 80 || a == 77) {
				return 111;
			}
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];

				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

int getchVal2(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[100] = {};

	int num = 1;
	int nm = 1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75)
				return  101;  // arrow up
			else if (a == 80 || a == 77)
				return 110;// arrow down
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			return 111; // enter
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100; // backspace
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

int getchValc(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[50] = {};

	int num = 1;
	int nm = 1; // for curriculum erasing
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

int getchVale(string& s, char t, int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[50] = {};

	int num = 1;
	int nm = 1; // for curriculum erasing
	char a;

	for (int z = 0;;) {
		a = _getch();

		/*if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}*/
		if (a == 13 && z >= 1) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s += x[j];
				}
				else {
					break;
				}
			}

			/*return 111;*/
			break;
		}
		else if (a == 8 && (z >= 1 || s != "")) {
			if (nm == 1 && s != "") { // for first time erasing
				s = "";
				nm = 0;
				return 100;
				break;
			}
			else {
				cout << "\b \b";
				if (z > 0) {
					x[z] = '\0';
					--z;
				}
			}
		}
		else if (/*((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') ||*/ (a >= '0' && a <= '1') /*|| a == ' ' */ && z < l) {

			// erasing previous string value
			if (num == 1) {
				s = "";
				num = 0;
			}
			if (t == 'n') { // age
				if ((a >= '0' && a <= '9')) {
					cout << a;
					x[z] = a;
					++z;
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
	return 0;
}


int getchValarr(string s[], int l) { // 101 is up, 111 is down // s string storage, l is length
	char x[32] = {};

	int num = 1;
	char a;

	for (int z = 0;;) {
		a = _getch();

		if (a == -32) {
			a = _getch();
			if (a == 72 || a == 75) return  101;
			else if (a == 80 || a == 77) return 111;
		}
		else if (a == 13) {
			x[z] = '\0';
			for (int j = 0; j < z; j++) { // Storing to string variable
				if ((x[j] >= 'a' && x[j] <= 'z') || (x[j] >= 'A' && x[j] <= 'Z') || (x[j] >= '0' && x[j] <= '9') || x[j] == ' ') {
					s[j] = x[j];
				}
				else {
					break;
				}
			}

			return 111;
			break;
		}
		else if (a == 8 && z >= 1) {
			cout << "\b \b";
			x[--z] = '\0';
		}
		else if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') {

			// erasing previous string value
			if (num == 1) {
				for (int j = 0; j < 32; j++) {
					s[j] = '\0';
				}
				num = 0;
			}
			if (l >= 2 && l <= 11) { // age
				if ((a >= '0' && a <= '9')) {
					if (l == 2 && z < 2) { // age and bday
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 11 && z < 11) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 4 && z < 4) { // byear and zip
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 12 && z < 11) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
					else if (l == 12 && z < 12) { // gnumber
						cout << a;
						x[z] = a;
						++z;
					}
				}
			}
			else {
				cout << a;
				x[z] = a;
				++z;
			}
		}
	}
}

void getchcout(char x[]) { // x = array of letters  y is size of letters
	for (int z = 0;; z++) {
		if (x[z] >= 'a' && x[z] <= 'z' || x[z] >= 'A' && x[z] <= 'Z' || x[z] >= '0' && x[z] <= '9' || x[z] == ' ') {
			cout << x[z];
		}
		else {
			break;
		}

	}
}

void delarr(char x[]) { // deleting array
	for (int z = 0; z < 32; z++) {
		x[z] = '\0';
	}
}

int  engetch(string& s,int v, int l) { // s = variable, v = 1/0 asterisk, l = length
	char x[100] = {}; // temp variable to collect characters
	char a;

	for (int i = 0;;) {
		a = _getch();

		if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'B') || (a >= '0' && a <= '9') || a == ' ') && i < l) {
			x[i++] = a;
			if (v == 1) cout << '*';
			else cout << a;
		}
		else if (a == 13 && i != 0) {
			x[i] = '\0';
			s = x;
			return 0;
			break;
		}
		else if (a == 8 && i != 0) {
			cout <<"\b \b";
			x[i--] = '\0';
		}
		else if (a == 27) {
			return 1;
			break;
		}
			
		
	}
}

int numgetch(string& s, int v, int l) { // s = variable, v = 1/0 numbers/letters, l = length
	char x[100] = {}; // temp variable to collect characters
	char a;

	for (int i = 0;;) {
		a = _getch();

		if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'B') || (a >= '0' && a <= '9') || a == ' ') && i < l) {
			/*x[i++] = a;
			if (v == 1) cout << '*';
			else cout << a;*/
			if (v == 1 && (a >= '0' && a <= '9')) { // numbers
				x[i++] = a;
				cout << a;
			}
			else if (v != 1 && (a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'B')){ // letters
				x[i++] = a;
				cout << a;
			}
			else if (v == 3) {

				x[i++] = a;
				cout << a;
			}
		}
		else if (a == 13 && i != 0) {
			x[i] = '\0';
			s = x;
			return 0;
			break;
		}
		else if (a == 8 && i != 0) {
			cout << "\b \b";
			x[i--] = '\0';
		}
		else if (a == 27) {
			return 1;
			break;
		}


	}
}

// advance sorting
bool customSort(const string& a, const string& b) {
	// Convertion for comparison
	string lowerA = a, lowerB = b;
	transform(lowerA.begin(), lowerA.end(), lowerA.begin(), ::tolower);
	transform(lowerB.begin(), lowerB.end(), lowerB.begin(), ::tolower);

	// If lowercase magkatulad, sort by length (shorter muna)
	if (lowerA == lowerB) {
		return a.length() < b.length();
	}

	return lowerA < lowerB;
}

void sortVector(vector<string>& vec) {
	sort(vec.begin(), vec.end(), customSort);
}

//  to ignore cases
string formatInput(const string& input) {
    if (input.empty()) return "";
    string formatted = input;
    formatted[0] = toupper(formatted[0]);
    for (size_t i = 1; i < formatted.size(); ++i) {
        formatted[i] = tolower(formatted[i]);
    }
    return formatted;
}

int showSuggestion(int x,int y, const string& input, const vector<string>& container, int a) { // x = x.axis, y = y.axis, input = hahanapin, container = lalagyan, a = 1/0 show all
	vector<string> matches; // vector for matched input
	int n = 1; // to increment y axis in coorxy
	int num = 0;
	int maxdis = 9; //max display

	string lowerInput = input;
	transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);

	for (const auto item : container) { // for each 'item' in 'container'

		string lowerItem = item;
		transform(lowerItem.begin(), lowerItem.end(), lowerItem.begin(), ::tolower);

		if (a == 1) { // if a = 1 'display all'
			matches.push_back(item); // it adds to the vector 'matches'
			num++;
			n++;
		}
		else {
			//if (item.find(input) == 0) { // if 'item' matched the string 'input' at the beginning '0'
			//	matches.push_back(item); // it adds to the vector 'matches'
			//	num++;
			//}

			if (lowerItem.find(lowerInput) == 0) { // Case-insensitive prefix match
				matches.push_back(item); // Add matched items to matches
				num++;
			}

		}
	}

	if (!matches.empty()) { // if 'matches' is not empty

		 //sorting by names - not learned - you are here - done
		/*for (size_t i = 0; i < matches.size() - 1; i++) {
			for (size_t j = 0; j < matches.size() - 1; j++) {
				if (matches[j][0] > matches[j + 1][0])
					swap(matches[j], matches[j + 1]);
			}
		}*/

		sort(matches.begin(), matches.end(), customSort);

		// display
		if (a != 1) {
			for (const auto match : matches) { // for each 'match' in 'matches'
				coorxy(x, y + n); cout << match; // display the match;
				n++;
				if (n == maxdis) break;
			}
		}
	}
	return n;
}

// x = x.axis, y = y.axis , container = vector, z = 1/0 numbbers or letters, w = length
string suggetch(int x, int y, const vector<string> &container,int z,int w) { 
	char temp[100] = {}; // declared to store the editable characters
	char a; // for getch
	string str; // final output as string
	int n=0;

	//n = showSuggestion(x, y, temp, container); // if i !=0 // temp is not empty character
	for (int i = 0;;) { // the methods
		coorxy(x, y);
		a = _getch(); // getch the input
		int maxdel = 9;

		if (((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z') || (a >= '0' && a <= '9') || a == ' ') && i <w) {
			if (z == 0) {
				temp[i++] = a; // adds to 'temp'
			}
			else if (z == 1) { // numbers only
				if (a >= '0' && a <= '9') {
					temp[i++] = a;
				}
			}
		}
		else if (a == 13 && i >= 0) { // if enter
			str = temp;  // made the 'temp' final output as string 'str'
			//for (const auto item : container) { // for each 'item' in 'container'
			//	if (str == item) { // if 'str' is equal to 'item'
			//		return str; // return the str // true
			//	}
			//	else return ""; // else return empty string // false
			//}

			for (int i = 0; i < n; i++) {
				coorxy(x, y + i); cout << string(20, ' ');
			}

			return str;
		}
		else if (a == 8) {
			if (i != 0) {
				temp[--i] = '\0';
				cout << "\b \b";
			}
		}
		else if (a == 27) { // esc key
			return "~&$e$s$c$&~";
		}
		else if (a == 3) { // ctrl + c
			return "hahahaha";
		}
		else if (a == 0) { // F1
			return "tulong!";
		}
		else if (a == 0x01) { // ctrl + a key == show all
			n = showSuggestion(x, y, temp, container, 1); // load all

			for (int i = 0; i < n; i++) { // remove suggestion list
				coorxy(x, y + i); cout << string(13, ' ');
				if (i == maxdel)break;
			}
			return "$A%L!L(n<";
		}
		else {
			if (a == -32) { // still jumping fix this
				a = _getch();
			}
			a = '\0';
		}

		for (int i = 0; i < n; i++) {
			coorxy(x, y + i); cout << string(20, ' ');
		}
		n = 0;
		//coorxy(x, y); cout << string(20, ' ');


		//system("cls");
		coorxy(x, y); cout << temp << endl;

		//if (i != 0) 
		n = showSuggestion(x,y,temp, container,0); // if i !=0 // temp is not empty character
	}
}

