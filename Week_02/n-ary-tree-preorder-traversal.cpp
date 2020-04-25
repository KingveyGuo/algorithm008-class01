// 题目描述
// 给定一个 N 叉树，返回其节点值的前序遍历。

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> preorder(Node* root) {
        vector<int> rst;
        if (root == NULL)
        {
            return rst;
        }
        rst.push_back(root->val);
        for (auto node : root->children)
        {
            preorderchildren(node, rst);
        }
        return rst;
    }

    void preorderchildren(Node* root, vector<int>& rst)
    {
        if (root == NULL)
        {
            return;
        }
        rst.push_back(root->val);
        for (auto node : root->children)
        {
            preorderchildren(node, rst);
        }
    }
};

// 递归遍历即可