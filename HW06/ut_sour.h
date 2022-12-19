#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../src/sour.h"

TEST(SourTest, Test1){
    Sour sour1("sour1", 500, 0.5);
    Sour sour2("sour2", 300, 0.3);
    Sour sour3("sour1", 500, 0.5);
    Sour sour;
    sour = (sour1 + sour2);
    sour2.dilute();
    ASSERT_EQ(sour == sour1, false);
    ASSERT_EQ(sour == sour2, false);
    ASSERT_EQ(sour1 == sour3, true);
    ASSERT_THROW(Sour tequila3("", 300, 0.3), std::invalid_argument);
    ASSERT_THROW(Sour tequila4("sour2", -300, 0.3), std::invalid_argument);
    ASSERT_THROW(Sour tequila5("sour2", 300, 1.3), std::invalid_argument);
}