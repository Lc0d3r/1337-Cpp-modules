#include "BitcoinExchange.hpp"

int main(int argc, char **argv) {
    try {
        if (argc < 2)
            throw std::runtime_error("Error: Need args e.g.=> ./btc filename.csv");
        std::map<std::string, std::string> db = loadDatabase("data.csv", ',');

        process(db, argv[1]);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
        return 1;
    }
    return 1;
}