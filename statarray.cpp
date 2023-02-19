#include "statarray.hpp"


int getMax(const int *ar, int size){
	static int left = 0;
        if(size - 1 == left){
                std::cout << "max = " << ar[left] << std::endl;
		left = 0;
                return 0;
        }

        if(ar[left] <= ar[size - 1]){
                left++;
        }

        else if(ar[left] > ar[size - 1]){
                size--;
        }

        getMax(ar, size);

        return 0;
}


int getMin(const int *ar, int size){        
	static int left = 0;
        if(size - 1 == left){
                std::cout << "min = " << ar[left] << std::endl;
                left = 0;
		return 0;
        }


        if(ar[left] <= ar[size - 1]){
                size--;
        }

        else if(ar[left] > ar[size - 1]){
                left++;
        }

        getMin(ar,size);

        return 0;
}


int binSearch(int* ar, int size, int el) {
	if (ar[size >> 1] == el) {
		return (size >> 1);
	}
	if (size == 1) {
		return -1;
	}

	if (el > ar[size >> 1]) {
		return binSearch(&ar[size >> 1], size - (size >> 1), el) + (size >> 1); 
	}

	if (el < ar[size >> 1]) {
		return binSearch(ar, size >> 1, el);
	}


	return -1;
}


int test_Ar(int *ar, int size){
	int count = 0;
	for(int i = 0; i < size; i++){
		if(ar[i] <= ar[i+1]){
			count++;
		}

		if(ar[i] >= ar[i+1]){
			count--;
		}
	}

	if(count == size - 2){
		return 1;
	}

	else if(count == -size + 1){
		return 2;
	}

	return 0;
	
}

