#include <iostream>
#include <array>
#include <cstdlib>
#include <ctime>


// void menu( );
// void process( int passWord ,double &balance);
// void display();

int main(){
    srand(time(nullptr));
    // Varible bank ======================= //
    double long balance = 0, lowBalance = 100, highBalance = 1000000;
    int passWord = 0;

    // Varible card ======================= //
    std::array<long, 10> randomData {
        1000,10000, // credit id
        1,12, // month
        27,35, // years
        100,200 // cvv
    };

    // Random bank data ======================= //
    balance = lowBalance + std::rand() % (int)( highBalance - lowBalance );

    // Random card data ======================= //
    int size = 4;
    int* creditData = new int[size]; // Month _ Year _ CVV

    std::array<int , 2> randomIndex = {2,3}; // {2,3} = Money , {4,5} = month , {6,7} = years , {8,9} = cvv
    for(int i = 0; i < size; ++i)
    {
        creditData[i] = randomData[randomIndex[2]] + std::rand() % ( randomData[randomIndex[3]] - randomData[randomIndex[2]] ); // randomIndex[1] => high_dist - randomIndex[0] => low_dist
        randomIndex[2] += 2 ,randomIndex[3] += 2; // first Iteration randomIndex[1000] , randomIndex[10000] => credit id -- second Iteration randomIndex[100000] , randomIndex[10000000] => money ...etc
    }

    int* id = new int[size];
    
    for(int i = 0 ; i < size ; ++i)
    {
        id[i] = randomData[0] + std::rand() % ( randomData[1] - randomData[0] );
    }





    // std::cout << "\n= ID: " << id[0] << " " << id[1] << " " << id[2] << " " << id[3];
    // std::cout << "\n= Date: " << creditData[2] << "/" << creditData[1];
    // std::cout << "\n= CVV: " << creditData[3];
    std::cout << "\n= Cridets: " << balance << std::endl;



// process Fun ======================= //
    // process( passWord , balance);
    // display();

// ATM MENU ====================== //

    // delete []creditData;
    // delete []id;
    return 0;
} // End main  ======================= //

// ATM MENU ====================== //
void menu( ){
    std::cout << "\n=======================" << std::endl;
    std::cout << "======== MENU =========" << std::endl;
    std::cout << "=======================" << std::endl;
    std::cout << "= 1:Balance " << std::endl;
    std::cout << "= 2:Withd draw " << std::endl;
    std::cout << "= 3:Deposit " << std::endl;
    std::cout << "= 4:Exit " << std::endl;
    std::cout << "======================" << std::endl;
}

// END     ======================= //

// process Fun ======================= //
void process( int passWord ,double &balance ){
    int title = 0;
    int choice = 0;
    int deposit = 0;
    int withdDraw = 0;
    int switchLoop = 0;
    char Continue = ' ';
    int limit = 1;
    char option = ' ';

    for(int i = 1 ; i < 5 ; ++i ){
        if( title == 0 ){
            std::cout << "\n======================" << std::endl;
            std::cout << "======== ATM =========" << std::endl;
            std::cout << "======================" << std::endl;
        }
        title++;
        
        std::cout << " Enter your password: ";
        std::cin >> passWord;
        if(passWord == 1111 ){
            do{
                menu();

                std::cout << " Enter your choice: ";
                std::cin >> choice;

                switch(choice){
                    case 1: std::cout << " your current balance is: " << balance << std::endl; break;
                    
                    case 2: 
                        std::cout << " your current balance is: " << balance << std::endl;
                        std::cout << " enter the amount: ";
                        std::cin >> withdDraw;

                        if( withdDraw <= balance && withdDraw >= 0 ){
                            balance -= withdDraw;
                            std::cout << " your current balance now is: " << balance << std::endl;
                        } else std::cout << " It's out of your current balance or it's negative balance " << std::endl;
                    break;

                    case 3:  
                        std::cout << " your current balance is: " << balance << std::endl;
                        std::cout << " enter the amount: ";
                        std::cin >> deposit;
                        
                        if( deposit >= 0 ){
                            balance += deposit;
                            std::cout << " your current balance is: " << balance << std::endl;
                        } else std::cout << " it's negative balance " << std::endl;
                    break;
                    
                    case 4: std::cout << " THANK YOU " << std::endl; switchLoop++; break;
                    default:
                        std::cout << " Uncorect choice " << "\n ( y - Y ) if yout want to try agian \n ( n - N )  if you want to exit\n |\n  -> ";
                        std::cin >> Continue;
                        if( Continue == 'y' || Continue == 'Y')
                        {
                            limit++;
                        } else if( Continue == 'n' || Continue == 'N' ) switchLoop++; 
                        else std::cout << " Wrong choice " << std::endl;
                    break;
                } // End switch ======================= //
            }while(switchLoop < limit); // End switch loop ======================= //
        }else {
            if( i < 4){
                std::cout << " " << i << "\\3" << " do you want to countinu y-Y( yes ) or n-N( no ): ";
                std::cin >> option;
                
                if( option == 'y' || option == 'Y' ){
                    std::cout << " countinu " << std::endl;
                }else if (  option == 'n' || option == 'N' )
                    break;
                else std::cout << " Wrong option " << std::endl;
            } else std::cout <<  " Out of tries" << std::endl;
        } // End else of Password tries  ======================= //
    } // End Password tries  ======================= //
} // End process  ======================= //
