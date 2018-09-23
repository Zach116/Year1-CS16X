#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <fstream>
#include <cmath>
#include <string>
#include "game.h"
#include "player.h"
#include "property.h"
#include "house.h"
#include "businessComplex.h"
#include "apartmentComplex.h"
#include "tools.h"


using namespace std;

int main() {
	House p1;
	ApartmentComplex p2;

	p1.set_propertyValue(30);
	p2.set_propertyValue(1000);

	cout << "House property value: " << p1.get_propertyValue() << endl;
	cout << "Apartment property value: " << p2.get_propertyValue() << endl;

	if (p1 > p2) {
		cout << "The house has the greater property value! " << endl;
	}
	if (p1 < p2) {
		cout << "The house has the lower property value! " << endl;
	}




	/*
	int turnNum = 0;
	srand(time(NULL));
	Game game;
	Player p1;
	game.set_player(p1);
	game.set_up();
	do {
		turnNum++;
		cout << "MONTH: " << turnNum << endl;
		cout << endl;

		game.collect_rent();
		game.pay_debt_taxes(turnNum);
		game.random_event();
		game.buy_property();
		game.sell_property();
		game.adjust_rent();


		// cout << "PROPERTIES OWNED:" << endl;
		// cout << "Num Houses owned: " << game.get_player().get_numHousesOwned() << endl;
		// for (int i = 0; i < game.get_player().get_numHousesOwned(); i++) {
		// 	game.get_player().get_ownedHouses()[i].print_info();
		// }
		// if (game.get_player().get_numHousesOwned() == 0) {
		// 	cout << endl;
		// }
		//
		// cout << "Num Apartments owned: " << game.get_player().get_numApartmentComplexesOwned() << endl;
		// for (int i = 0; i < game.get_player().get_numApartmentComplexesOwned(); i++) {
		// 	game.get_player().get_ownedApartmentComplexes()[i].print_info();
		// }
		// if (game.get_player().get_numApartmentComplexesOwned() == 0) {
		// 	cout << endl;
		// }
		//
		// cout << "Num Businesses owned: " << game.get_player().get_numBusinessComplexesOwned() << endl;
		// for (int i=0; i < game.get_player().get_numBusinessComplexesOwned(); i++) {
		// 	game.get_player().get_ownedBusinessComplexes()[i].print_info();
		// }
		// if (game.get_player().get_numBusinessComplexesOwned() == 0) {
		// 	cout << endl;
		// }


		cout << "END TURN" << endl;
		cout << "--------------------------------------------------------------------------------------------------------------" << endl;
	} while(!game.game_over());



cout << "PROPERTIES TO BUY AFTER:" << endl;
cout << "--------------------------------------------------------------------------------------------------------------" << endl;
for (int i = 0; i < 3; i++) {
	game.get_housesToBuy()[i].print_info();
	cout << endl;
	cout << "00000000000000000000000000000000000000000000000" << endl;
	cout << endl;
	game.get_apartmentComplexesToBuy()[i].print_info();
	cout << endl;
	cout << "00000000000000000000000000000000000000000000000" << endl;
	cout << endl;
	game.get_businessComplexesToBuy()[i].print_info();
	cout << endl;
	cout << "00000000000000000000000000000000000000000000000" << endl;
	cout << endl;
}
*/
	return 0;

}
