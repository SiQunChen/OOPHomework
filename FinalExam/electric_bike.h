#ifndef ELECTRIC_BIKE_H
#define ELECTRIC_BIKE_H
#include <bits/stdc++.h>

class ElectricBike : public Bike{
    private:
        double _power = 0;
    public:
        ElectricBike() = default;
        
        ElectricBike(int ID, int rent_price, double power = 0) : Bike(ID, rent_price){
            if(power < 0 || power > 1){
                throw std::invalid_argument("invalid arguments");
            }
            _power = power;
        }

        ~ElectricBike()override{}

        int get_id(){
            return _id;
        }

        int get_rental_price(){
            return _price;
        }

        double get_power(){
            return _power;
        }

        void set_power(double power){
            if(power < 0 || power > 1){
                throw std::invalid_argument("invalid arguments");
            }
            _power = power;
        }

        std::string to_string(){
            char str[80];
            sprintf(str, "%d-ElectricBike price=%d power=%.2f", _id, _price, _power);
            return str;
        }
};
#endif