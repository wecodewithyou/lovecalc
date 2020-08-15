#include<iostream>
#include<cstring>
using namespace std ;

void perct( char , char );
void line( int* line_in , int totx);		 // last output is here

int main() 	
{
	char name1[100],name2[100];
	cout << " Enter Your First Name : ";
	cin >> name1 ;
	cout << " Enter Your Cursh's First Name : ";
	cin >> name2 ;
	
	// Processing Starts From Here
	
	int len1 = strlen(name1) , len2 = strlen(name2) ;  	//lengths of names
	int tot = len1+len2+4  ; 	// Total letters
	char full_line[tot+1] ;
	int  line1[tot] ;
	int i,j ;  		//initializing Variables 
	char love[5] = { 'l' ,'o' , 'v' , 'e' } ;
	
	
	strcat( full_line , name1 ) ;
	strcat( full_line , love ) ;
	strcat( full_line , name2 ) ;
	
	
	for ( i=0 ; i<=tot ; i++ )			// in full_name total no.of element is (tot+1)
	{
		line1[i] = 1;					// in index1 total no.of elemwnt is (tot)
		for ( j=tot ; j>i ; j-- )		
		{
				if ( full_line[i] == full_line[j] )			
				{
					line1[i] = 2 ;
					
					for(int del=j ; del<=tot-1 ; del++ )
					{
						full_line[del]= full_line[del+1] ; 
					}
					tot = tot -1 ; 
					j=0;  
				}}}
	cout << "\n\t";
	for( i=0 ; i<tot ; i++)
	{
		cout << line1[i];			
	}
	cout << endl <<'\t' << "  " ;
	
	line(line1, tot) ; 		// Frist Line Finished
}

void line( int* line_in , int totx )
{	
	int *line_out , emty[totx]={0};
	int toty,i,j;
	
	line_out = &emty[0];
			
	if( totx %2 != 0) 	//it is odd
	{
		toty = (totx/2)+1;
		*(line_out + (toty-1)) = *(line_in + (totx-1)/2);
	}
	
	for(i=0 ; i<totx ; i++)
	{
		for(j=totx-1 ; j>i ; j--)
		{
			*(line_out + i) = *(line_in+i) + *(line_in + j) ;
			*(line_in + j) = 0;
			totx = totx-1;			
			j=0;
		}}
	for(i=0 ; i<totx ; i++)
	{
		if( totx > 2)
		{
			cout << *(line_out + i);			
		}
	}
	cout << endl << '\t' << "   ";
	if ( totx == 2 )
	{
		char choice ;
		cout << "\n Percentage = " << *line_out << *(line_out +1) << '%' << endl;
		cout << "\n \n Do you Want to continue (y/n) : ";
		x:
		cin >> choice;
		if ( choice == 'n' || choice == 'N' )
		{
			exit (0);
		}

		else if ( choice == 'y' || choice == 'Y' )
		{
			cout << "\n \n";
			main();
		}

		else
		{
			cout<< "\n \t Wrong Input \n \n Type Again : " ;
			goto x;
	
		}
	}
	else
	{
		line(line_out,totx);
	}
}
