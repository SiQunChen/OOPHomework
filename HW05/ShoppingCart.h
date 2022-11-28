#include <string>
#include <vector>
#include "Product.h"
#ifndef ShoppingCart_h
#define ShoppingCart_h
class ShoppingCart{
    public:
        void init(int item_list_size, Product* item_list){
            _item_list_size = item_list_size;
            for (int i = 0; i < item_list_size; i++){
                _item_list.push_back(item_list[i]);
                _TotalCost += item_list[i].getPrice();
                for(int j = 0; j < i; j++){
                    if(_item_list[i] == _item_list[j]){
                        throw std::string("Error.");
                    }
                }
            }
        }

        ShoppingCart() = default;
        ShoppingCart(int item_list_size, Product* item_list){
            init(item_list_size, item_list);
        }
        ~ShoppingCart() = default;
        int getItemCount() const {
            return _item_list_size;
        }
        Product getItemByIndex(int index) const {
            if(index > _item_list_size){
                throw std::string("The index too large.");
            }
            else{
                return _item_list[index];
            }
        }
        void setItemByIndex(int index, Product product){
            if(index > _item_list_size){
                throw std::string("Error.");
            }
            else{
                for(int i=0;i<_item_list_size;i++){
                    if(_item_list[i] == product){
                        throw std::string("Repeat product.");
                    }
                }
            }
            _item_list[index] = product;
        }
        void appendItem(Product product){
            for(int i=0;i<_item_list_size;i++){
                if(_item_list[i] == product){
                    throw std::string("Repeat product.");
                }
            }
            _item_list.push_back(product);
            _item_list_size += 1;
            _TotalCost += product.getPrice();
        }
        int getTotalCost() const {
            return _TotalCost;
        }
        ShoppingCart& operator+(const ShoppingCart &other){
            int flag = 0;
            int count = 0;
            for(int i=0;i<other._item_list_size;i++){
                for(int j=0;j<this -> _item_list_size;j++){
                    if(this -> _item_list[j] == other._item_list[i]){
                        flag = 1;
                    }
                }
                if(flag == 0){
                    this -> _item_list.push_back(other._item_list[i]);
                    this -> _TotalCost += other._item_list[i].getPrice();
                    count += 1;
                }
                flag = 0;
            }
            this -> _item_list_size += count;
            return *this;
        }
        ShoppingCart& operator-(const ShoppingCart &other){
            std::vector<Product> temp;
            int flag = 0;
            for(int i=0;i<this -> _item_list_size;i++){
                for(int j=0;j<other._item_list_size;j++){
                    if(this -> _item_list[i] == other._item_list[j]){
                        flag = 1;
                    }
                }
                if(flag == 0){
                    temp.push_back(this -> _item_list[i]);
                }
                flag = 0;
            }
            this -> _item_list.clear();
            this -> _TotalCost = 0;
            for(int i=0;i<temp.size();i++){
                this -> _item_list.push_back(temp[i]);
                this -> _TotalCost += temp[i].getPrice();
            }
            this -> _item_list_size = temp.size();
            return *this;
        }
        ShoppingCart& operator=(const ShoppingCart &other){
            if (this != &other){
                for (int i = 0; i < this -> _item_list_size; i++){
                    this -> _item_list[i] = other._item_list[i];
                }
                this -> _item_list_size = other._item_list_size;
                this -> _TotalCost = other._TotalCost;
            }
            return *this;
        }
    private:
        std::vector<Product> _item_list;
        int _item_list_size = 0;
        int _TotalCost = 0;
};
#endif
