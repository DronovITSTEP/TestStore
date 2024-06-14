#pragma once
#include <iostream>
#include "Tovar.h"

using namespace std;

class _File
{
public:
	string path = "";
	string name = "";

	void Open(string path, string namefile, char* type_of_access, Product*& products);
	void Save(string path, string namefile, char* type_of_access, Product* products);
};

