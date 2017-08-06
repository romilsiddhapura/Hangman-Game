
//#include <iostream>
#include <String.h>
#include <dos.h>
//#include <iostream.h>
#include <ctype.h>
#include <fstream.h>
#include <conio.h>
#include <graphics.h>
#include <stdlib.h>

#define MAX_WORD_SIZE 15
#define MAX_WORDS 500

int arrX1[10],arrY1[5];
int characterName;
typedef char String[MAX_WORD_SIZE]; // take a char type with 15 chars
String Words[MAX_WORDS - 1];  // this array contain  our words
int count;
//int _AX;

//Mouse handling /////////////////////
void initialize( ){
	_AX=0;
	geninterrupt(0x33);
}

void showPointer( ){
	_AX=1;
	geninterrupt(0x33);
}

void hideMouse( ){
	_AX=2;
	geninterrupt(0x33);
}

int showStatus(int *a,int *b ){
		_AX=3;
		geninterrupt(0x33);
		*a=_CX;
		*b=_DX;
		return _BX;
}
//Graphics front page ///////////////////////////

void front () {
	int x1=285 , y1=200 , x2=340, y2=285;
	for (int i=0; i<95; i++) {
		setcolor(9);
		cleardevice ();
		setlinestyle(SOLID_LINE,1,THICK_WIDTH);
		rectangle(x1,y1,x2,y2);
		rectangle(x1+5,y1+5,x2-5,y2-5);
		delay(40);

		x1-=3;
		y1-=2;
		x2+=3;
		y2+=2;
	}
}
//show name /////////////////
void name () {
	settextstyle(7,0,8);
	setcolor(YELLOW);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	outtextxy(100,60,"Hangman");
	settextstyle(7,0,4);
	setcolor(15);
	outtextxy(230,150,"Designed by");
	setfillstyle(1,6);
	bar(10,440,615,465);
	settextstyle(2,0,7);
	setcolor(15);
	outtextxy(300,440,"Press any key to Continue");

	do {
		for(int i=1; i< 16; i++){
			setcolor(i);
			settextstyle(7,0,4);
			outtextxy(70,200,"15CP032 ROMIL SIDDHAPURA");
			setcolor(i+1);
			outtextxy(70,250,"15CP033 HIREN KAVAIYA");
			setcolor(i+2);
			outtextxy(70,300,"15CP018 KEVAL AHALPARA");
			delay(50);
	    }
	}while(!kbhit());
}

//Load game /////////////////////////////////////

void loadGame() {
	setcolor(9);
	setlinestyle(0,1,THICK_WIDTH);
	rectangle(5,10,615,475);
	rectangle(10,15,610,470);
	setcolor(15);
	settextstyle(2,0,8);
	outtextxy(20,40,"Loading Game ... ");
	setcolor(10);
	rectangle(100,120,520,180);
	outtextxy(155,80,"Please wait... ");
	rectangle(150,135,480,165);
	for(int i=3; i<328; i++){
		setcolor(14);
		line(150+i,138,150+i,162);
		delay(15);
	}
}
//Last page //////////////////////
void LastPage () {
		hideMouse();
		setfillstyle(1,BLACK);
		bar(0,0,780,600);
	       //	setcolor(8);
		settextstyle(3,0,8);
		setcolor(9);
		setlinestyle(0,1,THICK_WIDTH);
		rectangle(5,10,615,475);
		rectangle(10,15,610,470);
		setcolor(14);
		outtextxy(100,200,"Thank You");
		setcolor(WHITE);
		settextstyle(3,0,3);
		outtextxy(300,400,"for Playing this Game");
		setcolor(WHITE);
		settextstyle(5,0,3);
	     //	outtextxy(50,200,"Designed By : ");
	     //	setcolor(2);
	     //	settextstyle(3,0,3);
	     //	outtextxy(150,250,"15CP032 Romil Siddhapura");
	     //	outtextxy(150,300,"15CP033 Hiren Kavaiya");
	     //	outtextxy(150,350,"15CP018 Keval Ahalpara");
		getch();
}
//text show ///////////////////////////////
void textshow(char a[50],int x,int y,int fontSize=1, char color=2) {
	moveto(x,y);
	settextstyle(7,HORIZ_DIR,fontSize);
	setcolor(color);
	settextjustify(LEFT_TEXT,TOP_TEXT);
	setusercharsize(1,1,1,1);
	outtext(a);
}

//drawing ///////////////////////////

