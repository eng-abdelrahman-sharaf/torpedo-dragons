#include <iostream>
using namespace std;
#include "bundle.h"

class Customer{
    Customer(string id , string name);
    void setBundle(int bundleType);
    void incrementOpNum();
    string getID();
    int getOpNum();
    string getName();
    Bundle getBundle();
};