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

Node *createNode(Node *root, int key)
{
    Node *newNode = new Node();
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}

Node *rightRotate(Node *A)
{
    Node *B = A->left;
    Node *C = B->right;

    B->right = A;
    A->left = C;

    A->height = max(height(A->left), height(A->right)) + 1;
    B->height = max(height(B->left), height(B->right)) + 1;

    return B;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

Node *balanceTree(Node *root)
{
    if (root == NULL)
        return root;
    int balance = getBalance(root);

    if (balance > 1 && getBalance(root->left) >= 0)
    {
        return rightRotate(root);
    }

    if (balance > 1 && getBalance(root->left) < 0)
    {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }

    if (balance < -1 && getBalance(root->right) <= 0)
    {
        return leftRotate(root);
    }

    if (balance < -1 && getBalance(root->right) > 0)
    {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

Node *insert(Node *root, int key)
{
    if (root == NULL)
    {
        return createNode(root, key);
    }

    if (key < root->key)
    {
        root->left = insert(root->left, key);
    }
    else if (key > root->key)
    {
        root->right = insert(root->right, key);
    }
    else
    {
        return root;
    }

    root->height = 1 + max(height(root->left), height(root->right));

    return balanceTree(root);
}

Node *minValueNode(Node *root)
{
    Node *current = root;
    while (current->left != NULL)
    {
        current = current->left;
    }
    return current;
}


Node *findRightest(Node *root)
{
    if (root->right == nullptr)
        return root;
    return findRightest(root->right);
}
Node *helper(Node *root)
{
    if (root->left == NULL)
        return root->right;
    else if (root->right == NULL)
        return root->left;
    Node *rightChild = root->right;
    Node *extremeRightNode = findRightest(root->left);
    extremeRightNode->right = rightChild;
    return root->left;
}

Node *deleteNode(Node *root, int key)
{
    // your code goes here
    if (root == NULL)
        return NULL;
    if (root->key == key)
    {
        return helper(root);
    }
    Node *temp = root;
    while (root != NULL)
    {
        if (root->key <= key)
        {
            if (root->right != NULL && root->right->key == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
        else
        {
            if (root->left != NULL && root->left->key == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
    }
    return temp;
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

    root = deleteNode(root, 20);

    cout << "\nPreorder traversal after deletion of 20 \n";
    preOrder(root);

    return 0;
}