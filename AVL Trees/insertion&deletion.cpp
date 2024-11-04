#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    Node *left;
    Node *right;
    int height;
};

int height(Node *N)
{
    if (N == NULL)
        return 0;
    return N->height;
}

int getBalance(Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

Node* createNode(Node *root, int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}


Node* rightRotate(Node *y){
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height =  max(height(y->left), height(y->right)) + 1;
    x->height =  max(height(x->left), height(x->right)) + 1;

    return x;
}


Node* leftRotate(Node *x){
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height =  max(height(x->left), height(x->right)) + 1;
    y->height =  max(height(y->left), height(y->right)) + 1;

    return y;
}


Node* insert(Node* root,int key){
    if(root == NULL){
        return createNode(root, key);
    }

    if(key < root->key){
        root->left = insert(root->left, key);
    }else if(key > root->key){
        root->right = insert(root->right, key);
    }else{
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && key < root->left->key){
        return rightRotate(root);
    }

    if(balance < -1 && key > root->right->key){
        return leftRotate(root);
    }

    if(balance > 1 && key > root->left->key){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && key < root->right->key){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;

}


Node* minValueNode(Node* root){
    Node* current = root;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}


Node* deleteNode(Node* root, int key){
    if(root == NULL){
        return root;
    }

    if(key < root->key){
        root->left = deleteNode(root->left, key);
    }else if(key > root->key){
        root->right = deleteNode(root->right, key);
    }else{
        if(root->left == NULL || root->right == NULL){
            Node* temp = root->left ? root->left : root->right;

            if(temp == NULL){
                temp = root;
                root = NULL;
            }else{
                *root = *temp;
            }
            free(temp);
        }else{
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if(root == NULL){
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    int balance = getBalance(root);

    if(balance > 1 && getBalance(root->left) >= 0){
        return rightRotate(root);
    }

    if(balance > 1 && getBalance(root->left) < 0){
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if(balance < -1 && getBalance(root->right) <= 0){
        return leftRotate(root);
    }

    if(balance < -1 && getBalance(root->right) > 0){
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}


void preOrder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 10); 
    root = insert(root, 20); 
    root = insert(root, 30); 
    root = insert(root, 40); 
    root = insert(root, 50); 
    root = insert(root, 25); 

    cout << "Preorder traversal of the constructed AVL tree is \n";
    preOrder(root);


    return 0;
}