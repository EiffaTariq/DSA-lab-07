#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

bool areIdentical(TreeNode* root1, TreeNode* root2)
{
    if (!root1 && !root2)
    {
        return true;
    }
    if (!root1 || !root2)
    {
        return false;
    }
    return (root1->val == root2->val &&
        areIdentical(root1->left, root2->left) &&
        areIdentical(root1->right, root2->right));
}

bool isSubtree(TreeNode* t1, TreeNode* t2)
{
    if (!t2)
    {
        return true;
    }
    if (!t1)
    {
        return false;
    }

    if (areIdentical(t1, t2))
    {
        return true;
    }

    return isSubtree(t1->left, t2) || isSubtree(t1->right, t2);
}

int main()
{
    TreeNode* t1 = new TreeNode(10);
    t1->left = new TreeNode(5);
    t1->right = new TreeNode(13);
    t1->left->left = new TreeNode(3);
    t1->left->right = new TreeNode(7);

    TreeNode* t2 = new TreeNode(5);
    t2->left = new TreeNode(3);
    t2->right = new TreeNode(7);

    bool result = isSubtree(t1, t2);
    cout << "Is t2 a subtree of t1? " << (result ? "Yes" : "No") << endl;
    return 0;
}