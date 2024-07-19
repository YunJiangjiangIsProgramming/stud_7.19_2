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

        // �����������������Ƿ�Ϊ�ն���Ҫ�������
        if (root->left) {
            str += "(" + tree2str(root->left) + ")";
        }
        else if (root->right) {
            // ���������Ϊ�գ�����������Ϊ�գ�����Ҫ���һ���յ����Ŷ�
            str += "()";
        }

        // ������������ֻ�е���������Ϊ��ʱ���������
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
    // ����������ڶ������Ĳ������
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        // ���ڴ洢���ս���Ķ�ά����
        vector<vector<int>> vv;

        // ʹ�ö��������в������
        queue<TreeNode*> q;

        // ������ڵ㲻Ϊ�գ��򽫸��ڵ����
        if (root)
        {
            q.push(root);
        }

        // �����в�Ϊ��ʱ����������
        while (!q.empty())
        {
            // ��ȡ��ǰ��Ľڵ���
            size_t  size = q.size();

            // ���ڴ洢��ǰ��Ľڵ�ֵ
            vector<int> v;

            // ������ǰ������нڵ�
            while (size--)
            {
                // ��ȡ����front�˵Ľڵ�
                TreeNode* node = q.front();

                // ���ڵ��ֵ��ӵ���ǰ��Ľ��������
                v.push_back(node->val);

                // ���ڵ�Ӷ����е���
                q.pop();

                // ������ӽڵ㲻Ϊ�գ��������
                if (node->left)
                {
                    q.push(node->left);
                }

                // ������ӽڵ㲻Ϊ�գ��������
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            // ����ǰ��Ľ��������ӵ����ս���Ķ�ά������
            vv.push_back(v);
        }

        // �������յĲ���������
        return vv;
    }
};
//����һ��vv
class Solution4 {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {

        // ���ڴ洢���ս���Ķ�ά����
        vector<vector<int>> vv;

        // ʹ�ö��������в������
        queue<TreeNode*> q;

        // ������ڵ㲻Ϊ�գ��򽫸��ڵ����
        if (root)
        {
            q.push(root);
        }

        // �����в�Ϊ��ʱ����������
        while (!q.empty())
        {
            // ��ȡ��ǰ��Ľڵ���
            size_t  size = q.size();

            // ���ڴ洢��ǰ��Ľڵ�ֵ
            vector<int> v;

            // ������ǰ������нڵ�
            while (size--)
            {
                // ��ȡ����front�˵Ľڵ�
                TreeNode* node = q.front();

                // ���ڵ��ֵ��ӵ���ǰ��Ľ��������
                v.push_back(node->val);

                // ���ڵ�Ӷ����е���
                q.pop();

                // ������ӽڵ㲻Ϊ�գ��������
                if (node->left)
                {
                    q.push(node->left);
                }

                // ������ӽڵ㲻Ϊ�գ��������
                if (node->right)
                {
                    q.push(node->right);
                }
            }

            // ����ǰ��Ľ��������ӵ����ս���Ķ�ά������
            vv.push_back(v);
        }

        reverse(vv.begin(), vv.end());
        return vv;
    }
};
//������Ĺ�������
//bool pInLeft,pInRight,qInLeft,qInRight;����дһ���Ӿ�֪�����ж�pq�������ĸ�����,�������Ҫ
//����ⷨȱ��Ҳ������ ���ǵݹ�̫��Ч�ʴ���ۿ�


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
//  ������������ת��Ϊѭ��˫������
class Solution6 {
public:
    
    Node* treeToDoublyList(Node* root) {
        // ������ڵ�Ϊ�գ��򷵻ؿ�
        if (root == nullptr) return nullptr;

        // �����������������˫������
        dfs(root);

        // ����ͷ����β����ʹ���Ϊѭ������
        head->left = pre;
        pre->right = head;

        // ���������ͷ��
        return head;
    }

private:
    // pre ���ڼ�¼ǰһ���ڵ㣬head ���ڼ�¼�����ͷ��
    Node* pre, * head;

    // ��������ĵݹ麯��
    void dfs(Node* cur) {
        // �����ǰ�ڵ�Ϊ�գ�ֱ�ӷ���
        if (cur == nullptr) return;

        // �ݹ����������
        dfs(cur->left);

        // ���ǰһ���ڵ㲻Ϊ�գ���ǰһ���ڵ����ָ��ָ��ǰ�ڵ�
        if (pre != nullptr) pre->right = cur;
        // ���ǰһ���ڵ�Ϊ�գ�˵����ǰ�ڵ��������ͷ��
        else head = cur;

        // ��ǰ�ڵ����ָ��ָ��ǰһ���ڵ�
        cur->left = pre;
        // ���� pre Ϊ��ǰ�ڵ�
        pre = cur;

        // �ݹ����������
        dfs(cur->right);
    }
};
int main()
{

	return 0;
}