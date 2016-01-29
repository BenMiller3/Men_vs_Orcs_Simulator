#include <iostream>
#include <string>
#include <random>
#include <ctime>

using namespace std;

int main() {
	
	// Random Number Generator
	default_random_engine randNum(time(NULL));
	uniform_real_distribution<float> attack(0.0f, 3.0f);
	
	// Total men and orcs, declared by user
	int men;
	int orcs;

	float manHealth = 10.0f;
	float orcHealth = 3.5f;

	cout << "*** Man vs. Orc Battle Simulator ***\n\n";
	cout << "How many men are you bringing into battle, general: ";
	cin >> men;

	cout << "\nHow many orcs are we up against, general: ";
	cin >> orcs;

	// Stores the values, as the other variables are altered
	int totalMen = men;
	int totalOrcs = orcs;

	cout << "\n\n*Battle has commenced*\n";

	// Simulation occurs
	while (men > 0 && orcs > 0) {
		float orcAttack = attack(randNum);
		float manAttack = attack(randNum);

		manHealth -= orcAttack;
		orcHealth -= manAttack;

		if (orcHealth <= 0) { orcs -= 1; orcHealth = 3.5f; }
		if (manHealth <= 0) { men -= 1; manHealth = 10.0f; }
	}
	
	// End game sequence
	cout << "\n*The battle has finished*\n";

	cout << "\n\n*** CASUALTY REPORT ***\n";
	cout << "Total men dead: " << totalMen - men << endl;
	cout << "Total orcs dead: " << totalOrcs - orcs << endl;

	if (men > orcs) {
		cout << "\nGeneral, This is a battle we can win" << endl;
	}

	else {
		cout << "\nGeneral, I would not put these men in this fight" << endl;
	}

	system("PAUSE");
	return 0;
}
