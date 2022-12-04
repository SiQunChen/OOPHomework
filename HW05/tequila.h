#ifndef TEQUILA_H
#define TEQUILA_H
#include <bits/stdc++.h>

class Tequila : public Alcohol{
    public:
        Tequila() = default;

	    Tequila(std::string name, int price, double content){
            init(name, price, content);
	    }

        ~Tequila(){}

	    void dilute() override{
            _content *= 0.95;
        }

        Tequila operator+(const Tequila &other){
            Tequila tmp;
            tmp._name = this -> _name;
            tmp._price = other._price + this -> _price;
            tmp._content = (this -> _content + other._content)/2;
            return tmp;
        }

        bool operator==(const Tequila &other){
            if (this -> _name == other._name && this -> _price == other._price && this -> _content == other._content){
                return true;
            }
            return false;
        }

        Tequila &operator=(const Tequila &other){
            if (this != &other){
                this -> _name = other._name;
                this -> _price = other._price;
                this -> _content = other._content;
            }
            return *this;
        }
};

#endif