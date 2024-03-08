#include <iostream>
#include <vector>
#include <algorithm>


//TABLEAU TRIE OU PAS
bool is_sorted(std::vector<int> const& vec) { 
    return std::is_sorted(vec.begin(), vec.end()); 
}

//AFFICHER UN TABLEAU
void display (std::vector<int> & vec){
    for (int i{0}; i<vec.size();i++){
        std::cout << vec[i] << " , " ;
    }
}

//BUBBLE TRI
void bubble_sort(std::vector<int> & vec){
    while (is_sorted(vec)==false){
        for (int i{0}; i<vec.size()-1; i++){
            if (vec[i]>vec[i+1]){
                int num_i = vec[i];
                vec[i]=vec[i+1];
                vec[i+1]=num_i;
            }
        }
    }
    display (vec);   
}



