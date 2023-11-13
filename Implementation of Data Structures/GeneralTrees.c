#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* firstChild;
    struct TreeNode* nextSibling;
};

struct TreeNode* createTreeNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

void addChild(struct TreeNode* parent, struct TreeNode* child) {
    if (parent->firstChild == NULL) {
        parent->firstChild = child;
    } else {
        struct TreeNode* temp = parent->firstChild;
        while (temp->nextSibling != NULL) {
            temp = temp->nextSibling;
        }
        temp->nextSibling = child;
    }
}

void depthFirstTraversal(struct TreeNode* node) {
    if (node == NULL) {
        return;
    }

    printf("%d ", node->data);

    depthFirstTraversal(node->firstChild);
    depthFirstTraversal(node->nextSibling);
}

int main() {
    struct TreeNode* root = createTreeNode(1);
    struct TreeNode* child1 = createTreeNode(2);
    struct TreeNode* child2 = createTreeNode(3);
    struct TreeNode* child3 = createTreeNode(4);
    struct TreeNode* child4 = createTreeNode(5);

    addChild(root, child1);
    addChild(root, child2);
    addChild(child2, child3);
    addChild(root, child4);

    printf("Depth-First Traversal: ");
    depthFirstTraversal(root);
    printf("\n");

    return 0;
}




