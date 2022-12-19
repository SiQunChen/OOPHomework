#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <bits/stdc++.h>
#include "alcohol.h"

void sort_alcohol_by_content(std::vector<Alcohol*> &alcohol){
    std::sort(alcohol.begin(), alcohol.end(),
                [](Alcohol *a, Alcohol *b){
                    if(a -> get_alcohol_content() < b -> get_alcohol_content()){
                        return true;
                    }
                    else if(a -> get_alcohol_content() == b -> get_alcohol_content()){
                        if(a -> get_name() < b -> get_name()){
                            return true;
                        }
                        return false;
                    }
                    return false;
                });
}

void sort_alcohol_by_name(std::vector<Alcohol*> &alcohol){
    std::sort(alcohol.begin(), alcohol.end(),
                [](Alcohol *a, Alcohol *b){
                    if(a -> get_name() < b -> get_name()){
                        return true;
                    }
                    return false;
                });
}

Alcohol* get_greatest_content_of_alcohol(std::vector<Alcohol*> alcohol){
    /*double ans = 0;
    int record = 0;
    for(int i = 0; i < alcohol.size(); i++){
        if(alcohol[i] -> get_alcohol_content() > ans){
            ans = alcohol[i] -> get_alcohol_content();
            record = i;
        }
    }*/
    sort_alcohol_by_content(alcohol);
    return alcohol[alcohol.size()-1];
}

Alcohol* get_smallest_content_of_alcohol(std::vector<Alcohol*> alcohol){
    /*double ans = 10000;
    int record = 0;
    for(int i = 0; i < alcohol.size(); i++){
        if(alcohol[i] -> get_alcohol_content() < ans){
            ans = alcohol[i] -> get_alcohol_content();
            record = i;
        }
    }*/
    sort_alcohol_by_content(alcohol);
    return alcohol[0];
}

#endif