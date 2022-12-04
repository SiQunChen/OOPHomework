#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../src/alcohol.h"
#include "../src/tequila.h"
#include "../src/sour.h"

class AlcoholTest : public ::testing::Test{
protected:
    Alcohol *a;
    void SetUp() override;
    void TearDown() override;
};

void AlcoholTest::SetUp(){
    a = new Tequila("tequila1", 500, 0.5);
}

void AlcoholTest::TearDown(){
}

TEST_F(AlcoholTest, Test1){
    ASSERT_EQ(a->get_name(), "tequila1");
    ASSERT_EQ(a->get_price(), 500);
    ASSERT_EQ(a->get_alcohol_content(), 0.5);
    delete a;
}
