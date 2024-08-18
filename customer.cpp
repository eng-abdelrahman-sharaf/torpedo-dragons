#include "customer.h"
//constructor
Customer::Customer(string id, string name)
{
	Name = name;
	ID = id;

}
string Customer:: getID() {
	return ID;
}
string Customer:: getName() {
	return Name;
}
void  Customer ::setBundle(int bundleType) {
	bundlenum=bundle->setBundletype(bundletype);

}
Bundle*  Customer ::getBundle() {
	return bundle;
}
void  Customer ::incrementOpNum() {
	bundlecounter++;
}
int Customer : :getOpNum() {
	return bundlecounter;
}
