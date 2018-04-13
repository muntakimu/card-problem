#include<iostream>
using namespace std;

struct Person{
	string cardname;
	string name;
	pair<int,int> Card;	
};

struct Track{
	pair<int,int>cardsuit;
};

typedef Person person;
void Insertionsort(person p[],int n);

int main(){
	//declarations
	Track trackArray[4];
	person Student[42];
	cout<<endl;
	int n,numb;
	string suits,names;
	int number;
	
	
	//opening a file using freopen file input stream
freopen("input.txt","r",stdin);
cin>>number;
for(int i=0;i<number;i++){
	
	////assigning the inputs in variables
	cin>>names>>n>>numb;
	
	//assigning the inputs in Struct array
	Student[i].name=names;
	Student[i].Card.first=n;
	Student[i].Card.second=numb;
}

Insertionsort(Student,number);


//trackarray
int firstsuit=Student[0].Card.first,i;
int crsuit=firstsuit;
trackArray[crsuit].cardsuit.first=0;
for( i=1;i<number;i++){
	if(Student[i].Card.first!=crsuit){
		trackArray[crsuit].cardsuit.second=i-1;
		crsuit=Student[i].Card.first;
		trackArray[crsuit].cardsuit.first=i;
	}
}

//my approach without tracking 
for(int i=0;i<number;i++){
		for(int i=1;i<number;i++){
		for(int j=i;j>0;j--){
			if(Student[j-1].Card.second>Student[j].Card.second){
				if(Student[j-1].Card.first==Student[j].Card.first){	
				swap(Student[j-1],Student[j]);
				}
			}
		}		
	}
	}
	


//printing output
for(int i=0;i<number;i++){
		
	cout<<Student[i].name<<"\t";
		switch(Student[i].Card.first){
			case 1:
				cout<<"Spades\t"<<Student[i].Card.second<<endl;
				break;
			case 2:
				cout<<"Clubs\t"<<Student[i].Card.second<<endl;
				break;
			case 3:
				cout<<"Hearts\t"<<Student[i].Card.second<<endl;
				break;
			case 4:
				cout<<"Dimonds\t"<<Student[i].Card.second<<endl;
				break;
			
		
	}

	}
}
//Insertion Sort function using the concept of card sorting
void Insertionsort(person p[],int n){
	for(int i=1;i<n;i++){
		for(int j=i;j>0;j--){
			if(p[j-1].Card.first>p[j].Card.first){
				swap(p[j-1],p[j]);
			}
		}		
	}
}


