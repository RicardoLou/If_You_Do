// # 导入实验3的实现即可
#include "nfa2dfa.h"

/******************DFA的最小化******************/
IntSet s[MAX];                    /*划分出来的集合数组*/
DfaState minDfaStates[MAX];        /*minDfa状态数组*/

int minDfaStateNum = 0;            /*minDfa的状态总数，同时也是划分出的集合数*/

struct stateSet            /*划分状态集*/
{

    int index;            /*该状态集所能转换到的状态集标号*/
    IntSet s;            /*该状态集中的dfa状态号*/
};

/*当前划分总数为count，返回状态n所属的状态集标号i*/
int findSetNum(int count, int n) {

    for (int i = 0; i < count; i++) {
        if (s[i].count(n)) {
            return i;
        }
    }
    return 0;
}

/*最小化DFA*/
DFA minDFA(DFA d) {
    int i, j;
    cout << endl << "*************     minDFA     **************" << endl << endl;

    DFA minDfa;
    minDfa.terminator = d.terminator;  /*把dfa的终结符集赋给minDfa*/

    memset(minDfa.trans, -1, sizeof(minDfa.trans));  /*初始化minDfa转移矩阵*/

    /*第一次划分，即将终态与非终态分开*/
    bool endFlag = true;  /*判断dfa的所有状态是否全为终态的标志*/
    for (i = 0; i < dfaStateNum; i++) {  /*遍历dfa状态数组*/
        if (DfaStates[i].isEnd == false) {  /*如果该dfa状态不是终态*/
            endFlag = false;  /*标志应为false*/
            minDfaStateNum = 2;  /*第一次划分应该有两个集合*/
            s[1].insert(DfaStates[i].index);  /*把该状态的状态号加入s[1]集合中*/
        } else {  /*如果该dfa状态是终态*/
            s[0].insert(DfaStates[i].index);  /*把该状态的状态号加入s[0]集合中*/
        }
    }

    if (endFlag) {  /*如果标志为真，则所有dfa状态都是终态*/
        minDfaStateNum = 1;  /*第一次划分结束应只有一个集合*/
    }

    bool cutFlag = true;  /*上一次是否产生新的划分的标志*/
    while (cutFlag) {  /*只要上一次产生新的划分就继续循环*/
        int cutCount = 0;  /*需要产生新的划分的数量*/
        // 优化
        for (i = 0; i < minDfaStateNum; i++) {  /*遍历每个划分集合*/

            // 修改部分：使用unordered_map优化缓冲区管理
            unordered_map<int, stateSet> temp;  /*临时保存每个转移的状态集*/  // **修改部分**

            for (auto it = d.terminator.begin(); it != d.terminator.end(); ++it) {  /*遍历dfa的终结符集*/
                for (auto iter = s[i].begin(); iter != s[i].end(); ++iter) {  /*遍历集合中的每个状态号*/

                    bool epFlag = true;  /*判断该集合中是否存在没有该终结符对应的转换弧的状态*/
                    for (j = 0; j < DfaStates[*iter].edgeNum; j++) {  /*遍历该状态的所有边*/
                        if (DfaStates[*iter].Edges[j].input == *it) {  /*如果该边的输入为该终结符*/
                            epFlag = false;  /*则标志为false*/
                            int transNum = findSetNum(minDfaStateNum, DfaStates[*iter].Edges[j].Trans);
                            temp[transNum].s.insert(*iter);  /*将当前状态添加到转换目标状态集*/  // **修改部分**
                        }
                    }

                    if (epFlag) {  /*如果该状态不存在与该终结符对应的转换弧*/
                        temp[-1].s.insert(*iter);  /*不存在转换弧则归为-1集合*/  // **修改部分**
                    }
                }

                if (temp.size() > 1) {  /*如果缓冲区中的状态集个数大于1，表示同一个状态集中的元素能转换到不同的状态集，则需要划分*/
                    cutCount++;  /*划分次数加一*/

                    /*为每组划分创建新的dfa状态*/
                    for (auto& group : temp) {  /*遍历缓冲区*/  // **修改部分**
                        int setNum = group.first;
                        for (auto state : group.second.s) {  /*遍历当前划分集合中的每个状态*/
                            s[i].erase(state);  /*在原来的状态集中删除该状态*/
                            s[minDfaStateNum].insert(state);  /*在新的状态集中加入该状态*/
                        }
                    }
                    minDfaStateNum++;  /*最小化DFA状态总数加一*/
                }
            }
        }

        if (cutCount == 0) {  /*如果需要划分的次数为0，表示本次不需要进行划分*/
            cutFlag = false;
        }
    }

    /*遍历每个划分好的状态集*/
    for (i = 0; i < minDfaStateNum; i++) {
        for (auto y : s[i]) {  /*遍历集合中的每个元素*/
            if (y == d.startState) {  /*如果当前状态为dfa的初态，则该最小化DFA状态也为初态*/
                minDfa.startState = i;
            }

            if (d.endStates.count(y)) {  /*如果当前状态是终态，则该最小化DFA状态也为终态*/
                minDfaStates[i].isEnd = true;
                minDfa.endStates.insert(i);  /*将该最小化DFA状态加入终态集中*/
            }

            for (j = 0; j < DfaStates[y].edgeNum; j++) {  /*遍历该DFA状态的每条弧，为最小化DFA创建弧*/
                for (int t = 0; t < minDfaStateNum; t++) {
                    if (s[t].count(DfaStates[y].Edges[j].Trans)) {
                        bool haveEdge = false;
                        for (int l = 0; l < minDfaStates[i].edgeNum; l++) {  /*遍历已创建的弧*/
                            if ((minDfaStates[i].Edges[l].input == DfaStates[y].Edges[j].input) && 
                                (minDfaStates[i].Edges[l].Trans == t)) {
                                haveEdge = true;  /*标志为真*/
                            }
                        }

                        if (!haveEdge) {  /*如果该弧不存在，则创建一条新的弧*/
                            minDfaStates[i].Edges[minDfaStates[i].edgeNum].input = DfaStates[y].Edges[j].input;
                            minDfaStates[i].Edges[minDfaStates[i].edgeNum].Trans = t;
                            minDfa.trans[i][DfaStates[y].Edges[j].input - 'a'] = t;
                            minDfaStates[i].edgeNum++;  /*该状态的弧的数目加一*/
                        }
                        break;
                    }
                }
            }
        }
    }

    return minDfa;
}

