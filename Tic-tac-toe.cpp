#include<iostream>
using namespace std;
char space[3][3]={{'1', '2', '3'},{'4', '5', '6'},{'7', '8', '9'}};// a array is formed whoch will be used to repsrent the slots
int row;
int column;
bool tie = false;
string player_1;
string player_2;
char token = 'x';//token used by the first player
void board(){// this function is made to build the architecture or construct how are tic tac toe wil look like
    //this function produces the board of the game
    cout<< "  |   |  \n";
    cout<< " "<<space[0][0]<<"| "<<space[0][1]<<" | "<<space[0][2]<<" \n";//space [i][j] is the specific location of the number
    cout<< "__|___|___  \n";
    cout<< " "<<space[1][0]<<"| "<<space[1][1]<<" | "<<space[1][2]<<" \n";
    cout<< "  |   |  \n";
    cout<< "__|___|___ \n";
    cout<< " "<<space[2][0]<<"| "<<space[2][1]<<" | "<<space[2][2]<<" \n";
    cout<< "  |   |  \n";
    cout<< "  |   |  \n";

}
// this function places the character of the user in thier desired place
void place_character(){

int digit;
if(token=='x')
 {
    cout<<player_1<< " please enter the number where you want to place your character \n";//taking the slot input of the number from the user1
    cin>>digit;
}
else if(token=='0'){
  cout<<player_2<< " please enter the number where you want to place your character \n";//taking the slot input of the number from the user1
    cin>>digit;
}
// as the digit will be provided by the user they are assigned the position so that the character is to replace the number on
//that position
if (digit == 1)
{
    row=0;
    column=0;
}
else if (digit == 2)
{
    row=0;
    column=1;
}
else if (digit == 3)
{
    row=0;
    column=2;
}
else if (digit == 4)
{
    row=1;
    column=0;
}
else if (digit == 5)
{
    row=1;
    column=1;
}
else if (digit == 6)
{
    row=1;
    column=2;
}
else if (digit == 7)
{
    row=2;
    column=0;
}
else if (digit == 8)
{
    row=2;
    column=1;
}
else if (digit == 9)
{
    row=2;
    column=2;
}
else  {cout<<"INVALID!! \n";}  //if the number entered by the user is not between 1-9 then invalid will be printed

//this code will replace the token with the digit but first it will check that it is not occupied by a token before
if (token=='x'&& space[row][column] != 'x' && space [row][column] != '0')
{
space[row][column] = 'x';
token = '0';
}
else if (token=='0'&& space[row][column] != 'x' && space [row][column] != '0')
{
space[row][column] = '0';
token = 'x';
}
else{cout<<"there is no empty space left /n"<<endl;


}
}
//this will decide the winner
bool winner(){

for (int i=0;i<3; i++ )// it checks that if either vertical or horizontal slots are not formed by the tokens if yes
//they are declared as the winners in the main loop
{
    if(space[i][0]==space[i][1] && space[i][0]==space[i][2] || space[0][i]==space[1][i] && space[0][i]==space[2][i])
    {
        return true;
    }
//below code checks if there is no match on the diagnol series, if yes the function is returned true
if(space[0][0]==space[1][1] && space[0][0]==space[2][2] || space[0][2]==space[1][1] && space[0][i]==space[2][0])
    {
        return true;
    }
// the function is returned false if there is any slot is  which is not filled
      for (int i=0;i<3; i++){
        for(int j=0;j<3; j++){
            if (space[i][j] != 'x' || space[i][j] != '0'){
                return false;
                }
// if the condition of if statement doesnt match then it is obvious that all the slots are been filled and the game is a draw
else {tie = true;
    return true;

}
       }
}
}


}
// this where the game starts
int main(){
    cout<< "enter name of first player: \n";//takes the name of the player
    getline(cin, player_1);
    cout<< "enter name of second player: \n";//takes the name of the second player
    getline(cin, player_2);
    cout<<player_1 <<" is the first player so he/she should start first \n";
    cout<<player_2 <<" the second player so he/she should start second\n";

while (!winner() ){//calls all the three functions in the loop while function three is returned false as soon as it is returned true, it will exit the loop

  board();
  place_character();
  winner();

}
// as soon as the winner function is returend true, it exits the loop and checks if tie is true or false and which token is now, and accordingly the winner is decided
if (token == 'x' && tie== false){

    cout<<player_2<<" wins!!"<<endl;

}
else if (token == '0' && tie== false)
{
    cout<<player_1<<" wins!!"<<endl;

}
//this is done in the case of a draw
else if (tie == true) {
    cout<<"it is a draw";
}
}
