/*
	Final Project 4/18/2024
	Made by: Nathaniel McGahey
	In this program, the user is asked to randomly generate a choosen number of patients and will test those patients to see if they have covid, the flu, or a cold.
	The program then prints outs the information for the user to see
*/

#include <iostream>
#include <time.h>

using namespace std;

//This the base class patient. This class holds each of the symptoms and the function to randomize the if the patient has them or not
class patient{
public:
	//These are the patient class instance variables
	string fever;
	string cough;
	string shortBreath;
	string runnyNose;
	string headaches;
	string sneezing;
	string fatigue;
	
	//This is function instanciation for randomDiseases
	patient randomDiseases(patient);
};

//This is the base class disease. This holds the random patient list and is the parent to each of the diseases.
class patientList: public patient{
	//These are the diesease class instance variables
	int patientNum;
	patient patientLists[400];
	
	//This constructor allows for a construction of a disease with a patient array and a int. Both of these represent the instance variables
	disease(patient patients[], int num){
		for(int x = 0; x < num; x++){
			patientList[x] = {patients[x]};
		}
		patientNum = num;
	}
	
	//This constructor allows for a construction of a disease without any constructors.
	disease(){
		patientNum = 0;
		patientList;
	}
	
	//This is the function instanciation for checkSymptoms
	void checkSymptoms(disease);
};

//This is the base class disease. This holds the random patient list and is the parent to each of the diseases.
class disease{
public:
	//These are the diesease class instance variables
	int patientNum;
	patient patientList[400];
	
	//This constructor allows for a construction of a disease with a patient array and a int. Both of these represent the instance variables
	disease(patient patients[], int num){
		for(int x = 0; x < num; x++){
			patientList[x] = {patients[x]};
		}
		patientNum = num;
	}
	
	//This constructor allows for a construction of a disease without any constructors.
	disease(){
		patientNum = 0;
		patientList;
	}
	
	//This is the function instanciation for checkSymptoms
	void checkSymptoms(disease);
};

//This is a child class to Disease. This has the symptoms present for the disease and the count of the people with the disease
class COVID19: public disease{
public:
	string fever="present";
	string cough="present";
	string shortBreath="present";
	string runnyNose="sometimes";
	string headaches="sometimes";
	string sneezing="absent";
	string fatigue="sometimes";
	int covidCount = 0;
};

//This is a child class to Disease. This has the symptoms present for the disease and the count of the people with the disease
class cold: public disease{
public:
	string fever="sometimes";
	string cough="sometimes";
	string shortBreath="absent";
	string runnyNose="present";
	string headaches="sometimes";
	string sneezing="present";
	string fatigue="sometimes";
	int coldCount = 0;
};

//This is a child class to Disease. This has the symptoms present for the disease and the count of the people with the disease
class flu: public disease{
public:
	string fever="present";
	string cough="present";
	string shortBreath="absent";
	string runnyNose="sometimes";
	string headaches="present";
	string sneezing="absent";
	string fatigue="present";
	int fluCount = 0;
	
};


//This function takes a patient and randomises if the patient has each of the dieases and returns the patient
patient patient::randomDiseases(patient p){
	//This set of code is repeated for each symptom in which a random number,either 0 - 1, is made and 0 means they dont have the symptom while 1 has it
	int randNum = rand() % 2;
	if(randNum == 1){
		p.fever = "present";
	}else{
		p.fever = "absent";
	}
	
	randNum = rand() % 2;
	if(randNum == 1){
		p.cough = "present";
	}else{
		p.cough = "absent";
	}
	
	randNum = rand() % 2;
	if(randNum == 1){
		p.shortBreath = "present";
	}else{
		p.shortBreath = "absent";
	}
	
	randNum = rand() % 2;
	if(randNum == 1){
		p.runnyNose = "present";
	}else{
		p.runnyNose = "absent";
	}
	
	randNum = rand() % 2;
	if(randNum == 1){
		p.headaches = "present";
	}else{
		p.headaches = "absent";
	}
	
	randNum = rand() % 2;
	if(randNum == 1){
		p.sneezing = "present";
	}else{
		p.sneezing = "absent";
	}
	
	randNum = rand() % 2;
	if(randNum == 1){
		p.fatigue = "present";
	}else{
		p.fatigue = "absent";
	}
	
	return p;
}

