#include <iostream>
#include <string.h>
// #include <iomanip>
#include <array>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <random>

int SizesProcess(int choice);
void IdProcess();
void ClientProcess();
// void BankProcess();
// void Menu();
// void AtmProcess( int passWord ,double &balance);
// void Display( int id[] ,int credData[] );

struct Data{ // Data  ======================= //
    int sizes = 0;
    int choice = 0;
    int limit = 1;
    int userChoice = 1 , clientChoice = 2;

}; // Data End ======================= //

struct Client{ // User Data ======================= //

    std::string name = " ";
    int lowIdRandomAToZ = 65 ,highidRandomAToZ = 90; // ASCII A -> Z
    long userId = 0, lowUserId = 100000000 , highUserId = 1000000000;
    std::string address = " ";
    int age = 0;
    

}; // User Data End ======================= //

struct Account{ // Client Data ======================= //
    long long AccountNumber = 0, lowAccountNumber = 1000000000 , highAccountNumber = 2000000000; // Created to make random ( Account Number ) 
    std::string accountType = " ";
    std::string Status = " "; // ACTIV OR NOT
    int currencyOptions = 0; 
    int currencySize = 0;
    std::vector <std::string> Currency; // "USD" , "EUR" , "GBP"
    std::string accountStatus = " "; // SAVINGS OR NOT
    char accountStatusOptions = ' ';
    std::string debitCard = " ";
    char debitCardOptions = ' ';
    std::string accountBenefits = " ";

}; // Client Data End ======================= //

struct Bank{ // Bank Data ======================= //
    double availableBalance = 0.0 , minimumOpeningBalance = 1000 , minimumBalance = 500;
    float accountFees = 0;
    double withdDraw = 0 , withdDrawLimts = 0 , deposit = 0;

    // if Account Status is savings;
    int interestOne = 10 , interestOne = 15 , interestOne = 30; // 500 X 10/100 = 50
        
}; // Bank Data End ======================= //

struct Atm{ // ATM Data  ======================= //
    int title = 0;
    int switchLoop = 0;
    char Continue = ' ';
    char option = ' ';
}; // End Data Atm ======================= //

struct Card{ // Card Data ======================= //
    std::array<int, 10> randomData {
        1000,10000, // credit id
        1,12, // month
        27,35, // years
        100,200 // cvv
    };

    int size = 4;
    int* credData = new int[size]; // Month _ Year _ CVV
    int* id = new int[size];
    int passWord = 0;

}; // Card Data End ======================= //

int main(){ // main  ======================= //
    srand(time(nullptr));




// Random bank data ======================= //
    // std::random_device _rd{};
    // std::mt19937 _gen{_rd()};
    // std::uniform_real_distribution<double> _dist;
    // std::uniform_real_distribution<double>::param_type param(bank.lowBalance, bank.highBalance);
    // _dist.param(param);
    // _dist(_gen);


// Random card data ======================= //


    // std::array<int , 2> randomIndex = {2,3}; // {2,3} = Money , {4,5} = month , {6,7} = years , {8,9} = cvv
    // for(int i = 0; i < size; ++i)
    // {
    //     creditData[i] = randomData[randomIndex[2]] + std::rand() % ( randomData[randomIndex[3]] - randomData[randomIndex[2]] ); // randomIndex[1] => high_dist - randomIndex[0] => low_dist
    //     randomIndex[2] += 2 ,randomIndex[3] += 2; // first Iteration randomIndex[1000] , randomIndex[10000] => credit id -- second Iteration randomIndex[100000] , randomIndex[10000000] => money ...etc
    // }

    
    // for(int i = 0 ; i < card.size ; ++i)
    // {
    //     card.id[i] = card.randomData[0] + std::rand() % ( card.randomData[1] - card.randomData[0] );
    // }

// bottons ======================= //
    // atmProcess( card.passWord , bank.Balance );
    IdProcess();
    ClientProcess();
    // display( card.id , card.credData );

// ATM MENU ====================== //

    // delete []creditData;
    // delete []card.id;
    return 0;
} // End main  ======================= //

