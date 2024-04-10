#ifndef KPOLYNOMIAL_H
#define KPOLYNOMIAL_H

#include <cstdint>
#include <iostream>
#include <stdexcept>

typedef std::int16_t int_;

template <class T>
class KPolynomial {
 private:
  int_ length;
  T* data;

 public:
  KPolynomial(int_ length_);

  ~KPolynomial() { delete[] data; }

  void setElem(int_ index, T data_);

  int_ getLength() const { return length; }
  T getData(int_ index) const { return data[index]; }

  int_ Degree() const;
  int_ Count() const;
  void Clear();

  KPolynomial& operator=(const KPolynomial& other);

  KPolynomial& operator+(const KPolynomial& other);
  KPolynomial& operator+=(const KPolynomial& other);

  KPolynomial operator*(const KPolynomial& other);
  KPolynomial& operator*=(const KPolynomial& other);

  class myItr {
   private:
    int_ index;
    const KPolynomial& pol;

   public:
    myItr(const int_& index, const KPolynomial& pol_)
        : index(index), pol(pol_) {}

    T operator*() const { return pol.getData(index); }
    void operator++() { ++index; }
    bool operator!=(const myItr& other) const { return index != other.index; }

    T getValue() const { return pol.getData(index); }
    void next() { ++index; }
    bool isNotEqual(const myItr& other) const { return index != other.index; }
  };

  myItr begin() const { return myItr(0, *this); }
  myItr end() const { return myItr(length, *this); }
};

/***********************************************************************\
*                                methods                                *
\***********************************************************************/

template <typename T>
void KPolynomial<T>::setElem(int_ index, T data_) {
  try {
    if (index < 0 || index >= length) {
      throw std::out_of_range("Invalid index");
    } else {
      data[index] = data_;
    }
  } catch (std::out_of_range& err) {
    std::cerr << err.what() << std::endl;
  }
}

template <typename T>
KPolynomial<T>::KPolynomial(int_ length_) : length(length_) {
  try {
    if (length <= 0) {
      throw std::length_error("Invalid length");
    } else {
      data = new T[length];
    }
  } catch (std::length_error& err) {
    std::cerr << err.what() << std::endl;
  }
}

template <typename T>
int_ KPolynomial<T>::Degree() const {
  for (int_ i = length - 1; i >= 0; --i) {
    if (data[i] != 0) {
      return i;
    }
  }

  return 0;
}

template <typename T>
int_ KPolynomial<T>::Count() const {
  int_ count = 0;
  for (int_ i = 0; i < length; ++i) {
    if (data[i] != 0) {
      ++count;
    }
  }

  return count;
}

template <typename T>
void KPolynomial<T>::Clear() {
  for (int_ i = 0; i < length; ++i) {
    data[i] = 0;
  }
}

template <typename T>
KPolynomial<T>& KPolynomial<T>::operator=(const KPolynomial<T>& other) {
  if (this != &other) {
    delete[] data;
    length = other.getLength();
    data = new T[length];
    for (int_ i = 0; i < length; ++i) {
      data[i] = other.getData(i);
    }
  }

  return *this;
}

template <typename T>
KPolynomial<T>& KPolynomial<T>::operator+(const KPolynomial<T>& other) {
  int_ maxlength = length;
  if (other.getLength() > length) {
    maxlength = other.getLength();
  }
  KPolynomial* result = new KPolynomial(maxlength);
  for (int_ i = 0; i < maxlength; ++i) {
    result->setElem(i, data[i] + other.getData(i));
  }

  return *result;
}

template <typename T>
KPolynomial<T>& KPolynomial<T>::operator+=(const KPolynomial<T>& other) {
  int_ maxlength = length;
  if (other.getLength() > length) {
    maxlength = other.getLength();
  }
  for (int_ i = 0; i < maxlength; ++i) {
    data[i] += other.getData(i);
  }

  return *this;
}

template <typename T>
KPolynomial<T> KPolynomial<T>::operator*(const KPolynomial<T>& other) {
  int_ maxlength = this->Degree() + other.Degree();
  KPolynomial<T> result(maxlength + 1);

  for (int_ i = 0; i <= this->Degree(); ++i) {
    for (int_ j = 0; j <= other.Degree(); ++j) {
      result.setElem(i + j, result.getData(i + j) + data[i] * other.getData(j));
    }
  }

  return result;
}

template <typename T>
KPolynomial<T>& KPolynomial<T>::operator*=(const KPolynomial<T>& other) {
  int_ maxlength = this->Degree() + other.Degree();
  KPolynomial<T> result(maxlength + 1);

  for (int_ i = 0; i <= this->Degree(); ++i) {
    for (int_ j = 0; j <= other.Degree(); ++j) {
      result.setElem(i + j, result.getData(i + j) + data[i] * other.getData(j));
    }
  }

  *this = result;

  return *this;
}

/***********************************************************************\
*                                MyClass                                *
\***********************************************************************/

class MyClass {
 private:
  int_ value;

 public:
  MyClass() : value(0) {}
  explicit MyClass(int value_) : value(value_) {}

  int_ getValue() const { return value; }
  void setValue(int value_) { value = value_; }

  bool operator>(int_ val) const { return value > val; }
  bool operator<(int_ val) const { return value < val; }
  bool operator>=(int_ val) const { return value >= val; }
  bool operator<=(int_ val) const { return value <= val; }
  bool operator==(int_ val) const { return value == val; }
  bool operator==(const MyClass& other) { return value == other.value; }
  bool operator!=(int_ val) const { return value != val; }

  MyClass operator+(const MyClass& other) const {
    return MyClass(value + other.value);
  }
  MyClass operator-(const MyClass& other) const {
    return MyClass(value - other.value);
  }
  MyClass operator*(const MyClass& other) const {
    return MyClass(value * other.value);
  }
  MyClass operator/(const MyClass& other) const {
    return MyClass(value / other.value);
  }
  MyClass operator%(const MyClass& other) const {
    return MyClass(value % other.value);
  }
};

#endif  // KPOLYNOMIAL_H