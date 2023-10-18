#include <iostream>
#include <vector>
#include "KDTree.h"
#include "point_generation.hh"

using namespace std;

int main() {
    srand(time(NULL));
    KDTree tree=KDTree();

    int n = get_random_int(0, 1000); //Numero de punts
    int m = get_random_int(1, 10); //dimensions
    cout<<n<<" "<<m<<endl;

    //point des del que busquem el mes proper
    vector<double> epoint = generate_point(m);

    double min=10;
    double dist;
    vector<double> sol(m);
    //input de tots el punts
    for (int i=0;i<n;i++) {
        vector<double> point = generate_point(m);

        for(int j=0;j<m;j++){
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
    //tree.print();

    cout<<"------"<<endl;
    cout<<"Num nodes: "<<n<<" | Num dimensiones: "<<m<<endl;
    cout<<"Punto aleatorio :";
    for(double d:epoint)cout<<" "<<d;
    cout<<endl;
    int cost=0;
    cout<<"Result        :"<<tree.findNearest(epoint,cost)->getName()<<endl;
    cout<<"Correct result:";
    for(double d:sol) cout<<" "<<d;
    cout<<endl;
    cout<<"Coste: "<<cost<<endl;

    // Destruir el árbol al finalizar
    tree.destroy();

    return 0;
}
