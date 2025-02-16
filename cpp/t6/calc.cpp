#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  bool repeat = false;
  std::cout << "Welcome to the greatest calculator on Earth" << std::endl;

  do {
    std::srand(
        std::time(nullptr)); // use current time as seed for random generator
        
    int num1 = rand() % 199;
    int num2 = rand() % 199;
    const char *primitives = "+-/x";
    int opidx = (rand() % 3);
    std::cout << "op idx = " << opidx << std::endl;
    char op = primitives[opidx];

    /*
    Figure out operator and calculate the answer.
    */
    int answer;
    switch (opidx) {
    case 0:
      answer = num1 + num2;
      break;

    case 1:
      answer = num1 - num2;
      break;

    case 2:
      answer = num1 * num2;
      break;

    case 3:
      answer = num1 / num2;
      break;
    }

    std::cout << "What's the result of " << num1 << op << num2 << "?";
    int userAnswer;
    std::cin >> userAnswer;

    if (userAnswer != answer) {
      std::cout << "Naah! The correct answer is : " << answer << std::endl;
    } else {
      std::cout << "Congratulations! You got the result " << answer << " right!"
                << std::endl;
    }

    std::cout << "Do you want me to try again? (Y | N) : ";
    char inp;
    std::cin >> inp;

    repeat = (inp == 'y' || inp == 'Y');
  } while (repeat);

  return 0;
}