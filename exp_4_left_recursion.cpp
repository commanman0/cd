#include<iostream>
#include<string>
using namespace std;
int main()
{
    int n,i,j,k,l;
    int len[10]={};
    string P,a,b,prod;
    char T;
    cout<<"Enter Parent Non-Terminal:-";
    cin>>T;
    P.push_back(T);
    a+=P+"\'->";
    P+="->";
    b+=P;
    cout<<"Enter the number of productions:-";
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the Production Rule:-"<<i+1<<":";
        cin>>prod;
        len[i]=prod.size();
        P+=prod;
        if(i!=n-1)
            P+="|";
    }
    cout<<"The Production Rule is:-";
    cout<<P<<endl;
     /*cout<<b<< endl;
      cout<<a<<endl;
      for(int i=0;i<n;i++){
          cout<<len[i]<<endl;
      }
          for(int i=0;i<P.length();i++){
          cout<<i<<" "<<P[i]<<endl;
      }*/
    for(i=0,k=3;i<n;i++)
    {
    //cout<<"k="<<k<<endl;
        if(P[0]!=P[k])
        {
            cout<<"Production number:"<<i+1;
            cout<<" does not have left recursion.";
            cout<<endl;
            if(P[k]=='#')
            {
                b.push_back(P[0]);
                b+="\'";
            }
            else
            {
                for(j=k;j<k+len[i];j++)
                    b.push_back(P[j]);
                k=j+1;
                b.push_back(P[0]);
                b+="\'|";
            }
        }
        else
        {
            cout<<"Production number:"<<i+1;
            cout<< " has left recursion";
            cout<<endl;
            if(P[k]!='#')
            {//cout<<"k="<<k<<endl;
                for(l=k+1;l<k+len[i];l++)
                {
                    //cout<<"P[l]="<<P[l]<<endl;
                    a.push_back(P[l]);
                }
                //cout<<endl<<"l="<<l<<endl;
                k=l+1;
                a.push_back(P[0]);
                a+="\'|";
            }
        }
    }
    a+="#";
    cout<<b<<endl;
    cout<<a<<endl;
    return 0;
}