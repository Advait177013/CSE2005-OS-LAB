#include<iostream>
#include<algorithm>

using namespace std;

struct process
{
int pid;
int btime;
int waitime;
int turnover;
};

bool compareBurst(process p1, process p2)
{
    return(p1.btime < p2.btime);
}

int main()
{
    cout<<"Enter number of processes : ";
    int no;
    cin>>no;
    process arr[no];

    for(int i=0; i<no; i++)
    {
        cout<<"Enter the burst time for pid: "<<i<<": ";
        arr[i].pid=i;
        cin>>arr[i].btime;        
    }

    sort(arr, arr+no, compareBurst);
    int w=0;
    int t=0;
    for(int i=0; i<no; i++)
    {
        arr[i].waitime=w;
        w=w+arr[i].btime;
        arr[i].turnover=arr[i].waitime+arr[i].btime;
        t=t+arr[i].turnover;
    }

    for(int i=0; i<no; i++)
    {
        cout<<"PiD: "<<arr[i].pid<<"; BurstTime: "<<arr[i].btime<<"; WaitTime: "<<arr[i].waitime<<"; TurnoverTime: "<<arr[i].turnover; 
        cout<<endl;
    }

    cout<<endl;
    cout<<"Avg turnaround time: "<<t/no<<endl;

    return 0;
}