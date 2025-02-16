#include <iostream>

int main()
{

  int arr0[5]{1, 2, 3, 4, 5};
  int arr1[5]{6, 7, 8, 9, 10};
  int *p_arr1{&arr1[0]};
  int *p_arr0{&arr0[0]};

  // Print arr0
  std::cout << "arr0 : ";
  for (size_t i{}; i < std::size(arr0); ++i)
  {
    std::cout << p_arr0[i] << " ";
  }
  std::cout << std::endl;

  // Print arr1
  std::cout << "arr1 : ";
  for (size_t i{}; i < std::size(arr1); ++i)
  {
    std::cout << p_arr1[i] << " ";
  }
  std::cout << std::endl;

  // Swapping data the hard way
  /*
  int temp[5];

  //Move data from arr1 into temp
  for (size_t i{ 0 }; i < std::size(arr1); ++i) {
      temp[i] = arr1[i];
  }

  //Move data from arr0 to arr1
  for (size_t i{ 0 }; i < std::size(arr0); ++i) {
      arr1[i] = arr0[i];
  }

  //Move data temp to arr0
  for (size_t i{}; i < std::size(temp); ++i) {
      arr0[i] = temp[i];
  }
  */

  /*
   int * temp{nullptr};

   temp = arr1;
   arr1 = arr0;
   */

  int *temp{nullptr};

  temp = &p_arr1[0];
  p_arr1 = &p_arr0[0];
  p_arr0 = &temp[0];

  // Print arr0
  std::cout << "arr0 : ";
  for (size_t i{}; i < std::size(arr0); ++i)
  {
    std::cout << p_arr0[i] << " ";
  }
  std::cout << std::endl;

  // Print arr1
  std::cout << "arr1 : ";
  for (size_t i{}; i < std::size(arr1); ++i)
  {
    std::cout << p_arr1[i] << " ";
  }
  std::cout << std::endl;

  int data[]{11, 2, 52, 53, 9, 13, 5, 7, 12, 11};
  unsigned int size = sizeof(data);
  int *p_data = data;
  std::cout << "*p_data: " << *p_data << "; size: " << size << std::endl;
  int *min_address = nullptr;

  int minVal = *data;
  std::cout << "*min_elt: " << minVal << std::endl;

  //   for (unsigned int i = 0; i < size; i++) {
  //     if (*(data + i) < minVal) {
  //       min_address = data + i;
  //       minVal = data[i];
  //     }
  //   }

  for (unsigned int i = 0; i < size; i++)
  {
    if (*(p_data + i) < minVal)
    {
      min_address = p_data + i;
      minVal = *(p_data + i);
    }
  }

  std::cout << "minVal: " << minVal << std::endl;

  int *p_ints = new int(200);
  int *p_lots = new int[200];

  // std::cout << "Size of p_lots: " << size_t(*p_lots) << std::endl;

  delete p_ints;
  p_ints = nullptr;

  delete p_lots;
  p_lots = nullptr;

  const int age{33};
  const int &age_ref{age};

  std::cout << "--Before--" << std::endl;
  std::cout << "age_ref: " << age_ref << std::endl;
  std::cout << "&age_ref : " << &age_ref << std::endl;

  int age1{44};
  // age_ref = age1; can't repoint a constant ptr!

  std::cout << "--After--" << std::endl;
  std::cout << "age_ref: " << age_ref << std::endl;
  std::cout << "&age_ref : " << &age_ref << std::endl;

  char message[]{"The sky is blue my friend."};
  size_t length = sizeof(message)/sizeof(*message);
  std::cout << "Len: " << length << std::endl;
  char *result = new char[length];  

  for(size_t i = 0; i < length; i++){
    if(std::isspace(message[i]))
      result[i] = '_';
    else
      result[i] = message[i];
  }

  std::cout << "result: " << result;

  return 0;
}