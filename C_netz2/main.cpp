#include "header007.h"

using namespace std;

int int_char(char y){
	int x=0;
	x = (int)y - 48; 
	return x;
}
int last_digit(int num){
	int x=0;
	x = num % 100;
	x = x % 10;
	return x;
}
int get_digit(int dig, int pos){
	switch (pos){
	case 1:
		return dig/100;
		break;
	case 2:
		dig=dig%100;
		return dig/10;
		break;
	case 3:
		dig=dig%100;
		return dig%10;
		break;
	}
}
int main(){

string input,x_c;
int x,c_last,c_cryp_001,endll=0;
int *dArray;


ofstream file_a;
file_a.open ("file_a.txt");

cout<<"ha33333llo"<<endl;

getline(cin,input);
int lenght_str=input.length()-1;
dArray = new int[lenght_str];			//<-- array list

for(int i=0;i<=lenght_str;i++){
	x=input.at(i);
	if(x<100 && x>0){
		//INT TO STRING
		x=x+500;
		dArray[i] = x;
		file_a<<x;
		//GET LAST DIGIT
		if(i==lenght_str){
			c_last=last_digit(x);
		}
	}else if(x<0){
		x=x*(-1)+300;
		dArray[i] = x;
		file_a<<x;
		if(i==input.length()-1){
			c_last = last_digit(x);
		}
	}else{
		dArray[i] = x;
		file_a<<x;
		//GET LAST DIGIT
		if(i==lenght_str){
			c_last = last_digit(x);
		}
	}
	endll++;
	if(endll==40){
		file_a<<endl;
		endll=0;
	}
}


if(c_last>=4){
	int x=0;
	x=(c_last%3);
	c_last=c_last/3;
	if(x==0){
		c_last--;
		x=3;
	}
	dArray[lenght_str+1]=get_digit(dArray[c_last],x);
}else{
	dArray[lenght_str+1]=get_digit(dArray[0],c_last);
}

	for(int i=0;i<=lenght_str+1;i++){
		cout<<dArray[i]<<endl;
	}


	file_a.close();
	getch();
	return 0;
}


//ostringstream uh; uh<<x; string num_u = "0" + uh.str();