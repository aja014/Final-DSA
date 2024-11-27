#pragma once
#include <iostream>
#include <Windows.h>
#include "Headers.h"
#include "color.h"
#include "Graphics.h"

using namespace std;

void b_login()
{
	//sa login at create account
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
		coorxy( x, 1);
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
	
	//box

	//user
	x = 45+30;
	for (int i = 0; i < 21; i++)
	{
		coorxy(x, 7);
		cout << char(205);

		coorxy(x, 9);
		cout << char(205);

		coorxy(x, 13);
		cout << char(205);

		coorxy(x, 15);
		cout << char(205);
		x++;
	}
	//top corner (1st box)
	coorxy(44+30, 7); cout << char(201);
	coorxy(66+30, 7); cout << char(187);
	//bot corner(1st box)
	coorxy(66+30, 9); cout << char(188);
	coorxy(44+30,9); cout << char(200);

	// top corner (2nd box)
	coorxy(44+30, 13); cout << char(201);
	coorxy(66+30,13); cout << char(187);
	//bot corner(2st box)
	coorxy(66+30, 15); cout << char(188);
	coorxy(44+30, 15); cout << char(200);



}
void front_a(int a) // unang window
{
	color(3);
	coorxy(85, 27); cout << "Use ";
	coorxy(100, 27); cout << "to navigate";
	color(1);
	color(6);
	coorxy(89, 27); cout << "Arrow keys ";
	color(1);

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int x = 0, y = 0;

	x = 70 + 10;
	for (int i = 0; i < 21; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(x, 3); cout << char(205);
		coorxy(x, 7); cout << char(205);
		SetConsoleTextAttribute(hConsole, 1);
		x++;

	}

	y = 3;
	for (int i = 0; i < 4; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(70 + 10, y); cout << char(186);
		coorxy(71 + 30, y); cout << char(186);
		SetConsoleTextAttribute(hConsole, 1);
		y++;

	}
	coorxy(70 + 10, 3); cout << char(201);
	coorxy(91 + 10, 3); cout << char(187);
	coorxy(70 + 10, 7); cout << char(200);
	coorxy(91 + 10, 7); cout << char(188);

	SetConsoleTextAttribute(hConsole, 3);
	coorxy(72 + 10, 5 + a); cout << "Welcome to";
	SetConsoleTextAttribute(hConsole, 1);

	SetConsoleTextAttribute(hConsole, 6);
	coorxy(83 + 10, 5 + a); cout << "Hi";
	SetConsoleTextAttribute(hConsole, 1);

	SetConsoleTextAttribute(hConsole, 3);
	coorxy(85 + 10, 5 + a); cout << "-Tech";
	SetConsoleTextAttribute(hConsole, 1);

	//small box
	x = 70;

	for (int i = 0; i < 40; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(x, 8); cout << char(205);
		coorxy(x, 24); cout << char(205);
		SetConsoleTextAttribute(hConsole, 1);
		x++;

	}

	y = 8;
	for (int i = 0; i < 16; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(70, y); cout << char(186);
		coorxy(110, y); cout << char(186);
		SetConsoleTextAttribute(hConsole, 1);
		y++;
	}

	coorxy(70, 8); cout << char(201);
	coorxy(110, 8); cout << char(187);
	coorxy(70, 24); cout << char(200);
	coorxy(110, 24); cout << char(188);



	// big box
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
void front_b(int a) // unang window
{
	
	color(3);
	coorxy(85, 27); cout << "Use ";
	coorxy(100, 27); cout << "to navigate";
	color(1);
	color(6);
	coorxy(89, 27); cout << "Arrow keys ";
	color(1);
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	int x = 0, y = 0;

	x = 70 + 10;
	for (int i = 0; i < 21; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(x, 3); cout << char(205);
		coorxy(x, 7); cout << char(205);
		SetConsoleTextAttribute(hConsole, 1);
		x++;

	}

	y = 3;
	for (int i = 0; i < 4; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(70 + 10, y); cout << char(186);
		coorxy(71 + 30, y); cout << char(186);
		SetConsoleTextAttribute(hConsole, 1);
		y++;

	}
	coorxy(70 + 10, 3); cout << char(201);
	coorxy(91 + 10, 3); cout << char(187);
	coorxy(70 + 10, 7); cout << char(200);
	coorxy(91 + 10, 7); cout << char(188);
	
	SetConsoleTextAttribute(hConsole, 3);
	coorxy(72 + 10, 5 + a); cout << "Welcome to";
	SetConsoleTextAttribute(hConsole, 1);

	SetConsoleTextAttribute(hConsole, 6);
	coorxy(83 + 10, 5 + a); cout << "Hi";
	SetConsoleTextAttribute(hConsole, 1);

	SetConsoleTextAttribute(hConsole, 3);
	coorxy(85 + 10, 5 + a); cout << "-Tech";
	SetConsoleTextAttribute(hConsole, 1);

	//small box
	x = 70;

	for (int i = 0; i < 40; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(x, 10); cout << char(205);
		coorxy(x, 23); cout << char(205);
		SetConsoleTextAttribute(hConsole, 1);
		x++;

	}

	y = 10;
	for (int i = 0; i < 13; i++)
	{
		SetConsoleTextAttribute(hConsole, 3);
		coorxy(70, y); cout << char(186);
		coorxy(110, y); cout << char(186);
		SetConsoleTextAttribute(hConsole, 1);
		y++;
	}

	coorxy(70,10); cout << char(201);
	coorxy(110,10); cout << char(187);
	coorxy(70,23); cout << char(200);
	coorxy(110,23); cout << char(188);



	// big box
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
void buy_part()
{
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

	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);
}

void my_cart()
{
	//sa my cart (user)
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

	//small box
	//int x = 0; y = 0;
	x = 7;
	for (int i=0; i < 12; i++)
	{
		coorxy(x, 4); cout << char(205);

		coorxy(x, 8); cout << char(205);
		x++;

	}

	y = 4;

	for (int i = 0; i < 4; i++)
	{
		coorxy(7, y); cout << char(186);
		coorxy(7+12, y); cout << char(186);
		y++;
	}

	coorxy(7, 4); cout << char(201);
	coorxy(19, 4); cout << char(187);
	coorxy(7, 8); cout << char(200);
	coorxy(19, 8); cout << char(188);


	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);
}
void admin_b()
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

