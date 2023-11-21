#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>
#include <exception>
#include <fstream>
#include "sorts.h"

int main() {

	int n;
	std::cout << "Nad nizovima od koliko elemenata zelite da isprobate algoritme: ";
	std::cin >> n;
	srand(time(NULL));

	std::fstream testbench("testbench_results.txt", std::ios::out);
	testbench << "\n\t\tNum of elements: " << n << "\n";

	n %= 10000; // ako se unese preko 10k srecno sa cekanjem :)

	try {
		
		// selection sort

				// pointer type array

		int* arrSelPtr = new int[n];

		for (int i = 0; i < n; ++i)
			arrSelPtr[i] = rand() % 1000 - 500;

		auto begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::selectionSort(arrSelPtr, n);
		auto end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tSelection sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tSelection sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int i = 0; i < n; ++i)
			std::cout << arrSelPtr[i] << ' ';
		std::cout << "]\n\n";

				// std::vector using algorithm header

		std::vector<int> arrSelVecAlgo;

		for (int i = 0; i < n; ++i)
			arrSelVecAlgo.push_back(rand() % 1000 - 500);

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::selectionSortAlgo(arrSelVecAlgo);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tSelection sort for std::vector type array with algorithm header[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tSelection sort for std::vector type array with algorithm header[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int a : arrSelVecAlgo)
			std::cout << a << ' ';
		std::cout << "]\n\n";

				// std::vector without using algorithm header

		std::vector<int> arrSelVec;

		for (int i = 0; i < n; ++i)
			arrSelVec.push_back(rand() % 1000 - 500);

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::selectionSort(arrSelVec);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tSelection sort for std::vector type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tSelection sort for std::vector type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int a : arrSelVec)
			std::cout << a << ' ';
		std::cout << "]\n\n";

		// bubble sort

				// pointer type array

		int* arrBubPtr = new int[n];

		for (int i = 0; i < n; ++i)
			arrBubPtr[i] = rand() % 1000 - 500;

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::bubbleSort(arrBubPtr, n);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tBubble sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tBubble sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int i = 0; i < n; ++i)
			std::cout << arrBubPtr[i] << ' ';
		std::cout << "]\n\n";

				// std::vector type array

		std::vector<int> arrBubVec;

		for (int i = 0; i < n; ++i)
			arrBubVec.push_back(rand() % 1000 - 500);

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::bubbleSort(arrBubVec);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tBubble sort for std::vector type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tBubble sort for std::vector type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int a : arrBubVec)
			std::cout << a << ' ';
		std::cout << "]\n\n";

		// insertion sort

			// pointer type array

		int* arrInsPtr = new int[n];

		for (int i = 0; i < n; ++i)
			arrInsPtr[i] = rand() % 1000 - 500;

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::insertionSort(arrInsPtr, n);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tInsertion sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tInsertion sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int i = 0; i < n; ++i)
			std::cout << arrInsPtr[i] << ' ';
		std::cout << "]\n\n";

				// std::vector type array

		std::vector<int> arrInsVec;

		for (int i = 0; i < n; ++i)
			arrInsVec.push_back(rand() % 1000 - 500);

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::insertionSort(arrInsVec);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tInsertion sort for std::vector type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tInsertion sort for std::vector type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int a : arrInsVec)
			std::cout << a << ' ';
		std::cout << "]\n\n";

		// merge sort

		int* arrMerPtr = new int[n];

		for (int i = 0; i < n; ++i)
			arrMerPtr[i] = rand() % 1000 - 500;

		begin = std::chrono::high_resolution_clock::now();
		ascendingOrder::mergeSort::mergeSort(arrMerPtr, n);
		end = std::chrono::high_resolution_clock::now();

		std::cout << "\n\t\tMerge sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n\n";
		testbench << "\n\t\tMerge sort for pointer type array[ns]: " <<
			std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count() << "\n";

		std::cout << "[ ";
		for (int i = 0; i < n; ++i)
			std::cout << arrMerPtr[i] << ' ';
		std::cout << "]\n\n";

	}
	catch (std::exception* ex) {
		std::cerr << ex->what() << "\n";
		delete ex;
	}

	testbench.close();

	return 0;
}