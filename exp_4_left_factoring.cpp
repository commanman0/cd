#include <iostream>
#include <string>
using namespace std;
int main()
{
    int n,i,j,k,l;
    int len[10]={};
    string P,b1,b2,prod;
    char T;
    cout<<"Enter Parent Non-Terminal:-";
    cin>>T;
    P.push_back(T);
    b1+=P+"\'->";
    b2+=P+"\'\'->";
    P+="->";
    cout<<"Enter the total number of productions:-";
    cin>>n;
    for (int i=0;i<n;i++)
    {
        cout<<"Enter the Production Rule"<<i+1<<":";
        cin>>prod;
        len[i]=prod.size();
        P+=prod;
        if(i!=n-1)
            P+="|";
    }
    cout<<"The Production Rule is:-"<<P<<endl;
    char x=P[3];
    for(i=0,k=3;i<n;i++)
    {
        if(x!=P[k])
            while(P[k++]!='|');
        else
        {
            if(P[k+1]!='|')
            {
                b1+="|"+P.substr(k+1,len[i]-1);
                P.erase(k-1,len[i]+1);
            }
            else
            {
                b1+="#";
                P.insert(k+1,1,P[0]);
                P.insert(k+2,1,'\'');
                k+=4;
            }
        }
    }
    char y=b1[6];
    for(i=0,k=6;i<n-1;i++)
    {
        if(y==b1[k])
        {
            if(b1[k+1]!='|')
            {
                prod.clear();
                for(int s=k+1;s<b1.length();s++)
                    prod.push_back(b1[s]);
                b2+="|"+prod;
                b1.erase(k-1,prod.length()+2);
            }
            else
            {
                b1.insert(k+1,1,b1[0]);
                b1.insert(k+2,2,'\'');
                b2+="#";
                k+=5;
            }
        }
    }
    b2.erase(b2.size()-1);
    cout<<"After Left Factoring:-"<<endl;
    cout<<P<<endl;
    cout<<b1<<endl;
    cout<<b2<<endl;
    return 0;
}