#pragma once

bool is_sorted(std::vector<int> const& vec);
void display (std::vector<int> & vec);

//BUBBLE TRI
void bubble_sort(std::vector<int> & vec);

//TRI FUSION
void merge_sort_merge(std::vector<float> & vec, size_t const left, size_t const middle, size_t const right);
void merge_sort(std::vector<float> & vec);
void merge_sort(std::vector<float> & vec, size_t const left, size_t const right);

//DICHOTOMIE
int search (std::vector<int> vec, int num);