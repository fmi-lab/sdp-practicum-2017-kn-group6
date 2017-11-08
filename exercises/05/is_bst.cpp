#include "../../lib/doctest.h"
#include "TreeNode.hpp"
#include <climits>

bool checkRange(IntNode *root, int left, int right) {
    if (root == nullptr) {
        return true;
    }

    if (left <= root->value && root->value <= right) {
        return checkRange(root->left, left, root->value) &&
               checkRange(root->right, root->value, right);
    }

    return false;
}

bool isBinarySearchTree(IntNode *root) {
    return checkRange(root, INT_MIN, INT_MAX);
}

TEST_CASE ("check if a tree is a binary search tree") {
    CHECK(!isBinarySearchTree(new IntNode(10,
                                          new IntNode(4,
                                                      new IntNode(1),
                                                      new IntNode(3)),
                                          new IntNode(15,
                                                      new IntNode(12)))));

    CHECK(!isBinarySearchTree(new IntNode(10,
                                          new IntNode(4,
                                                      new IntNode(1),
                                                      new IntNode(13)),
                                          new IntNode(15,
                                                      new IntNode(12)))));


}
