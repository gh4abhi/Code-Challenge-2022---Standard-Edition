#include<bits/stdc++.h>
#define ll long long
#define pb push_back
using namespace std;

void inOt()
{
    freopen("input.txt" , "r" , stdin);   // For getting input from input.txt file
    freopen("output.txt" , "w" , stdout);  // Printing the Output to output.txt file
}

class DList
{
    public:
    vector<ll> vect;
    vector<ll> na;
    ll sum;
    DList()
    {
        vect.pb(0);
        vect.pb(0);
        vect.pb(0);
        vect.pb(0);
        sum = 0;
    }
    DList(ll sc, ll tr, ll sr, ll naR, vector<ll> naTemp, ll s)
    {
        vect.pb(sc);
        vect.pb(tr);
        vect.pb(sr);
        vect.pb(naR);
        na = naTemp;
        sum = s;
    }
};
bool cmp(pair<ll,DList> a, pair<ll,DList> b)
{
    if(a.second.vect[0]< b.second.vect[0] and a.second.vect[1]<b.second.vect[1] and a.second.sum>b.second.sum)
        return 1;
     else if(a.second.vect[0]< b.second.vect[0] and a.second.vect[1]<b.second.vect[1] and a.second.sum<b.second.sum)
        {
            if(max(a.second.vect[0]- b.second.vect[0], a.second.vect[1]-b.second.vect[1])<a.second.sum<b.second.sum)
                return 1;
            else
            {
                return 0;
            }
        } 
        else if(a.second.vect[0]< b.second.vect[0] and a.second.vect[1]<b.second.vect[1] and a.second.sum>b.second.sum)
        {
            
        }
    else if(a.second.vect[0]< b.second.vect[0] and a.second.vect[1]<b.second.vect[1])
    {
        if(a.second.vect[0]-b.second.vect[0]<a.second.vect[1]-b.second.vect[1])
            return 1;
        else
            return 0;
    }
    else
        return 0;
}


int main()
{
    #ifndef ONLINE_JUDGE
        inOt();
    #endif
    ll Si, SMax, T, D;
    cin>>Si>>SMax>>T>>D;
    vector<pair<ll, DList>> lis;
    for(ll i=0;i<D;i++)
    {
        ll sc,tr,sr,na;
        cin>>sc>>tr>>sr>>na;
        vector<ll> temp(na);
        ll sum = 0;
        for(ll i=0;i<na;i++)
        {
            cin>>temp[i];
            sum+=temp[i];
        }
        DList sam = DList(sc,tr,sr,na,temp,sum); 
        lis.push_back({i,sam});
    } 

    sort(lis.begin(),lis.end(), cmp);

    for(auto i:lis)
    {
        cout<<i.first<<endl;
    }
}