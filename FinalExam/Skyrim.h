#include <iostream>

using namespace std;

//*Disclaimer*: Advanced apologies my code looks like an essay - i did game dev in my last 2 co-ops and may be thinking about this a little too much lol

//character is a variable where different integers are different objects
// Key: 1 = Chair, 2 = Statue

class Object
{
	public:
		// the common functionality between all objects is set here
		// each function is given dummy values which are overrided in the concrete classes
		//virtual function to determine if it can be sat on
		virtual bool AbleToSit() = 0;
		//virtual function to determine if it can be destroyed
		virtual bool AbleToDestroy() = 0;
		//virtual function for sitting
		virtual void Sit() = 0;
		//virtual function for destroying
		virtual void Destroy() = 0;
		
	protected:
		//character is to allow you to build upon the current requirements (if the functions would require character type, etc.)
		int character;
		//bools below are triggers to check if the object can be sat on or destroyed
		bool sitAbility;
		bool destroyAbility;
};

class Chair : public Object
{
	public:
		Chair()
		{
			character = 1;
			sitAbility = true;
			destroyAbility = true;
		}
		//boolean to determine if the object can be sat on (dummy value of true lets that be the automatic since chair can be sat on to begin with)
		//An edge/corner case AbleToSit can handle is that if AbleToDestroy is false, then sit should also be false since the chair was already destroyed 
		//Additional edge/corner cases can be added if there were players we need to account for - my assumption is that we can disregard that for the final
		bool AbleToSit() { return true; }
		//boolean to determine if the object can be destroyed (dummy value of true since in the beginning since chairs can be destroyed)
		//"Edge case" for AbleToDestroy - if the object is already destroyed; keep the variable as false
		bool AbleToDestroy() { return true; }
		//Since the logic/conditions are handled in the boolean function the sit function will call AbleToSit at the beginning
		//if AbleToSit returns true then the functionality to sit will run, 
		//if AbleToSit returns false that means an edge/corner case was triggered and the chair is not in the state to be sat on and will return an cout statement to let the user know it cannot be sat on (identify error - exception thrown)
		//if we were developing the game, there would be a library of error codes that can be outputted to the user so they know which case they triggered is the bool was false 
		void Sit() {};
		//Since the logic/conditions are handled in the boolean function the sit function will call AbleToDestroy at the beginning
		//if AbleToDestroy returns true then the functionality to destroy will run 
		//if AbleToDestroy returns false that means an edgecase was triggered and the chair is not in the state to be destroyed and will return an cout statement to let the user know it cannot be destroyed (identify error - exception thrown)
		//if we were developing the game, there would be a library of error codes that can be outputted to the user so they know which case they triggered is the bool was false 
		void Destroy() {};
		//~Chair();
};

class Statue: public Object
{
	public:
		Statue()
		{
			character = 2;
			sitAbility = false;
			destroyAbility = false;
		}
		//Since statues in general can not be sat on, the bool is hardcoded to false
		bool AbleToSit() { return false; }
		//Since statues in general can not be destroyed, the bool is hardcoded to false
		bool AbleToDestroy() { return false; }
		//Sit() will use AbleToSit to check before running functionality to ensure that the bool is set to false
		//Sit will then run the output message for false, if needed (by some error or race condition in the fact that accidentally set to true) - hardcoded/log an error in the true condition still
		//so either way it doesn't still actually run the functionality
		void Sit() {};
		//Destroy() will use AbleToDestroy to check before running functionality to ensure that the bool is set to false
		//Destroy will then run the output message for false, if needed (by some error or race condition in the fact that accidentally set to true) - hardcoded/log an error in the true condition still
		//so either way it doesn't still actually run the functionality
		void Destroy() {};
		//~Statue();

};