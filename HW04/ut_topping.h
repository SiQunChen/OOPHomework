#include <cmath>

TEST(ToppingTest, TestWithCopyConstructor){
    Topping topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithCopyAssignment){
    Topping topping;
    topping = Topping("Bubble", 0.4, 5);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_EQ(topping.getSweetnessLevel(), 0.4);
    ASSERT_EQ(topping.getPrice(), 5);
}

TEST(ToppingTest, TestWithWrongValue){
    ASSERT_THROW(Topping("Bub", 0.4, 5), std::string);
    ASSERT_THROW(Topping("Bubble", -0.1, 5), std::string);
    ASSERT_THROW(Topping("Bubble", 0.4, -5), std::string);
}

TEST(DrinkTest, Test1){
    Drink women_coffee("Signature Black Tea with Milk", 0.3, 45);
    ASSERT_EQ(women_coffee.getName(), "Signature Black Tea with Milk");
    ASSERT_EQ(women_coffee.getSweetnessLevel(), 0.3);
    ASSERT_EQ(women_coffee.getPrice(), 45);
}

TEST(DrinkTest, Test2){
    Drink women_coffee("Signature Black Tea with Milk", 0.3, 45);
    women_coffee.addTopping(Topping("Bubble", 0.15, 5));
    ASSERT_EQ(women_coffee.getName(), "Signature Black Tea with Milk");
    ASSERT_NEAR(women_coffee.getSweetnessLevel(), 0.45, 0.1);
    ASSERT_EQ(women_coffee.getPrice(), 50);
}

TEST(DrinkTest, Test3){
    Drink women_coffee("Black Tea", 0.2, 15);
    Drink drink;
    drink = women_coffee;
    ASSERT_EQ(drink.getName(), "Black Tea");
    ASSERT_NEAR(drink.getSweetnessLevel(), 0.2, 0.1);
    ASSERT_EQ(drink.getPrice(), 15);
}

TEST(DrinkTest, Test4){
    Drink women_coffee("Black Tea", 0.2, 15);
    women_coffee.addTopping(Topping("Bubble", 0.15, 5));
    Topping topping = women_coffee.getToppingByIndex(0);
    ASSERT_EQ(topping.getName(), "Bubble");
    ASSERT_NEAR(topping.getSweetnessLevel(), 0.15, 0.1);
    ASSERT_EQ(topping.getPrice(), 5);
    ASSERT_EQ(women_coffee.getToppingCount(), 1);
}

TEST(DrinkTest, Test5){
    ASSERT_THROW(Drink women_coffee("Black Tea", -0.2, 15), std::string);
}

TEST(DrinkTest, Test6){
    ASSERT_THROW(Drink women_coffee("Black Tea", 0.2, -15), std::string);
}

TEST(DrinkTest, Test7){
    ASSERT_THROW(Drink women_coffee("Tea", 0.2, 15), std::string);
}

TEST(DrinkTest, Test8){
    Drink women_coffee;
    ASSERT_THROW(women_coffee.getName(), std::string);
    ASSERT_THROW(women_coffee.getSweetnessLevel(), std::string);
    ASSERT_THROW(women_coffee.getPrice(), std::string);
    ASSERT_THROW(women_coffee.getToppingByIndex(1), std::string);
}
