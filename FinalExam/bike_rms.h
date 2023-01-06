#ifndef BIKE_RMS_H
#define BIKE_RMS_H
#include <bits/stdc++.h>
#include "bike.h"

class BikeRMS{
    private:
        static int _total;
        std::vector<int> _rent;
    protected:
        std::vector<Bike*> _bikes;
    public:
        BikeRMS(std::vector<Bike*> bikes){
            for(int i=0; i < bikes.size(); i++){
                _bikes.push_back(bikes[i]);
            }
        }

        ~BikeRMS(){
            _total --;
        }

        int get_count_of_available_bike(){
            return _bikes.size() - _rent.size();
        }

        Bike* rent_bike(int ID){
            for(int i=0; i<_rent.size(); i++){
                if(_rent[i] == ID){
                    throw std::invalid_argument("invalid arguments");
                }
            }
            for(int i=0; i < _bikes.size(); i++){
                if(_bikes[i] -> get_id() == ID){
                    _total += _bikes[i] -> get_rental_price();
                    _rent.push_back(ID);
                    return _bikes[i];
                }
            }
            throw std::invalid_argument("invalid arguments");
        }

        void return_bike(Bike* bike){
            int flag = 0;
            for(int i=0; i<_rent.size(); i++){
                if(_rent[i] == bike -> get_id()){
                    _rent.erase(_rent.begin()+i);
                    flag = 1;
                }
                else{
                    throw std::invalid_argument("invalid arguments");
                }
            }
            if(flag == 0){
                throw std::invalid_argument("invalid arguments");
            }
        }

        void append_bike(Bike* bike){
            for(int i=0; i < _bikes.size(); i++){
                if(_bikes[i] -> get_id() == bike -> get_id()){
                    throw std::invalid_argument("invalid arguments");
                }
            }
            _bikes.push_back(bike);
        }

        static int get_total_rental_income(){
            return _total;
        }

        static void reset_total_rental_income(){
            _total = 0;
        }
};
int BikeRMS::_total = 0;
#endif