#include <iostream>
#include <vector>
#include "tri.hpp"


int main () {

    std::vector<int> array {6, 2, 8, 1, 5, 3, 9};
if (is_sorted(array)) {
    std::cout << "Le tableau est trie" << std::endl;
} else {
    std::cout << "Le tableau n'est pas trie" << std::endl;
}

bubble_sort(array);

}