#include<bits/stdc++.h>
using namespace std;
void rabincarp(char Text[],char patt[],int d, int q)
{
	int n=strlen(Text);
	int m=strlen(patt);
	long int h = long(pow(d, m-1)) % q;
	long int p=0, t=0;
	for (int i=0; i<m; i++)
	{
		p = (p*d+(patt[i]-'a'+1)) % q;
		t = (t*d+(Text[i]-'a'+1)) % q;
	}
	cout << "Pattern Hashcode= "<<p<<endl<<endl;
	for (int s=0; s<=n-m; s++)
	{
		cout << "T"<<s <<"="<<t<<endl;
		if (p == t)
		{//cout<<"hii";
			int flag = 1;
			for (int i=0; i<m; i++)
			{
				if (patt[i] != Text[s+i])
				{
				flag = 0;
				break;
				}
			}
			if (flag)
				cout << "Pattern matches with shift " << s << endl;
		}
		if (s<n-m)
			t = (((t - (Text[s]-'a'+1)*h)*d)+(Text[s+m]- 'a'+1)) % q;
	}
}



int main()
{
char p[100], t[500];
char ch;
int d=10,q=10000;
cout << "Enter the pattern to match: ";
cin >> p;
do
{
cout << "Enter the text: ";

cin >> t;
rabincarp(t,p,d,q);
cout << "Do you want search in another text (y/n) ? ";
cin >> ch;
}
while (ch == 'y' || ch == 'Y');
return 0;
}
