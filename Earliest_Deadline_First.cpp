#include<iostream>
#include<algorithm>
using namespace std; 


struct Process{
    int NumProcess;
    int BurstTime;
    int ArriveTime;
    int deadline;
    int WaitTime=0;
    int ResponseTime;
    int CompleteTime;
    int restTime=0;
    int countTime=0;
    
}A[1000], B[1000], C[1000];

bool arrivalSort(Process A, Process B)
{
	return A.ArriveTime < B.ArriveTime;
}

bool deadlineSort(Process A, Process B)
{
	return A.deadline < B.deadline;
}

bool burstTimeSort(Process A,Process B)
{
    return A.BurstTime < B.BurstTime; 
}
int k=0, f=0, r=0;

void show(int sizeProcess,int qt)
{
	int n=sizeProcess;
	int takenTime=0, j, timeArray[n], allTime=0, q, i;
	bool moveLast=false;
	
	for(int i=0; i<n; ++i)
	{
		allTime+=A[i].BurstTime;
	}
	allTime+=A[0].ArriveTime;
	
	for(  i=0; takenTime<=allTime;)
	{
		j=i;
		
		while(A[j].ArriveTime<=takenTime && j!=n)
		{
			B[r]=A[j];
			++j;
			++r;
		}
		
		if(r==f)
		{
			C[k].NumProcess='i';
			C[k].BurstTime=A[j].ArriveTime-takenTime;
            C[k].ArriveTime=takenTime;
            takenTime+=C[k].BurstTime;
            ++k;
            continue;
		}
		i=j;
        if(moveLast==true)
		{
            sort(B+f,B+r,deadlineSort);
    	}
    	j=f;
    	if(B[j].BurstTime>qt)
		{
            C[k]=B[j];
            C[k].BurstTime=qt;
            ++k;
            B[j].BurstTime=B[j].BurstTime-qt;
            takenTime+=qt;  
            moveLast=true;
            
            for(q=0;q<n;q++)
			{
                if(B[j].NumProcess!=A[q].NumProcess)
				{
                    A[q].WaitTime+=qt;
                }
            }
        }
        else
		{
            C[k]=B[j];
            ++k;
            ++f;
            takenTime+=B[j].BurstTime; 
            moveLast=false;
            
            for(q=0;q<sizeProcess;q++){
                if(B[j].NumProcess!=A[q].NumProcess){
                    A[q].WaitTime+=B[j].BurstTime;
                }
            }
        }
        
        if(f==r&&i>=n)
        break;
	}
	
	timeArray[i]=takenTime;
    takenTime+=A[i].BurstTime;
    
    for(i=0;i<k-1;i++)
	{
        if(C[i].NumProcess==C[i+1].NumProcess)
		{
            C[i].BurstTime+=C[i+1].BurstTime;
            for(j=i+1;j<k-1;j++)
                C[j]=C[j+1];
            --k;
            --i;
        }
    }
	
	int runTime=0;
    for(j=0;j<n;j++){
        runTime=0;
        for(i=0;i<k;i++){
            if(C[i].NumProcess==A[j].NumProcess)
			{
                A[j].restTime=runTime;
                break;
            }
            runTime+=C[i].BurstTime;
        }
    }
    
    float averageWaitingTime=0, averageResponseTime=0, averageTurnaroundTime=0;
    
    cout<<"\nTimeline\n";
    runTime=0;
    
    for (i=0; i<k; i++)
	{
        if(i!=k)
            cout<<"|  "<<'P'<< C[i].NumProcess << "   "; 
        runTime+=C[i].BurstTime;
        for(j=0;j<n;j++)
		{
            if(A[j].NumProcess==C[i].NumProcess)
                A[j].countTime=runTime;
        } 
    }
    
    cout<<endl;
    runTime=0;
    for (i=0; i<k+1; i++)
	{
        cout << runTime << "\t";
        timeArray[i]=runTime;
        runTime+=C[i].BurstTime; 
    }
    cout<<endl;
    
    cout<<"\n";
    cout<<"P.Name Deadline AT\tBT\tTAT\tWT\n";
    
    for (i=0; i<sizeProcess&&A[i].NumProcess!='i'; ++i)
	{
        if(A[i].NumProcess=='\0')
            break;
        cout <<'P'<< A[i].NumProcess << "\t"; 
        cout << A[i].deadline << "\t";
        cout << A[i].ArriveTime << "\t";
        cout << A[i].BurstTime << "\t";
        cout << A[i].WaitTime+A[i].countTime-runTime+A[i].BurstTime << "\t"; 
        averageTurnaroundTime+=A[i].WaitTime+A[i].countTime-runTime+A[i].BurstTime;
        cout << A[i].WaitTime+A[i].countTime-runTime << "\t"; 
        averageWaitingTime+=A[i].WaitTime+A[i].countTime-runTime;  
        cout <<"\n"; 
    }
    cout<<"Average Waiting time: "<<(float)averageWaitingTime/(float)n<<endl;
    cout<<"Average TA time: "<<(float)averageTurnaroundTime/(float)n<<endl;
}
int main()
{
	int sizeProcess, choose, qt, i;
	cout<<"Enter the number of process:";
	cin>>sizeProcess;
	cout<<"Enter the process, burst time, arrival time and deadline (Eg. 1 10 0 20)"<<endl;
	
	for( i=0; i<sizeProcess; ++i)
	{
		cin>>A[i].NumProcess;
		cin>>A[i].BurstTime;
		cin>>A[i].ArriveTime;
		cin>>A[i].deadline;
		A[i].WaitTime=-A[i].ArriveTime+1;
	}
	show(sizeProcess, 1);
	
	return 0;
}
