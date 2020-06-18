#include "utils.h"

#include <iostream>
#include <vector>
using namespace std;

class Sorting{
	public:
		static int available_sorting_choices(){
			int algorithms_implemented = 4;
			cout << "1 - Selection Sort\n";
			cout << "2 - Bubble Sort\n";
			cout << "3 - Merge Sort\n";
			cout << "4 - Quick Sort\n";
			return algorithms_implemented;
		}

		static void sort(const int sorting_algorithm, vector<int> &numbers){
			switch(sorting_algorithm){
				case 1:
					selection_sort(numbers);
					break;
				case 2:
					bubble_sort(numbers);
					break;
				case 3:
					merge_sort(numbers);
					break;
				case 4:
					quick_sort(numbers);
					break;
			}
		}


	private:
		static void selection_sort(vector<int> &numbers){
			for(int i = 0; i < numbers.size() - 1; ++i){
				int min_index = i;
				for(int j = i + 1; j < numbers.size(); ++j){
					if(numbers[j] < numbers[min_index]){
						min_index = j;
					}
				}
				Utils::swap(numbers[i], numbers[min_index]);
			}
		}

		static void bubble_sort(vector<int> &numbers){
			for(int i = 0; i < numbers.size() - 1; ++i){
				int swaps = 0;
				for(int j = 1; j < numbers.size() - i; ++j){
					if(numbers[j] < numbers[j - 1]){
						Utils::swap(numbers[j], numbers[j - 1]);
						++swaps;
					}
				}
				if(0 == swaps){
					break;
				}
			}
		}

		static void merge_sort(vector<int> &numbers){
			merge_sort_helper(numbers, 0, numbers.size());
		}

		static void merge_sort_helper(vector<int> &numbers, int left, int right){
			int mid = (left + right) / 2;
			if(left < mid){
				merge_sort_helper(numbers, left, mid);
				merge_sort_helper(numbers, mid, right);
				merge(numbers, left, mid, right);
			}
		}

		static void merge(vector<int> &numbers, int left, int mid, int right){
			int leftSize = mid - left;
			int rightSize = right - mid;
			vector<int> tmpLeft(leftSize), tmpRight(rightSize);
			for(int i = 0; i < leftSize; ++i){
				tmpLeft[i] = numbers[left + i];
			} 
			for(int j = 0; j < rightSize; ++j){
				tmpRight[j] = numbers[mid + j];
			}
			int leftIndex = 0;
			int rightIndex = 0;
			for(int mainIndex = left; mainIndex < right; ++mainIndex){
				if(leftIndex < leftSize && rightIndex < rightSize){
					if(tmpLeft[leftIndex] <= tmpRight[rightIndex]){
						numbers[mainIndex] = tmpLeft[leftIndex];
						++leftIndex;
					}
					else{
						numbers[mainIndex] = tmpRight[rightIndex];
						++rightIndex;
					}
				}
				else if(leftIndex < leftSize){
					numbers[mainIndex] = tmpLeft[leftIndex];
					++leftIndex;
				}
				else{
					numbers[mainIndex] = tmpRight[rightIndex];
					++rightIndex;
				}
			}
		}

		static void quick_sort(vector<int> &numbers){
			quick_sort_helper(numbers, 0, numbers.size() - 1);
		}

		static void quick_sort_helper(vector<int> &numbers, int left, int right){
			if(left < right){
				int tail = left;
				for(int head = left; head < right; ++head){
					if(numbers[head] < numbers[right]){
						Utils::swap(numbers[tail], numbers[head]);
						++tail;
					}
				}
				Utils::swap(numbers[tail], numbers[right]);
				
				quick_sort_helper(numbers, left, tail - 1);
				quick_sort_helper(numbers, tail + 1, right);
			}
		}

};


