#include<iostream>
using namespace std;
void registerUser(string &name, string &email, string &city, string &customerType){
    cout<<"Enter User Name: ";
    cin>>name;
    cout<<"Enter Email: ";
    cin>>email;
    cout<<"Enter City: ";
    cin>>city;
    cout<<"Enter Customer Type (New/Returning): ";
    cin>>customerType;
}

int displayMenu(){
    int choice;
    cout<<"\n===== MAIN MENU ====="<<endl;
    cout<<"1. View Products"<<endl;
    cout<<"2. Add Product to Cart"<<endl;
    cout<<"3. Calculate Checkout Bill"<<endl;
    cout<<"4. View User Details"<<endl;
    cout<<"5. Exit"<<endl;
    cout<<"Enter Choice: ";
    cin>>choice;
    return choice;
}

void displayProducts(string products[], float prices[], int size){
    cout<<"========== PRODUCT LIST =========="<<endl;
    for(int i=0; i<size; i++){
        cout<<i+1<<". "<<products[i]<<" - Rs. "<<prices[i]<<endl;
    }
}

void addToCart(string products[], float prices[], int size, float &productTotal){
	cout<<"========== Add To Cart =========="<<endl;
    int productNo, quantity;
    cout<<"Enter Product Number: ";
    cin>>productNo;
    cout<<"Enter Quantity: ";
    cin>>quantity;
    if(productNo>=1 && productNo<=size){
        productTotal+=prices[productNo-1]*quantity;
        cout<<"Product Added Successfully!"<<endl;
    }
    else{
        cout<<"Invalid Product Number!"<<endl;
    }
}

float calculateGST(float total){
    return total*0.17;
}

float calculateDeliveryCharges(string city){
    if(city=="Lahore" || city=="Karachi" || city=="Islamabad"){
        return 250;
    }
    else{
        return 500;
    }
}

float calculateCustomerDiscount(float total, string customerType){
    if(customerType=="Returning" || customerType=="returning"){
        return total*0.10;
    }
    else{
        return total*0.05;
    }
}

float calculateOrderDiscount(float total){
    if(total>10000){
        return total*0.12;
    }
    else if(total>=5000){
        return total*0.05;
    }
    else{
        return 0;
    }
}

float calculatePaymentCharges(float total, int paymentMethod){
    if(paymentMethod==2){
        return total*0.025;
    }
    else{
        return 0;
    }
}

void displayBill(string name, string city, string customerType,float productTotal, float gst,float deliveryCharges, float customerDiscount,float orderDiscount, float paymentCharges){
    float finalAmount;
    finalAmount=productTotal+gst+deliveryCharges+paymentCharges-customerDiscount-orderDiscount;
    cout<<"========== ONLINE SHOPPING BILL =========="<<endl;
    cout<<"User Name: "<<name<<endl;
    cout<<"City: "<<city<<endl;
    cout<<"Customer Type: "<<customerType<<endl;
    cout<<"Product Total: Rs. "<<productTotal<<endl;
    cout<<"GST: Rs. "<<gst<<endl;
    cout<<"Delivery Charges: Rs. "<<deliveryCharges<<endl;
    cout<<"Customer Discount: Rs. "<<customerDiscount<<endl;
    cout<<"Order Discount: Rs. "<<orderDiscount<<endl;
    cout<<"Payment Charges: Rs. "<<paymentCharges<<endl;
    cout<<"------------------------------------------"<<endl;
    cout<<"Final Payable Amount: Rs. "<<finalAmount<<endl;
    cout<<"Thank You for Shopping "<<endl;
    cout<<"------------------------------------------"<<endl;
}

int main(){
    string name, email, city, customerType;
    registerUser(name, email, city, customerType);
    int size=8;
    string products[size]={"T-Shirt","Jeans","Shoes","Watch","Handbag","Headphones","Mobile Cover","Perfume"};
    float prices[size]={1200,3500,5000,2500,4200,3000,700,2800};
    float productTotal=0;
    int choice;
    do{
        choice=displayMenu();
        switch(choice){
            case 1:
                displayProducts(products, prices, size);
                break;
            case 2:
                addToCart(products, prices, size, productTotal);
                break;
            case 3:{
                float gst=calculateGST(productTotal);
                float deliveryCharges=calculateDeliveryCharges(city);
                float customerDiscount=calculateCustomerDiscount(productTotal, customerType);
                float orderDiscount=calculateOrderDiscount(productTotal);
                int paymentMethod;
                cout<<"Select Payment Method"<<endl;
                cout<<"1. Cash on Delivery"<<endl;
                cout<<"2. Debit/Credit Card"<<endl;
                cout<<"Enter Choice: ";
                cin>>paymentMethod;
                float paymentCharges=calculatePaymentCharges(productTotal, paymentMethod);
                displayBill(name, city, customerType,productTotal, gst,deliveryCharges,customerDiscount,orderDiscount,paymentCharges);
                break;
            }
            case 4:
                cout<<"===== USER DETAILS ====="<<endl;
                cout<<"User Name: "<<name<<endl;
                cout<<"Email: "<<email<<endl;
                cout<<"City: "<<city<<endl;
                cout<<"Customer Type: "<<customerType<<endl;
                break;
            case 5:
                cout<<"Program Ended"<<endl;
                break;
            default:
                cout<<"Invalid Choice!"<<endl;
        }
    }while(choice!=5);
    return 0;
}
