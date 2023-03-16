#include <iostream>
using namespace std;

int main(){
  // Chuyen doi float -> int -> float
  float f = 3.14;
  int i = static_cast<int>(f);  // Chuyển từ float sang int
  float f2 = static_cast<float>(i);  // Chuyển từ int sang float
  cout << "Float ban dau: " << f << endl;
  cout << "Sau khi chuyen sang int va tro lai float: " << f2 << endl;
  cout << "----------------------------------------------------------" << endl;


  // Chuyen doi in -> float -> int
  int j = 42;
  float k = static_cast<float>(j);  // Chuyển từ int sang float
  int j2 = static_cast<int>(k);  // Chuyển từ float sang int
  cout << "Int ban dau: " << j << endl;
  cout << "Sau khi chuyen sang float va tro lai int: " << j2 << endl;
  cout << "----------------------------------------------------------" << endl;

  // Phép cộng số chấm động có tính kết hợp ? (x+y)+z = x+(y+z).
  float x = 3.14;
  float y = 1.23;
  float z = 0.98;

  float res1 = (x + y) + z;
  float res2 = x + (y + z);

  cout << "(x+y)+z = " << res1 << endl;
  cout << "x+(y+z) = " << res2 << endl;

  if (res1 == res2) {
    cout << "The addition of floating-point numbers is associative!" << endl;
  } else {
    cout << "The addition of floating-point numbers is not associative!" << endl;
  }
  cout << "----------------------------------------------------------" << endl;


  // Voi i la bien kieu int, f la bien kieu float
  i = 3;
  f= 3.14;

  i = (int) (3.14159 * f);
  cout << i << endl;

  f = f + (float) i;
  cout << f << endl;

  if(i == (int)((float) i)) cout << "Statement 6 is true" << endl;

  if (i == (int)((double) i)) cout << "Statement 7 is true" << endl; 

  if (f == (float)((int) f)) cout << "Statement 8 is true" << endl;

  if (f == (double)((int) f)) cout << "Statement 9 is true" << endl;

  return 0;
}


// Chuyển đổi float -> int -> float. Kết quả có thể khác so với ban đầu.
// Trong trường hợp này, ta muốn chuyển đổi một số kiểu float sang kiểu int và sau đó chuyển ngược trở lại kiểu float. Việc chuyển đổi từ float sang int sẽ làm mất thông tin phần thập phân của số ban đầu. Sau đó, khi ta chuyển đổi lại từ kiểu int sang kiểu float, số đó sẽ được làm tròn lại với phần thập phân bị mất. Do đó, kết quả có thể khác so với số ban đầu.

// Dưới đây là một ví dụ minh họa:

// c++
// Copy code
// #include <iostream>

// int main() {
  // float f = 3.14;
  // int i = static_cast<int>(f);  // Chuyển từ float sang int
  // float f2 = static_cast<float>(i);  // Chuyển từ int sang float
  // cout << "Float ban dau: " << f << endl;
  // cout << "Sau khi chuyen sang int va tro lai float: " << f2 << endl;
//   return 0;
// }
// Kết quả chạy chương trình có thể là:

// sql
// Copy code
// Float ban dau: 3.14
// Sau khi chuyen sang int va tro lai float: 3
// Như vậy, kết quả sau khi chuyển đổi trở lại kiểu float là 3, thay vì 3.14.

// Chuyển đổi int -> float -> int. Kết quả giống nhau so với ban đầu.
// Trong trường hợp này, ta muốn chuyển đổi một số kiểu int sang kiểu float và sau đó chuyển ngược trở lại kiểu int. Việc chuyển đổi từ kiểu int sang kiểu float không làm mất thông tin nào của số ban đầu, vì kiểu float có độ chính xác cao hơn so với kiểu int. Sau đó, khi ta chuyển đổi lại từ kiểu float sang kiểu int, số đó sẽ được làm tròn lại về kiểu int, nhưng sẽ giữ nguyên giá trị chính xác của số ban đầu.

// Dưới đây là một ví dụ minh họa:

// c++
// Copy code
// #include <iostream>

// int main() {
  // int i = 42;
  // float f = static_cast<float>(i);  // Chuyển từ int sang float
  // int i2 = static_cast<int>(f);  // Chuyển từ float sang int
  // cout << "Int ban dau: " << i << endl;
  // cout << "Sau khi chuyen sang float va tro lai int: " << i2 << endl;
//   return 0;
// }

// i = (int) (3.14159 * f);: Chuyển đổi giá trị số thực 3.14159 * f sang kiểu số nguyên và lưu vào biến i. Kết quả sẽ bị cắt đi phần thập phân và chỉ giữ lại phần nguyên. Ví dụ: nếu f = 2.5 thì kết quả của biểu thức sẽ là 7.

// f = f + (float) i;: Chuyển đổi giá trị số nguyên i sang kiểu số thực và cộng vào biến f. Sau đó, giá trị của biến f sẽ được cập nhật với kết quả của phép cộng này.

// if (i == (int)((float) i)) { printf(“true”); }: Ép kiểu giá trị của biến i sang kiểu số thực và rồi lại chuyển đổi ngược trở lại kiểu số nguyên. Nếu giá trị của biến i không bị thay đổi sau khi thực hiện phép ép kiểu này, tức là không mất mát dữ liệu, thì sẽ in ra chuỗi "true".

// if (i == (int)((double) i)) { printf(“true”); }: Ép kiểu giá trị của biến i sang kiểu số thực lớn hơn (double) và rồi lại chuyển đổi ngược trở lại kiểu số nguyên. Vì kiểu double có độ chính xác cao hơn so với kiểu float, nên phép ép kiểu này có thể dẫn đến mất mát dữ liệu. Nếu giá trị của biến i không bị thay đổi sau khi thực hiện phép ép kiểu này, tức là không mất mát dữ liệu, thì sẽ in ra chuỗi "true".

// if (f == (float)((int) f)) { printf(“true”); }: Ép kiểu giá trị của biến f sang kiểu số nguyên và rồi lại chuyển đổi ngược trở lại kiểu số thực. Nếu giá trị của biến f không bị thay đổi sau khi thực hiện phép ép kiểu này, tức là không mất mát dữ liệu, thì sẽ in ra chuỗi "true".

// if (f == (double)((int) f)) { printf(“true”); }: Ép kiểu giá trị của biến f sang kiểu số nguyên và rồi lại chuyển đổi ngược trở lại kiểu số thực lớn hơn (double). Vì kiểu double có độ chính xác cao hơn so với kiểu float, nên phép ép kiểu này có thể dẫ