//This function uses the different diseases ability to store counts to add up how many of the diseases matches and prints it out
void disease::checkSymptoms(disease d){
	//These different disease functions holds the symptoms of each repectable disease count
	COVID19 covidDisease;
	cold coldDisease;
	flu fluDisease;
	
	//This loop iterates through each patient in the array and checks if their symptoms matches the symptoms of a disease. If they do, the will update the count in the disease
	for(int x = 0; x < d.patientNum; x++){
		if(d.patientList[x].fever == covidDisease.fever && d.patientList[x].cough == covidDisease.cough && d.patientList[x].sneezing == covidDisease.sneezing){
			covidDisease.covidCount++;
		}if(d.patientList[x].shortBreath == coldDisease.shortBreath && d.patientList[x].runnyNose == coldDisease.runnyNose && d.patientList[x].sneezing == coldDisease.sneezing){
			coldDisease.coldCount++;
		}if(d.patientList[x].fever == fluDisease.fever && d.patientList[x].cough == fluDisease.cough && d.patientList[x].shortBreath == fluDisease.shortBreath && d.patientList[x].headaches == fluDisease.headaches && d.patientList[x].sneezing == fluDisease.sneezing && d.patientList[x].fatigue == fluDisease.fatigue){
			fluDisease.fluCount++;
		}
	}
	
	//This prints out the total number of patients with each disease and the rest that dont match the diseases listed
	int otherDisease = d.patientNum - (covidDisease.covidCount + coldDisease.coldCount + fluDisease.fluCount);
	cout << "\nSymptoms Checker\n";
	cout << "======================================================\n";
	cout << covidDisease.covidCount << " patients have COVID-19\n";
	cout << coldDisease.coldCount << " patients have the cold\n";
	cout << fluDisease.fluCount << " patients have the flu\n";
	cout << otherDisease << " patients have other diseases\n";
	cout << "======================================================\n";
	
	//This part prints out the percentages of each illess and represent this with the amount of + marks
	cout << "\nPercentage of each illness\n";
	cout << "COVID-19:      [" << covidDisease.covidCount << "%]:";
	for(int x = 0; x < covidDisease.covidCount; x++){
		cout << "+";
	}
	cout << "\n";
	cout << "Cold:          [" << coldDisease.coldCount << "%]:";
	for(int x = 0; x < coldDisease.coldCount; x++){
		cout << "+";
	}
	cout << "\n";
	cout << "Flu:           [" << fluDisease.fluCount << "%]:";
	for(int x = 0; x < fluDisease.fluCount; x++){
		cout << "+";
	}
	cout << "\n";
	cout << "Other diseases:[" << otherDisease << "%]:";
	for(int x = 0; x < otherDisease; x++){
		cout << "+";
	}
	cout << "\n";
} 
                       

//This function prints the table of the illnesses symptoms to let the user know what each illness symptoms are
void printTable(){
	cout << "Guide:   * Common      + Sometimes/Rarely         - NO\n";
	cout << "======================================================\n";
	cout << "Symptoms            | COVID-19 |   Cold   |    Flu   |\n";
	cout << "======================================================\n";
	cout << "Fever               |    *     |    +     |     *    |\n";
	cout << "Cough               |    *     |    +     |     *    |\n";
	cout << "Shortness of Breath |    *     |    -     |     -    |\n";
	cout << "Runny Nose          |    +     |    *     |     +    |\n";
	cout << "Headaches           |    +     |    +     |     *    |\n";
	cout << "Sneezing            |    -     |    *     |     -    |\n";
	cout << "Fatigue             |    +     |    +     |     *    |\n";
	cout << "======================================================\n\n";
}

//This function is the function that runs the program
void patientRun(){
	//Count variable to hold the amount of patients
	int numPatients;
	
	//Allows the user to see the table of symptoms and to enter the amount of patients they are wanting test
	cout << "Welcome to Symptoms Checker\n\n";
	printTable();
	cout << "Enter the number of patients: ";
	cin >> numPatients;
	
	//This creates the patient array and the patient that we use to do functions with
	patient patientList[numPatients];
	patient p1;	
	
	//This loop goes through each patient in the array and randomly sets their symptoms0
	for(int x = 0; x < numPatients; x++){
		patientList[x] = p1.randomDiseases(p1);
	}
	
	//This creates the disease class and uses that disease to check the sypmtoms of the patients
	disease d1(patientList, numPatients);
	d1.checkSymptoms(d1);
}

//This sets the random to not get the same number on each run and calls the running function	
int main(){
	srand(time(0));
	patientRun();	               
	return 1;
