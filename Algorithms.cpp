#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

struct sortingAlgosInfo{
    int Start, End, Value;
};

class sortingAlgos{
    private:
        int* Array;
        int n;
        
// Bubble Sort        
        void bubbleSort(sortingAlgosInfo& ANS)
		{
        	struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
        	bubbleSort(Array, n);
  			cout << "Sorted Array by Bubble Sort Algorithm :\n";
  			printArray(Array, n);
  			gettimeofday(&end, NULL);
			double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;

        }
        void bubbleSort(int* Array, int n) 
		{
			for (int step = 0; step < (n-1); ++step) 
			{
				int swapped = 0;
    			for (int i = 0; i < (n-step-1); ++i) 
				{
        			if (Array[i] > Array[i + 1]) 
					{
						int temp = Array[i];
        				Array[i] = Array[i + 1];
        				Array[i + 1] = temp;
        				swapped = 1;
      				}
    			}
				if (swapped == 0)
					break;
  			}
		}
		void printArray(int* Array, int n) 
		{
			for (int i = 0; i < n; ++i) 
			{
				cout << "  " << Array[i];
			}
   			cout<<endl;
		}


// Selection Sort
        void selectionSort(sortingAlgosInfo& ANS)
		{
        	struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
        		selectionSort(Array, n);
			   		cout << "Sorted Array by Selection Sort Algorithm :\n";
  				printarray(Array, n);
			gettimeofday(&end, NULL);
			double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
        }
		void swap(int *a, int *b) 
		{
  			int temp = *a;
  			*a = *b;
  			*b = temp;
		}
		void printarray(int* Array, int n) 
		{
			for (int i = 0; i < n; i++) 
			{
    			cout << Array[i] << " ";
  			}
  			cout << endl;
		}
		void selectionSort(int* Array, int n) 
		{
  			for (int step = 0; step < n - 1; step++) 
			{
    			int min_idx = step;
    			for (int i = step + 1; i < n; i++) 
				{
					if (Array[i] < Array[min_idx])
        				min_idx = i;
    			}
				swap(&Array[min_idx], &Array[step]);
  			}
		}



// Insertion Sort
        void insertionSort(sortingAlgosInfo& ANS)
		{
        	struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				insertionSort(Array, n);
					cout << "Sorted Array by Insertion Sort Algorithm :\n";
				printArr(Array, n);
				gettimeofday(&end, NULL);
				double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
        }
		void insertionSort(int* Array, int n)
		{
			int i, key, j;
			for (i = 1; i < n; i++)
			{
				key = Array[i];
				j = i - 1;
				while (j >= 0 && Array[j] > key)
				{
					Array[j + 1] = Array[j];
					j = j - 1;
				}
				Array[j + 1] = key;
			}
		}
		void printArr(int* Array, int n)
		{
			int i;
			for (i = 0; i < n; i++)
				cout << Array[i] << " ";
			cout << endl;
		}



// Merge Sort
        void mergeSort(sortingAlgosInfo& ANS)
		{
        	struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				mergeSort(Array, 0, n - 1);
				cout << "Sorted Array by Merge Sort Algorithm :\n";
				printarr(Array, n);
				gettimeofday(&end, NULL);
				double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
        }
		void merge(int* Array, int p, int q, int r) 
		{
			int n1 = q - p + 1;
  			int n2 = r - q;
			int L[n1], M[n2];
			for (int i = 0; i < n1; i++)
				L[i] = Array[p + i];
  				for (int j = 0; j < n2; j++)
    				M[j] = Array[q + 1 + j];
					int i, j, k;
					i = 0;
  					j = 0;
  					k = p;
					  while (i < n1 && j < n2) 
					  {
					  	if (L[i] <= M[j]) 
						  {
						  	Array[k] = L[i];
      						i++;
    						} 
							else {
      								Array[k] = M[j];
      								j++;
    							}
    							k++;
  						}
						  while (i < n1) 
						  {
						  	Array[k] = L[i];
							   i++;
							   k++;
							}
							while (j < n2) 
							{
								Array[k] = M[j];
								j++;
								k++;
							}
		}
		void mergeSort(int* Array, int l, int r) 
		{
			if (l < r) 
			{
				int m = l + (r - l) / 2;
				mergeSort(Array, l, m);
    			mergeSort(Array, m + 1, r);
				merge(Array, l, m, r);
  			}
		}
		void printarr(int* Array, int n) 
		{
  			for (int i = 0; i < n; i++)
    			cout << Array[i] << " ";
  			cout << endl;
		}
 
 
// Quick Sort         
        void quickSort(sortingAlgosInfo& ANS)
		{
        	struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				quickSort(Array, 0, n - 1);
				cout << "Sorted Array by Quick Sort Algorithm :\n";
				PrintArray(Array, n);
				gettimeofday(&end, NULL);
				double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
        }
		void swapfor( int* a, int* b)
		{
			int t = *a;
			*a = *b;
			*b = t;
		}
		int partition (int* Array, int low, int high)
		{
			int pivot = Array[high]; 
			int i = (low - 1); 
			for (int j = low; j <= high - 1; j++)
			{
				if (Array[j] < pivot)
				{
					i++; 
					swap(&Array[i], &Array[j]);
				}
			}
			swap(&Array[i + 1], &Array[high]);
				return (i + 1);
		}
		void quickSort(int* Array, int low, int high)
		{
			if (low < high)
			{
				int pi = partition(Array, low, high);
				quickSort(Array, low, pi - 1);
				quickSort(Array, pi + 1, high);
			}
		}
		void PrintArray(int* Array, int n)
		{
			int i;
			for (i = 0; i < n; i++)
				cout << Array[i] << " ";
			cout << endl;
		}

