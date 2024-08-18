#ifndef LOGGER_H
#define LOGGER_H

#include "customer.h"
#include <iostream>
#include<fstream>

class Logger{
    public:
        static Logger* init(string fileName);
        void logPurchase(Customer * customer , float price); /*logs buying operation and discount applying */
        void logNewBundle(Customer * customer);
        void logBundleModification(Customer * customer);
        ~Logger();
        // deleting copy constructor
        Logger(const Logger& obj) = delete;
    private:
        static Logger* logger;
        Logger(string fileName);
        string filename;
};

#endif