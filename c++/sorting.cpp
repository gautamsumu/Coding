#include "sorting.h"

#include <iostream>
#include <vector>
using namespace std;

int main(){
	cout << "Testing Sorting Algorithms";
	cout << "\n";
	cout << "--------------------------";
	char choice = 'Y';
	while('Y' == choice){
		cout << "\n";
		cout << "Size of integer vector: ";
		int vector_size;
		cin >> vector_size;
		if(vector_size <= 0){
			cout << "ERROR: Vector size must be greater than 0\n";
		}
		else{
			cout << "Integers: ";
			vector<int> numbers(vector_size, 0);
			for(int i = 0; i < vector_size; ++i){
				cin >> numbers[i];
			}
			while('Y' == choice){
				cout << "\n";
				int algorithm_types = Sorting::available_sorting_choices();
				cout << "Pick a sorting algorithm (from 1 to " << algorithm_types << "): ";
				int sorting_algorithm;
				cin >> sorting_algorithm;
				if(sorting_algorithm <= 0 || sorting_algorithm > algorithm_types){
					cout << "ERROR: Available sorting choices are from 1 to " << algorithm_types << "\n";
					cout << "Want to try again (Y/N): ";
					cin >> choice;
				}
				else{
					cout << "Input:";
					for(int i = 0; i < vector_size; ++i){
						cout << " " << numbers[i];
					}
					cout << "\n";
					vector<int> result(numbers);
					Sorting::sort(sorting_algorithm, result);
					cout << "Result:";
					for(int i = 0; i < result.size(); ++i){
						cout << " " << result[i];
					}
					cout << "\n";
					cout << "Want to try another algorithm (Y/N): ";
					cin >> choice;
				}
			}
		}
		cout << "Want to try a different list of integers (Y/N): ";
		cin >> choice;
	}
	cout << "Thanks.\n";
	return 0;
}


