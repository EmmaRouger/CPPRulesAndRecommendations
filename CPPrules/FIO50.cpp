#include <iostream>
#include <fstream>
#include <string>

void write_and_read(const std::string &fileName) {

    std::fstream myFile(fileName, std::ios::in | std::ios::out);

    if (!myFile.is_open()) {
        std::cerr << "WARNING!!! Error: Failed to open file " << fileName << std::endl;
        return; 
    }

    myFile << "Output some data to the file\n Don't worry this is okay it will be read later on";

    myFile.seekg(0, std::ios::beg); //allow to do both write and read from same opened filed

    std::string str;
    myFile >> str;

    std::cout << "Data read from myFile: " << str << std::endl;

    std::cout << "\n\nYay it was written and read without error :)"<< std::endl;

    myFile.close();
}

int main() {
    write_and_read("myFile.txt");

    return 0;
}