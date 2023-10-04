#include "KDTree.h"

using namespace std;

KDNode::KDNode(const vector<double>& p) : point(p), left(nullptr), right(nullptr) {}

string KDNode::getName(){
    string name="cood:";
    for(double p:point){
        name+=" "+ to_string(p);
    }
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
void KDTree::insert(string name, const vector<double>& point) {
    root = insert(root, point, 0);
}

// Función para destruir el árbol k-d
void KDTree::destroy() {
    destroyTree(root);
    root = nullptr;
}

// Función para mostrar el arbol k-d
void KDTree::print2DUtil(KDNode* root, int space, vector<vector<string>>&out,int &col,int count){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += count;

    // Process right child first
    print2DUtil(root->left, space,out,col,count);

    // Print current node after space
    for (int i = count; i < space; i++)
        cout << " ";

    cout << root->getName() << "\n";
    out[space][col++]=root->getName();

    // Process left child
    print2DUtil(root->right, space,out,col,count);
}

int alturaArbol(KDNode* root) {
    if (root == NULL) {
        return 1; // Si el árbol está vacío, la altura es 0
    } else {
        // Recursivamente calculamos la altura de los subárboles izquierdo y derecho
        int alturaIzquierdo = alturaArbol(root->left);
        int alturaDerecho = alturaArbol(root->right);

        // La altura del árbol es el máximo de las alturas de los subárboles más 1
        return 1 + max(alturaIzquierdo, alturaDerecho);
    }
}

// Función para mostrar el arbol k-d
void KDTree::print(int n) {
    int count=20;
    int h=alturaArbol(root);
    vector<vector<string>> out(count*(h),vector<string>(n," "));
    int col=0;
    print2DUtil(root, 0,out,col,count);
    cout<<"---------------------"<<endl;
    for(int i=0;i<out.size();i+=count){
        for(int j=0;j<out[i].size();j++){
            cout<<out[i][j];
        }
        cout<<endl;
    }
}

