#include "../../lib/doctest.h"
#include "TreeNode.hpp"

int sum(TreeNode<int> *root) {
    if (root == nullptr) {
        return 0;
    }

    return root->value + sum(root->left) + sum(root->right);
}

TEST_CASE ("sum tree") {
    TreeNode<int> *tree =
        new IntNode(10,
             new IntNode(4,
                 new IntNode(1),
                 new IntNode(3)),
             new IntNode(15,
                 new IntNode(12)));

    CHECK(45 == sum(tree));
}
