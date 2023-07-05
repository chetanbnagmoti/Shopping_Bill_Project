#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:

    int pcode;
    float price;
    float dis;
    string pname;


    public:

      void menu();
      void administration();
      void buyer();
      void add();
      void edit();
      void rem();
      void list();
      void receipt();
};


void shopping :: menu()
{   
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t                                          \n";
    cout<<"\t\t\t\t       SuperMarket Main Menu               \n";
    cout<<"\t\t\t\t                                           \n";
    cout<<"\t\t\t\t__________________________________________\n";
    cout<<"\t\t\t\t|      1)Administrator      |\n";
    cout<<"\t\t\t\t|      2)Buyer              |\n";
    cout<<"\t\t\t\t|      3)Exit               |\n";
    cout<<"\t\t\t\t|                           |\n";
    cout<<"\n\t\t\t  Please Select Any One :- ";
    cin>>choice;


    switch(choice)
    {
        case 1:

       { 
           cout<<"\t\t\t\t  Plase Login     \n";
           cout<<"\t\t\t\t  Enter Email     \n";
           cin>>email;
           cout<<"\t\t\t\t  Enter Password  \n";
           cin>>password;

          if(email == "chetan@gmail.com" && password == "123")

           {
            administration();
           }else{
            cout<<"Invalid Password !!!!";
           }
           break;
       }
           case 2:
           {
            buyer();
            break;
           }
           case 3:
           {
            exit(0);
           }
           default:
           {
            cout<<"Please Select From The Given Options";
           }
            
    }
   goto m;
}


void shopping:: administration(){
      m:
      int choice;
      cout<<"\n\n\n\t\t\t   Administrator menu  ";
      cout<<"\n\t\t\t\t\t |_______1)Add the product_________|";
      cout<<"\n\t\t\t\t\t_________2)Modify the product______|";
      cout<<"\n\t\t\t\t\t_________3)Delete the product_______|";
      cout<<"\n\t\t\t\t\t_________4)Back to main Menu________|";

      cout<<"\n\n\t Please enter your choice:-";
      cin>>choice;

      switch (choice)
      {
      case 1:
      {   add();
          break;
      }
      case 2:
      {   edit();
          break;
      }
      case 3:
      {   rem();
          break;
      }
      case 4:
      {   menu();
          break;
      }
      default:
         cout<<"Invalide choice !! ";
        
      }

  goto m;

}


void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t   1)Buyer   \n";
    cout<<"\t\t\t   2)Buy Product    \n";
    cout<<"\t\t\t   3)Go Back        \n";
    cout<<"\t\t\t   Enter your choice \n";
    cin>>choice;

    switch (choice)
    {
    case 1:
    {
        receipt();
         break;
    }
       case 2:
    {
        menu();
         break;
    }
    default:
        cout<<"Invalide choice :";
    }
  goto m;
}

void shopping ::add()
{   m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;

    cout<<"\n\n\t\t\t Add new Product:-";
    cout<<"\\n\n\t\t\t Product code of the product ";
    cin>>pcode;
    cout<<"\n\n Name of the product :-";
    cin>>pname;
    cout<<"\n\n\t\t\t  Price of the product ";
    cin>>price;
    cout<<"\n\n\t\t\t  Discount on the product";
    cin>>dis;

    data.open("database.txt" ,ios::in);

    if(!data){
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
        data.close();
    }else{
        data>>c>>n>>p>>d;

        while(!data.eof())
        {
            if(c==pcode){
                 token++;
            }
            data>>c>>n>>p>>d;
            
        }
        data.close();
    

    if(token==1)
    goto m;
    else{
        data.open("database.txt",ios::app|ios::out);
        data<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"\n";
        data.close();
    }
}
    cout<<"\n\n\n\t\t\t Record Inserted !!!!";
}


