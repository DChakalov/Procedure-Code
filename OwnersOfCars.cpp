//FN: 45050, Dinko Nikolaev Chakalov;

/*Poneje, ne popitah kakvo tochno oznachava "ako db-save.dat ne syshtestvuva vse edno e bil prazen" 
sym zakomentiral proverkite za tova, dali faila e otvoren uspeshno. Ako pri puskane, faila
ne syshtesvuva, pod syotvetnite imena na kolonite ne se izpisva nishto.*/

#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
	
using namespace std;


const int NAME_SIZE = 23;
const int N_OF_CARS = 4;


struct Owner
{
	char owner[NAME_SIZE];
	int regNumber;
	int idCar;
};


int CarReport(Owner* owners, int hpOfCars[N_OF_CARS], int allRecords, double hpAvgOfAllCars, const char* mostCommonCar);
int GetInformation (ifstream& ownerInf, int hpOfCars[N_OF_CARS], char names[N_OF_CARS][NAME_SIZE], int allRecords);
int AddOwner(char names[N_OF_CARS][NAME_SIZE]);


int main()
{
	Owner currAcc;
	char names[N_OF_CARS][NAME_SIZE] = { "Lambordgini Murcielago", "Mercedes - AMG", "Pagani Zonda R", "Bugatti Veyron" };
	int hpOfCars[N_OF_CARS] = { 670, 503, 740, 1020 };
	int allRecords= 0;
	int choice = 0;

	ifstream ownerInf;
	ownerInf.open("db-save.dat", ios::in | ios::binary);

	/*if (!ownerInf)
	{
		cerr << "File couldn't be opened!" << endl;
		ownerInf.close();
		return 1;
	}*/
	
	cout << setiosflags(ios::left) << setw(10) << "OWNER"
		<< setw(15) << "REG. NUMBER" << setw(10)
		<< "ID NUMBER" << endl;

	cout << "\n";

	while (ownerInf)
	{
		ownerInf.read((char*)(&currAcc), sizeof(Owner));
		if (ownerInf)
		{
			cout << setiosflags(ios::left) << setw(13) << currAcc.owner
				<< setw(15) << currAcc.regNumber << setw(10)
				<< currAcc.idCar << endl;

				allRecords++;
		}
			
	}

	//cout << allRecords;

	ownerInf.close();

	cout << "\n" << "Enter \"1\" for new record or \"0\" to end: " << endl;
	cin >> choice;
	switch (choice)
	{
		case 0:	return 0;
		case 1:	if (AddOwner(names))
				{
					return 1;
				} 
				break;
		default: return 1;
	}

	ownerInf.open("db-save.dat", ios::in | ios::binary);

	if (!ownerInf)
	{
		cerr << "File couldn't be opened!" << endl;
		ownerInf.close();
		return 1;
	}
	else
	{
		GetInformation(ownerInf, hpOfCars, names, allRecords+1);
	}

	ownerInf.close();

	return 0; 
}

int AddOwner(char names[N_OF_CARS][NAME_SIZE])
{
	Owner accounts;
	Owner newAcc;
	char p[5];
	cout << "\nEnter owner name: ";
	cin.getline(p, 5);
	cin.getline(newAcc.owner, NAME_SIZE);
	cout << "\nEnter car registration number: ";
	cin >> newAcc.regNumber;
	cout << "\n"; 
	
	if (newAcc.regNumber < 1000 || newAcc.regNumber > 9999)
	{
		cout << "Wrong registration number!" << endl;
		return 1;
	}

	ifstream checkFile("db-save.dat", ios::in | ios::binary);

	/*if (!checkFile)
	{
		cerr << "File couldn't be opened!" << endl;
		checkFile.close();
		return 1;
	}*/

	checkFile.read((char*)(&accounts), sizeof(Owner));

	while (checkFile)
	{
		if (newAcc.regNumber == accounts.regNumber)             // Proverqva dali registracionniq e izpozvan predi.
		{
			cout << "Registration number already exist !" << endl;
			checkFile.close();
			return 1;
		}

		checkFile.read((char*)(&accounts), sizeof(Owner));
	}

	checkFile.close();
	
	cout << "Enter car ID: ";
	cin >> newAcc.idCar;
	cout << "\n";
	
	if (newAcc.idCar > 3 || newAcc.idCar < 0)                                // Proverka za validen ID nomer.
	{
		cout << "Wrong ID ! " << "\n" << "Available cars: " << endl;
		for (int i = 0; i < N_OF_CARS; i++)
		{
			cout << names[i] << ", ID - " << i << endl;
		}

		cout << endl;
		return 1;
	}


	ofstream putInFile("db-save.dat", ios::out | ios::app | ios::binary);
				 
	/*if (!putInFile)
	{
		cerr << "File couldn't be opened!" << endl;
		putInFile.close();
		return 1;
	}*/

	putInFile.write((const char*)(&newAcc), sizeof(Owner));
	putInFile.close();

	return 0;
}

