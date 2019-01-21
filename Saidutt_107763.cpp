#include<iostream>
#include<string>
using namespace std;

class Person {
public:
	int Id;
	string firstName, lastName,group;
	void acceptPerson() {
		cout << "Enter Id" << endl;
		cin >> Id;
		cout << "Enter FirstName" << endl;
		cin >> firstName;
		cout << "Enter LastName" << endl;
		cin >> lastName;
		cout << "Enter Group" << endl;
		cin >> group;
		cout << endl;
	}
	void displayPerson() {
		cout << "Id: " << Id << " FirstName: " << firstName << " LastName: " << lastName <<" Group: "<<group<< endl;
	}
	};

	class UgStudent:public Person {
	public:
		string UG_Group;
	  void	assignGroup(string m) {
		  UG_Group = m;
		}
	  void printGroup() {
		  cout << UG_Group << endl;
	  }
	};
	
	class Sports {
	public:
		string sportName;
		void assignSportName(string sp) {
			sportName = sp;
		}
		void printSport() {
			cout << sportName << endl;
		}
	};
	
	class PGStudent : public UgStudent,public Sports{
	public:
		string PG_Group;
	};
	
	int main() {
		PGStudent pgObj[25];
		pgObj[0].Id = 1001;
		pgObj[0].firstName = "Sai";
		pgObj[0].lastName = "dutt";
		pgObj[0].group = "CSE";

		pgObj[1].Id = 1002;
		pgObj[1].firstName = "Ranjith";
		pgObj[1].lastName = "Kumar";
		pgObj[1].group = "CSE";

		pgObj[2].Id = 1003;
		pgObj[2].firstName = "Nava";
		pgObj[2].lastName = "Teja";
		pgObj[2].group = "CSE";


		int choice,sid,temp=0;
		string sfname, slname, group;
		 int pos = 3;
		do{
		cout << "\n1.Enter 1 to add data in student array\n2.Enter 2 to display data from array\n3.Enter 3 to search data\n4.Enter 4 to update data\n5.Enter 5 to Delete data\n6.Enter 6 to Exit" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
			pgObj[pos].acceptPerson();
			pos++;
			break;
		case 2:
				for (int k = 0; k < pos; k++) {
					pgObj[k].displayPerson();
				}
			break;
		case 3:
			temp = 0;
				cout << "Enter id to search" << endl;
				cin >> sid;
				for (int l = 0; l < pos; l++) {
					if (pgObj[l].Id == sid) {
						pgObj[l].displayPerson();
						temp = 1;
					}
					
				}
				
				if (temp == 0) {
					cout << "Id Not found" << endl;
				}
			
			break;
		case 4:
			temp = 0;
			cout << "Enter id to Update" << endl;
			cin >> sid;
			cout << "\n----------------The details of Student:---------------" << endl;
			for (int l = 0; l < pos; l++) {
				if (pgObj[l].Id == sid) {
					temp = 1;
					pgObj[l].displayPerson();
				}
				
			}
			if (temp == 0) {
				cout << "Id Not found" << endl;
			}
			else {
				cout << "\nEnter Updated Student FirstName" << endl;
				cin >> sfname;
				cout << "Enter Updated Student LastName" << endl;
				cin >> slname;
				cout << "Enter Updated Student Group" << endl;
				cin >> group;

				for (int l = 0; l < pos; l++) {
					if (pgObj[l].Id == sid) {
						pgObj[l].firstName = sfname;
						pgObj[l].lastName = slname;
						pgObj[l].group = group;
					}

				}

				cout << "\n--------------------After Updating details of Student:--------------------" << endl;
				for (int l = 0; l < pos; l++) {
					if (pgObj[l].Id == sid) {
						pgObj[l].displayPerson();
					}

				}
			}
			
			break;
		case 5:
			temp = 0;
			cout << "\nEnter id to delete" << endl;
			cin >> sid;
			for (int l = 0; l < pos; l++) {
				if (pgObj[l].Id == sid) {
					temp = 1;
					for (int m = l; m < pos-1; m++) {
						pgObj[m] = pgObj[m + 1];
					}
					pos--;
				}
			}

			if (temp==0) {
				cout<<"Id Not found"<<endl;
			}
			break;
		}
		} while (choice<6);
	}