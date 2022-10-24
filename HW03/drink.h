#include <string>
#include <vector>

class Drink{
private:
    /* Put some attribute on here if necessary. */
    double _sweetness_level;
    std::string _name;
    std::vector<std::string> _topping;
    int count = 0;
public:
    /* The constructor of the Drink. */
    Drink(){
        _sweetness_level = 6666699999;
        _name = "";
    }
    Drink(std::string name, double sweetness_level){
        if(name == "" || name.length() < 5 || sweetness_level > 1 || sweetness_level < 0){
            throw std::string("Wrong!");
        }
        else{
            _sweetness_level = sweetness_level;
            _name = name;
        }
    }
    /* The destructor of the Drink. */
    ~Drink(){

    }
    /* Return the name of drink. */
    std::string getName(){
        if(_name == "" || _name.length() < 5){
            throw std::string("Undefined.");
        }
        else{
            return _name;
        }
    }
    /* Return the level of sweetness. */
    double getSweetnessLevel(){
        if(_sweetness_level > 1 || _sweetness_level < 0){
            throw std::string("Undefined.");
        }
        else{
            return _sweetness_level;
        }
    }
    /* Add a topping to the drink. */
    void addTopping(std::string topping){
        _topping.push_back(topping);
        count += 1;
    }
    /* Get the topping of drink by index, the index is determine by the order of topping added and start from 0. */
    std::string getToppingByIndex(int index){
        if(index > count-1){
            throw std::string("TOO OVER!");
        }
        else{
            return _topping[index];
        }
    }
    /* Get the count of topping in drink. */
    int getToppingCount(){
        return count;
    }
};
