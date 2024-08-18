#include <iostream>

using namespace std;
class Bundle{
private:
    int BundleType ;
public:
    Bundle(){
        BundleType=0 ;
    }
    void setBundleType(int TypeNumber){
        if(TypeNumber>=0 && TypeNumber<=4){
            BundleType=TypeNumber ;
        }
        else {cout<<"Invalid Bundle Type !";}


    }
    int getBundleType(){
        return BundleType ;
    }
    float applydiscount(float price){
        if(BundleType==1){
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


    }
    string getBundleName(){
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
};


   int main() {

    Bundle bundle;
    bundle.setBundleType(1);
    float price = 250;
    float discountedPrice = bundle.applydiscount(price);

    cout << "Original Price: " << price << " L.E." << endl;
    cout << "Bundle Applied: " << bundle.getBundleName() << endl;
    cout << "Discounted Price: " << discountedPrice << " L.E." << endl ;
    return 0;
}
