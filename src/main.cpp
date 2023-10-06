#include <iostream>
#include <vector>
#include "KDTree.h"
#include <queue>
#include <map>
using namespace std;

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
double distance(const vector<double>& point1, const vector<double>& point2){
    if(point1.size() != point2.size())  throw invalid_argument( "points size not equal" );

    double sum=0;

    for(int i=0; i< point1.size();++i)
        sum += ((point1[i]-point2[i]) * (point1[i]-point2[i]));

    return sqrt(sum);
}

int main() {
    KDTree tree=KDTree();

    int n;
    int m;
    cin>>n>>m;

    //point
    vector<double> epoint(m);
    for(int i=0;i<m;i++){
        cin>>epoint[i];
    }

    for (int i=0;i<n;i++) {
        vector<double> point(m);
<<<<<<< HEAD
=======
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
>>>>>>> 136e675 (first commit)
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
        for(int j=0;j<m;j++){
            double aux;
            cin>>aux;
            point[j]=aux;
<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
            cout<<aux<<" ";
        }

        tree.insert(point);
        cout<<" -> "<<distance(epoint,point)<<endl;
    }

    //result
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
    cout<<"Result "<<tree.findNearest(tree.getRoot(),epoint)->getName()<<endl;
    cout<<"Correct result:";
    for(double d:result) cout<<" "<<d;
    cout<<endl;
<<<<<<< HEAD
=======
        }
        tree.insert(name,point);
    }

    // Realizar operaciones en el árbol...
    tree.print(n);

>>>>>>> 136e675 (first commit)
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
    // Destruir el árbol al finalizar
    tree.destroy();

    return 0;
}
