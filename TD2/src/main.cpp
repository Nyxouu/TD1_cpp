#include <iostream>
#include <vector>
#include "tri.hpp"
#include "ScopedTimer.hpp"


int main () {

  std::vector<float> array {6., 2., 8., 1., 5., 3., 9., 7.};
  std::vector<int> array2 {6, 2, 8, 1, 5, 3, 9, 7};
// if (is_sorted(array)) {
//     std::cout << "Le tableau est trie" << std::endl;
// } else {
//     std::cout << "Le tableau n'est pas trie" << std::endl;
// }

//tri bubble
//bubble_sort(array2);

//tri fusion
// merge_sort(array);
// for (float i : array){
//   std::cout << i << ", ";
// }

//exo 3
{
    ScopedTimer timer1("chronometre tri bubble");
    bubble_sort(array2);

    ScopedTimer timer2("chronometre tri fusion");
    merge_sort(array);

    //On remarque que le tri Bubble est plus long que le tri fusion pour un tableau de même taille. 
    //Donc le fusion est plus optimisé que le bubble.
}


//dichotomie 

    std::vector<int> vec1 {1, 2, 2, 3, 4, 8, 12} ;//(valeur recherchée: 8)
    std::vector<int> vec2 {1, 2, 3, 3, 6, 14, 12, 15} ;//(valeur recherchée: 15)
    std::vector<int> vec3 {2, 2, 3, 4, 5, 8, 12, 15, 16}; //(valeur recherchée: 16)
    std::vector<int> vec4 {5, 6, 7, 8, 9, 10, 11, 12, 13} ;//(valeur recherchée: 6)
    std::vector<int> vec5 {1, 2, 3, 4, 5, 6, 7, 8, 9} ;//(valeur recherchée: 10)

std::cout << search (vec1,8) << std::endl ;
std::cout << search (vec2,15) << std::endl ;
std::cout << search (vec3,16) << std::endl ;
std::cout << search (vec4,6) << std::endl ;
std::cout << search (vec5,10) << std::endl ;

}