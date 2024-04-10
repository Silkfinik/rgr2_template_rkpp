#include "../src/funcs.cpp"
#include "KPolynomial.h"

int main() {
  // KPolynomial<double> a(4);
  // a.setElem(0, 1.5);
  // a.setElem(1, -4);
  // a.setElem(2, 4);
  // a.setElem(3, -8);
  // KPolynomial<double> b(2);
  // b.setElem(0, 1);
  // b.setElem(1, 2);
  // std::cout << b.Degree() << std::endl;

  // std::cout << a << std::endl;
  // std::cout << find2<double>(a, -8) << std::endl;
  // std::cout << b << std::endl;
  // std::cout << std::endl;

  // KPolynomial c = a * b;
  // std::cout << c << std::endl;

  // a *= b;
  // std::cout << a << std::endl;

  // std::cout << a.Count() << std::endl;

  // std::cout << "\n\n";

  MyClass temp1(-1);
  MyClass temp2(2);
  MyClass temp3(-5);
  KPolynomial<MyClass> d(3);
  d.setElem(0, temp1);
  d.setElem(1, temp2);
  d.setElem(2, temp3);

  KPolynomial<MyClass> e(3);
  e.setElem(0, temp3);
  e.setElem(1, temp2);
  e.setElem(2, temp1);

  std::cout << "d polynomial: " << d << '\n';
  std::cout << "e polynomial: " << e << '\n';

  d *= e;

  std::cout << d << '\n';

  MyClass temp_find(-12);

  std::cout << "Index " << temp_find.getValue()
            << " element: " << find1<MyClass>(d, temp_find) << '\n';

  return 0;
}