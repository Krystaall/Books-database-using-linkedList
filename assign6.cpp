#include<iostream>
using namespace std;

class node{
public:
	int isbn,edition;
	string name,author;
	node *next;
	node(){
		next=NULL;
	}
	node(string n,string a,int ISBN,int e)    //initialize all variables
	{
     isbn=ISBN;
     edition=e;
     name=n;
     author=a;
     next=NULL;
    }
    friend class bookList;
};


class bookList
{
public:
 int count=0;
 node *head;
 bookList(){
	 head=NULL;
 }
 bookList(node *n){
	 head=n;
 }

 void add(node *n);                  //function declarations
 void display();
 node* searchIsbn(node *head, int value);    //USING BINARY SEARCH
 node* middle(node* start, node* last);
 void sort();                     //USING BUBBLE SORT
 void ofAuthor(string m);         //USING LINEAR SEARCH


};

void bookList::add(node *n)                       //create Linked List
{
	 node* ptr=head;
	if(head==NULL){
		head=n;
		cout<<"\nBOOK ADDED\n"<<endl;
		count+=1;
	}
	else{

	 while(ptr->next!=NULL)
		{
		ptr= ptr->next;
		}
		ptr->next=n;
		cout<<"\nBOOK ADDED\n"<<endl;
		count+=1;

	}

}

void bookList::display()                      //display the data
{
	cout<<"\nThe total number of books present are: \n"<<count<<endl;
	if(head==NULL){
	  cout<<"\nNO BOOKS PRESENT"<<endl;
	}
	else{
	   cout<<endl<<"\nBOOK DETAILS: \n ";
	   node* temp=head;
       while(temp!=NULL){
	   cout<<"\nISBN NO. \tNAME \t\t AUTHOR \t\tEDITION \n"<<temp->isbn<<"\t\t"<<temp->name<<"\t\t "<<temp->author<<"\t\t    "<<temp->edition<<endl;
	   temp= temp->next;
		}
	}
}


	// function to find out middle element for binary search
	 node* bookList::middle(node* start, node* last)
	{
	    if (start == NULL){
	        return NULL;
	    }

	     node* slow = start;
	     node* fast = start -> next;

	    while (fast != last)
	    {
	        fast = fast -> next;
	        if (fast != last)
	        {
	            slow = slow -> next;
	            fast = fast -> next;
	        }
	    }

	    return slow;
	}

	//  Binary Search on linked list
	node* bookList::searchIsbn(node *head, int value)
	{
	    node* start = head;
	    node* last = NULL;
	    node*mid;

	    do
	    {
	        // Find middle
	        node* mid = middle(start, last);

	        // If middle is empty
	        if (mid == NULL)
	            return NULL;

	        // If value is present at middle
	        if (mid ->isbn == value){

	            return mid;
	        }


	        // If value is more than mid
	        else if (mid ->isbn < value)
	            start = mid -> next;

	        // If the value is less than mid.
	        else
	            last = mid;

	    } while (last == NULL ||last != start);




	}


void bookList::ofAuthor(string m){

	node* temp=head;
		node* ptr=NULL;
		while(temp!=NULL){
			if(temp->author==m){
				cout<<"\nBOOK DETAILS: \n"<<endl;
				cout<<"\nISBN NO. \tNAME \t\t AUTHOR \t\tEDITION \n"<<temp->isbn<<"\t\t"<<temp->name<<"\t\t "<<temp->author<<"\t\t   "<<temp->edition<<endl;
				ptr=temp;
				temp=temp->next;

			}
			else{
				temp=temp->next;
			}
		}
		if(ptr==NULL){
			cout<<"\nBOOK OF GIVEN AUTHOR NOT AVAILABLE IN LIBRARY.\n"<<endl;
		}
		return;


}

void bookList::sort()
{
	node *current , *current2 ;
	int temp,k;
	string A,N;
	cout<<"\nThe total number of books present are: \n"<<count<<endl;
	for(current=head; current!=NULL;current=current->next){



    	for( current2=head; current2->next!=NULL;current2=current2->next){


        if(current2->isbn > current2->next->isbn)
        {
            temp = current2->isbn;
            current2->isbn = current2->next->isbn;
            current2->next->isbn= temp;

            k = current2->edition;
            current2->edition = current2->next->edition;
            current2->next->edition= k;

             A= current2->author;
            current2->author = current2->next->author;
            current2->next->author= A;

            N = current2->name;
            current2->name = current2->next->name;
            current2->next->name= N;



        }

    	}

	}
    cout<<"SORTED";
    display();

}


