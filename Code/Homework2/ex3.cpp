// Câu 3) a)
// Float 1.3e+20 convert to binary is:
// Sign: 0
// Exponent: 11000001
// Mantissa: 11000011000001110011001

// Cau 3) b)
// Số float nhỏ nhất là 2^-126
// Float 1.17549e-38 convert to binary is:
// Sign: 0
// Exponent: 00000001
// Mantissa: 00000000000000000000000

// Cau 3c)
// Trong chuẩn IEEE 754 cho số dấu phẩy động, có một số giá trị đặc biệt được gọi là "giá trị đặc biệt". Các giá trị đặc biệt này bao gồm số không, vô cùng, NaN, và các giá trị số dấu phẩy động bình thường.

// Nếu bit exponent (8 bit kế tiếp bit dấu) đều bằng 1 và toàn bộ bit mantissa (23 bit tiếp theo) đều bằng 0, thì đây là giá trị vô cùng (+infinity) hoặc âm vô cùng (-infinity), tùy thuộc vào bit dấu.

// Nếu bit exponent đều bằng 1 và bit mantissa không đều bằng 0, thì đây là một giá trị NaN.

// Vì vậy, trong hàm dumpFloat trên, để kiểm tra một số float có phải là vô cùng hay NaN, ta chỉ cần kiểm tra bit exponent và bit mantissa theo các quy tắc trên.

// Nếu bit exponent đều bằng 1 và toàn bộ bit mantissa đều bằng 0, đó là số vô cùng.
// Nếu bit exponent đều bằng 1 và bit mantissa không đều bằng 0, đó là số NaN.

// Số vô cùng dương: float x = std::numeric_limits<float>::infinity();
// Khi đưa số này vào hàm dumpFloat(&x) ta sẽ nhận được output tương tự như sau:

// vbnet
// Copy code
// Float inf convert to binary is:
// Sign: 0
// Exponent: 11111111
// Mantissa: 00000000000000000000000
// ---------------------------------------
// Số vô cùng âm: float x = -std::numeric_limits<float>::infinity();
// Khi đưa số này vào hàm dumpFloat(&x) ta sẽ nhận được output tương tự như sau:

// vbnet
// Copy code
// Float -inf convert to binary is:
// Sign: 1
// Exponent: 11111111
// Mantissa: 00000000000000000000000
// ---------------------------------------
// Số NaN: float x = std::numeric_limits<float>::quiet_NaN();
// Khi đưa số này vào hàm dumpFloat(&x) ta sẽ nhận được output tương tự như sau:

// vbnet
// Copy code
// Float nan convert to binary is:
// Sign: 0
// Exponent: 11111111
// Mantissa: 10000000000000000000000
// ---------------------------------------
// Lưu ý rằng giá trị mantissa của NaN không chỉ toàn bộ là 0 như với giá trị vô cùng. Thay vào đó, nó phải có ít nhất một bit là 1 để phân biệt với giá trị vô cùng. Trong ví dụ này, bit thứ 23 của mantissa là 1, do đó đó là một giá trị NaN hợp lệ.






// Các trường hợp sau đây sẽ tạo ra các số đặc biệt (special floating-point values) khi thực hiện các phép tính với số dấu phẩy động kiểu float:

// Số vô cùng (infinity): Nếu thực hiện phép chia mà mẫu (divisor) bằng 0 hoặc khi một số âm được chuyển đổi thành số dương vô cùng, thì kết quả của phép tính sẽ là số vô cùng. Ví dụ:
// css
// Copy code
// float a = 1.0 / 0.0;  // a sẽ có giá trị là infinity
// float b = -3.5;
// float c = b / 0;      // c sẽ có giá trị là infinity
// Số báo lỗi NaN (not-a-number): Nếu thực hiện các phép tính không hợp lệ hoặc kết quả không xác định, thì kết quả của phép tính sẽ là NaN. Ví dụ:
// scss
// Copy code
// float d = 0.0 / 0.0;  // d sẽ có giá trị là NaN
// float e = sqrt(-1);   // e sẽ có giá trị là NaN
// Phép tính với số vô cùng hoặc NaN:
// X – (+∞) hoặc (+∞) – (+∞): Kết quả sẽ là NaN nếu cả 2 số đều là số vô cùng, hoặc là số vô cùng có dấu phù hợp nếu chỉ có một số là số vô cùng.
// X/0 hoặc ∞/∞: Kết quả sẽ là NaN nếu số chia hoặc số bị chia là số vô cùng, hoặc là số vô cùng có dấu phù hợp nếu số chia bằng 0 và số bị chia khác 0.
// 0/0: Kết quả sẽ là NaN.
// sqrt(X) với X < 0: Kết quả sẽ là NaN nếu X là số âm.
// Ví dụ:

