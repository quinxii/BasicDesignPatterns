#include "Header.h"

DailyEmployee::DailyEmployee() {
	this->Name = "";
	this->DailyPayment = 0;
	this->TotalDays = 0;
}
DailyEmployee::DailyEmployee(string paraName, int paraDailyPayment, int paraTotalDays) {
	this->Name = paraName;
	this->DailyPayment = paraDailyPayment;
	this->TotalDays = paraTotalDays;
}
int DailyEmployee::FinalPayment() {
	int sum = this->DailyPayment * this->TotalDays;
	return sum;
}
string DailyEmployee::ConvertPayment() {
	string str = to_string(this->FinalPayment());
	string Payment = "";
	int count = 0;
	int temp = str.size() % 3;
	if (str.size() <= 3)return str;
	for (int i = 0; i < str.size(); i++) {
		count++;
		Payment += str[i];
		if (count == temp && temp != 0) {
			Payment += ".";
			temp = 0;
			count = 0;
		}
		else if (count == 3 && i != str.size() - 1) {
			Payment += ".";
			count = 0;
		}
		else if (i == str.size() - 1)Payment += "$";
	}
	return Payment;
}
void DailyEmployee::print() {
	cout << "DailyEmployee: " << this->Name << endl;
	cout << "DailyPayment=" << this->DailyPayment<<"$" << "; TotalDays=" << this->TotalDays << endl;
	cout << "Final Payment: " << this->ConvertPayment() << endl;
	cout << endl;
}
shared_ptr<OmegaCompany>DailyEmployee::clone(string str1, string str2) {
	string ReadFileofName = "", ReadFileofDailyPayment = "", ReadFileofTotalDays = "";
	for (int i = str1.find_first_of(':') + 2; i < str1.size(); i++) {
		ReadFileofName += str1[i];
	}
	for (int i = str2.find_first_of('=') + 1; i < str2.find_first_of('$'); i++) {
		ReadFileofDailyPayment += str2[i];
	}
	for (int i = str2.find_last_of('=') + 1; i < str2.size(); i++) {
		ReadFileofTotalDays += str2[i];
	}
	shared_ptr<OmegaCompany>s = make_shared<DailyEmployee>(ReadFileofName, stoi(ReadFileofDailyPayment), stoi(ReadFileofTotalDays));
	return s;
}

HourlyEmployee::HourlyEmployee() {
	this->Name = "";
	this->HourlyPayment = 0;
	this->TotalHours = 0;
}
HourlyEmployee::HourlyEmployee(string paraName, int paraHourlyPayment, int paraTotalHours) {
	this->Name = paraName;
	this->HourlyPayment = paraHourlyPayment;
	this->TotalHours = paraTotalHours;
}
int HourlyEmployee::FinalPayment() {
	int result = this->HourlyPayment * this->TotalHours;
	return result;
}
string HourlyEmployee::ConvertPayment() {
	string str = to_string(this->FinalPayment());
	string Payment = "";
	int count = 0;
	int temp = str.size() % 3;
	if (str.size() <= 3)return str;
	for (int i = 0; i < str.size(); i++) {
		count++;
		Payment += str[i];
		if (count == temp && temp != 0) {
			Payment += ".";
			temp = 0;
			count = 0;
		}
		else if (count == 3 && i != str.size() - 1) {
			Payment += ".";
			count = 0;
		}
		else if (i == str.size() - 1)Payment += "$";
	}
	return Payment;
}
void HourlyEmployee::print() {
	cout << "HourlyEmployee: " << this->Name << endl;
	cout << "HourlyPayment=" << this->HourlyPayment << "$" << "; TotalHours=" << this->TotalHours << endl;
	cout << "Final Payment: " << this->ConvertPayment() << endl;
	cout << endl;
}
shared_ptr<OmegaCompany>HourlyEmployee::clone(string str1, string str2) {
	string ReadFileofName = "", ReadFileofHourlyPayment = "", ReadFileofTotalHours = "";
	for (int i = str1.find_first_of(':') + 2; i < str1.size(); i++) {
		ReadFileofName += str1[i];
	}
	for (int i = str2.find_first_of('=') + 1; i < str2.find_first_of('$'); i++) {
		ReadFileofHourlyPayment += str2[i];
	}
	for (int i = str2.find_last_of('=') + 1; i < str2.size(); i++) {
		ReadFileofTotalHours += str2[i];
	}
	shared_ptr<OmegaCompany>s = make_shared<HourlyEmployee>(ReadFileofName, stoi(ReadFileofHourlyPayment), stoi(ReadFileofTotalHours));
	return s;
}

