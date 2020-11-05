#include <time.h>
#include <stdlib.h>
#include <vector>
#include "CharacterFactory.h"
#include <algorithm>
#include "Wizard.h"
#include <iostream>
//#include "Party.h"

int main()
{
   srand(time(NULL));
   bool victory1;
   bool victory2;

   CharacterFactory factory;

   //First Party Characters
   Character *Wizard1 = factory.CreateCharacter(CharacterFactory::enumOfClass::WizardClass, CharacterFactory::enumOfRace::HalflingRace);
   Character *Cleric1 = factory.CreateCharacter(CharacterFactory::enumOfClass::ClericClass, CharacterFactory::enumOfRace::DwarfRace);
   Character *Rogue1 = factory.CreateCharacter(CharacterFactory::enumOfClass::RogueClass, CharacterFactory::enumOfRace::HumanRace);
   Character *Fighter1 = factory.CreateCharacter(CharacterFactory::enumOfClass::FighterClass, CharacterFactory::enumOfRace::DwarfRace);
   Wizard1->setParty(1);
   Wizard1->setWizard();
   Cleric1->setParty(1);
   Rogue1->setParty(1);
   Rogue1->setRogue();
   Fighter1->setParty(1);

   Party<Character> party1 = Party<Character>(Fighter1, Rogue1, Cleric1, Wizard1);

   //Second Party Characters
   Character *Wizard2 = factory.CreateCharacter(CharacterFactory::enumOfClass::WizardClass, CharacterFactory::enumOfRace::ElfRace);
   Character *Cleric2 = factory.CreateCharacter(CharacterFactory::enumOfClass::ClericClass, CharacterFactory::enumOfRace::HalflingRace);
   Character *Rogue2 = factory.CreateCharacter(CharacterFactory::enumOfClass::RogueClass, CharacterFactory::enumOfRace::HumanRace);
   Character *Fighter2 = factory.CreateCharacter(CharacterFactory::enumOfClass::FighterClass, CharacterFactory::enumOfRace::HalflingRace);
   Wizard2->setParty(2);
   Wizard2->setWizard();
   Cleric2->setParty(2);
   Rogue2->setParty(2);
   Rogue2->setRogue();
   Fighter2->setParty(2);

   Party<Character> party2 = Party<Character>(Fighter2, Rogue2, Cleric2, Wizard2);

   std::vector<int> initiative{Wizard1->getInitiativeBonus(), Cleric1->getInitiativeBonus(),
                               Rogue1->getInitiativeBonus(), Fighter1->getInitiativeBonus(), Wizard2->getInitiativeBonus(),
                               Cleric2->getInitiativeBonus(), Rogue2->getInitiativeBonus(), Fighter2->getInitiativeBonus()};

   sort(initiative.begin(), initiative.end());

   std::vector<Character *> characters{Wizard1, Cleric1, Rogue1, Fighter1, Wizard2, Cleric2, Rogue2, Fighter2};
   std::vector<Character *> attackorder{Wizard1, Cleric1, Rogue1, Fighter1, Wizard2, Cleric2, Rogue2, Fighter2};

   for (int i = 0; i < initiative.size(); i++)
   {
      for (int j = 0; j < characters.size(); j++)
      {

         if (initiative.at(i) == characters.at(j)->getInitiativeBonus())
         {
            attackorder.at(i) = characters.at(j);
         }
      }
   }
   while (victory1 != true && victory2 != true)
   {
      for (int i = 0; i < attackorder.size(); i++)
      {
         if (attackorder.at(i)->getParty() == 1 && attackorder.at(i)->getWizard() == 1)
         {
            attackorder.at(i)->AttackWizard(party2);
            if (party2.backrow.at(0)->isAlive() == false && party2.backrow.at(1)->isAlive() == false && party2.frontrow.at(0)->isAlive() == false && party2.frontrow.at(1)->isAlive() == false)
            {
               victory1 = true;
            }
         }
         else if (attackorder.at(i)->getParty() == 1 && attackorder.at(i)->getRogue() == 1)
         {
            if (party2.backrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.backrow.at(0));
            }
            else if (party2.backrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.backrow.at(1));
            }
            else if (party2.frontrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.frontrow.at(0));
            }
            else if (party2.frontrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.frontrow.at(1));
            }
            else
            {
               victory1 = true;
            }
         }
         else if (attackorder.at(i)->getParty() == 1)
         {
            if (party2.frontrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.frontrow.at(0));
            }
            else if (party2.frontrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.frontrow.at(1));
            }
            else if (party2.backrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.backrow.at(0));
            }
            else if (party2.backrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party2.backrow.at(1));
            }
            else
            {
               victory1 = true;
            }
         }
         else if (attackorder.at(i)->getParty() == 2 && attackorder.at(i)->getWizard() == 1)
         {
            attackorder.at(i)->AttackWizard(party1);
            if (party1.backrow.at(0)->isAlive() == false && party1.backrow.at(1)->isAlive() == false && party1.frontrow.at(0)->isAlive() == false && party1.frontrow.at(1)->isAlive() == false)
            {
               victory2 = true;
            }
         }
         else if (attackorder.at(i)->getParty() == 2 && attackorder.at(i)->getRogue() == 1)
         {
            if (party1.backrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.backrow.at(0));
            }
            else if (party1.backrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.backrow.at(1));
            }
            else if (party1.frontrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.frontrow.at(0));
            }
            else if (party1.frontrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.frontrow.at(1));
            }
            else
            {
               victory2 = true;
            }
         }
         else if (attackorder.at(i)->getParty() == 2)
         {
            if (party1.frontrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.frontrow.at(0));
            }
            else if (party1.frontrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.frontrow.at(1));
            }
            else if (party1.backrow.at(0)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.backrow.at(0));
            }
            else if (party1.backrow.at(1)->isAlive() == true)
            {
               attackorder.at(i)->Attack(party1.backrow.at(1));
            }
            else
            {
               victory2 = true;
            }
         }
      }
   }

   if(victory1 == true)
   {
      std::cout << "Party 1 has won!" << std::endl;
   }
   else if(victory2 == true)
   {
      std::cout << "Party 2 has won!" << std::endl;
   }

}