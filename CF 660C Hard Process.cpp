/*
Contest: Codeforces Education Round 11
Problem : 660C Hard Process
Complexity: O(n)
Language: C++
*/

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define dipw(t)  int t;cin>>t;++t;while(--t)
#define ll long long
#define f(i,a,b) for(i=a;i<b;++i)
#define ln '\n'

//for using vector
#define vt(v,type) vector<type> v
#define pb push_back

int main()
{
  fast           //for faster input operation
  ll n,k;
  cin>>n>>k;     //user inputs

  vt(v,int);      //for storing using inputs
  vt(zero,int);   //for storing only zero in user inputs
  ll i,inp;

  f(i,0,n)        //storing data in vectors v and zero
  {
    cin>>inp;
    v.pb(inp);
    if(inp==0)
    zero.pb(i);
  }

  if(zero.size()==n)    //if all inputs are zero(0)
                    //it means there can be k convertions
                    //therfore k max sequence of 1
  {
    cout<<k<<ln;
    f(i,0,k)
    cout<<1<<" ";

    f(i,0,n-k)
    cout<<0<<" ";
    cout<<ln;
    return 0;
  }

  if(zero.size()==0)    //if all inputs are one(1)
                        //no need to change
  {
    cout<<n<<ln;

    f(i,0,n)
    cout<<1<<" ";
    cout<<ln;
    return 0;
  }

  ll l,r,ml,mr,cnt;
  ll max=INT_MIN;
  l=ml=mr=cnt=0;
  i=0;

  f(r,0,n)
  {
    if(v[r]==0) //if current value is 0
    {
      if(k>cnt) //if we can convert 0 to 1
      {
        ++cnt;
      }
      else    //if we can't convert 0 to 1
      {
        l=zero[i]+1; //shift the lower pointer
                      //to the next 0 in zero vector
        ++i;
      }
    }

    if(max<r-l+1) //check for the max sequence
    {
      ml=l;
      mr=r;
      max=r-l+1;
    }
  }
  cout<<max<<ln; //printing maximum seq. of 1
  f(i,0,n)
  {
    if(i>=ml && i<=mr)
    cout<<1<<" ";     //printing 1 for the range ml<=i>=mr
    else
    cout<<v[i]<<" ";  //printing default value for the rest range
  }
  cout<<ln;

  return 0;
}
