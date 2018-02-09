// identification
// Hongseok Jang
// Lab 8, dealingCards.8a.cpp
// Editor(s) used: Sublime Text2
// Compiler(s) used: Xcode

#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cctype>

#include <iostream>
using std::cin;
using std::cout;
using std::ios;

#include <algorithm>
using std::swap;

#include <fstream>
using std::fstream;

void outputCard(int, int);

struct PlayingCard
{
  int value; // 2-10, 11=jack, 12=queen, 13=king, 14=Ace
  int suit; // 0=spade, 1=diamond, 2=heart, 3=club
};

int main()
{
  // identification
  cout << "Hongseok Jang\n\n";
  cout << "dealingCards.8a.cpp\n";
  cout << "Editor(s) used: Sublime Text2\n";
  cout << "Compiler(s) used: Xcode\n";
  cout << "File: " << __FILE__ << "\n";
  cout << "Compiled: " << __DATE__ << " at " << __TIME__ << "\n\n";
  
  srand(time(0));
  
  PlayingCard deck[52];
  
  // spades
  for (int i = 0; i < 13; i++)
  {
    deck[i].suit = 0;
    deck[i].value = i + 2;
  }
  
  // diamonds
  for (int i = 13; i < 26; i++)
  {
    deck[i].suit = 1;
    deck[i].value = i - 11;
  }
  
  // hearts
  for (int i = 26; i < 39; i++)
  {
    deck[i].suit = 2;
    deck[i].value = i - 24;
  }
  
  // clubs
  for (int i = 39; i < 52; i++)
  {
    deck[i].suit = 3;
    deck[i].value = i - 37;
  }
  
  for (int shuffle = 0; shuffle < 7; shuffle++)
    for (int i = 0; i < 52; i++)
      for(int j = i + 1; j < 52; j++)
        if(rand() % 2)
          swap(deck[i], deck[j]);
  
  PlayingCard hand[5];
  int card = 0;
  for (card = 0; card < 5; card++)
    hand[card] = deck[card];
  card = 5;
  
  fstream fin;
  fin.open("PlayingCard.dat", ios::binary|ios::in);
  if (fin.good())
  {
    fin.read(reinterpret_cast<char*>(&deck[0]), sizeof(deck));
    fin.read(reinterpret_cast<char*>(&hand[0]), sizeof(hand));
    fin.read(reinterpret_cast<char*>(&card), sizeof(int));
  }
  fin.close();

  char buf[10];
  while (true)
  {
    cout << "My hand: \n";
    for (int i = 0; i < 5; i++)
    {
      cout << i + 1 << ". ";
      outputCard(hand[i].value, hand[i].suit);
    }
    cout << "\n";
    if (card == 52) break;
    cout << "Choose a card to recycle or Q to quit: ";
    cin >> buf;
    if (tolower(buf[0]) == 'q') break;
    int recycleCard = atoi(buf);
    hand[recycleCard - 1] = deck[card];
    card++;
    cout << "\n";
  }
  fstream fout;
  fout.open("PlayingCard.dat", ios::binary|ios::out);
  fout.write(reinterpret_cast<char*>(&deck[0]), sizeof(deck));
  fout.write(reinterpret_cast<char*>(&hand[0]), sizeof(hand));
  fout.write(reinterpret_cast<char*>(&card), sizeof(int));
  fout.close();
}

void outputCard(int value, int suit)
{
  if (value == 2)
    cout << "two";
  else if (value == 3)
    cout << "three";
  else if (value == 4)
    cout << "four";
  else if (value == 5)
    cout << "five";
  else if (value == 6)
    cout << "six";
  else if (value == 7)
    cout << "seven";
  else if (value == 8)
    cout << "eight";
  else if (value == 9)
    cout << "nine";
  else if (value == 10)
    cout << "ten";
  else if (value == 11)
    cout << "Jack";
  else if (value == 12)
    cout << "Queen";
  else if (value == 13)
    cout << "King";
  else if (value == 14)
    cout << "Ace";
  
  cout << " of ";
  
  if (suit == 0)
    cout << "Spades";
  else if (suit == 1)
    cout << "Diamonds";
  else if (suit == 2)
    cout << "Hearts";
  else if (suit == 3)
    cout << "Clubs";
  cout << "\n";
}
