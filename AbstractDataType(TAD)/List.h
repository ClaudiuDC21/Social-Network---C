#pragma once
#include <vector>
using namespace std;

template<class T>
class List {
private:
    vector<T> data;

public:
    T& operator[](int index) {
        return this->data[index];
    }

    void add(const T& value) {
        this->data.push_back(value);
    }

    void remove(int index) {
        this->data.erase(this->data.begin() + index);
    }

    int getSize() const {
        return this->data.size();
    }

};