#include <iostream>

bool is_collection_sorted(int numbers[], unsigned int collection_size);

int main()
{
    int n[] = {1, 22222, 4, 5, 8, 12, 13, 16, 71, 92};
    int s = sizeof(n) / sizeof(int);
    std::cout << "collection size: " << s << std::endl;
    bool r = is_collection_sorted(n, s);
    std::cout << "Ret: " << r << std::endl;
}

bool is_collection_sorted(int numbers[], unsigned int collection_size)
{
    bool sorted = false;
    int nextIdx = 1;

    // Outer loop to cruise through the array elements:
    for (int i = 0; i < collection_size; i++)
    {
        std::cout << "i=" << i << "; nextIdx=" << nextIdx << std::endl;
        // Check upper bounds and compensate for index origin 0:
        if (nextIdx == collection_size)
        {
            std::cout << "We made it to the end of array!\n";
            sorted = true;
            break;
        }
        else
        {
            // Inspect the next element to it's predecessor:
            std::cout << "Is " << numbers[i] << " < " <<  numbers[nextIdx] << std::endl;
            if (numbers[i] < numbers[nextIdx++])
            {
                // We're less than the next value so move forward.
                continue;
            }
            else
            {
                // Array is unsorted - abort:
                break;
            }
        }
    }

    return sorted;
}