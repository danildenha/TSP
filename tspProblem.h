#ifndef PROBLEM_H
#define PROBLEM_H

#include <iostream>
#include <climits>
#include <vector>
#include <assert.h>
#include <bitset>
#include <string>
#include "graph.h"

using namespace std;
const int MAX_BITS = 32;
 
class tspProblem
{
private:
    Graph W;
    vector<vector<int>> D,P;
public:
	tspProblem(Graph& w): W(w) {
        bitset<MAX_BITS> set;
        size_t size = w.getNumVertices();
        //set all bits of size - 1 to 1
        //we use size - 1 since v1 is not included
        for (int i = 0; i < size-1; ++i) {set.set(i);}
        //rows: number of vertices
        //cols: number of possible subsets
        D.resize(size, vector<int>(set.to_ulong()));
        P.resize(size, vector<int>(set.to_ulong()));
    }
    unsigned int minDist() {
        unsigned int minLength;
        size_t size = W.getNumVertices();

        //every vertex except v1 the cost of edge
        //vi to v1 must be considered
        for (unsigned int i{0}; i < size; i++)
        {
            D[i][0] = W.getEdgeCost(i, 0);
        }

                    //TODO: implement the main DP loop and add bitsets
/*
        //main DP loop
         for (unsigned int i{0}; i < size - 2; i++)
        {
            if ()
        }
 */


        return minLength;
    }

};

#endif