int SizesProcess( int choice ){ // Sizes Process  ======================= //
    int usertSize = 0 , clientSize = 0;
        do{
            switch(choice){
                case 1:
                    std::cout << "\n=================================" << std::endl;
                    std::cout << "======== SIZE OF USERS =========" << std::endl;
                    std::cout << "==================================" << std::endl;
                    std::cout << "= HOW MANY USERS: ";
                    std::cin >> usertSize;
                    if(usertSize > 0){
                        return usertSize;
                    } else std::cout << " ERROR: 0 OR NEGATIVE " << std::endl;
                break;

                case 2:
                        std::cout << "\n=================================" << std::endl;
                        std::cout << "======== SIZE OF CLIENTS =========" << std::endl;
                        std::cout << "==================================" << std::endl;
                        std::cout << "= HOW MANY CLIENT: ";
                        std::cin >> clientSize;
                        if(usertSize > 0){
                            return usertSize;
                        } else std::cout << " ERROR: 0 OR NEGATIVE " << std::endl;
                break;
            } // End switch ====================== //
        }while(true);
} // Sizes Process End ====================== //

void IdProcess(){ // ID  ====================== //
    std::random_device dev;
    std::mt19937 rng(dev());
    Data data;
    std::vector<Client>user(SizesProcess(data.userChoice));

    // ID Process  ====================== //

    for(int i = 0; i < user.size() ; ++i){

        std::uniform_int_distribution<std::mt19937::result_type> dist6( user.at(i).lowIdRandomAToZ , user.at(i).highidRandomAToZ );
        user.at(i).userId = user.at(i).lowUserId + std::rand() % ( user.at(i).highUserId - user.at(i).lowUserId);

        std::cout << "\n===============================" << std::endl;
        std::cout << "======== USER ID =========" << std::endl;
        std::cout << "===============================" << std::endl;
        std::cout << "= ID: " << char(dist6(rng)) << user.at(i).userId << std::endl;
    }

    // ID Process End ====================== //



} // ID End ====================== //

void ClientProcess(){ // Client ====================== //
    Data data;
    std::vector<Account> account(SizesProcess(data.clientChoice));

    for(int i = 0; i < account.size() ; ++i){
        std::cout << "\n=================================" << std::endl;
        std::cout << "======== CLIENT SERVICE =========" << std::endl;
        std::cout << "=================================" << std::endl;
        std::cout << "= CLIENT NUMBER [ " << account.at(i).AccountNumber << " ]" << std::endl;
        std::cout << "= Please type y - Y{yeas} or n - N(no)" << std::endl; 
        std::cout << "= Savings Account? ";
        std::cin >> account.at(i).accountStatusOptions;
        if( account.at(i).accountStatusOptions == 'y' || account.at(i).accountStatusOptions == 'Y' ){
            account.at(i).accountStatus = "SAVINGS";
        } else if ( account.at(i).accountStatusOptions == 'n' || account.at(i).accountStatusOptions == 'N' ) {
            account.at(i).accountStatus = "Current";
        } // End if ====================== //
        
        std::cout << "( 1 - USD | 2 - EUR | 3 - GBP )" << std::endl;
        std::cout << "How Many Currency? ";
        std::cin >> account.at(i).currencySize;
        for( int j = 0; j < account.at(i).currencySize ; ++j){
            std::cout << "Which Currency? ";
            std::cin >> account.at(i).currencyOptions;
            if( account.at(i).currencyOptions <= 3 && account.at(i).currencyOptions > 0 ){
                switch(account.at(i).currencyOptions){
                    case 1: account.at(i).Currency.push_back("USD"); break;
                    case 2: account.at(i).Currency.push_back("EUR"); break;
                    case 3: account.at(i).Currency.push_back("GBP"); break;
                    default: std::cout << "Wrong choice" << std::endl;
                } // End switch ====================== //
            } else {
                std::cout << "OUT OF RANGE" << std::endl;
            } // End if ====================== //
        } // End for ====================== //

        std::cout << "Debit Card? " << std::endl;
        std::cin >> account.at(i).debitCardOptions;
        if( account.at(i).debitCardOptions == 'Y' || account.at(i).debitCardOptions == 'y' ){
            account.at(i).debitCard = "yes";
        } else if ( account.at(i).debitCardOptions == 'N' || account.at(i).debitCardOptions == 'n' ){
            account.at(i).debitCard = "No";
        } else std::cout << " PLEASE YES OR NO " << std::endl;
    } // End for ====================== //
} // Client End ====================== //


