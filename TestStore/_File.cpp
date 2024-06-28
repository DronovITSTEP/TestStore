#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "_File.h"

bool _File::Open(string namefile, string path) {
	std::ifstream file(path + namefile);
	if (file.is_open()) {

		string name;
		float price;
		int count;

		string line;
		while (std::getline(file, line)) {
			istringstream iss(line);
			iss >> name
				>> price
				>> count;
			products.push_back(new Product{
				name,
				price,
				count
				});
		}
		file.close();
		return true;
	}
	else
		cout << "no file";
	return false;
}

bool _File::Save(string path, string namefile, vector<Product*> prods) {
	ofstream out(path + namefile);
	if (out.is_open()) {
		for (auto prod : prods) {
			out << prod->name << prod->price << prod->count << "\n";
		}
		out.close();
		return true;
	}
	return false;
}

vector<Product*> _File::GetProducts() {
	return products;
}

