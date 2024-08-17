#include "logger.h"
#include <ctime>
Logger* Logger::logger= nullptr;

Logger * Logger::init(string fileName) {
	if (logger != NULL) return logger;
	else {
		logger = new Logger(fileName);
		return logger;
	}
}



Logger::Logger(string fileName) {
	this->loggingFile.open(fileName , ios_base::app);
}

Logger::~Logger(){
	logger = nullptr;
	if (logger->loggingFile) {
		logger->loggingFile.close();
	}
}

void Logger::logPurchase(Customer* customer, float price) { /*logs buying operation and discount applying */
	time_t timestamp = time(NULL);
	float finalPrice = customer->getBundle()->applyDiscount(price);
	if (price != finalPrice) {
		logger->loggingFile << timestamp<<": "<< customer->getName() <<" with id "<< customer->getID() <<" used bundle" << customer->getBundle()->getBundleName();
	}
	logger->loggingFile << timestamp<<": "<< customer->getName() <<" with id "<< customer->getID() <<" bought items with " << finalPrice;
}

void Logger::logBundleModification(Customer* customer) {
	logger->loggingFile << timestamp<<": "<< customer->getName() <<" with id "<< customer->getID() <<" changed his bundle to " << customer->getBundle()->getBundleName();
}


void Logger::logNewBundle(Customer* customer) {
	logger->loggingFile << timestamp << ": " << customer->getName() << " with id " << customer->getID() << " got a new bundle " << customer->getBundle()->getBundleName() ;
}