void Drawings(int state) {
		switch (state) {
		case 1:
			setcolor(2);
			setlinestyle(SOLID_LINE,1,THICK_WIDTH);
			line(400,300,550,300);
			break;
		case 2:
			setcolor(2);
			setlinestyle(SOLID_LINE, 1,THICK_WIDTH);
			line (400,100,400,300);
			break;
		case 3:
			setcolor(2);
			setlinestyle(SOLID_LINE, 1,THICK_WIDTH);
			line (400,100,480,100);
			break;
		case 4:
			setcolor(2);
			setlinestyle(SOLID_LINE, 1,THICK_WIDTH);
			line (480,100,480,150);
			circle(480,170,20);
			break;
		case 5:
			setcolor(2);
			setlinestyle(SOLID_LINE, 1,THICK_WIDTH);
			line (480,190,480,250);
			break;
		case 6:
			setcolor(2);
			setlinestyle(SOLID_LINE, 1,THICK_WIDTH);
			line (480,200,445,215);
			line (480,200,515,215);
			break;
		case 7:
			setcolor(2);
			setlinestyle(SOLID_LINE, 1,THICK_WIDTH);
			line (480,250,445,275);
			line (480,250,515,275);
			textshow("You are dead",353,50,4,2);
			break;
	}
}

//Games Rules //////////////////////////

void Rules () {
	cleardevice();
	textshow("Rules for Playing Game",100,40,1,2);
	line(100,85,500,85);
	line(100,90,500,90);
	setcolor(15);
	settextstyle(2,0,6);
	outtextxy(80,120,"1.   First click on the button using mouse to enter");
	outtextxy(123,140," an alphabet. ");
	outtextxy(80,180,"2.   If the alphabet is right it will appear on the ");
	outtextxy(127,200,"basis provided for the Word.");
	outtextxy(80,240,"3.   If the alphabet is wrong than it will make the ");
	outtextxy(125,260,"Gallows in the rectangle.");
	outtextxy(80,300,"4.   The seven chances will be provided for guess.");
	outtextxy(80,340,"5.   If the guess is correct than 'CORRECT' message,");
	outtextxy(125,360,"will appear on the screen.");
	outtextxy(80,400,"6.   If the guess is incorrect than 'You Loss' message,");
	outtextxy(125,420,"will appear on the screen and you will be hanged.");
	setcolor(9);
	setlinestyle(0,1,THICK_WIDTH);
	rectangle(5,10,615,475);
	rectangle(10,15,610,470);
	getch();
	cleardevice();
}

////////////////////Class Character and button handler///////
class Character {
	private:
		int left,top;
		int bottom,right;
	public:
		Character(){
		}
		Character(int,int,int,int);
		void createButton(char*,int);
		void initializeGraph();
		void game();
		void buttonPressed(int);
		void buttonUnpressed(int);
		char characterHandler(int[],int[]);
		void keyboard ();
		void fileLoad();
		void runGame();

};

void Character::initializeGraph(){
	int a = DETECT,b;
	initgraph(&a, &b, "C:\\TURBOC3\\BGI");
}

Character::Character(int x,int y,int width, int length){
	 left=x;
	 top=y;
	 right=x+width;
	 bottom=top+length;
}
// Key Board ////////////////////
void Character::keyboard() {
	Character *character[26];
	char* characterNames[]={" A"," J"," S"," B"," K"," T"," C",
		" L"," U"," D"," M"," V"," E"," N"," W"," F"," O"," X" ," G",
		" P"," Y"," H"," Q"," Z", " I" ," R"," "};

	for(int i=0; i<3; i++){
		character[i]=new Character(25,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i]->createButton(characterNames[i],7);
	}

	for(i=0; i<3; i++){
		character[i+3]=new Character(85,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+3]->createButton(characterNames[i+3],7);
	}

	for(i=0; i<3; i++){
		character[i+6]=new Character(145,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+6]->createButton(characterNames[i+6],7);
	}

	for(i=0; i<3; i++){
		character[i+9]=new Character(205,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+9]->createButton(characterNames[i+9],7);
	}

	for(i=0; i<3; i++){
		character[i+12]=new Character(265,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+12]->createButton(characterNames[i+12],7);
	}

	for(i=0; i<3; i++){
		character[i+15]=new Character(325,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+15]->createButton(characterNames[i+15],7);
	}

	for(i=0; i<3; i++){
		character[i+18]=new Character(385,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+18]->createButton(characterNames[i+18],7);
	}

	for(i=0; i<3; i++){
		character[i+21]=new Character(445,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+21]->createButton(characterNames[i+21],7);
	}
	for(i=0; i<2; i++){
		character[i+24]=new Character(505,340+i*40,45,30);
		settextstyle(1,0,4);
		character[i+24]->createButton(characterNames[i+24],7);
	}
	arrX1[0]=0;
	arrX1[1]=25;
	arrX1[2]=85;
	arrX1[3]=145;
	arrX1[4]=205;
	arrX1[5]=265;
	arrX1[6]=325;
	arrX1[7]=385;
	arrX1[8]=445;
	arrX1[9]=505;
	arrY1[0]=0;
	arrY1[1]=340;
	arrY1[2]=380;
	arrY1[3]=420;
	arrY1[4]=460;

}

