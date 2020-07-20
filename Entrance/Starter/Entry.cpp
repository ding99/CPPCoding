#include <cstring>
#include <iostream>

#include "windows.h"
#include "Entry.h"

void Page1(Page*);
void Page2(Page*);

void SetMenu(Menu* menu) {
	memset(menu, 0, sizeof(Menu));

	strcpy_s(menu->title, "LeetCode");
	
	Page* page = new(std::nothrow)Page;
	Page1(page);
	menu->pages.push_back(*page);
	page = new(std::nothrow)Page;
	Page2(page);
	menu->pages.push_back(*page);
}

void Page1(Page* page) {
	strcpy_s(page->title, "Page 1");
	Problem* p;

	p = new(std::nothrow)Problem;
	///memset(&p, 0, sizeof(Problem));
	wcscpy_s(p->library,L"Problems01_10");
	strcpy_s(p->method, "add1");
	strcpy_s(p->descrption, "Add");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	//memset(&p, 0, sizeof(Problem));
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "add2");
	strcpy_s(p->descrption, "Substruct");
	page->problems.push_back(*p);
}

void Page2(Page* page) {
	strcpy_s(page->title, "Page 2");

	Problem* p;

	p = new(std::nothrow)Problem;
	//memset(&p, 0, sizeof(Problem));
	wcscpy_s(p->library, L"Problems11_20");
	strcpy_s(p->method, "add1");
	strcpy_s(p->descrption, "Add");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	//memset(&p, 0, sizeof(Problem));
	wcscpy_s(p->library, L"Problems11_20");
	strcpy_s(p->method, "add2");
	strcpy_s(p->descrption, "Substruct");
	page->problems.push_back(*p);
}

void SubStart(Page*);

void Start(Menu* menu) {
	int select;

	while (true) {
		std::cout << menu->title << std::endl;

		int i = 0;
		for (i = 0; i < menu->pages.size(); i++)
			std::cout << (i + 1) << ". " << menu->pages.at(i).title << std::endl;
		std::cout << (i + 1) << ". " << "Exit" << std::endl;

		while (true) {
			std::cin >> i;

			if (i == menu->pages.size() + 1)
				return;

			if (i >= 1 && i <= menu->pages.size()) {
				SubStart(&menu->pages.at(i - 1));
			}
		}
	}
}

void SubStart(Page* page) {
	int i;

	while (true) {
		std::cout << page->title << std::endl;

		i = 0;
		for (i = 0; i < page->problems.size(); i++) {
			std::cout << (i + 1) << ". " << page->problems.at(i).descrption << std::endl;
		}
		std::cout << (i + 1) << ". " << "Exit" << std::endl;

		while (true) {
			std::cin >> i;

			if (i == page->problems.size() + 1)
				return;

			if (i >= 1 && i <= page->problems.size()) {
				HINSTANCE hDllInst;
				hDllInst = LoadLibrary(page->problems.at(i - 1).library);
				typedef void(*PLUSFUNC)();
				PLUSFUNC plus_str = (PLUSFUNC)GetProcAddress(hDllInst, page->problems.at(i - 1).method);
			}
		}
	}
}