void shopping:: edit()
{
    fstream data,data1;
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;

    cout<<"\n\t\t\t\t  Modify the Record ";
    cout<<"\n\t\t\t\t  Product code : ";
    cin>>pkey;

    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nFile does'not exit !";
    }else{
        data1.open("database1.txt",ios::app|ios::out);

        data>>pcode>>pname>>price>>dis;
          while(!data.eof()){
            if(pkey==pcode){
                cout<<"\n\t\t\t  Product new Code : ";
                cin>>c;
                cout<<"\n\t\t\t Name of the Product : ";
                cin>>n;
                cout<<"\n\t\t\t  Price :";
                cin>>p;
                cout<<"\n\t\t\t  Discount :" ;
                cin>>d;
                data1<<" "<<c<<"  "<<n<<"  "<<p<<"  "<<d<<"  "<<"\n";
                cout<<"\n\n\t\t\t   Record edited ";
                token++;

            }
            else
            {
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"  "<<dis<<"  \n";
            }

            data>>pcode>>pname>>price>>dis;
          }

          data.close();
          data1.close();


          remove("database.txt");
          rename("database1.txt","database.txt");

          if(token==0){
            cout<<"\n\n Record Not Found Soorry !!!";
          }



    }
}


void shopping :: rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t\t\t Delete Product ";
    cout<<"Enter the Product Code :";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data){
        cout<<"File Does not Exit";
    }
    else{
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        while (!data.eof())
        {
            if(pcode==pkey){
                cout<<"\n\n\t\t\t   Product Dleted Succesfully !!! ";
                token++;
            }
            else{
                data1<<"  "<<pcode<<"  "<<pname<<"  "<<price<<"   "<<dis<<"\n";
            }

            data>>pcode>>pname>>price>>dis;
        }
      data.close();
      data1.close();
      remove("database.txt");
      rename("database1.txt","database.txt");

      if(token==0){
        cout<<"\n\n\t Record Can not Found";
      }

        
    }
}


void shopping:: list()
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|_______________________________________________\n";
    cout<<"Product Number \t\ttName\t\tPrice\n";
    cout<<"\n\n|________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while (!data.eof()){
        
            cout<<pcode<<"t\t"<<pname<<"\t\t"<<price<<"\n";
            data>>pcode>>pname>>price>>dis;

    }
    
      data.close(); 
    
}


void shopping:: receipt()
{
    fstream data;
    int arrc[100];
    int arrq[100];
    char choice;
    int c=0;
    float amount;
    float dis=0;
    float total=0;

    cout<<"\n\n\t\t\t\t Receipt :- ";

    data.open("database.txt",ios::in);
    if(!data){
        cout<<"\n\n  Empty Database ";
    }
    else{
        data.close();

        list();
        cout<<"\n\n________________________________________________________\n";
        cout<<"\n\n|           Plase Place The Order                       \n";
        cout<<"\n\n________________________________________________________\n";
        do
        {  m:
           cout<<"/n/n Enter the product Code ";
           cin>>arrc[c];
           cout<<"/n/nEnter the quntity ";
           cin>>arrq[c];
           for(int i=0;i<c;i++)
           {
            if(arrc[c] ==arrc[i])
            {
                cout<<"\n\n  Dulicate Product Code Plase Try Again ";
                goto m;
            }
           }
           c++;
           cout<<"\n\n Do ou want to pay another product : if yes then presss y else no";
           cin>>choice;
        } while (choice =='y');


        cout<<"\n\n\t\t\t ___________________________Receipt___________________________\n";
        cout<<"\nProduct No \t Prpduct Name \t Product Quntity \t Pricre \t Amounnt With Discount \n";

        for(int i=0;i<c;i++)
        {
            data.open("database.txt" ,ios::in);
            
                data>>pcode>>pname>>price>>dis;
                while (!data.eof())
                {
                   if(pcode==arrc[i])
                   {
                    amount=price*arrq[i];
                    dis=amount-(amount*dis/100);
                    total=total+dis;
                    cout<<"\n"<<"\t\t"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                   }

                   data>>pcode>>pname>>price>>dis;
                }
            
        }
        data.close();
        
    }
    cout<<"\n\n_______________________________________________________________________\n";
    cout<<"\n Total Amount  :"<<total;
}

int main(){
    shopping s;
    s.menu();
}