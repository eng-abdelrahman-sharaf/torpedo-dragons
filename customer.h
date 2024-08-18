#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
using namespace std;
#include "bundle.h"

class Customer {
public:
    Customer(string id, string name);
    void setBundle(int bundleType);
    void incrementOpNum();
    string getID();
    int getOpNum();
    string getName();
    Bundle *getBundle();

private:
    string Name;
    int ID;
    int bundlenum;
    Bundle *bundle;
    int bundlecounter;
};

#endif
