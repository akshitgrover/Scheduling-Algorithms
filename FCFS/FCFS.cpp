#include<iostream>
using namespace std;
int main(){
    int n,arv[25],burst[25],name[25];
    cin>>n; //!Number of processes.
    for(int i=0;i<n;i++){
        cin>>burst[i]; //!Burst Time.
        cin>>arv[i]; //!Arrival Time.
        name[i]=i; //! Name of process.
    }
    //! Using Selection sort:
    int flag;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(arv[i]>arv[j]){
                flag=arv[i];
                arv[i]=arv[j];
                arv[j]=flag;
                flag=burst[i];
                burst[i]=burst[j];
                burst[j]=flag;
                flag=name[i];
                name[i]=name[j];
                name[j]=flag;
            }
        }
    }
    cout<<"Process Execution order is: ";
    for(int i=0;i<n;i++){
        cout<<name[i]<<" ";
    }
    float tur_aro=0;
    float wait=burst[0];
    for(int i=1;i<n;i++){
        wait+=tur_aro;
        tur_aro+=burst[i]+wait;
    }
    cout<<"\nAverage Waiting Time Is: "<<wait/(float)n;
    cout<<"\nAverage TurnAround Time Is: "<<tur_aro/(float)n;
    return 0;
}
