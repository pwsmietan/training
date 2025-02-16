#include <iostream>

using namespace std;

void unique_numbers(int numbers[], unsigned int collection_size) {

  // Allocate memory for our unique array (up to the length of the source)
  int finishedUniqueData[collection_size];
  // Our working accumulator:
  int countOfUniques = 0;

  /*
   * Nested for loop approach. Not the most efficient but all this logic has to
   * go into one function call with no other sub-funtions :-(
   */
  for (int i = 0; i < collection_size; i++) {
    bool isFound = false;

    /*
     * Loop through arrays and compare (would prefer to use a collection but
     * this'll do for now). If the value exists then we'll break out.
     */
    for (int j = 0; j < countOfUniques; j++) {
      if (finishedUniqueData[j] == numbers[i]) {
        isFound = true;
        break;
      }
    }

    if (!isFound) {
      finishedUniqueData[countOfUniques++] = numbers[i];
    }
  }

  std::cout << "The collection contains " << countOfUniques
            << " unique numbers, they are : ";

  for (unsigned int i{}; i < countOfUniques; ++i) {
    std::cout << finishedUniqueData[i] << " ";
  }
}