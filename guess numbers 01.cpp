//guess numbers game.cpp

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
	int num[3],g_num[3],A,B,i,j,k,n=0,win=0,lose=0;
	char a;
	bool flag=true;
	while (flag){                                           //this while is used for play games many times
		cout<<"Do you need to play games?(Y/N)"<<endl;
		cin>>a;
		if(a=='N') {
			cout<<"You have played"<<n<<"times,win"<<win<<"times,lose"<<lose<<"times"<<endl;
			flag=false;
		}
		else{
			n+=1;
			srand(time(NULL));                               //conduct three different numbers
			num[0]=rand()%10;
			num[1]=rand()%10;
			while (num[0]==num[1]){
				num[1]=rand()%10;
			}
			num[2]=rand()%10;
			while (num[0]==num[2]||num[1]==num[2]){
				num[2]=rand()%10;
			}
			for(i=0;i<7;++i){
				A=0;B=0;
				cout<<"please input your numbers:"<<endl;
				cin>>g_num[0]>>g_num[1]>>g_num[2];
				for(j=0;j<3;++j){
					for(k=0;k<3;++k){
						if(g_num[j]==num[k]&&j==k) A+=1;
						if(g_num[j]==num[k]&&j!=k) B+=1;
					}
				}
				if(A==3) {
					cout<<"congratuation! you win!"<<endl;
					win+=1;
					break; 
				}
				else cout<<A<<'A'<<B<<'B'<<endl;
			}
			if(i==7&&A!=3){
				cout<<"Sorry!You do not guess the right answer,the answer is:"<<num[0]<<num[1]<<num[2]<<endl;
				lose+=1;
			}
			
		}
	}
	return 0;
}

