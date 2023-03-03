#ifndef HUMAN_H
#define HUMAN_H

class Human {
    private:
        Human();
        Human(name);

        std::string name;

    public:
        char makeMove();
        std::string getName();
}

#endif