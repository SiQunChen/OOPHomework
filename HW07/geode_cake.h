#ifndef GEODE_CAKE_H
#define GEODE_CAKE_H
#include <bits/stdc++.h>

class GeodeCake : public Cake{
    private:
        static int _count;
    public:
        GeodeCake(){
            _count ++;
        }
        
        GeodeCake(int price, int sweet) : Cake(price, sweet){
            _count ++;
        }

        ~GeodeCake()override{
            _total --;
            _count --;
        }

        std::string to_string()override{
            char str[80];
            sprintf(str, "| GeodeCake            |         %d |         %d |", _price, _sweet);
            puts(str);
            return str;
        }

        static int get_count(){
            return GeodeCake::_count;
        }
};
int GeodeCake::_count = 0;

#endif