void printMinDFA(DFA d) {

    int i, j;
    cout << "minDFA总共有" << minDfaStateNum << "个状态，" << "初态为" << d.startState << endl << endl;

    cout << "有穷字母表为｛ ";
    set<char>::iterator it;
    for (it = d.terminator.begin(); it != d.terminator.end(); it++) {
        cout << *it << ' ';
    }
    cout << '}' << endl << endl;

    cout << "终态集为｛ ";
    IntSet::iterator iter;
    for (iter = d.endStates.begin(); iter != d.endStates.end(); iter++) {
        cout << *iter << ' ';
    }
    cout << '}' << endl << endl;

    cout << "转移函数为：" << endl;
    for (i = 0; i < minDfaStateNum; i++) {
        for (j = 0; j < minDfaStates[i].edgeNum; j++) {

            if (minDfaStates[minDfaStates[i].Edges[j].Trans].isEnd == true) {
                cout << minDfaStates[i].index << "-->'" << minDfaStates[i].Edges[j].input;
                cout << "'--><" << minDfaStates[i].Edges[j].Trans << ">\t";
            } else {
                cout << minDfaStates[i].index << "-->'" << minDfaStates[i].Edges[j].input;
                cout << "'-->" << minDfaStates[i].Edges[j].Trans << '\t';
            }
        }
        cout << endl;
    }

    cout << endl << "转移矩阵为：" << endl << "     ";
    CharSet::iterator t;
    for (t = d.terminator.begin(); t != d.terminator.end(); t++) {
        cout << *t << "   ";
    }
    cout << endl;

    for (i = 0; i < minDfaStateNum; i++) {

        if (d.endStates.count(i)) {
            cout << '<' << i << ">  ";
        } else {
            cout << ' ' << i << "   ";
        }

        for (j = 0; j < 26; j++) {
            if (d.terminator.count(j + 'a')) {
                if (d.trans[i][j] != -1) {
                    cout << d.trans[i][j] << "   ";
                } else {
                    cout << "    ";
                }
            }
        }

        cout << endl;
    }
    cout << endl << "*******************************************";
}

