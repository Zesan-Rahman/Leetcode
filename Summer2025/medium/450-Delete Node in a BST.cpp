#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <math.h>
#include <unordered_map>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //Find the node
        bool found = false;
        TreeNode* target = root;
        TreeNode* parent = nullptr;
        while(!found && target) {
            if(target->val == key) {
                found = true;
            }
            else {
                if (target->val > key) {
                    parent = target;
                    target = target->left;
                }
                else {
                    parent = target;
                    target = target->right;
                }
            }
        }
        if(!found) return root; //There's no node to delete
        //case 1: node is a leaf
        if(!target->left && !target->right) {
            if(parent) {
                if(target == parent->left) {
                    parent->left = nullptr;
                }
                if (target == parent->right) {
                    parent->right = nullptr;
                }
            }
            else {//If there is no parent, our target was root which needs to be deleted
                root = nullptr;
            }
            return root;
        }
        //case 2: node has only left child
        if(target->left && !target->right) {
            if(parent) {
                if(target == parent->left) {
                    target = target->left;
                    parent->left = target;
                }
                if (target == parent->right) {
                    target = target->left;
                    parent->right = target;
                }
                return root;
            }
            else {//If there is no parent, our target was root and now the root is root's left, which is target
                target = target->left;
                return target;
            }
        }
        //case 3: node has only right child (Very similar to case 2)
        if(!target->left && target->right) {
            if(parent) {
                if(target == parent->left) {
                    target = target->right;
                    parent->left = target;
                }
                if (target == parent->right) {
                    target = target->right;
                    parent->right = target;
                }
                return root;
            }
            else {//If there is no parent, our target was root and now the root is root's right, which is target
                target = target->right;
                return target;
            }
        }
        //case 4: Node has both left and right child
        if(target->left && target->right) {
            TreeNode* replacement = target->left;
            parent = target;
            while (replacement->right) {
                parent = replacement;
                replacement = replacement->right;
            }
            target->val = replacement->val;
            if(replacement == parent->left) {
                if(replacement->left) {
                    parent->left = replacement->left;
                }
                else {
                    parent->left = nullptr;
                }
            }
            if(replacement == parent->right) {
                if(replacement->left) {
                    parent->right = replacement->left;
                }
                else {
                    parent->right = nullptr;
                }
            }
            return root;
        }
        return root; 
    }
};

int main() {
    TreeNode root(5);
    TreeNode child3(3);
    TreeNode child6(6);
    TreeNode child2(2);
    TreeNode child4(4);
    TreeNode child7(7);
    root.left = &child3;
    root.right = &child6;
    child3.left = &child2;
    child3.right = &child4;
    child6.right = &child7;
    Solution sol;
    sol.deleteNode(&root, 3);
}