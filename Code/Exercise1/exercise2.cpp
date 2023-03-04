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

/////////////////////////////////////////////////

int Binary_str_to_Dec(string n){
  int p = 0;
  int dec = 0;
  for(int i = n.length() - 1; i > 0; i--){
    string tmp(1, n[i]);
    dec += stoi(tmp) * pow(2, p);
    p++;
  }

  string tmp_z(1, n[0]);
  dec += - stoi(tmp_z) * pow(2, p);
  return dec;
}

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

void Two_Comp_16_Bits(string& s){
  // Reverse 0 to 1 and 1 to 0
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '0'){
      s[i] = '1';
    } else {
      s[i] = '0';
    }
  }
  // cout << "After reverse: " << s << endl;

  // Convert to two
  string two = "0000000000000000";
  string add_one = "0000000000000001";
  int carry = 0;
  for(int i = s.length() - 1; i >= 0; i--){
    if(s[i] == '1' && add_one[i] == '1'){
      if(carry == 1){
        two[i] = '1';
        carry = 1;
      } else {
        two[i] = '0';
        carry = 1;
      }
    }
    if(s[i] == '0' && add_one[i] == '0'){
      if(carry == 0){
        two[i] = '0';
      } else {
        two[i] = '1';
        carry = 0;
      }
    }
    if((s[i] == '1' && add_one[i] == '0') || (s[i] == '0' && add_one[i] == '1')){
      if(carry == 0){
        two[i] = '1';
      } else {
        two[i] = '0';
        carry = 1;
      }
    }
  }
  s = two;
}

void Two_Comp_8_Bits(string& s){
  // Reverse 0 to 1 and 1 to 0
  for(int i = 0; i < s.length(); i++){
    if(s[i] == '0'){
      s[i] = '1';
    } else {
      s[i] = '0';
    }
  }
  // cout << "After reverse: " << s << endl;

  // Convert to two
  string two = "00000000";
  string add_one = "00000001";
  int carry = 0;
  for(int i = s.length() - 1; i >= 0; i--){
    if(s[i] == '1' && add_one[i] == '1'){
      if(carry == 1){
        two[i] = '1';
        carry = 1;
      } else {
        two[i] = '0';
        carry = 1;
      }
    }
    if(s[i] == '0' && add_one[i] == '0'){
      if(carry == 0){
        two[i] = '0';
      } else {
        two[i] = '1';
        carry = 0;
      }
    }
    if((s[i] == '1' && add_one[i] == '0') || (s[i] == '0' && add_one[i] == '1')){
      if(carry == 0){
        two[i] = '1';
      } else {
        two[i] = '0';
        carry = 1;
      }
    }
  }
  s = two;
}

void add(string num1, string num2){
  int n1 = Binary_str_to_Dec(num1);
  int n2 = Binary_str_to_Dec(num2);
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
  int overflow = 0;
  if(s1[0] == '1' && s2[0] == '1' && result[0] == '0') overflow = 1;
  if(s1[0] == '0' && s2[0] == '0' && result[0] == '1') overflow = 1;
  if(overflow == 0){
    cout << "Result of add " << num1 << " (" << n1 << ")" << " and " << num2 << " (" << n2 << ") is " << result << " (" << Binary_str_to_Dec(result) << ")" << endl;
  } else {
    cout << "Result of " << num1 << " + " << num2 << " (" << n1 << " + " << n2 << ") " << endl;
    cout << "OVERFLOW OVERFLOW" << endl;
  }
}

void subtract(string num1, string num2){
  int n1 = Binary_str_to_Dec(num1);
  int n2 = Binary_str_to_Dec(num2);
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

  int overflow = 0;
  if(s1[0] == '1' && s2[0] == '1' && result[0] == '0') overflow = 1;
  if(s1[0] == '0' && s2[0] == '0' && result[0] == '1') overflow = 1;
  if(overflow == 0){
    cout << "Result of " << num1 << " - " << num2 << " is " << result << " (" << n1 << " - " << -n2 << " = " << Binary_str_to_Dec(result) << " )" << endl;
  } else {
    cout << "Result of " << num1 << " - " << num2 << " (" << n1 << " - " << -n2 << ") " << endl;
    cout << "OVERFLOW OVERFLOW" << endl;
  }
}

