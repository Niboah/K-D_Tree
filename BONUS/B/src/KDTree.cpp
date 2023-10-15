#include "KDTree.h"

using namespace std;

KDNode::KDNode(const vector<double>& p,int dis) : point(p), left(nullptr), right(nullptr), discriminant(dis) {}

string KDNode::getName(){
    string name="";
    for(double p:point)
        name+=" "+ to_string(p);
    return name;
}


KDTree::KDTree() : root(nullptr) {}



int KDTree::bigdimensionBB (const vector<double>& bb){
    double dmax = bb[1]-bb[0];
    double d;
    int imax=0;
    for(int i=2;i<bb.size();i+=2){
        d = bb[i+1]-bb[i];
        if(d>dmax){
            dmax=d;
            imax=i;
        }
    }
    return imax/2;
}

// Función para insertar un punto en el árbol k-d
KDNode* KDTree::insert(KDNode* node, const vector<double>& point,vector<double> bb) {
    
    int dis = bigdimensionBB(bb);//mira la dimensió amb més amplitud.
    if (node == nullptr){
        KDNode* a = new KDNode(point,dis);
        cout<<a->discriminant<<endl;
        return a;
    }
    // Comparar puntos en función de la dimensión actual
    if (point[(node->discriminant)] < node->point[node->discriminant]) {
        bb[((node->discriminant)*2)+1] = node->point[node->discriminant];//el punt final de la bounding box en la dimensió discriminant tindrà la posició del node en la dimensió discriminant.
        node->left = insert(node->left, point,bb);
    } else {
        bb[(node->discriminant)*2] = node->point[node->discriminant]; //el punt inicial de la bounding box en la dimensió discriminant tindrà la posició del node en la dimensió discriminant.
        node->right = insert(node->right, point,bb);
    }
    return node;
}

// Función para destruir el árbol k-d
void KDTree::destroyTree(KDNode* node) {
    if (node != nullptr) {
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

// Función para insertar un punto en el árbol k-d
//bb té 2 valors per dimensió que indiquen el punt inicial i 
//final de la bouding box per cada coordenada.
void KDTree::insert(const vector<double>& point) {
    vector<double>bb (2*point.size());

    for(int i=0;i<bb.size();i+=2){
        bb[i]=0;
        bb[i+1]=1;
    }//en totes les dimensions l'hipercub va de 0 a 1.
    root = insert(root, point,bb);
}

// Función para destruir el árbol k-d
void KDTree::destroy() {
    destroyTree(root);
    root = nullptr;
}

// Función que calcula la distancia euclidiana entre 2 puntos
double distance(const vector<double>& point1, const vector<double>& point2){
    if(point1.size() != point2.size())  throw invalid_argument( "points size not equal" );

    double sum=0;

    for(int i=0; i< point1.size();++i)
        sum += (point1[i]-point2[i]) * (point1[i]-point2[i]);

    return sqrt(sum);
}

// Función para encontrar el punto más cercano recursivamente
KDNode* KDTree::findNearest_rec(KDNode* current, const vector<double>& q,KDNode* best,int& cost){
    if (current == nullptr) return best;

    //Actualizar coste
    cost+=1;

    // Decide si buscar en el subárbol izquierdo o derecho
    KDNode* nextBranch = (q[current->discriminant] < current->point[current->discriminant]) ? current->left : current->right;
    KDNode* otherBranch = (nextBranch == current->left) ? current->right : current->left;

    // Realiza la búsqueda en el subárbol elegido
    best = findNearest_rec(nextBranch, q, best,cost);

    // Calcula la distancia entre el punto actual y Q
    double currentDist = distance(current->point, q);
    double bestDist = distance(best->point, q);

    // Compara y actualiza el punto más cercano si es necesario
    if (currentDist < bestDist)
        best = current;

    // Verifica si es necesario buscar en el otro subárbol
    if (abs(q[current->discriminant] - current->point[current->discriminant]) < bestDist) {
        best = findNearest_rec(otherBranch, q, best,cost);
    }

    return best;
}

// Función para encontrar el punto más cercano
KDNode* KDTree::findNearest(const vector<double>& q,int &cost){
    return findNearest_rec(root,q,root,cost);
}

// Función para mostrar el arbol k-d
void KDTree::print2DUtil(KDNode* root, int space,int count,bool left){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += count;

    // Process right child first
    print2DUtil(root->left, space,count,true);

    // Print current node after space
    for (int i = count; i < space; i++)
        cout << " ";
    if(left)cout<<"/";
    else cout<<"\\";
    cout << root->getName() << "\n";

    // Process left child
    print2DUtil(root->right, space,count,false);
}


// Función para mostrar el arbol k-d
void KDTree::print() {
    print2DUtil(root, 0,20,true);
}
