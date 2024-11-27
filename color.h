#pragma once
#include <Windows.h>
using namespace std;

void color(int x) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
}