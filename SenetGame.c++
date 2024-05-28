#include<iostream>
#include<cstdlib>
#include<conio.h>
using namespace std;
class Senet{
	public:
		char Board[30];
		void Menu()
		{
			cout<<"\n   ----- SENET -----";
			cout<<"\n[1]----- PLAY  -----";
			cout<<"\n[2]----- RULES -----";
			cout<<"\n[3]----- EXIT  -----";
		
		}
		int Roll()
		{
			int score;
			score = rand() % 5 + 1;
			return score;
		}
		void HowToPlay(){
			cout<<"\nFollow the instructions: ";
			cout<<"\n[1] Senet is a Multiplayer Game. (2 Players)";
			cout<<"\n[2] There are 30 Squares on the Board.";
			cout<<"\n[3] Both players have 5, 5 pieces.";
			cout<<"\n[4] There are 5 Special Boxes:\n   a) HOUSE OF BEAUTY(26TH)\n   b)POWER OF LIFE(15TH)\n   c)HOUSE OF WATER(27TH)\n   d)HOUSE OF THREE SPIRITS(28TH)\n   e)HOUSE OF TWOS(29TH)";
			cout<<"\n[5] First one to get their all pieces off the board WINS!";
			cout<<"\nYou have to move like this:   \n------>\n<------\n------>";
		}
		
		int choice()
		{
			int choice;
			cout<<"\nEnter Your Choice: ";
			cin>>choice;
			return choice;
		}
		
		bool Error_Message()
		{
			cout<<"\nSomething Went Wrong :(\nGo To Menu?[Y/N] :)";
			char choice;
			cin>>choice;
			if(choice=='y' || choice =='Y' )
			return true;
			else false;
		}
		
		char Back()
		{
			cout<<"\nGo To Menu?[Y/N] :)";
			char choice;
			cin>>choice;
			return choice;
		}
     	void GoodBye()
		{
			cout<<"\nHave a Nice Day :)";
		}
};

class Player: public Senet{
	public:
	//Variables are Here..............!!!!!
	int choice;
	char select;
	//Variables are Here..............!!!!!	
	
	//Objects are HERE................!!!!
	Senet Game;

	string currentPlayer;
	//Objects are HERE................!!!!
	
		string name;
		int move;
		char mark;
		int count = 5;
		
		bool ifCheckpoint(int move, int roll, int player)
		{ 	Player Player[2], Play;
			int check = move+roll;
			if(check == 14 || check == 25 || check == 26 || check == 27 || check == 28)
			{
						
						return true;
			} else return false;
		}
		