ProductEmployee::ProductEmployee() {
	this->Name = "";
	this->PaymentPerProduct = 0;
	this->TotalProducts = 0;
}
ProductEmployee::ProductEmployee(string paraName, int paraPaymentPerProducts, int paraTotalProducts) {
	this->Name = paraName;
	this->PaymentPerProduct = paraPaymentPerProducts;
	this->TotalProducts = paraTotalProducts;
}
int ProductEmployee::FinalPayment() {
	int result = this->PaymentPerProduct * this->TotalProducts;
	return result;
}
string ProductEmployee::ConvertPayment() {
	string str = to_string(this->FinalPayment());
	string Payment = "";
	int count = 0;
	int temp = str.size() % 3;
	if (str.size() <= 3)return str;
	for (int i = 0; i < str.size(); i++) {
		count++;
		Payment += str[i];
		if (count == temp && temp != 0) {
			Payment += ".";
			temp = 0;
			count = 0;
		}
		else if (count == 3 && i != str.size() - 1) {
			Payment += ".";
			count = 0;
		}
		else if (i == str.size() - 1)Payment += "$";
	}
	return Payment;
}
void ProductEmployee::print() {
	cout << "ProductEmployee: " << this->Name << endl;
	cout << "PaymentPerProduct=" << this->PaymentPerProduct << "$" << "; TotalProducts=" << this->TotalProducts << endl;
	cout << "Final Payment: " << this->ConvertPayment() << endl;
	cout << endl;
}
shared_ptr<OmegaCompany>ProductEmployee::clone(string str1, string str2) {
	string ReadFileofName = "", ReadFileofPaymentPerProduct = "", ReadFileofTotalProducts = "";
	for (int i = str1.find_first_of(':') + 2; i < str1.size(); i++) {
		ReadFileofName += str1[i];
	}
	for (int i = str2.find_first_of('=') + 1; i < str2.find_first_of('$'); i++) {
		ReadFileofPaymentPerProduct += str2[i];
	}
	for (int i = str2.find_last_of('=') + 1; i < str2.size(); i++) {
		ReadFileofTotalProducts += str2[i];
	}
	shared_ptr<OmegaCompany>s = make_shared<ProductEmployee>(ReadFileofName, stoi(ReadFileofPaymentPerProduct), stoi(ReadFileofTotalProducts));
	return s;
}

Manager::Manager() {
	this->Name = "";
	this->FixedPayment = 0;
	this->PaymentPerEmployee = 0;
	this->TotalEmployees = 0;
}
Manager::Manager(string paraName, int paraFixedPayment, int paraTotalEmployees, int paraPaymentPerEmployee) {
	this->Name = paraName;
	this->FixedPayment = paraFixedPayment;
	this->TotalEmployees = paraTotalEmployees;
	this->PaymentPerEmployee = paraPaymentPerEmployee;
}
int Manager::FinalPayment() {
	int result = (this->TotalEmployees * this->PaymentPerEmployee) + this->FixedPayment;
	return result;
}
string Manager::ConvertPayment() {
	string str = to_string(this->FinalPayment());
	string Payment = "";
	int count = 0;
	int temp = str.size() % 3;
	if (str.size() <= 3)return str;
	for (int i = 0; i < str.size(); i++) {
		count++;
		Payment += str[i];
		if (count == temp && temp != 0) {
			Payment += ".";
			temp = 0;
			count = 0;
		}
		else if (count == 3 && i != str.size() - 1) {
			Payment += ".";
			count = 0;
		}
		else if (i == str.size() - 1)Payment += "$";
	}
	return Payment;
}
void Manager::print() {
	cout << "Manager: " << this->Name << endl;
	cout << "Fixed Payment=" << this->FixedPayment << "$" << "; TotalProducts=" << this->TotalEmployees << "; PaymentPerEmployee=" << this->PaymentPerEmployee << "$" << endl;
	cout << "Final Payment: " << this->ConvertPayment() << endl;
	cout << endl;
}
shared_ptr<OmegaCompany>Manager::clone(string str1, string str2) {
	string ReadFileofName = "", ReadFileofFixedPayment = "", ReadFileofTotalEmployees = "", ReadFileofPaymentPerEmployee = "";
	for (int i = str1.find_first_of(':') + 2; i < str1.size(); i++) {
		ReadFileofName += str1[i];
	}
	for (int i = str2.find_first_of('=') + 1; i < str2.find_first_of('$'); i++) {
		ReadFileofFixedPayment += str2[i];
	}
	for (int i = str2.find_first_of(';') + 17; i < str2.find_last_of(';'); i++) {
		ReadFileofTotalEmployees += str2[i];
	}
	for (int i = str2.find_last_of('=') + 1; i < str2.size(); i++) {
		ReadFileofPaymentPerEmployee += str2[i];
	}
	shared_ptr<OmegaCompany>s = make_shared<Manager>(ReadFileofName, stoi(ReadFileofFixedPayment), stoi(ReadFileofTotalEmployees), stoi(ReadFileofPaymentPerEmployee));
	return s;
}

Factory::Factory() {
	_prototypes.insert({ "DailyEmployee",make_shared<DailyEmployee>() });
	_prototypes.insert({ "HourlyEmployee",make_shared<HourlyEmployee>() });
	_prototypes.insert({ "ProductEmployee",make_shared<ProductEmployee>() });
	_prototypes.insert({ "Manager",make_shared<Manager>() });
}
shared_ptr<OmegaCompany>Factory::create(string str1, string str2, string choice) {
	shared_ptr<OmegaCompany>result = NULL;
	auto item = _prototypes[choice];
	result = item->clone(str1, str2);
	return result;
}
shared_ptr<Factory>Factory::instance() {
	if (_instance == NULL) {
		Factory* temp = new Factory();
		_instance = make_shared<Factory>(*temp);
	}
	return _instance;
}

void ReadFile(string str1, string str2) {
	ifstream ifs;
	ifs.open("November2021.txt");
	while (ifs.good()) {
		getline(ifs, str1, '\n');
		int tempTypes = str1.find_first_of(':');
		string Types = str1.substr(0, tempTypes);
		auto factory = Factory::instance();
		getline(ifs, str2, '\n');
		auto omegacompany = factory->create(str1, str2, Types);
		omegacompany->print();
	}
	ifs.close();
}
