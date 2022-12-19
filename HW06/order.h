#ifndef ORDER_H
#define ORDER_H
#include <bits/stdc++.h>
#include "alcohol.h"
#include "algorithm.h"

class Order{
    private:
        //std::vector<Alcohol*> _alcohol;
    public:
        std::vector<Alcohol*> _alcohol;
        Order() = default;

        ~Order(){}

        void append_alcohol(Alcohol* alcohol){
            _alcohol.push_back(alcohol);
        }

        int get_alcohol_count(){
            return _alcohol.size();
        }

        int get_total_price(){
            int total = 0;
            for(int i = 0; i < _alcohol.size(); i++){
                total += _alcohol[i] -> get_price();
            }
            return total;
        }
};

#endif