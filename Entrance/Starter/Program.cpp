#include <iostream>
#include "Entry.h"

int main() {
	struct Menu* menu = new(std::nothrow)Menu;
	SetMenu(menu);
	Start(menu);

	return 0;
}