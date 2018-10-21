#include<cstdlib>
#include<iostream>
#include<cmath>
#include<string>
#include<algorithm>
#include "Add.h"

using namespace std;

//Loops through each index of the string and constrains the string to only numerical values. Returns true if it does, returns false if it doesn't
//@param str1: string of first addend that holds numeric values
//@param str2: string of second addend that holds numeric values
bool Add::Check_Numeric(string str1, string str2){
  //find_first_not_of finds the first value in an index of the string that does not match the specified argument
  //some conditionals checks to see whether the first index of the string has "-" meaning it's negative thus, the argument begins at the second index of that string instead of the first index
  //returns npos if invalid values are passed
  char c1 = str1[0];
  char c2 = str2[0];
  if ((c1 == '-') && (c2 != '-')) return ((str1.find_first_not_of("0123456789", 1) == string::npos) && (str2.find_first_not_of("0123456789") == string::npos));
  else if ((c2 == '-') &&  (c1 != '-')) return ((str1.find_first_not_of("0123456789") == string::npos) && (str2.find_first_not_of("0123456789", 1) == string::npos));
  else if ((c1 == '-') && (c2 == '-')) return ((str1.find_first_not_of("0123456789", 1) == string::npos) && (str2.find_first_not_of("0123456789", 1) == string::npos));
  else return ((str1.find_first_not_of("0123456789") == string::npos) && (str2.find_first_not_of("0123456789") == string::npos));
}

//Accounts for the summation of two integer, one of which is positive, another which is negative
//Checks to see which integer is greater; returns the sign (positive/negative) of which integer is greater
//@param str1: string of first addend that holds numeric values
//@param str2: string of second addend that holds numeric values
int Add::Compare_String(string& str1, string& str2){
  bool neg1 = false;
  bool neg2 = false;
  string OG1 = str1;
  string OG2 = str2;

  //checks to see which of the two strings is negative and erases it
  if(str1[0] == '-'){
    str1.erase(0,1);
    neg1 = true;
  } else if(str2[0] == '-'){
    str2.erase(0,1);
    neg2 = true;
  }

  int temp1 = stoi(str1);
  int temp2 = stoi(str2);

  //multi-conditional that takes the lower integer and applies the negative sign on it
  if(temp1 == temp2){
    str1 = OG1;
    str2 = OG2;
    return 1;
  }
  else if((temp1 > temp2) && (neg1)){
    temp2 *= -1;
    str1 = to_string(temp1);
    str2 = to_string(temp2);
    return -1;
  }else if((temp1 > temp2) && (neg2)){
    temp2 *= -1;
    str1 = to_string(temp1);
    str2 = to_string(temp2);
    return 1;
  }else if ((temp1 < temp2) && (neg2)){
    temp1 *= -1;
    str1 = to_string(temp1);
    str2 = to_string(temp2);
    return -1;
  }else if ((temp1 < temp2) && (neg1)){
    temp1 *= -1;
    str1 = to_string(temp1);
    str2 = to_string(temp2);
    return 1;
  }

  return 1;
}

//Returns a string that holds the sum of the str1 and str2. Str1 and str2 are casted to integers and then assigned to a new variable, which is casted to a string and concatenated to the new string.
//@param str1: string of first addend that holds numeric values
//@param str2: string of second addend that holds numeric values
string Add::Adder(string str1, string str2, int sign){
  int addend1, addend2, addend3, remainder = 0, neg_remainder = 0;
  string s1, s2, str3 = "";
  int i = 0;
  char c1 = str1[str1.size() - 1];
  char c2 = str2[str2.size() - 1];
  int str1sign = 1;
  int str2sign = 1;

  //deletes the negative sign from those strings that are negative
  if((str1[str1.size() - 1] == '-') && (str2[str2.size() - 1] == '-')){
    str1.pop_back(); //deletes last value of string
    str2.pop_back(); //deletes last value of string
  } else if ((str1[str1.size() - 1] == '-') && (str2[str2.size() - 1] != '-')){
    str1sign = -1;
    str1.pop_back();
  } else if ((str1[str1.size() - 1] != '-') && (str2[str2.size() - 1] == '-')){
    str2sign = -1;
    str2.pop_back();
  }

  //makes the size of both strings equivalent, so cast from string to int and addition won't create an error
  if (str1.size() > str2.size()){
    for(int i = str2.size(); i < str1.size(); i++) str2 += "0";
  } else if (str1.size() < str2.size()){
    for(int i = str1.size(); i < str2.size(); i++) str1 += "0";
  }

  //for loop that appends and casts the summation of each index of the strings to a new string
  for(i = 0; i < str1.size(); i++){
    s1 = str1[i]; // s1 refers to value of index of str1
    s2 = str2[i]; // s2 refers to value of index of str2
    addend1 = str1sign*stoi(s1); //casts the string to an int and assigns it to a variable
    addend2 = str2sign*stoi(s2); //casts the string to an int and assigns it to a variable
    addend3 = addend1 + addend2; //adds the two integers and assigns it to new variable

    //conditional to account for subtraction with regrouping("borrowing")
    //if a value did borrow from the following number, then the number will decrement by 1
    if(neg_remainder > 0){
      addend3 -= neg_remainder;
      neg_remainder = 0;
    }

    //conditional to check if the remainder is greater than 0
    //if there is a remainder then the remainder will be added to addend3,
    //which is the summation of the two values of the indexes of strings
    //remainder is then assigned 0
    if(remainder > 0){
      addend3 += remainder;
      remainder = 0;
    }

    //conditional to check if addend3 is greater than 3 meaning there will be a remainder
    //ensures that addend3 will be a single digit integer instead of double digit
    //assigns the value of 1 to remainder if greater than 9
    //assigns the module of addend which removes the tens place of the integer leaving only the ones place
    if(addend3 > 9){
      remainder = 1;
      addend3 = addend3 % 10;
    }

    //conditional to account for regrouping("borrowing")
    //if the negative value is not in the first index,
    //a remainder(neg_remainder) is incremented to ensure that this value is deduced from the next iteration
    //the value is then added by 10 to make it positive
    if(addend3 < 0){
      neg_remainder = 1;
      addend3 += 10;
    }

    //appends the value of addend3 to str3
    str3 += to_string(addend3);
  }

  //if the remainder is still greater than one meaning that the last values summed to a number greater than 9,
  //then concatenate 1 to the string i.e. "500 + 500" = "1000"
  //without this the output would be "000"
  if(remainder > 0) str3 += "1";

  i = str3.size() -1;
  //in the case of remainders, the last index could be used to borrow thus,
  //possibly making the value 0; if it is zero, then it will be removed from the final product
  while(str3[i] == '0'){
    str3.pop_back();
    i--;
  }

  //if both values were originally negative, which was stored in c1 and c2 before the pop_back
  //then the summation string will have "-" appended to it
  //however, if sign was returned -1 since one of the values was negative, then "-" will be appended to it
  if((c1 == '-') && (c2 == '-')) str3 += "-";
  else if (sign == -1) str3 += "-";

  //if string3 does not have any values contained inside or just "-",
  //then overwrite the value with "0"
  //previous conditionals delete any values of 0 to ensure str3 would not have unnecessary 0's
  if(str3 == "-" || str3 == "") str3 = "0";

  return str3;
}
