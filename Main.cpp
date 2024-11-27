#include <iostream>
#include <conio.h> // for getch
#include <fstream> // for database
#include <sstream> // for looking specific line in database
#include "Headers.h" // my headers
#include "getchValue.h" // my getchs
#include "loading.h" // opening
#include <string> // for getline
#include <vector> // for vector
#include <cstdio> // for removing text file account
#include <Windows.h>
#include "border.h"
#include "color.h"
#include "Graphics.h"


using namespace std;


int main()
{
	hideCursor(1);
	opening();
	outtextxy(260, 230, "                       ");
	ldscreen();




Q:
	struct productStruct {
		bool exist;
		int id = 0;
		string name = "";
		int quantity = 0;
		int price = 0;
		int itms = 0;
		struct productStruct* next;
	};

	productStruct* products = NULL; // Main list for products
	productStruct* accCart = NULL; // List of accounts cart
	productStruct* temp; // for temporary storing
	productStruct* temp2; // duplicated list for manipulating main list 'products'
	productStruct* display; // duplicated list of main list 'products' for display

	vector<string> productName; // products local storage/vector for product name 
	//vector<string> productLine;
	vector<string> id; // local storage for item ID
	vector<string> tempVector; // temporary vector
	vector<string> accUser;
	vector<string> accPs;
	vector<string> tempVector2;
	vector<string> tempVector3;
	vector<string> tempVectorLine; // for temporary storing string line (database)


	string tuser, tpass; // use for opening the account / text file
	string nuser, npass; // temporary variable for making account
	string tempid, tempname, tempquantity, tempprice, tempsold; // local variabals for adding product
	string line = ""; // for line inside text file / database
	string line2 = ""; // temporary string line for text
	string product = ""; // for product inside 'products.txt'
	string type = ""; // variable to identify each category
	string tempquant = ""; // for temporary string that will converted to int
	string item; // used to get the value of suggetch
	string accUsrn = ""; // username
	string accPass = ""; // password
	string account;
	string accAdmin = "addmin123";
	string value1; // temporary string used in sorting by price
	string value2; // temporary string used in sorting by price

	size_t LastTabPos; // for locating position of tab
	size_t LastTabPos2; // for locating the position of tab (2)

	int keycntr = 0; // arrow ke counter
	int lcntr = 0; // option indicator
	int y = 0; // y axis coorxy for display
	int esc = 0; // esc confirmation of engetch
	int pieces = 0; // number of products to buy
	int tempnum = 0; // temporary num
	int tempnum2 = 0; // temporaru num2
	int access = 1; // 0 = user / 1 = admin
	int prodCounterID = 0;
	int total = 0;

	int addc = 0;
	int maxdis = 0;
	int add = 0;

	char a;
	char arr[100]; // temporary char for getch

	bool check;
	bool accCheck;

	system("color 01");
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


	system("cls");

	//front 
	front_b(0);
	logo(11, 3);
	hideCursor(true);
	coorxy(77 + 10, 11 + 3); cout << "Login";

	coorxy(73 + 10, 17 + 3); cout << "Create Account";

q:
	for (int i = 10 + 3; i <= 18 + 3; i++) { // erasing asterisk
		coorxy(71 + 10, i); cout << ' ';
		coorxy(89 + 10, i); cout << ' ';
	}

	switch (keycntr) { // outputing '*' depending on 'keycntr'
	case 0:

		color(3);
		// top corner
		coorxy(71 + 10, 10 + 3); cout << char(201); // left
		coorxy(89 + 10, 10 + 3); cout << char(187); // right

		// bot corner
		coorxy(71 + 10, 12 + 3); cout << char(200); // left
		coorxy(89 + 10, 12 + 3); cout << char(188); // right

		color(1);
		break;
	case 1:
		color(3);
		// top corner (2nd box)
		coorxy(71 + 10, 16 + 3); cout << char(201); // left
		coorxy(89 + 10, 16 + 3); cout << char(187); // right

		//bot corner(2st box)
		coorxy(71 + 10, 18 + 3); cout << char(200); // left
		coorxy(89 + 10, 18 + 3); cout << char(188); // right		

		color(1);
		break;
	default:
		goto q;
	}

	switch (_getch()) { // switch case for switching the '*'
	case 72:
		if (keycntr == 1) keycntr = 0;
		else keycntr++;
		goto q;
		break;
	case 80:
		if (keycntr == 0) keycntr = 1;
		else keycntr--;
		goto q;
		break;
	case 13: // if entered, the loop will break
		break;
	default:
		goto q;
		break;
	}

	system("cls");

	//  login

	if (keycntr == 1) { // if creating account

	E:
		hideCursor(false);
		b_login();
		logo(11, 3);
		coorxy(32, 14);
		cout << "CREATE ACCOUNT";
		lcntr = 0;
		nuser, npass;

		coorxy(80, 5); cout << "Username " << string(10, ' ');
		coorxy(80, 11); cout << "Password " << string(10, ' ');;
		coorxy(35, 10); cout << string(21, ' '); //25


		//hideCursor(false);
		coorxy(50 + 30, 18); cout << " Confirm";
		coorxy(52 + 30, 22); cout << " Back";

		color(3);
		coorxy(10, 27); cout << "Press ";
		color(1);

		color(6);
		coorxy(16, 27); cout << "'esc'";
		color(1);
		color(3);
		coorxy(22, 27); cout << "to go back";
		color(1);

		//input
		color(6);
		coorxy(46 + 30, 8); esc = engetch(nuser, 0, 10);
		if (esc == 1) goto Q;
		coorxy(46 + 30, 14); esc = engetch(npass, 1, 10);
		if (esc == 1) goto Q;
		color(1);
		// arrow keys for back and confirm
	e:
		hideCursor(true);//nakatago cursor
		for (int i = 17; i <= 23; i++) {
			coorxy(48 + 30, i); cout << ' ';
			coorxy(61 + 30, i); cout << ' ';
		}

		switch (lcntr) { // arrow key display
		case 0:


			color(3);
			// top corner
			coorxy(48 + 30, 17); cout << char(201); // left
			coorxy(61 + 30, 17); cout << char(187); // right

			// bot corner
			coorxy(48 + 30, 19); cout << char(200); // left
			coorxy(61 + 30, 19); cout << char(188); // right

			color(1);

			break;
		case 1:


			color(3);
			// top corner
			coorxy(48 + 30, 21); cout << char(201); // left
			coorxy(61 + 30, 21); cout << char(187); // right

			// bot corner
			coorxy(48 + 30, 23); cout << char(200); // left
			coorxy(61 + 30, 23); cout << char(188); // right

			color(1);

			break;
		}

		a = _getch();
		if (a == -32) { // arrow key
			switch (_getch()) {
			case 72:
				if (lcntr == 1) lcntr = 0;
				else lcntr++;
				goto e;
				break;
			case 80:
				if (lcntr == 0) lcntr = 1;
				else lcntr--;
				goto e;
				break;
			default:
				a = '\0';
				goto e;
				break;
			}
		}
		else if (a == 13) { // enter
			if (lcntr == 1) { // if back go back
				system("cls");
				goto Q;
			}
			else { // else check if existing or not

				tempVector = {};
				ifstream loadAcc("accounts.txt", ios::in);
				if (loadAcc.is_open()) {
					line = "";
					while (getline(loadAcc, line)) {
						stringstream ss(line);
						getline(ss, line, '\t');
						tempVector.push_back(line);
					}
					loadAcc.close();
				}

				//check if existing
				for (const auto& i : tempVector) {
					if (nuser == "admin" || i == nuser) {


						color(3);
						coorxy(85, 27); cout << string(26, ' ');
						coorxy(75, 27); cout << "Username already exist";
						color(1);

						color(6);
						coorxy(74, 27); cout << "!";
						coorxy(97, 27); cout << "!";
						color(1);

						a = _getch();
						system("cls");
						goto E;
					}
				}

				// make new if not existing
				ofstream newfile;
				newfile.open(nuser + npass + ".txt");
				newfile.close();
				coorxy(85, 27); cout << string(26, ' ');

				color(3);
				coorxy(75, 27); cout << "Created Successfuly";
				color(1);


				color(6);
				coorxy(74, 27); cout << "!";
				coorxy(94, 27); cout << "!";
				color(1);


				fstream openlist;
				openlist.open("accounts.txt", ios::app);
				openlist << nuser << '\t' << npass << endl;
				openlist.close();

				system("pause>0");
				/*a = _getch();*/
				goto Q;

			}
		}
		else if (a == 27) goto Q;
		else goto e;
	}

	// LOGIN

W:
	lcntr = 0;
	system("cls");
	b_login(); // DESIGN
	coorxy(36, 14);
	cout << "LOGIN";
	logo(11, 3);
	coorxy(46 + 30, 5); cout << "Enter your Username ";
	coorxy(46 + 30, 11); cout << "Enter your Password ";
	coorxy(35 + 30, 10); cout << string(21, ' ');

	coorxy(50 + 30, 18); cout << " Confirm";
	coorxy(52 + 30, 22); cout << " back";

	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);

	// input 
	hideCursor(false);
	color(6);
	coorxy(46 + 30, 8); esc = engetch(tuser, 0, 10); if (esc == 1) goto Q;
	coorxy(46 + 30, 14); esc = engetch(tpass, 1, 10); if (esc == 1) goto Q;
	color(1);
