#include <iostream>
#include <string>

using namespace std;

class DarazPersonData {
private:
    string lastName;
    string firstName;
    string address;
    string city;
    string state;
    string zip;
    string phone;

public:
    string getLastName()
	  { 
	  return lastName;
	   }
    string getFirstName()  {
	 return firstName; 
	 }
    string getAddress()  { 
	return address;
	 }
    string getCity()  {
	 return city;
	  }
    string getState()  {
	 return state; 
	 }
    string getZip()  {
	 return zip; 
	 }
    string getPhone()  { 
	return phone; 
	}

    void setLastName( string ln) { 
	lastName = ln;
	 }
    void setFirstName( string fn) { 
	firstName = fn;
	 }
    void setAddress( string addr) {
	 address = addr;
	  }
    void setCity( string cty) { 
	city = cty;
	 }
    void setState( string st) {
	 state = st; 
	 }
    void setZip( string zp) {
	 zip = zp;
	  }
    void setPhone( string ph) {
	 phone = ph;
	  }
	  
};
class DarazCustomerData {
protected:
    int customerNumber;
    int loyaltyPoints;
public:

    DarazCustomerData(int custNum, int loyaltyPts)
	{
		customerNumber=custNum;
		loyaltyPoints=loyaltyPts;
}

    int getCustomerNumber()  { 
	return customerNumber;
	 }
    int getLoyaltyPoints()  {
	 return loyaltyPoints;
	  }

    void setCustomerNumber(int custNum)
	 { 
	 customerNumber = custNum; 
	 }
    void setLoyaltyPoints(int loyaltyPts) 
	{
	 loyaltyPoints = loyaltyPts; 
	 }
};
class DarazaLoyaltyProgram: public DarazCustomerData{
	public:
		using DarazCustomerData::DarazCustomerData;
		void LoyaltyptsPurchases(){
			if (loyaltyPoints<=0){
				cout<<"invalid points..."<<endl;
				exit(1);
				
			}
			else{
				cout<<"Purchase successful. Updating your Loyalty points...";
				loyaltyPoints= loyaltyPoints+10;
				cout<<"Loyalty points update!"<<endl;
			}
		}
		void Redeemloyaltypts(){
			if (loyaltyPoints<=0){
				cout<<"invalid points..."<<endl;
				exit(1);
				
			}
			else if (loyaltyPoints>=0 && loyaltyPoints<10){
				cout<<"insufficient loyalty points..."<<endl;
				exit(1);
				
			}
			else{
				int discountrate=loyaltyPoints / 10;
				int discount= 50 * discountrate;
				cout<<"You got a discount of "<< discount<<"rupees"<<endl;
			}
		}
		void displayloyalPts(){
			cout<<"Your loyal points are:"<< loyaltyPoints<<endl;
		}
};
int main() {
    DarazPersonData person;
    person.setLastName("Hamza");
    person.setFirstName("Sheikh");
    person.setAddress("fast nuces");
    person.setCity("Karachi");
    person.setState("Sindh");
    person.setZip("73500");
    person.setPhone("03232323232");
    cout << "Person Information:" << endl;
    cout << "Last Name: " << person.getLastName() << endl;
    cout << "First Name: " << person.getFirstName() << endl;
    cout << "Address: " << person.getAddress() << endl;
    cout << "City: " << person.getCity() << endl;
    cout << "State: " << person.getState() << endl;
    cout << "ZIP: " << person.getZip() << endl;
    cout << "Phone: " << person.getPhone() << endl;

    DarazCustomerData customer(1100, 53);

    cout << "\nCustomer Information:" << endl;
    cout << "Customer Number: " << customer.getCustomerNumber() << endl;
    cout << "Loyalty Points: " << customer.getLoyaltyPoints() << endl;

    DarazaLoyaltyProgram loyaltyProgram(1200, 150);
    loyaltyProgram.LoyaltyptsPurchases();
    loyaltyProgram.displayloyalPts();
    loyaltyProgram.Redeemloyaltypts();

    return 0;
}

