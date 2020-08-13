#include <iostream>
#include <iomanip>

/*************************************************************************************
*
* Author: Jacob Stockwell AU_ID: JTS0098 
* Date: Started 05/23/19 - Last modified 05/29/19
*  
* Description: This program is designed to tell the user how many months it will 
* take to pay off a loan 
*
* File Name: P1_JTS0098.cpp
*
* How to compile in terminal: g++ P1_JTS0098.cpp -o Proj1
*                 ./Proj1
*************************************************************************************/

using namespace std;

int main () {

   //user input variables
   double loanAmount;
   double interestRate;
   double monthlyPay;
   double displayRate;
   

   //varaibles for calculation 
   double convertedRate;
   int months = 0;
   double interestResult;
   double interestPaid = 0;
   double principal; 


   //user prompt 
   cout << "Loan amount:";
   cin >> loanAmount;
   
   cout << "Interest Rate (% per year): ";
   cin >> interestRate;
   
   cout << "Monthly payments: ";
   cin >> monthlyPay; 

   cout << endl; //spacing
   
 
   
   //rate conversion calculation
   convertedRate = (interestRate / 12) / 100; //for formula 
   
   displayRate = (interestRate / 12); // for output display only 
    
   
   
   //output formating title
   cout << "***************************************************************************" << endl;
   cout << "       Amortization Table                             " << endl;
   cout << "***************************************************************************" << endl;
   cout << "Month    balance        Payment      rate           Interest     Principal" << endl;
   cout << "0         $"<< loanAmount <<"           N/A         N/A              N/A           N/A   " << endl;
   
   
   
   //begining of while loop 
   while (loanAmount > 0)
   {
      
      interestResult = loanAmount * convertedRate; //interest on each payment calculation
      
      loanAmount = (loanAmount + interestResult) - monthlyPay; //payment for each month
      
      interestPaid = interestPaid + interestResult; //total interest paid calculation 
      
      principal = monthlyPay - interestResult; //principal calculation 
      
      
      //Special case 
      //Emailed TA to clarfify what was being asked in PDF
      if (monthlyPay < interestResult) {
         cout << endl;
         cout << " INVALID ENTRY: Interest is larger than monthly pay. Please re-enter information." << endl;
         break;
      } 
        
         
      //pays in full if amount is less than monthly pay  
      if (loanAmount <= monthlyPay){
         loanAmount = loanAmount - loanAmount;
      }
         
      months++;
      
      //list output 
      //to align looked up API for setW and setprecision on cplusplus.com
      //TA helped with $ placement
      cout << setw(10) << left << months 
           << "$" << setw(15) << left << setprecision(5) << loanAmount 
           << "$" << setw(11) << left << monthlyPay 
           << setw(15) << left << displayRate 
           << "$" << setw(15) << left << setprecision(4) << interestResult 
           << "$" << setw(15) << left << setprecision(4) << principal << endl;  
   }
   cout << "***************************************************************************" << endl;
   //---------------- end of while loop ------------------------------------------------
   
   //to add 1 month so month 0 is calculated in final result
   months++;
   
   //totals output 
   cout << endl;
   cout << "It takes " << months  << " months to pay off the loan." << endl;
   cout << "total interest paid is: $" << setprecision(5) << interestPaid << endl;
   
   return 0;
}