// ATM MENU ====================== //
// void menu( ){
//     std::cout << "\n=======================" << std::endl;
//     std::cout << "======== MENU =========" << std::endl;
//     std::cout << "=======================" << std::endl;
//     std::cout << "= 1:Balance " << std::endl;
//     std::cout << "= 2:Withd draw " << std::endl;
//     std::cout << "= 3:Deposit " << std::endl;
//     std::cout << "= 4:Exit " << std::endl;
//     std::cout << "======================" << std::endl;
// }

// END     ======================= //

// process Fun ======================= //
// void atmProcess( int passWord ,double &balance ){


//     for(int i = 1 ; i < 5 ; ++i ){
//         if( title == 0 ){
//             std::cout << "\n======================" << std::endl;
//             std::cout << "======== ATM =========" << std::endl;
//             std::cout << "======================" << std::endl;
//         }
//         title++;
        
//         std::cout << " Enter your password: ";
//         std::cin >> passWord;
//         if(passWord == 1111 ){
//             do{
//                 menu();

//                 std::cout << " Enter your choice: ";
//                 std::cin >> choice;

//                 switch(choice){
//                     case 1: std::cout << " your current balance is: " << balance << std::endl; break;
                    
//                     case 2: 
//                         std::cout << " your current balance is: " << balance << std::endl;
//                         std::cout << " enter the amount: ";
//                         std::cin >> withdDraw;

//                         if( withdDraw <= balance && withdDraw >= 0 ){
//                             balance -= withdDraw;
//                             std::cout << " your current balance now is: " << balance << std::endl;
//                         } else std::cout << " It's out of your current balance or it's negative balance " << std::endl;
//                     break;

//                     case 3:  
//                         std::cout << " your current balance is: " << balance << std::endl;
//                         std::cout << " enter the amount: ";
//                         std::cin >> deposit;
                        
//                         if( deposit >= 0 ){
//                             balance += deposit;
//                             std::cout << " your current balance is: " << balance << std::endl;
//                         } else std::cout << " it's negative balance " << std::endl;
//                     break;
                    
//                     case 4: std::cout << " THANK YOU " << std::endl; switchLoop++; break;
//                     default:
//                         std::cout << " Uncorect choice " << "\n ( y - Y ) if yout want to try agian \n ( n - N )  if you want to exit\n |\n  -> ";
//                         std::cin >> Continue;
//                         if( Continue == 'y' || Continue == 'Y')
//                         {
//                             limit++;
//                         } else if( Continue == 'n' || Continue == 'N' ) switchLoop++; 
//                         else std::cout << " Wrong choice " << std::endl;
//                     break;
//                 } // End switch ======================= //
//             }while(switchLoop < limit); // End switch loop ======================= //
//         }else {
//             if( i < 4){
//                 std::cout << " " << i << "\\3" << " do you want to countinu y-Y( yes ) or n-N( no ): ";
//                 std::cin >> option;
                
//                 if( option == 'y' || option == 'Y' ){
//                     std::cout << " countinu " << std::endl;
//                 }else if (  option == 'n' || option == 'N' )
//                     break;
//                 else std::cout << " Wrong option " << std::endl;
//             } else std::cout <<  " Out of tries" << std::endl;
//         } // End else of Password tries  ======================= //
//     } // End Password tries  ======================= //
// } // End process  ======================= //


// void display( int id[] ,long credData[] ){



//     std::cout << "\n= ID: " << id[0] << " " << id[1] << " " << id[2] << " " << id[3] << std::endl;
//     std::cout << "\n= Date: " << credData[2] << "/" << credData[1];
//     std::cout << "\n= CVV: " << credData[3];
//     std::cout << std::fixed << std::setprecision(2);
//     std::cout << "Balance: " << _dist(_gen) << '\n';
// }