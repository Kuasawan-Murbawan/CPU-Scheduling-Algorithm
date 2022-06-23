// Shortest Remaining Time 

#include <bits/stdc++.h>
using namespace std;

struct Process{
    int NumProcess;
    int BurstTime;
    int ArriveTime;
}process[1000];

// Main function
int main()
{
	int n;
   	cout << "Enter number of process\n";
	cin >> n;
	cout << endl;
	
	cout << "Enter ProcessNumber ArrivalTime, BurstTime (ex: 1 30 30)\n";
	
	for(int i=0; i<n; i++){
		cin >> process[i].NumProcess;
		cin >> process[i].ArriveTime;
		cin >> process[i].BurstTime;
	}
    
    //cout<<n;
    
    int WaitingTime[n], Turnaroundtime[n];
    int totalWaitingTime = 0, totalTATtime = 0;
    
    //Waiting Time 
    int ReTime[n];
    
    for (int i = 0; i < n ; i++)
    	ReTime[i] = process[i].BurstTime;
        
    int Completed = 0, Time = 0, minimum = INT_MAX , ShortestProc = 0, Finish;
    bool Check = false;
    
    while(Completed != n){
    	
    	//Process to find minimum time remaining 
    	 for (int k = 0; k < n; k++) {
            if ((process[k].ArriveTime <= Time) && (ReTime[k] < minimum) && ReTime[k] > 0) {
                minimum = ReTime[k];
                ShortestProc = k;
                Check = true;
            	}
        	}
        
       	 if (Check == false){
        	Time++;
        	continue;
			}
		
		ReTime[ShortestProc]--;
		
		minimum = ReTime[ShortestProc];
			if (minimum == 0)
				minimum = INT_MAX;
			
		if (ReTime[ShortestProc] == 0){
			
			Completed++;
			Check == false;
			
			Finish = Time + 1;
  
           //To calculate Waiting Time
            WaitingTime[ShortestProc] = Finish-process[ShortestProc].BurstTime-process[ShortestProc].ArriveTime;

            if (WaitingTime[ShortestProc] < 0)
    			WaitingTime[ShortestProc] = 0;
        	}
      	
        Time++;
		}
		
    
    //Calculate the turnaroundtime
    for (int i = 0; i < n; i++){
    	Turnaroundtime[i] = process[i].BurstTime + WaitingTime[i];
	}
        
    
   	//Display the output 
   	cout<<"Shortest Remaining Time \n\n";
    cout << " P\t" << "BT\t" << "WT\t" << "TAT\t\n";
  
    //Calculate total waiting time and total turnaround time
    for (int i = 0; i < n; i++) {
        totalWaitingTime = totalWaitingTime + WaitingTime[i];
        totalTATtime = totalTATtime + Turnaroundtime[i];
        cout << " " << process[i].NumProcess << "\t" << process[i].BurstTime << "\t" << WaitingTime[i] << "\t" << Turnaroundtime[i] << endl;
    }
  
  	float TotalWaitingTime , TotalTATtime;
  	
  	TotalWaitingTime = totalWaitingTime;
  	TotalTATtime =  totalTATtime;
  	
  	
  	cout << endl;
  
  	cout<< endl;
    cout << "Average waiting time = " << TotalWaitingTime / (float)n << endl;
    cout << "Average turn around time = " << TotalTATtime / (float)n;

 
    return 0;
}
