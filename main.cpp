#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include "Add.h"

using namespace std;

void ClearScreen();
char Greeting();

int main(){
  Add a; //object declared of type Add
  string S_ENT1, S_ENT2;
  char answer;

  ClearScreen();
  answer = Greeting();
  //re-asks the user whether they would like to addition two other terms
  while(answer == 'Y'){
    ClearScreen();
    //when code reruns, re-asks user for addends instead of assuming same
    bool check = false;
    int sign = 1;
    while(!check){
      cout << "Enter sequence of first addend to compute: ";
      cin >> S_ENT1;
      cout << "Enter sequence of second addend to compute: ";
      cin >> S_ENT2;

      check = a.Check_Numeric(S_ENT1, S_ENT2); //checks that string is purely numeric, no alphanumerics or other operators
    }

    string TEMP_S_ENT1 = S_ENT1;
    string TEMP_S_ENT2 = S_ENT2;

    if(((S_ENT1[0] == '-') && (S_ENT2[0] != '-')) || ((S_ENT1[0] != '-') &&(S_ENT2[0] == '-'))){
      sign = a.Compare_String(S_ENT1, S_ENT2);
    }

    reverse(S_ENT1.begin(), S_ENT1.end()); //reverses string 1
    reverse(S_ENT2.begin(), S_ENT2.end()); //reverses string 2
    string S_ENT3 = a.Adder(S_ENT1, S_ENT2, sign);
    reverse(S_ENT3.begin(), S_ENT3.end()); //reverses string 3

    if(TEMP_S_ENT2[0] == '-'){
      TEMP_S_ENT2.erase(0,1);
      cout << TEMP_S_ENT1 << " - " << TEMP_S_ENT2 << " = " << S_ENT3 << endl;  
    } else cout << TEMP_S_ENT1 << " + " << TEMP_S_ENT2 << " = " << S_ENT3 << endl;
    cout << "Would you like to add two other values? (Y/N) ";
    cin >> answer;
    answer = toupper(answer);
    cout << endl;
  }

  cout << "Good bye!" << endl;

  return 0;
}

//Sends 100 newlines to the console, which is equivalent to UNIX command "clear"
//Used to show changes in matrix without stacking each display on top of one another
void ClearScreen(){
  for(int n = 0; n < 10; n++){
    std::cout << "\n\n\n\n\n\n\n\n\n\n";
  }
}

//Returns char to determine whether the user wants to play game
//Greets player and explains rules of the game
char Greeting(){
  //declaration and initialization of answer to ' '
  char answer = ' ';

  //explains the rules of Conway's Game of Life
  cout << "\t\t\t\t\t\t\t\t \"Welcome to the String Adder Calculator\"" << endl;
  cout << "Welcome to Trung and Faiza’s program to add two string inputs." << endl;
  cout << "You can enter any two integers, negative and/or positive, and the output will be the sum of those two  numbers." << endl;
  cout << "For example, if the first addend is 500 and the second addend is 1000, the sum is 1500." << endl;
  cout << "Similarly, if the first addend is -10 and the second addend is +1, the result is -9." << endl;
  cout << endl;

  //while loop to ensure player either selects Y or N, which determines whether they play or not
  while (answer != 'Y' && answer != 'N'){
    std::cout << "Would you like to calculate two numbers? (Y/N): ";
    std::cin >> answer;
    answer = toupper(answer); //capitalizes the char inputted by user
  }

  return answer;
}
