// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <string>
// #include <sstream>
// #include <iterator>
// #include <cctype> 
// #include <stack>
// #include "structure-de-donnee-ex1.hpp"



// //EXERCICE 1

// std::string SaisieUtilisateur (){
//     std::string saisie {};

//     std::cout << "Entrez votre calcul : ";
//     std::getline(std::cin , saisie);
//     return saisie ;
// }

// std::vector<std::string> split_string(std::string const& s){
//     std::istringstream in(s); // transforme une chaîne en flux de caractères, cela simule un flux comme l'est std::cin
//     // l’itérateur va lire chaque element de "in", comme un flux d'entrée, chaque élément est séparé par un espace
//     return std::vector<std::string>(std::istream_iterator<std::string>(in), std::istream_iterator<std::string>()); 
// }

// bool is_floating(std::string const& s){
//     for (int i : s){
//         if (!(std::isdigit(i) || i == '.')){
//             return false ;
//         }
//     }
//     return true ;

// }

// float npi_evaluate(std::vector<std::string> const& tokens){
//     std::stack<float> stack ;
//     for(std::string str : tokens ){
//         if (is_floating(str)==true){
//             stack.push(stof(str));  //std::stof sert a convertir les caracteres du tableau en float 
//         }
//         if (is_floating(str)==false){
//             // Je récupère l'élément en haut de la pile
//             float rightOperand { stack.top() };
//             // Je l'enlève de la stack (la méthode top ne fait que lire l’élément en dessus de la pile)
//             stack.pop();
//             float leftOperand { stack.top() };
//             stack.pop();

//             // Il faut ensuite en fonction de l'opérateur calculer le résultat pour le remettre dans la pile
//             float result {};
//             if (str == "+"){
//                 result =leftOperand+rightOperand;
//             }
//             else if (str == "-"){
//                 result =leftOperand-rightOperand;
//             }
//             else if (str == "*"){
//                 result =leftOperand*rightOperand;
//             }
//             else if (str == "/"){
//                 result =leftOperand/rightOperand;
//             }
//             else if (str == "^"){
//                 result = pow(leftOperand, rightOperand);
//             }
//             stack.push(result);
//         }
//     }
//     float final_result {stack.top()};
//     return (final_result) ;
    
// }