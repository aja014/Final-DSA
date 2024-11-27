#pragma once
#include <time.h>
#include <Windows.h>
#include <sstream>
#include <string>
#include "color.h"
#include "Graphics.h"
#include "Headers.h"
#define c color


using namespace std;

//void coorxy(int x, int y) {
//	HANDLE buffer = GetStdHandle(STD_OUTPUT_HANDLE);
//	_COORD pos;
//	pos.X = x;
//	pos.Y = y;
//	SetConsoleCursorPosition(buffer, pos);
//}

void font1(int x, int y, int z) {
	static CONSOLE_FONT_INFOEX font;
	font.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE buffer = GetStdHandle(STD_OUTPUT_HANDLE);
	font.FontWeight = x;
	font.dwFontSize.X = y;
	font.dwFontSize.Y = z;
	SetCurrentConsoleFontEx(buffer, 0, &font);
}


void hideCursor(boolean x)
{
	HANDLE HideCursor = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO HIDECURSOR;

	HIDECURSOR.dwSize = 1;
	if (x == true) {
		HIDECURSOR.bVisible = FALSE; // not visible
	}
	else if (x == false) {
		HIDECURSOR.bVisible = TRUE; // visible
	}


	SetConsoleCursorInfo(HideCursor, &HIDECURSOR);
}

int delay(int mseconds) {
	clock_t goal = mseconds + clock();
	while (goal > clock());
	return mseconds;
}

void editLine(int x, int y,string &a) {
	string id, name, quantity, price,itms;
	string line,var, output;
	int lcntr = 1; // counter
	char aa;
	char tempsto[100];


	line = a;
	stringstream ss(line);
	getline(ss, var, '\t');
	id = var;
	getline(ss, var, '\t');
	name = var;
	getline(ss, var, '\t');
	quantity = var;
	getline(ss, var, '\t');
	price = var;
	getline(ss, var, '\t');
	itms = var;

	/*coorxy(x, y); cout << name;
	coorxy(x+15, y); cout << quantity;
	coorxy(x+25, y); cout << price;*/
	
a:
	switch (lcntr) {
	case 1:
		coorxy(x, y);
		break;
	case 2:
		coorxy(x + 15, y);
		break;
	case 3:
		coorxy(x + 37, y);
		break;
	}


	aa = _getch();
	if (aa == -32) { // arrow keys
		aa = _getch();
		if (aa == 75) { // left arrow
			if (lcntr == 1) lcntr = 3;
			else lcntr--;
			goto a;
		}
		else if (aa == 77) { // right arrow
			if (lcntr == 3) lcntr = 1;
			else lcntr++;
			goto a;
		}
		else if (aa == 83) { // delete
			a = id + '\t' + "$empty$";
			
		}
		else {
			goto a;
		}

	}
	else if (aa == 13) { // enter
		if (lcntr == 1) { // name

			tempsto[20] = {};

			coorxy(x, y); cout << string(15, ' ');
			coorxy(x, y);
			for (int i = 0;;) {
				aa = _getch();

				if (((aa >= 'a' && aa <= 'z') || (aa >= 'A' && aa <= 'Z') || (aa >= '0' && aa <= '9') || aa == ' ') && i < 15) {
					tempsto[i++] = aa;
					cout << aa;
				}
				else if (aa == 13) {
					if (i != 0) {
						tempsto[i] = '\0';
						name = tempsto;
						goto a;
						break;
					}
					else {
						coorxy(x, y); cout << name;
						goto a;
					
					}
				}
				else if (aa == 8) {
					if (i != 0) {
						tempsto[--i] = '\0';
						cout << "\b \b";
					}
				}
				else {
					if (aa == -32) { 
						aa = _getch();
					}
					aa = '\0';
				}
			}
		}
		else if (lcntr == 2) { // quantity
			tempsto[20] = {};

			coorxy(x + 15, y); cout << string(2, ' ');
			coorxy(x + 15, y);
			for (int i = 0;;) {
				aa = _getch();

				if ((aa >= '0' && aa <= '9') && i < 2) {
					tempsto[i++] = aa;
					cout << aa;
				}
				else if (aa == 13) {
					if (i != 0) {
						tempsto[i] = '\0';
						quantity = tempsto;
						//cout << name;
						goto a;
						break;
					}
					else {
						coorxy(x + 15, y); cout << quantity;
						goto a;
					}
				}
				else if (aa == 8) {
					if (i != 0) {
						tempsto[--i] = '\0';
						cout << "\b \b";
					}
				}
			}
		}
		else if (lcntr == 3) { // price
			tempsto[20] = {};

			coorxy(x + 37, y); cout << string(3, ' ');
			coorxy(x + 37, y);
			for (int i = 0;;) {
				aa = _getch();

				if ((aa >= '0' && aa <= '9') && i < 3) {
					tempsto[i++] = aa;
					cout << aa;
				}
				else if (aa == 13) {
					if (i != 0) {
						tempsto[i] = '\0';
						price = tempsto;
						goto a;
						break;
					}
					else {
						coorxy(x + 37, y); cout << price;
						goto a;

					}
				}
				else if (aa == 8) {
					if (i != 0) {
						tempsto[--i] = '\0';
						cout << "\b \b";
					}
				}
			}
		}
	}
	else if (aa == 27) { // escape
		output = id + '\t' + name + '\t' + quantity + '\t' + price + '\t' + itms;
		a = output;
	}
	else {
		if (aa == -32) { // still jumping fix this
			aa = _getch();
		}
		aa = '\0';
		goto a;
	}
}

