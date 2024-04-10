#include <cstdint>
#include <ostream>

#include "../include/KPolynomial.h"

std::ostream &operator<<(std::ostream &os, const MyClass &obj) {
  os << obj.getValue();
  return os;
}

template <typename T>
std::ostream &operator<<(std::ostream &os, const KPolynomial<T> &other) {
  bool flag = false;
  if (other.getLength() >= 2) {
    if (other.getLength() > 2) {
      if (other.getData(other.getLength() - 1) != 0) {
        os << other.getData(other.getLength() - 1) << "x^"
           << other.getLength() - 1;
        flag = true;
      }

      for (int_ i = other.getLength() - 2; i > 1; --i) {
        if (other.getData(i) != 0) {
          if (other.getData(i) > 0) {
            os << "+" << other.getData(i) << "x^" << i;
            flag = true;
          } else {
            os << other.getData(i) << "x^" << i;
            flag = true;
          }
        }
      }
    }

    if (other.getData(1) != 0) {
      if (other.getData(1) > 0) {
        os << "+" << other.getData(1) << "x";
        flag = true;
      } else {
        os << other.getData(1) << "x";
        flag = true;
      }
    }

    if (other.getData(0) != 0) {
      if (other.getData(0) > 0) {
        os << "+" << other.getData(0);
        flag = true;
      } else {
        os << other.getData(0);
        flag = true;
      }
    }
  } else if (other.getLength() == 1) {
    os << other.getData(0);
    flag = true;
  } else {
    os << "0";
  }

  if (!flag) {
    os << "0";
  }

  return os;
}

template <typename T>
int_ find1(const KPolynomial<T> &other, T value) {
  int_ result = 0;
  for (auto it = other.begin(); it != other.end(); ++it) {
    if (*it == value) {
      return result;
    }
    ++result;
  }
  return -1;
}

template <typename T>
int_ find2(const KPolynomial<T> &other, T value) {
  int_ result = 0;
  for (auto it = other.begin(); it.isNotEqual(other.end()); it.next()) {
    if (it.getValue() == value) {
      return result;
    }
    ++result;
  }
  return -1;
}