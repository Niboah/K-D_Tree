#ifndef K_D_TREE_KDTREE_H
#define K_D_TREE_KDTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class KDNode {
    public:
        vector<double> point;  // Coordenadas k-dimensionales
        KDNode* left;
        KDNode* right;

        // Constructora
        KDNode(const vector<double>& p);

        // Función para sacar las coordenadas
        string getName();
};

class KDTree {
    private:
        KDNode* root;

        // Función para insertar un punto en el árbol k-d
        KDNode* insert(KDNode* node, const vector<double>& point, int depth);

        // Función para destruir el árbol k-d
        void destroyTree(KDNode* node);

        // Función para mostrar el árbil k-d
        void print2DUtil(KDNode* root, int ,int);

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
        // Función que calcula la distancia euclidiana entre 2 puntos
        double distance(const vector<double>& point1, const vector<double>& point2);

        // Función para encontrar el punto más cercano recursivamente
        KDNode* findNearest_rec(KDNode* root, const vector<double>& q,KDNode* best, int depth);

<<<<<<< HEAD
=======
>>>>>>> 136e675 (first commit)
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
    public:
        KDTree();

        // Función para insertar un punto en el árbol k-d
<<<<<<< HEAD
<<<<<<< HEAD
        void insert(const vector<double>& point);
=======
        void insert(string name, const vector<double>& point);
>>>>>>> 136e675 (first commit)
=======
        void insert(const vector<double>& point);
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0

        // Función para destruir el árbol k-d
        void destroy();

<<<<<<< HEAD
<<<<<<< HEAD
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0
        // Función para encontrar el punto más cercano
        KDNode* findNearest(KDNode* root, const vector<double>& q);

        // Función para mostrar el árbil k-d
        void print();
<<<<<<< HEAD
=======
        // Función para mostrar el árbil k-d
        void print(int n);
>>>>>>> 136e675 (first commit)
=======
>>>>>>> ff25502712ac2b69618e84fa36c3e09869117fa0

        KDNode* getRoot() {return root;}
};


#endif //K_D_TREE_KDTREE_H
