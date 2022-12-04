#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "../src/tequila.h"

TEST(TequilaTest, Test1){
    Tequila tequila1("tequila1", 500, 0.5);
    Tequila tequila2("tequila2", 300, 0.3);
    Tequila tequila;
    tequila = (tequila1 + tequila2);
    tequila2.dilute();
    ASSERT_EQ(tequila == tequila1, false);
    ASSERT_EQ(tequila == tequila2, false);
    ASSERT_THROW(Tequila tequila3("", 300, 0.3), std::invalid_argument);
    ASSERT_THROW(Tequila tequila4("tequila2", -300, 0.3), std::invalid_argument);
    ASSERT_THROW(Tequila tequila5("tequila2", 300, 1.3), std::invalid_argument);
}