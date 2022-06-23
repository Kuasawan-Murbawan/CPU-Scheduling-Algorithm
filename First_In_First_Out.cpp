#include<iostream>
using namespace std;
int n=4;


int main()
{
	int numProcess;
	int burstTime[numProcess];
	int arrivalTime[numProcess];
	int waiting[1]={0 };
	int burst=0;
	float totalWaiting=0;
	int averageWaiting=0;
	int averageTurn=0;
	
	cout<<"Enter the number of process:";
	cin>>numProcess;
	cout<<endl;
	for(int i =0; i<numProcess; ++i)
	{
		cout<<"Enter the processes"<<" "<<i+1<<" arrival time and burst time:";
		cin>>arrivalTime[i]>>burstTime[i];
		cout<<"\n";
	}
	
	for(int i=1; i < 4; ++i)
	{
		
		burst+= burstTime[i-1];
		waiting[i]= burst - arrivalTime[i];	
		
		cout<< waiting[i]<< " ";	
		totalWaiting+=waiting[i];	
	}
	cout << "Average Waiting Time:"<< totalWaiting/n;
	cout << "\n" ;
	
	float totalTurn=0;
	int turnaround[]={0};
	
	burst=0;
	for( int i=0; i<4; ++i)
	{
		
		burst+= burstTime[i];
		turnaround[i] = burst - arrivalTime[i];
		
		cout << turnaround[i]<<" ";
		totalTurn+= turnaround[i];
	}
	cout << "Average Turnaround Time:" << totalTurn/n;
	
	int totalBurst=0;
	burst=0;
	cout<<"\n";
	for(int i=0; i<n;++i)
	{
		if(i==0)
		{
			cout<<"p"<<i+1;
			totalBurst+=burstTime[i];
			do
			{
				burst+=10;
				cout<<"-";	
			}while(burst<totalBurst);
		}
		else
		{
			cout<<"p"<<i+1;
			totalBurst+=burstTime[i];
			
			do
			{
			
				burst+=10;
				cout<<"-";
			}while(burst<totalBurst);
		}
		
		
	}

	
	return 0;	
}






