#include <bits/stdc++.h>

using namespace std;

int N;
struct Node {
    int cmd;
    double value;
    int x1, x2;
};
vector<Node> nodes;
vector<double> values;
set<int> s;

double getValue(int index)
{
    Node &node = nodes[index];
    switch(node.cmd)
    {
        case 0:
            return values[index] = node.value;
        case 1:
            return values[index] = getValue(node.x1) + getValue(node.x2);
        case 2:
            return values[index] = getValue(node.x1) - getValue(node.x2);
        case 3:
            return values[index] = getValue(node.x1) * getValue(node.x2);
        case 4:
            return values[index] = exp(getValue(node.x1));
        case 5:
            return values[index] = log(getValue(node.x1));
        case 6:
            return values[index] = sin(getValue(node.x1));
    }
}

double getPD(int index, int x)
{
    Node &node = nodes[index];
    switch(node.cmd)
    {
        case 0:
            return index == x ? 1 : 0;
        case 1:
            return getPD(node.x1, x) + getPD(node.x2, x);
        case 2:
            return getPD(node.x1, x) - getPD(node.x2, x);
        case 3:
            return getPD(node.x1, x) * values[node.x2] + values[node.x1] * getPD(node.x2, x);
        case 4:
            return values[index] * getPD(node.x1, x);
        case 5:
            return 1.0 / values[node.x1] * getPD(node.x1, x);
        case 6:
            return cos(values[node.x1]) * getPD(node.x1, x);
    }
}

int main()
{
    cin >> N;
    vector<int> X;
    values.resize(N);
    for (int i = 0; i < N; i ++)
    {
        int cmd;
        int x1, x2;
        cin >> cmd;
        Node node;
        node.cmd = cmd;
        switch(cmd)
        {
            case 0:
                double v;
                cin >> v;
                node.value = v;
                X.push_back(i);
                break;
            case 1:
            case 2:
            case 3:
                cin >> x1 >> x2;
                node.x1 = x1;
                node.x2 = x2;
                s.insert(x1);
                s.insert(x2);
                break;
            case 4:
            case 5:
            case 6:
                cin >> x1;
                node.x1 = x1;
                s.insert(x1);
                break;
        }
        nodes.push_back(node);
    }

    int end;
    for (end = 0; end < N; end ++)
    {
        if (s.find(end) == s.end()) 
            break;
    }
    
    printf("%.3f\n", getValue(end));
    for (int i = 0; i < X.size(); i ++)
    {
        printf("%.3f", getPD(end, X[i]));
        if (i != X.size() - 1)
        {
            cout << " ";
        }
    }
    
    return 0;
}