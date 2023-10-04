#include <iostream>
#include <vector>
#include "KDTree.h"
#include <queue>
#include <map>
using namespace std;

int main() {
    KDTree tree=KDTree();
    // Insertar puntos k-dimensionales en el árbol
    int n;
    int m;
    cin>>n>>m;
    for (int i=0;i<n;i++) {
        vector<double> point(m);
        string name;
        cin>>name;
        for(int j=0;j<m;j++){
            double aux;
            cin>>aux;
            point[j]=aux;
        }
        tree.insert(name,point);
    }

    // Realizar operaciones en el árbol...
    tree.print(n);

    // Destruir el árbol al finalizar
    tree.destroy();

    return 0;
}
