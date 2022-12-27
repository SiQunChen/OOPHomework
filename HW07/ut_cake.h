#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../src/cake.h"
#include "../src/cake_showcase.h"
#include "../src/chocolate_cake.h"
#include "../src/geode_cake.h"
#include "../src/honey_cake.h"
TEST(CakeTest, Test1){
    Cake *c1 = new ChocolateCake(45, 15);
    Cake *c2 = new GeodeCake(30, 15);
    Cake *c3 = new HoneyCake(10, 5);
    Cake *a[3] = {c1, c2, c3};
    CakeShowcase<Cake> *c = new CakeShowcase<Cake>(3, a);
    ASSERT_EQ("| CakeName             | Price      | Sweet      |\n| -------------------- | ---------- | ---------- |\n| ChocolateCake        |         45 |         15 |\n| GeodeCake            |         30 |         15 |\n| HoneyCake            |         10 |         5 |\n| -------------------- | ---------- | ---------- |", c -> to_string());
    ASSERT_EQ(1, ChocolateCake::get_count());
    ASSERT_EQ(1, GeodeCake::get_count());
    ASSERT_EQ(1, HoneyCake::get_count());
    ASSERT_EQ(45, a[0] -> get_price());
    ASSERT_EQ(15, a[0] -> get_sweet());
    ASSERT_EQ(3, Cake::get_total());
    ASSERT_EQ(85, c -> calc_total_price());
    ASSERT_EQ(35, c -> calc_total_sweet());
    delete c1;
    delete c2;
    delete c3;
    delete c;
}