void Character::createButton(char * msg,int color){
	setfillstyle(1,color);
	bar(left,top,right-1,bottom-1);
	setcolor(0);
	outtextxy(left,top-4,msg);
	buttonUnpressed(BLACK);
	buttonPressed(WHITE);
}

void Character::buttonUnpressed(int color){
	setcolor(color);
	setlinestyle(SOLID_LINE,1,1);
	line(left,bottom,right-1,bottom);
	line(right,bottom-1,right,top);
}

void Character::buttonPressed(int color){
	setlinestyle(SOLID_LINE,1,1);
	setcolor(color);
	line(left,top,right-1,top);
	line(left,top,left,bottom-1);
}

//KEY BOARD ///////////////////////

char Character::characterHandler(int arrX[],int arrY[]){
	  int x,y,b;
	  int col=0;
	  int bool=0,bool2=0;
	  char buttonN[]={' ','A','J','S','B','K','T','C',
		'L','U','D','M','V','E','N','W','F','O','X' ,'G',
		'P','Y','H','Q','Z', 'I' ,'R'};

		b=showStatus(&x,&y);
		if(b==1 && x>=25 && x<getmaxx()-90 && y>=340 && y<getmaxy()-30){

			if(x>arrX[1] && x<arrX[1]+45){
				left=arrX[1];
				right=arrX[1]+45;
				col=1;
				bool=1;
			}
			else if(x>arrX[2] && x<arrX[2]+45){
				left=arrX[2];
				right=arrX[2]+45;
				col=4;
				bool=1;
			}
			else if(x>arrX[3] && x<arrX[3]+45){
				left=arrX[3];
				right=arrX[3]+45;
				col=7;
				bool=1;
			}
			else if(x>arrX[4] && x<arrX[4]+45){
				left=arrX[4];
				right=arrX[4]+45;
				col=10;
				bool=1;
			}
			else if(x>arrX[5] && x<arrX[5]+45){
				left=arrX[5];
				right=arrX[5]+45;
				col=13;
				bool=1;
			}
			else if(x>arrX[6] && x<arrX[6]+45){
				left=arrX[6];
				right=arrX[6]+45;
				col=16;
				bool=1;
			}
			else if(x>arrX[7] && x<arrX[7]+45){
				left=arrX[7];
				right=arrX[7]+45;
				col=19;
				bool=1;
			}

			else if(x>arrX[8] && x<arrX[8]+45){
				left=arrX[8];
				right=arrX[8]+45;
				col=22;
				bool=1;
			}
			else if(x>arrX[9] && x<arrX[9]+45){
				left=arrX[9];
				right=arrX[9]+45;
				col=25;
				bool=1;
			}

			if(y>arrY[1] && y<arrY[1]+30){
				top=arrY[1];
				bottom=arrY[1]+30;
				col+=0;
				bool2=1;
			}
			else if(y>arrY[2] && y<arrY[2]+30){
				top=arrY[2];
				bottom=arrY[2]+30;
				col+=1;
				bool2=1;
			}
			else if(y>arrY[3] && y<arrY[3]+30){
				top=arrY[3];
				bottom=arrY[3]+30;
				col+=2;
				bool2=1;
			}
			else if(y>arrY[4] && y<arrY[4]+30){
				top=arrY[4];
				bottom=arrY[4]+30;
				col+=3;
				bool2=1;
			}

			if(bool==1 && bool2==1){
				buttonPressed(BLACK);   // when button pressed make rectangle white & black
				buttonUnpressed(WHITE);
			}

		}
		else{
			buttonUnpressed(BLACK);
			buttonPressed(WHITE);
			if(bool==1 && bool2==1){
				bool=0;
				bool2=0;
			}
		}
	showPointer();
	return buttonN[col];

}
//Load file Words.dat for words ///////////////////////////
void Character::fileLoad() {
	count =0;
	char ch;
	ifstream infile;		      // create input file
	infile.open ("words.dat", ios::in | ios::binary); 	// open the file default or in binary form

	while((ch=infile.peek()) != EOF) {
		infile>>Words[count++];
	}
	count--;
	infile.close ();
}

