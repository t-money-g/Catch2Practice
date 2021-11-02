//
// Created by tyoun on 11/1/2021.
//

#ifndef PRINT_STD_LIBRARY_CONTAINERS_H
#define PRINT_STD_LIBRARY_CONTAINERS_H

#include <iostream>
#include <vector>
#include <map>

using std::ostream;

// print a vector
template <typename T>
ostream& operator<<(ostream& o, std::vector<T>& v) {
    o << "[";
    if(v.empty()) {
        o << "]";
        return o;
    }

    // For every item except the last write "Item, "
    for (auto it = v.begin(); it != --v.end(); ++it) {
        o << *it << ", ";
    }
    // write out the item
    o << v.back() << "]";
    return o;
}

template <typename KeyT, typename ValueT>
ostream& operator <<(ostream& o, const std::map<KeyT, ValueT>& m) {
    o << "{ ";
    if (m.empty()) {
        o << "} ";
        return o;
    }

    // For every pair except the last write "Key : Value, "
    for (auto it = m.begin(); it != --m.end(); ++it)
    {
        const auto& [key, value] = *it;
        o << key << ": " << value << ", ";
    }

    // write out the last item
    const auto& [key, value] = *--m.end();
    o << key << ": " << value << "}";
    return o;
}
#endif //PRINT_STD_LIBRARY_CONTAINERS_H
