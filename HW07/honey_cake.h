#ifndef HONEY_CAKE_H
#define HONEY_CAKE_H
#include <bits/stdc++.h>

class HoneyCake : public Cake{
    private:
        static int _count;
    public:
        HoneyCake(){
            _count ++;
        }
        
        HoneyCake(int price, int sweet) : Cake(price, sweet){
            _count ++;
        }

        ~HoneyCake()override{
            _total --;
            _count --;
        }

        std::string to_string()override{
            char str[80];
            sprintf(str, "| HoneyCake            |         %d |         %d |", _price, _sweet);
            puts(str);
            return str;
        }

        static int get_count(){
            return HoneyCake::_count;
        }
};
int HoneyCake::_count = 0;

#endif