#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include "Add.h"

using namespace std;

int main(){
  Add a; //object declared of type Add
  string S_ENT1, S_ENT2;
  char answer = 'Y';
  int sign = 1;

  //re-asks the user whether they would like to addition two other terms
  while(answer == 'Y'){
    //when code reruns, re-asks user for addends instead of assuming same
    bool check = false;
    while(!check){
      cout << "Enter sequence of first addend to compute: ";
      cin >> S_ENT1;
      cout << "Enter sequence of second addend to compute: ";
      cin >> S_ENT2;

      check = a.Check_Numeric(S_ENT1, S_ENT2); //checks that string is purely numeric, no alphanumerics or other operators
    }

    if(((S_ENT1[0] == '-') && (S_ENT2[0] != '-')) || ((S_ENT1[0] != '-') &&(S_ENT2[0] == '-'))){
      sign = a.Compare_String(S_ENT1, S_ENT2);
    }

    reverse(S_ENT1.begin(), S_ENT1.end()); //reverses string 1
    reverse(S_ENT2.begin(), S_ENT2.end()); //reverses string 2
    string S_ENT3 = a.Adder(S_ENT1, S_ENT2, sign);
    reverse(S_ENT3.begin(), S_ENT3.end()); //reverses string 3

    cout << "The sum of the first and second addend is " << S_ENT3 << endl;
    cout << "Would you like to add two other values? (Y/N) ";
    cin >> answer;
    answer = toupper(answer);
  }

  return 0;
}
