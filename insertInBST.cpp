#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int integerValue;
    Node *leftNode;
    Node *rightNode;

    Node(int integerValue)
    {
        this->integerValue = integerValue;
        this->leftNode = NULL;
        this->rightNode = NULL;
    }
};

Node *inputTree()
{
    int inputValue;
    cin >> inputValue;
    if (inputValue == -1)
    {
        return NULL;
    }

    Node *root = new Node(inputValue);

    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        Node *frontNode = nodeQueue.front();
        nodeQueue.pop();

        int leftValue, rightValue;
        cin >> leftValue >> rightValue;

        Node *leftOfFront, *rightOfFront;

        if (leftValue != -1)
        {
            leftOfFront = new Node(leftValue);
        }
        else
        {
            leftOfFront = NULL;
        }

        frontNode->leftNode = leftOfFront;

        if (rightValue != -1)
        {
            rightOfFront = new Node(rightValue);
        }
        else
        {
            rightOfFront = NULL;
        }

        frontNode->rightNode = rightOfFront;

        if (frontNode->leftNode)
        {
            nodeQueue.push(frontNode->leftNode);
        }

        if (frontNode->rightNode)
        {
            nodeQueue.push(frontNode->rightNode);
        }
    }

    return root;
}

void printLevelOrder(Node *root)
{
    queue<Node *> nodeQueue;
    nodeQueue.push(root);
    while (!nodeQueue.empty())
    {
        Node *frontNode = nodeQueue.front();
        nodeQueue.pop();

        cout << frontNode->integerValue << " ";

        if (frontNode->leftNode)
        {
            nodeQueue.push(frontNode->leftNode);
        }

        if (frontNode->rightNode)
        {
            nodeQueue.push(frontNode->rightNode);
        }
    }
}

void insert(Node *&root, int desiredValue)
{
    if (root == NULL)
    {
        root = new Node(desiredValue);
        return;
    }

    if (root->integerValue > desiredValue)
    {
        if (root->leftNode == NULL)
        {
            Node *newNode = new Node(desiredValue);
            root->leftNode = newNode;
        }
        else
        {
            insert(root->leftNode, desiredValue);
        }
    }
    else
    {
        if (root->rightNode == NULL)
        {
            Node *newNode = new Node(desiredValue);
            root->rightNode = newNode;
        }
        else
        {
            insert(root->rightNode, desiredValue);
        }
    }
}

int main()
{
    Node *root = inputTree();

    int desiredValue;
    cin >> desiredValue;

    insert(root, desiredValue);
    printLevelOrder(root);

    return 0;
}