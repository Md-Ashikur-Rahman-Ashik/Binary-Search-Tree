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

Node *convert(int integerArray[], int arraySize, int leftIndex, int rightIndex)
{
    if (leftIndex > rightIndex)
    {
        return NULL;
    }

    int mid = (leftIndex + rightIndex) / 2;
    Node *root = new Node(integerArray[mid]);

    Node *leftOfRoot = convert(integerArray, arraySize, leftIndex, mid - 1);
    Node *rightOfRoot = convert(integerArray, arraySize, mid + 1, rightIndex);

    root->leftNode = leftOfRoot;
    root->rightNode = rightOfRoot;
    return root;
}

int main()
{
    int arraySize;
    cin >> arraySize;
    int integerArray[arraySize];
    for (int i = 0; i < arraySize; i++)
    {
        cin >> integerArray[i];
    }

    Node *root = convert(integerArray, arraySize, 0, arraySize - 1);
    printLevelOrder(root);

    return 0;
}