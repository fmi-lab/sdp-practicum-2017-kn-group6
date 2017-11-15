#include "TreeNode.hpp"
#include "../../lib/doctest.h"

IntNode* lowest_common_ancestor(IntNode *root, IntNode* a, IntNode* b) {
    IntNode *left = a;
    IntNode *right = b;
    if (a->value > b->value) {
        left = b;
        right = a;
    }

    if (left->value <= root->value && root->value <= right->value) {
        return root;
    } else if (left->value <= root->value && root->value > right->value) {
        return lowest_common_ancestor(root->left, left, right);
    } else if (left->value > root->value && root->value <= right->value) {
        return lowest_common_ancestor(root->right, left, right);
    }

    return nullptr; // binary search tree invariant doesn't hold
}

TEST_CASE("lowest common ancestor") {
    IntNode *tree = new IntNode(10,
                                new IntNode(7,
                                            new IntNode(1),
                                            new IntNode(9,
                                                        new IntNode(8))),
                                new IntNode(13,
                                            new IntNode(12)));

    IntNode *lca1 = lowest_common_ancestor(tree, new IntNode(1), new IntNode(8));
    CHECK(lca1->value == 7);

    IntNode *lca2 = lowest_common_ancestor(tree, new IntNode(9), new IntNode(13));
    CHECK(lca2->value == 10);

    IntNode *lcaReversed = lowest_common_ancestor(tree, new IntNode(8), new IntNode(1));
    CHECK(lcaReversed->value == 7);
}
