#include <sys/wait.h>
#include <unistd.h>

#include <iostream>
#include <vector>

#include "KDTree.h"
#include "point_generation.hh"

#define N 10000
#define Q 10

#define _CORES_ 16

using namespace std;

int main(int argc, char* argv[]) {
    int K = 2;

    if (argc > 2) {
        cout << "Usage: main [K]\n"
                "    K : k-dimesions"
             << endl;
        return 0;
    } else if (argc == 1) {
        cerr << "!! warning !! no K detected, defaulting to K = 2" << endl;
    }
    else if (argc == 2) {
        K = *argv[1] - '0';
    }

    int work_per_core = N / _CORES_;

    if (N % _CORES_ != 0)
        cerr << "non-divisible integer detected! || real executed iteratioins -> " << (N / _CORES_) * _CORES_ << endl;

    for (int i = 0; i < _CORES_; ++i) {
        if (fork() == 0) {
            KDTree tree = KDTree();
            for (int n = work_per_core * i + 1; n <= work_per_core * (i + 1); ++n) {
                for (int i = 0; i < n; i++) {
                    vector<double> tree_point = generate_point(K);
                    tree.insert(tree_point);
                }
                double costMean = 0;
                for (int q = 0; q < Q; q++) {
                    vector<double> point = generate_point(K);

                    int cost = 0;
                    tree.findNearest(point, cost);
                    costMean += cost;
                }

                cout << n << " " << costMean / Q << endl;

                tree.destroy();
            }
            exit(0);
        }
    }

    while (waitpid(-1, NULL, 0) > 0);

    return 0;
}