//border fo helpDis
void ha()
{
	//admin menu border

	color(3);
	coorxy(85, 27); cout << "Use ";
	coorxy(100, 27); cout << "to navigate";
	color(1);
	color(6);
	coorxy(89, 27); cout << "Arrow keys ";
	color(1);

	int x = 0, y = 0;
	x = 1;
	for (int i = 0; i < 118; i++)
	{
		coorxy(x, 1);
		cout << char(219);

		coorxy(x, 26);
		cout << char(219);

		coorxy(x, 28);
		cout << char(219);

		x++;
		cout << endl;
	}


	y = 1;
	for (int i = 0; i < 28; i++)
	{
		coorxy(1, y);
		cout << char(219);

		coorxy(118, y);
		cout << char(219);

		y++;
	}
}
void helpDis(int key)
{
start:

	system("cls");
	color(3);
	coorxy(85, 27); cout << "Use ";
	coorxy(100, 27); cout << "to navigate";
	color(1);
	color(6);
	coorxy(89, 27); cout << "Arrow keys ";
	color(1);

	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);

	ha();
	coorxy(53, 3);
	cout << "HELP MENU";
	if (key == 7) {
		key = 6;
	}
	if (key == -1) {
		key = 0;
	}

	switch (key) {
	case 0:
		coorxy(55, 6);
		cout << "ABOUT";

		coorxy(7, 8);
		cout << "This Help option provides a comprehensive guide on system navigation and interaction. It outlines key actions ";
		coorxy(5, 9);
		cout << "and , it outlines key actions and their associated shortcut keys for an efficient user Interface.";
		cout << "page 1";
		coorxy(55, 27);
		cout << "page 1";
		break;
	case 1:
		coorxy(55, 6);
		cout << "CUSTOMER MENU";

		coorxy(7, 8);
		cout << "The Customer's Menu is to give customers a personalized and user-friendly interface that";
		coorxy(5, 9);
		cout << "gives ease of use and flexible user interface for controlling, viewing, and adjusting their orders.";
		coorxy(55, 27);
		cout << "page 2";
		break;
	case 2:
		coorxy(55, 6);
		cout << "BUY PARTS:";

		coorxy(7, 8);
		cout << "Customers can purchase any products from the inventory. Users can search, add, and adjust the amount of items ";
		coorxy(5, 9);
		cout << "they want from the inventory." << endl;

		coorxy(5, 11);
		cout << "Buy Products Instructions:";
		coorxy(3, 12);
		cout << char(4) << " Search an item/product";
		coorxy(3, 13);
		cout << char(4) << " Choose the item/product";
		coorxy(3, 14);
		cout << char(4) << " Enter the amount of product";
		coorxy(55, 27);
		cout << "page 3";
		break;
	case 3:
		coorxy(45, 6);
		cout << "Guide for Buy Parts option:";
		coorxy(3, 8);
		cout << char(4) << " The Enter how many field facilitates the specification of the quantity of the selected item to";
		coorxy(5, 9);
		cout << "be added to the cart.";
		coorxy(3, 10);
		cout << char(4) << " The Your Cart section displays the items already added to the cart, along with their quantities.";
		coorxy(5, 12);
		cout << "Keyboard shortcuts for navigating the item list:";
		coorxy(3, 13);
		cout << char(4) << " Press 'ctrl + q' to Sort by quantity: Sort items by quantity from highest to lowest.";
		coorxy(3, 14);
		cout << char(4) << " Press 'ctrl + p' to Sort by prices: Sort items by price from lowest to highest";
		coorxy(3, 15);
		cout << char(4) << " Press 'ctrl + a' to Show all products: Displays all available products.";
		coorxy(3, 16);
		cout << char(4) << " Press 'tab' to Search again: Enables searching for another item.";
		coorxy(3, 17);
		cout << char(4) << " Press 'esc' to go back: Return to the previous menu.";
		coorxy(55, 27);
		cout << "page 4";
		break;
	case 4:
		coorxy(55, 6);
		cout << "MY CART";
		coorxy(3, 8);
		cout << "Customers have access to view and manage the items they are going to purchase, allowing";
		coorxy(3, 9);
		cout << "them to adjust the quantities,  remove items, and see the total cost before completing";
		coorxy(3, 10);
		cout << " the transaction process.";
		coorxy(5, 12);
		cout << "Display:";
		coorxy(3, 13);
		cout << char(4) << " Name of the recipient";
		coorxy(3, 14);
		cout << char(4) << " Name of the product/item";
		coorxy(3, 15);
		cout << char(4) << " The Quantity each of item";
		coorxy(3, 16);
		cout << char(4) << " Price of each items";
		coorxy(3, 17);
		cout << char(4) << " Total amount of the item";
		coorxy(3, 18);
		cout << char(4) << " Total cost of the products";
		coorxy(55, 27);
		cout << "page 5";
		break;
	case 5:
		coorxy(55, 6);
		cout << "Guide for Cart option:";
		coorxy(3, 8);
		cout << char(4) << " Press 'Enter' to select the item. Select the highlighted option in the shopping cart.";
		coorxy(3, 9);
		cout << char(4) << " Press 'tab' to re-select: Move the highlight to the next option in the shopping cart.";
		coorxy(3, 10);
		cout << char(4) << " Press 'ctrl + o' to open the receipt: Open the receipt for the selected item.";
		coorxy(5, 11);
		cout << "After selecting an item using 'Enter', pressing 'ctrl + o' allows viewing its receipt.";
		coorxy(3, 12);
		cout << char(4) << " Press 'ctrl + n' to sort by name A-Z: Alphabetically sort the items in";
		coorxy(5, 13);
		cout << "the cart by name for quick identification.";
		coorxy(3, 14);
		cout << char(4) << " Press 'ctrl + q' to sort by quantity (highest to low): Sort items in the cart";
		coorxy(5, 15);
		cout << "by quantity in descending order to identify items with the most stock.";
		coorxy(3, 16);
		cout << char(4) << " Press 'ctrl + p' to sort by price (highest to low): Sort items in the cart";
		coorxy(5, 17);
		cout << "by price in descending order to find the most expensive or cheapest items.";
		coorxy(3, 18);
		cout << char(4) << " Select an item, then press '0' to delete it: Deletes the selected item from";
		coorxy(5, 19);
		cout << "the cart. Ensure the correct item is selected before pressing 'o' to delete.";
		coorxy(3, 20);
		cout << char(4) << " Press 'esc' to go back: Return to the previous menu.";
		coorxy(55, 27);
		cout << "page 6";
		break;
	case 6:
		coorxy(52, 6);
		cout << "Key Knowledge:";
		coorxy(3, 8);
		cout << char(4) << " Keyboard Shortcuts: Provide a swift and efficient way to navigate and manage items in the shopping cart.";
		coorxy(3, 9);
		cout << char(4) << " Sorting: Enables users to organize items based on different criteria, such as name, quantity, or price.";
		coorxy(3, 10);
		cout << char(4) << " Receipt: Displays a summary of the items in the cart, including the total price.";
		coorxy(55, 27);
		cout << "page 7";
		break;
	}
