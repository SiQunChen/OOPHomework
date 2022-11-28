#include <string>
#ifndef  Product_h
#define	Product_h
class Product{
public:
	void init(std::string name, int price){
		if(name.length() < 4){
			throw std::string("Name should longer than 4.");
		}
		if(!(0 <= price)){
			throw std::string("Price should be between [0, inf).");
		}
		_name = name;
		_price = price;
	}

	Product() = default;

	Product(std::string name, int price){
		init(name, price);
	}

	~Product(){}

	std::string getName() const {
            return _name;
	}

	int getPrice() const {
			return _price;
	}

	Product& operator=(const Product& other){
		if (this != &other){
			init(other.getName(), other.getPrice());
		}
		return *this;
	}
	
	bool operator==(const Product& other){
		if ((this -> getName() == other.getName()) && (this -> getPrice() == other.getPrice())){
			return true;
		}
		else{
			return false;
		}
	}

private:
	std::string _name = "";
	int _price = -1;
};
#endif