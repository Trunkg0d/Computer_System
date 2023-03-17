#include <iostream>
#include <bitset>
#include <math.h>
#include <limits>
using namespace std;

string dumpFloat(float *p) {
  string result = "";
  cout << "Float " << *p << " convert to binary is: " << endl;
  bitset<32> bits(*reinterpret_cast<unsigned int*>(p));
  cout << "Sign: " << bits[31] << endl;
  result += bits[31];
  cout << "Exponent: ";
  for (int i = 30; i >= 23; i--) {
      cout << bits[i];
      result += bits[i];
  }
  cout << endl;
  cout << "Mantissa: ";
  for (int i = 22; i >= 0; i--) {
      cout << bits[i];
      result += bits[i];
  }
  cout << endl;
  cout << "---------------------------------------" << endl;
  return result;
}

int main(){
  float p1 = 6;
  dumpFloat(&p1);
  float p2 = -12.625;
  dumpFloat(&p2);
  float p3 = 0.1015625;
  dumpFloat(&p3);
  float p4 = 0.1;
  dumpFloat(&p4);
  float p5 = 0;
  dumpFloat(&p5);


  float p6 = 1.3E+20;
  dumpFloat(&p6);
  float p7 = pow(2, -126);
  dumpFloat(&p7);

  float x = std::numeric_limits<float>::infinity();
  dumpFloat(&x);

  float y = -std::numeric_limits<float>::infinity();
  dumpFloat(&y);

  float z = std::numeric_limits<float>::quiet_NaN();
  dumpFloat(&z);
  return 0;
}