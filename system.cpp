#include "system.h"

void System::systemExit() {
	exit(0);
}

void System::performOperation(){
	string ID;
	do{
		cout << "enter Customer ID : ";
		cin >> ID;
	} while (this->customers.count(ID) == 0);
	float price;
	cout << "enter product price : ";
	cin >> price;
	Customer &targetedCustomer = this->customers.at(ID);
	this->applyPurchase(targetedCustomer , price);
}

void System::applyPurchase(Customer &targetedCustomer , float price){
	targetedCustomer.incrementOpNum();
	int operationsCount = targetedCustomer.getOpNum();
	Bundle bundle;
	if(operationsCount <= 3 ) {
		logger->logPurchase(&targetedCustomer, price);// buying before using bundle 3 if operations count = 3
		if (operationsCount == 3) {
			cout << "Congrats, Customer (" << targetedCustomer.getName() << "). You are currently on Bundle " << bundle.getBundleName() << endl;
			bundle.setBundleType(2);
			targetedCustomer.setBundle(2);
			logger->logNewBundle(&targetedCustomer);
		}
	}
	else{
		if (operationsCount > 10) {
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
		logger->logPurchase(&targetedCustomer, price); // buying after using bundle
	}
}


void System::addCustomer() {
	string name , ID;
	do {
		cout << "enter customer Name : ";
		cin >> name;
		cout << "enter customer ID : ";
		cin >> ID;
	} while (this->customers.count(ID));
	this->customers.insert({ ID , Customer(ID , name) });
}

void System::mainLoop(){
			logger = Logger::init("logging.txt");
			while (1) {
				bool validOperation = true;
				cout << 
					"1. Add NewCustomer.\n"
					"2. Perform Operation.\n"
					"3. Exit.\n";
				do {
					cout << "choose an operation number : ";
					char operation;
					cin >> operation;
					switch (operation)
					{
					case '1':
						this->addCustomer();
						break;
					case '2':
						this->performOperation();
						break;
					case '3':
						this->systemExit();
						break;
					default:
						validOperation = false;
						while (cin.get() != '\n');
						break;
					}
				} while (!validOperation);
			}
}