#include <bits/stdc++.h>
using namespace std;
/*IMPLEMENTATION OF HASH TABLE
TO FIND THE FREQUENCY OF EACH CHARACTER IN A GIVEN STRING*/

int f[200];
int hashf(char key){
	return(key-'!');
}

void countFreq(string s){
	for(int i=0; i<s.length(); i++){
		int idx= hashf(s[i]);
		f[idx]++;
	}

	for(int i=0; i<200; i++)
		if(f[i]!=0)
        	cout<<(char)(i+'!')<<' '<<f[i]<<endl;
}

int main(){
	string s;
	cin>>s;
	countFreq(s);
}