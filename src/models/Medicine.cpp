#include "Medicine.h"


Medicine::Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price
	, const Date& expiryDate) : _expiryDate(expiryDate) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price
	, const std::string& expiryDate) : _expiryDate(expiryDate) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price) : _expiryDate(Date::getDate()) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price
	, int day, int month, int year) : _expiryDate(day, month, year) {
	_medicineId = id;
	_name = name;
	_type = type;
	_quantity = quantity;
	_price = price;
}

Medicine::Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price
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
	std::cout << "Medicine ID: " << _medicineId << " ";
	std::cout << "Name: " << _name << " ";
	std::cout << "Type: " << _type << " ";
	std::cout << "Quantity: " << _quantity << " ";
	std::cout << "Price: " << _price << " ";
	std::cout << "Expiry Date: " << _expiryDate << " ";
}

bool Medicine::checkAvailability() {
	return (_quantity > 0);
}

