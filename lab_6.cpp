#include<bits/stdc++.h>
using namespace std;
int Search(vector<pair<int,int>> &A, int l, int r, int a) 
{ 
    if (r >= l) 
    { 
        int middle;
        middle=l + (r - l) / 2; 
        if (A[middle].first == a) return middle; 
        if (A[middle].first > a) return Search(A, l, middle - 1, a); 
  
        return Search(A, middle + 1, r, a); 
    } 
  
    return -1; 
}

int main()
{
    long long int n,q;
    cin>>n>>q;
    long long int max_ID=-1;
    long long int max_recharge=INT_MIN;
    vector<pair<int,int>> queries;
    for(int i=0;i<q;i++)
    {
        int num;
        cin>>num;
        if(num==1)
        {
            int user_id,recharge;
            cin>>user_id>>recharge;
            pair <int,int> node;
            node.first=user_id;
            node.second=recharge;
            
            queries.push_back(node);
        }
        else if(num==2)
        {
            
            pair <int,int> node;
            node.first=-1;
            node.second=0;
            
             queries.push_back(node);
        }
        else
        {
            pair <int,int> node;
            node.first=-2;
            node.second=0;
            
            queries.push_back(node);

        }

    }
    vector<int> vec;
    for(int i=0;i<q;i++)
    {
        if(queries[i].first>0)
        {
            vec.push_back(queries[i].first);
        }
    }
    vector <pair < int,int > > USER_ID;
    sort(vec.begin(),vec.end());
    int y=0;
    for(int i=0;i<vec.size();i++)
    {
        if(vec[i]!=y)
        {
             pair<int,int> p;
            p.first=vec[i];
            p.second=0;
            USER_ID.push_back(p);
        }
        y=vec[i];
    }

    for(int i=0;i<q;i++)
    {
       
        if(queries[i].first>0)
        {
            int s;
            s= queries[i].first;
            int x;
            x=Search(USER_ID, 0, (USER_ID.size()-1),s);
            
            USER_ID[x].second=USER_ID[x].second+queries[i].second;
            if(USER_ID[x].second>max_recharge)
            {
                max_recharge=USER_ID[x].second;
                max_ID=USER_ID[x].first;    
            }
        }
        else if(queries[i].first==-1)
        {
            if(max_ID==-1)
            {
                cout<<"No data available.";
            }
            else
            {
                cout<<"\n\n"<<max_ID;
            }
            cout<<endl;

        }
        else
        {
            cout<<"Invalid Input"<<endl;
        }
        
    }



}
