#ifndef BMS_RSC_H
#define BMS_RSC_H

#endif //BMS_RSC_H
#include <vector>

using namespace std;
class RSC {
public:
    RSC();
    int next(int value);
    int get_last();
    int get_prev();
    int clearing_sequence();

private:
    int last, prev;
    vector<int> mem;
};

