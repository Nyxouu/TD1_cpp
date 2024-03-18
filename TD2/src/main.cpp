#include <iostream>
#include <vector>
#include "tri.hpp"


int main () {

  std::vector<float> array {6., 2., 8., 1., 5., 3., 9., 7.};
// if (is_sorted(array)) {
//     std::cout << "Le tableau est trie" << std::endl;
// } else {
//     std::cout << "Le tableau n'est pas trie" << std::endl;
// }

// bubble_sort(array);
//merge_sort(array, 0, -1);

//tri fusion
merge_sort(array);
for (float i : array){
  std::cout << i << ", ";
}

}