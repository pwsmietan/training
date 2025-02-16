#include <numeric>
#include <vector>
#include <iostream>
#include <concepts>
#include <string>

// Here's my concept/type constraint:
template <typename T>
concept ConvertibleToStdString = requires(T a) {
    std::to_string(a);
};

// template <typename T>
//     requires ConvertibleToStdString<T>
// std::string concatenate(T a, T b)
// {
//     return std::to_string(a) + std::to_string(b);
// }

// Here's my function definition with the template decoration.
// This format is nicer and more compact!
template <ConvertibleToStdString T>
std::string concatenate(T a, T b)
{
    return std::to_string(a) + std::to_string(b);
}

// template <typename T>
//     requires std::integral<T> || std::floating_point<T>
// std::string concatenate(T a, T b)
// {
//     return std::to_string(a) + std::to_string(b);
// }

int main()
{
    double x{6};
    double y{7};

    // This will cause a compiler error because it breaks the constraints:
    // std::string x{"Hello"};
    // std::string y{"World"};

    auto result = concatenate(x, y);
    std::cout << "result : " << result << std::endl;
}