void user_b()
{
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

void manprod_b() //manage product border
{
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

	// small box for search bar
	x = 3;
	for (int i = 0; i < 24; i++)
	{
		coorxy(x, 2); cout << char(205);

		coorxy(x, 4); cout << char(205);
		x++;

	}

	y = 2;

	for (int i = 0; i < 2; i++)
	{
		coorxy(3, y); cout << char(186);
		coorxy(26, y); cout << char(186);
		y++;
	}

	coorxy(3, 2); cout << char(201);
	coorxy(26, 2); cout << char(187);
	coorxy(3, 4); cout << char(200);
	coorxy(26, 4); cout << char(188);

	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);
}

void man_acc_b() // manage account
{
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
	
	x = 2;
	for (int i = 0; i < 116; i++)
	{
		coorxy(x, 2); cout << char(205);
		coorxy(x, 4); cout << char(205);
		x++;
	}
	y = 3;
	for (int i = 0; i < 23; i++)
	{
		coorxy(58, y); cout << char(186);
		y++;
	}

	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);
}
void man_acc2_b() // for user's cart
{
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

	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);



} 

void recS_b()
{
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
	color(3);
	coorxy(10, 27); cout << "Press ";
	color(1);

	color(6);
	coorxy(16, 27); cout << "'Esc'";
	color(1);
	color(3);
	coorxy(22, 27); cout << "to go back";
	color(1);
}