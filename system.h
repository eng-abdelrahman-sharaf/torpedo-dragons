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
		void applyPurchase(Customer &targetedCustomer , float price);

	public:
		void mainLoop();
};


