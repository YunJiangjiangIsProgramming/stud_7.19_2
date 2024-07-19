#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
    
};
class Solution1 {
public:
    string tree2str(TreeNode* root) {
        if (root == nullptr) {
            return "";
        }

        string str = to_string(root->val);

        // 处理左子树，无论是否为空都需要添加括号
        if (root->left) {
            str += "(" + tree2str(root->left) + ")";
        }
        else if (root->right) {
            // 如果左子树为空，但右子树不为空，则需要添加一个空的括号对
            str += "()";
        }

        // 处理右子树，只有当右子树不为空时才添加括号
        if (root->right) {
            str += "(" + tree2str(root->right) + ")";
        }

        return str;
    }
};
class Solution2 {
public:
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        vector<vector<int>> vv;
        queue<TreeNode*> q;
        if (root)
        {
            q.push(root);
        }
        while (!q.empty())
        {
            size_t  size = q.size();
            vector<int> v;
            while (size--)
            {
                TreeNode* node = q.front();
                v.push_back(node->val);
                q.pop();
                if (node->left)
                {
                    q.push(node->left);

                }
                if (node->right)
                {
                    q.push(node->right);
                }

            }
            vv.push_back(v);
        }
        return vv;
    }
};
class Solution3 {
public:
    // 这个函数用于二叉树的层序遍历
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // 用于存储最终结果的二维向量
        vector<vector<int>> vv;

        // 使用队列来进行层序遍历
        queue<TreeNode*> q;

        // 如果根节点不为空，则将根节点入队
        if (root)
        {
            q.push(root);
        }

        // 当队列不为空时，继续遍历
        while (!q.empty())
        {
            // 获取当前层的节点数
            size_t  size = q.size();

            // 用于存储当前层的节点值
            vector<int> v;

            // 遍历当前层的所有节点
            while (size--)
            {
                // 获取队列front端的节点
                TreeNode* node = q.front();

                // 将节点的值添加到当前层的结果向量中
                v.push_back(node->val);

                // 将节点从队列中弹出
                q.pop();

                // 如果左子节点不为空，则将其入队
                if (node->left)
                {
                    q.push(node->left);
                }

                // 如果右子节点不为空，则将其入队
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            // 将当前层的结果向量添加到最终结果的二维向量中
            vv.push_back(v);
        }

        // 返回最终的层序遍历结果
        return vv;
    }
};
//逆置一下vv
class Solution4 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        // 用于存储最终结果的二维向量
        vector<vector<int>> vv;

        // 使用队列来进行层序遍历
        queue<TreeNode*> q;

        // 如果根节点不为空，则将根节点入队
        if (root)
        {
            q.push(root);
        }

        // 当队列不为空时，继续遍历
        while (!q.empty())
        {
            // 获取当前层的节点数
            size_t  size = q.size();

            // 用于存储当前层的节点值
            vector<int> v;

            // 遍历当前层的所有节点
            while (size--)
            {
                // 获取队列front端的节点
                TreeNode* node = q.front();

                // 将节点的值添加到当前层的结果向量中
                v.push_back(node->val);

                // 将节点从队列中弹出
                q.pop();

                // 如果左子节点不为空，则将其入队
                if (node->left)
                {
                    q.push(node->left);
                }

                // 如果右子节点不为空，则将其入队
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            // 将当前层的结果向量添加到最终结果的二维向量中
            vv.push_back(v);
        }

        reverse(vv.begin(), vv.end());
        return vv;
    }
};
//找最近的公共祖先
//bool pInLeft,pInRight,qInLeft,qInRight;这样写一下子就知道是判断pq在左右哪个子树,这个很重要
//这个解法缺点也很明显 就是递归太深效率大打折扣


class Solution5 {
public:
    bool Find(TreeNode* root, TreeNode* x)
    {
        if (root == nullptr)
        {
            return false;
        }
        return root == x
            || Find(root->left, x)
            || Find(root->right, x);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (root == p || root == q)
        {
            return root;
        }
        bool pInLeft, pInRight, qInLeft, qInRight;
        pInLeft = Find(root->left, p);
        pInRight = !pInLeft;
        qInLeft = Find(root->left, q);
        qInRight = !qInLeft;
        if ((pInLeft && qInRight) || (pInRight && qInLeft))
        {
            return root;
        }
        else if (pInLeft && qInLeft)
        {
            return lowestCommonAncestor(root->left, p, q);
        }
        else
        {
            return lowestCommonAncestor(root->right, p, q);
        }

    }
};
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
//  将二叉搜索树转换为循环双向链表
class Solution6 {
public:
    
    Node* treeToDoublyList(Node* root) {
        // 如果根节点为空，则返回空
        if (root == nullptr) return nullptr;

        // 进行中序遍历，构建双向链表
        dfs(root);

        // 连接头部和尾部，使其成为循环链表
        head->left = pre;
        pre->right = head;

        // 返回链表的头部
        return head;
    }

private:
    // pre 用于记录前一个节点，head 用于记录链表的头部
    Node* pre, * head;

    // 中序遍历的递归函数
    void dfs(Node* cur) {
        // 如果当前节点为空，直接返回
        if (cur == nullptr) return;

        // 递归遍历左子树
        dfs(cur->left);

        // 如果前一个节点不为空，则将前一个节点的右指针指向当前节点
        if (pre != nullptr) pre->right = cur;
        // 如果前一个节点为空，说明当前节点是链表的头部
        else head = cur;

        // 当前节点的左指针指向前一个节点
        cur->left = pre;
        // 更新 pre 为当前节点
        pre = cur;

        // 递归遍历右子树
        dfs(cur->right);
    }
};
int main()
{

	return 0;
}