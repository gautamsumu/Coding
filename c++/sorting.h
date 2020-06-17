#include "utils.h"

#include <iostream>
#include <vector>
using namespace std;

class Sorting{
	public:
		static int available_sorting_choices(){
			int algorithms_implemented = 1;
			cout << "1 - Selection Sort\n";
			return algorithms_implemented;
		}

		static void sort(const int sorting_algorithm, vector<int> &numbers){
			switch(sorting_algorithm){
				case 1:
					selection_sort(numbers);
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
};


