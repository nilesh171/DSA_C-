//Name - Nilesh Jivan Sonawane
//Roll No - FY23M270
//PRN- 123B1B270
//Assignment No - 5
// Implement a navigation system for a delivery service using a circular linked list to represent routes. The navigation system should support the following functionalities: a. Add route b. Remove route c. Display route.
#include <iostream>
using namespace std;

class route {
	string source,dest;
	int distance;
	route* next;  // Add this member to manage the linked list

public:
	route() : next(nullptr) {}  // Initialize next to nullptr

	void read() {
    	cout << "Enter Source : ";
    	cin >>source;
    	cout << "Enter Destination: ";
    	cin >>dest;
    	cout << "Enter Distance : ";
    	cin >>distance;
	}

	void display() const {
    	cout << "Source :"<<source<<"  ";
    	cout << "Destination : " <<dest <<"  ";
    	cout << "Distance : " <<distance <<"  ";
   	 
	}

	friend class route_nav;  // Allow playlist to access private members
};
 class route_nav{
 	public:
 	route *tail;
 	route_nav(){
     	tail=NULL;
 	}
 	void addrouteatend(){
      	route *ch=new route;
      	ch->read();
     	if(tail==NULL){
         	tail=ch;
         	tail->next=ch;
     	}
     	else{
         	ch->next=tail->next;
         	tail->next=ch;
         	tail=ch;
     	}
    	 
    	 
 	}
 	void addrouteatstart(){
      	route *ch=new route;
      	ch->read();
     	if(tail==NULL){
         	tail=ch;
         	tail->next=ch;
     	}
     	else{
         	ch->next=tail->next;
         	tail->next=ch;
     	}
    	 
    	 
 	}
 	void displaydata(){
     	if(!tail)return;
     	route *ch;
     	for(ch=tail->next;ch!=tail;ch=ch->next){
         	ch->display();
         	cout<<endl;
     	}
     	ch->display();
     	cout<<endl;
 	}
 	void deleteroute(){
     	route *p=tail;
     	route* t=tail->next;
     	string src,desti;
     	cout<<"Enter source : ";
     	cin>>src;
     	cout<<"Enter destination : ";
     	cin>>desti;
     	 do{
         	if(t->source==src && t->dest==desti){
            	if(t==tail){
                	if(tail==tail->next){
                    	delete t;
                    	tail=nullptr;
                    	return;
                	}else{
                	p->next=t->next;
                	tail=p;
                	delete t;
                	return;
                	}
            	}else{
                	p->next=t->next;
                	delete t;
                	return;
            	}
         	}else{
             	p=t;
             	t=t->next;
         	}
    	 
        	 
     	}while(t!=tail->next);
     	cout<<"Route Does Not Exist"<<endl;
 	}
 };
 int main(){
 	route_nav s1;
 	int n=1;
 	while(n!=0){
     	cout<<"Enter 1 for adding at end & 2 for adding at first & 3 for Display data & 4 for delete route & 0 for Exit : ";
     	cin>>n;
     	if(n==1){
         	s1.addrouteatend();
     	}
     	else if(n==2){
         	s1.addrouteatstart();
     	}
     	else if(n==3){
         	s1.displaydata();
     	}
     	else if(n==4){
         	 s1.deleteroute();
     	}
     	else{
         	n=0;
     	}
 	}
 }





