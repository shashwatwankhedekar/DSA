// https://www.geeksforgeeks.org/batch/test-series-bundle/track/amazon-linkedlists/problem/remove-duplicates-from-an-unsorted-linked-list

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

void print(Node *root)
{
    Node *temp = root;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution
{
public:
    Node *removeDuplicates(Node *head)
    {
        unordered_set<int> seen;
        Node *current = head;

        if (current == NULL)
        {
            return head;
        }
        else
        {
            seen.insert(current->data);
        }

        // run loop till end of list
        while (current != NULL && current->next != NULL)
        {
            if (seen.find(current->next->data) != seen.end())
            { // check if element already in set
                // same
                current->next = current->next->next; // skip this duplicate element
            }
            else
            { // if not already present in list then add it into list
                seen.insert(current->next->data);
                current = current->next;
            }
        }
        return head;
    }
};

//{ Driver Code Starts.

int main()
{
    // your code goes here
    int T;
    cin >> T;

    while (T--)
    {
        int K;
        cin >> K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for (int i = 0; i < K; i++)
        {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        Node *result = ob.removeDuplicates(head);
        print(result);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends