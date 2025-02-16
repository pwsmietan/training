#include <iostream>

using namespace std;

int main()
{
  cout << "Declare pointer and reference" << endl;
  double double_value{12.34};
  // assignment can use = or parenthesis ... double d = 12.34;
  double &ref_double_value{double_value}; // Reference to double_value
  double *p_double_value{&double_value};  // Pointer to double_value

  cout << "Reading" << endl;
  std::cout << "double_value : " << double_value << std::endl;
  std::cout << "ref_double_value : " << ref_double_value << std::endl;
  std::cout << "p_double_value : " << p_double_value << std::endl;
  std::cout << "*p_double_value : " << *p_double_value << std::endl;
  cout << endl;

  cout << "Writing through pointer" << endl;
  *p_double_value = 15.44;
  std::cout << "double_value : " << double_value << std::endl;
  std::cout << "ref_double_value : " << ref_double_value << std::endl;
  std::cout << "p_double_value : " << p_double_value << std::endl;
  std::cout << "*p_double_value : " << *p_double_value << std::endl;
  cout << endl;

  cout << "Writing through reference" << endl;
  ref_double_value = 18.44;
  std::cout << "double_value : " << double_value << std::endl;
  std::cout << "ref_double_value : " << ref_double_value << std::endl;
  std::cout << "p_double_value : " << p_double_value << std::endl;
  std::cout << "*p_double_value : " << *p_double_value << std::endl;
  cout << endl;

  cout << "Change the reference to something else" << endl;
  double some_other_double{78.45};
  ref_double_value = some_other_double;
  cout << "some_other_double: " << some_other_double << endl;
  std::cout << "double_value : " << double_value << std::endl;
  std::cout << "ref_double_value : " << ref_double_value << std::endl;
  std::cout << "p_double_value : " << p_double_value << std::endl;
  std::cout << "*p_double_value : " << *p_double_value << std::endl;
  cout << endl;

  cout << "Make the pointer point to something else" << endl;
  p_double_value = &some_other_double;
  std::cout << "double_value : " << double_value << std::endl;
  std::cout << "ref_double_value : " << ref_double_value << std::endl;
  std::cout << "&double_value : " << &double_value << std::endl;
  std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
  std::cout << "p_double_value : " << p_double_value << std::endl;
  std::cout << "*p_double_value : " << *p_double_value << std::endl;
  cout << endl;

  cout << "Assign pointer a new value" << endl;
  *p_double_value = 555.5;
  std::cout << "double_value : " << double_value << std::endl;
  std::cout << "ref_double_value : " << ref_double_value << std::endl;
  std::cout << "&double_value : " << &double_value << std::endl;
  std::cout << "&ref_double_value : " << &ref_double_value << std::endl;
  std::cout << "p_double_value : " << p_double_value << std::endl;
  std::cout << "*p_double_value : " << *p_double_value << std::endl;
  cout << endl;

  cout << "Changing age to 22" << endl;
  int age{22};

  //   int *age_ptr = &age;
  //   int &age_ref(age);

  int *age_ptr = &age;
  int &age_ref = age;

  std::cout << "value1 : " << *age_ptr << std::endl;
  std::cout << "value2 : " << age_ref << std::endl;

  return 0;
}