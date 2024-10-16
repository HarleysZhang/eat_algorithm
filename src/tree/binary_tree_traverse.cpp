#include <iostream>
#include <queue>
#include <iomanip>
#include <cmath>

// 定义二叉树节点类
class TreeNode {
public:
    int value;
    TreeNode* left;
    TreeNode* right;

    // 构造函数
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// 定义二叉树类
class BinaryTree {
public:
    TreeNode* root;

    // 构造函数
    BinaryTree() : root(nullptr) {}

    // 前序遍历函数
    void preorderTraversal(TreeNode* node) const {
        if (node == nullptr) return;
        std::cout << node->value << " "; // 访问根节点
        preorderTraversal(node->left); // 前序遍历左子树
        preorderTraversal(node->right); // 前序遍历右子树
    }

    // 中序遍历函数
    void inorderTraversal(TreeNode* node) const {
        if (node == nullptr) return;
        inorderTraversal(node->left); // 中序遍历左子树
        std::cout << node->value << " "; // 访问根节点
        inorderTraversal(node->right); // 中序遍历右子树
    }

    // 后序遍历函数
    void postorderTraversal(TreeNode* node) const {
        if (node == nullptr) return;
        postorderTraversal(node->left); // 后序遍历左子树
        postorderTraversal(node->right); // 后序遍历右子树
        std::cout << node->value << " "; // 访问根节点
    }

    // 计算树的高度
    int getHeight(TreeNode* node) const {
        if (node == nullptr) return 0;
        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);
        return std::max(leftHeight, rightHeight) + 1;
    }

    // 可视化打印函数
    void printTree(TreeNode* node) const {
        if (node == nullptr) return;

        int height = getHeight(node);
        int maxNodes = std::pow(2, height) - 1;
        int maxWidth = 4 * maxNodes; // Adjust spacing for larger values

        std::queue<TreeNode*> nodes;
        nodes.push(node);

        for (int level = 0; level < height; ++level) {
            int levelNodes = std::pow(2, level);
            int spacing = maxWidth / (levelNodes + 1);
            for (int i = 0; i < levelNodes; ++i) {
                TreeNode* current = nodes.front();
                nodes.pop();

                if (current) {
                    std::cout << std::setw(spacing) << current->value;
                    nodes.push(current->left);
                    nodes.push(current->right);
                } else {
                    std::cout << std::setw(spacing) << " ";
                    nodes.push(nullptr);
                    nodes.push(nullptr);
                }
            }
            std::cout << std::endl;
        }
    }

    // 对外提供接口，遍历树
    void preorderTraversal() const {
        preorderTraversal(root);
    }

    void inorderTraversal() const {
        inorderTraversal(root);
    }

    void postorderTraversal() const {
        postorderTraversal(root);
    }

    // 对外提供接口，打印树
    void printTree() const {
        printTree(root);
    }
};

// 主函数
int main() {
    // 创建一个简单的二叉树
    BinaryTree tree;
    tree.root = new TreeNode(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);
    tree.root->right->left = new TreeNode(6);
    tree.root->right->right = new TreeNode(7);

    // 前序遍历
    std::cout << "Preorder traversal: ";
    tree.preorderTraversal();
    std::cout << std::endl;

    // 中序遍历
    std::cout << "Inorder traversal: ";
    tree.inorderTraversal();
    std::cout << std::endl;

    // 后序遍历
    std::cout << "Postorder traversal: ";
    tree.postorderTraversal();
    std::cout << std::endl;

    // 打印二叉树
    std::cout << "Binary Tree:" << std::endl;
    tree.printTree();

    return 0;
}