a:
	switch (_getch())
	{
	case 77://right
		key++;
		goto start;
		break;
	case 75://left
		key--;
		goto start;
		break;
	case 224:
		goto a;
		break;
	case 27:
		break;
	default:
		goto start;
		break;
	}
}
void logo(int a, int b) {
	int i, x = 0, y = 0;
	char w, t, d;
	w = char(219);
	d = char(220);
	t = char(223);

	//CPU
	for (i = 0; i < 15; i++) {
		coorxy(5 + a, 3 + y + b);
		cout << w;
		coorxy(20 + a, 3 + y + b);
		cout << w;
		y++;
	}
	for (i = 0; i < 14; i++) {
		coorxy(6 + x + a, 3 + b);
		cout << t;
		coorxy(6 + x + a, 4 + b);
		cout << d;
		coorxy(6 + x + a, 6 + b);
		cout << t;
		coorxy(6 + x + a, 17 + b);
		cout << d;
		x++;
	}

	//MONITOR
	y = 0; x = 0;
	for (i = 0; i < 8; i++) {
		coorxy(20 + a, 8 + y + b);
		cout << string(1, ' ');
		coorxy(14 + a, 8 + y + b);
		cout << w;
		coorxy(41 + a, 8 + y + b);
		cout << w;
		y++;
	}
	for (i = 0; i < 26; i++) {
		coorxy(15 + x + a, 8 + b);
		cout << t;
		coorxy(15 + x + a, 14 + b);
		cout << t;
		coorxy(15 + x + a, 15 + b);
		cout << d;
		x++;
	}

	//MONITOR STAND
	y = 0; x = 0;
	for (i = 0; i < 2; i++) {
		coorxy(27 + a, 16 + y + b);
		cout << w << w;

		y++;
	}
	for (i = 0; i < 10; i++) {
		coorxy(23 + x + a, 17 + b);
		cout << w;

		x++;
	}

}

