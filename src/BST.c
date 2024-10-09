#include "../include/BST.h"

int order(char *str) {
    int res = 0;
    int l = strlen(str);
    int i = 0;
    while (i < l) {
        res *= 1000;
        res += (int)str[i];
        i++;
    }

    return res;
}

BST *createNewNode(Data data) {
    BST *temp = (BST *)malloc(sizeof(BST));

    if (temp == NULL) {
        fprintf(stderr, "ERROR: fail to allocate memory for BST structure\n");
        exit(EXIT_FAILURE);
    }

    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

BST *insert(BST *root, Data data) {
    if (root == NULL) {
        root = createNewNode(data);
    }

    if (data.key < root->data.key) {
        root->left = insert(root->left, data);
    }

    if (data.key > root->data.key) {
        root->right = insert(root->right, data);
    }
    return root;
}

BST *search(BST *root, int key) {
    if (root == NULL || root->data.key == key) {
        return root;
    }

    if (key < root->data.key) {
        return search(root->left, key);
    }

    return search(root->right, key);
}

BST *findMin(BST *root) {
    if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

BST *findMax(BST *root) {
    if (root->right == NULL) {
        return root;
    } else {
        return findMax(root->right);
    }
}

BST *delete(BST *root, int key) {
    if (root == NULL) {
        return NULL;
    }

    if (key > root->data.key) {
        root->right = delete (root->right, key);
        return root;
    } else if (key < root->data.key) {
        root->left = delete (root->left, key);
        return root;
    }

    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            BST *temp = root->left == NULL ? root->right : root->left;
            free(root);
            return temp;
        }

        else {
            BST *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete (root->right, root->data.key);
            return root;
        }

        return root;
    }
}

int maxDepth(BST *root) {
    if (root == NULL) {
        return 0;
    } else {
        int tempL = maxDepth(root->left);
        int tempR = maxDepth(root->right);
        return (tempL > tempR ? tempL : tempR) + 1;
    }
}

void collapseTree(BST *root) {
    if (root->left != NULL) {
        collapseTree(root->left);
    }
    if (root->right != NULL) {
        collapseTree(root->right);
    }

    free(root);
    return;
}