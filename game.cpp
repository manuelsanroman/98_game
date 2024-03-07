/*
Name: Team 6
Game: 98 (cards)

-------------------------------

MY CODE:

We will create objects to represent the cards.
We have a parent class Card.
And we have 6 child clasess: NumCard, SkipCard, RevCard, Draw2Card, WildCard and Wild4Card.

Each card must define as class members its type, number and color, as well as the number of play. When the card has no color o number, the members should be 0 or "0".

We have a virtual function call showCard(), which is used to show the attributes of each card. This function changes depending on the type of child class, as it only shows the essential information for each type of card:
- Only type for WildCard and Wild4Card.
- Only color and type for SkipCard, RevCard and Draw2Card.
- Only color and number for NumCard.

We have a function setPlay() to count the plays that have been made.

We have a friend fucntion called move() which determines if you can use a specific card. For that, it takes as attributes two cards (in the game they will be the last card on the table and the card from your hand that wants to check). It compares both cards and determines if you can use that card. If the card is valid, it returns 1, if it is not, it returns 0.

When we create a card (an object), we must use the constructor to specify the type ("Number", "Skip", "Draw Two", "Reverse", "Wild" or "Wild Draw Four"), the number (0-9), and the color ("Red", "Yellow", "Green" or "Blue").

-------------------------------
RULES:

The game is a drinking game caled 98.

The rules are as follow:
The objective of the game is to get the other player to overpass 98 and you to avoid to pass 98.

The cards are as follow:
1-7 Number Cards: Add its value to the sum of the play.
"Substract Ten": When play discards this one, the sum is substracted 10.
"Reverse": Changes the turn of the actual player.
"You Decide": Changes the sum to the number you decide to be.

When a player gets to 10, 20, 30, 40, 50, 60, 70, 80 and 90, the other player drinks x/10 swallows of the drink.

When a player surpass 98, he has to drink a shot.
*/



#include <iostream>
#include <ctime>
using namespace std;


class Card{ // Parent class
private: // Private member
    int count = 0;

public: // Public members and methods
    int play;
    string type;
    int num;
    string color;

    Card(string t, int n, string c){ // Constructor
        type = t;
        num = n;
        color = c;
    };

    friend void move(Card); // Friend function

    virtual void showCard(){ // Virtual method
        cout << " The card is a " << type << " card: ";
        cout << "(" << num << ", " << color << ")";
    };

    void setType(){}

    void setPlay(){ // Sets the number of plays
        count += 1;
        play = count;
    };
};

class NumCard: public Card{ // one zero, two each of 1 through 9 of each color suite
public:
    NumCard(string t, int n, string c) : Card(t, n, c){}; // Constructor

    void showCard(){
        cout << "\nThe card is: \n";
        cout << " Color: " << color << ", Number: " << num;
    }
};

class SkipCard: public Card{ // Next player in sequence misses a turn
public:
    SkipCard(string t, int n, string c) : Card(t, n, c){}; // Constructor

    void showCard(){
        cout << "The card is: \n";
        cout << " Color: " << color << ", Type: " << type;
    }
};

class RevCard: public Card{ // Order of play switches directions
public:
    RevCard(string t, int n, string c) : Card(t, n, c){}; // Constructor

    void showCard(){
        cout << "\nThe card is: \n";
        cout << " Color: " << color << ", Type: " << type;
    }
};

class Draw2Card: public Card{ // Next player in sequence draws two cards and misses a turn
public:
    Draw2Card(string t, int n, string c) : Card(t, n, c){}; // Constructor

    void showCard(){
        cout << "The card is: \n";
        cout << " Color: " << color << ", Type: " << type;
    }
};

class WildCard: public Card{ // 	Player declares the next color to be matched (may be used on any turn even if the player has matching color)
public:
    WildCard(string t, int n, string c) : Card(t, n, c){}; // Constructor

    void showCard(){
        cout << "\nThe card is: \n";
        cout << "Type: " << type;
    }
};

class Wild4Card: public Card{ // Player declares the next color to be matched; next player in sequence draws four cards and misses a turn.
public:
    Wild4Card(string t, int n, string c) : Card(t, n, c){}; // Constructor

    void showCard(){
        cout << "\nThe card is: \n";
        cout << "Type: " << type;
    }
};

int move(Card previous, Card actual){ // Friend function
    if (previous.color == actual.color){
        return 1;
    }

    else if (previous.num == actual.num){
        return 1;
    }

    else if ((actual.type == "Wild") || (actual.type == "Wild Draw Four")){
        return 1;
    }

    else{
        return 0;
    }
};


void showCards(Card playerhand[]){

    for(int i=0; i<3; i++){
        cout << "\n\n" << i+1 << ". ";
        playerhand[i].showCard();
    }
};

Card selectedCard(Card playerhand[], int c){
    Card selectedCard("0", 0, "0");

    switch (c) {
        case 1: {
            selectedCard = playerhand[0];
            break;
        }

        case 2: {
            selectedCard = playerhand[1];
            break;
        }


        case 3: {
            selectedCard = playerhand[2];
            break;
        }

    }

    return selectedCard;
};


int action(Card selectedCard, int sum, int turn){
    if (selectedCard.type == "Number"){
        sum += selectedCard.num;

        return sum;
    }

    else if (selectedCard.type == "You Decide"){
        cout << "Introduce which number you want the sum to be: ";
        cin >> sum;

        return sum;
    }

    else if (selectedCard.type == "Reverse"){
        return sum;
    }

    else{ // Substract 10
        return sum-10;
    }
}


