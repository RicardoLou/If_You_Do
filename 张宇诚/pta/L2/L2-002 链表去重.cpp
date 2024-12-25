#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int key;
    string link;
};

int main()
{
    string head;
    int N;
    cin >> head;
    cin >> N;

    map<string, Node> link_list;

    for(int i = 0; i < N; i ++)
    {
        string addr, link;
        int key;
        cin >> addr;
        cin >> key;
        cin >> link;
        Node node;
        node.key = key;
        node.link = link;
        link_list[addr] = node;
    }

    string cur_link = head;
    vector<int> exist_key;
    vector<string> del_links;

    while(cur_link != "-1")
    {
        Node node = link_list[cur_link];
        int key = node.key;
        if(find(exist_key.begin(), exist_key.end(), abs(key)) != exist_key.end())
        {
            del_links.push_back(cur_link);
        }
        else {
            if(cur_link == head)
            {
                cout << head << " " << key << " ";
            }
            else {
                cout << cur_link << "\n" << cur_link << " " << key << " ";
            }
            exist_key.push_back(abs(key));
        }
        cur_link = node.link;
    }

    cout << "-1" << std::endl;

    for(int i = 0; i < del_links.size(); i ++)
    {
        string addr = del_links[i];
        int key = link_list[addr].key;
        string link = "-1";
        if(i != del_links.size() - 1)
        {
            link = del_links[i + 1];
        }
        cout << addr << " " << key << " " << link << endl;
    }
    
    return 0;
}
