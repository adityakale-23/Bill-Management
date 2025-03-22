#include<iostream>
#include<string>
using namespace std;
class item
{
	public:
	string name;
	float price;
	int quantity;
	
		void getdata(){
			cout<<endl<<endl<<"Enter name of the product : ";
			cin>>name;
			cout<<"Enter price of the product : ";
			cin>>price;
			cout<<"Enter how many units you want : ";
			cin>>quantity;
			cout<<endl<<"Thank You!"<<endl<<endl;
		}
		int showdata(){
			cout<<"|  "<<name;
			for(int i=1; i<=20-name.length(); i++){
				cout<<" ";
			}
			cout<<price<<"                     ";
			cout<<quantity<<"                    ";
			cout<<price*quantity<<"   |"<<endl;
			return price*quantity;
		}
};

class root{
	public:
	item a;
	root* next;
		void add(){
			root* newnode = new root;
			newnode->next = NULL;
			newnode->a.getdata();
			root* temp = this;
			while(temp->next != NULL) {
				temp = temp->next;
			}
			temp->next = newnode;
		}
};

void swap(item a, item b)
{
	
}

int partition(item arr[], int low, int high) {
    int pivot = arr[high].price * arr[high].quantity;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].price * arr[j].quantity < pivot) {
            i++;
            item temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
        }
    }
    item temp = arr[i+1];
	arr[i+1] = arr[high];
	arr[high] = temp;
    return i + 1;
}

void quicksort(item arr[], int low, int high) {
    if (low < high) {
        int pivot_index = partition(arr, low, high);
        quicksort(arr, low, pivot_index - 1);
        quicksort(arr, pivot_index + 1, high);
    }
}


void intro()
{
	cout<<"      ====================================================="<<endl;
	cout<<"                 Welcome to Bill Management system"<<endl;
	cout<<"      ====================================================="<<endl<<endl;
	cout<<"Enter the Details of the products you have purchased and get the bill!!"<<endl;
	cout<<"------------------------------------------------------------------------"<<endl;
}

int main()
{
	intro();
	int sum= 0;
	int size=0;
	root* head = new root;
	head->next = NULL;
	head->a.getdata();
	while(1){
		int choice=0;
		cout<<"1. Want to add new item"<<endl;
		cout<<"2. Want to see the bill"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		if(choice != 1){
			break;
		}
		
		head->add();
	}
	
	root* t=head;
	while(t!=NULL){
		size= size+1;
		t=t->next;
	}
	delete t;
	
	item arr[size];
	root* tp= head;
	for(int i=0; i<size; i++){
		arr[i]=tp->a;
		tp=tp->next;
	} 
	cout<<endl;
	delete tp;
	
	quicksort(arr, 0, size-1);
	
	
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"|                             RECEIPT                                   |"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"|  NAME               PRIZE               Quantity               Total  |"<<endl;
	cout<<"|                                                                       |"<<endl;
	for(int i= 0; i<size; i++){
		sum= sum + arr[i].showdata();
	}
	cout<<"-------------------------------------------------------------------------"<<endl;
	cout<<"|                                           TOTAL                  "<<sum<<"  |"<<endl;
	cout<<"-------------------------------------------------------------------------"<<endl<<endl;
	cout<<"                         Thank You For Shopping "<<endl<<endl<<endl;
	return 0;
}

