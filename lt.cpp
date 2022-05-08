#include<bits/stdc++.h>
using namespace std;
#include<string.h>
int NT,T,top=0;
char prod[50],nt[10],t[10],l[10][10],tr[50][50];
int search_nt(char a)
{
    for(int i=0;i<NT;i++)
        if(nt[i]==a)
            return i;

    return -1;

}

int search_t(char a)
{
    for(int i=0;i<T;i++)
        if(t[i]==a)
            return i;

    return -1;
}

void push(char a){
    prod[top]=a;
    top++;
}

char pop()
{
    top--;
    return prod[top];
}

void assign_l(int a,int b)
{
    if(l[a][b]=='f')
    {
        l[a][b]='t';
        push(t[b]);
        push(nt[a]);
    }
}

void assign_t(int a,int b)
{
    if(tr[a][b]=='f')
    {
        tr[a][b]='t';
        push(t[b]);
        push(nt[a]);
    }
}
int main()
{
    int i,j,k,n,s;
    char p[30][30],b,c;
    cout<<"Enter the numner of productions:-";
    cin>>n;
    cout<<"Enter the productions:-\n";
    for(i=0;i<n;i++)
        cin>>p[i];
    
    NT=0;
    T=0;
    for(i=0;i<n;i++)
    {
        if((search_nt(p[i][0]))==-1)
            nt[NT++]=p[i][0];
    }
    for(i=0;i<n;i++)
    {
        for(j=3;j<strlen(p[i]);j++)
        {
            if(search_nt(p[i][j])==-1)
            {
                if(search_t(p[i][j])==-1)
                    t[T++]=p[i][j];
            }
        }
    }
    for(i=0;i<NT;i++)
    {
        for(j=0;j<T;j++)
            l[i][j]='f';
    }
    for(i=0;i<NT;i++)
    {
        for(j=0;j<T;j++)

            tr[i][j]='f';
    }
    for(i=0;i<NT;i++)
    {
        for(j=0;j<n;j++)
        {
            if(nt[(search_nt(p[j][0]))]==nt[i])
            {
                if(search_t(p[j][3])!=-1)
                    assign_l(search_nt(p[j][0]),search_t(p[j][3]));
                else
                {
                    for(k=3;k<strlen(p[j]);k++)
                    {
                        if(search_nt(p[j][k])==-1)
                        {
                            assign_l(search_nt(p[j][0]),search_t(p[j][k]));
                            break;
                        }
                    }
                }
            }
        }
    }
    while(top!= 0)
    {
        b=pop();
        c=pop();
        for(s=0;s<n;s++)
        {
            if(p[s][3]==b)
                assign_l(search_nt(p[s][0]), search_t(c));
        }
    }
    for(i=0;i<NT;i++)
    {
        cout<<"Leading["<<nt[i]<<"]"<<"\t{";
        for(j=0;j<T;j++)
        {
            if(l[i][j]=='t')
                cout<<t[j]<<",";
        }
        cout<<"}\n";
    }

    top=0;
    for(i=0;i<NT;i++)
    {
        for(j=0;j<n;j++)
        {
            if(nt[search_nt(p[j][0])]==nt[i])
            {
                if(search_t(p[j][strlen(p[j]) - 1]) != -1)
                    assign_t(search_nt(p[j][0]),search_t(p[j][strlen(p[j])-1]));
                else
                {
                    for(k=(strlen(p[j])-1);k>=3;k--)
                    {
                        if(search_nt(p[j][k])==-1)
                        {
                            assign_t(search_nt(p[j][0]),search_t(p[j][k]));
                            break;
                        }
                    }
                }
            }
        }
    }
    while(top!=0)
    {
        b=pop();
        c=pop();
        for(s=0;s<n;s++)
        {
            if(p[s][3]==b)
                assign_t(search_nt(p[s][0]),search_t(c));
        }
    }
    for(i=0;i<NT;i++)
    {
        cout <<"Trailing["<<nt[i]<<"]"<<"\t{";
        for(j=0;j<T;j++)
        {
            if(tr[i][j]=='t')
                cout<<t[j]<<",";
        }
        cout<<"}\n";
    }
    return 0;
}
    
