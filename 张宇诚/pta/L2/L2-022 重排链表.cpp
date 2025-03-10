#include <bits/stdc++.h>

using namespace std;

string head;
int N;
struct Node
{
    string cur;
    string next;
    int data;
};
map<string, Node> mp;
map<int, Node> mp2;

int main()
{
    cin >> head >> N;
    for (int i = 0; i < N; i ++)
    {
        string Address;
        int Data;
        string Next;
        cin >> Address >> Data >> Next;
        Node node;
        node.next = Next;
        node.data = Data;
        mp[Address] = node;
    }

    string curNode = head;
    int curPos = 0;
    while (curNode != "-1")
    {
        Node &node = mp[curNode];
        Node newNode;
        newNode.cur = curNode;
        newNode.next = node.next;
        newNode.data = node.data;
        mp2[curPos ++] = newNode;
        curNode = node.next;
    }
    for(int i = 0; i < curPos / 2; i ++)
    {
        Node &curNode = mp2[curPos - i - 1];
        Node &nextNode = mp2[i];
        if (i != 0)
        {
            cout << curNode.cur << endl;
        }
        cout << curNode.cur << " " << curNode.data << " " << nextNode.cur << endl;
        cout << nextNode.cur << " " << nextNode.data << " ";
    }
    if (curPos % 2 == 1)
    {
        Node &curNode = mp2[curPos / 2];
        cout << curNode.cur << endl;
        cout << curNode.cur << " " << curNode.data << " -1" << endl;
    }
    else 
    {
        cout << "-1" << endl;
    }
    
    return 0;
}