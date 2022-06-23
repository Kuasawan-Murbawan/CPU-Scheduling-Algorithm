#include<iostream>
#include <algorithm>

using namespace std;
int main()
{
      int i, j, temp;
      int trem_bt1=0, trem_bt2=0, trem_bt3=0;
      float tottt = 0, totwt = 0;
      float avgtt, avgwt;

      int at[] = {0, 1, 2};
	  int bt[] = {3, 5, 7};
	  int ct[3]; 
	  int tt[3];
	  int wt[3];
	  int rem_bt[3];
	  
	  for (int i = 0 ; i < 3 ; i++)
        rem_bt[i] = bt[i];
	  
	  for(i=0; i<3; i++)
      {
      	for(j=i+1; j<3; j++)
        {
            if(rem_bt[j] < rem_bt[i])
            {
                temp = rem_bt[i];
                rem_bt[i] = rem_bt[j];
                rem_bt[j] = temp;
            }
        }
      }
      
      for(i=0; i<1; i++)
      {
      	trem_bt1 += rem_bt[i];
	  }
	  ct[0] = trem_bt1;
       
      for(i=0; i<2; i++)
      {
      	trem_bt2 += rem_bt[i];
	  }
	  ct[1] = trem_bt2;
	  
	  for(i=0; i<3; i++)
      {
      	trem_bt3 += rem_bt[i];
	  }
	  ct[2] = trem_bt3;

  
      for(i=0;i<3;i++)
      {
        tt[i] = ct[i] - at[i];
        wt[i] = tt[i] - bt[i];
      }
      
      cout<<"Process\tArrival Time\tBurst TimeT\tCT\tTT\tWT\n";
      
      for(i=0;i<3;i++)
      {
        cout<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tt[i]<<"\t"<<wt[i]<<"\n";
      }
      
      for(i=0;i<3;i++)
      {
        tottt = tottt + tt[i];
        totwt = totwt + wt[i];
      }
      
      avgtt = tottt/3;
      avgwt = totwt/3;
      
      cout<<"\n"<<"Average turnaround time : "<<avgtt<<" "<<"\nAverage waiting time : "<<avgwt;

    return 0;
}
