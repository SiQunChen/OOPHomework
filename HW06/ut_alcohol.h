#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../src/alcohol.h"
#include "../src/tequila.h"
#include "../src/sour.h"
#include "../src/order.h"
#include "../src/algorithm.h"

class AlcoholTest : public ::testing::Test{
protected:
    //Tequila t;
    Order o;
    Alcohol *a;
    Alcohol *b;
    Alcohol *c;
    Alcohol *d;
    Alcohol *e;
    void SetUp() override;
    void TearDown() override;
};

void AlcoholTest::SetUp(){
    //t = Tequila("tequila1", 500, 0.5);
    //a = &t;
    a = new Tequila("DEF", 500, 0.5);
    b = new Sour("ABC", 1000, 0.5);
    c = new Tequila("AB", 800, 0.5);
    d = new Sour("ZXC", 300, 0.8);
    e = new Tequila("ZZZ", 100, 0.6);
}

void AlcoholTest::TearDown(){
    if (a != nullptr)
        delete a;
    if (b != nullptr)
        delete b;
    if (c != nullptr)
        delete c;
    if (d != nullptr)
        delete d;
    if (e != nullptr)
        delete e;
}

TEST_F(AlcoholTest, Test1){
    o.append_alcohol(a);
    o.append_alcohol(b);
    o.append_alcohol(c);
    o.append_alcohol(d);
    o.append_alcohol(e);
    sort_alcohol_by_content(o._alcohol);
    sort_alcohol_by_name(o._alcohol);
    ASSERT_EQ(5, o.get_alcohol_count());
    ASSERT_EQ(2700, o.get_total_price());
    ASSERT_EQ("ZXC", get_greatest_content_of_alcohol(o._alcohol) -> get_name());
    ASSERT_EQ("AB", get_smallest_content_of_alcohol(o._alcohol) -> get_name());
}
