
#include <iostream>
#include <map>
using namespace std;
int adj_mat[50][50]={0};
int main()
{
    int n;
    cout<<"Enter the number of cities : ";
    cin>>n;
    string cities[n];
    map<string,int>cityIndex;

    for (int i=0;i<n;i++)
    {
        cout<<"Enter the airport code for city "<<i+1<<" : ";
        cin>>cities[i];
        cityIndex[cities[i]]=i;
    }
    cout<<"\n Your cities are -\n";
    for(int i=0;i<n;i++)
    {
        cout<<"city #"<<i+1<<cities[i]<<endl;
    }
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            cout<<"Enter distance between "<<cities[i]<<" and "<<cities[j]<<" : ";
            cin>>adj_mat[i][j];
            adj_mat[j][i]=adj_mat[i][j];
        }
    }
    cout<<endl;
    cout<<"\t";
    for(int i=0;i<n;i++)
    {
        cout<<cities[i]<<"\t";
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<cities[i]<<"\t";
        for(int j=0;j<n;j++)
        {
            cout<<adj_mat[i][j]<<"\t";
        }
        cout<<endl;
    }
    string city1,city2;
    cout<<"Enter the name of city 1 : ";
    cin>>city1;
    cout<<"Enter the name of city 2 : ";
    cin>>city2;

    if(cityIndex.find(city1)==cityIndex.end()||cityIndex.find(city2)==cityIndex.end())
    {
        cout<<"One of the cities is not in the list."<<endl;
    }
    else{
    int index1=cityIndex[city1];
    int index2=cityIndex[city2];
    if(adj_mat[index1][index2]>0)
    {
        cout<<"There is a direct connection between "<<city1<<" and "<<city2;
    }
    else{
        cout<<"There is no direct connection between "<<city1<<" and "<<city2;
    }
    }
return 0;
}
