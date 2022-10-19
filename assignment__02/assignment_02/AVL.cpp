#include "AVL.h"
#include <iostream>

using namespace std;

avl_tree::avl_tree() {
    root = NULL;
}

Node* avl_tree::insert(Node* r, int v) {

    if (r == NULL) {
        r = new Node;
        r->data = v;
        r->left = NULL;
        r->right = NULL;
        return r;
    }
    else if (v < r->data) {
        r->left = insert(r->left, v);
        r = balance(r);
    }
    else if (v >= r->data) {
        r->right = insert(r->right, v);
        r = balance(r);
    } return r;
}

//int avl_tree::insert(int x) {
//    Node* currNode = root;
//    Node* r = root;
//    while (currNode) {
//        r = currNode;
//        if (x < currNode->data) {
//            currNode = currNode->left;
//            r = balance(r);
//        }
//            
//        else {
//            currNode = currNode->right;
//            r = balance(r);
//        }
//            
//    }
//
//    if (!r)
//        root = new Node(x);
//    else {
//        currNode = new Node(x);
//        if (x < r->data) {
//            r->left = currNode;
//            
//        }
//            
//        else {
//            r->right = currNode;
//            //r = balance(currNode);
//        }
//           
//    };
//    cout << x << "Thuong dz" << endl;
//    return 1;
//}

void avl_tree::print() {
    cout << "current tree\n";
    print__private(root);
}

void avl_tree::print__private(Node* node) {
    int l = 1;
    if (node) {
        cout << endl;
        cout << "Node = " << node->data << endl;
        //cout << "level = " << node->level << endl;
        //cout << "col = " << node->col << endl;
        //cout << "x = " << node->x << endl;
        //cout << "y = " << node->y << endl;
        cout << endl;
        print__private(node->left);
        print__private(node->right);
        
    }
}

int avl_tree::height(Node* node) {
    int h = 0;
    if (node != NULL) {
        int l_height = height(node->left);
        int r_height = height(node->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}
int avl_tree::difference(Node* node) {
    int l_height = height(node->left);
    int r_height = height(node->right);
    int b_factor = l_height - r_height;
    return b_factor;
}
Node* avl_tree::rr_rotat(Node* parent) {
    Node* t;
    t = parent->right;
    parent->right = t->left;
    t->left = parent;
    cout << "Right-Right Rotation" << endl;
    return t;
}
Node* avl_tree::ll_rotat(Node* parent) {
    Node* t;
    t = parent->left;
    parent->left = t->right;
    t->right = parent;
    cout << "Left-Left Rotation" << endl;
    return t;
}
Node* avl_tree::lr_rotat(Node* parent) {
    Node* t;
    t = parent->left;
    parent->left = rr_rotat(t);
    cout << "Left-Right Rotation" << endl;
    return ll_rotat(parent);
}
Node* avl_tree::rl_rotat(Node* parent) {
    Node* t;
    t = parent->right;
    parent->right = ll_rotat(t);
    cout << "Right-Left Rotation" << endl;
    return rr_rotat(parent);
}
Node* avl_tree::balance(Node* node) {
    int bal_factor = difference(node);
    if (bal_factor > 1) {
        if (difference(node->left) > 0)
            node = ll_rotat(node);
        else
            node = lr_rotat(node);
    }
    else if (bal_factor < -1) {
        if (difference(node->right) > 0)
            node = rl_rotat(node);
        else
            node = rr_rotat(node);
    }
    return node;
}
//Node* avl_tree::insert(Node* r, int v) {
//    if (r == NULL) {
//        r = new Node;
//        r->data = v;
//        r->left = NULL;
//        r->right = NULL;
//        return r;
//    }
//    else if (v < r->data) {
//        r->left = insert(r->left, v);
//        r = balance(r);
//    }
//    else if (v >= r->data) {
//        r->right = insert(r->right, v);
//        r = balance(r);
//    } return r;
//}
//void avl_tree::show() {
//    avl_tree::_show(root,1);
//}

void avl_tree::_LNR(Node* node) {
    if (node == NULL)
        return;
    cout << node->data << " ";
    _LNR(node->left);
    _LNR(node->right);
}

void avl_tree::LNR() {
    _LNR(root);
}
//void avl_tree::preorder(Node* t) {
//    if (t == NULL)
//        return;
//    cout << t->data << " ";
//    preorder(t->left);
//    preorder(t->right);
//}
//void avl_tree::postorder(Node* t) {
//    if (t == NULL)
//        return;
//    postorder(t->left);
//    postorder(t->right);
//    cout << t->data << " ";
//}

