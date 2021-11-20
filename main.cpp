#include <iostream>
#include <utility>
#include <getopt.h>

#include "RSC.h"

using namespace std;

void print(vector<int> *v){
    for(int i : *v) {
        cout << i << ' ';
    }
    cout << endl;
}
pair<vector<int>, vector<int>> inter_leaver(string input, string pos) {
    vector<int> data;
    vector<int> position;

    // Create input bits
    for(char bit : input) {
        data.push_back((int)bit - '0');
    }

    // Parse bits position
    auto start = 0U;
    auto end = pos.find(',');
    while (end != std::string::npos)
    {
        position.push_back(atoi(pos.substr(start, end - start).data()));
        start = end + 1;
        end = pos.find(',', start);
    }
    position.push_back(atoi(pos.substr(start, end - start).data()));

    vector<int> inter(data.size());
    for (int i = 0; i < data.size(); ++i) {
        inter.at(i) = data.at(position.at(i));
    }

    return make_pair(data, inter);
}



int main(int argc, char **argv) {
    RSC rsc1;
    RSC rsc2;

    int c, encoder, decoder;
    string pos, input;
    while ((c = getopt(argc, argv, "edi:")) != -1) {
        switch (c) {
            case 'e':
                encoder = 1;
                break;
            case 'd':
                decoder = 1;
                break;
            case 'i':
               pos = optarg;
               break;
            default:
                exit(1);
        }
    }

    while(cin) {
        getline(cin, input);
        cout << input << endl;
    };

    pair<vector<int>, vector<int>> test = inter_leaver("101","3,2,4,1,5,0");//011101

    int y1, y2;
    for(int i = 0; i < test.first.size(); i++) {
        y1 = rsc1.next(test.first.at(i));
        y2 = rsc2.next(test.second.at(i));
        cout << test.first.at(i) << y1 << y2;
    }

    y1 = rsc1.next(0);
    y2 = rsc2.next(0);
    cout << rsc1.get_last() << y1 << y2;

    y1 = rsc1.next(0);
    y2 = rsc2.next(0);
    cout << rsc1.get_last() << y1 << y2 << endl;

    cout << "110001101001111000111000" << endl;
    return 0;
}
