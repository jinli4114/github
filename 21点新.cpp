#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

char get_color(char color[4]);
char get_card(char card[13]);
float get_number(int n,char store[50][2]);
void show_card(int n,char store[50][2]);


int main(){
	bool flag=true;
	char choose;
	while(flag){                                                  //while to play game many times 
		cout<<"New game?(Y/N)"<<endl;
		cin>>choose;
		if(choose=='N') {
			cout<<"Game over"<<endl;
			flag=false;
		}
		if(choose=='Y'){
			cout<<"Player time"<<endl;
			char color[4]={'1','2','3','4'},card[13]={'A','2','3','4','5','6','7','8','9','W','J','Q','K'},man_store[50][2],next;
			bool a=true,judge,b=true;
			float man_total;
			int n=2,i;
			man_store[0][0]=get_color(color);                     //Player get two cards first
			man_store[0][1]=get_card(card);
			man_store[1][0]=get_color(color);
			man_store[1][1]=get_card(card);
			while(man_store[1][1]==man_store[0][1]&&man_store[1][0]==man_store[0][0]){
				man_store[1][0]=get_color(color);
				man_store[1][1]=get_card(card);
			}
			man_total=get_number(n,man_store);
			cout<<"Player get card:";
			show_card(n,man_store);
			cout<<endl;
			do{
				cout<<"order more card?(Y/N)";
				cin>>next;
				if(next=='N'){
					a=false;
					break;
				}
				else if(next=='Y'){
					do{
						judge=false;
						man_store[n][0]=get_color(color);
						man_store[n][1]=get_card(card);
						for(i=0;i<n;++i){
						    if(man_store[i][0]==man_store[n][0]&&man_store[i][1]==man_store[n][1]) {
							    judge=true;
							    break;
					        }
					    }
					}while(judge);
					n+=1;
					cout<<"continue to order a card:";
					show_card(n,man_store);
					cout<<endl;
					man_total=get_number(n,man_store);
					if(man_total>21.0){
						cout<<"Player lose"<<endl;
						b=false;
						break;
					}
				}
			}while(a);
			if(b){                                                 //Computer time(the same as Player)
				cout<<"Computer time"<<endl;
				float computer_total;
				char computer_store[50][2];
				int m=2,j;
				bool q,e=true;
				computer_store[0][0]=get_color(color);
			    computer_store[0][1]=get_card(card);
			    computer_store[1][0]=get_color(color);
			    computer_store[1][1]=get_card(card);
			    while(computer_store[1][1]==computer_store[0][1]&&computer_store[1][0]==computer_store[0][0]){
				    computer_store[1][0]=get_color(color);
				    computer_store[1][1]=get_card(card);
			    }
			    computer_total=get_number(m,computer_store);
			    cout<<"Computer get card:";
			    show_card(m,computer_store);
			    cout<<endl;
			    while(computer_total<=man_total){
			    	do{
			    		q=false;
			    		computer_store[m][0]=get_color(color);
			    	    computer_store[m][1]=get_card(card);
			    	    for(j=0;j<m;++j){
			    		    if(computer_store[j][0]==computer_store[m][0]&&computer_store[j][1]==computer_store[m][1]){
			    			    q=true;
			    			    break;
						    }
					    }
			    	}while(q);
			    	m+=1;
			    	cout<<"continue to order a card:";
			    	show_card(m,computer_store);
			    	cout<<endl;
			    	computer_total=get_number(m,computer_store);
			    	if(computer_total>21.0){
			    		cout<<"Player win"<<endl;
			    		e=false;
			    		break;
					}
					else if(computer_total==21.0&&computer_total==man_total){
						if(n<m){
							cout<<"Player win"<<endl;
						}
						else if(n=m){
							cout<<"Draw"<<endl;
						}
						     else cout<<"Player lose"<<endl;
						e=false;
						break;
					}
				}
				if(e){
					cout<<"Player lose"<<endl;
				}
			}
		}
	}
}

char get_color(char color[4]){                                   //the function to get cards' color 
	srand(time(NULL));
	return color[rand()%4];
}

char get_card(char card[13]){                                   //the function to get cards' number 
	srand(time(NULL));
	return card[rand()%13];
}

float get_number(int n,char store[50][2]){                       //the function to sum the cards' numbers 
	float number;
	int i;
	for(i=0;i<n;++i){
		if(store[i][1]=='A') number+=1.0;
	    else if(store[i][1]=='J'||store[i][1]=='Q'||store[i][1]=='K') number+=0.5;
	         else if(store[i][1]=='W') number+=10.0;
	              else number+=store[i][1]-'0';
	}
	return number;
}

void show_card(int n,char store[50][2]){                         //the function to show cards
	int i;
	for(i=0;i<n;++i){
		if(store[i][1]!='W'){
			switch(store[i][0]-'0'){
			    case 1:cout<<"Spade"<<store[i][1]<<'\t';break;
			    case 2:cout<<"Heart"<<store[i][1]<<'\t';break;
			    case 3:cout<<"Club"<<store[i][1]<<'\t';break;
			    case 4:cout<<"Diamond"<<store[i][1]<<'\t';break;
		    }
		}
		else {
			switch(store[i][0]-'0'){
			    case 1:cout<<"Spade"<<10<<'\t';break;
			    case 2:cout<<"Heart"<<10<<'\t';break;
			    case 3:cout<<"Club"<<10<<'\t';break;
			    case 4:cout<<"Diamond"<<10<<'\t';break;
		    }
		}
		
	}
}
