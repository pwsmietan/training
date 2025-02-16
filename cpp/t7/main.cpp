#include <iostream>

int main() {
  const char *str = "C++ is cool!";
  // Compiler err: char *p_str = &str[0];
  std::cout << "&str=" << &str << std::endl;

  char str2[] = "This is another test";
  char *p_str2 = &str2[0];

  char s = 'a';
  char *p_s = &s;

  std::cout << "str2" << str2 << std::endl;
  std::cout << "\t&p_str2=" << &p_str2
            << " \t\tsizeof &p_str=" << sizeof(&p_str2) << std::endl;
  std::cout << "\tp_str=" << p_str2 << "\t\tsizeof p_str=" << sizeof(p_str2)
            << std::endl;
  std::cout << "\t*p_str=" << *p_str2 << "\t\tsizeof p_str=" << sizeof(p_str2)
            << std::endl;

  std::cout << "s=" << s << std::endl;
  std::cout << "\t &p_s=" << &p_s << "\t\tsizeof &p_s=" << sizeof(&p_s)
            << std::endl;
  std::cout << "\t*p_s=" << *p_s << "\t\tsizeof p_s=" << sizeof(p_s)
            << std::endl;

  // must be const - cannot modify string!
  const char *p_msg = "This is a test";
  std::cout << "p_msg=" << p_msg << std::endl;
  std::cout << "\t &p_msg=" << &p_msg << "\t\tsizeof &p_msg=" << sizeof(&p_msg)
            << std::endl;
  std::cout << "\tp_msg=" << p_msg << "\t\tsizeof p_msg=" << sizeof(p_msg)
            << std::endl;
  std::cout << "\t*p_msg=" << *p_msg << "\t\tsizeof *p_msg=" << sizeof(*p_msg)
            << std::endl;

  const char *mystrs[] = {"Paul", "Billy", "SKS", "PSH", "RK"};

  std::cout << "mystrs: " << mystrs << std::endl;     // addr
  std::cout << "&mystrs: " << &mystrs << std::endl;   // addr
  std::cout << "*mystrs: " << *mystrs << std::endl;   // string 1
  std::cout << "**mystrs: " << **mystrs << std::endl; // first byte of string 1
  std::cout << "*mystrs[1]: " << *mystrs[1]
            << std::endl; // first byte of string 2
  std::cout << "mystrs[1]: " << mystrs[1] << std::endl; // string 2

  const char *repl = "Wamba";
  mystrs[1] = repl;
  std::cout << "mystrs[1]: " << mystrs[1] << std::endl; // string 2

  // For Each
  for (const char *n : mystrs) {
    std::cout << "n: " << n << std::endl;
  }

  int scores[]{1, 5, 7, 3, 9};
  int *p_scores = &scores[0];
  std::cout << "p_s: " << p_scores << std::endl;
  std::cout << "*p_s: " << *p_scores << std::endl;
  std::cout << "sizeof p_s: " << sizeof(p_s) << std::endl;
  std::cout << "size of *p_s: " << sizeof(*p_s) << std::endl;

  int data[]{181, 82, 22, 53, 19, 1, 51, 217, 12, 11};
  for (int i = 0; i < sizeof(data); i++) {
    
  }

  return 0;
}