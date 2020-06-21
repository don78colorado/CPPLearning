#include <iostream>

struct btree_node
{
    int data;
    btree_node *left_child = NULL;
    btree_node *right_child = NULL;
};

namespace blah
{
    btree_node *insert(btree_node *node, int data)
    {
        if (node == NULL)
        {
            btree_node *newNode = new btree_node;
            newNode->data = data;
            return newNode;
        }
        if (data > node->data)
        {
            node->right_child = insert(node->right_child, data);
        }
        else {
            node->left_child = insert(node->left_child, data);
        }
        return node;
    }
} // namespace blah

class btree
{
    btree_node *root_node = NULL;

public:
    virtual void insert(int data);
    btree_node *getRootNode() { return root_node; }

protected:
    void setRootNode(btree_node *node) { root_node = node; }
};

void btree::insert(int data)
{
    btree_node *newNode = new btree_node;
    newNode->data = data;
    if (root_node == NULL)
    {
        root_node = newNode;
    }
}

class bst : public btree
{
public:
    virtual void insert(int data);
};

void bst::insert(int data)
{
    setRootNode(blah::insert(getRootNode(), data));
}

void inOrder(const btree_node *node)
{
    if (node != NULL)
    {
        inOrder(node->left_child);
        std::cout << node->data << std::endl;
        inOrder(node->right_child);
    }
}

int main()
{
    bst myTree;
    myTree.insert(5);
    myTree.insert(15);
    myTree.insert(35);
    myTree.insert(32);
    myTree.insert(22);
    inOrder(myTree.getRootNode());
    return 0;
}