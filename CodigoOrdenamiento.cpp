//Autor: Juan Diego Lozada

#include <iostream>
#include <algorithm>
#include <ctime>
#include <locale.h>
#define K 200

using namespace std;

void radixSort(int arr[], int n) {
    int i, j, m = arr[0], exp = 1;
    int *b = new int[n];

    for (i = 1; i < n; i++) {
        if (arr[i] > m) {
            m = arr[i];
        }
    }

    while (m / exp > 0) {
        int bucket[10] = { 0 };
        
        for (i = 0; i < n; i++) {
            bucket[(arr[i] / exp) % 10]++;
        }
        
        for (i = 1; i < 10; i++) {
            bucket[i] += bucket[i - 1];
        }
        
        for (i = n - 1; i >= 0; i--) {
            b[--bucket[(arr[i] / exp) % 10]] = arr[i];
        }
        
        for (i = 0; i < n; i++) {
            arr[i] = b[i];
        }
        
        exp *= 10;
    }

    delete[] b;
}

int main() {
	
	setlocale(LC_ALL," ");
	
    srand(time(0));

	clock_t start_time, end_time;
    
	int i;
	int n;
    //int n=45, i;
    //cout << "Cantidad de numeros a ordenar: "<<n<<endl;
    
	for(int n=5;n<=K;n=n+5){
		double time_taken;
    	start_time = clock();
    	
		cout << "\n-------------------Sucesion con "<<n<<" numeros---------------------------"<<endl;
	    int *arr = new int[n];
	    cout << "\nNumeros aleatorios generados: "<<endl;
	    for (i = 0; i < n; i++) {
	        arr[i] = rand() % 99999 + 10000;
	        cout << arr[i] << " ";
	    }
	    cout << endl;
	
	    radixSort(arr, n);
	
	    cout << "Numeros ordenados: "<<endl;
	    for (i = 0; i < n; i++) {
	        cout << arr[i] << " ";
	    }
	    cout << endl;
		end_time = clock();
		
		time_taken = double(end_time - start_time) / CLOCKS_PER_SEC;
		
		cout << "\nEl tiempo de ejecucion fue de " << time_taken << " segundos." << endl; 
	    delete[] arr;
	}
    return 0;
}
