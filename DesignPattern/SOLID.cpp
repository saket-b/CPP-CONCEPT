#include<iostream>
using namespace std;

class Product{

    private:
    int id;
    string name;
    double price;

    public:

    Product(int id, string name, double price): id(id), name(name), price(price){}

    string  getName() const {
        return name;

    }
    double getPrice() const{
        return price;
    }

};

class CartItem{

    public:
    Product product;
    int quantity;

   
    CartItem(Product p, int q): product(p), quantity(q){}

    double getTotalPrice() const {
        return product.getPrice()*quantity;
    }

};

class Cart{

    private:
    vector<CartItem>items;

    public:

    void addProduct(const Product &p, int quantity)
    {
        items.push_back(CartItem(p, quantity));
    }

};


class Payment{

    public:

    virtual void pay(  double amount)=0;
};

class CreditCard : public Payment{

    public:

    void pay( double amount)
    {
        cout<<"Payment is done "<<amount<<" By Credit Card"<<endl;
    }
};

class DebitCard : public Payment{

    public:

    void pay( double amount)
    {
        cout<<"Payment is done "<<amount<<" By Debit Card"<<endl;
    }
};

class UPI : public Payment{

    public:

    void pay( double amount)
    {
        cout<<"Payment is done "<<amount<<" By UPI"<<endl;
    }
};

class Order{

    private:
    vector<CartItem> items;
    double total ;

    public:

    Order(vector<CartItem> items): items(items)
    {
        total =0;

        for(auto const &item : items)
        {
            total +=item.getTotalPrice();
        }
        
    }

    void showOrder(){

        for( auto const & item : items)
        {
            cout<<item.product.getName()<<" "<<"quantity = "<<item.quantity
            <<"= "<<item.getTotalPrice()<<endl; 
        }

        cout<<"Total Price = "<<ca
    }
    void makePayment(Payment *payment){
        payment->pay(total);
    }
};

int main(){

    Product p1(1, "laptop", 300000);
    Product p2(2, "mobile", 10000);

    Cart cart;

    cart.addProduct(p1, 2);
    cart.addProduct(p2, 2);

    cart.showCart();

    Order order(cart.getItems());
    order.showOrder();
    CreditCard creditCard;
    order.makePayment(&creditCard);

}




