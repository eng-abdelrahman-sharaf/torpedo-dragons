#include "logger.h"
#include <ctime>
Logger* Logger::logger= nullptr;

Logger * Logger::init(string fileName) {
	if (logger != nullptr) return logger;
	else {
		logger = new Logger(fileName);
		return logger;
	}
}

Logger::Logger(string fileName) {
	this->filename=fileName;
}

Logger::~Logger(){
	logger = nullptr;
}

void Logger::logPurchase(Customer* customer, float price) { /*logs buying operation and discount applying */
	time_t timestamp = time(NULL);
	float finalPrice = customer->getBundle()->applyDiscount(price);
	ofstream loggingFile;
	loggingFile.open(logger->filename , ios_base::app);
	if (price != finalPrice) {
		loggingFile << timestamp<<": "<< customer->getName() <<" with id "<< customer->getID() <<" used bundle " << customer->getBundle()->getBundleName() << endl;
	}
	loggingFile << timestamp<<": "<< customer->getName() <<" with id "<< customer->getID() <<" bought items with " << finalPrice << endl;
	loggingFile.close();
}

void Logger::logBundleModification(Customer* customer) {
	time_t timestamp = time(NULL);
	ofstream loggingFile;
	loggingFile.open(logger->filename , ios_base::app);
	loggingFile << timestamp<<": "<< customer->getName() <<" with id "<< customer->getID() <<" changed his bundle to " << customer->getBundle()->getBundleName() << endl;
	loggingFile.close();
}


void Logger::logNewBundle(Customer* customer) {
	time_t timestamp = time(NULL);
	ofstream loggingFile;
	loggingFile.open(logger->filename , ios_base::app);
	loggingFile << timestamp << ": " << customer->getName() << " with id " << customer->getID() << " got a new bundle " << customer->getBundle()->getBundleName() << endl;
	loggingFile.close();
}