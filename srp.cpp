#include <bits/stdc++.h>
#include<string.h>
#include<conio.h>
using namespace std;
 
struct productions{
    char NT[20];
    char prod[20];
}P[10];

int main(){
    int i,j,k,l,m,n,o,p,q,r,f,stp;
    cout<<"Enter the Number of Productions:-";
    cin>>n;
    char temp[10],inp[10],stack[10],s;
    cout<<"\nEnter the Productions:\n";
    for(i=0;i<n;i++){
        cin>>temp;
        strncpy(P[i].NT,temp,1);
        strcpy(P[i].prod,&temp[3]);
    }
    cout<<"\nEnter the Input:";
    cin>>inp;
    l=strlen(inp);
    stp=i=0;

    s=inp[i];
    stack[stp]=s;
    i++;
    stp++;
 
    cout<<"\n\nStack\tInput\tAction";
    do
    {
        r=1;
        while(r!=0)
        {
            cout<<"\n";

            for(p=0;p<stp;p++)
                cout<<stack[p];
            
            cout<<"\t";
            
            for(p=i;p<l;p++)
                cout<<inp[p];
 
            if(r==2)
            cout<<"\tReduced";
            else
            cout<<"\tShifted";
    
            r=0;
             
            getch();
            for(k=0;k<stp;k++)
            {
                f=0;
 
                for(l=0;l<10;l++)
                {
                    temp[l]='\0';
                }
 
                q=0;
                for(l=k;l<stp;l++) 
                {
                    temp[q]=stack[l];
                    q++;
                }
 
                for(m=0;m<n;m++)
                {
                    o = strcmp(temp,P[m].prod);

                    if(o==0)
                    {
                        for(l=k;l<10;l++)
                        {
                            stack[l]='\0';
                            stp--;
                        }
 
                        stp=k;
         
                        strcat(stack,P[m].NT);
                        stp++;
                        r=2;
                    }
                }
            }
        }

        s=inp[i];
        stack[stp]=s;
        i++;stp++;
 
    }while(strlen(stack)!=1 && stp!=l);
 
    if(strlen(stack)==1)
    {
        cout<<"\n Input String Accepted";
    }
 
    getch();

return 0;
}