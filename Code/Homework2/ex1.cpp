#include<iostream>
#include<string>
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
  if(n == 0) return "0";
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

int get_Natural(float *p){
    return (int)*p;
}

float get_Decimal(float *p){
  return *p - (int)*p;
}

void dumpFloat(float *p){
  if(*p != 0){
    // Check negative number: flag = 1: p < 0;
    int flag = 0;
    if(*p < 0){
      flag = 1;
      *p = -*p;
    }

    int natural = get_Natural(&*p);
    string str_na = Dec_to_Bin(natural);
    float decimal = get_Decimal(&*p);
    string str_dec = "";
    while(true){
      decimal = decimal * 2;
      str_dec += to_string(get_Natural(&decimal));
      // cout << "Float: " << decimal << endl;
      // cout << "Decimal part: " << decimal << endl;
      // cout << "String dec: " << str_dec << endl;
      if(get_Decimal(&decimal) == (float)0){
        break;
      }
      decimal = get_Decimal(&decimal);
    }
    // cout << "Result: " << str_na + '.' + str_dec << endl;

    int b_position = str_na.length();
    int a_position = 0;
    string temp1 = str_na + str_dec;

    for(int i = 0; i < temp1.length(); i++){
      if(temp1[i] == '1'){
        a_position = i + 1;
        break;
      }
    }

    int power = 0;
    power = b_position - a_position;
    string temp2 = "1." + temp1.substr(a_position, temp1.length() - a_position + 1);
    // cout << "Before position: " << b_position << endl;
    // cout << "After position: " << a_position << endl;
    // if(flag == 1) cout << "After transform: -" << temp2 + " * 2^" << power << endl;
    // if(flag == 0) cout << "After transform: " << temp2 + " * 2^" << power << endl;

    // Fill bit
    string S = "";
    if(flag == 1){
      S += '1';
    } else {
      S += '0';
    }

    string Exp = "";
    int plus_power = power + 127;
    Exp += Dec_to_Bin(plus_power);
    convert_to_eight(Exp);

    string Significand = temp1.substr(a_position, temp1.length() - a_position + 1);
    while(Significand.length() < 23){
      Significand += '0';
    }

    cout << "So cham dong: " << *p << " -> Dang nhi phan tuong ung: " << S << " " << Exp << " " << Significand << endl;
    cout << "-------------------------------" << endl;
  } else {
    string S = "0";
    string Exp = "00000000";
    string Significand = "00000000000000000000000";

    cout << "So cham dong: " << *p << " -> Dang nhi phan tuong ung: " << S << " " << Exp << " " << Significand << endl;
    cout << "-------------------------------" << endl;
  }
}

int main(){
  float p = 12.625;
  dumpFloat(&p);
  float p1 = -5.25;
  dumpFloat(&p1);
  float p2 = -0.09375;
  dumpFloat(&p2);
  float p3 = 0.1015625;
  dumpFloat(&p3);
  float p4 = 0.1;
  dumpFloat(&p4);
  float p5 = 6;
  dumpFloat(&p5);
  float p6 = 0;
  dumpFloat(&p6);
  return 0;
  float p7 = 1.3e+20;
  dumpFloat(&p7);
}

// Test case:
// 0.1: 0 01111011 10011001100110011001101
//      0 01111011 10011001100110011001101
// 0.1015625: 0 01111011 10100000000000000000000
//            0 01111011 10100000000000000000000
// 6: 0 10000001 10000000000000000000000
//    0 10000001 10000000000000000000000