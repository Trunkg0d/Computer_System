#include <iostream>
#include <string>
#include <math.h>
using namespace std;

string Dec_to_Bin(int n){  // He 10 -> He 2
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

string Hex_to_Bin(string s){  // He 16 -> He 10
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
  string tmp = Bin_to_Dec(n);
  string result = Dec_to_Hex(stoi(tmp));
  return result;
}

int main(){
  cout << Dec_to_Bin(77) << endl;
  cout << Bin_to_Dec(1001101) << endl;
  cout << Dec_to_Hex(166) << endl;
  cout << Hex_to_Bin("A6") << endl;
  cout << Bin_to_Hex(10100110) << endl;
  return 0;
}