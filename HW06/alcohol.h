#ifndef ALCOHOL_H
#define ALCOHOL_H
#include <bits/stdc++.h>

class Alcohol{
    protected:
        std::string _name = "";
        int _price = -1;
        double _content = -1;
        
    public:
        Alcohol() = default;

        Alcohol(std::string name, int price, double content){
            if(name.length() == 0){
                throw std::invalid_argument("invalid_argument");
            }
            else if(price < 0){
                throw std::invalid_argument("invalid_argument");
            }
            else if(content < 0 || content > 1){
                throw std::invalid_argument("invalid_argument");
            }
            else{
                _name = name;
                _price = price;
                _content = content;
            }
	    }

        virtual ~Alcohol(){}

        virtual void dilute() = 0;

        double get_alcohol_content(){
            return _content;
        }

        int get_price(){
            return _price;
        }

        std::string get_name(){
            return _name;
        }
};

#endif