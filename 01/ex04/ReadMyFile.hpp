#ifndef READFILE_HPP
# define READFILE_HPP

# include <iostream>
# include <fstream>
# include <cstring>

class ReadMyFile {
    private:
        std::string fileName;
        std::ifstream file;
    public:
        ReadMyFile(void);
        ReadMyFile(std::string name);
        ReadMyFile(char *name);
        ~ReadMyFile();
        int open(void);
        void replaceAll(std::string oldStr, std::string newStr);

};

#endif