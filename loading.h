#pragma once
#include <iostream>
#include "Headers.h"
#include <Windows.h>
#include "Graphics.h"

#define g coorxy

using namespace std;


void ldscreen1() {
	int i;


	//g(25, 10);
	//cout << "Hello world";

	//g(50, 10);
	//font(30, 40, 600);
	//cout << "Hello sayu!";

	//border animation
	for (i = 0; i <= 95; i++) {
		g(12 + i, 12);
		cout << char(219);
		g(12 + i, 12);
		cout << char(219);
	}
	for (i = 0; i <= 0; i++) {
		g(12, 12 + i);
		cout << char(219);
		g(107, 12 + i);
		cout << char(219);
	}
	delay(250);
	for (i = 0; i <= 97; i++) {
		g(11 + i, 11);
		cout << char(219);
		g(11 + i, 13);
		cout << char(219);
	}
	for (i = 0; i <= 2; i++) {
		g(11, 11 + i);
		cout << char(219);
		g(108, 11 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 97; i++) {
		g(11 + i, 11);
		cout << char(219);
		g(11 + i, 13);
		cout << char(219);
	}
	for (i = 0; i <= 2; i++) {
		g(11, 11 + i);
		cout << char(219);
		g(108, 11 + i);
		cout << char(219);
	}
	for (i = 0; i <= 99; i++) {
		g(10 + i, 10);
		cout << char(219);
		g(10 + i, 14);
		cout << char(219);
	}
	for (i = 0; i <= 4; i++) {
		g(10, 10 + i);
		cout << char(219);
		g(109, 10 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 99; i++) {
		g(10 + i, 10);
		cout << char(219);
		g(10 + i, 14);
		cout << char(219);
	}
	for (i = 0; i <= 4; i++) {
		g(10, 10 + i);
		cout << char(219);
		g(109, 10 + i);
		cout << char(219);
	}
	for (i = 0; i <= 101; i++) {
		g(9 + i, 9);
		cout << char(219);
		g(9 + i, 15);
		cout << char(219);
	}
	for (i = 0; i <= 6; i++) {
		g(9, 9 + i);
		cout << char(219);
		g(110, 9 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 101; i++) {
		g(9 + i, 9);
		cout << char(219);
		g(9 + i, 15);
		cout << char(219);
	}
	for (i = 0; i <= 6; i++) {
		g(9, 9 + i);
		cout << char(219);
		g(110, 9 + i);
		cout << char(219);
	}
	for (i = 0; i <= 103; i++) {
		g(8 + i, 8);
		cout << char(219);
		g(8 + i, 16);
		cout << char(219);
	}
	for (i = 0; i <= 8; i++) {
		g(8, 8 + i);
		cout << char(219);
		g(111, 8 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 103; i++) {
		g(8 + i, 8);
		cout << char(219);
		g(8 + i, 16);
		cout << char(219);
	}
	for (i = 0; i <= 8; i++) {
		g(8, 8 + i);
		cout << char(219);
		g(111, 8 + i);
		cout << char(219);
	}
	for (i = 0; i <= 105; i++) {
		g(7 + i, 7);
		cout << char(219);
		g(7 + i, 17);
		cout << char(219);
	}
	for (i = 0; i <= 10; i++) {
		g(7, 7 + i);
		cout << char(219);
		g(112, 7 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 105; i++) {
		g(7 + i, 7);
		cout << char(219);
		g(7 + i, 17);
		cout << char(219);
	}
	for (i = 0; i <= 10; i++) {
		g(7, 7 + i);
		cout << char(219);
		g(112, 7 + i);
		cout << char(219);
	}
	for (i = 0; i <= 107; i++) {
		g(6 + i, 6);
		cout << char(219);
		g(6 + i, 18);
		cout << char(219);
	}
	for (i = 0; i <= 12; i++) {
		g(6, 6 + i);
		cout << char(219);
		g(113, 6 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 107; i++) {
		g(6 + i, 6);
		cout << char(219);
		g(6 + i, 18);
		cout << char(219);
	}
	for (i = 0; i <= 12; i++) {
		g(6, 6 + i);
		cout << char(219);
		g(113, 6 + i);
		cout << char(219);
	}
	for (i = 0; i <= 109; i++) {
		g(5 + i, 5);
		cout << char(219);
		g(5 + i, 19);
		cout << char(219);
	}
	for (i = 0; i <= 14; i++) {
		g(5, 5 + i);
		cout << char(219);
		g(114, 5 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 109; i++) {
		g(5 + i, 5);
		cout << char(219);
		g(5 + i, 19);
		cout << char(219);
	}
	for (i = 0; i <= 14; i++) {
		g(5, 5 + i);
		cout << char(219);
		g(114, 5 + i);
		cout << char(219);
	}
	for (i = 0; i <= 111; i++) {
		g(4 + i, 4);
		cout << char(219);
		g(4 + i, 20);
		cout << char(219);
	}
	for (i = 0; i <= 16; i++) {
		g(4, 4 + i);
		cout << char(219);
		g(115, 4 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 111; i++) {
		g(4 + i, 4);
		cout << char(219);
		g(4 + i, 21);
		cout << char(219);
	}
	for (i = 0; i <= 16; i++) {
		g(4, 4 + i);
		cout << char(219);
		g(115, 4 + i);
		cout << char(219);
	}
	for (i = 0; i <= 113; i++) {
		g(3 + i, 3);
		cout << char(219);
		g(3 + i, 22);
		cout << char(219);
	}
	for (i = 0; i <= 18; i++) {
		g(3, 3 + i);
		cout << char(219);
		g(116, 3 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 113; i++) {
		g(3 + i, 3);
		cout << char(219);
		g(3 + i, 22);
		cout << char(219);
	}
	for (i = 0; i <= 18; i++) {
		g(3, 3 + i);
		cout << char(219);
		g(116, 3 + i);
		cout << char(219);
	}
	for (i = 0; i <= 115; i++) {
		g(2 + i, 2);
		cout << char(219);
		g(2 + i, 23);
		cout << char(219);
	}
	for (i = 0; i <= 20; i++) {
		g(2, 2 + i);
		cout << char(219);
		g(117, 2 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 115; i++) {
		g(2 + i, 2);
		cout << char(219);
		g(2 + i, 23);
		cout << char(219);
	}
	for (i = 0; i <= 20; i++) {
		g(2, 2 + i);
		cout << char(219);
		g(117, 2 + i);
		cout << char(219);
	}
	for (i = 0; i <= 117; i++) {
		g(1 + i, 1);
		cout << char(219);
		g(1 + i, 24);
		cout << char(219);
	}
	for (i = 0; i <= 22; i++) {
		g(1, 1 + i);
		cout << char(219);
		g(118, 1 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 117; i++) {
		g(1 + i, 1);
		cout << char(219);
		g(1 + i, 24);
		cout << char(219);
	}
	for (i = 0; i <= 22; i++) {
		g(1, 1 + i);
		cout << char(219);
		g(118, 1 + i);
		cout << char(219);
	}
	for (i = 0; i <= 119; i++) {
		g(0 + i, 0);
		cout << char(219);
		g(0 + i, 25);
		cout << char(219);
	}
	for (i = 0; i <= 24; i++) {
		g(0, 0 + i);
		cout << char(219);
		g(119, 0 + i);
		cout << char(219);
	}
	delay(250);
	system("cls");
	for (i = 0; i <= 119; i++) {
		g(0 + i, 0);
		cout << char(219);
		g(0 + i, 25);
		cout << char(219);
	}
	for (i = 0; i <= 24; i++) {
		g(0, 0 + i);
		cout << char(219);
		g(119, 0 + i);
		cout << char(219);
	}

	//hehe

	for (i = 0; i <= 13; i++) {
		g(13 + i, 5);
		cout << char(219);
		g(13 + i, 12);
		cout << char(219);
	}
	for (i = 0; i <= 5; i++) {
		g(12, 6 + i);
		cout << char(219);
		g(27, 6 + i);
		cout << char(219);
	}
	g(13, 6);
	cout << char(219);
	g(26, 6);
	cout << char(219);
	g(13, 11);
	cout << char(219);
	g(26, 11);
	cout << char(219);
	for (i = 0; i <= 11; i++) {
		g(14 + i, 7);
		cout << char(219);
		g(14 + i, 10);
		cout << char(219);
	}
	for (i = 0; i <= 3; i++) {
		g(14, 7 + i);
		cout << char(219);
		g(25, 7 + i);
		cout << char(219);
	}

	for (i = 0; i <= 13; i++) {
		g(93 + i, 5);
		cout << char(219);
		g(93 + i, 12);
		cout << char(219);
	}
	for (i = 0; i <= 5; i++) {
		g(92, 6 + i);
		cout << char(219);
		g(107, 6 + i);
		cout << char(219);
	}
	g(93, 6);
	cout << char(219);
	g(106, 6);
	cout << char(219);
	g(93, 11);
	cout << char(219);
	g(106, 11);
	cout << char(219);
	for (i = 0; i <= 11; i++) {
		g(94 + i, 7);
		cout << char(219);
		g(94 + i, 10);
		cout << char(219);
	}
	for (i = 0; i <= 3; i++) {
		g(94, 7 + i);
		cout << char(219);
		g(105, 7 + i);
		cout << char(219);
	}

	//delay(3000);
	system("cls");
	g(0, 29);
	//system("pause");
}

void ldscreen() {
	int i, x = 35, y = 18, a = 0, b = 0;

	color(3);
	// Hi - Tech

	logo(37, 2);

	//
	for (i = 0; i <= 4; i++) {
		g(4 + i + a + x, 5 + b + y);
		cout << char(223);
	}
	g(4 + a + x, 3 + b + y);
	cout << char(219);
	g(4 + a + x, 7 + b + y);
	cout << char(223);
	g(8 + a + x, 3 + b + y);
	cout << char(219);
	g(8 + a + x, 7 + b + y);
	cout << char(223);
	for (i = 0; i <= 2; i++) {
		g(4 + a + x, 4 + i + b + y);
		cout << char(219);
		g(8 + a + x, 4 + i + b + y);
		cout << char(219);
	}

	//i
	for (i = 0; i <= 2; i++) {
		g(11 + x, 3 + y);
		cout << char(223);
		g(11 + x, 5 + i + y);
		cout << char(219);
		g(11 + x, 7 + y);
		cout << char(223);
	}

	//-
	for (i = 0; i <= 4; i++) {
		g(15 + i + x, 4 + y);
		cout << char(220);
		g(15 + i + x, 5 + y);
		cout << char(223);
	}

	//T
	for (i = 0; i <= 6; i++) {
		g(21 + i + x, 3 + y);
		cout << char(223);
	}
	g(24 + a + x, 3 + b + y);
	cout << char(219);
	g(24 + a + x, 7 + b + y);
	cout << char(223);
	for (i = 0; i <= 2; i++) {
		g(24 + a + x, 4 + i + b + y);
		cout << char(219);
	}

	//e
	for (i = 0; i <= 1; i++) {
		g(28 + i + a + x, 4 + b + y);
		cout << char(220);
		g(28 + i + a + x, 6 + b + y);
		cout << char(223);
		g(28 + i + a + x, 7 + b + y);
		cout << char(223);
	}
	for (i = 0; i <= 1; i++) {
		g(27 + a + x, 5 + i + b + y);
		cout << char(219);
		g(30 + a + x, 5 + b + y);
		cout << char(219);
	}

	//c
	for (i = 0; i <= 2; i++) {
		g(34 + i + a + x, 4 + b + y);
		cout << char(220);
		g(34 + i + a + x, 7 + b + y);
		cout << char(223);
	}
	for (i = 0; i <= 1; i++) {
		g(33 + a + x, 5 + i + b + y);
		cout << char(219);
		/*g(15 + a + x, 5 + i + b + y);
		cout << char(219);*/
	}

	//h
	for (i = 0; i <= 2; i++) {
		g(40 + i + x, 4 + y);
		cout << char(220);
	}
	for (i = 0; i <= 1; i++) {
		g(43 + x, 5 + i + y);
		cout << char(219);
	}
	for (i = 0; i <= 3; i++) {
		g(39 + a + x, 3 + i + b + y);
		cout << char(219);
	}
	g(39 + x, 7 + y);
	cout << char(223);
	g(43 + x, 7 + y);
	cout << char(223);

	for (i = 0; i <= 59; i++) {
		g(59 - i, 0);
		cout << char(219);
		g(60 + i, 29);
		cout << char(219);
		delay(10);
	}
	for (i = 0; i <= 29; i++) {
		g(0, 0 + i);
		cout << char(219);
		g(119, 29 - i);
		cout << char(219);
		delay(10);
	}
	for (i = 0; i <= 59; i++) {
		g(0 + i, 29);
		cout << char(219);
		g(119 - i, 0);
		cout << char(219);
		delay(10);
	}



	delay(3000);
	system("cls");
}

void drawMonitorOpeningAnimation() {
	initgraph();

	int centerX = getmaxx() / 2; // Center of the screen horizontally
	int centerY = getmaxy() / 2; // Center of the screen vertically
	int width = 300; // Monitor width
	int height = 200; // Monitor height

	int screenFillHeight = 0; // Start with no screen area filled
	int fillStep = 5; // How many pixels to fill per frame

	// Draw monitor frame
	setcolorRGB(255, 255, 255); // White color
	rectangle(centerX - width / 2, centerY - height / 2, centerX + width / 2, centerY + height / 2);

	// Simulate the screen turning on by gradually filling it
	while (screenFillHeight <= height - 40) { // -40 to leave room for monitor edges
		setcolorRGB(0, 255, 0); // Greenish fill for the screen
		rectangle(centerX - width / 2 + 20, centerY - screenFillHeight / 2,
			centerX + width / 2 - 20, centerY + screenFillHeight / 2);

		screenFillHeight += fillStep;
		Sleep(50); // Delay for smoother animation
	}

	// Draw final filled screen
	setcolorRGB(0, 255, 0);
	rectangle(centerX - width / 2 + 20, centerY - height / 2 + 20, centerX + width / 2 - 20, centerY + height / 2 - 20);

	Sleep(2000); // Pause to display final screen
	clrscr();    // Clear screen before exiting
}