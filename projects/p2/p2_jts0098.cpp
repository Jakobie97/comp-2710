#include <iostream>
#include <stdlib.h> 
#include <assert.h>
#include <ctime> 

using namespace std;

/****************************************************************
*
*@Author: Jacob Stockwell 
*  AU_ID JTS0098
*  File name: p2_jts0098.cpp
*
*@Version: Started 05/30/19 - 06/07/19 Finished
*
* Description: Write a program to simulate the duel using this strategy. 
* Your program should use random numbers and the probabilities given 
* in the problem to determine whether a shooter hits his target.
*
* Compiled using Jgrasp and the AU server unix machine
* 
*
******************************************************************/

//parameters to get started provided by the pdf 
bool firstShot = true; 
const double Aarons_prob = 33; // hits 1/3 of the time
const double Bobs_prob = 50;   // hits 1/2 of the time
const double percent = 100;
const double duels = 10000;



//----------------prototypes--------------------------


/* This is a test driver for at_least_two_alive() */
bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {
 
   if ((A_alive && B_alive)|| (B_alive && C_alive) || (A_alive && C_alive)) {
      return true;
   }
   else {
      return false;
   }
}

/* Add more prototypes for other test drivers below */

/*  Reference by pdf
 *
 *   Input: A_alive indicates whether Aaron is alive or dead
 *         C_alive indicates whether Charlie is alive or dead
 *
 *  Return: Change A_alive into false if Aaron is killed.
 *         Change C_alive into false if Charlie is killed.
*/

/*----------Start of Probabilty calculations----------------*/

void Aaron_Shoots1(bool& B_alive, bool& C_alive) {

   double shotFired; 
   
   //determins if person gets hit
   shotFired = rand() % 100; 

   if (shotFired <= Aarons_prob) {
      if (C_alive) {
         C_alive = false; 
         cout << "\t\tCharlie is dead! (✖╭╮✖)" << endl;
         
      }
      else {
         B_alive = false; 
         cout << "\t\tBob is dead (✖╭╮✖)" << endl; 
         
      }
   }
   else {
      cout << "\t\tAaron missed... (。-ω-)" << endl;  
   }
   

}

/*  Reference by pdf
 *
 *  Input: A_alive indicates whether Aaron is alive or dead
 *         C_alive indicates whether Charlie is alive or dead
 *
 *
 *  Return: Change A_alive into false if Aaron is killed.
 *         Change C_alive into false if Charlie is killed.
*/

void Bob_Shoots1(bool& A_alive, bool& C_alive) {

   double shotFired; 
   
   //determins if person gets hit
   shotFired = rand() % 100; 
   
   if (shotFired <= Bobs_prob) {
      if (C_alive) {
         C_alive = false; 
         cout << "\t\tCharlie is dead! (✖╭╮✖)" << endl;
      }
      else {
         A_alive = false; 
         cout << "\t\tAaron is dead! (✖╭╮✖)" << endl; 
      }
   }
   else {
      cout << "\t\tBob missed... (。-ω-)" << endl;  
   }
   
}

/*  Call by pdf
 *   Input: A_alive indicates whether Aaron is alive or dead
 *         C_alive indicates whether Charlie is alive or dead
 *  Return: Change A_alive into false if Aaron is killed.
 *         Change C_alive into false if Charlie is killed.
*/

void Charlie_Shoots1(bool& A_alive, bool& B_alive) {

   double shotFired; 
   
   shotFired = rand() % 100; 

   if (B_alive){
      B_alive = false;
      cout << "\t\tBob is dead! (✖╭╮✖)" << endl;
   }
      
   if (A_alive){
      A_alive = false;
      cout << "\t\tAaron died! (✖╭╮✖)" << endl;
   }
      

}

void Aaron_Shoots2(bool& B_alive, bool& C_alive) {


   double shotFired; 
   
   //intentionally misses first shot 
   if(firstShot ==  true) {
      firstShot = false; 
      cout << "\t\tAaron intentionally missed his first shot" << endl; 
   }
   
   //determins if person gets hit
   shotFired = rand() % 100; 

   if (shotFired <= Aarons_prob) {
      if (B_alive) {
         B_alive = false; 
         cout << "\t\tBob is dead! (✖╭╮✖)" << endl;
      }
      else {
         C_alive = false; 
         cout << "\t\tCharlies is dead (✖╭╮✖)" << endl; 
      }
   }
   else {
      cout << "\t\tAaron missed... (。-ω-)" << endl;  
   }
   

}

/* Press any key function goes here*/
void Press_Any_Key() {
   
   //provided by  the pdf 
   cout << "Press Enter to continue...";
   cin.ignore().get(); //Pause Command for Linux Terminal

}



/*----------Start of Tests----------------*/