void multiply(string str1, string str2){
  int num1 = Binary_str_to_Dec(str1);
  int num2 = Binary_str_to_Dec(str2);
  // Check negative
  int flag = 0;
  if(num1 < 0 && num2 > 0 || num1 > 0 && num2 < 0) flag = 1;
  int n1 = num1;
  int n2 = num2;
  if(num1 < 0) n1 = - num1;
  if(num2 < 0) n2 = - num2;

  string s1 = Dec_to_Bin(n1);
  string s2 = Dec_to_Bin(n2);

  convert_to_eight(s1);
  convert_to_eight(s2);

  // cout << "Number 1: " << s1 << endl;
  // cout << "Number 2: " << s2 << endl;

  // Init variables
  int k = s2.length();
  string c = "0";
  string a = "00000000";
  string result;

  // Algo
  while(k > 0){
    string re = c + a + s2;
    // cout << "First re: " << re << endl;

    if(re[re.length() - 1] == '1'){
      string temp = "00000000";  // init temp [C, A]
      string ca = a;
      // cout << "[C, A]: " << ca << endl;

      int carry = 0;
      for(int i = s1.length() - 1; i >= 0; i--){
        if(ca[i] == '1' && s1[i] == '1'){
          if(carry == 1){
            temp[i] = '1';
            carry = 1;
          } else {
            temp[i] = '0';
            carry = 1;
          }
        }
        if(ca[i] == '0' && s1[i] == '0'){
          if(carry == 0){
            temp[i] = '0';
          } else {
            temp[i] = '1';
            carry = 0;
          }
        }
        if((ca[i] == '1' && s1[i] == '0') || (ca[i] == '0' && s1[i] == '1')){
          if(carry == 0){
            temp[i] = '1';
          } else {
            temp[i] = '0';
            carry = 1;
          }
        }
      }
      if(carry == 1){
        temp[0] = '1';
      }
      a = temp;
    }
    re = c + a + s2;
    // cout << "Before shift right: " << re << endl;

    // Shift right
    string tmp = re.substr(0, re.length() - 1);
    c = "0";
    re = c + tmp;
    // cout << "After shift right: " << re << endl;
    // cout << endl;

    // Update C, A, Q (s2)
    c = re[0];
    a = re.substr(1, s1.length());
    s2 = re.substr(1 + s1.length(), s1.length());
    k--;
    result = re.substr(1, re.length() - 1);
  }
  if(flag == 1){
    Two_Comp_16_Bits(result);
  }
  cout << "Result of multiply " << str1 << "(" << num1 << ") and " << str2 << " (" << num2 << ") is: " << result  << " (" << Binary_str_to_Dec(result) << ")" << endl;
}

void divide(string str1, string str2){
  int num1 = Binary_str_to_Dec(str1);
  int num2 = Binary_str_to_Dec(str2);
  // Check negative
  int flag = 0;
  if(num1 < 0 && num2 > 0 || num1 > 0 && num2 < 0) flag = 1;
  int n1 = num1;
  int n2 = num2;
  if(num1 < 0) n1 = - num1;
  if(num2 < 0) n2 = - num2;

  string s1 = Dec_to_Bin(n1);
  string s2 = Dec_to_Bin(n2);

  convert_to_eight(s1);
  convert_to_eight(s2);

  // Init variables
  string a = "00000000";
  // if(num1 < 0){
  //   a = "11111111";
  // }
  int k = s1.length();
  string q = s1;
  string m = s2;
  string re = a + q;
  string m_s2 = m;
  Two_Comp_8_Bits(m_s2);
  // cout << "Q: " << q << endl;
  // cout << "M: " << m << endl;
  // cout << "M in two complements: " << m_s2 << endl;

  // Algo
  while(k > 0){
    // Shift right
    // cout << "M: " << m << endl;
    // cout << "Before shift left: " << a << " " << q << endl;
    // cout << "M in two complements: " << m_s2 << endl;
    a = a.substr(1, a.length() - 1) + q[0];
    q = q.substr(1, q.length() - 1) + '0';
    // cout << "After shift left: " << a << " " << q << endl;
    // cout << "A after shift left: " << a << endl;

    // Calculate A - M
    string old_a = a; // Save old a
    string re_subtract = "00000000";
    int carry = 0;

    for(int i = a.length() - 1; i >= 0; i--){
      if(a[i] == '1' && m_s2[i] == '1'){
        if(carry == 1){
          re_subtract[i] = '1';
          carry = 1;
        } else {
          re_subtract[i] = '0';
          carry = 1;
        }
      }
      if(a[i] == '0' && m_s2[i] == '0'){
        if(carry == 0){
          re_subtract[i] = '0';
        } else {
          re_subtract[i] = '1';
          carry = 0;
        }
      }
      if((a[i] == '1' && m_s2[i] == '0') || (a[i] == '0' && m_s2[i] == '1')){
        if(carry == 0){
          re_subtract[i] = '1';
        } else {
          re_subtract[i] = '0';
          carry = 1;
        }
      }
    }

    // cout << "Subtract result: " << re_subtract << endl;
    // Assign A = A - M
    a = re_subtract;
    
    // Calculate a in decimal
    int dec_a = Binary_str_to_Dec(a);
    if(dec_a < 0){
      a = old_a;
    } else {
      q[q.length() - 1] = '1';
    }

    // cout << "New a: " << a << endl;
    // cout << "----------------------------------------------------------------" << endl;

    k--;
  }

  // Check negative
  if(flag == 1){
    Two_Comp_8_Bits(q);
  }
  if (num1 < 0){
    Two_Comp_8_Bits(a);
  }
  cout << "Result of " << str1 <<  " / " << str2 << " (" << num1 << " / " << num2 << "): " << endl;
  cout << "Quotient (Thuong so): " << q << " (" << Binary_str_to_Dec(q) << ")" << endl;
  cout << "Remainder (So du:) " << a << " (" << Binary_str_to_Dec(a) << ")" << endl;
  cout << endl;
}

