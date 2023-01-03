#ifndef SANDWICH_FACTORY_H
#define SANDWICH_FACTORY_H
#include <bits/stdc++.h>
#include "sandwich.h"
#include "sweet_sandwich.h"
#include "beef_sandwich.h"

template <typename T>
class SandwichFactory{
    public:
        SandwichFactory() = default;

        static T* create_sandwich(int price, int id){
            T* tmp = new T(price, id);
            return tmp;
        }

        static std::vector<T*> create_sandwich_array(int price, int count, std::vector<int> id_list){
            if(count < 0){
                throw std::invalid_argument("price is negative");
            }
            std::vector<T*> arr;
            for(int i = 0; i < count; i++){
                T* tmp = new T(price, id_list[i]);
                arr.push_back(tmp);
            }
            return arr;
        }
};

#endif