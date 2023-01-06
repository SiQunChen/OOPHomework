#ifndef BIKE_H
#define BIKE_H
#include <bits/stdc++.h>

class Bike{
    protected:
        int _price = 0;
        int _id = 0;
    public:
        Bike() = default;

        Bike(int ID, int rent_price){
            if(rent_price < 0){
                throw std::invalid_argument("the rent_price is negative!");
            }
            _id = ID;
            _price = rent_price;
        }

        virtual ~Bike(){}

        int get_id(){
            return _id;
        }

        int get_rental_price(){
            return _price;
        }

        virtual std::string to_string() = 0;
};
#endif
