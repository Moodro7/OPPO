
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct tovar {
	int yyyy, mm, dd;
	string name;
	int quant;
};

int main()
{
	setlocale(0, "");

	vector<tovar> tovars;

	ifstream ist("in.txt");
	if (!ist.is_open()) {
		cout << "Файл не найден";
		return 0;
	}

	tovar item;
	while (!ist.eof()) {
		ist >> item.yyyy;
		ist.get();
		ist >> item.mm;
		ist.get();
		ist >> item.dd;
		ist.get();
		ist >> item.name >> item.quant;
		tovars.push_back(item);
	}
	ist.close();

	for (const tovar& t : tovars) {
		cout << "Дата: " << t.yyyy << "." << t.mm << "." << t.dd << endl;
		cout << "Название: " << t.name << endl;
		cout << "Количество: " << t.quant << endl;
	}

	return 0;
}
