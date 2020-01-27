//Ankita Saha
//19HCS4069
#include<iostream>
using namespace std;

class Polynomial
{
  private:
    int m;
    int A[100];
   
  public:
    Polynomial()
    {
    	m=0;
    	
      // Behavior of default constructor
    }

    Polynomial(int deg)
    {
    	m=deg;
    
      // Behavior of constructor with arguments
    }
    Polynomial(const Polynomial &t)
    {
    	m=t.m;
    	
      // Behavior of constructor with arguments
    }
  
    ~Polynomial()
    {
      // Behavior of destructor
    }
  
  Polynomial operator + (Polynomial const &obj)
  {	
        Polynomial temp;
    	int size;
    	if(this->m > obj.m){
    		temp.m = this->m;
    		size = obj.m;
		}else{
			temp.m = obj.m;
			size = this->m;
		}
    	for(int i=temp.m;i>=0;i--){
    		if(i<=size){
    			temp.A[i] = obj.A[i] + this->A[i];
			}else{
				if(this->m > obj.m){
					temp.A[i] = this->A[i];
				}else{
					temp.A[i] = obj.A[i];
				}
				
			}
		}
    	return temp;
	}
	
    void operator = (Polynomial const &obj)
	{	
		this->m = obj.m;
		for(int i=obj.m;i>=0;i--)
		{
			this->A[i] = obj.A[i];
		}
	}
   
  Polynomial operator - (Polynomial const &obj)
  {		
    	Polynomial temp;
    	int size;
    	if(this->m > obj.m){
    		temp.m = this->m;
    		size = obj.m;
		}
		else
		{
			temp.m = obj.m;
			size = this->m;
		}
    	for(int i=temp.m;i>=0;i--)
		{
    		if(i<=size)
		   {
    			temp.A[i] = this->A[i] - obj.A[i];
			}else
			{
				if(this->m > obj.m){
					temp.A[i] = this->A[i];
				}else{
					temp.A[i] = -obj.A[i];
				}
				
			}
		}
    	return temp;
  }
    //  Overload copy constructor, +, - and = operators
  
      
      void storePolynomial()
	  {
    	cout<<"Enter the elements of the polynomial::"<<endl;
        for(int i=m;i>=0;i--)
	    {
      	  cin>>A[i];
      	}
      }
   void display() 
{
    for (int i=0; i<=m; i++) 
    { 
       cout << A[i]; 
       if (i != 0) 
        cout << "x^" << i ; 
       if (i != m) 
       cout << " + "; 
    } 
} 
  
};

int main()
{
  int degFirst, degSecond;
  cout<<"Enter degFirst::";
  cin>>degFirst;
  cout<<"Enter degSecond::";
  cin>>degSecond;
  // Ask user to input the values of degFirst and degSecond 
  Polynomial firstPolynomial(degFirst);
  Polynomial secondPolynomial(degSecond);
  Polynomial thirdPolynomial;
  
  firstPolynomial.storePolynomial();
  secondPolynomial.storePolynomial();
  
  
  thirdPolynomial=firstPolynomial+secondPolynomial;
  Polynomial fourthPolynomial=firstPolynomial-secondPolynomial;
  
  firstPolynomial.display();
  cout<<endl;
  secondPolynomial.display();
  cout<<endl;
  cout<<"Polynomial after addition::"<<endl;
  thirdPolynomial.display();
  cout<<endl;
  cout<<"Polynomial after subtraction::"<<endl;
  fourthPolynomial.display();
  return 0;
}