// scss
// Copy code
// float f = 5.0 / 0.0;      // f sẽ có giá trị là infinity
// float g = f - f;          // g sẽ có giá trị là NaN
// float h = sqrt(-2.0);     // h sẽ có giá trị là NaN
// float i = 0.0 / 0.0;      // i sẽ có giá trị là NaN
// float j = 1.0 / 0.0 + f;  // j sẽ có giá trị là infinity nếu f là số dương,
//                           // và NaN nếu f là số âm hoặc là NaN

// tiếp tục
// Tràn số (overflow): Nếu giá trị của một số vượt quá giới hạn tối đa mà kiểu dữ liệu float có thể biểu diễn, kết quả sẽ là số vô cùng. Ví dụ:
// bash
// Copy code
// float k = 3.4e38 * 2;    // k sẽ có giá trị là infinity vì tràn số
// float l = -3.4e38 * 2;   // l sẽ có giá trị là -infinity vì tràn số
// Số nhỏ dưới ngưỡng (underflow): Nếu giá trị của một số nhỏ hơn ngưỡng tối thiểu mà kiểu dữ liệu float có thể biểu diễn, kết quả sẽ là số 0. Ví dụ:
// css
// Copy code
// float m = 1.0e-40;       // m sẽ có giá trị là 0 vì số quá nhỏ dưới ngưỡng
// float n = 2.0e-45;       // n sẽ có giá trị là 0 vì số quá nhỏ dưới ngưỡng
// Các trường hợp này thường xảy ra khi tính toán số dấu phẩy động trong các thuật toán phức tạp hoặc khi giải quyết các bài toán về khoa học, kỹ thuật và toán học. Việc hiểu rõ cách các số đặc biệt này được tạo ra và cách xử lý chúng là rất quan trọng để đảm bảo tính toàn vẹn và chính xác của các phép tính số học.


// tiếp tục
// Số báo lỗi NaN (Not a Number): Số NaN được tạo ra khi một phép tính không thể được thực hiện hoặc kết quả của nó không xác định. Ví dụ:
// css
// Copy code
// float a = 0.0 / 0.0;    // a sẽ có giá trị NaN vì không thể chia 0 cho 0
// float b = sqrt(-1.0);   // b sẽ có giá trị NaN vì không thể lấy căn bậc hai của số âm
// Số vô cực (infinity): Số vô cực được tạo ra khi một phép tính cho kết quả là một giá trị vô cùng. Ví dụ:
// css
// Copy code
// float c = 1.0 / 0.0;    // c sẽ có giá trị infinity vì chia một số bất kỳ cho 0
// float d = -1.0 / 0.0;   // d sẽ có giá trị -infinity vì chia một số bất kỳ cho 0 với dấu âm
// Việc xử lý các số đặc biệt này cũng rất quan trọng trong tính toán số học. Chúng ta cần đảm bảo rằng các phép tính trả về kết quả hợp lệ và chính xác, và tránh các trường hợp phát sinh số NaN hoặc số vô cực không mong muốn.


// tiếp tục
// Phép tính chia cho 0: Khi chia một số bất kỳ cho 0, kết quả sẽ là số vô cùng hoặc số NaN, tùy thuộc vào dấu của số đó. Ví dụ:
// java
// Copy code
// float e = 1.0 / 0.0;    // e sẽ có giá trị infinity vì chia 1 cho 0
// float f = -1.0 / 0.0;   // f sẽ có giá trị -infinity vì chia -1 cho 0
// float g = 0.0 / 0.0;    // g sẽ có giá trị NaN vì chia 0 cho 0
// Phép tính căn bậc hai của số âm: Khi tính căn bậc hai của một số âm, kết quả sẽ là số NaN. Ví dụ:
// r
// Copy code
// float h = sqrt(-1.0);   // h sẽ có giá trị NaN vì không thể lấy căn bậc hai của số âm
// Phép tính logarit của số không hoặc số âm: Khi tính logarit tự nhiên của số không hoặc số âm, kết quả sẽ là số NaN. Ví dụ:
// css
// Copy code
// float i = log(0.0);     // i sẽ có giá trị NaN vì không thể tính logarit của số không
// float j = log(-1.0);    // j sẽ có giá trị NaN vì không thể tính logarit của số âm
// Các trường hợp này cũng thường xảy ra trong tính toán số học và rất quan trọng để hiểu và xử lý chúng để đảm bảo tính toàn vẹn và chính xác của các phép tính.