#include <iostream>
#include <string>
#include <windows.h>
#include<bits/stdc++.h>
using namespace std;
class Contact{
	public:
		string fname;
		string lname;
		int gender;//1.male    2.female
		int age;
		string phone_number;
		string adress;
		void showInfo(){
			cout<<"first name: "<<fname<<endl;
			cout<<"last name: "<<lname<<endl;
			if(gender == 1) cout<<"gender: male"<<endl;
			else cout<<"gender: female"<<endl;
			cout<<"Age: "<<age<<endl;
			cout<<"Phone: "<<phone_number<<endl;
			cout<<"Adress: "<<adress<<endl;
			cout<<"*************************"<<endl;
		}
		
};
void getEnter(){
	cout<<"press enter key to continue..."<<endl;
		if(cin.get() == '\n'){}
		if(cin.get() == '\n'){
			system("cls");
		}
}
int main(int argc, char** argv) {
	Contact ob[20];
	int index = 0;
	while(true){
		cout<<"**************************************"<<endl;
		cout<<"**** Adress Book Managment System ****"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"**** 1. Add contact ******************"<<endl;
		cout<<"**** 2. Display contacts *************"<<endl;
		cout<<"**** 3. Delete contact ***************"<<endl;
		cout<<"**** 4. Find contacts ****************"<<endl;
		cout<<"**** 5. Modify contact ***************"<<endl;
		cout<<"**** 6. Clear contacts ***************"<<endl;
		cout<<"**** 7. Advanced Search **************"<<endl;
		cout<<"**** 0. Exit the address book ********"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"**************************************"<<endl;
		cout<<"**************************************"<<endl;
		int vorodi;
		cin>>vorodi;
		if(vorodi == 1){
			cout<<"Please enter your first name:"<<endl;
			cin>>ob[index].fname;
			cout<<"Please enter your last name:"<<endl;
			cin>>ob[index].lname;
			wrong1:
			cout<<"Please enter Gender:"<<endl<<"1.... Male."<<endl<<"2.... female"<<endl;
			int inputGender;
			cin>>inputGender;
			if(inputGender == 1 || inputGender == 2){
				ob[index].gender = inputGender;
			}else{
				cout<<"your answer is incorrect. try again."<<endl;
				goto wrong1;
			}
			cout<<"please enter age:"<<endl;
			cin>>ob[index].age;
			cout<<"Please enter phone number:"<<endl;
			cin>>ob[index].phone_number;
			cout<<"Please enter the adress:"<<endl;
			cin>>ob[index].adress;
			//*******************************
			cout<<"added successfully!"<<endl;
			++index;
			getEnter(); continue;
		}
		if(vorodi == 2){
			for(int i=0; i<index; ++i){
				ob[i].showInfo();
			}
			getEnter(); continue;
		}
		if(vorodi == 3){
			cout<<"Please enter a first name to delete that contact."<<endl;
			string deleteName;
			cin>>deleteName;
			for(int j=0; j<index; ++j){
				if(deleteName == ob[j].fname){
					for (int ii = j; ii < index-1 ; ++ii){
					    ob[ii] = ob[ii + 1]; 
					}
					--index;
				}
			}
			getEnter(); continue;
		}
		if(vorodi == 4){
			cout<<"Please Enter a first name or last name or phone number to search:"<<endl;
			string searchName;
			cin>>searchName;
			for(int jj=0; jj<index; ++jj){
				if(searchName == ob[jj].fname || searchName == ob[jj].lname || searchName == ob[jj].phone_number){
					ob[jj].showInfo();
				}
			}
			getEnter(); continue;
		}
		if(vorodi == 5){
			cout<<"Enter a first name to change the contact: "<<endl;
			string modifyName;
			cin>>modifyName;
			for(int ij=0; ij<index; ++ij){
				if(modifyName == ob[ij].fname){
					cout<<"Please enter new first name:"<<endl;
					cin>>ob[ij].fname;
					cout<<"Please enter new last name:"<<endl;
					cin>>ob[ij].lname;
					cout<<"Please enter Gender:"<<endl<<"1.... Male."<<endl<<"2.... female"<<endl;
					cin>>ob[ij].gender;
					cout<<"please enter age:"<<endl;
					cin>>ob[ij].age;
					cout<<"Please enter phone number:"<<endl;
					cin>>ob[ij].phone_number;
					cout<<"Please enter the adress:"<<endl;
					cin>>ob[ij].adress;
				}
			}
			getEnter(); continue;
		}
		if(vorodi == 6){
			wrongAnswer:
			cout<<"Are you sure you want to clear the address book? (Y to confirm/ N to cancel)"<<endl;
			string z;
			cin>>z;
			transform(z.begin(), z.end(), z.begin(),::tolower);
			if(z == "y"){
				for(int q=0; q<index; ++q){
					for (int x = q; x < index-1 ; ++x){
					    ob[x] = ob[x + 1]; 
					}
				}
				int z2=index;
				for(int w=0; w<z2; ++w){
					--index;
				}
				system("cls");
				continue;
			}else if (z == "n"){
				system("cls");
				continue;
			}else{
				cout<<"your answer is incorrect. try again."<<endl;
				goto wrongAnswer;
			}
		}
		if(vorodi == 7){
			cout<<"Enter the first letter or letters of the first name: "<<endl;
			string v;
			cin>>v;
			transform(v.begin(), v.end(), v.begin(),::tolower);
			if(v.length() == 1){
				int e1 = 0;
				for(int r=0; r<index; ++r){
					transform(ob[r].fname.begin(), ob[r].fname.end(), ob[r].fname.begin(),::tolower);
					if(ob[r].fname.length() >= v.length()){
						if(v[0] == ob[r].fname[0]){
							ob[r].showInfo();
						}
						else{
							++e1;
						}
					}
					else{
						++e1;
					}
				}
				if(e1 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 2){
				int e2 = 0;
				for(int r2=0; r2<index; ++r2){
					transform(ob[r2].fname.begin(), ob[r2].fname.end(), ob[r2].fname.begin(),::tolower);
					if( ob[r2].fname.length() >= v.length()){
						if(v[0] == ob[r2].fname[0] && v[1] == ob[r2].fname[1]){
							ob[r2].showInfo();
						}
						else{
							++e2;
						}
					}
					else{
						++e2;
					}
				}
				if(e2 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 3){
				int e3 = 0;
				for(int r3=0; r3<index; ++r3){
					transform(ob[r3].fname.begin(), ob[r3].fname.end(), ob[r3].fname.begin(),::tolower);
					if(ob[r3].fname.length() >= v.length()){
						if(v[0] == ob[r3].fname[0] && v[1] == ob[r3].fname[1] && v[2] == ob[r3].fname[2]){
							ob[r3].showInfo();
						}
						else{
							++e3;
						}
					}
					else{
						++e3;
					}
				}
				if(e3 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 4){
				int e4 = 0;
				for(int r4=0; r4<index; ++r4){
					transform(ob[r4].fname.begin(), ob[r4].fname.end(), ob[r4].fname.begin(),::tolower);
					if(ob[r4].fname.length() >= v.length()){
						if(v[0] == ob[r4].fname[0] && v[1] == ob[r4].fname[1] && v[2] == ob[r4].fname[2] &&  v[3] == ob[r4].fname[3]){
							ob[r4].showInfo();
						}
						else{
							++e4;
						}	
					}
					else{
						++e4;
					}
				}
				if(e4 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 5){
				int e5 = 0;
				for(int r5=0; r5<index; ++r5){
					transform(ob[r5].fname.begin(), ob[r5].fname.end(), ob[r5].fname.begin(),::tolower);
					if(ob[r5].fname.length() >= v.length()){
						if(v[0] == ob[r5].fname[0] && v[1] == ob[r5].fname[1] && v[2] == ob[r5].fname[2] &&  v[3] == ob[r5].fname[3] && v[4] == ob[r5].fname[4]){
							ob[r5].showInfo();
						}
						else{
							++e5;
						}	
					}
					else{
						++e5;
					}
				}
				if(e5 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 6){
				int e6 = 0;
				for(int r6=0; r6<index; ++r6){
					transform(ob[r6].fname.begin(), ob[r6].fname.end(), ob[r6].fname.begin(),::tolower);
					if(ob[r6].fname.length() >= v.length()){
						if(v[0] == ob[r6].fname[0] && v[1] == ob[r6].fname[1] && v[2] == ob[r6].fname[2] &&  v[3] == ob[r6].fname[3] && v[4] == ob[r6].fname[4] && v[5] == ob[r6].fname[5]){
							ob[r6].showInfo();
						}
						else{
							++e6;
						}	
					}
					else{
						++e6;
					}
				}
				if(e6 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 7){
				int e7 = 0;
				for(int r7=0; r7<index; ++r7){
					transform(ob[r7].fname.begin(), ob[r7].fname.end(), ob[r7].fname.begin(),::tolower);
					if(ob[r7].fname.length() >= v.length()){
						if(v[0] == ob[r7].fname[0] && v[1] == ob[r7].fname[1] && v[2] == ob[r7].fname[2] &&  v[3] == ob[r7].fname[3] && v[4] == ob[r7].fname[4] && v[5] == ob[r7].fname[5] && v[6] == ob[r7].fname[6]){                  
							ob[r7].showInfo();
						}
						else{
							++e7;
						}	
					}
					else{
						++e7;
					}
				}
				if(e7 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			if(v.length() == 8){
				int e8 = 0;
				for(int r8=0; r8<index; ++r8){
					if(ob[r8].fname.length() >= v.length()){
						if(v[0] == ob[r8].fname[0] && v[1] == ob[r8].fname[1] && v[2] == ob[r8].fname[2] &&  v[3] == ob[r8].fname[3] && v[4] == ob[r8].fname[4] && v[5] == ob[r8].fname[5] && v[6] == ob[r8].fname[6] && v[7] == ob[r8].fname[7]){                  
							ob[r8].showInfo();
						}
						else{
							++e8;
						}	
					}
					else{
						++e8;
					}
				}
				if(e8 == index){
					cout<<"Not found."<<endl;
				}
				getEnter(); continue;
			}
			
		}
		if(vorodi == 0){
			exit(0);
		}
		if(!(vorodi >= 0 && vorodi <= 7)){
			cout<<"Your number is incorrect. Try again."<<endl;
			getEnter(); continue;
		}	
	}	
}