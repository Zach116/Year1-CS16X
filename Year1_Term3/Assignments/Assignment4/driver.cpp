#include <iostream>
#include <string>
#include <vector>
#include "player.h"
#include "insect.h"
#include "ant.h"
#include "bee.h"
#include "tools.h"

using namespace std;

int main() {
  Player player;

  do {
    player.generate_food();

    cout << "BEE GENERATED!" << endl;
    player.generate_bee();

    player.print_board();

    cout << "FOODBANK: " << player.get_foodBank() << endl;
    player.ant_selection();

    cout << "ANTS ATTACK!" << endl;
    player.take_turn_ants();
    player.print_board();

    cout << "BEES MOVE AND ATTACK!" << endl;
    player.take_turn_bees();
    player.print_board();
    cout << "--------------------------------------------------------------" << endl;
  } while (!player.game_over());

  player.delete_vector();

}