//Game //////////////////////////////

void Character::runGame () {
	int Word;
	int WordSize;
	int xPosition=20; int yPosition=50;
	int subscriptLines=0;
	char wordToGuess[MAX_WORD_SIZE];
	char copy[MAX_WORD_SIZE];
	char alphabet;
	int index=0;
	int faults=0;
	int alpha[27];
	for(int i=0; i<27; i++)
	alpha[i]=0;

	srand((unsigned)time(NULL));
	Word = rand() % count;
	strcpy (copy,Words[Word]);
	WordSize = strlen(Words[Word]);

	for (subscriptLines=0; subscriptLines < WordSize ; subscriptLines++) {
		copy[subscriptLines]=toupper(copy[subscriptLines]);
		if (copy[subscriptLines]!=' ')
			textshow("_",xPosition+5+(subscriptLines*27),yPosition+15,2,2);

	}
	copy[subscriptLines] ='\0';

	int count =0;
	int alphaIndex=0;
	char arr[2];
	strcpy(arr," ");
	keyboard();
	do {
		alphabet =characterHandler(arrX1,arrY1); // get the alphabet on button pressed
			arr[0]=alphabet;
			if (alpha[(int)alphabet-65]==0) {
				setcolor(15);
				settextstyle(4,0,3);
				outtextxy(30,130,"Alphabets Used");
				textshow(arr,15+(count*25),160,1,9);
				count++;
			} // if
			alphaIndex=0;
			arr[0]=alphabet;
			if(alpha[(int)alphabet-65]==0) {
				alpha[(int)alphabet-65]=1;
				for (subscriptLines=0; subscriptLines < WordSize ; subscriptLines++) {
					if(copy[subscriptLines] == alphabet) {
						alphaIndex++;
					} //if
				} // for

				for (subscriptLines=0; subscriptLines < WordSize ; subscriptLines++) {
					if(copy[subscriptLines]==alphabet) {
						textshow(arr,xPosition+5+(subscriptLines*27),yPosition+10,1,2);
						index++;
					}
					else if (alphaIndex==0)
						faults++;
				} // for
			} // if

			if (faults%WordSize==0)
				Drawings(faults/WordSize);
			if ((faults/WordSize)==7)
					goto lose;

	}while(WordSize>index); //do while end
	textshow("You Survived",354,50,8);
	setlinestyle(1,1,THICK_WIDTH);
	rectangle(40,245,275,315);
	do {
		for(int i=1; i< 16; i++){
			setcolor(i);
			settextstyle(7,0,7);
			outtextxy(50,240,"Correct");
			delay(50);
	    }
	}while(!kbhit());
	goto end;

	lose:
		setlinestyle(4,1,THICK_WIDTH);
		rectangle(40,210,240,255);
		do {
			for(int i=1; i< 16; i++){
				setcolor(i);
				settextstyle(1,0,5);
				outtextxy(50,205,"You Lose");
				delay(50);
		    }
		    textshow("The Answer is",25,260,1,2);
		    textshow(copy,70,290,3,4);
		}while(!kbhit());
	end:
		getch();
}

void Character::game() {
char ch;
	do {
		initialize();
		cleardevice();
		fileLoad();
		setcolor(4);
		setlinestyle(0,1,THICK_WIDTH);
		rectangle(350,50,580,325);
		setcolor(9);
		setlinestyle(0,1,THICK_WIDTH);
		rectangle(5,10,615,475);
		rectangle(10,15,610,470);
		runGame();
		cleardevice();
		hideMouse();
		char a[2];
		strcpy(a," ");
		setcolor(9);
		setlinestyle(0,1,THICK_WIDTH);
		rectangle(5,10,615,475);
		rectangle(10,15,610,470);
		textshow("Want to Play again ",60,100,6,15);
		textshow("YES / NO ",150,150,5,2);
		ch=getch();
		ch=toupper(ch);
		a[0]=ch;
		textshow(a,200,200,5,9);
		delay(1000);
	}while(ch=='Y');
}

//MAIN////////////////////////////////////

void main(){
	clrscr();
	Character b;
	char ch;
	b.initializeGraph();
	front();
	name();
	getch();
	Rules();
	cleardevice();
	closegraph();
	b.initializeGraph();
	initialize();
	loadGame();
	b.game();
	hideMouse();
	LastPage();
	b.initializeGraph();
	hideMouse();
	exit(0);
	getch();
}

