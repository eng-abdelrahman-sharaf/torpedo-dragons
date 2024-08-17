# OOP Task Prototype

## Customer Protype

```cpp
class Customer{
    public:
        Customer(string id , string name);
        void setBundle(int bundleType);
        void incrementOpNum();
        string getID();
        int getOpNum();
        string getName();
        Bundle* getBundle();
};
```

## Logger Protype

```cpp
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
        ofstream loggingFile;
        static Logger* logger;
        Logger(string fileName);
};
```

### Logging Messages Prototype (printed in a file):

**Purchase operation :**

"(timestamp): (Customer Name) with id (Customer ID) used bundle (bundle name)"

"(timestamp): (Customer Name) with id (Customer ID) bought items with (price)"

**new bundle operation :**

"(timestamp): (Customer Name) with id (Customer ID)  got a new bundle (bundle Name)"

**bundle modification:**

"(timestamp): (Customer Name) with id (Customer ID)  changed his bundle to (bundle name)"

## Bundle Protype

```cpp
class Bundle{
    public:
        Bundle(); /*=> set bundleType to 0*/
        void setBundleType(int typeNum); /* from 0 to 4 */
        int getBundleType(); /* returns from 0 to 4 */
        float applyDiscount(float price);
        string getBundleName();
};
```

## Directory Structure Prototype

- main.cpp
- system.cpp
- system.h
- bundle.cpp
- bundle.h
- customer.cpp
- customer.h
- logger.cpp
- logger.h
