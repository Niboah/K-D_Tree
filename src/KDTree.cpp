#include "KDTree.h"

using namespace std;

KDNode::KDNode(const vector<double>& p) : point(p), left(nullptr), right(nullptr) {}

string KDNode::getName(){
    string name="";
    for(double p:point)
        name+=" "+ to_string(p);
    return name;
}

KDTree::KDTree() : root(nullptr) {}

// Función para insertar un punto en el árbol k-d
KDNode* KDTree::insert(KDNode* node, const vector<double>& point, int depth) {
    if (node == nullptr)
        return new KDNode(point);

    int k = point.size();
    int cd = depth % k;

    // Comparar puntos en función de la dimensión actual
    if (point[cd] < node->point[cd]) {
        node->left = insert(node->left, point, depth + 1);
    } else {
        node->right = insert(node->right, point, depth + 1);
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
void KDTree::insert(const vector<double>& point) {
    root = insert(root, point, 0);
}

// Función para destruir el árbol k-d
void KDTree::destroy() {
    destroyTree(root);
    root = nullptr;
}

// Función que calcula la distancia euclidiana entre 2 puntos
double KDTree::distance(const vector<double>& point1, const vector<double>& point2){
    if(point1.size() != point2.size())  throw invalid_argument( "points size not equal" );

    double sum=0;

    for(int i=0; i< point1.size();++i)
        sum += (point1[i]-point2[i]) * (point1[i]-point2[i]);

    return sqrt(sum);
}

// Función para encontrar el punto más cercano recursivamente
KDNode* KDTree::findNearest_rec(KDNode* root, const vector<double>& q,KDNode* best, int depth){
    if (root == nullptr) return best;

    // Calcula la distancia entre el punto actual y Q
    double currentDist = distance(root->point, q);
    double bestDist = distance(best->point, q);

    // Compara y actualiza el punto más cercano si es necesario
    if (currentDist < bestDist) {
        best = root;
    }

    // Elige la siguiente dimensión para dividir el espacio
    int k = root->point.size();
    int dimension = depth % k;

    // Decide si buscar en el subárbol izquierdo o derecho
    KDNode* nextBranch = (q[dimension] < root->point[dimension]) ? root->left : root->right;
    KDNode* otherBranch = (nextBranch == root->left) ? root->right : root->left;

    // Realiza la búsqueda en el subárbol elegido
    best = findNearest_rec(nextBranch, q, best, depth + 1);

    // Verifica si es necesario buscar en el otro subárbol
    if (abs(q[dimension] - root->point[dimension]) < bestDist) {
        best = findNearest_rec(otherBranch, q, best, depth + 1);
    }

    return best;

}

// Función para encontrar el punto más cercano
KDNode* KDTree::findNearest(KDNode* root, const vector<double>& q){
    return findNearest_rec(root,q,root,0);
}



// Función para mostrar el arbol k-d
void KDTree::print2DUtil(KDNode* root, int space,int count){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += count;

    // Process right child first
    print2DUtil(root->left, space,count);

    // Print current node after space
    for (int i = count; i < space; i++)
        cout << " ";
    cout << root->getName() << "\n";

    // Process left child
    print2DUtil(root->right, space,count);
}

// Función para mostrar el arbol k-d
void KDTree::print() {
    print2DUtil(root, 0,20);
}