int main(){
  // Menu
  int flag = 0;
  while(true){
    cout << "Nhan 1: Tinh tong hai day bit" << endl;
    cout << "Nhan 2: Tinh hieu hai day bit" << endl;
    cout << "Nhan 3: Tinh tich hai day bit" << endl;
    cout << "Nhan 4: Tinh thuong hai day bit" << endl;
    cout << "Nhan 0: De thoat khoi chuong trinh" << endl;
    cout << "Nhap so: ";
    cin >> flag;
    cout << endl;
    string s1 = "";
    string s2 = "";
    if(flag == 1){
      cout << "Nhap so thu nhat duoi dang nhi phan: " << endl;
      cin >> s1;
      cout << "Nhap so thu hai dang nhi phan: " << endl;
      cin >> s2;
      add(s1, s2);
    }

    if(flag == 2){
      cout << "Nhap so thu nhat duoi dang nhi phan: " << endl;
      cin >> s1;
      cout << "Nhap so thu hai dang nhi phan: " << endl;
      cin >> s2;
      subtract(s1, s2);
    }
    
    if(flag == 3){
      cout << "Nhap so thu nhat duoi dang nhi phan: " << endl;
      cin >> s1;
      cout << "Nhap so thu hai dang nhi phan: " << endl;
      cin >> s2;
      multiply(s1, s2);
    }

    if(flag == 4){
      cout << "Nhap so thu nhat duoi dang nhi phan: " << endl;
      cin >> s1;
      cout << "Nhap so thu hai dang nhi phan: " << endl;
      cin >> s2;
      divide(s1, s2);
    }

    if(flag == 0){
      break;
    }
    cout << "----------------------------------------------------------------" << endl;
  }

  // add("11111001", "00000101");  // -7 + 5
  // add("11111100", "00000100"); // -4 + 4
  // add("00000011", "00000100"); // 3 + 4
  // add("11111100", "11111111"); // -4 + (-1)
  // add("00000101", "00000100"); // 5 + 4
  // add("11111001", "11111010"); // -7 + (-6)
  // add("01111111", "01111111"); // 127 + 127 OVERFLOW OVERFLOW

  // subtract("00000010", "00000111");  // 2 - 7
  // subtract("00000101", "00000010");  // 5 - 2
  // subtract("00000101", "11111110");  // 5 - (-2)
  // subtract("11111010", "11111100"); // -6 - (-4)
  // subtract("11111010", "00000100"); // -6 - 4
  // subtract("01111111", "10000001"); // 127 - (-127) OVERFLOW OVERFLOW

  // multiply("00000101", "00000110"); // 5*6
  // multiply("00000111", "11111101"); // 7*(-3)
  // multiply("11111100", "11111010"); // -4 * (-6)
  // multiply("11111011", "00000010"); // -5 * 2
  // multiply("00001011", "00001100"); // 11* 12
  // multiply("01111011", "01111110"); // 123 * 126

  // divide("00000111", "00000011"); //    7 / 3
  // divide("00000111", "11111101"); //    7 / (-3)
  // divide("11111001", "00000011"); //    -7 / 3
  // divide("11111001", "11111101"); //    -7 / (-3)
  // divide("00001000", "00000100"); //    8 / 4
  // divide("11111101", "00000101"); //    -3 / 5
  return 0;
}