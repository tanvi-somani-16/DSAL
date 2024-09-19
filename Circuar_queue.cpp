#include<iostream>
#define max 10
using namespace std;

class Queue{
	int data[max];
	int front;
	int rear;
	public:
		Queue(){
			front=-1;
			rear=-1;
		}
		int isfull(){
			if(front==0 && rear==max-1 || front==(rear+1)%max){
				return 1;
			}
			else {
				return 0;
			}
		}
		
		int isempty(){
			if(front==-1 && rear==-1){
				return 1;
			}
			else{
				return 0;
			}
		}
		void enQueue(int a);
		void deQueue();
		void display();
};

void Queue::enQueue(int a){
	if(rear==-1){
		front++;
		rear++;
		data[rear]=a;
	}
	else{
		rear=(rear+1)%max;
		data[rear]=a;
	}
}

void Queue::deQueue(){
	if(front==rear){
		int x=data[front];
		front=-1;
		rear=-1;
		cout<<"The deleted element is "<<x<<endl;
	}
	else{
		int x=data[front];
		front=(front+1)%max;
		cout<<"The deleted element is "<<x<<endl;
	}
}

void Queue::display(){
	if(rear>=front){
		for(int i=front;i<=rear;i++){
			cout<<data[i]<<endl;
		}
	}
	else{
		for(int i=front;i<max;i++){
			cout<<data[i]<<endl;
		}
		for(int i=0;i<=rear;i++){
			cout<<data[i]<<endl;
		}
	}
}

int main(){
	Queue obj;
	int choice;
	int flag=1;
	do{
	cout<<"Main menu:"<<endl;
	cout<<"1 Insert Element "<<endl;
	cout<<"2 Delete Element "<<endl;
	cout<<"3 Display Queue "<<endl;
	cout<<"4 Exit "<<endl;
	
	cout<<"Enter the choice : "<<endl;
	cin>>choice;
	
	switch(choice){
		case 1:
			if(obj.isfull()){
				cout<<"Queue is full "<<endl;
			}
			else{
				int b;
				cout<<"Enter the element :"<<endl;
				cin>>b;
				obj.enQueue(b);
			}	
			break;
		case 2:
			if(obj.isempty()){
				cout<<"Queue is empty "<<endl;
			}
			else{
				obj.deQueue();
			}
			break;
		case 3:
			obj.display();
			break;
		case 4:
			flag=0;
			cout<<"PROGRAM TERMINATED "<<endl;
			break;
		default:
			cout<<"Enter a valid choice"<<endl;
		}
	}while(flag!=0);
	return 0;
 }
	

