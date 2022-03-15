#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <bits/stdc++.h>
#include <sys/time.h>
using namespace std;

struct maxSubArrayInfo{
    int Start, End, Value;
};

class maxSubArray{
    private:
        int* Array;
        int n;
//Cubic Method
		void cubicMethod(maxSubArrayInfo& ANS)
		{
			struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				int highest = 0;
				for (int a = 0; a < n; a++)
				{
					for (int b = a; b < n; b++)
					{
						int sum = 0;
            			for (int k = a; k <= b; k++)
            			{
                			sum = sum + Array[k];
            			}
            			highest = std::max(highest, sum);
        			}
    			}
				std::cout << "Maximum Cubic Method sum is " << highest << std::endl;
				gettimeofday(&end, NULL);
				double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
		}

//Square Method        
	    void squareMethod(maxSubArrayInfo& ANS)
		{
			struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				int i, j;
				int sum_till_now = 0;
				int max_till_now = 0;
				for(i = 0; i < n ; i++) 
				{
					sum_till_now = 0;
					for(j = i; j < n ; j++) 
					{
            			sum_till_now += Array[j];
            			if(sum_till_now > max_till_now)
                			max_till_now = sum_till_now;
        			}
    			}
				cout << "Maximum Square Method sum is " << max_till_now << endl;
				gettimeofday(&end, NULL);
				double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
        }

        
//nlogn Method		
		void nlognMethod(maxSubArrayInfo& ANS)
		{
			struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				int max_sum = maxSubArraySum(Array, 0, n - 1);
					printf("Maximum nlogn Method sum is %d\n", max_sum);
				gettimeofday(&end, NULL);
				double time_taken;
				time_taken = (end.tv_sec - start.tv_sec) * 1e6;
				time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
				cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
				cout << " sec" << endl;
		}
		int max(int a, int b) { return (a > b) ? a : b; }
		int max(int a, int b, int c) { return max(max(a, b), c); }
		int maxCrossingSum(int* Array, int l, int m, int h)
		{
			int sum = 0;
			int left_sum = INT_MIN;
			for (int i = m; i >= l; i--) 
			{
				sum = sum + Array[i];
				if (sum > left_sum)
					left_sum = sum;
			}
			sum = 0;
			int right_sum = INT_MIN;
			for (int i = m + 1; i <= h; i++) 
			{
				sum = sum + Array[i];
				if (sum > right_sum)
					right_sum = sum;
			}
			return max(left_sum + right_sum, left_sum, right_sum);
		}
		int maxSubArraySum(int* Array, int l, int h)
		{
			if (l == h)
				return Array[l];
			int m = (l + h) / 2;
				return max(maxSubArraySum(Array, l, m),
					   maxSubArraySum(Array, m + 1, h),
			           maxCrossingSum(Array, l, m, h));
        }

        
//Linear Method		
		void linearMethod(maxSubArrayInfo& ANS)
		{
			struct timeval start, end;
				gettimeofday(&start, NULL);
				ios_base::sync_with_stdio(false);
				int maxxx= maxsubarraySum(Array, n);
					cout<< "Maximum Linear Method sum is "<<maxxx<<endl;
				gettimeofday(&end, NULL);
				double time_taken;
					time_taken = (end.tv_sec - start.tv_sec) * 1e6;
					time_taken = (time_taken + (end.tv_usec - start.tv_usec)) * 1e-6;
					cout << "Time taken by program is : " << fixed << time_taken << setprecision(6);
					cout << " sec" << endl;
        }
		int maxsubarraySum(int* array, int n)
		{
			int max_ending_here = 0, max_so_far = INT_MIN;
			for (int i = 0; i < n; i++) 
			{	
				if (Array[i] <= max_ending_here + Array[i]) 
				{
					max_ending_here += Array[i];
				}
				else {
					max_ending_here = Array[i];
				}
				if (max_ending_here > max_so_far)
				max_so_far = max_ending_here;
			}
			return max_so_far;
		}


    public:
        maxSubArray(){
            Array = NULL;
            n = 0;
        }

        void findMaxSubarray(int method, maxSubArrayInfo& ANS){
            if(n == 0){
                ANS.Start = ANS.End = ANS.Value = -1;
                return;
            }

            if(method == 1)
                cubicMethod(ANS);
            else if (method == 2)
                squareMethod(ANS);
            else if (method == 3)
                nlognMethod(ANS);
            else
                linearMethod(ANS);
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
            <<"1. Create Numbers "<<endl
            <<"2. Sava Data"<<endl
            <<"3. Find MaxSubArray using Cubic Method"<<endl
            <<"4. Find MaxSubArray using Quadratic Method"<<endl
            <<"5. Find MaxSubArray using n.log(n) Method"<<endl
            <<"6. Find MaxSubArray using Linear Method"<<endl
            <<"7. Exit"<<endl
            <<"Enter Your Choice   ";

        cin>>Choice;

    }while(Choice < 1 || Choice > 7);
    return Choice;
}


int main()
{
    maxSubArray Algo;
    cout << "IMPLEMENT THE FOUR ALGORITHMS FOR SOLVIG THE MAXSUBARRAY PROBLEM";
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
            Algo.saveData("data.txt");

        }
        else if( 2 < Choice && Choice < 7){
            maxSubArrayInfo ANS;
            Algo.findMaxSubarray(Choice-2,ANS);
            cout<<endl<<"Start:  "<<ANS.Start
                <<endl<<"End:    "<<ANS.End
                <<endl<<"Value  "<<ANS.Value<<endl;
        }
    }while(Choice !=7);

    return 0;
}