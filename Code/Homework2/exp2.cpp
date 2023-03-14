#include <iostream>
using namespace std;

void forceFloat(float *result, const string& input) {
  // Interpret the binary representation of the input string as a 32-bit integer.
  int bin = 0;
  for (int i = 0; i < 32 && i < input.length(); i++) {
    if (input[i] == '1') {
      bin |= 1 << (31 - i);
    }
  }
  // Interpret the 32-bit integer as a floating-point number.
  *result = *reinterpret_cast<float*>(&bin);
}

int main(){
  float x;
  forceFloat(&x, "01000100001101100001000000000000");  // 728.25
  cout << x << endl;
  forceFloat(&x, "10100011001101011000000000000000");  // -9.83913e-18
  cout << x << endl;
  forceFloat(&x, "00111101110011001100110011001101");  // 0.1
  cout << x << endl;
  forceFloat(&x, "01111111100000000000000000000000");  // +inf
  cout << x << endl;
  forceFloat(&x, "01111111110000000000000000000000");  // NaN
  cout << x << endl;
  return 0;
}