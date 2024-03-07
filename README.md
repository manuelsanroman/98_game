# 98_game
An automated cards game.

## Our Code:
We will create objects to represent the cards.
We have a parent class Card.
And we have 6 child clasess: NumCard, SkipCard, RevCard, Draw2Card, WildCard and 
Wild4Card.
Each card must define as class members its type, number and color, as well as the number of 
play. When the card has no color o number, the members should be 0 or "0".
We have a virtual function call showCard(), which is used to show the attributes of each card. 
This function changes depending on the type of child class, as it only shows the essential 
information for each type of card:
- Only type for WildCard and Wild4Card.
- Only color and type for SkipCard, RevCard and Draw2Card.
- Only color and number for NumCard.
We have a function setPlay() to count the plays that have been made.
We have a friend fucntion called move() which determines if you can use a specific card. For 
that, it takes as attributes two cards (in the game they will be the last card on the table and the 
card from your hand that wants to check). It compares both cards and determines if you can 
use that card. If the card is valid, it returns 1, if it is not, it returns 0.
When we create a card (an object), we must use the constructor to specify the type 
("Number", "Skip", "Draw Two", "Reverse", "Wild" or "Wild Draw Four"), the number (0-9), 
and the color ("Red", "Yellow", "Green" or "Blue").

-------------------------------

## Rules:
The game is a drinking game caled 98.
The rules are as follow:
The objective of the game is to get the other player to overpass 98 and you to avoid to pass 98.
The cards are as follow:
1-7 Number Cards: Add its value to the sum of the play.
"Substract Ten": When play discards this one, the sum is substracted 10.
"Reverse": Changes the turn of the actual player.
"You Decide": Changes the sum to the number you decide to be.
When a player gets to 10, 20, 30, 40, 50, 60, 70, 80 and 90, the other player drinks x/10 
swallows of the drink.
When a player surpass 98, he has to drink a shot.
