#pragma once
#include "../assignment_02/src/Node.h"
class avl_tree {
public:
    Node* root;
    int height(Node*);
    int difference(Node*);
    Node* rr_rotat(Node*);
    Node* ll_rotat(Node*);
    Node* lr_rotat(Node*);
    Node* rl_rotat(Node*);
    Node* balance(Node*);
    Node* insert(Node*,int);
    void show();
    void _LNR(Node*);
    void LNR();
    void preorder(Node*);
    void postorder(Node*);
    void print();
    avl_tree();
    private: 
        void print__private(Node* node);
        void _show(Node*, int);
};