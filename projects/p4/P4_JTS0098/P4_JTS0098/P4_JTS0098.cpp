#include <iostream>
#include <cstring>
# include <assert.h>
# include <cstdlib>
using namespace std;
/*********************************************************************
 *
 *@Author - Jacob Stockwell Au_IS: JTS0098
 *@version: 06/17/19 
 *
 *
 *Description: this project is designed to use singly linked list by
 * creating a fun quiz game!
 *
 ********************************************************************/

 //variables for main
int TotalQ = 0;
bool cont = false;

//--------------constructor of the node for trivia--------------------- 
struct TriviaNode {

	//variables for our node structure 
   string question;
   string answer;
	
   int points = 0;

   TriviaNode* pointer; // links and goes to next node 
};

//------------Initializes the Trivia Linked list ------------------------
void initializeQuestion(TriviaNode* s) {
	
	//links them togethor 
   TriviaNode* Question1 = s;
   TriviaNode* Question2 = new TriviaNode;
   TriviaNode* Question3 = new TriviaNode;

	//Format for the three standard question referenced by pdf
   Question1->question = "What location/event In New York City that sparked the first LGBTQ+ pride? (Hint: The first pride was a riot)";
   Question1->answer = "stonewall";
   Question1->points = 100;
   Question1->pointer = Question2;

   Question2->question = "What year was the Nintendo 64 released? (Hint: It was released sometime in the 90's)";
   Question2->answer = "1996";
   Question2->points = 50;
   Question2->pointer = Question3;

   Question3->question = "What University did Tim Cook, The CEO of Apple, attend? (Hint the colors of his university are orange and blue)";
   Question3->answer = "Auburn";
   Question3->points = 20;
   Question3->pointer = NULL;

   TotalQ = 3;

}

//--------------Function adds questions to the node list -----------------------
void addQuestionToList(TriviaNode *s) {

   string keepGoing;
	
		//goes to end of the linked list
   while (s->pointer != NULL)
   {
      s = s->pointer;
   }

		// Creates a new node so user can add their questions
   TriviaNode *UserInput = new TriviaNode();

   cout << "Enter a question: ";
   cin >> UserInput->question;
		

   cout << "Enter an answer: ";
   cin >> UserInput->answer;
		

   cout << "Enter award points: ";
   cin >> UserInput->points;
		
   s->pointer = UserInput;

   cout << "Continue? (y/n) "; 
   TotalQ++;
   cin >> keepGoing;


		//breaks the do while loop in main function
   if (keepGoing.compare("n") == 0 || keepGoing.compare("N") == 0) {
      cont = false;
   }
   else {
      cont = true;
   }

}

//------------------Function checks the answer-------------------
bool checksTheAnswer(string answr, TriviaNode* n) {

	//compares the correct answer that to what was given 
   if (n->answer.compare(answr) == 0)
   {
      return true;
   }
   else
   {
      return false;
   }

}

//------------------ Function for asking the question------------
void askQuestion(TriviaNode *a, int total) {

   int allPoints = 0;
   bool correct = true;
   string userInput = ""; 
	//int totalNumberQuestions = 3; standard number from intializing the questions

	//error checking 
   if (total == 0) {
      cout << "Warning – The number of trivia to be asked must equal to or larger than 1." << endl;
   }
   
   else if (total == 1) {
      cout << "Question: " << a -> question << endl;
      cout << "Answer: ";
      cin >> userInput;
   
      if(checksTheAnswer(userInput, a)){
         correct = true;
      }
      else {
         correct = false;
      }
   
      a = a->pointer;
      cout << endl; //spacing 
   }
   
   else if (total == 3) {
   
      while (a->pointer != NULL)
      {
         a = a->pointer;
      }
   
      cout << "\nQuestion: " << a -> question << endl;
      cout << "Answer: ";
      cin >> userInput;
   }
   
   else if (total > TotalQ)
   {
      cout << "Warning - There are only three trivia in the list." << endl;
   }
   
   //--------------main part of function------------------------
   else {
   
      for (int i = 0; i < total; i++) {
         cout << "\nQuestion: " << a -> question << endl;
         cout << "Answer: ";
         cin >> userInput;	
      	
      
         if (checksTheAnswer(userInput, a)) {
            cout << "You got the right answer! You get " << a-> points << " points." << endl;
            allPoints += a->points;
            cout << "Your total number of points are: " << allPoints << endl;
         }
         else {
            cout << "Your answer was incorrect! The correct answer is " << a-> answer << endl;
            cout << "Your current number of points are: " << allPoints << endl;
         
            a = a->pointer;
            cout << endl; //spacing 
         }
         a = a->pointer;
      }
   }
}

//------------------ Unit Testing -------------------------------

void Unit_Test(TriviaNode *test) {

	//variables for testing 
   bool correct = true;

   cout << "*** This is a debugging version ***" << endl;

   cout << "Unit Test Case 1: Ask no question. The program should give a warning message. " << endl; 
   askQuestion(test, 0);

   cout << "Unit Test Case 2.1: Ask 1 question in the linked list. The tester enters an incorrect answer." << endl;
   askQuestion(test, 1);

   if (!correct)
   {
      cout << "Case 2.1: Passed... " << endl;
   }

   cout << "Unit Test Case 2.2: Ask 1 question in the linked list. The tester enters the correct answer." << endl;
   askQuestion(test, 1);

   if (correct)
   {
      cout << "Case 2.1: Passed... " << endl;
   }

   cout << "Unit Test Case 3: Ask all the questions of the last trivia in the linked list." << endl;
   askQuestion(test, 3);

   cout << "Unit Test Case 4: Ask five questions in the linked list." << endl;
   askQuestion(test, 5);

   cout << "*** End of the Debugging Version ***" << endl;
}
//-----------------------Main------------------------------------
int main(){
	

	//debug version
	#ifdef UNIT_TESTING 
    TriviaNode *starter = new TriviaNode;
    initializeQuestion(starter);
    Unit_Test(starter);
}
	#else 

	//product version 
   TriviaNode *driver2 = new TriviaNode;
   initializeQuestion(driver2);

   cout << "*** Welcome to jacobs trivia quiz game ***" << endl;

	//do while that creates the users questions 
   do {
      addQuestionToList(driver2);
   } while (cont);

	//calls the funtion to asks the question 
   cin.ignore(1);
   askQuestion(driver2, TotalQ);

   cout << "\n*** Thank you for playing the trivia quiz game. Goodbye! ***" << endl;
}
#endif


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
