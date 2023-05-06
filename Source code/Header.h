#ifndef _FUNCTION_H_
#define _FUNCTION_H_

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <memory>
using namespace std;

class OmegaCompany;
class DailyEmployee;
class HourlyEmployee;
class ProductEmployee;
class Manager;
class Factory;

class OmegaCompany {
public:
	virtual int FinalPayment() = 0;
	virtual void print() { cout << "Nothing" << endl; }
	virtual string ConvertPayment() = 0;
	virtual shared_ptr<OmegaCompany>clone(string str1, string str2) = 0;
};

class DailyEmployee : public OmegaCompany {
private:
	string Name;
	int DailyPayment;
	int TotalDays;
public:
	string getName() { return this->Name; }
	void setName(string val) { this->Name = val; }
	int getDailyPayment() { return this->DailyPayment; }
	void setDailyPayment(int val) { this->DailyPayment = val; }
	int getTotalDays() { return this->TotalDays; }
	void setTotalDays(int val) { this->TotalDays = val; }

	shared_ptr<OmegaCompany>clone(string, string);
	DailyEmployee();
	DailyEmployee(string, int, int);
	int FinalPayment();
	string ConvertPayment();
	void print();
};

class HourlyEmployee :public OmegaCompany {
private:
	string Name;
	int HourlyPayment;
	int TotalHours;
public:
	string getName() { return this->Name; }
	void setName(string val) { this->Name = val; }
	int getHourlyPayment() { return this->HourlyPayment; }
	void setHourlyPayment(int val) { this->HourlyPayment = val; }
	int getTotalHours() { return this->TotalHours; }
	void setTotalHours(int val) { this->TotalHours = val; }

	shared_ptr<OmegaCompany>clone(string, string);
	HourlyEmployee();
	HourlyEmployee(string, int, int);
	int FinalPayment();
	string ConvertPayment();
	void print();
};

class ProductEmployee : public OmegaCompany {
private:
	string Name;
	int PaymentPerProduct;
	int TotalProducts;
public:
	string getName() { return this->Name; }
	void setName(string val) { this->Name = val; }
	int getPaymentPerProduct() { return this->PaymentPerProduct; }
	void setPaymentPerProduct(int val) { this->PaymentPerProduct = val; }
	int getTotalProducts() { return this->TotalProducts; }
	void setTotalProducts(int val) { this->TotalProducts = val; }

	shared_ptr<OmegaCompany>clone(string, string);
	ProductEmployee();
	ProductEmployee(string, int, int);
	int FinalPayment();
	string ConvertPayment();
	void print();
};

class Manager :public OmegaCompany {
private:
	string Name;
	int PaymentPerEmployee;
	int TotalEmployees;
	int FixedPayment;
public:
	string getName() { return this->Name; }
	void setName(string val) { this->Name = val; }
	int getPaymentPerEmployee() { return this->PaymentPerEmployee; }
	void setPaymentPerEmployee(int val) { this->PaymentPerEmployee = val; }
	int getTotalEmployees() { return this->TotalEmployees; }
	void setTotalEmployees(int val) { this->TotalEmployees = val; }

	shared_ptr<OmegaCompany>clone(string, string);
	Manager();
	Manager(string, int, int, int);
	int FinalPayment();
	string ConvertPayment();
	void print();
};

class Factory {
private:
	map<string, shared_ptr<OmegaCompany>>_prototypes;
	inline static shared_ptr<Factory>_instance = NULL;
	Factory();
public:
	static shared_ptr<Factory>instance();
	shared_ptr<OmegaCompany>create(string, string, string);
};

void ReadFile(string str1, string str2);

#endif