void Test_at_least_two_alive(void) {

   cout << "Unit Testing 1: Function – at_least_two_alive()\n";
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n"; 
   
   assert(true == at_least_two_alive(true, true, true)); //111
   cout << "Case passed ...\n";
   
   
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true)); //011
   cout << "Case passed ...\n";
   
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n"; 
   assert(true == at_least_two_alive(true, false, true)); //101
   cout << "Case passed ...\n";
   
   cout << "\tCase 4: Aaron alive, Bob dead, Charlie dead" << endl;
   assert(false == at_least_two_alive(true, false, false));//100
   cout << "Case passed ...\n";
   
   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive" << endl;
   assert(false == at_least_two_alive(false, false, true)); //001
   cout << "Case passed ...\n";
   
   cout << "\tCase 6: Aaron dead, Bob dead, Charlie dead" << endl;
   assert(false == at_least_two_alive(false, false, false)); //000
   cout << "Case passed ...\n";
   
   cout << "\tCase 7: Aaron alive, Bob alive, Charlie dead" << endl;
   assert(true == at_least_two_alive(true, true, false));//110
   cout << "Case passed ...\n";

}


//Test cases for Aaron 
void Test_Aaron_Shoots1(void) {

   bool Charlie, Bob = true; 

   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)" << endl;
   
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive" << endl;
   Bob = true;
   Charlie = true;
   cout << "\t\tAaron is shooting at Charlie" << endl; 
   Aaron_Shoots1(Charlie, Bob);
   
   cout << "\tCase 2: Bob dead, Charlie alive" << endl;
   Bob = false; 
   Charlie = true; 
   cout << "\t\tAaron is shooting at Charlie" << endl;
   Aaron_Shoots1(Bob, Charlie); 
   
   cout << "\tCase 3: Bob alive, Charlie dead" << endl;
   Bob = true; 
   Charlie = false; 
   cout << "\t\tAaron is shooting at Bob" << endl;
   Aaron_Shoots1(Bob, Charlie);
   
}


//Test casees for bob  
void Test_Bob_Shoots1(void) {
   bool Aaron, Charlie = true;

   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)" << endl; 

   cout << "\tCase 1: Aaron alive, Charlie alive" << endl;
   Aaron = true; 
   Charlie = true;
   cout << "\t\tBob is shooting at Charlie" << endl;
   Bob_Shoots1(Aaron, Charlie);

   cout << "\tCase 2: Aaron dead, Charlie alive" << endl; 
   Aaron = false;
   Charlie = true; 
   cout << "\t\tAaron is shooting at Charlie" << endl;
   Bob_Shoots1(Aaron, Charlie);

   cout << "\tCase 3: Aaron alive, Charlie dead" << endl;
   Aaron = true;
   Charlie = false; 
   cout << "\t\tBob is shooting at Aaron" << endl;
   Bob_Shoots1(Aaron, Charlie);
}

//Charlie test cases 
void Test_Charlie_Shoots1(void) {
   
   bool Aaron, Bob = true;
  
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Charlie_alive)" << endl;
  
   cout << "\tCase 1: Aaron alive, Bob alive" << endl;
   Aaron = true; 
   Bob = true;
   cout << "\t\tCharlie is shooting at Bob" << endl;
   Charlie_Shoots1(Aaron, Bob);
  
   cout << "\tCase 2: Aaron dead, Bob alive" << endl;
   Aaron = false; 
   Bob = true;
   cout << "\t\tCharlie is shooting at Aaron" << endl;
   Charlie_Shoots1(Aaron, Bob);
  
   cout << "\tCase 3: Aaron alive, Bob dead" << endl;
   Aaron = true; 
   Bob = false;
   cout << "\t\tCharlie is shooting at Aaron" << endl;
   Charlie_Shoots1(Aaron, Bob);
  
}

void Test_Aaron_Shoots2(void) {
   
   bool Bob, Charlie = true;

   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)" << endl;
   cout << "\tCase 1: Bob alive, Charlie alive" << endl; 
   Bob = true;
   Charlie = true; 
   
   Aaron_Shoots2(Bob, Charlie);
   cout << "\t\tBoth Bob and Charlie are alive." << endl;

   cout << "\tCase 2: Bob dead, Charlie alive" << endl; 
   Bob = false; 
   Charlie  = true;
   Aaron_Shoots2(Bob, Charlie); 

   cout << "\tCase 3: Bob alive, Charlie dead" << endl; 
   Bob = true;
   Charlie = false;
   cout << "\t\tAaron is shooting at Bob" << endl;
   Aaron_Shoots2(Bob, Charlie); 
}
/*----------End of Tests----------------*/



