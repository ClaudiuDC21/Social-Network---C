#pragma once
#include "../AbstractDataType(TAD)/List.h"
#include <iostream>
using namespace std;

template<class T>
class OrderedMultitude {
private:
    struct Node {
        T valoare;
        Node* stanga;
        Node* dreapta;
    };

    Node* node;

    void add(Node*& pNode, T value) {
        if (pNode == nullptr) {
            pNode = new Node;
            pNode->valoare = value;
            pNode->stanga = nullptr;
            pNode->dreapta = nullptr;
        }
        else if (value < pNode->valoare) {
            add(pNode->stanga, value);
        }
        else if (value > pNode->valoare) {
            add(pNode->dreapta, value);
        }
    }

    void destroy(Node* node) {
        if (node != nullptr) {
            destroy(node->stanga);
            destroy(node->dreapta);
            delete node;
        }
    }

    void remove(Node*& node, T value) {
        if (node != nullptr) {
            if (value < node->valoare) {
                remove(node->stanga, value);
            }
            else if (value > node->valoare) {
                remove(node->dreapta, value);
            }
            else {
                if (node->stanga == nullptr && node->dreapta == nullptr) {
                    delete node;
                    node = nullptr;
                }
                else if (node->stanga == nullptr) {
                    Node* aux = node;
                    node = node->dreapta;
                    delete aux;
                }
                else if (node->dreapta == nullptr) {
                    Node* aux = node;
                    node = node->stanga;
                    delete aux;
                }
                else {
                    Node* aux = node->dreapta;
                    while (aux->stanga != nullptr) {
                        aux = aux->stanga;
                    }
                    node->valoare = aux->valoare;
                    remove(node->dreapta, aux->valoare);
                }
            }
        }
    }

    bool exists(Node* node, T value) {
        if (node != nullptr) {
            if (value < node->valoare) {
                exists(node->stanga, value);
            } else if (value > node->valoare) {
                exists(node->dreapta, value);
            } else {
                return true;
            }
        } else {
            return false;
        }
    }

    void getListOrdered(Node* node, List<T> &list) const {
        if (node != nullptr) {
            getListOrdered(node->stanga, list);
            list.add(node->valoare);
            getListOrdered(node->dreapta, list);
        }
    }

public:
    OrderedMultitude() {
        node = nullptr;
    }

    ~OrderedMultitude() {
        destroy(node);
    }

    void add(T value) {
        add(node, value);
    }

    void remove(T value) {
        remove(node, value);
    }

    bool exists(T value) {
        return exists(node, value);
    }

    List<T> getOrderedList() {
        List<T> list;
        getListOrdered(node, list);
        return list;
    }
};