int selectTurn(Card selectedCard, int turn){
    if (selectedCard.type == "Number"){
        if (turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }

        return turn;
    }

    else if (selectedCard.type == "You Decide"){
        if (turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }

        return turn;
    }

    else if (selectedCard.type == "Reverse"){
        cout << "\n>>> It's your time again!\n";
        if (turn == 1){
            turn = 1;
        }
        else{
            turn = 2;
        }
        return turn;
    }

    else{ // Substract 10
        if (turn == 1){
            turn = 2;
        }
        else{
            turn = 1;
        }

        return turn;
    }
}


void changeCard(Card playerhand[], int c, Card allCards[]){
    playerhand[c-1] = allCards[rand() % 40];
};


int main(){ // Just used to check if everything works
    Card allCards[40] = {
            NumCard("Number", 1, "Red"),
            NumCard("Number", 2, "Red"),
            NumCard("Number", 3, "Red"),
            NumCard("Number", 4, "Red"),
            NumCard("Number", 5, "Red"),
            NumCard("Number", 6, "Red"),
            NumCard("Number", 7, "Red"),
            NumCard("Number", 1, "Yellow"),
            NumCard("Number", 2, "Yellow"),
            NumCard("Number", 3, "Yellow"),
            NumCard("Number", 4, "Yellow"),
            NumCard("Number", 5, "Yellow"),
            NumCard("Number", 6, "Yellow"),
            NumCard("Number", 7, "Yellow"),
            NumCard("Number", 1, "Green"),
            NumCard("Number", 2, "Green"),
            NumCard("Number", 3, "Green"),
            NumCard("Number", 4, "Green"),
            NumCard("Number", 5, "Green"),
            NumCard("Number", 6, "Green"),
            NumCard("Number", 7, "Green"),
            NumCard("Number", 1, "Blue"),
            NumCard("Number", 2, "Blue"),
            NumCard("Number", 3, "Blue"),
            NumCard("Number", 4, "Blue"),
            NumCard("Number", 5, "Blue"),
            NumCard("Number", 6, "Blue"),
            NumCard("Number", 7, "Blue"),
            SkipCard("You Decide", 0, "Red"),
            SkipCard("You Decide", 0, "Green"),
            SkipCard("You Decide", 0, "Yellow"),
            SkipCard("You Decide", 0, "Blue"),
            RevCard("Reverse", 0, "Red"),
            RevCard("Reverse", 0, "Green"),
            RevCard("Reverse", 0, "Yellow"),
            RevCard("Reverse", 0, "Blue"),
            Draw2Card("Substract Ten", 0, "Red"),
            Draw2Card("Substract Ten", 0, "Green"),
            Draw2Card("Substract Ten", 0, "Yellow"),
            Draw2Card("Substract Ten", 0, "Blue")
    };

    srand(time(0));

    Card Player1Hand[3] = {
            allCards[rand() % 40],
            allCards[rand() % 40],
            allCards[rand() % 40],
    };

    Card Player2Hand[3] = {
            allCards[rand() % 40],
            allCards[rand() % 40],
            allCards[rand() % 40],
    };

    int sum = 0;
    int c = 0;
    int turn = 1;
    string o;
    string player1;
    string player2;

    cout << "\nPlease, insert name of player 1: ";
    cin >> player1;

    cout << "\nPlease, insert name of player 2: ";
    cin >> player2;


    while(sum<98){
        if (turn == 1){
            cout << "\n-------- TURN FOR " << player1 << " --------\n\nThese are your cards:";
            showCards(Player1Hand);

            cout << "\n\nPlease, select which card you want to play: ";
            cin>>c;
            cout << "\n";

            Card selected = selectedCard(Player1Hand, c);
            sum = action(selected, sum, turn);

            if ((sum == 10)||(sum == 20)||(sum == 30)||(sum == 40)||(sum == 50)||(sum == 60)||(sum == 70)||(sum == 80)||(sum == 90)){
                cout << "\n\n>>> DECIDE WHO DRINKS " << sum/10 << " SWALLOWS OF HIS/HER DRINK.\nWrite anything to continue.\n";
                cin >> o;
            }

            turn = selectTurn(selected, turn);

            cout << "\n\nThe SUM is currently at " << sum << "\n\n\n\n";

            changeCard(Player1Hand, c, allCards);
        }

        else{
            cout << "\n-------- TURN FOR " << player2 << " --------\n\nThese are your cards:";
            showCards(Player2Hand);

            cout << "\n\nPlease, select which card you want to play: ";
            cin>>c;
            cout << "\n";

            Card selected = selectedCard(Player2Hand, c);
            sum = action(selected, sum, turn);

            if ((sum == 10)||(sum == 20)||(sum == 30)||(sum == 40)||(sum == 50)||(sum == 60)||(sum == 70)||(sum == 80)||(sum == 90)){
                cout << "\n\n>>> DECIDE WHO DRINKS " << sum/10 << " SWALLOWS OF HIS/HER DRINK.\nWrite anything to continue.\n";
                cin >> o;
            }

            turn = selectTurn(selected, turn);

            cout << "\n\nThe SUM is currently at " << sum << "\n\n\n\n";

            changeCard(Player2Hand, c, allCards);
        }
    }

    if (turn == 1){
        cout << player1 << " WINS!!!\nThe other player has surpassed 98 and he has to drink a shot.";
    }

    else{
        cout << player2 << " WINS!!!\nThe other player has surpassed 98 and he has to drink a shot.";
    }

}
