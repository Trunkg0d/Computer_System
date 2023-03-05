#include <iostream>
#include <string>
#include <math.h>
using namespace std;

int Abs(int n){
  if(n < 0){
    return -n;
  }
  return n;
}

void convert_to_eight(string& num){
// Check if the byte is full of 5 bits or not
  int re = 0;
  if(num.length() % 8 != 0){
    re = Abs(num.length() - 8);
  }

  while(re > 0){
    num = '0' + num;
    re--;
  }
}

string Dec_to_Bin(int n){  // He 10 -> He 2
  if(n == 0) return "0000";
  string tmp = "";
  string result = "";
  
  while(true){
    if(n == 0){
      break;
    } else {
      tmp += to_string(n % 2);
      n /= 2;
    }
  }

  for (int i = tmp.length() - 1; i >= 0; i--){
    result += tmp[i];
  }
  return result;
}

string Bin_to_Dec(int n){  // He 2 -> He 10
  int result = 0;
  int p = 0;

  while(n != 0){
    result += (n % 2) * pow(2, p);
    n /= 10;
    p += 1;
  }
  return to_string(result);
}

string Dec_to_Hex(int n){  // He 10 -> He 16
  string tmp = "";
  string result = "";
  
  while(true){
    if(n == 0){
      break;
    } else {
      int r = n % 16;
      if (r < 10){
        tmp += to_string(r);
      } else {
        if(r == 10){
          tmp += 'A';
        }
        if(r == 11){
          tmp += 'B';
        }
        if(r == 12){
          tmp += 'C';
        }
        if(r == 13){
          tmp += 'D';
        }
        if(r == 14){
          tmp += 'E';
        }
        if(r == 15){
          tmp += 'F';
        }
      }
      n /= 16;
    }
  }

  for (int i = tmp.length() - 1; i >= 0; i--){
    result += tmp[i];
  }
  return result;
}

string Hex_to_Dec(string s){  // He 16 -> He 10
  int result = 0;
  int p = 0;
  for(int i = s.length() - 1; i >= 0; i--){
    if(s[i] == 'A'){
      result += 10 * pow(16, p);
    } else if(s[i] == 'B'){
      result += 11 * pow(16, p);
    } else if(s[i] == 'C'){
      result += 12 * pow(16, p);
    } else if(s[i] == 'D'){
      result += 13 * pow(16, p);
    } else if(s[i] == 'E'){
      result += 14 * pow(16, p);
    } else if(s[i] == 'F'){
      result += 15 * pow(16, p);
    } else{
      string tmp(1, s[i]);
      result += stoi(tmp) * pow(16, p);
    }
    p += 1;
  }
  return to_string(result);
}

string Bin_to_Hex(int n){  // He 2 -> He 16
  string bin_str = to_string(n);
  convert_to_eight(bin_str);
  string tmp = Bin_to_Dec(n);
  string result = Dec_to_Hex(stoi(tmp));
  return result;
}

int main(){
  // Test case for Dec_to_Bin
  // cout << Dec_to_Bin(77) << endl;
  // cout << Dec_to_Bin(12) << endl;
  // cout << Dec_to_Bin(122) << endl;
  // cout << Dec_to_Bin(0) << endl;

  // Test case for Dec_to_Hex
  // cout << Dec_to_Hex(166) << endl;
  // cout << Dec_to_Hex(122) << endl;
  // cout << Dec_to_Hex(222) << endl;
  // cout << Dec_to_Hex(57) << endl;

  // Test case for Bin_to_Dec
  // cout << Bin_to_Dec(1001101) << endl;
  // cout << Bin_to_Dec(1100) << endl;
  // cout << Bin_to_Dec(1111010) << endl;
  // cout << Bin_to_Dec(0) << endl;
  // cout << Bin_to_Dec(11111111) << endl;

  // Test case for Hex_to_Dec
  // cout << Hex_to_Dec("A6") << endl;
  // cout << Hex_to_Dec("BB") << endl;
  // cout << Hex_to_Dec("157") << endl;
  // cout << Hex_to_Dec("153") << endl;
  // cout << Hex_to_Dec("9F") << endl;

  // Test case for Bin_to_Hex
  // cout << Bin_to_Hex(10100110) << endl;
  // cout << Bin_to_Hex(1) << endl;
  // cout << Bin_to_Hex(111111) << endl;
  // cout << Bin_to_Hex(110001) << endl;
  return 0;
}