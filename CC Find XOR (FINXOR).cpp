/* Time Complexity = O(t)
   Space Complexity = O(1) */

#include <bits/stdc++.h>
using namespace std;

#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);

#define dipw(t)  int t;cin>>t;++t;while(--t)
#define ll long long
#define f(i,a,b) for(i=a;i<b;++i)
#define ln '\n'

//vector
#define vt(v,type) vector<type> v
#define vtn(v,n,type) vector<type> v(n)
#define pb push_back
#define bg begin()
#define ed end()

#define ff first
#define ss second

#define MOD 1000000007
#define dec_eq 1048576

void sublimeFile()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

static ll n1;  //for checking
ll a[]={1 , 1, 1 ,1}; 


//for getting xor of Ai for all valid i
ll grader_ans()
{
  ll sum=0,i;
  f(i,0,n1)
  {
    sum^=a[i];
  }
  return sum;
}

//only for testing purpose
//for getting summation of (K ^ Ai) for all values of i
ll grader(ll k)
{
  ll sum=0,i;
  f(i,0,n1)
  sum+= a[i] ^ k;
  return sum;
}


//Note: //add and //remove comments for testing purpuse

int32_t main()
{
  fast
  sublimeFile();
  dipw(t)
  {

    ll n;
    cin>>n; //input the number of elements in unknown sequence

    n1=n;  //remove


    ll tot_sum; //for storing total sum of unknown sequence (A)
    ll input_res; //for storing gradle responses 

    cout<<1<<" "<<dec_eq<<endl; //query for getting tot_sum
    //cin>>tot_sum;           //add

    tot_sum=grader(dec_eq); //remove

    if(tot_sum==-1) //for wrong query
      return 0;


    tot_sum -= dec_eq*n; //calulating total sum

    cout<<"Total Sum:"<<tot_sum<<ln; //remove


    ll i=0; //iteration variable
    ll final_answer=0; //for storing final answer
    ll sub_sum=0; //for storing current value of final answer

    while(i<19)  //for asking 19 queries
    {
      ll cur=1<<i; //to get 2^i
      cout<<1<<" "<<cur<<endl; //query question
      //cin>>input_res; //add
     

      input_res=grader(cur);//remove

       if(input_res==-1){ //for wrong query
        return 0;
        }


      cout<<"grader res: "<<input_res<<ln; //remove

      ll diff=(tot_sum - input_res)/cur; //calculation of difference and then dividing by 2^i
      cout<<"Diff: "<<diff<<ln; //remove

      ll noOfOne; //for storing number of 1's at a particular bit
      if(diff > 0) //number of 1 are more than 0 at a bit
      {
        noOfOne=(n+diff)/2;  //calculation noOfOne
        cout<<"noOfOne "<<noOfOne<<ln; //remove

        sub_sum+=(noOfOne)*cur; //current calculated final answer update
        
        if(noOfOne % 2 != 0) //odd number of 1's
        {
          final_answer+=cur; //final answer value update
          
        }
        cout<<"Final: "<<final_answer<<ln; //remove
      }
      else //for number of 1's are less than 0
      {
        noOfOne=(n+diff)/2; //calculation noOfOne
        cout<<"noOfOne "<<noOfOne<<ln; //remove
        

        sub_sum+=(noOfOne)*cur;  //current calculated final answer update
        if(noOfOne % 2 != 0) //odd
        {
          final_answer+=cur;  //final answer value update

        }
        cout<<"Final: "<<final_answer<<ln; //remove

      }

      ++i; //updating the loop variable
      cout<<ln; //remove

    }

    cout<<"sub_sum: "<<sub_sum<<" "<<tot_sum<<ln;//remove


    //2^20 bit values left but no more queries left therefore
    if(tot_sum != sub_sum) //if final answer not reached
    {
      ll c=(1<<19); //2^20

      cout<<tot_sum - sub_sum<<ln; //remove
      ll d=(tot_sum - sub_sum)/c; //calculating difference from final sum and current sum
      cout<<"d: "<<d<<ln; //remove
      if(d%2!=0) //if number of one are odd then we count this bit vice versa
      {
        final_answer+=c; //updating the final answer
      }
    }

    int check; //for checking for correct solution

    cout<<2<<" "<<final_answer<<endl;

    cout<<"Correct ans: "<<grader_ans()<<ln; //remove

    //cin>>check;  //add
    check=1; //remove
    if(check==-1) //for wrong answer
      return 0;

  }
  return 0;
}
