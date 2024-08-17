#include "customer.h"
#include <iostream>

class Logger{
    public:
    void logPurchase(Customer * customer , float price); /*logs buying operation and discount applying */
    void logNewBundle(Customer * customer);
    void logBundleModification(Customer * customer);
};