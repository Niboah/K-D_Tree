#include <iostream>
#include <vector>
#include <time.h>
#include <stdlib.h>
#include "KDTree.h"

using namespace std;


int main() {
    srand(time(NULL));
    KDTree tree=KDTree();

    int n = rand()%1000; //Numero de punts
    int m = rand()%10; //dimensions
    cout<<n<<" "<<m<<endl;

    //point des del que busquem el mes proper
    vector<double> epoint(m);
    for(int i=0;i<m;i++){
        epoint[i] = (double)(rand() % 1000000) / 1000000;
    }
    double min=10;
    double dist;
    vector<double> sol(m);
    //input de tots el punts
    for (int i=0;i<n;i++) {
        vector<double> point(m);
        for(int j=0;j<m;j++){
            point[j] = (double)(rand() % 1000000) / 1000000;
            cout<<point[j]<<" ";
        }

        tree.insert(point);
        dist=distance(epoint,point);
        cout<<" -> "<<dist<<endl;
        if (dist<min){
            sol=point;
            min=dist;
        }
    }


    // Realizar operaciones en el árbol...
    tree.print();

    cout<<"------"<<endl;
    cout<<"Point:";
    for(double d:epoint)cout<<" "<<d;
    cout<<endl;
    cout<<"Result        :"<<tree.findNearest(epoint)->getName()<<endl;
    cout<<"Correct result:";
    for(double d:sol) cout<<" "<<d;
    cout<<endl;

    // Destruir el árbol al finalizar
    tree.destroy();

    return 0;
}
