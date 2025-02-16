#include <iostream>
#include <type_traits>
#include <concepts>
#include <string>

// Syntax1

// template <typename T>
// concept MyIntegral = std::is_integral_v<T>;

// MyIntegral auto add( MyIntegral auto a, MyIntegral auto b) {
//     return a + b;
// }

template <typename T>
  requires std::integral<T> || std::floating_point<T>
std::string concatenate(T a, T b)
{
  return std::to_string(a) + std::to_string(b);
}

int main()
{

  double x{6};
  double y{7};

  // std::string x{"Hello"};
  // std::string y{"World"};

  concatenate(x, y);

  std::cout << "Done!" << std::endl;

  return 0;
}