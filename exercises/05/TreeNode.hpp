#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class TreeNode {
public:
    T value;
    TreeNode<T>* left;
    TreeNode<T>* right;

    TreeNode(const T& _value = T(), TreeNode<T>* _left = nullptr, TreeNode<T>* _right = nullptr)
            : value(_value), left(_left), right(_right) {}
};

typedef TreeNode<int> IntNode;

#endif //TREE_NODE_H
