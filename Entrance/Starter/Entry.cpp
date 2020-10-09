#include <cstring>
#include <iostream>

#include "windows.h"
#include "Entry.h"

void LeetCode(Platform*);
void ProjectEuler(Platform*);

void LeetP01(Page*);
void LeetP02(Page*);
void EulerP01(Page*);

void SetMenu(Menu* menu) {
	memset(menu, 0, sizeof(Menu));

	strcpy_s(menu->title, "LeetCode");

	Platform* form = new(std::nothrow)Platform;
	LeetCode(form);
	menu->forms.push_back(*form);

	form = new(std::nothrow)Platform;
	ProjectEuler(form);
	menu->forms.push_back(*form);
}

void LeetCode(Platform* plat) {
	strcpy_s(plat->title, "LeetCode");

	Page* page = new(std::nothrow)Page;
	LeetP01(page);
	plat->pages.push_back(*page);

	page = new(std::nothrow)Page;
	LeetP02(page);
	plat->pages.push_back(*page);
}

void ProjectEuler(Platform* plat) {
	strcpy_s(plat->title, "Project Euler");

	Page* page = new(std::nothrow)Page;
	EulerP01(page);
	plat->pages.push_back(*page);
}

void LeetP01(Page* page) {
	strcpy_s(page->title, "Page 1");
	Problem* p;

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "TwoSum");
	strcpy_s(p->descrption, "Two Sum");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "VeriList");
	strcpy_s(p->descrption, "Verify Arrays");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "Round");
	strcpy_s(p->descrption, "Round");
	page->problems.push_back(*p);
}

void LeetP02(Page* page) {
	strcpy_s(page->title, "Page 2");

	Problem* p;

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "add1");
	strcpy_s(p->descrption, "Add");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "add2");
	strcpy_s(p->descrption, "Substruct");
	page->problems.push_back(*p);
}

void EulerP01(Page* page) {
	strcpy_s(page->title, "Page 1");
	Problem* p;

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "TwoSum");
	strcpy_s(p->descrption, "Two Sum");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "VeriList");
	strcpy_s(p->descrption, "Verify Arrays");
	page->problems.push_back(*p);

	p = new(std::nothrow)Problem;
	wcscpy_s(p->library, L"Problems01_10");
	strcpy_s(p->method, "Round");
	strcpy_s(p->descrption, "Round");
	page->problems.push_back(*p);
}

void StartForm(Platform*);
void StartPage(Page*);

void Start(Menu* menu) {
	int i;

	while (true) {
		std::cout << menu->title << std::endl;

		for (i = 0; i < menu->forms.size(); i++)
			std::cout << (i + 1) << ". " << menu->forms.at(i).title << std::endl;
		std::cout << (i + 1) << ". " << "Exit" << std::endl;

		while (true) {
			std::cin >> i;

			if (i == menu->forms.size() + 1)
				return;

			if (i >= 1 && i <= menu->forms.size()) {
				StartForm(&menu->forms.at(i - 1));
				break;
			}
		}
	}
}

void StartForm(Platform* form) {
	int i;

	while (true) {
		std::cout << form->title << std::endl;

		for (i = 0; i < form->pages.size(); i++)
			std::cout << (i + 1) << ". " << form->pages.at(i).title << std::endl;
		std::cout << (i + 1) << ". " << "Exit" << std::endl;

		while (true) {
			std::cin >> i;

			if (i == form->pages.size() + 1)
				return;

			if (i >= 1 && i <= form->pages.size()) {
				StartPage(&form->pages.at(i - 1));
				break;
			}
		}
	}
}

void StartPage(Page* page) {
	int i;

	while (true) {
		std::cout << page->title << std::endl;

		for (i = 0; i < page->problems.size(); i++)
			std::cout << (i + 1) << ". " << page->problems.at(i).descrption << std::endl;
		std::cout << (i + 1) << ". " << "Exit" << std::endl;

		while (true) {
			std::cin >> i;

			if (i == page->problems.size() + 1)
				return;

			if (i >= 1 && i <= page->problems.size()) {
				HINSTANCE hDllInst;
				hDllInst = LoadLibrary(page->problems.at(i - 1).library);
				typedef void(*PLUSFUNC)();
				PLUSFUNC run = (PLUSFUNC)GetProcAddress(hDllInst, page->problems.at(i - 1).method);
				run();
				break;
			}
		}
	}
}
