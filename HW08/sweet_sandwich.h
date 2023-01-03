#ifndef SWEET_SANDWICH_H
#define SWEET_SANDWICH_H
#include <bits/stdc++.h>
#include "sandwich.h"

class SweetSandwich : public Sandwich{
    private:
        static std::set<int> IDset;
    public:
        SweetSandwich() = default;

        SweetSandwich(int price, int id) : Sandwich(price, id){
            SweetSandwich::IDset.insert(id);
        }

        ~SweetSandwich()override{
            Sandwich::IDset.erase(_id);
            SweetSandwich::IDset.erase(_id);
        }

        static bool record_has_specific_id(int id){
            if(SweetSandwich::IDset.count(id) == 1){
                return true;
            }
            return false;
        }

        static int get_size_of_record_container(){
            return SweetSandwich::IDset.size();
        }
};
std::set<int> SweetSandwich::IDset;
#endif