//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 9b
#include<iostream>
using namespace std;
class customer{
	string name;
	long mob;
	public:
	void read(){
    	cout<<"Enter name of Customer : ";
    	cin>>name;
    	cout<<"Enter Mobile No Of Customer : ";
    	cin>>mob;
	}
	void display(){
    	cout<<"Name of Customer : "<<name<<endl;
    	cout<<"Mobile No : "<<mob<<endl;
	}
	friend class counterqueue;
};
class counterqueue{
	customer q[10];
	int front,rear;
	public:
	counterqueue(){
    	front=rear=-1;
	}
	void addcustomer(){
    	if(front== -1){
        	front++;
        	rear++;
        	q[rear].read();
    	}
    	else{
        	rear=(rear+1)%10;
        	if((rear+1)%10==front){
            	cout<<"Sorry!!No More Space"<<endl;
        	}else{
        	q[rear].read();
        	}
    	}
	}
	void checkout(){
    	if(front== -1){
        	cout<<"Super Market Is Empty !!"<<endl;
    	}
    	else{
       	 
       	front=(front+1)%10;
    	}
	}
	void check(){
    	if(front==rear){
        	cout<<"Counter Was Closed !!!"<<endl;
    	}
    	else{
        	cout<<"Counter Is Open !!!"<<endl;
    	}
	}
	void displayque(){
    	int i=front;
    	while(i!=rear){
        	q[i].display();
        	i=(i+1)%10;
    	}
    	q[i].display();
	}
};
int main(){
	counterqueue s;
	int n=1;
	while(n!=0){
    	cout<<"Enter 1 to add Customer \n 2 for delete Customer \n 3 for Counter was closed or not \n 4 for display data \n 0 for Exit : ";
    	cin>>n;
    	if(n==1){
        	s.addcustomer();
    	}
    	else if(n==2){
        	s.checkout();
        	s.displayque();
    	}        

    	else if(n==3){
    	    	s.check();
    	}
    	else if(n==4){
        	s.displayque();
    	}
    	else{
        	n=0;
    	}
	}
}
