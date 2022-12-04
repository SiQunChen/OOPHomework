#ifndef SOUR_H
#define SOUR_H
#include <bits/stdc++.h>

class Sour : public Alcohol{
    public:
        Sour() = default;

	    Sour(std::string name, int price, double content){
            init(name, price, content);
	    }

        ~Sour(){}

	    void dilute() override{
            _content *= 0.7;
        }

        Sour operator+(const Sour&other){
            Sour tmp;
            tmp._name = this -> _name;
            tmp._price = other._price + this -> _price;
            tmp._content = (this -> _content + other._content)/2;
            return tmp;
        }

        bool operator==(const Sour &other){
            if (this -> _name == other._name && this -> _price == other._price && this -> _content == other._content){
                return true;
            }
            return false;
        }

        Sour &operator=(const Sour &other){
            if (this != &other){
                this -> _name = other._name;
                this -> _price = other._price;
                this -> _content = other._content;
            }
            return *this;
        }
};

#endif