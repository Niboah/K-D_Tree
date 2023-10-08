#include <iostream>
#include <vector>
#include "KDTree.h"

using namespace std;


int main() {
    KDTree tree=KDTree();

    int n; //Numero de punts
    int m; //dimensions
    cin>>n>>m;

    //point des del que busquem el mes proper
    vector<double> epoint(m);
    for(int i=0;i<m;i++){
        cin>>epoint[i];
    }

    //input de tots el punts
    for (int i=0;i<n;i++) {
        vector<double> point(m);
        for(int j=0;j<m;j++){
            double aux;
            cin>>aux;
            point[j]=aux;
            cout<<aux<<" ";
        }

        tree.insert(point);
        cout<<" -> "<<distance(epoint,point)<<endl;
    }

    //si ja sabem el resultat correcte del punt guanyador el donem per comparar
    vector<double> result(m);
    for(int i=0;i<m;i++){
        cin>>result[i];
    }

    // Realizar operaciones en el árbol...
    tree.print();

    cout<<"------"<<endl;
    cout<<"Point:";
    for(double d:epoint)cout<<" "<<d;
    cout<<endl;
    int cost=0;
    cout<<"Result "<<tree.findNearest(epoint,cost)->getName()<<endl;
    cout<<"Correct result:";
    for(double d:result) cout<<" "<<d;
    cout<<endl;
    cout<<"Cost: "<<cost<<endl;

    // Destruir el árbol al finalizar
    tree.destroy();

    return 0;
}
