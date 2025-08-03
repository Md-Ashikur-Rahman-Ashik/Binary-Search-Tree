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

bool search(Node *root, int desiredValue)
{
    if (root == NULL)
    {
        return false;
    }
    else if (root->integerValue == desiredValue)
    {
        return true;
    }
    else if (root->integerValue > desiredValue)
    {
        bool leftSearch = search(root->leftNode, desiredValue);
        return leftSearch;
    }
    else
    {
        bool rightSearch = search(root->rightNode, desiredValue);
        return rightSearch;
    }
}

int main()
{
    Node *root = inputTree();

    int desiredValue;
    cin >> desiredValue;

    bool result = search(root, desiredValue);
    if (result == true)
    {
        cout << "The value is found";
    }
    else
    {
        cout << "The value isn't found";
    }

    return 0;
}