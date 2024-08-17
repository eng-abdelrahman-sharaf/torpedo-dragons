#include "system.h"

void System::systemExit() {
	exit(0);
}

void System::performOperation(){
	string ID;
	cout << "enter Customer ID : ";
	cin >> ID;
	float price;
	cout << "enter product price : ";
	cin >> price;
	Customer targetedCustomer = this->customers[ID];
	Customer targetedCustomer("1234", "ali");
	int operationsCount = targetedCustomer.getOpNum();
	Bundle bundle;
	if (operationsCount == 3) {
		bundle.setBundleType(2);
		cout << "Congrats, Customer (" << targetedCustomer.getName() << "). You are currently on Bundle " << bundle.getBundleName();
		targetedCustomer.setBundle(2);
		logger->logNewBundle(&targetedCustomer);
	}
	else if (operationsCount > 10) {
		int bundlet1, bundlet2;
		if (operationsCount <= 15) bundlet1 = 1, bundlet2 = 2;
		else bundlet1 = 3, bundlet2 = 4;
		int bundleType;
		bundle.setBundleType(bundlet1);
		cout << "1- " << bundle.getBundleName() << '\n';
		bundle.setBundleType(bundlet2);
		cout << "2- " << bundle.getBundleName() << '\n';
		cout << "choose bundle Number : ";
		cin >> bundleType;
		bundle.setBundleType(bundleType);
		targetedCustomer.setBundle(bundleType);
		logger->logBundleModification(&targetedCustomer);
	}
	targetedCustomer.incrementOpNum();
}

void System::addCustomer() {
	string name , ID;
	cout << "enter customer Name : ";
	cin >> name;
	cout << "enter customer ID : ";
	cin >> ID;
	this->customers[ID] = Customer(ID, name);
}