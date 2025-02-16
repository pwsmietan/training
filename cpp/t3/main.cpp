#include <iostream>
#include <vector>

using namespace std;
////////////////////////////////////////

const int ASCII_START = 65;

// Function prototype:
unsigned int sum_up_to_99();

int main()
{
    //std::cout << "Sum is: " << sum_up_to_99() << std::endl;

    // for(int i = 0; i < 255; ++i)
    // {
    //     if(i >= 0x41 && i <= 0x5A)
    //     {
    //         std::cout << static_cast<char>(i) << (i != 0x5A ? " " : "");            
    //     }
    // }

    std::vector<int> numbers {1,21,4,5,7,3,9,3,5,17,15};
    for (auto v : numbers)
    {
        if(v % 3 == 0)
            std::cout << v << " ";
    }
    
     for( unsigned char i{10}; i >= 0 ; --i)
            std::cout << "value : " << static_cast<unsigned int>(i) << std::endl;
    

    return 0;
}

unsigned int sum_up_to_99()
{
    unsigned int sum{};

    // Don't modify anything above this line
    // Your code will go below this line

    for (int i = 0, a = 5; i <= 99; i++)
    {
        
        sum += i;
        a++;
        std::cout << "a=" << a << "; sum=" << sum << std::endl;
    }

    // Your code will go above this line
    // Don't modify anyting below this line

    return sum;
}
