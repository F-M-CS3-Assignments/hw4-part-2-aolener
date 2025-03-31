#include "bdc.h"
#include <vector>

#include <algorithm>

#include <iostream>
#include <string>



using namespace std;

int longestVector(vector<vector<int>> input) {
    unsigned int longest = 0;
    int idx = 0;
    for (size_t ii = 0; ii < input.size(); ii++) {
        if (input.at(ii).size() > longest) {
            longest = input.at(ii).size();
            idx = ii;
        }
    }
    return idx;
}

vector<int> findConglomerate(vector<int> startingList) {
    if (startingList.size() == 0 || startingList.size() == 1) {
        return startingList;
    }

    vector<vector<int>> idx(startingList.size());

    for (size_t ii = 0; ii < startingList.size(); ii++) {
        idx.at(ii) = {startingList.at(ii)};
    }

    int current;

    for (size_t ii = 0; ii < startingList.size(); ii++) {
        current = startingList.at(ii);

        for (size_t jj = ii + 1; jj < startingList.size(); jj++) {
            if (startingList.at(jj) % current == 0 && idx.at(ii).size() >= idx.at(jj).size()) {
                idx.at(jj) = {startingList.at(jj)};

                for (size_t kk = 0; kk < idx.at(ii).size(); kk++) {
                    idx.at(jj).push_back(idx.at(ii).at(kk));
                }
            }
        }
    }
    int max = longestVector(idx);
    return (idx.at(max));
}

vector<int> biggest_divisible_conglomerate(vector<int> input) {
    sort(input.begin(), input.end());
    return findConglomerate(input);
}

string vec_to_string(vector<int> vector) {
    string result = "{";
    for (size_t ii = 0; ii < vector.size(); ii++) {
        result.append(to_string(vector[ii]));
        result.append(", ");
    }
    result.append("}");
    return result;
}
