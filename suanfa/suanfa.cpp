#include<iostream>
#include<vector>
#include<cstdlib>
#include<ctime>


using namespace std;
void subVector(vector<int>& x, int start, int end, int sub) {
    
    for (int i = start; i <= end; i++) {
        x[i] -= sub;       
    }
    cout << "test...";
}

int main() {
     clock_t startTime,endTime;
     startTime = clock();
    vector<int> x;
    srand(time(0));
    for(int i = 0; i < 1000; i++){
        x.push_back(rand() % 10000);
    }
     int size = x.size();


    // vector<int> x;
    // int size;
    // cin >> size;
    //     int a;
    // while (cin >> a)
    // {
    //     x.push_back(a);
    //     if (cin.get() == '\n') break;
    // }
    
    int min = INT32_MAX;
    long long res = 0;
    int i;
    for (i = 0; i < size; i++) { //去掉前导0
        if (x[i] == 0) continue;
        else break;
    }

    for (; i < size;) {
        if (x[i] == 0){
            i++;
            continue;
        } 
        
        for (int j = i; j <= size; j++) {
            if (j == size || (x[j] == 0)) {
                subVector(x, i, j - 1, min);
                res += min;
                min = INT32_MAX;
                break;
            }
            if (x[j] != 0) {
                if (x[j] < min) {
                    min = x[j];
                    // std::cout << '\n' << min;
                }
            }
        }
       
    }

    std::cout << res  << endl;
    endTime = clock();//计时结束
    cout << "The run time is:" <<(double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
}
