#include <bits/stdc++.h>
#include "../src/drink.h"

/* Place some test here */
TEST(DrinkName0, SweetLevel0){
    ASSERT_THROW(Drink women_coffee("QQ", 0.87), std::string);
}

TEST(DrinkName1, SweetLevel1){
    ASSERT_THROW(Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 69), std::string);
}

TEST(DrinkName2, SweetLevel2){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.87);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    ASSERT_EQ("QQMilkMilkGoodDrinkToMeiPuTea",women_coffee.getName());
}

TEST(DrinkName3, SweetLevel3){
    Drink women_coffee("CHEN WEI is ugly tea", 0.87);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    ASSERT_EQ("CHEN WEI is ugly tea",women_coffee.getName());
}

TEST(DrinkName4, SweetLevel4){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.87);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    ASSERT_EQ(0.87,women_coffee.getSweetnessLevel());
}

TEST(DrinkName5, SweetLevel5){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    ASSERT_EQ(0.69,women_coffee.getSweetnessLevel());
}

TEST(DrinkName6, SweetLevel6){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    ASSERT_EQ(2,women_coffee.getToppingCount());
}

TEST(DrinkName7, SweetLevel7){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    women_coffee.addTopping("Pink corner");
    ASSERT_EQ(3,women_coffee.getToppingCount());
}

TEST(DrinkName8, SweetLevel8){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    women_coffee.addTopping("Pink corner");
    ASSERT_EQ("Bubble",women_coffee.getToppingByIndex(0));
}

TEST(DrinkName9, SweetLevel9){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    women_coffee.addTopping("Pink corner");
    ASSERT_EQ("Pink corner",women_coffee.getToppingByIndex(2));
}

TEST(DrinkName10, SweetLevel10){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    women_coffee.addTopping("Pink corner");
    women_coffee.addTopping("Coconut fruit");
    ASSERT_EQ(4,women_coffee.getToppingCount());
}

TEST(DrinkName11, SweetLevel11){
    Drink women_coffee("QQMilkMilkGoodDrinkToMeiPuTea", 0.69);
    women_coffee.addTopping("Bubble");
    women_coffee.addTopping("Pudding");
    women_coffee.addTopping("Pink corner");
    women_coffee.addTopping("Coconut fruit");
    women_coffee.addTopping("OREEEEEEO");
    ASSERT_EQ(5,women_coffee.getToppingCount());
}