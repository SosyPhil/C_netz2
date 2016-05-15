#include "header007.h"

using namespace std;

int int_char(char y){
	int x=0;
	x = (int)y - 48; 
	return x;
}

int main(){

string input,x_c;
int x,c_last,c_cryp_001,endll=0;
int *dArray;


ofstream file_a;
file_a.open ("file_a.txt");

cout<<"hal66gg"<<endl;

getline(cin,input);
dArray = new int[input.length()-1];			//<-- array list

for(int i=0;i<=input.length()-1;i++){
	x=input.at(i);
	if(x<100 && x>0){
		//INT TO STRING
		int int_u;
		ostringstream uh; uh<<x; string num_u = "0" + uh.str();
		int_u=int_char(num_u);
		dArray[x] = int_u;
		file_a<<num_u;
		//GET LAST DIGIT
		if(i==input.length()-1){
			c_last=int_char(num_u.at(2));
		}
	}else if(x<0){
		x=x*(-1)+300;
		file_a<<x;
		if(i==input.length()-1){
			 int c_last = x % 100;
			 c_last = x % 10;
		}
	}else{
		ostringstream oh; oh<<x; string num_o = oh.str();
		file_a<<num_o;
		//GET LAST DIGIT
		if(i==input.length()-1){
			c_last=int_char(num_o.at(2));
		}
	}
	endll++;
	if(endll==40){
		file_a<<endl;
		endll=0;
	}
}

	file_a.close();
	getch();
	return 0;
}