w:
	for (int i = 17; i <= 23; i++) {
		coorxy(48 + 30, i); cout << ' ';
		coorxy(61 + 30, i); cout << ' ';
	}
	hideCursor(true);
	switch (lcntr) {
	case 0:
		color(3);
		// top corner
		coorxy(48 + 30, 17); cout << char(201); // left
		coorxy(61 + 30, 17); cout << char(187); // right

		// bot corner
		coorxy(48 + 30, 19); cout << char(200); // left
		coorxy(61 + 30, 19); cout << char(188); // right

		color(1);
		break;
	case 1:

		color(3);
		// top corner
		coorxy(48 + 30, 21); cout << char(201); // left
		coorxy(61 + 30, 21); cout << char(187); // right

		// bot corner
		coorxy(48 + 30, 23); cout << char(200); // left
		coorxy(61 + 30, 23); cout << char(188); // right

		color(1);
		break;
	}

	a = _getch();
	if (a == -32) { // arrow keys
		switch (_getch()) {
		case 72:
			if (lcntr == 1) lcntr = 0;
			else lcntr++;
			goto w;
		case 80:
			if (lcntr == 0) lcntr = 1;
			else lcntr--;
			goto w;
		default:
			a = '\0';
			goto w;
			break;
		}
	}

	else if (a == 13) {
		if (lcntr == 1) {
			goto Q;
		}
		else {
			if (tuser == "admin" && tpass == "123") {

				//coorxy(45, 24); cout << "login successfuly!" << string(40, ' ');


				color(3);
				coorxy(77, 27); cout << "Login Successfuly"; //<< string(40, ' ');
				color(1);

				color(6);
				coorxy(76, 27); cout << "!";
				coorxy(94, 27); cout << "!";
				color(1);

				access = 1;
			}
			else {
				ifstream load;
				load.open(tuser + tpass + ".txt");

				// check if existing
				if (load.is_open()) {

					//coorxy(46, 24); cout << "login successfuly!" << string(30, ' ');
					coorxy(85, 27); cout << string(26, ' ');
					color(3);
					coorxy(77, 27); cout << "Login Successfuly"; //<< string(10,' ');
					color(1);



					color(6);
					coorxy(76, 27); cout << "!";
					coorxy(94, 27); cout << "!";
					color(1);



					load.close();
					accUsrn = tuser;
					accPass = tpass;
					account = accUsrn + accPass + ".txt";
					access = 0;

					system("pause>0");
				}
				else { // else not exisitng

					//coorxy(40, 24); cout << "!Incorrect Username or Password!";


					color(3);
					coorxy(85, 27); cout << string(26, ' ');
					coorxy(70, 27); cout << "Incorrect Username or Password"; //<< string(30, ' ');
					color(1);

					color(6);
					coorxy(59 + 10, 27); cout << "!";
					coorxy(100, 27); cout << "!";
					color(1);

					a = _getch();
					/*coorxy(45, 10); cout << "Enter your Username : "; cout << string(10, ' ');
					coorxy(45, 11); cout << "Enter your Password : "; cout << string(10, ' ');*/
					goto W;
				}
			}
		}
	}
	else if (a == 27) goto Q;
	else goto w;

	//Sleep(2000);

	keycntr = 0; // arrow ke counter
	lcntr = 0; // option indicator

	//DONE
	// for user
	if (access == 0) {

		//loading the products
		fstream load("products2.txt", ios::in);
		if (load.is_open()) {
			line = "";
			type = "";// temporary variable to identify each category
			while (getline(load, line)) {
				stringstream ss(line);
				//Using linked list
				temp = new productStruct;
				temp->exist = true;
				getline(ss, type, '\t'); // id
				temp->id = stoi(type);
				id.push_back(type);
				getline(ss, type, '\t'); // name
				temp->name = type;
				productName.push_back(type);
				getline(ss, type, '\t');  // quantity
				temp->quantity = stoi(type);
				getline(ss, type, '\t'); // price
				temp->price = stoi(type);
				getline(ss, type, '\t'); // itms
				temp->itms = stoi(type);
				temp->next = NULL;
				temp2;
				if (products == NULL) {
					products = temp;
				}
				else {
					temp2 = products;
					while (temp2->next) temp2 = temp2->next;
					temp2->next = temp;
				}
			}
			load.close();
		}


		// Load
		fstream loadAcc(account, ios::in);
		if (loadAcc.is_open()) {
			line = "";
			type = "";
			tempVector = {};
			while (getline(loadAcc, line)) {

				// edit the name
				stringstream ss(line);
				getline(ss, type, '\t'); // id
				display = products;

				// YOU ARE HERE WHEN YOU DELETE A PRODUCT THEN GO TO ACCOUNT THERES ERROR - done
				if (products != NULL) {
					while (to_string(display->id) != type) {
						display = display->next;
						if (display == NULL) break;
					}

					if (display != NULL) {
						getline(ss, type, '\t'); // name
						getline(ss, type, '\t'); // name
						tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + type + '\t' + to_string(stoi(type) * display->price));
					}
				}
			}

			loadAcc.close();
		}

		// SORT THE VECTOR BEFORE UPDATING ACCOUNT - you are here
		value1 = "";
		value2 = "";
		for (size_t i = 0; i < tempVector.size(); i++) {
			for (size_t j = 0; j < tempVector.size() - 1; j++) {
				stringstream ss(tempVector[j]);
				getline(ss, value1, '\t');
				stringstream ss2(tempVector[j + 1]);
				getline(ss2, value2, '\t');

				if (stoi(value1) > stoi(value2)) {
					swap(tempVector[j], tempVector[j + 1]);
				}

				/*if (tempVector[j][0] > tempVector[j + 1][0]) {
					swap(tempVector[j], tempVector[j + 1]);
				}*/
			}
		}

		// Update account
		ofstream updateAcc(account, ios::out);
		if (updateAcc.is_open()) {
			for (const auto& i : tempVector) {
				updateAcc << i << endl;
			}
			updateAcc.close();
		}


		// lOADING CART
		fstream loadacc(account, ios::in); // open the accout text file
		if (loadacc.is_open()) {
			line = "";
			type = "";
			while (getline(loadacc, line)) { // loop every 'line' in 'load'
				stringstream ss(line);
				temp = new productStruct; // make new struct with address
				temp->exist = true;
				getline(ss, type, '\t'); // get the id
				temp->id = stoi(type);
				getline(ss, type, '\t'); // get the name
				temp->name = type;
				getline(ss, type, '\t');// get the quantity
				temp->quantity = stoi(type);
				getline(ss, type, '\t'); // get the price
				temp->price = stoi(type);
				temp->itms = 0;
				temp->next = NULL;
				temp2;
				if (accCart == NULL) { // if main account cart is empty
					accCart = temp; // transfer the temporary list 'temp'
				}
				else { // else find the 'temp' that is Null
					temp2 = accCart;
					while (temp2->next) temp2 = temp2->next; // find the NULL
					temp2->next = temp; // store to NULL
				}
				accCheck = true;
			}
		}
		loadacc.close();



	Q1: // pag balik sa Q1 == reset vectors and indicator
		system("cls");


		// Save the products
		fstream save("products2.txt", ios::out);
		if (save.is_open()) {

			id = {};
			display = products;
			while (display != NULL) {
				if (display->exist == true) id.push_back(to_string(display->id));
				display = display->next;
			}

			//Sort all ID
			for (size_t i = 0; i < id.size(); i++) {
				for (size_t j = 0; j < id.size() - 1; j++) {
					if (stoi(id[j]) > stoi(id[j + 1])) {
						swap(id[j], id[j + 1]);
					}
				}
			}

			// save based on sorted id and update the prodCounterID

			for (const auto& i : id) {

				// save
				display = products;
				while (to_string(display->id) != i) display = display->next;
				save << to_string(display->id) << '\t' << display->name << '\t' << to_string(display->quantity) << '\t' << to_string(display->price) << '\t' << to_string(display->itms) << endl;
			}

		}
		save.close();

		// USER MENU
		system("cls");
		hideCursor(true);
		user_b();
		logo(11, 3);
		front_b(-1);
		coorxy(83, 6);
		color(3);
		cout << "User: "; color(7); cout << accUsrn;
		//hideCursor();

		color(3);
		coorxy(46 + 40, 12); cout << " Buy Parts"; // top 9 bot 11
		coorxy(47 + 40, 15); cout << " My Cart"; // top 12 bot 14		
		coorxy(48 + 40, 18); cout << " Help"; // top 15 bot 17		
		coorxy(47 + 40, 21); cout << " Logout"; // top 18 bot 20

		color(3);
		coorxy(10, 27); cout << "Press ";
		color(1);

		color(6);
		coorxy(16, 27); cout << "'Esc'";
		color(1);
		color(3);
		coorxy(22, 27); cout << "for exit";
		color(1);
		//color(1);
	Q2:
		for (int i = 11; i <= 22; i++) {
			coorxy(42 + 40, i); cout << ' ';
			coorxy(60 + 40, i); cout << ' ';
		}

		switch (keycntr) {
		case 0:
			//coorxy(46, 10); cout << '*';


			color(6);
			// top corner
			coorxy(42 + 40, 11); cout << char(201); // left
			coorxy(60 + 40, 11); cout << char(187); // right

			// bot corner
			coorxy(42 + 40, 13); cout << char(200); // left
			coorxy(60 + 40, 13); cout << char(188); // right

			color(1);

			break;
		case 1:
			//coorxy(46, 11); cout << '*';

			color(6);
			// top corner
			coorxy(42 + 40, 14); cout << char(201); // left
			coorxy(60 + 40, 14); cout << char(187); // right

			// bot corner
			coorxy(42 + 40, 16); cout << char(200); // left
			coorxy(60 + 40, 16); cout << char(188); // right

			color(1);


			break;
		case 2:
			//coorxy(46, 12); cout << '*';

			color(6);
			// top corner
			coorxy(42 + 40, 17); cout << char(201); // left
			coorxy(60 + 40, 17); cout << char(187); // right

			// bot corner
			coorxy(42 + 40, 19); cout << char(200); // left
			coorxy(60 + 40, 19); cout << char(188); // right

			color(1);

			break;
		case 3:
			//coorxy(46, 13); cout << '*';

			color(6);
			// top corner
			coorxy(42 + 40, 20); cout << char(201); // left
			coorxy(60 + 40, 20); cout << char(187); // right

			// bot corner
			coorxy(42 + 40, 22); cout << char(200); // left
			coorxy(60 + 40, 22); cout << char(188); // right

			color(1);

			break;
		}

		a = _getch();
		switch (a) {
		case -32:
			switch (_getch()) {
			case 72:
				if (keycntr == 0) keycntr = 3;
				else keycntr--;
				break;
			case 80:
				if (keycntr == 3) keycntr = 0;
				else keycntr++;
				break;
			}
			goto Q2;
			break;
		default:
			goto Q2;
		case 13:
			break;
		case 27:
			system("cls");
			user_b();
			b_ex();
			system("cls");
			goto Q1;
			break;
		}

		// user main menu functions
		system("cls");

		if (keycntr == 0) { // BUY PARTS

		buyparts:
			system("cls");
			hideCursor(false);
			buy_part();

			check = false;
			item = " ";
			lcntr = 0; // option indicator

			coorxy(5, 4); cout << "Search item : ";

			coorxy(3, 22); cout << "Press 'F1' to Open Help Option";
			coorxy(3, 23); cout << "Press 'Ctrl + A' to Show all products";
			coorxy(3, 24); cout << "Press 'Ctrl + C' to View Cart";
			coorxy(3, 25); cout << "Press 'Tab' to Search again";

			// display account cart

			//	coorxy(80, 15); cout << "Your Cart : ";
			//	y = 0;
			//	fstream load(account, ios::in);
			//if (load.is_open()) {
			//	line = "";
			//	type = "";
			//	while (getline(load, line)) {
			//		stringstream ss(line);
			//		getline(ss, type, '\t');
			//		getline(ss, type, '\t'); // name
			//		coorxy(80, 16 + y); cout << type;
			//		getline(ss, type, '\t'); // quantity
			//		coorxy(95, 16 + y); cout << type;
			//		y++;
			//	}
			//	load.close();
			//}
		searchAgain:
			maxdis = 9;
			add = 0;
			hideCursor(false);
			lcntr = 0;
			tempVector = {}; // temp variable for loading names
			coorxy(20, 4); cout << string(20, ' ');
			item = suggetch(20, 4, productName, 0, 15); // y axis ng cursor yun input (sobrang argument)

			// Try here
			//add = 0;

			coorxy(35, 4); cout << string(17, ' ');
			if (item == "~&$e$s$c$&~") goto Q1; // string equivalent to esc
			if (item == "hahahaha") goto here; //string equivalent to ctrl + c
			if (item == "tulong!") { //string quivalent to h
				system("cls");
				helpDis(3);
				system("cls");
				goto buyparts;
			}
			if (item == "$A%L!L(n<");
			else {
				coorxy(20, 4); cout << item;
			}

			if (item != "") { // if searched is not empty string
				check = false;
				//y = 0; // number of options
				display = products;

				// Find and load to tempVector
				for (const auto& itm : productName) {

					// to ignore case
					string lowerInput = itm;
					transform(lowerInput.begin(), lowerInput.end(), lowerInput.begin(), ::tolower);
					string lowerItem = item;
					transform(lowerItem.begin(), lowerItem.end(), lowerItem.begin(), ::tolower);

					if (lowerInput.find(lowerItem) == 0 || item == "$A%L!L(n<") { // if 'itm' matches the string 'item' at the beginning // if ctrl+a == load all
						while (display->name != itm) display = display->next; // if the searched item matched the product, put on vector
						tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + to_string(display->quantity) + '\t' + to_string(display->price) + '\t' + to_string(display->itms)); // you have something to do here if no stock available - done

						check = true;
					}
				}

				// TRY
				//add = 0;

				if (!check) goto noResult;


				// sorting
			displaySorted:
				if (item == "$A%L!L(n<") { // sorted name
					value1 = "";
					value2 = "";
					for (size_t i = 0; i < tempVector.size() - 1; i++) {
						for (size_t j = 0; j < tempVector.size() - 1; j++) {

							value1 = tempVector[j];
							stringstream ss(value1);
							for (int i = 0; i < 2; i++) getline(ss, value1, '\t');

							value2 = tempVector[j + 1];
							stringstream sss(value2);
							for (int i = 0; i < 2; i++) getline(sss, value2, '\t');

							/*if (value1[0] > value2[0]) {
								swap(tempVector[j], tempVector[j + 1]);
							}*/
							if (customSort(value2, value1)) {
								swap(tempVector[j], tempVector[j + 1]);
							}


						}
					}
				}
				else if (item == "$A%L!L(p<") { // display sorted price

					value1 = "";
					value2 = "";
					for (size_t i = 0; i < tempVector.size() - 1; i++) {
						for (size_t j = 0; j < tempVector.size() - 1; j++) {

							value1 = tempVector[j];
							stringstream ss(value1);
							for (int i = 0; i < 4; i++) getline(ss, value1, '\t');

							value2 = tempVector[j + 1];
							stringstream sss(value2);
							for (int i = 0; i < 4; i++) getline(sss, value2, '\t');

							if (value1 < value2) {
								swap(tempVector[j], tempVector[j + 1]);
							}
						}
					}

				}
				else if (item == "$A%L!L(q<") { // YOU ARE HERE FIXING BUG (Not sorting after buying) - done

					// load procduct to tempVector
					/*tempVector = {};
					display = products;
					while (display) {
						tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + to_string(display->quantity) + '\t' + to_string(display->price) + '\t' + to_string(display->itms));
						display = display->next;
					}*/

					line = "";
					line2 = "";
					value1 = "";
					value2 = "";

					for (size_t i = 0; i < tempVector.size(); i++) {
						for (size_t j = 0; j < tempVector.size() - 1; j++) {

							line = tempVector[j];
							stringstream ss(line);
							for (int k = 0; k < 3; k++) getline(ss, value1, '\t');

							line2 = tempVector[j + 1];
							stringstream tt(line2);
							for (int k = 0; k < 3; k++) getline(tt, value2, '\t');

							if (stoi(value1) < stoi(value2)) {
								swap(tempVector[j], tempVector[j + 1]);
							}
						}
					}

				}

			productList:

				// display account cart
				//coorxy(80, 15); cout << "Your Cart :";
				//y = 0;
				//fstream load(account, ios::in);
				//if (load.is_open()) {
				//	line = "";
				//	type = "";
				//	while (getline(load, line)) {
				//		stringstream ss(line);
				//		getline(ss, type, '\t'); // id
				//		getline(ss, type, '\t'); // name
				//		coorxy(80, 16 + y); cout << string(14, ' ');
				//		coorxy(80, 16 + y); cout << type;
				//		getline(ss, type, '\t'); // quantity
				//		coorxy(95, 16 + y); cout << string(3, ' ');
				//		coorxy(95, 16 + y); cout << type;
				//		y++;
				//	}
				//	load.close();
				//}
			dito:
				hideCursor(true);
				coorxy(35, 5); cout << "Name:";
				coorxy(60, 5); cout << "Quantity:";
				coorxy(75, 5); cout << "Price:";
				total = 0;
				int size = 0;
				// save to vector then display
				y = 0; // number of options
				line = "";
				type = "";
				for (size_t i = 0 + add; i < tempVector.size(); i++) {
					display = products;
					line = tempVector[i];
					stringstream ss(line);
					for (int i = 0; i < 2; i++) getline(ss, type, '\t');

					while (display) {
						if (type == display->name) {

							// display
							// searching the item and adding
							coorxy(35, 6 + y); cout << display->name;
							if (display->quantity != 0) { // if no stock
								coorxy(60, 6 + y); cout << display->quantity;
								coorxy(75, 6 + y); cout << char(36) << " " << display->price;
							}
							else {
								coorxy(60, 6 + y); cout << "No stock";
								coorxy(75, 6 + y); cout << char(36) << " " << display->price;
							}
							check = true;
							y++;
							break;
						}
						display = display->next;
					}
					size += 1;
					if (i == maxdis)break;
				}

				// youre at choosing the product - done
			W1:
				// Display - done
				for (int i = 1; i <= 10; i++) {
					coorxy(33, 5 + i); cout << ' ';
				}
				for (int i = 0; i < y; i++) {
					if (lcntr == i) {
						coorxy(33, 6 + i); cout << "*";
						break;
					}
				}

				// YOU ARE HERE DISPLAYING THE SORTED PRICE OR QUANTITY USING ASCII
			//	if (add > size)add = size;

				if (add > size)total = size - size;
				int cursor = lcntr + add + total; // RUNTIME ERROR HERE

				line = tempVector[cursor];
				stringstream ss(line);
				a = _getch();
				coorxy(90, 5); cout << string(25, ' '); // erase how many
				coorxy(85, 4); cout << string(26, ' '); // erase not enough stock
				switch (a) {
				case -32: // arrow keys
					switch (_getch()) {
					case 72:
						if (lcntr == 0) lcntr = y - 1;
						else lcntr--;
						break;
					case 80:
						if (lcntr == y - 1) lcntr = 0;
						else lcntr++;
						break;
					case 77: //right key buy product - todo here again
						if (maxdis >= tempVector.size() || tempVector.size() <= 10) {
							/*if (maxdis > tempVector.size()) {*/
							maxdis = 9;
							add = 0;
						}
						else {
							for (int i = 0; i < 10; i++) {
								if (maxdis >= tempVector.size()) break;
								else {
									maxdis++;
								}
							}
							add+=10;
						}
						/*maxdis += 10;
						add += 10;
						lcntr = 0;*/

						/*lcntr = 0;
						for (int i = 0; i < 10; i++) {
							if (maxdis >= tempVector.size()) break;
							else {
								maxdis++;
							}
						}
						add+=10;*/

						if (maxdis > tempVector.size() || tempVector.size() <= 10) {
							/*if (maxdis > tempVector.size()) {
							} */
							maxdis = 9;
							add = 0;
						}
						else if (add >= tempVector.size() && maxdis >= tempVector.size()) {
							maxdis = 9;
							add = 0;
						}
						
						if (add > tempVector.size())add = tempVector.size();
						/*if(add>size)
						for (int i = 0; i <= y; i++) {
							coorxy(35, 6 + i); cout << string(56, ' ');
						}*/
						for (int i = 0; i <= y; i++) {
							coorxy(34, 6 + i); cout << string(57, ' ');
						}
						lcntr = 0;
						goto productList;
						break;
					case 75: //left
						if (maxdis == 9 && add == 0 || maxdis <= 10) {
							maxdis = 9;
							add = 0;
						}
						else {
							maxdis -= 10;
							add -= 10;
							lcntr = 0;

							if (maxdis < 10) maxdis = 9;
							else if (maxdis % 10 != 0) {
								if (add + 10 <= tempVector.size()) {
									maxdis = add + 9;
								}
							}
							
						}
						for (int i = 0; i <= y; i++) {
							coorxy(34, 6 + i); cout << string(57, ' ');
						}
						lcntr = 0;
						goto productList;
						break;
					}
					goto W1;
					break;
				case 27: // esc
					goto Q1;
				case 3: // ctr + c
					goto here;
				case 0: // F1
					system("cls");
					helpDis(3);
					system("cls");
					goto buyparts;
				case 13: // if enter return break
					display = products;

					for (int i = 0; i < 2; i++) getline(ss, line, '\t');
					while (line != display->name) display = display->next;
					if (display->quantity == 0) goto W1;

					coorxy(85, 4); cout << string(26, ' '); // Erase 'Not enough stock available'
					break;
				case 9: // 'tab' go to searchAgain
					// Erase display

					// RUNTIME HERE
					//add = 0;

					for (int i = 0; i <= 11; i++) {
						coorxy(33, 4 + i); cout << string(56, ' ');
					}
					coorxy(90, 5); cout << string(25, ' '); // erase how many
					coorxy(85, 4); cout << string(26, ' '); // erase not enough stock
					goto searchAgain;
					break;
				case 0x10: // ctrl + p = price
					item = "$A%L!L(p<";
					for (int i = 0; i <= y; i++) {
						coorxy(35, 6 + i); cout << string(35, ' ');
					}
					goto displaySorted;
					break;
				case 17: // ctrl + q = quantity
					item = "$A%L!L(q<";
					for (int i = 0; i <= y; i++) {
						coorxy(35, 6 + i); cout << string(35, ' ');
					}
					goto displaySorted;
					break;
				case 14: // ctrl + n = name
					item = "$A%L!L(n<";
					for (int i = 0; i <= y; i++) {
						coorxy(35, 6 + i); cout << string(35, ' ');
					}
					goto displaySorted;
					break;
				default:
					goto W1;
					break;
				}
			}
			else { // no result
			noResult:
				color(4);
				coorxy(25, 4); cout << "Not existing";
				color(1);
				goto searchAgain;

			}

			//YOU ARE HERE MODIFYING THE ACCOUNT AND QUANTITY
			hideCursor(false);
			coorxy(90, 5); cout << string(25, ' '); // erase how many
			coorxy(85, 4); cout << string(26, ' '); // erase not enough stock
			tempquant = "";
			coorxy(90, 5); cout << "Enter how many : ";
			arr[5] = {};

			for (int i = 0;;) {
				a = _getch();

				if ((a >= '0' && a <= '9')) {
					if (i < 3) {
						arr[i++] = a;
						cout << a;
					}
				}
				else if (a == 8) {
					if (i != 0) {
						arr[--i] = '\0';
						cout << "\b \b";
					}
				}
				else if (a == 13) {
					if (i != 0) {
						arr[i] = '\0';
						tempquant = arr;
						break;
					}
				}
				else if (a == 27) { // esc
					goto Q1;
					break;
				}
				else if (a == 9) { // tab

					for (int i = 0; i <= 11; i++) {
						coorxy(33, 4 + i); cout << string(56, ' ');
					}
					coorxy(90, 5); cout << string(25, ' '); // erase how many
					coorxy(85, 4); cout << string(26, ' '); // erase not enough stock

					goto searchAgain;
					break;
				}
				else {
					if (a == -32) { // receive unwanted char
						a = _getch();
					}
					a = '\0';
				}
			}


			if (esc == 1) goto Q1;

			pieces = stoi(tempquant);

			// find the product inside the list
			temp2 = products;
			line = tempVector[lcntr + add - total];
			stringstream ss(line);
			for (int i = 0; i < 2; i++) getline(ss, line, '\t');

			while (line != temp2->name) temp2 = temp2->next;

			if ((pieces <= temp2->quantity) && (temp2->quantity != 0)) {// if product quantity is still greater than pieces and not 0 stock
				temp2->quantity -= pieces;
				temp2->itms += pieces;

				// updating the product list and amount
				line = "";
				tempVectorLine = {};
				fstream load(account, ios::in || ios::app);
				if (load.is_open()) {
					line = "";
					type = "";
					check = false;
					while (getline(load, line)) {
						stringstream ss(line);
						getline(ss, type, '\t'); // id
						getline(ss, type, '\t'); // name
						if (type == temp2->name) { // if existing on account
							//add also the total amount

							getline(ss, type, '\t'); // get the quantiy
							line = to_string(temp2->id) + '\t' + temp2->name + '\t' + (to_string(stoi(type) + pieces) + '\t' + to_string((stoi(type) + pieces) * temp2->price));
							check = true;
						}
						tempVectorLine.push_back(line); // store to tempVectorLine
					}
					if (!check) { // if not, store to tempVectorLine
						tempVectorLine.push_back(to_string(temp2->id) + '\t' + temp2->name + '\t' + to_string(pieces) + '\t' + to_string(pieces * temp2->price));
					}
					load.close();
				}

				// sort the ID
				value1 = "";
				value2 = "";
				for (int i = 0; i < tempVectorLine.size() - 1; i++) {
					for (int j = 0; j < tempVectorLine.size() - 1; j++) {
						stringstream ss(tempVectorLine[j]);
						getline(ss, value1, '\t');
						stringstream ss2(tempVectorLine[j + 1]);
						getline(ss2, value2, '\t');

						if (stoi(value1) > stoi(value2)) {
							swap(tempVectorLine[j], tempVectorLine[j + 1]);
						}

						/*if (tempVectorLine[j][0] > tempVectorLine[j + 1][0])
							swap(tempVectorLine[j], tempVectorLine[j + 1]);*/
					}
				}

				// Saving to account
				ofstream saveA(account, ios::out);
				for (const auto& i : tempVectorLine) { // saving the lines from tempVectorLine to account
					saveA << i << endl;
				}
				saveA.close();

				// Saving products to database
				fstream save("products2.txt", ios::out);
				if (save.is_open()) {

					id = {};
					display = products;
					while (display != NULL) {
						if (display->exist == true) id.push_back(to_string(display->id));
						display = display->next;
					}

					//Sort all ID
					for (size_t i = 0; i < id.size(); i++) {
						for (size_t j = 0; j < id.size() - 1; j++) {
							if (stoi(id[j]) > stoi(id[j + 1])) {
								swap(id[j], id[j + 1]);
							}
						}
					}

					// save based on sorted id and update the prodCounterID
					for (const auto& i : id) {

						// save
						display = products;
						while (to_string(display->id) != i) display = display->next;
						save << to_string(display->id) << '\t' << display->name << '\t' << to_string(display->quantity) << '\t' << to_string(display->price) << '\t' << to_string(display->itms) << endl;
					}


				}
				save.close();

				// Erase display
				for (int i = 0; i <= y; i++) {
					coorxy(35, 6 + i); cout << string(35, ' ');
				}

				coorxy(90, 5); cout << string(25, ' '); // erase 'Enter how many'

				goto productList;
			}
			else { // quantity is empty || no stock available
				if (pieces > temp2->quantity) {
					coorxy(85, 4); cout << string(20, ' ');
					coorxy(85, 4); cout << "Not enough stock available";
				}
				goto productList;
			}




		}
		// USER CART
		//MY CART
		else if (keycntr == 1) { // load cart
		here:
			system("cls");
			hideCursor(true);
			my_cart();

			coorxy(10, 6); cout << "My cart:";
			coorxy(5, 21); cout << "Press 'Enter' to select the item";
			coorxy(5, 22); cout << "Press 'Tab' to re-select";
			coorxy(5, 23); cout << "Press 'Ctrl + O' to open receipt";
			coorxy(5, 24); cout << "Press 'F1' to open help option";
			coorxy(5, 25); cout << "Select an item then edit to '0' to delete the item";


			accCheck = false;
			fstream loadacc(account, ios::in); // open the accout text file
			if (loadacc.is_open()) {
				accCart = NULL;
				line = ""; // declare empty line for storing the line from notepad
				type = ""; // 'type' to accept the single word in line

				while (getline(loadacc, line)) { // loop every 'line' in 'load'
					stringstream ss(line);

					// YOU HAVE MAJOR TASK HERE IF ADMIN EDIT THE NAME AND PRICE

					temp = new productStruct; // make new struct with address
					temp->exist = true; // means product exist 
					getline(ss, type, '\t'); // get the id
					temp->id = stoi(type); // id
					getline(ss, type, '\t'); // get the name
					temp->name = type; // store to temporary list
					getline(ss, type, '\t');// get the quantity
					temp->quantity = stoi(type); // store to temporary list
					getline(ss, type, '\t'); // get the price
					temp->price = stoi(type); // store to temporary list
					temp->next = NULL; // declare the next as 'NULL' for sooner transfer


					temp2;
					if (accCart == NULL) { // if main account cart is empty
						accCart = temp; // transfer the temporary list 'temp'
					}
					else { // else find the 'temp' that is Null
						temp2 = accCart; // load to temporary struct
						while (temp2->next) temp2 = temp2->next; // find the NULL
						temp2->next = temp; // store to NULL
					}
					accCheck = true;
				}
			}
			loadacc.close();

		checkCart:
			if (!accCheck) { // check if empty
				system("cls");
				my_cart();
				coorxy(10, 6); cout << "My Cart";
				coorxy(55, 15); cout << "No item found\n";
				coorxy(45, 23); system("pause");
				goto Q1;
			}
			// Arrow key counter
			lcntr = 0;
			int tempo;
			addc = 0;
			// load to temporary vector for sorting
			tempVector = {};
			display = NULL;
			display = accCart;
			while (display) {
				tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + to_string(display->quantity) + '\t' + to_string(display->price));
				display = display->next;
			}

			// sort by name
		sortName:

			value1 = "";
			value2 = "";
			for (size_t i = 0; i < tempVector.size() - 1; i++) {
				for (size_t j = 0; j < tempVector.size() - 1; j++) {

					value1 = tempVector[j];
					stringstream ss(value1);
					for (int i = 0; i < 2; i++) getline(ss, value1, '\t');

					value2 = tempVector[j + 1];
					stringstream sss(value2);
					for (int i = 0; i < 2; i++) getline(sss, value2, '\t');

					if (customSort(value2,value1)){
					/*if (value1[0] > value2[0]) {*/
						swap(tempVector[j], tempVector[j + 1]);
					}
				}
			}



			// count the number of product
			y = 0;
			value1 = "";
			for (const auto& i : tempVector) {
				stringstream ss(i);
				getline(ss, value1, '\t');
				display = accCart;
				while (to_string(display->id) != value1) display = display->next;
				y++;
			}

			// Display
		DisplaySort:
			lcntr = 0;
			// Erase display
			for (int i = 0; i <= 16; i++) {
				coorxy(34, 3 + i); cout << string(51, ' ');
			}
			coorxy(35, 4); cout << "Name:";
			coorxy(60, 4); cout << "Quantity:";
			coorxy(75, 4); cout << "Price:";

			tempnum = 0;
			value1 = "";
			int v = 0;
			for (const auto& i : tempVector) {
				stringstream ss(i);
				getline(ss, value1, '\t');
				display = accCart;
				while (to_string(display->id) != value1) display = display->next;
				if (v >= addc) {
					coorxy(35, 5 + tempnum); cout << display->name; //6
					coorxy(60, 5 + tempnum); cout << display->quantity;//6
					coorxy(75, 5 + tempnum); cout << char(36) << " " << display->price;//6
					tempnum++;
					if (tempnum == 10)break;
				}
				v++;
			}
			tempnum2 = tempnum;

		Arrow2:
			for (int i = 0; i <= tempnum; i++) { // Erase arrow key
				coorxy(33, 5 + i); cout << ' ';
			}

			for (int i = 0; i < tempnum; i++) { // Display arrow key
				if (lcntr == i) {
					coorxy(33, 5 + i); cout << "*";
				}
			}

			for (int i = 0;;) { // youre here manipulating the arrow key option
				a = _getch();
				if (a == -32) {
					a = _getch();
					if (a == 72) { // arrow up
						if (lcntr == 0) lcntr = tempnum - 1;
						else lcntr--;
					}
					else if (a == 80) { // arrow down
						if (lcntr == tempnum - 1) lcntr = 0;
						else lcntr++;
					}
					else if (a == 77) { // arrow right
						tempo = tempVector.size();
						if ((tempo - (addc + 10)) <= 0) {
							addc = 0;
							lcntr == 0;
						}
						else {
							addc += 10;
							lcntr == 0;
						}
						//maxdis += 10;
						goto DisplaySort;
					}
					else if (a == 75) { //arrow left
						if (addc == 0) {
							//maxdis = 10;
							addc = 0;
							lcntr == 0;
						}
						else {
							addc -= 10;
							lcntr == 0;
							//maxdis -= 10;
							goto DisplaySort;
						}
					}
					goto Arrow2;
				}
				else if (a == 13) { // enter
					break;
				}
				else if (a == 27) { // esc
					if (keycntr == 0) {
						goto buyparts;
					}
					goto Q1;
				}
				else if (a == 17 || a == 0x10) { // ctrl + q = quantity // ctrl + p = price
					line = "";
					line2 = "";
					value1 = "";
					value2 = "";
					type = "";
					tempnum = 0;

					if (a == 17) tempnum = 3; // ctrl + q = quantity
					else tempnum = 4;// ctrl + p = price

					for (size_t i = 0; i < tempVector.size(); i++) {
						for (size_t j = 0; j < tempVector.size() - i - 1; j++) {

							line = tempVector[j];
							stringstream ss(line);
							for (int i = 1; i <= tempnum; i++) {
								getline(ss, type, '\t');
							}
							value1 = type;

							line2 = tempVector[j + 1];
							stringstream ss2(line2);
							for (int i = 1; i <= tempnum; i++) {
								getline(ss2, type, '\t');
							}
							value2 = type;

							if (stoi(value1) < stoi(value2)) {
								swap(tempVector[j], tempVector[j + 1]);
							}
						}
					}

					goto DisplaySort;
				}
				else if (a == 0) { //F1
					system("cls");
					helpDis(5);
					system("cls");
					goto here;
				}
				else if (a == 14) { // ctrl + n = Name
					goto sortName;
				}
				else if (a == 15) { // ctrl + o = output/receipt
					//RECEIPT
					for (int i = 0; i <= 11; i++) {
						coorxy(34, 4 + i); cout << string(51, ' ');
					}
					coorxy(55, 3); cout << accUsrn + "'s receipt:";
					coorxy(35, 4); cout << "Name:";
					coorxy(60, 4); cout << "Quantity:";
					coorxy(75, 4); cout << "Price:";

					// sort by name
					value1 = "";
					value2 = "";
					for (size_t i = 0; i < tempVector.size() - 1; i++) {
						for (size_t j = 0; j < tempVector.size() - 1; j++) {

							value1 = tempVector[j];
							stringstream ss(value1);
							for (int i = 0; i < 2; i++) getline(ss, value1, '\t');

							value2 = tempVector[j + 1];
							stringstream sss(value2);
							for (int i = 0; i < 2; i++) getline(sss, value2, '\t');

							if (value1[0] > value2[0]) {
								swap(tempVector[j], tempVector[j + 1]);
							}
						}
					}

					// display
					addc = 0;
				disrec:
					for (int i = 0; i <= 11; i++) {
						coorxy(34, 5 + i); cout << string(51, ' ');
					}
					y = 0;
					v = 0;
					line = "";
					value1 = "";
					tempnum = 0;
					tempnum2 = 0;
					tempVector2 = tempVector;
					//FOR DISPLAY
					for (const auto& i : tempVector2) {
						line = i;
						stringstream ss(line);
						for (int i = 0; i < 2; i++) getline(ss, value1, '\t');


						display = accCart;
						while (!value1.find(display->name) == 0) display = display->next;
						if (v >= addc) {
							coorxy(35, 5 + y); cout << display->name;
							coorxy(60, 5 + y); cout << display->quantity;
							coorxy(75, 5 + y); cout << char(36) << " " << display->price;
							y++;
							if (y == 10)break;
						}
						v++;
					}

					//For total of price and items
					line = "";
					value1 = "";
					tempnum = 0;
					tempnum2 = 0;
					tempVector2 = tempVector;
					for (const auto& i : tempVector2) {
						line = i;
						stringstream ss(line);
						for (int i = 0; i < 2; i++) getline(ss, value1, '\t');

						display = accCart;
						while (!value1.find(display->name) == 0) display = display->next;
						tempnum += display->quantity; // total items
						tempnum2 += display->price;// total price
					}

					coorxy(52, 16); cout << "Items : " << tempnum; // total item display
					coorxy(66, 16); cout << "Amount :" << char(36) << " " << tempnum2; // total amount display
				a:
					switch (_getch()) {
					case 77://right
						tempo = tempVector.size();
						if ((tempo - (addc + 10)) <= 0) {
							addc = 0;
						}
						else {
							addc += 10;
						}
						goto disrec;
						break;
					case 75://left
						if (addc == 0) {
							addc = 0;
						}
						else {
							addc -= 10;
						}
						goto disrec;
						break;
					case 224: //pagtumalon
						goto a;
						break;
					case 27: //esc
						break;
					default:
						goto disrec;
						break;
					}

					//erase receipt


					goto DisplaySort;
				}
			}

			// Edit the quantity
			line = "";
			value1 = "";
			value2 = "";
			arr[5] = {};

			coorxy(60, 5 + lcntr); cout << "  ";
			coorxy(60, 5 + lcntr);
			for (int i = 0;;) {
				a = _getch();

				if (a >= '0' && a <= '9') {
					if (i < 2) {
						arr[i++] = a;
						cout << a;
					}
				}
				else if (a == 13) {
					if (i != 0) {
						arr[i] = '\0';
						value1 = arr;
					}

					// Edit the specific line

					item = "";
					line = tempVector[lcntr + addc];
					stringstream ss(line);
					getline(ss, tempid, '\t'); // id
					getline(ss, tempname, '\t');  // name
					getline(ss, tempquantity, '\t');  // qty
					getline(ss, tempprice, '\t'); // price

					if (value1 == "") {
						coorxy(60, 5 + lcntr); cout << "  ";
						coorxy(60, 5 + lcntr); cout << tempquantity;
						goto Arrow2;
					}
					else if (stoi(value1) >= stoi(tempquantity)) {
						coorxy(60, 5 + lcntr); cout << "  ";
						coorxy(60, 5 + lcntr); cout << tempquantity;
						goto Arrow2;
					}

					// get the products
					tempVectorLine = {};
					ifstream loadprod("products2.txt", ios::in);
					if (loadprod.is_open()) {
						line = "";
						while (getline(loadprod, line)) {
							tempVectorLine.push_back(line);
						}
						loadprod.close();
					}

					// edit the product vector
					value2 = "";
					line = "";
					display = products;

					while (display->id != stoi(tempid)) {
						display = display->next;
					}

					for (int i = 0; i < tempVectorLine.size(); i++) {
						stringstream ss2(tempVectorLine[i]);
						getline(ss2, value2, '\t'); // id
						if (value2 == tempid) {
							stringstream ss(tempVectorLine[i]);
							getline(ss, value2, '\t'); // id
							getline(ss, value2, '\t'); // name
							getline(ss, value2, '\t'); // qty
							display->quantity = stoi(value2) + (stoi(tempquantity) - stoi(value1));
							getline(ss, value2, '\t'); // price
							getline(ss, value2, '\t'); // itms
							display->itms = stoi(value2) - (stoi(tempquantity) - stoi(value1));
							tempVectorLine[i] = line;
							break;
						}
					}

					// load the product price
					ifstream load("products2.txt", ios::app);
					line2 = "";
					while (getline(load, line2)) {
						stringstream ss(line2);
						for (int i = 0; i < 2; i++) getline(ss, item, '\t');
						if (item == tempname) {
							getline(ss, item, '\t'); // Qty
							getline(ss, item, '\t'); // Price
							break;
						}
					}
					load.close();
					value2 = "";
					value2 += tempid + '\t' + tempname + '\t' + value1 + "\t";
					//value2 += value1 +'\t';
					value2 += to_string(stoi(value1) * stoi(item)); // you are here, it should update the cost/price too - done
					tempVector[lcntr] = value2;

					// saving to text file
					type = "";
					fstream save(account, ios::out);
					if (save.is_open()) {
						for (const auto& i : tempVector) {
							stringstream ss(i);
							for (int i = 1; i <= 3; i++) getline(ss, type, '\t');
							if (stoi(type) == 0);
							else {
								save << i << endl;
							}
						}
						save.close();
					}

					// Load to link list
					y = 0;

					// for display bug
					ifstream loadd(account, ios::app);
					if (loadd.is_open()) {
						line = "";
						tempVector = {};
						while (getline(loadd, line)) {
							tempVector.push_back(line);
							y++;
						}
						loadd.close();
					}
					if (y == 0) {
						accCheck = false;
						goto checkCart;
					}
					line = "";
					accCart = NULL;

					type = "";
					for (const auto& i : tempVector) {
						line = i;
						stringstream ss(line);

						temp = new productStruct;

						temp->exist = true;
						getline(ss, type, '\t'); // id
						temp->id = stoi(type);
						getline(ss, type, '\t'); // name
						temp->name = type;
						getline(ss, type, '\t'); // quantity
						temp->quantity = stoi(type);
						if (temp->quantity == 0) break;
						getline(ss, type, '\t'); // price
						temp->price = stoi(type);
						temp->next = NULL;

						temp2;
						if (accCart == NULL) {
							accCart = temp;
						}
						else {
							temp2 = accCart;
							while (temp2->next) temp2 = temp2->next;
							temp2->next = temp;
						}
					}
					if (addc >= tempVector.size()) {
						addc -= 10;
						if (addc < 0) addc = 0;
					}

					goto DisplaySort;
					break;


				}
				else if (a == 8) { // backspace
					if (i != 0) {
						arr[--i] = '\0';
						cout << "\b \b";
					}
				}
				else if (a == 27) { // esc
					fstream save(account, ios::out || ios::app);
					if (save.is_open()) {
						for (const auto& i : tempVector) {
							save << i << endl;
						}
						save.close();
					}


					goto Q1;
				}
				else if (a == 9) { // tab
					goto DisplaySort;
				}
			}

		}
		else if (keycntr == 2) {
			system("cls");
			admin_b();
			helpDis(0);
			goto Q1;
		}
		else if (keycntr == 3) {
			goto Q;
		}
	}
	//ADMIN MENU
	else if (access == 1) { // admin
		keycntr = 0;

	A1:
		system("cls");
		admin_b();
		logo(11, 3);
		front_a(-1);
		coorxy(85, 6);
		color(7);
		cout << "Administrator";
		hideCursor(true);
		color(3);
		coorxy(45 + 40, 10); cout << "Manage products";
		coorxy(45 + 40, 13); cout << "Manage accounts";
		coorxy(45 + 40, 16); cout << "Record of sales";
		coorxy(50 + 40, 19); cout << "Help";
		coorxy(49 + 40, 22); cout << "Logout";

		color(3);
		coorxy(10, 27); cout << "Press ";
		color(1);

		color(6);
		coorxy(16, 27); cout << "'Esc'";
		color(1);
		color(3);
		coorxy(22, 27); cout << "for exit";
		color(1);

	arrw1:
		// erase arrow key
		for (int i = 9; i <= 23; i++) {
			coorxy(43 + 40, i); cout << ' ';
			coorxy(61 + 40, i); cout << ' ';
		}

		// display arrow key
		switch (keycntr) {
		case 0:
			//coorxy(46, 10); cout << "*";

			color(6);
			// top corner
			coorxy(43 + 40, 9); cout << char(201); // left
			coorxy(61 + 40, 9); cout << char(187); // right

			// bot corner
			coorxy(43 + 40, 11); cout << char(200); // left
			coorxy(61 + 40, 11); cout << char(188); // right

			color(1);

			break;
		case 1:
			//coorxy(46, 11); cout << "*";

			color(6);
			// top corner
			coorxy(43 + 40, 12); cout << char(201); // left
			coorxy(61 + 40, 12); cout << char(187); // right

			// bot corner
			coorxy(43 + 40, 14); cout << char(200); // left
			coorxy(61 + 40, 14); cout << char(188); // right

			color(1);

			break;
		case 2:
			//coorxy(46, 12); cout << "*";

			color(6);
			// top corner
			coorxy(43 + 40, 15); cout << char(201); // left
			coorxy(61 + 40, 15); cout << char(187); // right

			// bot corner
			coorxy(43 + 40, 17); cout << char(200); // left
			coorxy(61 + 40, 17); cout << char(188); // right

			color(1);

			break;
		case 3:
			//coorxy(46, 13); cout << "*";

			color(6);
			// top corner
			coorxy(43 + 40, 18); cout << char(201); // left
			coorxy(61 + 40, 18); cout << char(187); // right

			// bot corner
			coorxy(43 + 40, 20); cout << char(200); // left
			coorxy(61 + 40, 20); cout << char(188); // right

			color(1);

			break;
		case 4:
			//coorxy(46, 14); cout << "*";

			color(6);
			// top corner
			coorxy(43 + 40, 21); cout << char(201); // left
			coorxy(61 + 40, 21); cout << char(187); // right

			// bot corner
			coorxy(43 + 40, 23); cout << char(200); // left
			coorxy(61 + 40, 23); cout << char(188); // right

			color(1);

			break;
		}

		a = _getch();
		switch (a) {
		case -32: // arrow keys
			a = _getch();
			switch (a) {
			case 72: // arrow up
				if (keycntr == 0) keycntr = 4;
				else keycntr--;
				break;
			case 80: // arrow down
				if (keycntr == 4) keycntr = 0;
				else keycntr++;
				break;
			}
			goto arrw1;
			break;
		case 13: // enter == break
			break;
		default:
			goto arrw1;
			break;
		case 27:
			system("cls");
			admin_b();
			b_ex();
			system("cls");
			goto A1;
			break;
		}

		if (keycntr == 0) { // manage products

			//showCursor();
		a1:
			// loading products
			prodCounterID = 1;
			ifstream load("products2.txt", ios::in);
			if (load.is_open()) {
				products = NULL;
				line = "";
				type = "";
				id = {};
				productName = {};
				//productLine = {};
				while (getline(load, line)) {
					stringstream ss(line);
					getline(ss, type, '\t'); // ID

					if (stoi(type) == prodCounterID) {
						prodCounterID++;
					}

					// storing to temporary vector

					   // Store to link list
					temp = new productStruct;
					temp->exist = true;
					temp->id = stoi(type);
					id.push_back(type);
					getline(ss, type, '\t'); // NAME
					temp->name = type;
					productName.push_back(type);
					getline(ss, type, '\t'); // QUANTITY
					temp->quantity = stoi(type);
					getline(ss, type, '\t'); // PRICE
					temp->price = stoi(type);
					getline(ss, type, '\t'); // ITMS
					temp->itms = stoi(type);
					temp->next = NULL;
					//productLine.push_back(line); // store to vector line

					temp2;
					if (products == NULL) {
						products = temp;
					}
					else {
						temp2 = products;
						while (temp2->next) temp2 = temp2->next;
						temp2->next = temp;
					}
				}
				load.close();
			}

			hideCursor(false);
			system("cls");
			manprod_b();
			coorxy(5, 3); cout << "Enter the product ID";
			coorxy(4, 17); cout << "Press 'Enter' to select";
			coorxy(4, 18); cout << "Press 'tab' to Search again";
			coorxy(4, 19); cout << "Press 'esc' to go back";
			coorxy(4, 20); cout << "Select the Item and press 'delete' to delete the item";
			coorxy(4, 21); cout << "Press 'ctrl + j' to Sort by product ID (low to high)";
			coorxy(4, 22); cout << "Press 'ctrl + q' to Sort by quantity (high to low)";
			coorxy(4, 23); cout << "Press 'ctrl + p' to Sort by prices (low to high)";
			coorxy(4, 24); cout << "Press 'ctrl + n' to Sort by name";
			coorxy(4, 25); cout << "Press 'ctrl + a' to Show all products";
		srchagn:
			int maxdis = 9;
			int tempo = 0;
			lcntr = 0;
			coorxy(28, 3); cout << string(13, ' '); // erase search
			tempVector = {}; // temp variable for loading names
			coorxy(28, 3); cout << string(10, ' '); //25
			item = suggetch(30, 3, id, 1, 2); // cursor sa pag input (sobrang argument)
			coorxy(28, 3); cout << string(1, ' ');//25
			if (item == "~&$e$s$c$&~") goto A1; // string equivalent to esc
			if (item == "$A%L!L(n<");
			else {
				coorxy(28, 3); cout << item;
			}


			//if (item != "") { // if searched is not empty string
			check = false;
			//y = 0; // number of options

			if (item == "") {
				color(4); //red
				coorxy(28, 3); cout << "Not Existing";
				color(1);
				goto adpList;
			}
			display = products;
			// Find and load to tempVector
			for (const auto& itm : id) {
				if (itm.find(item) == 0 || item == "$A%L!L(n<") { // if 'itm' matches the string 'item' at the beginning // if ctrl+a == load all
					while (to_string(display->id) != itm) display = display->next; // if the searched item matched the product, put on vector
					tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + to_string(display->quantity) + '\t' + to_string(display->price) + '\t' + to_string(display->itms)); // you have something to do here if no stock available - done

					check = true;
				}
			}


			if (!check) {
				//goto noResult1;
				coorxy(28, 3); cout << string(13, ' '); // erase search
				color(4); //red
				coorxy(28, 3); cout << "Not Existing";
				color(1);
				goto adpList;
			}


			// sorting
		admindisplaySorted:

			// erase display products
			for (int i = 0; i <= 11; i++) {
				coorxy(40, 4 + i); cout << string(61, ' ');//3 //5
			}

			// load to tempvector
			/*tempVector = {};
			display = products;
			while (display) {
				tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + to_string(display->quantity) + '\t' + to_string(display->price));
				display = display->next;
			}*/

			if (item == "$A%L!L(n<") { // sorted id
				value1 = "";
				value2 = "";
				for (size_t i = 0; i < tempVector.size() - 1; i++) {
					for (size_t j = 0; j < tempVector.size() - 1; j++) { // UPDATED SORT 11.13.24
						stringstream ss(tempVector[j]);
						getline(ss, value1, '\t');
						stringstream ss2(tempVector[j + 1]);
						getline(ss2, value2, '\t');

						if (stoi(value1) > stoi(value2))
							swap(tempVector[j], tempVector[j + 1]);
					}
				}
			}
			else if (item == "$A%L!L(n2<") { // sorted name
				line = "";
				line2 = "";
				value1 = "";
				value2 = "";
				for (size_t i = 0; i < tempVector.size(); i++) {
					for (size_t j = 0; j < tempVector.size() - 1; j++) {
						line = tempVector[j];
						stringstream ss(line);
						for (int k = 0; k < 2; k++) getline(ss, value1, '\t');

						line2 = tempVector[j + 1];
						stringstream tt(line2);
						for (int k = 0; k < 2; k++) getline(tt, value2, '\t');

						if (customSort(value2,value1)){
						/*if (value1[0] > value2[0]) {*/
							swap(tempVector[j], tempVector[j + 1]);
						}
					}
				}

			}
			else if (item == "$A%L!L(p<") { // display sorted price

				value1 = "";
				value2 = "";
				for (size_t i = 0; i < tempVector.size() - 1; i++) {
					for (size_t j = 0; j < tempVector.size() - 1; j++) {

						value1 = tempVector[j];
						stringstream ss(value1);
						for (int i = 0; i < 4; i++) getline(ss, value1, '\t');

						value2 = tempVector[j + 1];
						stringstream sss(value2);
						for (int i = 0; i < 4; i++) getline(sss, value2, '\t');

						if (value1 < value2) {
							swap(tempVector[j], tempVector[j + 1]);
						}
					}
				}

			}
			else if (item == "$A%L!L(q<") { // YOU ARE HERE FIXING BUG (Not sorting after buying) - done

				// load procduct to tempVector
				/*tempVector = {};
				display = products;
				while (display) {
					tempVector.push_back(to_string(display->id) + '\t' + display->name + '\t' + to_string(display->quantity) + '\t' + to_string(display->price) + '\t' + to_string(display->itms));
					display = display->next;
				}*/

				line = "";
				line2 = "";
				value1 = "";
				value2 = "";

				for (size_t i = 0; i < tempVector.size(); i++) {
					for (size_t j = 0; j < tempVector.size() - 1; j++) {

						line = tempVector[j];
						stringstream ss(line);
						for (int k = 0; k < 3; k++) getline(ss, value1, '\t');

						line2 = tempVector[j + 1];
						stringstream tt(line2);
						for (int k = 0; k < 3; k++) getline(tt, value2, '\t');

						if (stoi(value1) < stoi(value2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}
					}
				}

			}
		adpList: // this is the goto after you edit the item

			coorxy(40, 4); cout << "Item ID:"; // ID
			coorxy(55, 4); cout << "Item Name:"; // Name
			coorxy(70, 4); cout << "Item Quantity"; // Total items 
			coorxy(90, 4); cout << "Item Price:"; // price
			// display
			y = 0; // number of options
			line = "";
			type = "";
			value1 = "";
			value2 = "";
			for (size_t i = 0 + tempo; i < tempVector.size(); i++) {
				display = products;
				while (display) {
					stringstream ss(tempVector[i]);
					getline(ss, value1, '\t');

					if (value1 == to_string(display->id)) { // UPDATED SRT 11.13.24

						// display
						coorxy(40, 5 + y); cout << display->id;
						coorxy(55, 5 + y); cout << display->name;
						if (display->quantity != 0) { // if no stock
							coorxy(70, 5 + y); cout << display->quantity;
							coorxy(90, 5 + y); cout << char(36) << " " << display->price;
						}
						else {
							coorxy(70, 5 + y); cout << "No stock";
							coorxy(90, 5 + y); cout << char(36) << " " << display->price;
						}
						check = true;
						y++;
						break;
					}
					display = display->next;
				}
				if (i == maxdis) break;
			}
			// Fixed gotoxy
			coorxy(65, 5 + y); cout << "Add Item"; // removed +y //2


			// youre at choosing the product - done
		aa1:
			// Display - done
			for (int i = 0; i < y + 1; i++) {
				coorxy(100, 5 + i); cout << ' ';
			}
			for (int i = 0; i < y + 1; i++) {
				if (lcntr == i) {
					coorxy(100, 5 + i); cout << "*";
					break;
				}
			}


			a = _getch(); // find bug here - done problem in adding
			switch (a) {
			case -32: // arrow keys
				switch (_getch()) {
				case 72:
					if (lcntr == 0) lcntr = y;
					else lcntr--;
					break;
				case 80:
					if (lcntr == y) lcntr = 0;
					else lcntr++;
					break;
				case 77: //right
					/*if (maxdis > tempVector.size() || tempVector.size() <= 10) {
						maxdis = 9;
						tempo = 0;
						lcntr = 0;
					}
					else {
						maxdis += 10;
						tempo += 10;
						lcntr = 0;
					}*/

					/*maxdis += 10;
					tempo += 10;
					lcntr = 0;

					if (maxdis > tempVector.size() || tempVector.size() <= 10) {
						maxdis = 9;
						tempo = 0;
						lcntr = 0;
					}*/

					lcntr = 0;
					if (maxdis >= tempVector.size() || tempVector.size() <= 10) { // pag max or first page
						maxdis = 9;
						tempo = 0;
					}
					else {
						for (int i = 0; i < 10; i++) {
							if (maxdis >= tempVector.size()) break;
							else {
								maxdis++;
							}
						}
						tempo += 10;
					}

					if (maxdis > tempVector.size() || tempVector.size() <= 10) { // if max page
						/*if (maxdis > tempVector.size()) {
						} */
						maxdis = 9;
						tempo = 0;
					}
					else if (tempo >= tempVector.size() && maxdis >= tempVector.size()) {
						maxdis = 9;
						tempo = 0;
					}

					/*if (maxdis == 9 && tempo == 0 || maxdis <= 10) {
						maxdis = 9;
						tempo = 0;
					}
					else {
						maxdis -= 10;
						tempo -= 10;
						lcntr = 0;

						if (maxdis < 10) maxdis = 9;
						else if (maxdis % 10 != 0) {
							if (tempo + 10 <= tempVector.size()) {
								maxdis = tempo + 9;
							}
						}

					}*/


					goto admindisplaySorted;
					break;
				case 75: //left
					/*if (maxdis == 9 && tempo == 0) {
						maxdis = 9;
						tempo = 0;
						lcntr = 0;
					}
					else {
						maxdis -= 10;
						tempo -= 10;
						lcntr = 0;
					}*/

					if (maxdis == 9 && tempo == 0 || maxdis <= 10) {
						maxdis = 9;
						tempo = 0;
					}
					else {
						maxdis -= 10;
						tempo -= 10;
						lcntr = 0;

						if (maxdis < 10) maxdis = 9;
						else if (maxdis % 10 != 0) {
							if (tempo + 10 <= tempVector.size()) {
								maxdis = tempo + 9;
							}
						}

					}
					lcntr = 0;
					goto admindisplaySorted;
					break;
				}
				goto aa1;
				break;
			case 27: // esc
				goto A1;
			case 13: // if enter return break

				display = products; // looking for the selected item

				if (lcntr != y) { // not last (edit) 
					value1 = "";
					value2 = "";
					stringstream ss(tempVector[lcntr]);
					getline(ss, value1, '\t');

					while (value1 != to_string(display->id)) {
						display = display->next;
					}
					check = false;
				}
				else check = true; // last means (add)


				//if (display->quantity == 0) goto aa1;
				//coorxy(80, 2); cout << string(26, ' '); // Erase 'Not enough stock available'

				break;
			case '\t': // 'tab' go to searchAgain
				// Erase display
				for (int i = 0; i <= 11; i++) {
					coorxy(40, 4 + i); cout << string(61, ' ');//3 //5
				}
				goto srchagn;
				break;
			case 10: // ctrl+j = ID
				item = "$A%L!L(n<";
				goto admindisplaySorted;
				break;
				break;
			case 0x10: // ctrl + p = price
				item = "$A%L!L(p<";
				goto admindisplaySorted;
				break;
			case 17: // ctrl + q = quantity
				item = "$A%L!L(q<";
				goto admindisplaySorted;
				break;
			case 0x0E: // ctrl + n = name
				item = "$A%L!L(n2<";
				goto admindisplaySorted;
				break;
			default:
				goto aa1;
				break;
			}
			//}else { // no result
			////noResult1:
			//	color(4); //red
			//	coorxy(15, 6); cout << "Not Existing";
			//	
			//	color(1);
			//	//coorxy(15, 6); cout << string(20, ' ');
			//	goto srchagn;

			//}

			// now here do the edit
			if (check) { // add

				// YOU ARE HERE NOW AT ADDING PRODUCT

				// then increment again starting from 1 to find the next not existing prodCounterID
				// save to database

				// input the name, quantity and price
				line = to_string(prodCounterID) + "\t\t\t";
				tempname = "";
				tempquantity = "";
				tempprice = "";

				// the prodCounterID will be the ID of new product
				coorxy(60, 5 + y); cout << string(13, ' '); //2
				coorxy(40, 5 + y); cout << prodCounterID;//2
				editLine(55, 5 + lcntr, line);//2
				stringstream ss(line);
				getline(ss, type, '\t'); // ID
				getline(ss, tempname, '\t');
				getline(ss, tempquantity, '\t');
				getline(ss, tempprice, '\t');
				if ((tempname == "" || tempquantity == "" || tempquantity == "0" || tempquantity == "00") || tempprice == "") { // if not filled up
					//coorxy(55, 3 + y); cout << string(33,' '); //2
					coorxy(40, 5 + y); cout << string(55, ' '); //2
					goto adpList;
				}

				// save to link list
				temp = new productStruct;
				temp->exist = true;
				temp->id = prodCounterID;
				temp->name = tempname;
				temp->quantity = stoi(tempquantity);
				temp->price = stoi(tempprice);
				temp->itms = 0;
				temp->next = NULL;
				display = products;


				if (products == NULL) products = temp;
				else {
					while (display->next) {
						display = display->next;
					}
					display->next = temp;
				}

				// store to vector 
				tempVector.push_back(to_string(temp->id) + '\t' + temp->name + '\t' + to_string(temp->quantity) + '\t' + to_string(temp->price) + '\t' + to_string(temp->itms));


			}
			else { // edit

				// after edit, sort it then save and load

				editLine(55, 5 + lcntr, tempVector[lcntr + tempo]); //2

				// now update the local products

				line = tempVector[lcntr + tempo];
				type = "";
				value1 = "";
				stringstream ss(line);
				getline(ss, type, '\t'); // getting the id
				display = products;
				while (display->id != stoi(type)) display = display->next;
				getline(ss, value1, '\t'); // getting the id

				if (value1 == "$empty$") { // if deleted
					display->exist = false;

					// pop from the vector
					if (tempVector.size() > 1) {
						for (size_t i = 0; i < tempVector.size() - 1; i++) {
							for (size_t j = 0; j < tempVector.size() - 1; j++) {
								line = tempVector[j];
								stringstream ss(line);
								getline(ss, value2, '\t');
								getline(ss, value2, '\t');
								if (value2 == "$empty$") {
									swap(tempVector[j], tempVector[j + 1]);
									break;
								}
							}

							/*line = tempVector[i];
							stringstream ss(line);
							getline(ss, value2, '\t');
							getline(ss, value2, '\t');
							if (value2 == "$empty$") {
								swap(tempVector[i], tempVector[tempVector.size() - 1]);
								break;
							}*/
						}
					}
					tempVector.pop_back();

					// delete from all account

					//Load accounts
					tempVector2 = {};
					line = "";
					tempname = "";
					ifstream allAcc("accounts.txt", ios::in);
					if (allAcc.is_open()) {
						while (getline(allAcc, line)) {
							stringstream ss(line);
							getline(ss, line, '\t');
							getline(ss, tempname, '\t');
							tempVector2.push_back(line + tempname);
						}
						allAcc.close();
					}

					// loop in all acc then find the deleted id
					for (const auto& i : tempVector2) {
						tempVectorLine = {};
						tempname = ""; // THe ID

						// load all the items from account except the deleted ID
						ifstream openAcc(i + ".txt", ios::in);
						if (openAcc.is_open()) {
							line = "";
							while (getline(openAcc, line)) {
								stringstream ss(line);
								getline(ss, tempname, '\t');
								if (tempname != type) {
									tempVectorLine.push_back(line);
								}
							}
							openAcc.close();
						}

						// Save to account the loaded items
						ofstream saveAcc(i + ".txt", ios::out);
						if (saveAcc.is_open()) {
							for (int i = 0; i < tempVectorLine.size(); i++) {
								saveAcc << tempVectorLine[i] << endl;
							}
							saveAcc.close();
						}
					}
				}
				else { // else
					display->exist = true;
					display->id = stoi(type);
					display->name = value1;
					getline(ss, type, '\t');
					display->quantity = stoi(type);
					getline(ss, type, '\t');
					display->price = stoi(type);
					getline(ss, type, '\t');
					display->itms = stoi(type);
				}
			}

			// sort the id // UPDATED SORT 11.13.2024
			tempVector2 = {};
			tempVector2 = tempVector;
			if (tempVector2.size() > 1) { // if many
				for (size_t i = 0; i < tempVector2.size() - 1; i++) {
					for (size_t j = 0; j < tempVector2.size() - 1; j++) {
						stringstream ss(tempVector[j]);
						getline(ss, value1, '\t');
						stringstream ss2(tempVector[j + 1]);
						getline(ss2, value2, '\t');

						if (stoi(value1) > stoi(value2))
							swap(tempVector[j], tempVector[j + 1]);

						/*if (tempVector2[j][0] > tempVector2[j + 1][0])
							swap(tempVector2[j], tempVector2[j + 1]);*/
					}
				}
			}

			// save to database
			prodCounterID = 1;
			ofstream save("products2.txt", ios::out); //products2
			if (save.is_open()) {

				// get all the ID
				id = {};
				display = products;
				while (display != NULL) {
					if (display->exist == true) id.push_back(to_string(display->id));
					display = display->next;
				}

				//Sort all ID
				for (size_t i = 0; i < id.size(); i++) {
					for (size_t j = 0; j < id.size() - 1; j++) {
						if (stoi(id[j]) > stoi(id[j + 1])) {
							swap(id[j], id[j + 1]);
						}
					}
				}

				// save based on sorted id and update the prodCounterID
				prodCounterID = 1;
				value1 = "";
				for (const auto& i : id) {

					// update prodCounter
					if (prodCounterID == stoi(i)) prodCounterID++;

					// save
					display = products;
					while (to_string(display->id) != i) {
						display = display->next;
					}
					save << to_string(display->id) << '\t' << display->name << '\t' << to_string(display->quantity) << '\t' << to_string(display->price) << '\t' << to_string(display->itms) << endl;
				}
				save.close();
			}

			// load to link list
			ifstream loadd("products2.txt", ios::in);
			if (loadd.is_open()) {
				products = NULL;
				line = "";
				type = "";
				id = {};
				productName = {};
				while (getline(loadd, line)) {
					stringstream ss(line);
					getline(ss, type, '\t'); // ID

					// Store to link list
					temp = new productStruct;
					temp->exist = true;
					temp->id = stoi(type);
					id.push_back(type); // store to vector id
					getline(ss, type, '\t'); // NAME
					temp->name = type;
					productName.push_back(type); // store to vector name
					getline(ss, type, '\t'); // QUANTITY
					temp->quantity = stoi(type);
					getline(ss, type, '\t'); // PRICE
					temp->price = stoi(type);
					getline(ss, type, '\t'); // ITMS
					temp->itms = stoi(type);
					temp->next = NULL;
					//productLine.push_back(line); // store to vector line

					temp2;
					if (products == NULL) {
						products = temp;
					}
					else {
						temp2 = products;
						while (temp2->next) temp2 = temp2->next;
						temp2->next = temp;
					}
				}
				loadd.close();
			}


			// erase display
			for (int i = 0; i <= y; i++) {
				coorxy(40, 5 + i); cout << string(55, ' '); //1
			}

			if (tempVector.size() != 0) {
				tempVector = tempVector2;
				lcntr = 0;
				goto adpList;
			}
			else goto srchagn;
		}
		else if (keycntr == 1) {	// manage accounts
		VA:
			system("cls");
			man_acc_b();

			// load accounts
			int maxdis = 10;
			int add = 0;
			lcntr = 0;
			y = 0; // number of accounts
			ifstream load("accounts.txt", ios::in);
			if (load.is_open()) {
				tempVector = {};
				tempVector2 = {};
				accUser = {};
				accPs = {};
				line = "";
				value1 = "";
				value2 = "";
				while (getline(load, line)) {
					value2 = "";
					tempVector.push_back(line);
					stringstream ss(line);
					getline(ss, value1, '\t'); // name
					accUser.push_back(value1);
					value2 += value1;
					getline(ss, value1, '\t'); // pass word
					accPs.push_back(value1);
					value2 += value1;
					tempVector2.push_back(value2);

					y++;
				}
				load.close();
			}

			// sort name alphabetical
			for (int i = 0; i < tempVector.size(); i++) {
				for (int j = 0; j < tempVector.size() - 1; j++) {
					if (customSort(tempVector[j+1],tempVector[j])){
					/*if (tempVector[j][0] > tempVector[j + 1][0]) {*/
						swap(tempVector[j], tempVector[j + 1]);
						swap(tempVector2[j], tempVector2[j + 1]);
						swap(accUser[j], accUser[j + 1]);
						swap(accPs[j], accPs[j + 1]);
					}
				}
			}

			coorxy(3, 23); cout << "Press 'delete' to Delete the Account";
			coorxy(3, 24); cout << "Press 'Enter' to Open the Account";
			coorxy(3, 25); cout << "Press 'esc' to go back";

			int i = 0;
			int hehe = 0;
			int cntr1 = 0;
			for (i = 0; i < y; i++) {
				if (cntr1 >= 10)break;
				coorxy(25, 6 + hehe); cout << accUser[i];
				coorxy(85, 6 + hehe); cout << accPs[i];
				hehe++;
				cntr1++;
			}
			int tempy = 0; // for left click
		dis:
			/*int*/ i = 0;
			/*int*/ hehe = 0;
			// Erase Display
			//for (i = 0; i <= 10; i++) {
			//	coorxy(25, 6 + hehe); cout << string(25, ' ');
			//	coorxy(85, 6 + hehe); cout << string(25, ' ');
			//	hehe++;
			//	//if (i > maxdis)break;
			//}

			// Display
			color(6);
			coorxy(25, 3); cout << "Username";
			coorxy(85, 3); cout << "Password";
			color(1);
			/*hehe = 0;
			for (i = 0 + add; i < y; i++) {
				coorxy(25, 6 + hehe); cout << accUser[i];
				coorxy(85, 6 + hehe); cout << accPs[i];
				hehe++;
				if (i >= maxdis)break;
			}*/

			// Arrow key
		arrow2:
			check = false;
			for (int i = 0; i <= 10; i++) {
				coorxy(20, 6 + i); cout << ' ';
			}
			//back here
			for (int i = 0; i <= 9; i++) {
				if (lcntr == i) {
					color(6);
					coorxy(20, 6 + i); cout << ">"; // removed +10 beside 4
					color(1);
					//if (i > maxdis)break;
					break;
				}
			}

			for (int i = 0;;) {
				a = _getch();
				if (a == -32) { // arrow keys
					hehe = 0;
					for (i = 0; i <= 10; i++) {
						coorxy(25, 6 + hehe); cout << string(25, ' ');
						coorxy(85, 6 + hehe); cout << string(25, ' ');
						hehe++;
						//if (i > maxdis)break;
					}
					a = _getch();
					if (a == 72) { // arrow up - YOU ARE HERE - done

						// display
						hehe = 0;
						cntr1 = 0;
						for (i = 0 + add; i < y; i++) {
							if (i >= y || cntr1 >= 10)break;
							coorxy(25, 6 + hehe); cout << accUser[i];
							coorxy(85, 6 + hehe); cout << accPs[i];
							hehe++;
							cntr1++;
						}

						if (lcntr == 0) lcntr = hehe - 1;
						else lcntr--;

						goto arrow2;
					}
					else if (a == 80) { // arrow down

						// display
						hehe = 0;
						cntr1 = 0;
						for (i = 0 + add; i < y; i++) {
							if (i >= y || cntr1 >= 10)break;
							coorxy(25, 6 + hehe); cout << accUser[i];
							coorxy(85, 6 + hehe); cout << accPs[i];
							hehe++;
							cntr1++;
						}

						if (lcntr == hehe - 1) lcntr = 0;
						else lcntr++;

						goto arrow2;
					}
					else if (a == 77) { //arrow right
						/*if (maxdis > tempVector.size()) {
							add = 0;
							maxdis = 9;
						}*/
						/*if (maxdis >= tempVector.size()) {
							add = 0;
							maxdis = 9;
						}
						else {
							maxdis += 10;
							add += 10;
							lcntr = 0;
						}*/

						if (maxdis >= tempVector.size()) {
							add = 0;
							maxdis = 10;
						}
						else {
							for (int i = 1; i <= 10; i++) {
								if (maxdis >= tempVector.size()) break;
								else {
									maxdis++;
								}
							}
							tempy = maxdis;
							add += 10;
							lcntr = 0;
						}

						// display
						hehe = 0;
						cntr1 = 0;
						for (i = 0 + add; i < y; i++) {
							coorxy(25, 6 + hehe); cout << accUser[i];
							coorxy(85, 6 + hehe); cout << accPs[i];
							hehe++;
							cntr1++;
							if (i >= y || cntr1 >= 10) break;
						}

						goto dis;
					}
					else if (a == 75) { //arrow left



						if (add > 0) {
							//if (maxdis == 9) {
							//	add = 0;
							//	maxdis = 9;
							//}
							//else {
							//	/*maxdis -= 10;
							//	add -= 10;
							//	lcntr = 0;*/
							for (int i = 1; i <= 10; i++) {
								if (maxdis <= 0) break;
								else {
									maxdis--;
								}
							}
							add -= 10;
							lcntr = 0;
							//}

							// display
							hehe = 0;
							cntr1 = 0;
							for (i = 0 + add; i < tempy; i++) {
								coorxy(25, 6 + hehe); cout << accUser[i];
								coorxy(85, 6 + hehe); cout << accPs[i];
								hehe++;
								cntr1++;
								if (cntr1 >= 10 || i < 0)break;
							}
							tempy -= 10;
						}
						else {
							hehe = 0;
							for (int i = 0; i < 10; i++) {
								coorxy(25, 6 + hehe); cout << accUser[i];
								coorxy(85, 6 + hehe); cout << accPs[i];
								hehe++;
							}
						}


						goto dis;
					}
					else if (a == 83) { // delete
						check = true;
						break;
					}
				}
				else if (a == 27) { // esc
					goto A1;
				}
				else if (a == 13) { // enter
					break;
				}
				else {
					if (a == -32) { // still jumping fix this
						a = _getch();
					}
					a = '\0';
				}
			}


			if (check) { // delete

				// delete the text file
				value1 = "";
				tempnum = tempVector2.size();

				swap(tempVector2[lcntr + add], tempVector2[tempnum - 1]);
				swap(tempVector[lcntr + add], tempVector[tempnum - 1]);

				value1 = tempVector2[tempnum - 1] + ".txt";
				remove(value1.c_str());

				tempVector2.pop_back();
				tempVector.pop_back();

				// sort name alphabetical
				for (int i = 0; i < tempVector.size(); i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {
						if (customSort(tempVector[j+1],tempVector[j])) {
						/*if (tempVector[j][0] > tempVector[j + 1][0]) {*/
							swap(tempVector[j], tempVector[j + 1]);
							swap(tempVector2[j], tempVector2[j + 1]);
						}
					}
				}

				// update the 'accounts.txt'
				ofstream save("accounts.txt", ios::out);
				if (save.is_open()) {
					for (const auto& i : tempVector) {
						save << i << endl;
					}
					save.close();
				}

				goto VA;
			}
			else { // open

				// YOU ARE HERE NOW AT OPENING THE SELECTED ACCOUNT

				// load products
				value1 = "";
				products = NULL;

				ifstream loadprod("products2.txt", ios::in);
				if (loadprod.is_open()) {
					line = "";
					while (getline(loadprod, line)) {
						//id.push_back(line);
						stringstream ss(line);

						temp = new productStruct;
						temp->exist = true;
						getline(ss, value1, '\t'); // id
						temp->id = stoi(value1);
						getline(ss, value1, '\t'); // name
						temp->name = value1;
						getline(ss, value1, '\t'); // quantity
						temp->quantity = stoi(value1);
						getline(ss, value1, '\t'); // price
						temp->price = stoi(value1);
						getline(ss, value1, '\t'); // itms
						temp->itms = stoi(value1);
						temp->next = NULL;

						temp2;
						if (products == NULL) {
							products = temp;
						}
						else {
							temp2 = products;
							while (temp2->next) temp2 = temp2->next;
							temp2->next = temp;
						}
					}
					loadprod.close();
				}

				// load account
				id = {};
				ifstream loadacc(tempVector2[lcntr + add] + ".txt", ios::in);
				if (loadacc.is_open()) {
					line = "";
					while (getline(loadacc, line)) {

						id.push_back(line); // 'id' as vector for account line
					}
					loadacc.close();
				}

				// update the name, qty and quantity
				tempVectorLine = {};
				value1 = "";
				value2 = "";
				for (const auto& i : id) {
					stringstream ss2(i);
					getline(ss2, value2, '\t');
					// get the id,name,price
					display = products;
					while (to_string(display->id) != value2) {
						display = display->next;
						if (display == NULL) break;
					}

					if (display != NULL) {

						// get the qty
						stringstream ss(i);
						for (int i = 0; i < 3; i++) getline(ss, value1, '\t'); // qty

						// save to vector
						tempVectorLine.push_back(to_string(display->id) + '\t' + display->name + '\t' + value1 + '\t' + to_string(stoi(value1) * display->price));
					}
				}
				// sort the id
				for (size_t i = 0; i < tempVectorLine.size(); i++) {
					for (size_t j = 0; j < tempVectorLine.size() - 1; j++) {
						if (stoi(tempVectorLine[j]) > stoi(tempVectorLine[j + 1])) {
							swap(tempVectorLine[j], tempVectorLine[j + 1]);
						}
					}
				}
				 
				// update the account database
				ofstream save(tempVector2[lcntr + add] + ".txt", ios::out);
				if (save.is_open()) {
					for (const auto& i : tempVectorLine) {
						save << i << endl;
					}
					save.close();
				}


				// diplay
				system("cls");
				maxdis = 0;
			disp:
				man_acc2_b();
				coorxy(50, 3); cout << accUser[lcntr + add] + " " << accPs[lcntr + add] << "'s cart";
				ifstream load(tempVector2[lcntr + add] + ".txt", ios::in);
				if (load.is_open()) {
					check = false;
					tempnum = 1;
					line = "";
					value1 = "";
					pieces = 0;
					tempnum2 = 0;
					y = 1;

					while (getline(load, line)) {
						stringstream ss(line);
						//ayusin pa toh tas tapos na
						if (!check) {
							coorxy(10, 5); cout << "Item ID:"; // ID
							coorxy(30, 5); cout << "Item Name:"; // Name
							coorxy(50, 5); cout << "Item Quantity:"; // Available
							coorxy(80, 5); cout << "Item Price:"; // price
						}

						if (y >= maxdis) {
							getline(ss, value1, '\t'); // Id 
							coorxy(10, 5 + tempnum); cout << value1;
							getline(ss, value1, '\t'); // name
							coorxy(30, 5 + tempnum); cout << value1;
							getline(ss, value1, '\t'); // quantity
							coorxy(50, 5 + tempnum); cout << value1;
							pieces += stoi(value1);
							getline(ss, value1, '\t'); // price
							coorxy(80, 5 + tempnum); cout << char(36) << " " << value1;
							tempnum2 += stoi(value1);
							check = true;
							tempnum++;
							if (tempnum == 15) break;
						}
						y++;
					}
					load.close();
				}
				load.open(tempVector2[lcntr + add] + ".txt", ios::in);
				if (load.is_open()) {
					check = false;
					tempnum = 1;
					line = "";
					value1 = "";
					pieces = 0;
					tempnum2 = 0;
					y = 1;

					while (getline(load, line)) {
						stringstream ss(line);

						getline(ss, value1, '\t'); // Id 
						getline(ss, value1, '\t'); // name
						getline(ss, value1, '\t'); // quantity
						pieces += stoi(value1);
						getline(ss, value1, '\t'); // price
						tempnum2 += stoi(value1);
						check = true;
						tempnum++;
						y++;
					}
					load.close();
				}

				// if empty
				if (!check) {
					coorxy(50, 10 + tempnum); cout << "Cart is empty";
				}
				else {
					coorxy(5, 24); cout << "Total items : " << pieces;
					coorxy(5, 25); cout << "Total amount : " << char(36) << " " << tempnum2;
				}
			talon:

				switch (_getch())
				{
				case 224:
					goto talon;
					break;
				case 77:// ayusin yung display tas goods na
					if (y < maxdis + 15) {
						maxdis = 0;
					}
					else {
						maxdis += 15;
					}
					for (int i = 0; i <= 15; i++) {
						coorxy(10, 5 + i); cout << string(90, ' ');
					}
					goto disp;
					break;
				case 75:
					if (maxdis == 0)maxdis = 0;
					else {
						maxdis -= 15;
					}
					for (int i = 0; i <= 15; i++) {
						coorxy(10, 5 + i); cout << string(90, ' ');
					}
					goto disp;
				case 27:
					break;
				default:
					goto talon;
					break;
				}

				//Erase display
				for (int i = 0; i <= tempnum + 7; i++) {
					coorxy(10, 5 + i); cout << string(40, ' ');
				}
				goto VA;
				//	goto arrow2;
			}


			coorxy(0, 29); system("pause");

		}
		else if (keycntr == 2) {	// record of sales
			system("cls");
			recS_b();
			// LOAD THE PRODUCTS2
			ifstream load("products2.txt", ios::in);
			if (load.is_open()) {
				products = NULL;
				tempVector = {};
				line = "";
				type = "";
				while (getline(load, line)) {

					stringstream ss(line);
					tempVector.push_back(line);
					temp = new productStruct;



					temp->exist = true;
					getline(ss, type, '\t'); // ID
					temp->id = stoi(type);
					getline(ss, type, '\t'); // NAME
					temp->name = type;
					getline(ss, type, '\t'); // QUANTITY
					temp->quantity = stoi(type);
					getline(ss, type, '\t'); // PRICE
					temp->price = stoi(type);
					getline(ss, type, '\t'); // ITMS
					temp->itms = stoi(type);
					temp->next = NULL;

					temp2;
					if (products == NULL) {
						products = temp;
					}
					else {
						temp2 = products;
						while (temp2->next) temp2 = temp2->next;
						temp2->next = temp;
					}
				}
				load.close();
			}

			display = products;
			if (display == NULL) {
				color(3);
				coorxy(43, 10); cout << "No product is Available :(";
				tempVector = {};
				products = NULL;
				line = "";
				type = "";
				coorxy(41, 15); system("pause");
				color(1);
				goto A1;
			}
			coorxy(10, 5); cout << "Item ID:"; // ID
			coorxy(20, 5); cout << "Item Name:"; // Name
			coorxy(35, 5); cout << "Items Acquired"; // Total items 
			coorxy(53, 5); cout << "Available Items"; // Available
			coorxy(72, 5); cout << "Item Sold"; // items sold
			coorxy(85, 5); cout << "Item Price"; // price

			coorxy(3, 19); cout << "Press 'ctrl + J' to Sort ID (low to high)";
			coorxy(3, 20); cout << "Press 'ctrl + N' to Sort Name alphabetically";
			coorxy(3, 21); cout << "Press 'ctrl + T' to Sort Acquired items (high to low)";
			coorxy(3, 22); cout << "Press 'ctrl + A' to Sort Available Items (high to low)";
			coorxy(3, 23); cout << "Press 'ctrl + S' to Sort Sold Items (high to low)";
			coorxy(3, 24); cout << "Press 'ctrl + P' to Sort Price (high to low)";
			coorxy(3, 25); cout << "Press 'esc' to go back";

			// Max number // should be editable
			int pg = 9;
			int add = 0;
			// Erase Display
			y = 0;
		r1:
			for (int i = 0; i <= y; i++) {
				coorxy(10, 6 + i); cout << string(100, ' ');
			}

			// DISPLAY // MINIMUM OF 10
			y = 0;
			line = "";
			value1 = "";
			value2 = "";
			for (int i = 0 + add; i < tempVector.size(); i++) {

				line = tempVector[i];
				stringstream ss(line);

				getline(ss, value1, '\t');
				coorxy(10, 6 + y); cout << value1; // ID

				getline(ss, value1, '\t');
				coorxy(20, 6 + y); cout << value1; // Name

				getline(ss, value2, '\t');
				coorxy(53, 6 + y); cout << value2; // Available

				getline(ss, value1, '\t');
				coorxy(85, 6 + y); cout << value1; // price

				getline(ss, value1, '\t');
				coorxy(72, 6 + y); cout << value1; // items sold

				getline(ss, value1, '\t');
				coorxy(35, 6 + y); cout << (stoi(value2) + stoi(value1)); // Total items 
				y++;
				if (i == pg)break;
			}

			line = "";
			line2 = "";

			a = _getch();
			if (a == 10) { // ctrl + j // ID
				value1 = "";
				value2 = "";

				for (int i = 0; i < tempVector.size() - 1; i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {

						stringstream ss(tempVector[j]);
						getline(ss, value1, '\t');
						stringstream ss2(tempVector[j + 1]);
						getline(ss2, value2, '\t');

						if (stoi(value1) > stoi(value2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}
						/*if (stoi(line) > stoi(line2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}*/

					}
				}

				goto r1;
			}
			else if (a == 14) { // ctrl + n // NAME

				for (int i = 0; i < tempVector.size() - 1; i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {

						line = tempVector[j];
						stringstream ss(line);
						for (int k = 1; k <= 2; k++) getline(ss, line, '\t');


						line2 = tempVector[j + 1];
						stringstream sss(line2);
						for (int k = 1; k <= 2; k++) getline(sss, line2, '\t');

						/*if (line[0] > line2[0]) {
							swap(tempVector[j], tempVector[j + 1]);
						}*/

						if (customSort(line2, line)) {
							swap(tempVector[j], tempVector[j + 1]);
						}

					}
				}
				goto r1;
			}
			else if (a == 20) { // ctrl + t // TOTAL ACQUIRED

				value1 = "";
				value2 = "";
				for (int i = 0; i < tempVector.size() - 1; i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {

						line = tempVector[j];
						stringstream ss(line);
						for (int k = 1; k <= 3; k++) getline(ss, value1, '\t');
						for (int k = 1; k <= 5; k++) getline(ss, value2, '\t');
						line = to_string(stoi(value1) + stoi(value2));


						line2 = tempVector[j + 1];
						stringstream sss(line2);
						for (int k = 1; k <= 3; k++) getline(sss, value1, '\t');
						for (int k = 1; k <= 5; k++) getline(sss, value2, '\t');
						line2 = to_string(stoi(value1) + stoi(value2));

						if (stoi(line) < stoi(line2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}

					}
				}
				goto r1;
			}
			else if (a == 1) { // ctrl + a // AVAILABLE
				for (int i = 0; i < tempVector.size() - 1; i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {

						line = tempVector[j];
						stringstream ss(line);
						for (int k = 1; k <= 3; k++) getline(ss, line, '\t');

						line2 = tempVector[j + 1];
						stringstream sss(line2);
						for (int k = 1; k <= 3; k++) getline(sss, line2, '\t');

						if (stoi(line) < stoi(line2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}

					}
				}
				goto r1;
			}
			else if (a == 19) { // ctrl + s // SOLD
				for (int i = 0; i < tempVector.size() - 1; i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {

						line = tempVector[j];
						stringstream ss(line);
						for (int k = 1; k <= 5; k++) getline(ss, line, '\t');

						line2 = tempVector[j + 1];
						stringstream sss(line2);
						for (int k = 1; k <= 5; k++) getline(sss, line2, '\t');

						if (stoi(line) < stoi(line2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}

					}
				}
				goto r1;
			}
			else if (a == 16) { // ctrl + p // PRICE
				for (int i = 0; i < tempVector.size() - 1; i++) {
					for (int j = 0; j < tempVector.size() - 1; j++) {

						line = tempVector[j];
						stringstream ss(line);
						for (int k = 1; k <= 4; k++) getline(ss, line, '\t');

						line2 = tempVector[j + 1];
						stringstream sss(line2);
						for (int k = 1; k <= 4; k++) getline(sss, line2, '\t');

						if (stoi(line) < stoi(line2)) {
							swap(tempVector[j], tempVector[j + 1]);
						}

					}
				}
				goto r1;
			}
			else if (a == 77) { //RIGHT ARROW
				if (pg > tempVector.size()) {
					pg = 9;
					add = 0;
				}
				else {
					pg += 10;
					add += 10;
				}
				goto r1;
			}
			else if (a == 75) { //LEFT ARROW
				if (pg == 9 && add == 0) {
					pg = 9;
					add = 0;
				}
				else {
					pg -= 10;
					add -= 10;
				}
				goto r1;
			}
			else if (a == 27) {
				goto A1;
			}
			else goto r1;

		}
		else if (keycntr == 3) {	// help
			system("cls");
			admin_b();
			helpDis(0);
			goto A1;
		}
		else if (keycntr == 4) {
			goto Q;
		}
	}



	//coorxy(0, 29); system("pause");
}