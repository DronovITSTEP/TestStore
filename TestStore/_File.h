#pragma once
#include <iostream>
#include <vector>
#include "Tovar.h"

using namespace std;

class _File
{
private:
	string path = "";
	string name = "";
	vector<Product*> products;
public:
	bool Open(string namefile, string path="");
	bool Save(string path, string namefile, vector<Product*> prods);
	vector<Product*> GetProducts();
};

