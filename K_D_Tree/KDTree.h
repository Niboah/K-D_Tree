//
// Created by 15ARCH6H on 27/09/2023.
//

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

        KDNode(const vector<double>& p);

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

    public:
        KDTree();

        // Función para insertar un punto en el árbol k-d
        void insert(string name, const vector<double>& point);

        // Función para destruir el árbol k-d
        void destroy();

        // Función para mostrar el árbil k-d
        void print(int n);

        KDNode* getRoot() {return root;}
};


#endif //K_D_TREE_KDTREE_H
