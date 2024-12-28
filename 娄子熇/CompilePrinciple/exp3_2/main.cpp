#include "regex2nfa.h"
#include <fstream>
#include <iostream>
using namespace std;

// 序列化 NFA 到文件
bool serializeNFA(const NFA& nfa, const string& filename) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        cerr << "无法打开文件进行写入" << endl;
        return;
    }
    // 写入头尾状态
    outFile.write(reinterpret_cast<const char*>(&nfa.head->index), sizeof(nfa.head->index));
    outFile.write(reinterpret_cast<const char*>(&nfa.tail->index), sizeof(nfa.tail->index));

    // 遍历所有状态，写入每个 NfaState
    NfaState* s = nfa.head;
    while (s != nullptr) {
        outFile.write(reinterpret_cast<const char*>(&s->index), sizeof(s->index));
        outFile.write(reinterpret_cast<const char*>(&s->input), sizeof(s->input));
        outFile.write(reinterpret_cast<const char*>(&s->chTrans), sizeof(s->chTrans));

        // 序列化 ε 转移集合
        int epTransSize = s->epTrans.size();
        outFile.write(reinterpret_cast<const char*>(&epTransSize), sizeof(epTransSize));
        for (int state : s->epTrans) {
            outFile.write(reinterpret_cast<const char*>(&state), sizeof(state));
        }
        // 如果有下一个状态，继续写入
        if (s->chTrans != -1) {
            s = &NfaStates[s->chTrans];
        } else {
            break;
        }
    }

    outFile.close();
    return true;
}



int main() {
    string str = "(a|b)*";
    // string str = "a(a|b)*aba";
    // string str="(a|b)*";
    // string str = "1(2|3)*234";
    str = infixToSuffix(str);
    int i;
    for (i = 0; i < MAX; i++) {

        NfaStates[i].index = i;
        NfaStates[i].input = '#';
        NfaStates[i].chTrans = -1;
    }

    // exp2: toNFA
    NFA nfa = strToNfa(str);
    //NFA
    printNFA(nfa);

    // 序列化NFA到文件
    if (
        serializeNFA(nfa, "../3-3_词法分析之NFA转换为DFA/exp3-3/nfa.dat") &&
        serializeNFA(nfa, "../3-4_DFA化简/exp3-4/nfa.dat"))
        cout << "序列化成功" << endl;

    return 0;
}
