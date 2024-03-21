#include <iostream>
#include <vector>
#include <algorithm>
#include "tri.hpp"


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


//TRI FUSION
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right) {
    // On crée deux vecteurs temporaires pour stocker les copies des deux sous-parties à fusionner
    size_t const left_size { middle - left + 1 };
    size_t const right_size { right - middle };
    std::vector<float> left_vec(vec.begin() + left, vec.begin() + middle + 1);
    std::vector<float> right_vec(vec.begin() + middle + 1, vec.begin() + right + 1);

    // Deux index pour parcourir les deux sous-parties et remplir le vecteur original
    size_t left_index {0};
    size_t right_index {0};

    size_t index {left};

    // Tant que nous avons pas parcouru tout les éléments d'au moins une des deux sous-parties
    while (left_index < left_size && right_index < right_size) {
        // On compare les éléments des deux sous-parties et on place le plus petit dans le vecteur original
        // on met à jour les index pour parcourir les sous-parties en conséquence
        if (left_vec[left_index] < right_vec[right_index]) {
            vec[index] = left_vec[left_index];
            left_index += 1;
        } else {
            vec[index] = right_vec[right_index];
            right_index += 1;
        }
        index += 1;
    }

    // S'il reste des éléments dans une des deux sous-parties, on les place dans le vecteur original
    while (left_index != left_size) {
        vec[index] = left_vec[left_index];
        left_index += 1;
        index += 1;
    }
    while (right_index != right_size) {
        vec[index] = right_vec[right_index];
        right_index += 1;
        index += 1;
    }
}


// Même mécanisme que pour le tri rapide
void merge_sort(std::vector<float> & vec) {
    merge_sort(vec, 0, vec.size() - 1);
}

void merge_sort(std::vector<float> & vec, size_t const left, size_t const right) {
    if (left >= right) {
        return;
    }
    // 1. Choix de l'index au milieu de la partition
    size_t const middle = (right+left)/2;

    // 2. Appels récursifs sur les deux sous-parties
    merge_sort (vec, left, middle);
    merge_sort (vec, middle+1, right);

    // 3. Fusion des deux sous-parties
    merge_sort_merge(vec, left,  middle, right);
}


//DICHOTOMIE
int search (std::vector<int> vec, int num){
    int left {0};
    int right = vec.size()-1 ;

    while (left <= right ){
        int middle {(left+right)/2};
        if (vec[middle] < num){
            left = middle+1 ;
            right = right ;
        }
        if (vec[middle] > num){
            left = left ;
            right = middle-1 ;
        }
        if (vec[middle] == num){
            return (middle);
        }
    }
    
    return (-1);
    
}
