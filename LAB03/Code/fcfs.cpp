#include<iostream>

using namespace std;

struct process
{
    int id=0;
    int wait=0;
    int burst=0;
    int turnaround=0;
};

int main()
{
    cout<<"Advait Deochakke\n20BCE1143\nEnter number of processes for FCFs: ";
    int n;
    int ttlwait=0, ttlturnaround=0;
    cin>>n;
    process arr[n];
    for(int i=0; i<n; i++)
    {
        cout<<"\nEnter PiD: ";
        cin>>arr[i].id;
        cout<<"\nEnter Burst time: ";
        cin>>arr[i].burst;
    }
    arr[0].wait=0;
    arr[0].turnaround=arr[0].burst;

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            arr[i].wait=arr[i].wait+arr[j].burst;
        }
        arr[i].turnaround=arr[i].wait+arr[i].burst;
        ttlturnaround=ttlturnaround+arr[i].turnaround;
        ttlwait=ttlwait+arr[i].wait;

    }

    int avgturnaround, avgwait;
    avgturnaround=ttlturnaround/n;
    avgwait=avgturnaround/n;
    cout<<"Avg waiting time is : "<<avgwait<<endl;
    cout<<"Avg turnaround is : "<<avgturnaround<<endl;

    cout<<"\n\nStats for each process: \n";
    for(int i=0; i<n; i++)
    {
        cout<<"PiD: "<<arr[i].id<<", PWait: "<<arr[i].wait<<", PBurst: "<<arr[i].burst<<", PTurn: "<<arr[i].turnaround<<endl;
    }

    return 0;
}