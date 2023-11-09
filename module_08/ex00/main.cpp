#include <iostream>
#include <vector>
#include <list>
#include "easyfind.hpp"

int main() {
    int vec_array[] = {1, 2, 3, 4, 5};
    std::vector<int> vec(vec_array, vec_array + sizeof(vec_array) / sizeof(vec_array[0]));

    int lst_array[] = {10, 20, 30, 40, 50};
    std::list<int> lst(lst_array, lst_array + sizeof(lst_array) / sizeof(lst_array[0]));

    int val_to_find = 3;

    try {
        int index_vec = easyfind(vec, val_to_find);
        std::cout << "Value " << val_to_find << " found at index " << index_vec << " in vector.\n";
    } catch (const std::exception &e) {
        std::cerr << "Value " << val_to_find << " not found in vector.\n";
    }

    try {
        int index_lst = easyfind(lst, val_to_find);
        std::cout << "Value " << val_to_find << " found at index " << index_lst << " in list.\n";
    } catch (const std::exception &e) {
        std::cerr << "Value " << val_to_find << " not found in list.\n";
    }

    // Testing with a value that doesn't exist
    int val_not_found = 8;

    try {
        int index_vec = easyfind(vec, val_not_found);
        std::cout << "Value " << val_not_found << " found at index " << index_vec << " in vector.\n";
    } catch (const std::exception &e) {
        std::cerr << "Value " << val_not_found << " not found in vector.\n";
    }

    try {
        int index_lst = easyfind(lst, val_not_found);
        std::cout << "Value " << val_not_found << " found at index " << index_lst << " in list.\n";
    } catch (const std::exception &e) {
        std::cerr << "Value " << val_not_found << " not found in list.\n";
    }

    return 0;
}
