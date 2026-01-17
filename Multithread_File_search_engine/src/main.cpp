#include <iostream>
#include <fstream>
#include <vector>
#include <thread>
#include <mutex>

std::mutex mtx;

void searchInFile(const std::string& filename, const std::string& keyword) {
    std::ifstream file(filename);
    std::string line;
    int lineNo = 0;

    while (getline(file, line)) {
        lineNo++;
        if (line.find(keyword) != std::string::npos) {
            std::lock_guard<std::mutex> lock(mtx);
            std::cout << "Found in " << filename
                      << " at line " << lineNo << std::endl;
        }
    }
}

int main() {
    std::vector<std::string> files = {
        "file1.txt", "file2.txt", "file3.txt"
    };

    std::string keyword = "C++";
    std::vector<std::thread> threads;

    for (auto& file : files) {
        threads.emplace_back(searchInFile, file, keyword);
    }

    for (auto& t : threads) {
        t.join();
    }

    return 0;
}
