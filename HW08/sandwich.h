#ifndef SANDWICH_H
#define SANDWICH_H
#include <bits/stdc++.h>

class Sandwich{
    protected:
        int _price = 0;
        int _id = 0;
        static std::set<int> IDset;
    public:
        Sandwich() = default;

        Sandwich(int price, int id){
            if(price < 0){
                throw std::invalid_argument("price is negative");
            }
            _price = price;
            _id = id;
            Sandwich::IDset.insert(id);
        }

        virtual ~Sandwich(){}

        int get_price(){
            return _price;
        }

        int get_id(){
            return _id;
        }

        static bool record_has_specific_id(int id){
            for (const auto &s : Sandwich::IDset) {
                if(s == id){
                    return true;
                }
            }
            return false;
        }

        static int get_size_of_record_container(){
            return Sandwich::IDset.size();
        }
};
std::set<int> Sandwich::IDset;
#endif