		void play()
		{ 	Player Player[2], Play;
	
			 //If player wants to play:
			cout<<"\nEnter The Name of First Player: (X) ";
			cin>>Player[0].name;
			cout<<"\nEnter The Name of Second Player: (#) ";
			cin>> Player[1].name;
			Play.SetBoard('X', '#');
			//Setting Board for Player1 and Player2
			system("cls");
			Play.showBoard();
			//Starting of Game: 
			cout<<"\nStart? (Y/N)";
			cin>>select;
			if(select == 'Y' || select == 'y')
			{
				system("cls");
					int newCount = 0;
					int i = 0;
				while(Player[0].count > 0 || Player[1].count > 0)
				{
					system("cls");
					Play.showBoard();
					currentPlayer = Player[i].name;
					Roll:
					cout<<"\nEnter 'R' to Roll the sticks : ("<<currentPlayer<<"'s Turn)"<<endl;
					int roll;
					getch();
					roll = Play.Roll();
					cout<<"\nIts "<<roll<<" !";
					Move:
						int move;
					cout<<"\nEnter The Piece that you want to move: ("<<currentPlayer<<")"<<endl;
					cin>>move;
					if(Play.isValidMove(move, roll, i))
					{
					
					     if(!Play.ifCheckpoint(move, roll, i))
					     {
						 
						char temp = Play.Board[move+roll];
						Play.Board[move+roll] = Play.Board[move];
						Play.Board[move] = temp; } 
						else {
							Play.Board[move+roll] = Play.Board[move];
							if(move+roll != 26)
						Play.Board[move] = 'F';
						else Play.Board[26] = 'W'; 
						}
						newCount++;
					if(newCount % 2 == 0)
						{
							i = 0;
						} else {
							i = 1;
						}
					} 
				 else {
					cout<<"\nInvalid Move";
					goto Move;					//return 0;  //This was to check isValid function working or not.
				}}
				
				
				
			} else if(select == 'N' || select == 'n')
				{
					Play.Menu();
				}
			
			
		}
		void SetBoard(char mark1, char mark2)
		{
				//Setting Board
				int k= 1;
		for(int i = 0; i<10; i = i+2)
			{
				Board[i] = mark1;
				Board[k] = mark2;
				k=k+2;		
		}
		for(int i = 10; i<30; i++)
		{
			if(i == 14 || i == 25)
			  Board[i] = 'S';
			  else if(i == 26)
			 	 Board[i] = 'W';
			 	  else if(i == 27)
			 	   Board[i] = '3';
			 	   else if(i==28)
			 	   Board[i] = '2';
			 	    else 
			 	    Board[i] = 'F';
		}
	}
		bool isValidMove(int position, int score, int player)
		{
			bool  checkTrue[7]= {true , true, true, true, true, true, true};
			//Setting Player's Mark and opponent's Mark
			 char OpponentsMark, PlayersMark;
				if (player == 0){
					
			 	OpponentsMark = '#'; 
			 	PlayersMark = 'X'; 
				 }
			else {
				
				PlayersMark = '#';
				OpponentsMark = 'X';
		}
			//If player is trying to move opponent's piece
			if(Board[position] != PlayersMark)
	    	checkTrue[6] = false;
				
		
			//Player can't replace opponent when they are at checkpoints (15 and 25)
			if(position + score == 14 || position + score == 25)
			{
				int checkPosition = position + score;
				
				if(Board[checkPosition] == OpponentsMark)
					checkTrue[0] = false;

			}
				//Player can't replace its own Piece
				    //    F           equal to #/X         
				if(Board[position + score]== PlayersMark)
				{
					checkTrue[1] = false;
				} 
				//Player moves from 26th to 15th (House of water to power of Life)
				if (position + score == 26)
				{
					if(Board[14] == OpponentsMark && Board[14] == PlayersMark)
					{
				    	//Board[15] =  Board[position];
					    //checkTrue[2] = true;
					    checkTrue[2] = false;
					 }
				}
				
				//if player is at pos 27, player need 3 score to move on	
				if(position == 27 )
				{
					if (score != 3)
					checkTrue[3] = false;
				} 
				
				//if player is at pos 28, player need 2 score to move on	
				if(position == 28)
				{
					if(score !=2)
					checkTrue[4] = false;
				} 
				//if player is at pos 29, player need 1 score to move on	
				if(position == 29)
				{
					if(score !=1)
					checkTrue[5] = false;
				} 
			
				if(checkTrue[0]  && checkTrue[1] && checkTrue[2] && checkTrue[3] && checkTrue[4] && checkTrue[5] && checkTrue[6])
				{
					return true;
				} else 
				{
				return false; }
				
		}
		void showBoard()
		{
		
		for(int i = 0; i<30; i++)
		{
			
			if(Board[i] != 'X' && Board[i] != '#'){
				if (i == 14 )
           		 Board[i] = 'S';
        		else if (i == 25)
            	 Board[i] = 'S';
        		else if (i == 26)
            	 Board[i] = 'W';
        		else if (i == 27)
            	 Board[i] = '3';
        		else if (i == 28)
             	 Board[i] = '2';
			}
		}
			int k = 19;
		for(int i = 0; i<30; i++)
			{
				
				if(i==10 || i == 20)
				 cout<<endl;
				if(i>9 && i<20)
				{
				  cout<<Board[k]<<" ";
				  k--;	
				} else
				 
				 cout<<Board[i]<<" ";
			}	
		}	
			
};


int main()
{
	//Variables are Here..............!!!!!
	int choice;
	char select;
	
	//Variables are Here..............!!!!!
	
	//Objects are HERE................!!!!
	Senet Game;
	Player Player[2], Play;
	string currentPlayer;
	//Objects are HERE................!!!!
	
	//Menu:
	menu:
	system("cls");
	Game.Menu();
	choice = Game.choice();
	//Cases:
	switch(choice)
	{
		case 1:
			Play.play();
			break;
		case 2: //If player want to see HowToPlay
			Game.HowToPlay();
			select = Game.Back();
			switch(select)
			{
				case 'y'||'Y':
					goto menu;
					break;
				default :
					system("cls");
					Game.GoodBye();
					return 0;
			}
			break;
		case 3: //If Player Wants to Exit
			system("cls");
			Game.GoodBye();
			break;
		default:
			select = Game.Error_Message();
			switch(select)
			{
				case 'y'||'Y':
					goto menu;
					break;
				default :
					system("cls");
					Game.GoodBye();
					return 0;
			}
			
	}
	return 0;
}
