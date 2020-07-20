#pragma once

#include <vector>

struct Problem {
	WCHAR library[100];
	char method[100];
	char descrption[100];
	char detail[512];
};

struct Page {
	char title[100];
	std::vector<Problem> problems;
};

struct Menu {
	char title[100];
	std::vector<Page> pages;
};

void SetMenu(Menu*);
void Start(Menu*);
