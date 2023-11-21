#pragma once

#include <vector>
#include <algorithm>
#include <exception>
#include <iterator>

namespace miscellaneous {
	// swap function
	template <class T>
	void swap(T& el1, T& el2) {
		T pom = el1;
		el1 = el2;
		el2 = pom;
	}
}

namespace ascendingOrder {

	// selection sort - pointer type array

	template <class T>
	void selectionSort(T arr[], long len) {
		if (len < 0)
			throw new std::exception("SELECTION_SORT: Given array length is negative!");
		for (long i = 0; i < len; ++i) {
			long imin = i;
			for (long j = i + 1; j < len; ++j)
				if (arr[j] < arr[imin])
					imin = j;
			if (imin != i)
				miscellaneous::swap(arr[i], arr[imin]);
		}
	}

	// selection sort - std::vector type array - using algorithm

	template <class T>
	void selectionSortAlgo(std::vector<T>& arr) {
		for (auto iter = arr.begin(); iter != arr.end(); iter++)
			std::swap(*iter, *std::min_element(iter, arr.end()));
	}

	// selection sort - std::vector type array - not using algorithm

	template <class T>
	void selectionSort(std::vector<T>& arr) {
		for (auto iterI = arr.begin(); iterI != arr.end(); ++iterI) {
			auto iterMin = iterI;
			for (auto iterJ = iterI + 1; iterJ != arr.end(); ++iterJ)
				if (*iterMin > *iterJ)
					iterMin = iterJ;
			if (iterI != iterMin)
				miscellaneous::swap(*iterI, *iterMin);
		}
	}

	// bubble sort - pointer type array

	template <class T>
	void bubbleSort(T arr[], long len) {
		if (len < 0)
			throw new std::exception("BUBBLE_SORT: Given array length is negative!");
		for (long i = 0; i < len; ++i) {
			long j = 0;
			while (j < len - 1 - i) {
				if (arr[j] > arr[j + 1])
					miscellaneous::swap(arr[j], arr[j + 1]);
				j++;
			}
		}
	}

	// bubble sort - std::vector type array

	template <class T>
	void bubbleSort(std::vector<T>& arr) {
		for (long i = 0; i < arr.size(); ++i) {
			long j = 0;
			while (j < arr.size() - 1 - i) {
				if (arr[j] > arr[j + 1])
					miscellaneous::swap(arr[j], arr[j + 1]);
				j++;
			}
		}
	}

	// insertion sort - pointer type array

	template <class T>
	void insertionSort(T arr[], int len) {
		if (len < 0)
			throw new std::exception("INSERTION_SORT: Given array length is negative!");
		for (long i = 1; i < len; ++i) {
			long j = i;
			T pom = arr[i];
			while (j > 0 && pom < arr[j - 1])
				arr[j] = arr[j - 1], j--;
			arr[j] = pom;
		}
	}

	// insertion sort - std::vector array type

	template <class T>
	void insertionSort(std::vector<T>& arr) {
		for (auto iterI = arr.begin(); iterI != arr.end(); iterI++) {
			auto iterJ = iterI;
			T pom = *iterI;
			while (iterJ != arr.begin() && pom < *(iterJ - 1))
				*iterJ = *(iterJ - 1), iterJ--;
			*iterJ = pom;
		}
	}

	namespace mergeSort {

		template <class T>
		void mergeHalves(T arr[], T temp[], long first, long last) {
			long s = (first + last) / 2;
			long i_temp = 0, i_left = first, i_right = s + 1;
			while (i_left <= s && i_right <= last)
				if (arr[i_left] < arr[i_right])
					temp[i_temp++] = arr[i_left++];
				else
					temp[i_temp++] = arr[i_right++];
			while (i_left <= s)
				temp[i_temp++] = arr[i_left++];
			while (i_right <= last)
				temp[i_temp++] = arr[i_right++];
			for (i_temp = 0, i_left = first; i_left <= last; i_left++, i_temp++)
				arr[i_left] = temp[i_temp];
		}

		template <class T>
		void mergeSort(T arr[], T temp[], long first, long last) {
			if (first >= last)
				return;
			long s = (first + last) / 2;
			mergeSort(arr, temp, first, s);
			mergeSort(arr, temp, s + 1, last);
			mergeHalves(arr, temp, first, last);
		}
		
		template <class T>
		void mergeSort(T arr[], long len) {
			if (len < 0)
				throw new std::exception("MERGE_SORT: Given array length is negative!");
			T* temp = new T[len];
			mergeSort(arr, temp, 0, len - 1);
			delete[] temp;
		}
	
	}

}

namespace descendingOrder {
	
}