#include "customer.h"
//constructor
Customer::Customer(string id, string name)
{
	bundle.setBundleType(0);
	Name = name;
	ID = id;
	operationsCounter = 0;
}
string Customer:: getID() {
	return ID;
}
string Customer:: getName() {
	return Name;
}
void  Customer ::setBundle(int bundleType) {
	bundle.setBundleType(bundleType);
}

Bundle* Customer ::getBundle() {
	return	&bundle;
}
void  Customer::incrementOpNum() {
	this->operationsCounter++;
	cout << "opCount : " << operationsCounter << endl;
}
int Customer::getOpNum() {
	return this->operationsCounter;
}
