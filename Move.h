#ifndef MOVE_H
#define MOVE_H

#include <string>
#include <vector>

class Move {
    private:
        std::string moveName;
        std::vector<std::string> losesTo;

    public:
        Move(std::string name, std::vector<std::string> losesTo);

        std::string getName();
        bool isBeatenBy(std::string move);
};

#endif