    public:
        sortingAlgos(){
            Array = NULL;
            n = 0;
        }

        void findMaxSubarray(int method, sortingAlgosInfo& ANS){
            if(n == 0){
                ANS.Start = ANS.End = ANS.Value = -1;
                return;
            }

            if(method == 1)
                bubbleSort(ANS);
            else if (method == 2)
                selectionSort(ANS);
            else if (method == 3)
                insertionSort(ANS);
            else if (method == 4)
				mergeSort(ANS);  
            else
                quickSort(ANS);
        }

        bool CreateRandomData(unsigned int n, int minValue, int maxValue){
            if(Array)
                delete [] Array;
            this->n = n;

            Array = new int[n];
            if (!Array){
                cout<<"Memory Issue:";
                return false;
            }

            srand( (unsigned)time(NULL) );
            for(unsigned int i = 0; i< n;i++){
                Array[i] = minValue + ( (float) rand())/RAND_MAX*(maxValue-minValue);
            }
            return true;
        }

        void saveData(char fileName[]){
            ofstream FOUT(fileName);
            if(!FOUT){
                cout<<"Output File Error";
                return;
            }
            FOUT <<n <<endl;
            for(int i = 0; i< n;i++)
                FOUT <<Array[i]<<endl;
            FOUT.close();
            cout<<"Numbers Saved in "<<fileName<<endl;
            return;
        }
};

int menu(){
    int Choice;
    do{
        cout<<endl
            <<"1. Create Numbers"<<endl
            <<"2. Sava Data"<<endl
            <<"3. Bubble Sort Algorithm"<<endl
            <<"4. Selection Sort Algorithm"<<endl
            <<"5. Insertion Sort Algorithm"<<endl
            <<"6. Merge Sort Algorithm"<<endl
            <<"7. Quick Sort Algorithm"<<endl
            <<"8. Exit"<<endl
            <<"Enter Your Choice   ";

        cin>>Choice;

    }while(Choice < 1 || Choice > 8);
    return Choice;
}

int main()
{
    sortingAlgos Algo;
    cout << "IMPLEMENT THE FIVE ALGORITHMS FOR SOLVIG THE SORTING PROBLEM";
    int Choice;
    do{
        Choice = menu();
        if(Choice == 1){
            int n, minValue, maxValue;
            cout<<"How Many Numbers ";
            cin>> n;
            cout<<"Min Value ";
            cin>>minValue;
            cout<<"Max Value ";
            cin>>maxValue;
            cout<<Algo.CreateRandomData(n, minValue,maxValue)
                <<endl;
        }
        else if(Choice == 2){
            Algo.saveData("Algodata.txt");

        }
        else if( 2 < Choice && Choice < 8){
            sortingAlgosInfo ANS;
            Algo.findMaxSubarray(Choice-2,ANS);
            cout<<endl<<"Start:  "<<ANS.Start
                <<endl<<"End:    "<<ANS.End
                <<endl<<"Value  "<<ANS.Value<<endl;
        }
    }while(Choice !=8);

    return 0;
}
