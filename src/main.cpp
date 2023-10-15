#include <iostream>
#include <vector>
#include "KDTree.h"
#include "../point_generation.hh"

using namespace std;


int main() {
    KDTree tree=KDTree();

    int N=10000;
    int Q=10;
    cout<<"N K Coste(Nodos) Coste(Tiempo)"<<endl;
    for(int n=1;n<N;n++){
        for(int k=2;k<=6;k++){

            for (int i=0;i<n;i++) {
                vector<double> tree_point = generate_point(k);
                tree.insert(tree_point);
            }


            for(int q=0; q < Q;q++){
                vector<double> point = generate_point(k);

                int cost=0;
                clock_t start, end;
                start = clock();
                tree.findNearest(point,cost);
                end = clock();
                cout<<n<<" "<<k<<" "<<cost<<" "<<(double)(end-start)/CLOCKS_PER_SEC<<endl;

            }
            tree.destroy();
        }
    }

    return 0;
}
