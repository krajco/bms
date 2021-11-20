#include "RSC.h"

#include <iostream>

using namespace std;

RSC::RSC() {
    mem = {0, 0, 0};
}

int RSC::next(int value) {
    this->mem.at(0) = value;

    int mem3 = this->mem.at(2);
    this->mem.at(2) = this->mem.at(1);
    this->mem.at(1) = this->mem.at(0) ^ mem3;
    prev = last;
    last = this->mem.at(0) ^ mem3;
    return last;
}

int RSC::get_last() {
    return last;
}

int RSC::get_prev() {
    return prev;
}

int RSC::clearing_sequence() {
    next(0);
};