# include "ReadMyFile.hpp"

ReadMyFile::ReadMyFile(void) {};

ReadMyFile::ReadMyFile(std::string name): fileName(name){
};

ReadMyFile::ReadMyFile(char *name) : fileName(name)  {
};

ReadMyFile::~ReadMyFile() {
    this->file.close();
}

int ReadMyFile::open(void) {

    this->file.open(this->fileName);

    if (this->file.is_open()) {
        return (1);
    } else {
        return (0);
    }
};

void ReadMyFile::replaceAll(std::string oldStr, std::string newStr) {
    
    size_t pos;
    std::string buffer;
    std::string nameFile = this->fileName + ".replace";
    std::ofstream newFile(nameFile.c_str());


    if (this->file.is_open()) {
        while (!this->file.eof()) {
            std::getline(this->file, buffer);
            pos = 0;
            while ((pos = buffer.find(oldStr, pos)) != std::string::npos)
            {
                buffer = buffer.substr(0, pos) + newStr + buffer.substr(pos + oldStr.length());
                pos += oldStr.length();
            }
            newFile << buffer;
            if (!this->file.eof()) {
                newFile << std::endl;
            }
        }
        newFile.close();
    }
};