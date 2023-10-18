#include <iostream>
#include <vector>
#include "KDTree.h"
#include "point_generation.hh"

#define N 10000
#define Q 10

using namespace std;

int main(int argc, char* argv[]) {

    int K=2;

    if(argc>2) {
        cout<<"Usage: main [K]\n"
              "    K : k-dimesions"<<endl;
        return 0;
    }else if(argc==2){
        K = *argv[1] - '0';
    }
    
    KDTree tree=KDTree();

    for(int n=1;n<N;n++){

        for (int i=0;i<n;i++) {
            vector<double> tree_point = generate_point(K);
            tree.insert(tree_point);
        }
        double costMean=0;
        for(int q=0; q < Q;q++){
            vector<double> point = generate_point(K);

            int cost=0;
            tree.findNearest(point,cost);
            costMean+=cost;
        }

        cout<<n<<" "<<costMean/Q<<endl;

        tree.destroy();
    }

    return 0;
}
