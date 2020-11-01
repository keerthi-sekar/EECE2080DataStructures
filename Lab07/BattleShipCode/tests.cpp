// tests.cpp
#include "Zerg.h"
#include <gtest/gtest.h>


		
 		TEST(StackTests,isEmpty1)
		{
			Zerg zerg;

			int hullMods = zerg.GetHullPointMods() ;
			int gunMods = zerg.GetGunMods() ;
			int dmgMods = zerg.GetDmgPerGunMods() ;

			ASSERT_EQ(hullMods,-1);
			ASSERT_EQ(gunMods,0);
			ASSERT_EQ(dmgMods,2);
		}









 

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
