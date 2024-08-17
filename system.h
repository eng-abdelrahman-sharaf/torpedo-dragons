#include "customer.h"
#include <unordered_map>
#include <iostream>
#include "logger.h"
using namespace std;

class System {
	private:
		unordered_map<string, Customer> customers;
		void addCustomer();
		void performOperation();
		void systemExit();
		Logger* logger;

	public:
		void mainLoop() {
			logger = Logger::init("logging.txt");
			while (1) {
				bool validOperation = true;
				cout << "1. Add NewCustomer.\n"
						"2. Perform Operation.\n"
						"3. Exit\n";
						"choose an operation number : \n";
				do {
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
						break;
					}
				} while (!validOperation);
			}
		}
};


