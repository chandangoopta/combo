# include <iostream>
# include <string>
# include <cstdio>

using namespace std;

long fac(int n) {
	long f;
	for(f=1; n>1; n--) f*=n;
	return f;
}

int swap(string &tekst, int pos, int npos){
	char tmpchr=tekst[pos];
	tekst[pos]=tekst[npos];
	tekst[npos]=tmpchr;
	return 0;
}

int findcombo(string tekst, int pos){
	int teller=1;
	int npos=pos;
	string tmpstr;
	int fact = fac(tekst.size()-pos);
	while(teller<=fact) {
		if(pos<(tekst.size()-1)) pos++;
		if(fact>2){
			tmpstr=tekst; //strcpy(oldtekst,tekst);
			teller+=findcombo(tekst,npos+1);
			tekst=tmpstr; //strcpy(tekst,oldtekst);
			swap(tekst, npos, pos);
		}
		else {
			teller++;
			swap(tekst,npos,pos);
			cout<<tekst<<"\n";
		}
	}
	return fact;
}


int main (int argc, char const* argv[])
{
	string tekst;
	cout<<"Entered a string: ";	cin>>tekst;
	cout<<"Combination: "<<fac(tekst.size())<<endl;
	findcombo(tekst,0);
	return 0;
}

