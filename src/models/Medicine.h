#ifndef MEDICINE_H_
#define MEDICINE_H_

#include <string>
#include <iostream>
#include <vector>
#include "../utils/Date.h"
using std::cout;
using std::string;
class Medicine {
private:
	string _medicineId;
	string _name;
	string _type;
	int _quantity;
	double _price;
	Date _expiryDate;
public:
	Medicine(const string& id, const string& name, const string& type, int quantity, double price, const Date& expiryDate);
	Medicine(const string& id, const string& name, const string& type, int quantity, double price, const string& expiryDate);
	Medicine(const string& id, const string& name, const string& type, int quantity, double price);
	Medicine(const string& id, const string& name, const string& type, int quantity, double price, int day, int month, int year);
	Medicine(const string& id, const string& name, const string& type, int quantity, double price, int days);
	~Medicine();
	void addStock(int quantity);
	bool checkAvailability();
	void getMedicineDetail();
	void setMedicineId(const string& id);
	void setName(const string& name);
	void setType(const string& type);
	void setQuantity(int quantity);
	string id();
	string name();
	string type();
	int quantity();
	double price();
	Date expiryDate();
};
#endif // !MEDICINE_H_
