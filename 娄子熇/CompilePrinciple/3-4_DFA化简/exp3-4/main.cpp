#include "mindfa.h"
#include <fstream>
#include <iostream>
using namespace std;

DFA getDFA(string str);
void deserializeNFA(NFA& nfa, const string& filename) {
    ifstream inFile(filename, ios::binary);

    // 读取头尾状态的索引
    int headIndex, tailIndex;
    inFile.read(reinterpret_cast<char*>(&headIndex), sizeof(headIndex));
    inFile.read(reinterpret_cast<char*>(&tailIndex), sizeof(tailIndex));

    // 初始化 NFA
    nfa.head = nullptr;
    nfa.tail = nullptr;
    NfaState* prevState = nullptr;

    // 反序列化 NfaState
    while (inFile.peek() != EOF) {
        NfaState* currentState = new NfaState;

        // 读取状态数据
        inFile.read(reinterpret_cast<char*>(&currentState->index), sizeof(currentState->index));
        inFile.read(reinterpret_cast<char*>(&currentState->input), sizeof(currentState->input));
        inFile.read(reinterpret_cast<char*>(&currentState->chTrans), sizeof(currentState->chTrans));

        // 读取 ε 转移集合
        int epTransSize;
        inFile.read(reinterpret_cast<char*>(&epTransSize), sizeof(epTransSize));
        for (int i = 0; i < epTransSize; ++i) {
            int epState;
            inFile.read(reinterpret_cast<char*>(&epState), sizeof(epState));
            currentState->epTrans.insert(epState);
        }

        // 将当前状态链接到 NFA 链表
        if (prevState != nullptr) {
            prevState->chTrans = currentState->index;
        }

        if (nfa.head == nullptr) {
            nfa.head = currentState;
        }

        prevState = currentState;

        // 设置尾指针为最后一个状态
        if (nfa.tail == nullptr || currentState->chTrans == -1) {
            nfa.tail = currentState;
        }

        // 填充 NfaStates 数组以便与 printNFA 函数兼容
        NfaStates[currentState->index] = *currentState;  // 将状态数据填充到 NfaStates 中
    }

    inFile.close();
}

DFA getDFA(string str)
{
    /*将中缀表达式转换为后缀表达式*/
    str = infixToSuffix(str);

    /***初始化所有的数组***/
    int i, j;
    for (i = 0; i < MAX; i++)
    {

        NfaStates[i].index = i;
        NfaStates[i].input = '#';
        NfaStates[i].chTrans = -1;
    }
    for (i = 0; i < MAX; i++)
    {

        DfaStates[i].index = i;
        DfaStates[i].isEnd = false;

        for (j = 0; j < 10; j++)
        {

            DfaStates[i].Edges[j].input = '#';
            DfaStates[i].Edges[j].Trans = -1;
        }
    }

    for (i = 0; i < MAX; i++)
    {

        minDfaStates[i].index = i;
        minDfaStates[i].isEnd = false;

        for (int j = 0; j < 10; j++)
        {

            minDfaStates[i].Edges[j].input = '#';
            minDfaStates[i].Edges[j].Trans = -1;
        }
    }

    //    exp3_2 :转换NFA
    NFA n = strToNfa(str);
    printNFA(n);
    //    exp3_3: NFA转换DFA
    DFA d = nfaToDfa(n, str);
    // 打印DFA
    printDFA(d);

    return d;
}

int main()
{
    // string nfaFilePath = "nfa.dat";
    string str = "(a|b)*";
    // string str = "(1|2)*";
    // string str = "a(a|b)*aba";

    // 实验3 main.cpp一样，简单地重新走一遍实验流程3_2—>3_3->3_4
    // 打包到一个函数中，这样主函数逻辑清晰点
    DFA dfa = getDFA(str);

    // exp4: 最小化DFA
    DFA minDfa = minDFA(dfa);
    printMinDFA(minDfa);

    cout << endl;
}
