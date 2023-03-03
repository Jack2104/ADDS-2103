#include "Player.h"
#include "Computer.h"
#include "Human.h"
#include "Referee.h"

#include <string>

int main() {
    Player* p1 = new Human("Mie");
    Player* p2 = new Computer();

    Referee ref = Referee();

    Player* winner = ref.refGame(p1, p2);
    std::cout << winner->getName() << std::endl;

    return 0;
}