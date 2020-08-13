#include <fstream>
#include <iostream>
#include <cassert>

/**************************************************
 *
 *
 *@Author: Jacob Stockwell AU_ID: JTS0098
 *@version: started 06/09/19 - finished 06/13/19 
 *
 * Description: this program is designed to read 
 * in and ouput txt files  
 *
 * compiled using jgrasp on mac and the AU server
 **************************************************/

using namespace std;

//global variables
const int MAX_SIZE = 100;

/***************************************************************/
/*------------------------ Functions ----------------------------*/
/***************************************************************/

/*--------------Gets the sizes of the array-------------------*/
int readfile(int inputArray[], ifstream& inStream){
   
   int index = 0;
   
   //check file opened
   if (inStream.fail()) {
      cout << "\tInput file opening failed. \n";
      return -1;
   }

   inStream >> inputArray[index];

   while (!inStream.eof()) {
      index++;
      inStream >> inputArray[index];
        //index++;
   }
   index++;
   inStream >> inputArray[index];

   return index;
}

int sort(int inputArray[], int inputArray1_size, int inputArray2[], int inputArray2_size, int outputArray[]) {

   int index = inputArray1_size + inputArray2_size;


//--adding to original list--------------------
   int counter = 0;
   for (int i = 0; i < inputArray1_size; i++) {
      outputArray[i] = inputArray[i];
      counter++;
   }

   int k = 0;
   for (int j = counter; j < counter + inputArray2_size; j++) {
      outputArray[j] = inputArray2[k];
      k++;
   }

//--Start of sorting-------------------------------------
   
   //variables for sorting loop
   int min;
   int Place_holder;

 //--looping thru combined list--------------
   for (int k = 0; k < index - 1; k++) {
      min = k;
   
      for (int l = k + 1; l < index; l++) // sorting by linear scan 
      
         if (outputArray[l] < outputArray[min])
            min = l;
      
      //moves tp the correct spot
      Place_holder = outputArray[k];
      outputArray[k] = outputArray[min];
      outputArray[min] = Place_holder;
   }

   return index;
}

/*--------writes a new file---------*/
void writefile(int outputArray[], int outputArray_size, string fileName) {
   
   ofstream outs;

   outs.open(fileName);

   for (int i = 0; i < outputArray_size; i++) {
      outs << outputArray[i] << endl;
   }

   outs.close();
   outs.clear();
   

}


/*---------------Press any key function goes here--------------*/
void Press_Any_Key() { 
   
   //provided from last week in project 2
   cout << "Press Enter to continue...";
   cin.ignore().get(); //Pause Command for Linux Terminal

}

 /***************************************************************/
/*------------------------ Testing ----------------------------*/
/***************************************************************/

//test the read file function 
void test_readfile(void) {

   //varaibles for testing 
   ifstream inFile;
   int iArray1[MAX_SIZE];
   int iArray_Size;
   
   inFile.open("input1.txt");
   cout << "Unit Test Case 1: Finction name – Read  File." << endl; 
   cout << "\tCase 1.1: reading in the correct normal file input 1." << endl;
   iArray_Size = readfile(iArray1, inFile);
   inFile.close();
    
   assert(6 == iArray_Size);
   assert(4 == iArray1[0]);
   assert(13 == iArray1[1]);
   assert(14 == iArray1[2]);
   assert(17 == iArray1[3]);
   assert(23 == iArray1[4]);
   assert(89 == iArray1[5]);
   cout << "\tCase 1.1 passed!!" << endl;

   inFile.open("input2.txt");
   cout << "\tCase 1.2: reading in the correct normal file input 2." << endl;
   iArray_Size = readfile(iArray1, inFile);
   inFile.close();
    
   assert(5 == iArray_Size);
   assert(3 == iArray1[0]);
   assert(7 == iArray1[1]);
   assert(9 == iArray1[2]);
   assert(14 == iArray1[3]);
   assert(15 == iArray1[4]);
   cout << "\tCase 1.2 passed!!" << endl;
   
   cout << "\tCase 1.3: Invalid file" << endl;
   inFile.open("NotAFile.txt"); 
   iArray_Size = readfile(iArray1, inFile);
   inFile.close();
   assert(-1 == iArray_Size);
   cout << "\tCase 1.3 passed!!" << endl;
   
   cout << "\tCase 1.4: too manny in file" << endl;
   inFile.open("toomany.txt"); 
   iArray_Size = readfile(iArray1, inFile);
   inFile.close();
   assert(-1 == iArray_Size);
   cout << "\tCase 1.4 passed!!" << endl;
}

