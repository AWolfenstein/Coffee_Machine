#include <iostream>
#define CUPS 7
#define PASSWORD 1234
using namespace std;

double getBalance(double currentBalance);
int getCountOfCups(int emptyCups);
int decreaseCupFromCoffeeMachine(int emptyCups);
double getMoney(double currentBalance, double allCash);

//void showWarning();
bool isCorrectInputMoney(double inputMoney);
double setMoney(double inputMoney);

double getMissingAmount(double inputMoney);
void showMissingAmountError(double missingAmmount);
bool isPaid(double currentBalance, double coffeePrice);

bool isCorrectPassword(int inputPass);
int setBlockMachine();



double updateBalance(double inputMoney, double currentBalance);
void showMoneyLessInput();

int main()
{
	int emptyCups=CUPS;
	double mon,balance;
	double PRICE=2.0;
	int password;
    cout<<"Password :";
    cin>>password;
    cout<<endl;
    cout<<isCorrectPassword(password);
/*	if(getCountOfCups(emptyCups)==0){
		setBlockMachine();
		return 1;
	}
	cout<<"Input money: ";
	cin>>mon;
	mon=setMoney(mon);
	balance=updateBalance(mon,balance);
    cout<<balance<<endl;
    cout<<"PAID: "<< isPaid(balance,PRICE)<<endl;
    cout<<"Empty cups: "<<emptyCups<<endl;
    cout<<"Current balance: "<<balance<<endl;
    emptyCups=decreaseCupFromCoffeeMachine(emptyCups);
    balance=updateBalance(-PRICE,balance);
    cout<<"Empty cups: "<<emptyCups<<endl;
    cout<<"Current balance: "<<balance<<endl;*/
    return 0;
}

double getBalance(double allCash){
	return allCash;
}
int getCountOfCups(int emptyCups){
	return emptyCups;
}
int decreaseCupFromCoffeeMachine(int emptyCups){
	emptyCups--;
	return emptyCups;
}
double getMoney(double currentBalance, double allCash){
	currentBalance=0;
	return allCash;
}
void showMoneyLessInput(){
	cout<<"The denomination of this bill is less than the allowed"<<endl;
}
bool isCorrectInputMoney(double inputMoney){
	if(inputMoney<1){
		showMoneyLessInput();
		return false;
	}else{
		return true;
	}
	
}
double setMoney(double inputMoney){
	if( isCorrectInputMoney(inputMoney)==true){
		return inputMoney;
	}
}
double missingAmount(double currentBalance, double coffeePrice ){
	 return coffeePrice-currentBalance;
}
bool isPaid(double currentBalance, double coffeePrice){
	 
	 if(currentBalance>=coffeePrice){
	 	return true;
	 }else{
	 	showMissingAmountError(missingAmount(currentBalance, coffeePrice));
	 	return false;
	 }
	
}
void showMissingAmountError(double missingAmmount){ 
	cout<<"Please deposit "<<missingAmmount<<"BYR"<<endl;
}
int setBlockMachine(){	
	return 1;
}
double updateBalance(double inputMoney, double currentBalance){
	currentBalance+=inputMoney;
	return currentBalance;
}
bool isCorrectPassword(int inputPass){
	if(inputPass==PASSWORD){
		return true;
	}else{
		return false;
	}
}