int GetInformation(ifstream& ownerInf, int hpOfCars[N_OF_CARS], char names[N_OF_CARS][NAME_SIZE], int allRecords)
{
	Owner *owners = new Owner[allRecords];
	int idCurrCar = 0;
	int mostCommonCar[N_OF_CARS];
	double hpAvgOfAllCars = 0.0;
	int index = 0;

	for (int i = 0; i < sizeof(mostCommonCar)/sizeof(int); i++)
	{
		mostCommonCar[i] = 0;
	}

	while (ownerInf)
	{
		ownerInf.read((char*)(&owners[index]), sizeof(Owner));

		if (ownerInf)
		{
			hpAvgOfAllCars += hpOfCars[owners[index].idCar];    //Nakraq, hpAvgOfAllCars sydyrja obshtata moshtnost na vsichki koli (zapisi).
			idCurrCar = owners[index].idCar;					//Posle q delim na broq na kolite, za da namerim srednata stoinost.
			for (int i = 0; i < N_OF_CARS; i++)
			{
				if (idCurrCar == i)
				{
					mostCommonCar[i]++;            //Indeksyt, na nai-golqmata stoinost v 
				}									//masiva mostCommonCar syotvetstva na indeksa, na nai-populqrnata kola v masiva names.
			}

			index++;
		}
	}

	hpAvgOfAllCars /= allRecords;		//Sredna moshtnost na vsichki pritejavani koli.
	int maxVal = 0;
	index = 0;

	for (int i = 0; i < N_OF_CARS; i++)     
	{
		if (mostCommonCar[i] > maxVal)
		{
			maxVal = mostCommonCar[i];
			index = i;						//Stoinostta na index nakraq, e indeksyt na nai-populqrnata kola v masiva names.
		}
	}
	
	CarReport(owners, hpOfCars, allRecords, hpAvgOfAllCars, names[index]);
	
	delete[] owners;

	return 0;
}

int CarReport(Owner* owners, int hpOfCars [N_OF_CARS], int allRecords, double hpAvgOfAllCars, const char* mostCommonCar)
{

	ofstream carInformation("car-report.txt", ios::out);

	/*if (!carInformation)
	{
		cerr << "File couldn't be opened!" << endl;
		return 1;
	}*/

	carInformation << mostCommonCar << endl;
	carInformation << hpAvgOfAllCars << endl;
	double sumOfHp = 0.0;

	for (int i = 0; i < allRecords; i++)
	{
		if (owners[i].owner[0] != '#')
		{
			sumOfHp = hpOfCars[owners[i].idCar];
			for (int j = i + 1; j < allRecords; j++)
			{
				if (!strcmp(owners[i].owner, owners[j].owner))
				{
					owners[j].owner[0] = '#';					//Taka imeto na vseki shte se ima predvid samo vednuj, 
					sumOfHp += hpOfCars[owners[j].idCar];       //za da ima samo po edin red za vseki sobstvenik v car-report.txt.
				}
			}													//Nakraq na sumOfHp sydyrja obshtata moshtnost na vsichki koli na tekushtiq sobstvenik.

			carInformation << owners[i].owner << '\t' << sumOfHp << endl;
			sumOfHp = 0;
		}
	}

	return 0;
}