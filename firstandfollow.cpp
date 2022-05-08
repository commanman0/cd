#include<iostream>	
#include<string.h>
using namespace std;
#define max 20
char P[max][10];
char T[10],nT[10];
char fi[10][10],fo[10][10];
int eps[10];
int count=0;
int findpos(char ch)
{
	int n;
	for(n=0;nT[n]!='\0';n++)
    	if(nT[n]==ch)
	        break;
	    if(nT[n]=='\0')
	        return 1;
	    return n;
}
	
int IsCap(char c)
{
	if(c >= 'A' && c<= 'Z')
    	return 1;
	return 0;
}
void add(char *arr,char c)
{
	int i,flag=0;
	for(i=0;arr[i]!='\0';i++)
	{
    	if(arr[i] == c)
	    {
	        flag=1;
	        break;
    	}
	}
	if(flag!=1)
	    arr[strlen(arr)] = c;
}
void addarr(char *s1,char *s2)
{
	int i,j,flag=99;
	for(i=0;s2[i]!='\0';i++)
	{
    	flag=0;
	    for(j=0;;j++)
	    {
	        if(s2[i]==s1[j])
	        {
	            flag=1;
	            break;
	        }
	        if(j==strlen(s1) && flag!=1)
	        {
	            s1[strlen(s1)] = s2[i];
	            break;
	        }
	    }
	}
}
void addprod(char *s)
{
	int i;
	P[count][0] = s[0];
	for(i=3;s[i]!='\0';i++)
	{
    	if(!IsCap(s[i]))
	        add(T,s[i]);
	    P[count][i-2] = s[i];
	}
	P[count][i-2] = '\0';
	add(nT,s[0]);
	count++;
}

void findfirst()
{
	int i,j,n,k,e,n1;
	for(i=0;i<count;i++)
	{
    	for(j=0;j<count;j++)
	    {
	        n = findpos(P[j][0]);
	        if(P[j][1] == (char)238)
            	eps[n] = 1;
	        else
        	{
            	for(k=1,e=1;P[j][k]!='\0' && e==1;k++)
            	{
                	if(!IsCap(P[j][k]))
                	{
                    	e=0;
                    	add(fi[n],P[j][k]);
	                }
	                else
	                {
                    	n1 = findpos(P[j][k]);
                    	addarr(fi[n],fi[n1]);
                    	if(eps[n1] == 0)
                    	    e=0;
                	}
				}
            	if(e==1)
            	    eps[n]=1;
        	}
        }
    }
}
void findfollow()
{
	int i,j,k,n,e,n1;
	n = findpos(P[0][0]);
	add(fo[n],'#');
	for(i=0;i<count;i++)
	{
    	for(j=0;j<count;j++)
	    {
	        k = strlen(P[j])-1;
	        for(;k>0;k--)
	        {
	            if(IsCap(P[j][k]))
            	{
                	n=findpos(P[j][k]);
                	if(P[j][k+1] == '\0')
                	{
                    	n1 = findpos(P[j][0]);
                    	addarr(fo[n],fo[n1]);
                	}
                	if(IsCap(P[j][k+1]))
                	{
                    	n1 = findpos(P[j][k+1]);
                    	addarr(fo[n],fi[n1]);
                    	if(eps[n1]==1)
                    	{
                        	n1=findpos(P[j][0]);
                        	addarr(fo[n],fo[n1]);
                    	}
                	}
                	else if(P[j][k+1] != '\0')
                	    add(fo[n],P[j][k+1]);
                }
    	    }
	    }
	}
}
int main()
{	int n;
	char p[max],i;
	cout<<"Enter the number of productions:-\n";
	cin>>n;
	while(n==0)
	{
		cin>>p;
	    addprod(p);
		n--; 
	}
	findfirst();
	findfollow();
	for(i=0;i<strlen(nT);i++)
	{
    	cout<<nT[i]<<"\t";
    	cout<<fi[i];
    	if(eps[i]==1)
    	    cout<<((char)238)<<"\t";
    	else
    	    cout<<"\t";
        cout<<fo[i]<<"\n";
	}
	return 0;
}