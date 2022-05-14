// Include needed standard library functions
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

// The main function is the entry point for any program written in C++
int main(int /*argc*/, char** /*argv*/)
{
  // Read first datapoint containing the number of data elements
  int N;
  std::cin >> N;

  // Create storage for the data and reserve memory
  std::vector<int> data;
  data.reserve(N);

  // Read each of the datapoints from standard in and store them in the data vector
  int element;
  for (auto i = 0; i < N; ++i) {
    std::cin >> element;
    data.emplace_back(element);
  }

  // Multiply each element in data by two
  std::transform(data.begin(), data.end(), data.begin(), 
               [](auto const& ele){ return ele*2; });

  // Compute the sum of all elements in data
  auto sum = std::accumulate(data.begin(), data.end(), 0);

  for( auto const& element : data )
    std::cout << element << ' ';
  std::cout << '\n' << sum;

  // Return the value Zero to the operating system
  // Indicating that your program terminated successfully without sideeffects
  return 0;
}