//test cases for the writing file function 
void test_writefile(){

  //varaibles for test 
   int outputTest[MAX_SIZE] = {3,4,7,9,13,14,14,15,17, 23, 89};
   int newArray[MAX_SIZE];
   int outSize = 11;
   int index = 0;
   string fileName = "testoutput.txt";
   ifstream inFile;
      
   cout << "\nUnit Test Case 2: Finction name – Write File." << endl; 
   cout << "\tCase 2.1: normal case writing the file" << endl;
   
   writefile(outputTest, outSize, fileName);
   inFile.open(fileName); 
   
   inFile >> newArray[index];
   
   while(!inFile.eof()) {
   
      index++;
      inFile >> newArray[index];
   }
   
   inFile.close();
   
   assert(3 == newArray[0]);
   assert(4 == newArray[1]);
   assert(7 == newArray[2]);
   assert(9 == newArray[3]);
   assert(13 == newArray[4]);
   assert(14 == newArray[5]);
   assert(14 == newArray[6]);
   assert(15 == newArray[7]);
   assert(17 == newArray[8]);
   assert(23 == newArray[9]);
   assert(89 == newArray[10]);
   
   cout << "\tCase 2.1 passed!!" << endl;
}

void test_sort() {
   
   //variables for sorting
   int Array1[MAX_SIZE] = {4, 13, 14, 17, 23, 89};;
   int Array2[MAX_SIZE] = {3, 7, 9, 10, 15};
   int Array1_size = 6;
   int Array2_size = 5;
   int outputArray[MAX_SIZE];
   int outputArray_size;
   
   cout << "Unit Test Case 3: Finction name – sorting." << endl;
   cout << "\t Case 3.1: sorting the two arrays" << endl;
   outputArray_size = sort(Array1, Array1_size, Array2, Array2_size, outputArray);

   
   assert(11 == outputArray_size);
   assert(3 == outputArray[0]);
   assert(4 == outputArray[1]);
   assert(7 == outputArray[2]);
   assert(9 == outputArray[3]);
   assert(10 == outputArray[4]);
   assert(13 == outputArray[5]);
   assert(14 == outputArray[6]);
   assert(15 == outputArray[7]);
   assert(17 == outputArray[8]);
   assert(23 == outputArray[9]);
   assert(89 == outputArray[10]);
   
   cout << "\tCase 3.1 passed!!" << endl;
}

/***************************************************************/
/*------------------------MAIN---------------------------------*/
/***************************************************************/

int main() {
   
   //variables for reading the files 
   ifstream inStream;
   ifstream inStream2;
   //int data, data2;
   string filename1, filename2;
   //int count = 0;
   
   //varaibles for  array sizes
   int iArray1[MAX_SIZE];
   int iArray1_size;
   int iArray2[MAX_SIZE];
   int iArray2_size;
   
   //variables for the writing file 
   string outFile;
   int outputArray[MAX_SIZE];
   
   //unit testing 
   test_readfile();
   Press_Any_Key();
   
   test_writefile();
   Press_Any_Key();
   
   test_sort();
   Press_Any_Key();
      
      
      /*---------Prompt-----------------*/
   cout << "*** Welcome to Jacob’s sorting program ***" <<endl;
   
   cout << "Enter the first input file name: ";
   cin >> filename1;
    
   cout << "entered filename is:" << filename1 << endl;
   
   //gets the how many elements are in the txt file 
   
   

/*-------Start of read files---------------------*/
   
   inStream.open((char*)filename1.c_str());
   if (inStream.fail()) {
      cout << "Input file opening failed." << endl; 
      exit(1);
   }
   
   iArray1_size = readfile(iArray1, inStream);

   cout << "The list of " << iArray1_size << " numbers in file " << filename1 << " is:" << endl;

   for (int i = 0; i < iArray1_size; i++) {
      cout << iArray1[i] << endl;
   }   
   inStream.close();
   
   /*-----------FILE 2-----------------------*/
   
   
   cout << "Enter the second input file name:";
   cin >> filename2;
   cout << "entered filename is: " << filename2 << endl;

   inStream2.open((char*)filename2.c_str());
   if (inStream2.fail()) {
      cout << "Input file opening failed." << endl; //error checking 
      exit(1);
   }
   
   iArray2_size = readfile(iArray2, inStream2);

   cout << "The list of " << iArray2_size << " numbers in file " << filename2 << " is:" << endl;

   for (int i = 0; i < iArray2_size; i++) {
      cout << iArray2[i] << endl;
   }

   inStream2.close();
  /*-------------End of reading files----------------------*/ 
  
  
  
  /*------------- Sorting method---------------------------*/
   int outsize = sort(iArray1, iArray1_size, iArray2, iArray2_size, outputArray);

   cout << "The sorted list of " << outsize << " numbers is: ";

   for (int j = 0; j < outsize; j++) {
      cout << outputArray[j] << " ";
   }
   
   
  
  /*-------Start of writing files---------------------*/
   cout << "\nEnter the output file name: ";
   cin >> outFile;
  
   
   writefile(outputArray, outsize, outFile);
   cout << "*** Please check the new file - " << outFile << " ***\n";
   cout << "*** Goodbye. ***\n";
   return 0;
}

