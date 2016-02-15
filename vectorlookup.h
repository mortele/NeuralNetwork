#pragma once

template <typename T>
T &at(std::vector<T> &vec, int index) {
    return vec.at(index);
    //return vec[index];
}
