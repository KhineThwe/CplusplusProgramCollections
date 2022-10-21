//
// Created by Khine on 10/8/2022.
//
#include "iostream"
using namespace std;
class Bank{
public:
    int locate=0;
    int currentIndex=0;
    int currentAmount = 0;
    string username[100];
    string upassword[100];
    int uamount[100];

    Bank(){
        cout<<"Welcome to our Bank!!"<<endl;
    }
    int reGister();
    int login();
    int mainMenu();
    int allInfo();
    int exchange();
    int toTransfer(int currentIndex,int receiverId,int toTransferAmount);
    int toCheckUserName(string toTransferName);
    int toWithdraw(int currentIndex,int withdrawAmount);
    int updatingAmount(int updateAmount,int updateOption);
    int changeAccountInfo();
    int changeAccountUsername();
    int changeAccountPassword();
};
int Bank::reGister(){
    string name;
    string password;
    string conPassword;
    int money;
    cout<<"This is from registration"<<endl;
    cout<<"Enter your name to register: "<<endl;
    cin>>name;
    int status = toCheckUserName(name);
    if(status==1111){
        cout<<"Enter your password to register: "<<endl;
        cin>>password;
        cout<<"Confirm password to register: "<<endl;
        cin>>conPassword;
        if(password == conPassword){
            cout<<"Enter amount: ";
            cin>>money;
            username[locate] = name;
            upassword[locate] = password;
            uamount[locate] = money;
            cout<<"Registration Success!!"<<endl;
            locate++;
            allInfo();
    }else{
        cout<<"Passwords don't match!!Registration Fail!!Try Again!!"<<endl;
        reGister();
    }
}else{
      cout<<"######Username Already Registered######"<<endl;
      reGister();
    }
}
int Bank::login() {
    string lusername;
    string lpassword;
    cout<<"This is from login"<<endl;
    cout<<"Enter username to login: "<<endl;
    cin>>lusername;
    cout<<"Enter password to login for"<<lusername<<endl;
    cin>>lpassword;

    for(int i=0;i<=locate;i++){
        if(lusername == username[i] && lpassword == upassword[i]){
            currentIndex = i;
            currentAmount = uamount[i];
            cout<<"Login Success"<<endl;
            exchange();
        }
    }
    return 100;
}
int Bank::mainMenu(){
    int option ;
    while(true){
        cout<<"Press 1 to Register: "<<endl;
        cout<<"Press 2 to Login: "<<endl;
        cout<<"Press 3 to Quit: "<<endl;
        cin>>option;

        if(option == 1){
            //registration
            reGister();

        }else if(option == 2){
            //login
            int status = login();
            if(status == 100){
                cout<<"Try again"<<endl;
            }
        }else{
            cout<<"Bye Bye"<<endl;
            return 0;
        }
    }
}
int Bank::allInfo() {
    cout<<"Username: "<<endl;
    for(int i=0;i<=locate;i++){
        cout<<" "<<username[i]<<endl;
    }

    cout<<"Password: "<<endl;
    for(int i=0;i<=locate;i++){
        cout<<" "<<upassword[i]<<endl;
    }

    cout<<"Amount: "<<endl;
    for(int i=0;i<locate;i++){
        cout<<" "<<uamount[i]<<endl;
    }
}
int Bank::exchange(){
    string toTransferName;
    int toTransferAmount;
    int exchangeOption = 0;
    cout<<"Press 1 to Transfer: "<<endl;
    cout<<"Press 2 to Withdraw: "<<endl;
    cout<<"Press 3 to Update: "<<endl;
    cout<<"Press 4 to Quit: "<<endl;
    cout<<"Press 5 to change account Information!!"<<endl;
    cin>>exchangeOption;
    if(exchangeOption == 1){
       cout<<"Enter name to transfer: ";
       cin>>toTransferName;
       int receiverId = toCheckUserName(toTransferName);
       if(receiverId>=0){
           while(receiverId>=0){
               cout<<"Enter amount to Transfer: "<<endl;
               cin>>toTransferAmount;
               if(toTransferAmount>=currentAmount){
                   cout<<"Invalid amount: "<<endl;
                   continue;
               }else{
                 toTransfer(currentIndex,receiverId,toTransferAmount);
                 allInfo();
                 exchange();
               }
           }
       }else{
           cout<<"Name is not exit in our db"<<endl;
           exchange();
       }
    }else if(exchangeOption == 2){
        //to withdraw
        int withdrawAmount = 0;
        cout<<"To Withdraw Option"<<endl;
        cout<<"Enter amount to withdraw: ";
        cin>>withdrawAmount;
        if(uamount[currentIndex]-1000 > withdrawAmount){
            toWithdraw(currentIndex,withdrawAmount);
            exchange();
        }else{
            cout<<"Invalid amount to withdraw"<<endl;
            exchange();
        }
    }else if(exchangeOption == 3){
        int updateAmount = 0;
        int updateOption = 0;
        cout<<"This is Update Option: "<<endl;
        cout<<"Press 1 To add amount for update\nPress 2 To sub amount for Update!"<<endl;
        cin>>updateOption;
        if(updateOption == 1){
            cout<<"Enter amount to add for update : "<<username[currentIndex];
            cin>>updateAmount;
            updatingAmount(updateAmount,updateOption);
            allInfo();
            exchange();
        }else{
            cout<<"Enter amount to sub for update for : "<<username[currentIndex];
            cin>>updateAmount;
            updatingAmount(updateAmount,updateOption);
            allInfo();
            exchange();
        }

    }else if(exchangeOption == 4){
        //quit option
        login();
    }else if(exchangeOption == 5){
        //account information
        changeAccountInfo();
    }else{
        cout<<"Invalid Option!!"<<endl;
        exchange();
    }
}
int Bank::toTransfer(int currentIndex,int receiverId,int toTransferAmount) {
    uamount[currentIndex] = uamount[currentIndex]-toTransferAmount;
    uamount[receiverId] = uamount[receiverId]+toTransferAmount;
    cout<<"Money Successfully Transferred to: "<<username[receiverId]<<endl;
    cout<<"Transferred Amount: "<<toTransferAmount;
}

