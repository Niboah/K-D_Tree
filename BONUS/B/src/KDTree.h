#ifndef K_D_TREE_KDTREE_H
#define K_D_TREE_KDTREE_H

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

// Función que calcula la distancia euclidiana entre 2 puntos
double distance(const vector<double>& point1, const vector<double>& point2);

class KDNode {
    public:
        vector<double> point;  // Coordenadas k-dimensionales
        KDNode* left;
        KDNode* right;
        int discriminant;

        // Constructora
        KDNode(const vector<double>& p,int dis);

        // Función para sacar las coordenadas
        string getName();
};

class KDTree {
    private:
        KDNode* root;

        // Función para insertar un punto en el árbol k-d
        KDNode* insert(KDNode* node, const vector<double>& point,vector<double> bb);


        //retorna la dimensio amb més que te més grandaria en la bounding box.
        int bigdimensionBB (const vector<double>& bb);


        // Función para destruir el árbol k-d
        void destroyTree(KDNode* node);

        // Función para mostrar el árbil k-d
        void print2DUtil(KDNode* root, int ,int,bool);

        // Función para encontrar el punto más cercano recursivamente
        KDNode* findNearest_rec(KDNode* root, const vector<double>& q,KDNode* best,int& cost);

    public:
        KDTree();

        // Función para insertar un punto en el árbol k-d
        void insert(const vector<double>& point);


        // Función para destruir el árbol k-d
        void destroy();

        // Función para encontrar el punto más cercano
        KDNode* findNearest(const vector<double>& q,int& cost);

        // Función para mostrar el árbil k-d
        void print();

        // Función para mostrar el árbil k-d
        void print(int n);

        KDNode* getRoot() {return root;}
};


#endif //K_D_TREE_KDTREE_H
