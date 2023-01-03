#ifndef BEEF_SANDWICH_H
#define BEEF_SANDWICH_H
#include <bits/stdc++.h>
#include "sandwich.h"

class BeefSandwich : public Sandwich{
    private:
        static std::set<int> IDset;
    public:
        BeefSandwich() = default;
        
        BeefSandwich(int price, int id) : Sandwich(price, id){
            BeefSandwich::IDset.insert(id);
        }

        ~BeefSandwich()override{
            Sandwich::IDset.erase(_id);
            BeefSandwich::IDset.erase(_id);
        }

        static bool record_has_specific_id(int id){
            if(BeefSandwich::IDset.count(id) == 1){
                return true;
            }
            return false;
        }

        static int get_size_of_record_container(){
            return BeefSandwich::IDset.size();
        }
};
std::set<int> BeefSandwich::IDset;
#endif