void b_ex() {

	color(3);
	coorxy(85, 27); cout << "Use ";
	coorxy(100, 27); cout << "to navigate";
	color(1);
	color(6);
	coorxy(89, 27); cout << "Arrow keys ";
	color(1);
	int x = 0, y = 0;
	int a = -29, b = -3;
	x = 70;
	int key = 0, cntr = 0;

	for (int i = 0; i < 40; i++)
	{
		c(3);
		coorxy(x + a, 8 + b); cout << char(205);
		coorxy(x + a, 24 + b); cout << char(205);
		c(1);
		x++;

	}

	y = 8;
	for (int i = 0; i < 16; i++)
	{
		c(3);
		coorxy(70 + a, y + b); cout << char(186);
		coorxy(110 + a, y + b); cout << char(186);
		c(1);
		y++;
	}

	coorxy(70 + a, 8 + b); cout << char(201);
	coorxy(110 + a, 8 + b); cout << char(187);
	coorxy(70 + a, 24 + b); cout << char(200);
	coorxy(110 + a, 24 + b); cout << char(188);
	coorxy(44, 7);
	color(6); cout << "!"; color(1); cout << " Are you sure you want to exit ? "; color(6); cout << "!";

	color(1);
	coorxy(48, 11);
	cout << "YES";

	coorxy(70, 11);
	cout << "NO";

pili:
	if (cntr == 0) {
		color(6);
		coorxy(45, 11);
		cout << ">>";
		coorxy(52, 11);
		cout << "<<";
		color(1);
	}
	if (cntr == 1) {
		color(6);
		coorxy(67, 11);
		cout << ">>";
		coorxy(73, 11);
		cout << "<<";
		color(1);
	}
	
	hideCursor(true);
	switch (_getch())
	{
	case 77:
		if (cntr == 1)cntr = 0;
		else cntr++;
		coorxy(45, 11); cout << string(2, ' ');
		coorxy(52, 11); cout << string(2, ' ');
		coorxy(67, 11); cout << string(2, ' ');
		coorxy(73, 11); cout << string(2, ' ');
		goto pili;
	case 75:
		if (cntr == 0)cntr = 1;
		else cntr--;
		coorxy(45, 11); cout << string(2, ' ');
		coorxy(52, 11); cout << string(2, ' ');
		coorxy(67, 11); cout << string(2, ' ');
		coorxy(73, 11); cout << string(2, ' ');
		goto pili;
	case 13:
		if (cntr == 0)exit(0);
		else break;
	default:
		goto pili;
		break;
	}

}

