#include<iostream>
#include<iomanip>
using namespace std;

//* ******************************************* * //

//FUNCTIONS - Obtain Data.
void calculateTyrePreassure_Data();
void calculateFuel_Data();
void calculateFOV_Data();
//FUNCTIONS - Operations.
void calculateTyrePreassure(float,float,float);
void calculateFuel(int,float,float);
void calculateFOV();

int main(){
	int opt_calculator;
	
	do{
		cout<<"\t[ACC] TYRE PREASSURE & FUEL CALCULATOR."<<endl;
	    cout<<"SELECT AN OPTION:"<<endl;
	    cout<<"  1. Calculate Tyre Preassure.";
	    cout<<"\n  2. Calculate Fuel.";
	    cout<<"\n  3. Calculate FOV.";
	    cout<<"\nOPTION: "; cin>>opt_calculator;
	    system("cls");
	}while(opt_calculator <= 0 || opt_calculator > 2);
	
	system("cls");
	switch(opt_calculator){
		case 1: calculateTyrePreassure_Data(); break;
		case 2: calculateFuel_Data(); break;
	}
	
	system("pause");
	return 0;
}

//* ******************************************* * //

void calculateTyrePreassure_Data(){
	int opt_CarClass;
	float normalTyrePreassure, maxTyrePreassure, optimalTyrePreassure;
	
	do{
		cout<<"\t[TYRE PREASSURE CALCULATOR]"<<endl;
	    cout<<"\n.:: Car Class ::."<<endl;
	    cout<<"  1. GT3"<<endl;
	    cout<<"  2. GT4"<<endl;
	    cout<<"OPTION: "; cin>>opt_CarClass;
	}while(opt_CarClass == 0 || opt_CarClass > 2);
	system("cls");
	
	switch(opt_CarClass){
		case 1: cout<<">> Class: GT3"<<endl; break;
		case 2: cout<<">> Class: GT4"<<endl; break;
	}
	
	cout<<"\n> Normal Tyre Preassure [PSI]: "; cin>>normalTyrePreassure;
	cout<<"> Maxinum Tyre Preassure [PSI]: "; cin>>maxTyrePreassure;
	
	if(opt_CarClass == 1){
		optimalTyrePreassure = 27.5;
		calculateTyrePreassure(optimalTyrePreassure,normalTyrePreassure,maxTyrePreassure);
	}else{
		optimalTyrePreassure = 26.5;
		calculateTyrePreassure(optimalTyrePreassure,normalTyrePreassure,maxTyrePreassure);
	}
}

void calculateTyrePreassure(float optimalTyrePreassure, float normalTyrePreassure, float maxTyrePreassure){
	float differenceTyrePreassure;
	
	differenceTyrePreassure = optimalTyrePreassure-maxTyrePreassure;
	cout<<"\n\t.:: RESULT ::."<<endl;
	cout<<fixed<<">  Tyre Preassurre Difference: "<<setprecision(1)<<differenceTyrePreassure<<" PSI";
	cout<<"\n>  Normal Preassure [+Plus] Difference: "<<normalTyrePreassure+differenceTyrePreassure<<" PSI";
	cout<<"\n"<<endl;
}

//* ******************************************* * //

void calculateFuel_Data(){
	int totalSessionTime;
	float LapTime, fuelPerLap;
	
	cout<<"\t[FUEL CALCULATOR]"<<endl;
	cout<<"\nENTER THE NEEDED VALUES."<<endl;
	cout<<"  > TOTAL RACE LENGTH [Min]: "; cin>>totalSessionTime;
	cout<<"  > TIME PER LAP [Min]: "; cin>>LapTime;
	cout<<"  > FUEL PER LAP: "; cin>>fuelPerLap;
	
	calculateFuel(totalSessionTime,LapTime,fuelPerLap);
}

void calculateFuel(int totalSessionTime, float LapTime, float fuelPerLap){
	int totalLaps;
	
	totalLaps = (totalSessionTime*60)/(LapTime*60);
	
	cout<<"\n\t.::RESULT::."<<endl;
	cout<<"> TOTAL ESTIMATED FUEL: "<<(totalLaps)*fuelPerLap;
	cout<<"\n> TOTAL LAPS: "<<totalLaps+1;
	cout<<"\n"<<endl;
}