int main()
{
	bookList l;       //object of bookList class
	int ch,e,ISBN;
	string n,a;
	node* head= new node();
    //node* TEMP= new node();


    do{
    	//Menu
    	cout<<"\n MENU\n1. ADD BOOK \n2. DISPLAY ALL BOOKS \n3. SEARCH BOOK BY ISBN\n4. SORT BOOKS\n5. SEARCH ALL BOOKS OF AUTHOR \n6. EXIT\n Enter a choice:";
    	cin>>ch;


        node* n1= new node();
    	switch(ch){
    	case 1: //CREATE
    		cout<<"Enter ISBN no., name of book , author , edition of book in order without using space: "<<endl;
    			cin>>ISBN;
    			cin>>n;
    			cin>>a;
    			cin>>e;
    			n1->isbn=ISBN;
    			n1->name=n;
    			n1->author= a;
    			n1->edition=e;
    			l.add(n1);

    		break;
    	case 2: {   // DISPLAY
    		l.display();
    	}
    		break;
        case 3:{   //SEARCH BY ISBN NUMBER
        	cout<<"\nTo check a specific book is available in library or not Enter ISBN no. of book: "<<endl;
        	cin>>ISBN;
        	if (l.searchIsbn(head, ISBN) == NULL)
        	{
        	        cout<<"\nBOOK NOT PRESENT\n";
        	}
        	    else{

        	        cout<<"\nBOOK PRESENT\n";


        	    }
            break;
        }
       case 4:  //SORTING ON BASIS OF ISBN NUMBER
       {
    	   l.sort();
            break;
       }
       case 5:   //DISPLAY
    	   cout<<"Enter the name of author whose books you want to be displayed: "<<endl;
    	   cin>>a;
    	   l.ofAuthor(a);
    	   break;
       case 6:  //EXIT
    	   break;

        default:
        	cout<<"\nEnter a valid choice";
        	break;
         }

      }while(ch!=6);
}


/* MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:2

The total number of books present are:
0

NO BOOKS PRESENT

 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:1
Enter ISBN no., name of book , author , edition of book in order without using space:
34
korean
jcw
6

BOOK ADDED


 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:1
Enter ISBN no., name of book , author , edition of book in order without using space:
67
jackson
jackson
2

BOOK ADDED


 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:1
Enter ISBN no., name of book , author , edition of book in order without using space:
12
wings
james
1

BOOK ADDED


 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:2

The total number of books present are:
3


BOOK DETAILS:

ISBN NO. 	NAME 		 AUTHOR 		EDITION
34		korean	 jcw		        6

ISBN NO. 	NAME 		 AUTHOR 		EDITION
67		jackson	 jackson		   2

ISBN NO. 	NAME 		 AUTHOR 		EDITION
12		wings	       james		   1

 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:3

To check a specific book is available in library or not Enter ISBN no. of book:
67

BOOK PRESENT

 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:4

The total number of books present are:
3
SORTED
The total number of books present are:
3


BOOK DETAILS:

ISBN NO. 	NAME 		 AUTHOR 		EDITION
12		wings		 james		   1

ISBN NO. 	NAME 		 AUTHOR 		EDITION
34		korean      jcw		        6

ISBN NO. 	NAME 		 AUTHOR 		EDITION
67		jackson      jackson		   2

 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:5
Enter the name of author whose books you want to be displayed:
james

BOOK DETAILS:


ISBN NO. 	NAME 		 AUTHOR 		EDITION
12		    wings		 james		       1

 MENU
1. ADD BOOK
2. DISPLAY ALL BOOKS
3. SEARCH BOOK BY ISBN
4. SORT BOOKS
5. SEARCH ALL BOOKS OF AUTHOR
6. EXIT
 Enter a choice:6



 TIME COMPLEXITITES:
1. add=O(N)
2. display=O(N)
3. searchIsbn=O(logN)
4. middle=O(N)
5. sort=O(N^2)
6. ofAuthor=O(N)


 */








