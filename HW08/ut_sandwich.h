#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../src/sandwich.h"
#include "../src/sweet_sandwich.h"
#include "../src/beef_sandwich.h"
#include "../src/sandwich_factory.h"
TEST(SandwichTest, Test1){
    /* Pre create these sandwich */
    Sandwich* bf1 = new BeefSandwich(25, 0);
    Sandwich* sw1 = new SweetSandwich(15, 1);
    Sandwich* bf2 = new BeefSandwich(45, 2);
    Sandwich* sw2 = new SweetSandwich(25, 3);

    /* Check record in sandwich */
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(0)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(1)); // TRUE
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(0)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(1)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); // TRUE

    /* Check record size in sandwich */
    ASSERT_EQ(25, bf1->get_price());
    ASSERT_EQ(0, bf1->get_id());
    ASSERT_THROW(SweetSandwich a(-1, 1), std::invalid_argument);
    ASSERT_EQ(2, BeefSandwich::get_size_of_record_container()); // 2
    ASSERT_EQ(2, SweetSandwich::get_size_of_record_container()); // 2
    ASSERT_EQ(4, Sandwich::get_size_of_record_container()); // 4

    /* Delete some sandwich and check record */
    delete sw1;
    delete bf1;

    /* Check record in sandwich */
    ASSERT_FALSE(BeefSandwich::record_has_specific_id(0)); // FALSE
    ASSERT_FALSE(SweetSandwich::record_has_specific_id(1)); // FALSE
    ASSERT_TRUE(BeefSandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(SweetSandwich::record_has_specific_id(3)); // TRUE
    ASSERT_FALSE(Sandwich::record_has_specific_id(0)); // FALSE
    ASSERT_FALSE(Sandwich::record_has_specific_id(1)); // FALSE
    ASSERT_TRUE(Sandwich::record_has_specific_id(2)); // TRUE
    ASSERT_TRUE(Sandwich::record_has_specific_id(3)); // TRUE

    /* Check record size in sandwich */
    ASSERT_EQ(1, BeefSandwich::get_size_of_record_container()); // 1
    ASSERT_EQ(1, SweetSandwich::get_size_of_record_container()); // 1
    ASSERT_EQ(2, Sandwich::get_size_of_record_container()); // 2

    delete sw2;
    delete bf2;
}

TEST(SandwichTest, Test2){
    SweetSandwich* sweet_sandwich = SandwichFactory<SweetSandwich>::create_sandwich(15, 32767);
    ASSERT_EQ(1, SweetSandwich::get_size_of_record_container());
    std::vector<SweetSandwich*> sweet_sandwich_set = SandwichFactory<SweetSandwich>::create_sandwich_array(15, 5, {33, 44, 55, 66, 99});
    ASSERT_EQ(6, SweetSandwich::get_size_of_record_container());
    ASSERT_THROW(SandwichFactory<SweetSandwich>::create_sandwich_array(15, -1, {33, 44, 55, 66, 99}), std::invalid_argument);
    delete sweet_sandwich;
    delete sweet_sandwich_set[0];
    delete sweet_sandwich_set[1];
    delete sweet_sandwich_set[2];
    delete sweet_sandwich_set[3];
    delete sweet_sandwich_set[4];
}