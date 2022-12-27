#ifndef CHOCOLATE_CAKE_H
#define CHOCOLATE_CAKE_H
#include <bits/stdc++.h>

class ChocolateCake : public Cake{
    private:
        static int _count;
    public:
        ChocolateCake(){
            _count ++;
        }

        ChocolateCake(int price, int sweet) : Cake(price, sweet){
            _count ++;
        }

        ~ChocolateCake()override{
            _total --;
            _count --;
        }

        std::string to_string()override{
            char str[80];
            sprintf(str, "| ChocolateCake        |         %d |         %d |", _price, _sweet);
            puts(str);
            return str;
        }

        static int get_count(){
            return ChocolateCake::_count;
        }
};
int ChocolateCake::_count = 0;

#endif