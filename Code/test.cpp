#include <iostream>
#include <string>
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

/////////////////////////////////////////////////

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

string convert_two_comp(int n){
  if(n > 0){
    string re = Dec_to_Bin(n);
    convert_to_eight(re);
    return re;
  }

  int n_new = -n;
  string one = Dec_to_Bin(n_new);
  convert_to_eight(one);
  // cout << "One complements: " << one << endl;

  // Reverse 0 to 1 and 1 to 0
  for(int i = 0; i < one.length(); i++){
    if(one[i] == '0'){
      one[i] = '1';
    } else {
      one[i] = '0';
    }
  }
  // cout << "After reverse: " << one << endl;

  // Convert to two
  string two = "00000000";
  string add_one = "00000001";
  int carry = 0;
  for(int i = one.length() - 1; i >= 0; i--){
    if(one[i] == '1' && add_one[i] == '1'){
      if(carry == 1){
        two[i] = '1';
        carry = 1;
      } else {
        two[i] = '0';
        carry = 1;
      }
    }
    if(one[i] == '0' && add_one[i] == '0'){
      if(carry == 0){
        two[i] = '0';
      } else {
        two[i] = '1';
        carry = 0;
      }
    }
    if((one[i] == '1' && add_one[i] == '0') || (one[i] == '0' && add_one[i] == '1')){
      if(carry == 0){
        two[i] = '1';
      } else {
        two[i] = '0';
        carry = 1;
      }
    }
  }
  // cout << "Two complements: " << two << endl;
  return two;
}

void add(int n1, int n2){
  string s1 = convert_two_comp(n1);
  string s2 = convert_two_comp(n2);

  string result = "00000000";
  int carry = 0;
  for(int i = s1.length() - 1; i >= 0; i--){
    if(s1[i] == '1' && s2[i] == '1'){
      if(carry == 1){
        result[i] = '1';
        carry = 1;
      } else {
        result[i] = '0';
        carry = 1;
      }
    }
    if(s1[i] == '0' && s2[i] == '0'){
      if(carry == 0){
        result[i] = '0';
      } else {
        result[i] = '1';
        carry = 0;
      }
    }
    if((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1')){
      if(carry == 0){
        result[i] = '1';
      } else {
        result[i] = '0';
        carry = 1;
      }
    }
  }
  cout << "Result of add " << n1 << " and " << n2 << ": " << result << endl;
}

void subtract(int n1, int n2){
  n2 = -n2;
  string s1 = convert_two_comp(n1);
  string s2 = convert_two_comp(n2);

  string result = "00000000";
  int carry = 0;
  for(int i = s1.length() - 1; i >= 0; i--){
    if(s1[i] == '1' && s2[i] == '1'){
      if(carry == 1){
        result[i] = '1';
        carry = 1;
      } else {
        result[i] = '0';
        carry = 1;
      }
    }
    if(s1[i] == '0' && s2[i] == '0'){
      if(carry == 0){
        result[i] = '0';
      } else {
        result[i] = '1';
        carry = 0;
      }
    }
    if((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1')){
      if(carry == 0){
        result[i] = '1';
      } else {
        result[i] = '0';
        carry = 1;
      }
    }
  }
  cout << "Result of subtract " << n1 << " - " << -n2 << "= " << result << endl;
}

int main(){
  // add(-7, 5);
  // add(-4, 4);
  // add(3, 4);
  // add(-4, -1);
  // add(5, 4);
  // add(-7, -6);

  // subtract(2, 7);
  // subtract(-5, 2);
  // subtract(5, 2);

  add(79, 29);

  subtract(89, 98);
  subtract(-80, 48);
  return 0;
}