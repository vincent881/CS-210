//Vincent Messina
//10/2
#include <iostream>
#include <iomanip>

using namespace std;

//declare variables to store imput
float initialInvest, monthlyDep, annualInterest, months, years;
//declare variables to store year end total amount, interest, and year end interest
float totalAmount, initialAmount, yearTotalInterest;
//function to display form to user
void displayForm() {
	cout << "******************************" << endl;
	cout << "********* Data Input *********" << endl;
	cout << "Initial Investment Amount:" << endl;
	cout << "Monthly Deposit:" << endl;
	cout << "Annual Interest:" << endl;
	cout << "Number of years:" << endl;
}
//function to get input from user
void dataInput() {
	cout << "******************************" << endl;
	cout << "********* Data Input *********" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvest;
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDep;
	cout << "Annual Interest: %" << endl;
	cin >> annualInterest;
	cout << "Number of years:" << endl;
	cin >> years;
	//calculate months based on years inputted
	months = years * 12;
}
//display year data without monthly deposits
void withoutMonthly() {
	cout << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "Year     Year End Balance     Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;
	
	for (int i = 0; i < years; i++) {
		//calculate yearly interest
		initialAmount = (totalAmount) * ((annualInterest / 100));
		//calculate year end total
		totalAmount = totalAmount + initialAmount;
		//print results to table
		cout << (i + 1) << "		$" << fixed << setprecision(2) << totalAmount << "            $" << initialAmount << endl;
	}
	cout << endl;
}
//display year data with monthly deposits
void withMonthly() {
	cout << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "========================================================" << endl;
	cout << "Year     Year End Balance     Year End Earned Interest" << endl;
	cout << "--------------------------------------------------------" << endl;

	for (int i = 0; i < years; i++) {
		//set yearly interest to zero
		yearTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			//calculate monthly interest
			initialAmount = (totalAmount + monthlyDep) * ((annualInterest / 100) / 12);
			//calculate month end interest
			yearTotalInterest = yearTotalInterest + initialAmount;
			//calculate month end total
			totalAmount = totalAmount + monthlyDep + initialAmount;
		}
		//print results to table
		cout << (i + 1) << "		$" << fixed << setprecision(2) << totalAmount << "            $" << yearTotalInterest << endl;
	}
}
int main() {
	//display form to user
	displayForm();
	//pause to wait for input from user
	system("PAUSE");
	//get data from user
	dataInput();
	//pause to wait for input from user
	system("PAUSE");
	//set total amount to initial investment to be updated
	totalAmount = initialInvest;
	//display without monthly deposits
	withoutMonthly();
	//set total amount to initial investment to be updated
	totalAmount = initialInvest;
	//display with monthly deposits
	withMonthly();

	return 0;
}