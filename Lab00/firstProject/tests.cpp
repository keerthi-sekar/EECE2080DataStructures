// tests.cpp
#include "whattotest.h"
#include <gtest/gtest.h>

int SumTest1(IWidget * widget);

int SumTest1(IWidget * widget)
{
    widget->storeInteger(1);
    widget->storeInteger(3);
    int sum= widget->sum();
    return sum;
}
 
TEST(WidgetWithArrays, SumTest1) 
{ 

    WidgetWithArrays * widget1 = new WidgetWithArrays();
    int sum1 = SumTest1(widget1);
    
    delete widget1;

    ASSERT_EQ(4, sum1);
}
 
TEST(WidgetWithVector, SumTest1) {

    WidgetWithVector * widget1 = new WidgetWithVector();
    int sum1 = SumTest1(widget1);
    
    delete widget1;

    ASSERT_EQ(4, sum1);
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
