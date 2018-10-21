#ifndef ADD_H
#define ADD_H

#include<string>

using namespace std;

class Add{
public:
  bool Check_Numeric(string str1, string str2);
  int Compare_String(string& str1, string& str2);
  string Adder(string str1, string str2, int sign);
private:
  int a;
};

#endif
