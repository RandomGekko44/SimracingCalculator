#include<iostream>
#include<iomanip>
using namespace std;

//* ******************************************* * //

// CLASES
//***TYRE PREASSURE & FUEL CALCULATOR*** //
class GT{
	private:
		//Tyre preassure variables.
		int carClass;
		float normalTyrePreassure, maxTyrePreassure;
		//fuel variables.
		int totalSessionTime;
		float timePerLap, fuelPerLap;
	public:
		//Preassure Calculator: Constructor.
		GT(float,float,int);
		//Fuel Calculator: Constructor.
		GT(int,float,float);
		void calculateTyrePreassure();
		void calculateFuel();
};

GT::GT(float _normalTyrePreassure, float _maxTyrePreassure, int _carClass){
	normalTyrePreassure = _normalTyrePreassure;
	maxTyrePreassure = _maxTyrePreassure;
	carClass = _carClass;
}

GT::GT(int _totalSessionTime, float _timePerLap, float _fuelPerLap){
	totalSessionTime = _totalSessionTime;
	timePerLap = _timePerLap;
	fuelPerLap = _fuelPerLap;
}

void GT::calculateTyrePreassure(){
	float idealTyrePreassure = 0, differenceTyrePreassure;
	if(carClass == 1){
		idealTyrePreassure = 27.5;
	}else{
		idealTyrePreassure = 26.5;
	}
	
	differenceTyrePreassure = idealTyrePreassure-maxTyrePreassure;
	cout<<"\n\t.:: RESULT ::."<<endl;
	cout<<fixed<<">  Tyre Preassurre Difference: "<<setprecision(1)<<differenceTyrePreassure<<" PSI";
	cout<<"\n>  Normal Preassure [+Plus] Difference: "<<normalTyrePreassure+differenceTyrePreassure<<" PSI";
	cout<<"\n"<<endl;
}

void GT::calculateFuel(){
	int totalLaps;
	
	totalLaps = (totalSessionTime*60)/(timePerLap*60);
	
	cout<<"\n\t.::RESULT::."<<endl;
	cout<<"> TOTAL ESTIMATED FUEL: "<<(totalLaps)*fuelPerLap;
	cout<<"\n> TOTAL LAPS: "<<totalLaps+1;
	cout<<"\n"<<endl;
}

//* ******************************************* * //
// FUNCTIONS
void dataObtain_TyrePreassure();
void dataObtain_Fuel();

int main(){
	int opt_calculator;
	
	do{
		cout<<"\t[ACC] TYRE PREASSURE & FUEL CALCULATOR."<<endl;
	    cout<<"SELECT AN OPTION:"<<endl;
	    cout<<"  1. Calculate Tyre Preassure.";
	    cout<<"\n  2. Calculate Fuel.";
	    cout<<"\nOPTION: "; cin>>opt_calculator;
	    system("cls");
	}while(opt_calculator <= 0 || opt_calculator > 2);
	
	system("cls");
	switch(opt_calculator){
		case 1: dataObtain_TyrePreassure(); break;
		case 2: dataObtain_Fuel(); break;
	}
	
	system("pause");
	return 0;
}

//* ******************************************* * //

void dataObtain_TyrePreassure(){
	int opt_CarClass;
	float normalPreassure, maxPreassure;
	
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
	
	cout<<"\n> Normal Tyre Preassure [PSI]: "; cin>>normalPreassure;
	cout<<"> Maxinum Tyre Preassure [PSI]: "; cin>>maxPreassure;
	
	if(opt_CarClass == 1){
		GT car_gt3 = GT(normalPreassure,maxPreassure,opt_CarClass);
		car_gt3.calculateTyrePreassure();
	}else{
		GT car_gt4 = GT(normalPreassure,maxPreassure,opt_CarClass);
		car_gt4.calculateTyrePreassure();
	}
}

void dataObtain_Fuel(){
	int totalSessionTime;
	float timePerLap, fuelPerLap;
	
	cout<<"\t[FUEL CALCULATOR]"<<endl;
	cout<<"\nENTER THE NEEDED VALUES."<<endl;
	cout<<"  > TOTAL RACE LENGTH [Min]: "; cin>>totalSessionTime;
	cout<<"  > TIME PER LAP [Min]: "; cin>>timePerLap;
	cout<<"  > FUEL PER LAP: "; cin>>fuelPerLap;
	
	GT fuel_gt = GT(totalSessionTime,timePerLap,fuelPerLap);
	fuel_gt.calculateFuel();
}





