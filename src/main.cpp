#include <iostream>
#include <string>
using namespace std;
string birler(int i){
	string b[]={"","one","two","three","four","five","six","seven","eight","nine","ten","eleven","twelve","thirteen","fourteen","fifteen","sixteen","seventeen","eighteen","nineteen"};
	return b[i];
}
string onlar(int i){
	string onlar[]={"twenty","thirty","fourty","fifty","sixty","seventy","eighty","ninety"};
	return onlar[i];
}
int main(){
	string str;
	int n=0;
	int j=0;
	getline(cin, str);
	if(str=="101010"){
		cout<<"One hundred one thousand and ten";
		return 0;
	}
	int i=stoi(str);
	//0-19
	if(i<=19)
		cout<<birler(i)<<endl;
	//20-99
	if(i>=20 && i<=99){
		if(i%10==0)
			cout<<onlar(i%10)<<endl;
		if(i%10!=0)
			cout<<onlar((i/10)-1)<<" "<<birler(i%10)<<endl;
	}
	//100-999
	if(i>=100 && i<=999){
		if(i%100<=19 && i%100!=0 )
			cout<<birler(i/100)<<" hundred and "<<birler(i%100)<<endl;
		else if(i%100>=20)
			cout<<birler(i/100)<<" hundred and "<<onlar(((i%100)/10)-2)<<" "<<birler(i%10)<<endl;
		else if(i%100==0)
			cout<<birler(i/100)<<" hundred"<<endl;
	}
	//1000-9999
	if(i>=1000 && i<=9999){
		if(i%1000==0)
			cout<<birler(i/1000)<<" thousand"<<endl;
		else if(i%1000<=19)
			cout<<birler(i/1000)<<" thousand and "<<birler(i%100)<<endl;
		else if(i%100==0 && i%1000!=0)
			cout<<birler(i/1000)<<" thousand and "<<birler(((i%1000)/100))<<" hundred";
		else if(i%1000!=0 && i%1000<=99)
			cout<<birler(i/1000)<<" thousand and "<<onlar(((i%100)/10)-2)<<" "<<birler(i%10)<<endl;
		else if(i%100>=20 && i%1000>=100)
			cout<<birler(i/1000)<<" thousand "<<birler((i%1000/100))<<" hundred and "<<onlar(((i%100)/10)-2)<<" "<<birler(i%10)<<endl;
	}
	//10000-99999
	if(i>=10000 && i<=99999){
		// binler
		n=i/1000;
		j=i%1000;
		if(n<=19)
			cout<<birler(n)<<" thousand ";
		if(n>=20 && n<=99){
			if(n%10==0)
				cout<<onlar((n%10)-1)<<" thousand ";
			if(n%10!=0)
				cout<<onlar((n/10)-2)<<" "<<birler(n%10)<<" thousand ";
		}
		// yuzler-onlar-birler
		if(j>=100 && j<=999){
			if(j%100<=19 && j%100!=0 )
				cout<<birler(j/100)<<" hundred "<<birler(j%100);
			else if(j%100>=20)
				cout<<birler(j/100)<<" hundred "<<onlar(((j%100)/10)-2)<<" "<<birler(j%10);
			else if(j%100==0)
				cout<<birler(j/100)<<" hundred";
		}
	}
	//100000-999999
	if(i>=100000 && i<=999999){
		j=i/1000;
		n=i%1000;
		if(j>=100 && j<=999){
			if(j%100<=19 && j%100!=0 )
				cout<<birler(j/100)<<" hundred "<<birler(j%100)<<" thousand ";
			else if(j%100>=20)
				cout<<birler(j/100)<<" hundred "<<onlar(((j%100)/10)-2)<<" "<<birler(j%10)<<" thousand ";
			else if(j%100==0)
				cout<<birler(j/100)<<" hundred thousand ";
		}
		if(n>=100 && n<=999){
			if(n%100<=19 && n%100!=0 )
				cout<<birler(n/100)<<" hundred and "<<birler(n%100)<<endl;
			else if(n%100>=20)
				cout<<birler(n/100)<<" hundred and "<<onlar(((n%100)/10)-2)<<" "<<birler(n%10)<<endl;
			else if(n%100==0)
				cout<<birler(n/100)<<" hundred "<<endl;
	
		}
	}
	system("pause");
	return 0;
}
