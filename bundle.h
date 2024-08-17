#include <iostream>
using namespace std;

class Bundle{
    public:
        Bundle(); /*=> set bundleType to 0*/
        void setBundleType(int typeNum); /* from 0 to 4 */
        int getBundleType(); /* returns from 0 to 4 */
        float applyDiscount(float price);
        string getBundleName();
};