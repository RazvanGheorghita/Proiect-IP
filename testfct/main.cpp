#include <iostream>
#include <string.h>
using namespace std;
const int lmax=6;
const int vmax=50;
typedef string expresie;
struct Vectori
{
    string info[50];
    int nr;
}vec;
char expr[1000];
void test(char expr[],Vectori& vec)
{
    int i=0;
    vec.nr=0;
    while(i<strlen(expr))
    {
        vec.info[i]=vec.info[i]+expr[i];
        cout<<vec.info[i]<<"|";
        i++;
        vec.nr++;
    }
}
void Vectorizare (char expr[], Vectori& vec)
{
	unsigned int i,j;
	i=0;
	j=0;
	while(i<strlen(expr))
	{
		if((expr[i]=='s')||(expr[i]=='c')||(expr[i]=='e')||(expr[i]=='l'))
		{
			if(expr[i]!='l')
			{
				vec.info[j]=vec.info[j]+expr[i]+expr[i+1]+expr[i+2];
				j++;
				i=i+3;
			}
			else
			{
				vec.info[j]=vec.info[j]+expr[i]+expr[i+1];
				j++;
				i=i+2;
			}
		}
		else
        {
            if((expr[i]=='(')||(expr[i]==')')||(expr[i]=='+')||(expr[i]=='-')||(expr[i]=='*')||(expr[i]=='/'||(expr[i]=='^')||(expr[i]=='x')))
            {
                vec.info[j]=vec.info[j]+expr[i];
                j++;
                i++;
            }
            else
            {
                while((expr[i]=='0')||(expr[i]=='1')||(expr[i]=='2')||(expr[i]=='3')||(expr[i]=='4')||(expr[i]=='5')||(expr[i]=='6')||(expr[i]=='7')||(expr[i]=='8')||(expr[i]=='9'))
                {
                    vec.info[j]=vec.info[j]+expr[i];
                    i++;
                }
                j++;
            }
        }
	}
	vec.nr=j;
}

int main()
{
    cin.get(expr,255);
    cout<<strlen(expr);
    Vectorizare(expr,vec);
    cout<<endl;
    for(int i=0;i<vec.nr;i++)
    cout<<vec.info[i]<<" ";
    return 0;
}
