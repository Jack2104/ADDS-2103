#ifndef PLAYER_H
#define PLAYER_H

class Player {
    private:
        

    public:
        virtual char makeMove() = 0;
        virtual std::string getname() = 0;
}

#endif