#include <iostream>
#include <cstdlib>
#include <chrono>
#include <ctime>
#include "SinglyLinkedList.h"

int main() {
	
	srand(time(NULL));
	int n;
	SinglyLinkedList<int> sllInt;

	try {

		std::cout << "Koliko elemenata zelite da ima vasa lista: ";
		std::cin >> n;

		for (int i = 0; i < n; ++i)
			sllInt.addToHead(rand() % 250 - 125);

		std::cout << '\n';
		sllInt.print(std::cout) << '\n';

		std::cout << "Koliko elemenata zelite da dodate na kraj liste: ";
		std::cin >> n;

		for (int i = 0; i < n; ++i)
			sllInt.addToTail(rand() % 250 - 125);

		std::cout << '\n';
		sllInt.print(std::cout) << '\n';

		std::cout << "Koliko elemenata zelite da obrisete sa pocetka liste: ";
		std::cin >> n;

		for (int i = 0; i < n; ++i)
			std::cout << sllInt.deleteFromHead() << '\n';

		std::cout << '\n';
		sllInt.print(std::cout) << '\n';

		std::cout << "Koliko elemenata zelite da obrisete sa kraja liste: ";
		std::cin >> n;

		for (int i = 0; i < n; ++i)
			std::cout << sllInt.deleteFromTail() << '\n';

		std::cout << '\n';
		sllInt.print(std::cout) << '\n';

		std::cout << "Koji element zelite da obrisete iz liste: ";
		std::cin >> n;

		std::cout << (sllInt.deleteEl(n) ? "obrisan!" : "nije u listi!") << '\n';

		std::cout << '\n';
		sllInt.print(std::cout) << '\n';

		std::cout << "Koji element zelite da pronadjete u listi: ";
		std::cin >> n;

		std::cout << "\nElement " << n << ((sllInt.findEl(n) != nullptr) ? " je nadjen\n" : " nije nadjen!\n");
	
	}
	catch (std::exception* ex) {
		std::cerr << "EXCEPTION THROWN: " << ex->what() << std::endl;
	}

	return 0;
}