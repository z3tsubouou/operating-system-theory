#include <process.h>
#include <stdio.h>
#include <stddef.h>
#include <windows.h>
#include <iostream>
#include<cstring>
using namespace std;
int a[5][5], b[5][5], x, y, n, i, j, k, mult[5][5];
int random_int(int min, int max){
    return min + rand() % (max - min + 1);
}
int random_matrix(int n){
  for(x = 0; x < n; x++) {
		for(y = 0; y < n; y++){
	    	a[x][y] = random_int(1, 5);
	    	cout << a[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for(x = 0; x < n; x++) {
		for(y = 0; y < n; y++){
	    	b[x][y] = random_int(1, 5);
	    	cout << b[x][y] << " ";
		}
		cout << endl;
	}
	cout << endl;
}
void multiply(void *param){
	for(k = 0; k < n; k++){
   		mult[x][y] += a[x][k] * b[k][y];
	}
	_endthread();
}
void primenumber(void *param){
    int i;
	for(i = 2; i <= n; i++)
	     if(n%i==0) break;
	if(i==n)cout << n <<endl;
	_endthread();
}
int main(){

    int i;
    while(true){
            cout<<"1=>1-100 hurtelh anhnii too"<<endl<<"2=>matritsiin urjver"<<endl<<"3=>programmaas garah"<<endl;
            cin>>i;
            if(i==1){
                    n = 2;
                    while(n < 100){
                        Sleep(1);
                        n++;
                        _beginthread(primenumber, 0, NULL);
                        /*_beginthreadex(NULL, 0, findPrimeNumber, NULL, 0, NULL);*/
                    }
            }
            if(i==2){
                    cout << "Matritsiin hemjee:" <<endl;
                    cin >> n;
                    cout << endl;
                    random_matrix(n);
                    x = y = 0;

                    while(x < n){
                        while(y < n){
                            _beginthread(multiply, 0, NULL);
                            Sleep(10);
                            y++;
                        }
                        x++;
                        y=0;
                    }
                    for(i = 0; i < n; ++i){
                        for(j = 0; j < n; ++j){
                            cout << mult[i][j] <<" ";
                        }
                        cout << endl;
                    }
            }
            if(i==3)
                return 0;
    }
	return 0;
}