int Bank::toCheckUserName(string toTransferName){
    for(int i=0;i<=locate;i++){
        if(toTransferName == username[i]){
            return i;
        }
    }
    return 1111;//error code for checking username
}

int Bank::toWithdraw(int currentIndex,int withdrawAmount){
    uamount[currentIndex] = uamount[currentIndex]-withdrawAmount;
    cout<<username[currentIndex]<<" : Amount= "<< uamount[currentIndex]<<endl;
}

int Bank::updatingAmount(int updateAmount,int updateOption) {
    if(updateOption == 1){
        uamount[currentIndex] = uamount[currentIndex] + updateAmount;
    }else{
        uamount[currentIndex] = uamount[currentIndex] - updateAmount;
    }
}
int Bank::changeAccountInfo(){
    int changeOption=0;

    cout<<"Press 1 to change username\n Press 2 to change password: "<<endl;
    cin>>changeOption;
    if(changeOption == 1){
        changeAccountUsername();
    }else if(changeOption == 2){
        changeAccountPassword();
    }
}
int Bank::changeAccountUsername() {
    string newUsername;
    cout<<"This is your current username: "<<username[currentIndex]<<endl;
    cout<<"Enter your new username : ";
    cin>>newUsername;
    int status = toCheckUserName(newUsername);//not include code 1111
    if(status == 1111){
        cout<<"Updating your new username........"<<endl;
        username[currentIndex] = newUsername;
        if(username[currentIndex] == newUsername){
            cout<<"Changing Success"<<endl;
            cout<<"This is your new username: "<<username[currentIndex]<<endl;
            mainMenu();
        }
    }else{
        cout<<"New username already registered!"<<endl;
        changeAccountUsername();
    }
}
int Bank::changeAccountPassword() {
    string newPassword;
    string currentPassword;
    cout<<"Enter your current password!";
    cin>>currentPassword;
    if(currentPassword == upassword[currentIndex]){
        cout<<"Enter your new password : ";
        cin>>newPassword;
        if(newPassword == currentPassword){
            cout<<"Passwords are same with old one:"<<endl;
            changeAccountPassword();
        }else{
            upassword[currentIndex] = newPassword;
            cout<<"Password changed successfully!!"<<endl;
            mainMenu();
        }
    }else{
        cout<<"Wrong Password!"<<endl;
        exchange();
    }
}
int main(){
    Bank _obj;
    int ex=_obj.mainMenu();
    if(ex == 0){
        exit(1);
    }
    return 0;
}

