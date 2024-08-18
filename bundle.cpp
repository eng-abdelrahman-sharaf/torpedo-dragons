#include <iostream>
using namespace std;
#include "bundle.h"

Bundle::Bundle(){
    BundleType=0 ;
}
void Bundle::setBundleType(int TypeNumber){
    if(TypeNumber>=0 && TypeNumber<=4){
        BundleType=TypeNumber ;
    }
    else cout<<"Invalid Bundle Type !";
}
int Bundle::getBundleType(){
    return BundleType ;
}
float Bundle::applyDiscount(float price){
    if (BundleType == 0) return price;
    else if(BundleType==1){
        return price*0.85 ;/*discount 15%*/
    }
    else if (BundleType==2){
        if(price>200){
                return price-100 ;
        }
        else return price ;
    }
    else if (BundleType==3){
        if(price>200){
            float discountedPrice=price-100 ;
            return discountedPrice*0.85 ;
        }
        else{return price*0.85;}
    }
    else if(BundleType==4){
        float discountedPrice=price*0.85 ;
        if(discountedPrice>200){
            return discountedPrice-100 ;
        }
        else{
            return discountedPrice ;
        }
    }
    else{
        throw std::invalid_argument("recieved invalid bundleType");
    }
}
string Bundle::getBundleName(){
    switch(BundleType){
        case 0 :
            return "No Bundle" ;
        case 1 :
            return "15% discount"  ;
        case 2 :
            return "100 L.E off " ;
        case 3 :
            return "100 L.E off then 15% discount" ;
        case 4 :
            return "15% discount then 100 L.E off"  ;
        default :
            return "Invalid Bundle"  ;
    }
}