#ifndef MEDICINE_H
#define MEDICINE_H

#include <string>
#include <iostream>
#include <vector>
#include "../utils/Date.h"
class Medicine {
private:
	std::string _medicineId;
	std::string _name;
	std::string _type;
	int _quantity;
	double _price;
	Date _expiryDate;
public:
	Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price, const Date& expiryDate);
	Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price, const std::string& expiryDate);
	Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price);
	Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price, int day, int month, int year);
	Medicine(const std::string& id, const std::string& name, const std::string& type, int quantity, double price, int days);
	~Medicine();
	void addStock(int quantity);
	bool checkAvailability();
	void getMedicineDetail();
	void setMedicineId(const std::string& id);
	void setName(const std::string& name);
	void setType(const std::string& type);
	void setQuantity(int quantity);
	std::string id();
	std::string name();
	std::string type();
	int quantity();
	double price();
	Date expiryDate();
};

#endif
