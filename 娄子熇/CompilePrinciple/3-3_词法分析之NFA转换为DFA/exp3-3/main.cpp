#include "nfa2dfa.h"
#include <fstream>
#include <iostream>
using namespace std;
#define cast(x) ((char*)(x))

NFA getNFA(string str)
{
    // 将中缀表达式转换为后缀表达式
    str = infixToSuffix(str);

    // 初始化 NFA 状态数组
    int i;
    for (i = 0; i < MAX; i++)
    {
        NfaStates[i].index = i;
        NfaStates[i].input = '#';
        NfaStates[i].chTrans = -1;
    }

    // 将正则表达式转为 NFA
    NFA n = strToNfa(str);
    printNFA(n);
    return n;
}

// 反序列化 NFA 从文件
// modify
void deserializeNFA(NFA& nfa, const string& filename) {
    ifstream inFile(filename, ios::binary);
    // 读取头尾状态的索引
    int headIndex, tailIndex;
    inFile.read(cast(&headIndex), sizeof(headIndex));
    inFile.read(cast(&tailIndex), sizeof(tailIndex));

    // 初始化 NFA
    nfa.head = nullptr;
    nfa.tail = nullptr;
    NfaState* ps = nullptr;

    // 反序列化 NfaState
    while (inFile.peek() != EOF) {
        NfaState* s = new NfaState;
        // 读取状态数据
        inFile.read(cast(&s->index), sizeof(s->index));
        inFile.read(cast(&s->input), sizeof(s->input));
        inFile.read(cast(&s->chTrans), sizeof(s->chTrans));
        // 读取 ε 转移集合
        int size;
        inFile.read(cast(&size), sizeof(size));
        for (int i = 0; i < size; ++i) {
            int epState;
            inFile.read(cast(&epState), sizeof(epState));
            s->epTrans.insert(epState);
        }
        // 将当前状态链接到 NFA 链表
        if (ps != nullptr) 
            ps->chTrans = s->index;
        if (nfa.head == nullptr) 
            nfa.head = s;
        ps = s;
        // 设置尾指针为最后一个状态
        if (nfa.tail == nullptr || s->chTrans == -1) {
            nfa.tail = s;
        }
        // 填充 NfaStates 数组以便与 printNFA 函数兼容
        NfaStates[s->index] = *s;  // 将状态数据填充到 NfaStates 中
    }
    inFile.close();
}

int main()
{
    // 设定 NFA 文件路径
    string nfaFilePath = "nfa.dot";
   //string str = "(a|b*)c*";
    // string str = "(1|2)*";
    string str = "(a|b)*";
     // string str = "a(a|b)*b";
    NFA nfa;

    ifstream infile1(nfaFilePath, ios::binary);
    if (infile1.good())
    {
        deserializeNFA(nfa, nfaFilePath);
    }
    else {
        nfa = getNFA(str);
    }
    // NFA 转换为 DFA
    for (int i = 0; i < MAX; i++)
    {
        DfaStates[i].index = i;
        DfaStates[i].isEnd = false;
        for (int j = 0; j < 10; j++)
        {
            DfaStates[i].Edges[j].input = '#';
            DfaStates[i].Edges[j].Trans = -1;
        }
    }
    // exp3: NFA 转 DFA
    DFA d = nfaToDfa(nfa, str);
    // 打印 DFA
    printDFA(d);

    return 0;
}