#include <iostream>
#include <fstream>

void printFileContent(const std::string& filename) {
    std::ifstream inFile(filename, std::ios::binary);
    if (!inFile) {
        std::cerr << "无法打开文件：" << filename << std::endl;
        return;
    }

    // 打印文件内容的十六进制
    char byte;
    while (inFile.read(&byte, sizeof(byte))) {
        std::cout << std::hex << (int)(unsigned char)byte << " ";
    }

    inFile.close();
    std::cout << std::endl;
}

int main() {
    std::string filename = "nfa.dat";  // 你可以修改为实际的文件路径
    printFileContent(filename);
    return 0;
}