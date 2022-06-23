#include <iostream>
using namespace std;

int main(){
	
	int cont, choose;
	
	while(cont == 0){
		cout << "Algorithm Available\n";
		cout << "1. First In First Out\n";
		cout << "2. Shortest Job First\n";
		cout << "3. Shortest Time Remaining\n";
		cout << "4. Priority Scheduling\n";
		cout << "5. Round Robin\n";
		cout << "6. Earliest Deadline First\n";
		cout << "0. Exit\n";
		cout << "Choose the algorithm (number only): \n\n";
		cin >> choose;
	
		switch(choose){
			
			case 1: system("First_In_First_Out.exe");
				break;
			
			case 2: system("Shortest_Job_First.exe");
				break;
			
			case 3: system("Shortest_Remaining_Time.exe");
				break;
				
			case 4: system("Priority_Scheduling.exe");
				break;
				
			case 5: system("Round_Robin.exe");
				break;
				
			case 6: system("Earliest_Deadline_First.exe");
				break;
				
			case 0: cout << "\nThank you for checking us out!" << endl;
					exit(0);
				break;
			
			default: cout << "Please enter a valid number!" << endl;
		}
			
	cout <<endl;
	cout << "Do you want to continue: ( Yes = 0 / No = 1 ) ";
	cin >> cont;
	cout << endl; 
	}
	
		
	return 0;


}