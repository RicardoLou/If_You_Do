#include<bits/stdc++.h>
#include<unordered_set>
using namespace std;

// 使用 unordered_set 代替数组，提高查找效率
unordered_set<string> KEYWORD = {"if", "else", "void", "return", "do", "while", "for",
"int", "char", "double", "float", "case", "cin", "cout"};
unordered_set<char> SEPARATER = {';', ',', '{', '}', '[', ']', '(', ')', '\"'}; // 分隔符
unordered_set<string> MULTI_OPERATOR = {"==", "!=", "<=", ">="}; // 多字符运算符
unordered_set<char> OPERATOR = {'+', '-', '*', '/', '>', '<', '=', '!'}; // 运算符
unordered_set<char> FILTER = {' ', '\t', '\r', '\n'}; // 过滤符

const int KEYWORD_VAL = 1;
const int IDENTIFIER_VAL = 2;
const int CONSTANT_VAL = 3;
const int OPERATOR_VAL = 4;
const int SEPARATER_VAL = 5;
const int STRING_LITERAL_VAL = 6; // 字符串
const int FILTER_VAL = 7; // 过滤符

bool isKeyword(string target) {
    return KEYWORD.count(target);
}
// 判断字符是否为过滤符
bool IsFilter(char ch) {
    return FILTER.count(ch);
}

// 判断是否为字母
bool IsLetter(char ch) {
	if ((ch >= 'A' && ch <= 'Z' )||( ch >= 'a' && ch <= 'z') || ch == '_')
        return true;
	return false;

}

// 判断是否为数字
bool IsDigit(char ch) {
	if (ch >= '0' && ch <= '9')
        return true;
	return false;

}

// 词法分析函数
void analyse(FILE* fpin) {
    char ch;
    string arr;
    // 判断结束
    while ((ch = fgetc(fpin)) != EOF) {
        arr = "";
        if (IsFilter(ch)) {
        printf("%3d ", FILTER_VAL);
            switch(ch) {
            case ' ':
                cout << "' ' 空格符" << endl;
                break;
            case '\t':
                cout << "'\\t' tab符" << endl;
                break;
            case '\r':
                cout << "'\\r' 回车符" << endl;
                break;
            case '\n':
                cout << "'\\n' 换行符" << endl;
                break;
            }
            continue;
        }

        if (IsLetter(ch)) {
        // 识别关键字或标识符
            while (IsLetter(ch) || IsDigit(ch)) {
                arr += ch;
                ch = fgetc(fpin);
            }
        fseek(fpin, -1L, SEEK_CUR); // 回退一个符号
            if (isKeyword(arr)) {
                printf("%3d ", KEYWORD_VAL);
                cout << arr << " 关键字" << endl;
            } else {
                printf("%3d ", IDENTIFIER_VAL);
                cout << arr << " 标识符" << endl;
            }
        } else if (IsDigit(ch)) {
            // 识别常数
            while (IsDigit(ch)) {
                arr += ch;
                ch = fgetc(fpin);
            }
            fseek(fpin, -1L, SEEK_CUR);
            printf("%3d ", CONSTANT_VAL);
            cout << arr << " 整形数" << endl;
        // 转义 判断当前是否是双引号，如果是，则接下来是字符串
        } else if (ch == '\"') {
            printf("%3d ", SEPARATER_VAL);
            cout << "\" " << "分隔符" << endl;
            // 识别字符串
            ch = fgetc(fpin);
            arr += ch;
            // 到下一个双引号之前
            while (ch != '\"' && ch != EOF) {
                // 在print里面出现斜杠的时候
                if(ch == '\\') {
                    char temp = fgetc(fpin);
                    if(temp == 't' || temp == 'r' || temp == 'n') {

                        printf("%3d ", STRING_LITERAL_VAL);
                        cout << arr << " 字符串" << endl;
                        arr = "";
                        printf("%3d ", FILTER_VAL);
                        cout << "\\" << temp << "过滤符" << endl;
                    } else
                        fseek(fpin, -1L, SEEK_CUR);
                }
                ch = fgetc(fpin);
                arr += ch;
            }
            printf("%3d ", STRING_LITERAL_VAL);
            cout << arr << " 字符串" << endl;
            printf("%3d ", SEPARATER_VAL);
            cout << "\" " << "分隔符" << endl;
            } else if (OPERATOR.count(ch)) {
                // 识别运算符（包括多字符运算符）
                arr += ch;
                char nextCh = fgetc(fpin);
                if (OPERATOR.count(nextCh) && MULTI_OPERATOR.count(arr + nextCh)) {
                arr += nextCh;
            } else {
                fseek(fpin, -1L, SEEK_CUR);
            }
                printf("%3d ", OPERATOR_VAL);
                cout << arr << " 运算符" << endl;
            } else if (SEPARATER.count(ch)) {
                // 识别分隔符
                printf("%3d ", SEPARATER_VAL);
                cout << ch << " 分隔符" << endl;
            } else {
                cout << "\"" << ch << "\": 无法识别的字符！" << endl;
            }
    }
}

int main() {
    // 替换为指针
    const char* inFile = "exp3_1.txt";
    FILE* fpin = fopen(inFile, "r");


    analyse(fpin);
    fclose(fpin); // 关闭流
    return 0;
}
