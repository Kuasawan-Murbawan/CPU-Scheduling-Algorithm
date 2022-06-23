// Priority Scheduling 

#include<iostream>
#include<algorithm>
using namespace std;

//Create an object for each process
struct Process{
    int NumProcess;
    int BurstTime;
    int ArriveTime;
    int Priority;
    int WaitTime ;
    int ResponseTime;
    int CompleteTime;
    
}A[100], B[100], C[100];

bool arrival(Process A,Process B){
   		 return A.ArriveTime < B.ArriveTime; 
	}
	
bool burstSort(Process A,Process B){
   		 return A.BurstTime < B.BurstTime; 
	}

bool prioSort(Process A,Process B){
	    return A.Priority < B.Priority; 
	}


int main(){
	
	int NoProc;

	cout << "Enter number of process : ";
	cin >> NoProc;
	cout << endl;
	
	cout << "Enter ProcessNumber , Priority , ArrivalTime, BurstTime (ex: 1 2 30 30)\n";
	
	for(int i=0; i<NoProc; i++){
		cin >> A[i].NumProcess;
		cin >> A[i].Priority;
		cin >> A[i].ArriveTime;
		cin >> A[i].BurstTime;
		A[i].WaitTime=-A[i].ArriveTime+1;
	}
	
	
	//Function to determine arrive time 
	sort(A,A+NoProc,arrival);
	
	int TakenTime=0,i, j,TimeArray[NoProc], ATime=0;
    bool Last=false;
    
    for(int i=0 ; i<NoProc ; i++){
        ATime+=A[i].BurstTime;
    }
    
    ATime+=A[0].ArriveTime;
    
    int QueueTime = 1;
    int a = 0 , b = 0, c = 0;
    
    for(int i=0; TakenTime<= ATime; ){
    	
        j=i;
        while(A[j].ArriveTime <= TakenTime && j!= NoProc){
            B[c]=A[j];
            j++;
            c++;
        }
        
        if(c == b){
            C[a].NumProcess= 'i';
            C[a].BurstTime = A[j].ArriveTime-TakenTime;
            C[a].ArriveTime=TakenTime;
            TakenTime+=C[a].BurstTime;
            a++;
            continue;
        }
        
        i=j;
        
        if(Last == true){
            sort(B+b,B+c,prioSort);
        }
  
        j=b;
        
        if(B[j].BurstTime > QueueTime){
            C[a]=B[j];
            C[a].BurstTime = QueueTime;
            a++;
            B[j].BurstTime = B[j].BurstTime - QueueTime;
            TakenTime += QueueTime;  
            Last =true;
            
            for(int m = 0 ; m < NoProc ; m++){
                if(B[j].NumProcess != A[m].NumProcess){
                    A[m].WaitTime += QueueTime;
                }
            }
        }
        
        else{
            C[a]=B[j];
            a++;
            b++;
            TakenTime += B[j].BurstTime;  
            Last=false;
            
            for(int m=0; m<NoProc ; m++){
                if(B[j].NumProcess != A[m].NumProcess ){
                    A[m].WaitTime += B[j].BurstTime;
                }
            }
        }
        if(b==c && i>=NoProc)
        break;
    }
    
    TimeArray[i] = TakenTime;
    TakenTime += A[i].BurstTime;
    
    for(int i=0; i<a-1; i++){
    	
        if(C[i].NumProcess == C[i+1].NumProcess) {
            C[i].BurstTime += C[i+1].BurstTime;
            
            for(j=i+1;j<a-1;j++)
                C[j]=C[j+1];
            a--;
            i--;
        }
    }
    
    int Responsetime=0;
    
    for(j=0;j<NoProc;j++){
    	
        Responsetime =0;
        for(int i=0;i<a;i++){
            if(C[i].NumProcess == A[j].NumProcess){
                A[j].ResponseTime = Responsetime ;
                break;
            }
            Responsetime +=C[i].BurstTime;
        }
    }


    cout<<"\n----------------Gantt Chart Timeline----------------\n\n";
    
    Responsetime=0;
    
    for (int i=0; i<a; i++){
        if(i!=a)
            cout<<"|  "<<'P'<< C[i].NumProcess << "   "; 
        Responsetime += C[i].BurstTime;
        for(j=0;j<NoProc;j++){
            if(A[j].NumProcess == C[i].NumProcess)
                A[j].CompleteTime = Responsetime;
        } 
    }
    
    cout<<endl;
    Responsetime=0;
    for (i=0; i<a+1; i++)
	{
        cout << Responsetime << "\t";
        TimeArray[i] = Responsetime ;
        Responsetime += C[i].BurstTime; 
    }
    
    cout<<"\n\n----------------------------------------------------\n\n";
    
    float avgWaitingTime=0;
    float avgTAT=0;
	
	//Display in table form
    cout<<"PName Priority Arrive\tBurst\tTAT\tWT\t\n";
    for (i=0; i<NoProc && A[i].NumProcess !='i' ; i++ ){
    	
        if(A[i].NumProcess=='\0')
            break;
            
        cout <<'P'<< A[i].NumProcess << "\t" ;
		cout << A[i].Priority << "\t";
        cout << A[i].ArriveTime << "\t";
		cout << A[i].BurstTime << "\t";
        cout << A[i].WaitTime + A[i].CompleteTime - Responsetime + A[i].BurstTime << "\t";
		avgTAT += A[i].WaitTime + A[i].CompleteTime - Responsetime + A[i].BurstTime;
		
        cout << A[i].ResponseTime - A[i].ArriveTime << "\t";
        avgWaitingTime += A[i].WaitTime + A[i].CompleteTime - Responsetime;
        
        cout <<"\n"; 
        
    }
    cout<<"Average Waiting time: "<<(float) avgWaitingTime / NoProc <<endl;
    cout<<"Average TA time: "<<(float)avgTAT / NoProc <<endl;
}
