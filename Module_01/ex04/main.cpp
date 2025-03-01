#include "utils.hpp"

int main(int argc, char *argv[]){
    if (argc != 4) {
        args_err(argc);
        return 1;
    }
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::string rfilename = filename + ".replace";
    std::ifstream myfile;
    std::ofstream rfile;
    std::string line;
    myfile.open (filename.c_str());
    rfile.open (rfilename.c_str());
    if (!myfile.is_open()) {
        std::cout << "Error: while opening the file named  <" << filename << ">" << std::endl;
        return 1;
    }
    while ( getline (myfile,line) ) {
        search_and_replace(line, s1, s2);
        if (myfile.eof())
            rfile << line;
        else
            rfile << line << '\n';
    }
    myfile.close();
    rfile.close();
    return 0;
}