//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 9a
#include <iostream>
using namespace std;
class party{
	string pname;
	public:
	void adddata(){
    	cout<<"Enter Party Name : ";
    	cin>>pname;
	}
	void display(){
    	cout<<"Party Name is "<<pname<<endl;
	}
	friend class waitlist;
};
class waitlist{
	party q[10];
	int front,rear;
	public:
	waitlist(){
    	front=rear=-1;
	}
	void addparty(){
    	if(front==-1){
        	front++;
        	rear++;
        	q[rear].adddata();
    	}
    	else{
        	rear++;
        	if(rear==10){
            	cout<<"No more !! Party is Added"<<endl;
        	}
        	else{
            	q[rear].adddata();
        	}
    	}
	}
	void seatparty(){
    	if(front>rear||front==-1){
        	cout<<"No party is seated !! Waitlist is Empty !!"<<endl;
       	 
    	}
    	else{
        	cout<<"Seating ";
        	q[front].display();
        	front++;
    	}    
	}
	void displaywaitlist(){
    	if(front>rear||front==-1){
        	cout<<"Waitlist is Empty !!"<<endl;
       	 
    	}else{
        	int i=front;
        	while(i<=rear){
            	cout<<"Party ";
            	q[i].display();
            	i++;
        	}
    	}
	}
};
int main(){
	waitlist s;
	int n=1;
	while(n!=0){
    	cout<<"Enter 1 Add Party to Waitlist \n 2 Seat Party \n 3 Display Playlist \n 0 for Exit : ";
    	cin>>n;
    	if(n==1){
        	s.addparty();
    	}
    	else if(n==2){
        	s.seatparty();
    	}
    	else if(n==3){
        	s.displaywaitlist();
    	}
    	else{
        	n=0;
    	}
	}
}
