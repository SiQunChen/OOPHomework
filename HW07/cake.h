#ifndef CAKE_H
#define CAKE_H
#include <bits/stdc++.h>

class Cake{
    protected:
        static int _total;
        int _price = 0;
        int _sweet = 0;
    public:
        
        Cake() = default;

        Cake(int price, int sweet){
            _price = price;
            _sweet = sweet;
            _total ++;
        }

        virtual ~Cake(){}

        int get_price(){
            return _price;
        }

        int get_sweet(){
            return _sweet;
        }

        static int get_total(){
            return _total;
        }

        virtual std::string to_string() = 0;
};
int Cake::_total = 0;

#endif
