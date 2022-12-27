#ifndef CAKE_SHOWCASE_H
#define CAKE_SHOWCASE_H
#include <bits/stdc++.h>
#include "cake.h"
#include "chocolate_cake.h"
#include "geode_cake.h"
#include "honey_cake.h"

template <typename T>
class CakeShowcase{
    private:
        int _length = 0;
        T** _array;
    public:
        CakeShowcase() = default;

        CakeShowcase(int length, T** array){
            _length = length;
            _array = array;
        }

        ~CakeShowcase(){};

        int calc_total_price(){
            int total_price = 0;
            for(int i = 0; i < _length; i++){
                total_price += _array[i] -> get_price();
            }
            return total_price;
        }

        int calc_total_sweet(){
            int total_sweet = 0;
            for(int i = 0; i < _length; i++){
                total_sweet += _array[i] -> get_sweet();
            }
            return total_sweet;
        }

        std::string to_string(){
            std::string str = "";
            std::cout << "| CakeName             | Price      | Sweet      |\n";
            str += "| CakeName             | Price      | Sweet      |\n";
            std::cout << "| -------------------- | ---------- | ---------- |\n";
            str += "| -------------------- | ---------- | ---------- |\n";
            for(int i = 0; i < _length; i++){
                str += _array[i] -> to_string();
                std::cout << "\n";
                str += "\n";
            }
            std::cout << "| -------------------- | ---------- | ---------- |\n";
            str += "| -------------------- | ---------- | ---------- |";
            return str;
        }

        T* operator[](int index){
            if(index >= _length || index < 0){
                throw std::out_of_range("out of range!");
            }
            return _array[index];
        }
};

#endif