void opening() {
	initgraph();
	int y = 0, i = 0;
	int radius = 2;

	hideCursor(1);
	while (true) {
		/*circle(250 + y, 450, 30);
		y += 10;
		if (y >= 900) y = 0;
		Sleep(50);
		clrscr();*/

		if (i <= 360) {
			++i;
			//circle(360, 200, 80);
			pieslice(360, 200, 0, i, 80);
			outtextxy(260, 230, "Loading... Please Wait!");

			if (i == 100 || i == 240) delay(1000);
			else if (i == 280) delay(3000);
			else if (i > 280) Sleep(10);
			else delay(20);
		}
		else {
			int num_segments = 360;
			for (int i = 0; i < num_segments; i++) {
				double angle1 = 2 * M_PI * i / num_segments;
				double angle2 = 2 * M_PI * (i + 1) / num_segments;
				int x1 = 360 + (80 + radius) * cos(angle1);
				int y1 = 200 + (80 + radius) * sin(angle1);
				int x2 = 360 + (80 + radius) * cos(angle2);
				int y2 = 200 + (80 + radius) * sin(angle2);
				// Draw the line
				line(x1, y1, x2, y2);
			}
			radius += 5;

		}

		if (radius >= 650) break;
		// Todo expanding circle

		// Monitor
		rectangle(100, 50, 600, 55);  // Top edge
		rectangle(100, 350, 600, 355); // Bottom edge
		rectangle(100, 50, 105, 350);  // Left edge
		rectangle(600, 50, 605, 355);  // Right edge

		// Monitor stand
		rectangle(280, 350, 420, 355);  // Top edge of stand
		rectangle(280, 400, 420, 405);  // Bottom edge of stand
		rectangle(280, 350, 285, 400);  // Left edge of stand
		rectangle(420, 350, 425, 400);  // Right edge of stand
		rectangle(150, 400, 550, 410);  // Bottom stand 

		// CPU 
		rectangle(650, 50, 850, 55);   // Top edge of CPU
		rectangle(650, 450, 850, 455); // Bottom edge of CPU
		rectangle(650, 50, 655, 450);  // Left edge of CPU
		rectangle(850, 50, 855, 450);  // Right edge of CPU

		// CPU details
		rectangle(680, 135, 820, 140); // CD/DVD slot
		rectangle(680, 100, 820, 120); // CD/DVD slot RECTANGLE
		rectangle(720, 300, 790, 305); // Button outline (top)
		rectangle(720, 355, 790, 350); // Button outline (bottom)
		rectangle(720, 300, 725, 350); // Button outline (left)
		rectangle(790, 300, 795, 355); // Button outline (right)


		// Loading Screen
		/*rectangle(250,270,450,290);*/
	}
}