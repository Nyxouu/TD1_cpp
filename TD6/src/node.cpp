#include <iostream>
#include <string>
#include <vector>
#include "node.hpp"


void pretty_print_left_right(Node const& node, std::string const& prefix, bool is_left) {
    if (node.right) {
        pretty_print_left_right(*node.right, prefix + (is_left ? "|   " : "    "), false);
    }
    std::cout << prefix << (is_left ? "+-- " : "+-- ") << node.value << std::endl;
    if (node.left) {
        pretty_print_left_right(*node.left, prefix + (is_left ? "    " : "|   "), true);
    }
}

void pretty_print_left_right(Node const& node) {
    pretty_print_left_right(node, "", true);
}

Node* create_node(int value){
    return {new Node {value, nullptr, nullptr}};
}

bool Node::is_leaf() const {
    if (left==nullptr && right==nullptr){
        return true;
    }
    else {
        return false;
    }
}

void Node::insert(int valeur){
    Node* new_node {create_node (valeur)};

    if (valeur < this->value){ //this sert a renvoyer la value de base 
        if (left!=nullptr){
           left -> insert(valeur); 
        }
        else {
            left = new_node ;
        }
    }
    else if (valeur > this->value){
        if (right!=nullptr){
           right -> insert(valeur); 
        }
        else {
            right = new_node ;
        }
    }
}

int Node::height() const{
    int h_left {0};
    int h_right {0};
    if (left != nullptr){
        h_left = left->height(); //appel recursif a partir de l'enfant left
    }
    if (right != nullptr){
        h_right = right->height(); //appel recursif a partir de l'enfant right
    }
    return (std::max(h_left,h_right)+1);

}

void Node::delete_childs(){
    if(left != nullptr ){
        left->delete_childs();
    }
    if(right != nullptr ){
        right->delete_childs();
    }
    delete this;
}

void Node::display_infixe() const{
    if (left!=nullptr){
        left->display_infixe();
    }
    std::cout << value << ", " ;
    if (right!=nullptr){
        right->display_infixe();
    }
}

std::vector<Node const*> Node::prefixe() const{
    std::vector<Node const*> vec_node {};
    vec_node.push_back(this);
    if (left!=nullptr){
        auto left_nodes {left->prefixe()};
        vec_node.insert(vec_node.end(), left_nodes.begin(), left_nodes.end());
    }
    if (right!=nullptr){
        auto right_nodes {right->prefixe()};
        vec_node.insert(vec_node.end(), right_nodes.begin(), right_nodes.end());
    }
    return vec_node;
}


Node*& most_left(Node*& node){
    if (node->left == nullptr){
        std::cout<< node->value <<std::endl;
        return node;
    }
    while (node->left != nullptr){
        node = node->left ;
    }
    std::cout<< node->value <<std::endl;
    return node;
}