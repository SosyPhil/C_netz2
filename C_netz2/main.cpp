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
/*string *int_b_str(int *x,int length){
	string *str_i;
	for(int i=0;i<=length;i++){
		for(int j=0;j<=2;j++){
			

		}
	}

}*/
string binary(int x){
	
string bina="";
int c=1,i=512;

do{
	if(x>=i){bina=bina + "1";x=x-i;
	}else{bina=bina + "0";}
	c++; i=i/2;
	}while(c<=10);
	return bina;	
}
int main(){

// -------define Variables
string input,x_c;

int x,c_last,c_cryp_001,endll=0;
int *dArray;
// ---------



//------ OPEN FILE
ofstream file_a;
file_a.open ("file_a.txt");
// --------- 

cout<<"ha3534634636"<<endl;

getline(cin,input); // << INPUT

int lenght_str=input.length()-1;
dArray = new int[lenght_str];

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

//---------- GET NUMBER OF RANDOM
if(c_last>=4 && c_last<=6){
	dArray[lenght_str+1]=get_digit(dArray[1],c_last-3);
}else if(c_last>=7 && c_last<=9){
	dArray[lenght_str+1]=get_digit(dArray[2],c_last-6);
}else{
	dArray[lenght_str+1]=get_digit(dArray[0],c_last);
}
//----------------------

string *bin = new string [lenght_str+1];


for(int i=0;i<=lenght_str;i++){
		dArray[i] = dArray[i]+dArray[lenght_str+1];		 // PLUS THE num_to_rand
		bin[i]=binary(dArray[i]);						 // GET BINARY to STRING
		cout<<bin[i]<<endl;								
	}



	


	file_a.close();
	getch();
	return 0;
}


//ostringstream uh; uh<<x; string num_u = "0" + uh.str();