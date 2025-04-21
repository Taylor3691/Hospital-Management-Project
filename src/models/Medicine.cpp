#include "Medicine.h"


Medicine::Medicine(const string& id, const string& name, const string& type, int quantity, double price
	, const Date& expiryDate) : _expiryDate(expiryDate) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const string& id, const string& name, const string& type, int quantity, double price
	, const string& expiryDate) : _expiryDate(expiryDate) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const string& id, const string& name, const string& type, int quantity, double price) : _expiryDate(Date::getDate()) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const string& id, const string& name, const string& type, int quantity, double price
	, int day, int month, int year) : _expiryDate(day, month, year) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const string& id, const string& name, const string& type, int quantity, double price
	, int days) : _expiryDate(days) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::~Medicine() {
	// Destructor
}

void Medicine::addStock(int quantity) {
	_quantity += quantity;
}

void Medicine::getMedicineDetail() {
	cout << "Medicine ID: " << _medicineId << " ";
	cout << "Name: " << _name << " ";
	cout << "Type: " << _type << " ";
	cout << "Quantity: " << _quantity << " ";
	cout << "Price: " << _price << " ";
	cout << "Expiry Date: " << _expiryDate << " ";
}