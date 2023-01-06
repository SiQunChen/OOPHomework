#ifndef MYBIKE_H
#define MYBIKE_H
#include <bits/stdc++.h>

class MyBike : public Bike{
    public:
        MyBike() = default;
        
        MyBike(int ID, int rent_price) : Bike(ID, rent_price){}

        ~MyBike()override{}

        int get_id(){
            return _id;
        }

        int get_rental_price(){
            return _price;
        }

        std::string to_string(){
            char str[80];
            sprintf(str, "%d-MyBike price=%d", _id, _price);
            return str;
        }
};
#endif