/*----------Start of main----------------*/ 
int main() {

//variables 
   bool aaron_live = true;
   bool bob_live = true;
   bool charlie_live = true;

  // winnings for the playeras round 1
   int Aaron_wins = 0;
   int Bob_wins = 0;
   int Charlie_wins = 0; 

   // winnings for the playeras round 2
   int Aaron_wins2 = 0;
   int Bob_wins2 = 0;
   int Charlie_wins2 = 0; 

   srand(time(0)); 
   srand(time(0));
   
   
   //TITLE 
   cout << "*** Welcome to Jacob’s Duel Simulator ***" << endl;
   
   //Start of Test cases 
   Test_at_least_two_alive();
   Press_Any_Key(); 
   cout << endl;
   
   Test_Aaron_Shoots1();
   Press_Any_Key(); 
   cout << endl;
   
   Test_Bob_Shoots1();
   Press_Any_Key(); 
   cout << endl;
   
   Test_Charlie_Shoots1();
   Press_Any_Key(); 
   cout << endl;
   
   Test_Aaron_Shoots2();
   Press_Any_Key(); 
   cout << endl;
   
   cout << "\nReady to test strategy 1 (run 10000 times):\n";
   Press_Any_Key(); 
   
   //begining of for loop for strategy 1
   for (int i = 0; i < duels; i++) {
   
       
    
    //Emailed TA twice No responce 
    //Will give either 100% when While is comment out or 0% on winnings with while loop 
    //Asked prof and still could not find the variable causing the issue
      while (at_least_two_alive(aaron_live, bob_live, charlie_live)) {
      
         if (aaron_live) {
            Aaron_Shoots1(bob_live, charlie_live);
         }
         if (bob_live) {
            Bob_Shoots1(aaron_live, charlie_live);
         }
         if (charlie_live) {
            Charlie_Shoots1(aaron_live, bob_live);
         }
      } 
      
      /*--------------THIS WHILE LOOP CAUSES AN INFINIT LOOP-------------*/
      
      if (aaron_live) {
         Aaron_wins++;
      }
      if (bob_live) {
         Bob_wins++;
      }
      if (charlie_live) {
         Charlie_wins++;
      }
      
      
   }
   /*-----------end of for loop----------------------*/
   
   //Outputs for strategy 1 go here 
   
   cout << "\nAaron won " << Aaron_wins << "/" << duels << " duels or " << (Aaron_wins/duels) * percent << "%" << endl; 
   cout << "Bob won " << Bob_wins << "/" << duels << " duels or " << (Bob_wins/duels) * percent << "%" << endl; 
   cout << "Charlie won " << Charlie_wins << "/" << duels << " duels or " << (Charlie_wins/duels) * percent << "%" << endl;
   
    
   
   cout << "\nReady to test strategy 2 (run 10000 times):\n";
   Press_Any_Key();
   
   //variables for strategy 2
   bool aa_live = true;
   bool bb_live = true;
   bool cc_live = true;
   
   //-----begining of for loop for strategy 2-------------
   for (int i = 0; i < duels; i++) {
     
   
     //Emailed TA twice No responce 
    //Will give either 100% or 0% on winnings
    //Asked prof and still could not find the variable causing the issue
      while (at_least_two_alive(aa_live, bb_live, cc_live)) {
      
         if (aa_live) {
            Aaron_Shoots2(bb_live, cc_live);
         }
         if (bb_live) {
            Bob_Shoots1(aa_live, cc_live);
         }
         if (cc_live) {
            Charlie_Shoots1(aa_live, bb_live);
         }
      }
      /*-----------end of while loop----------------------*/
      
      if (aa_live) {
         Aaron_wins2++;
      }
      if (bb_live) {
         Bob_wins2++;                   
      }
      if (cc_live) {
         Charlie_wins2++;
      }
      
   }
   /*-----------end of for loop----------------------*/
   
   //outputs for strategy 2 go here 
   
   cout << "\nAaron won " << Aaron_wins << "/" << duels << " duels or " << (Aaron_wins/duels) * percent << "%" << endl; 
   cout << "Bob won " << Bob_wins << "/" << duels << " duels or " << (Bob_wins/duels) * percent << "%" << endl; 
   cout << "Charlie won " << Charlie_wins << "/" << duels << " duels or " << (Charlie_wins/duels) * percent << "%" << endl; 

  
  
   //Checks to see which strategy  is better 
   if (Aaron_wins > Aaron_wins2) {
   
      cout << "\nStrategy 1 is better than Strategy 2" << endl;
   }
   
   else if (Aaron_wins2 > Aaron_wins) {
   
      cout << "\nStrategy 2 is better than Strategy 2" << endl;
   }
   else {
      cout << "\nThey are equal" << endl; //fail safe if they are equal (should not exicute)
   }
   
   
   
   return 0;
}

