#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <time.h>
#include <string>
#include <cstring>
#include <sstream>
#include <Windows.h>

using namespace sf;
using namespace std;
#define MAX_NUMBER_OF_ITEMS 2

int nextFrame = 0;
int  dise;
bool gameover = false;

struct Levels_u
{
	Font font;
	Text text[3];
}l;
struct players {
	string NameOfplayer;
	int score = 1;
} Number[5];

Texture dice, dice1, dice2, dice3, dice4, dice5, dice6, p1, p2, p3, p4, p6, p7, p8, p9, p10;
Sprite imdice, imdice1, imdice2, imdice3, imdice4, imdice5, imdice6, ip1, ip2, ip3, ip4, ip6, ip7, ip8, ip9, ip10;

RenderWindow window(VideoMode(1000, 700), "SNAKE AND LADDER", Style::Close);
int NumberOfPlayers;

SoundBuffer buffer;
Sound sound;
SoundBuffer befo;
Sound soun;

void ONE_PLAYER_Hard();
void ONE_PLAYER_Easy();
void Draw();
void Dice2();
void Dice3();
void Dice4();
void NO_OF_PLAYERS();
void Levels();
void Menu_u();
void scoreBoard2();
void scoreBoard3();
void scoreBoard4();
void scoreBoard_Comp(int& a);
void convert(int n, players Number[], string s[]);
void Draw_Hard();
int Playerturn = -1;
int	Ladder1 = 1 + rand() % 5;
int Ladder2 = 6 + rand() % 5;
int Ladder3 = 20 + rand() % 10;
int Ladder4 = 45 + rand() % 5;
int Ladder5 = 76 + rand() % 5;
int Snake1 = 21 + rand() % 10;
int Snake2 = 41 + rand() % 10;
int Snake3 = 65 + rand() % 5;
int Snake4 = 75 + rand() % 5;
int Snake5 = 95 + rand() % 5;

Text text, text2, text3;
struct Menu
{
	Font font;
	Text text[MAX_NUMBER_OF_ITEMS];
}m;
int main() {

	while (window.isOpen())
	{

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == event.Closed)
			{
				window.close();
			}

			if (event.type == event.MouseButtonPressed) {
				if (event.mouseButton.x >= m.text[0].getPosition().x && event.mouseButton.y >= m.text[0].getPosition().y)
				{
					nextFrame = 1;
				}
				if (event.mouseButton.x >= m.text[1].getPosition().x && event.mouseButton.y >= m.text[1].getPosition().y)
				{
					nextFrame = 2;
				}

			}
		}
		window.clear(Color::White);

		Menu_u();

		if (nextFrame != 0)
			window.clear();

		if (nextFrame == 1) {
			NO_OF_PLAYERS();
		}
		else if (nextFrame == 2) {
			Levels();
		}
		else if (nextFrame == 3) {
			Draw();
			ONE_PLAYER_Easy();
		}
		else if (nextFrame == 4) {
			Draw_Hard();
			ONE_PLAYER_Hard();
		}
		else if (nextFrame == 6) {
			Draw();
			Dice2();
		}
		else if (nextFrame == 7) {
			Draw();
			Dice3();
		}
		else if (nextFrame == 8) {
			Draw();
			Dice4();
		}
		window.display();
	}
	system("pause");
	return 0;
}
void Menu_u() {

	Texture background;
	background.loadFromFile("snake.jpg");
	Sprite backgroundSprite(background);
	backgroundSprite.setScale(1.12, 1.5);
	m.font.loadFromFile("BLKCHCRY.ttf");
	window.draw(backgroundSprite);
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++) {
		m.text[i].setFont(m.font);
		m.text[i].setFillColor(sf::Color::Red);
		m.text[0].setString("Play with Your Friend");
		m.text[i].setCharacterSize(50);
		m.text[0].setPosition(300, 480);
		m.text[1].setString("Play With Your PC");
		m.text[1].setCharacterSize(50);
		m.text[1].setPosition(320, 590);
		window.draw(m.text[i]);
	}
}
void Levels() {
	Texture background2;
	background2.loadFromFile("wood1.jpg");
	Sprite b2(background2);
	b2.setScale(0.78, 0.55);

	l.font.loadFromFile("waltograph42.ttf");
	window.draw(b2);
	for (int i = 0; i < 3; i++) {
		l.text[i].setFont(m.font);
		l.text[i].setFillColor(sf::Color::Red);
		l.text[0].setString("Choose Level : ");
		l.text[1].setString("Normal level");
		l.text[2].setString("Hard level");
		l.text[i].setCharacterSize(70);
		l.text[0].setPosition(175, 150);
		l.text[1].setPosition(285, 220);
		l.text[2].setPosition(295, 420);
		window.draw(l.text[i]);
	}
	Event evo;
	while (window.pollEvent(evo)) {
		if (evo.type == evo.MouseButtonPressed) {
			if (evo.mouseButton.x >= l.text[1].getPosition().x && evo.mouseButton.y >= l.text[1].getPosition().y)
			{
				nextFrame = 3;
			}
			if (evo.mouseButton.x >= l.text[2].getPosition().x && evo.mouseButton.y >= l.text[2].getPosition().y) {
				nextFrame = 4;
			}
		}
	}
}
void NO_OF_PLAYERS() {

	Texture background2;
	background2.loadFromFile("wood1.jpg");
	Sprite b2(background2);
	b2.setScale(0.78, 0.55);

	Font font;
	font.loadFromFile("waltograph42.ttf");

	text.setFont(font);
	text.setString("[2] Players");
	text.setCharacterSize(80);
	text.setFillColor(Color::Red);
	text.setStyle(Text::Bold);
	text.setPosition(350, 200);

	text2.setFont(font);
	text2.setString("[3] Players");
	text2.setCharacterSize(80);
	text2.setFillColor(Color::Red);
	text2.setStyle(Text::Bold);
	text2.setPosition(350, 300);

	text3.setFont(font);
	text3.setString("[4] Players");
	text3.setCharacterSize(80);
	text3.setFillColor(Color::Red);
	text3.setStyle(Text::Bold);
	text3.setPosition(350, 400);

	Event evon;
	while (window.pollEvent(evon)) {
		if (evon.type == evon.MouseButtonPressed) {
			if (evon.mouseButton.x >= text.getPosition().x && evon.mouseButton.y >= text.getPosition().y)
			{
				nextFrame = 6;
			}
			if (evon.mouseButton.x >= text2.getPosition().x && evon.mouseButton.y >= text2.getPosition().y) {
				nextFrame = 7;
			}
			if (evon.mouseButton.x >= text3.getPosition().x && evon.mouseButton.y >= text3.getPosition().y) {
				nextFrame = 8;
			}
		}
	}
	window.draw(b2);
	window.draw(text);
	window.draw(text2);
	window.draw(text3);
}
void Draw()
{
	srand(time(0));

	int w = 70;
	int sgrid[10][10];

	Texture board;;
	board.loadFromFile("block.jpg");
	Sprite s(board);
	s.setScale(0.8, 0.8);
	Texture ladders[5];
	Sprite laddersSpirit[5];
	for (int i = 0; i < 5; i++) {
		String lad = to_string(i + 1);
		ladders[i].loadFromFile("L" + lad + ".png");
		laddersSpirit[i].setTexture(ladders[i]);
		laddersSpirit[i].setScale(0.1, 0.08);
	}
	Texture snakes[5];
	Sprite snakesSpirit[5];
	for (int i = 0; i < 5; i++) {
		String sn = to_string(i + 1);
		snakes[i].loadFromFile("S" + sn + "Head.png");
		snakesSpirit[i].setTexture(snakes[i]);
		snakesSpirit[i].setScale(0.09, 0.09);
	}
	Texture snakesTails[5];
	Sprite snakesT[5];
	for (int i = 0; i < 5; i++) {
		String snt = to_string(i + 1);
		snakesTails[i].loadFromFile("S" + snt + "Tail.png");
		snakesT[i].setTexture(snakesTails[i]);
		snakesT[i].setScale(0.07, 0.07);
	}
	Text text;
	Font font;
	font.loadFromFile("BLKCHCRY.ttf");
	text.setFont(font);
	window.clear(Color::White);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			s.setScale(0.993, 0.9928);
			s.setTextureRect(IntRect(sgrid[i][j] * 0, 0, w, w));
			s.setPosition(i*w, j*w);
			window.draw(s);
		}
	}
	int arr[10][10];
	int x = 100, temp = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 != 0)
		{
			temp = x - 9;
			x -= 10;
		}
		for (int j = 0; j < 10; j++)
		{
			if (i % 2 != 0)
			{
				arr[i][j] = temp;
				temp++;
			}
			else
			{
				arr[i][j] = x;
				x--;
			}
			text.setFillColor(Color::White);
			String str = to_string(arr[i][j]);
			text.setString(str);
			text.setCharacterSize(30);
			text.setPosition(w * j + 15, w * i + 15);
			window.draw(text);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == Ladder1) {
				laddersSpirit[0].setPosition(w * j + 5, w * i + 5);
				window.draw(laddersSpirit[0]);
			}
			else if (arr[i][j] == Ladder2) {
				laddersSpirit[1].setPosition(w * j + 7, w * i + 7);
				window.draw(laddersSpirit[1]);
			}
			else if (arr[i][j] == Ladder3) {
				laddersSpirit[2].setPosition(w * j + 12, w * i + 10);
				window.draw(laddersSpirit[2]);
			}
			else if (arr[i][j] == Ladder4) {
				laddersSpirit[3].setPosition(w * j + 15, w * i + 8);
				window.draw(laddersSpirit[3]);
			}
			else if (arr[i][j] == Ladder5) {
				laddersSpirit[4].setPosition(w * j + 10, w * i + 7);
				window.draw(laddersSpirit[4]);
			}
			else if (arr[i][j] == Snake1) {
				snakesSpirit[0].setScale(0.15, 0.15);
				snakesSpirit[0].setPosition(w * j, w * i + 5);
				window.draw(snakesSpirit[0]);
			}
			else if (arr[i][j] == Snake2) {
				snakesSpirit[1].setPosition(w * j + 4, w * i + 5);
				window.draw(snakesSpirit[1]);
			}
			else if (arr[i][j] == Snake3) {
				snakesSpirit[2].setScale(0.15, 0.1);
				snakesSpirit[2].setPosition(w * j + 3, w * i + 5);
				window.draw(snakesSpirit[2]);
			}
			else if (arr[i][j] == Snake4) {
				snakesSpirit[3].setPosition(w * j, w * i + 8);
				window.draw(snakesSpirit[3]);
			}
			else if (arr[i][j] == Snake5) {
				snakesSpirit[4].setPosition(w * j, w * i + 8);
				window.draw(snakesSpirit[4]);
			}
			else if (arr[i][j] == 37) {

				laddersSpirit[0].setPosition(w * j + 5, w * i + 5);
				window.draw(laddersSpirit[0]);
			}
			else if (arr[i][j] == 30) {
				laddersSpirit[1].setPosition(w * j + 7, w * i + 7);
				window.draw(laddersSpirit[1]);
			}
			else if (arr[i][j] == 85) {
				laddersSpirit[2].setPosition(w * j + 12, w * i + 10);
				window.draw(laddersSpirit[2]);
			}
			else if (arr[i][j] == 72) {
				laddersSpirit[3].setPosition(w * j + 15, w * i + 8);
				window.draw(laddersSpirit[3]);
			}
			else  if (arr[i][j] == 100) {
				laddersSpirit[4].setPosition(w * j + 10, w * i + 7);
				window.draw(laddersSpirit[4]);
			}
			else if (arr[i][j] == 4) {
				snakesT[0].setScale(0.12, 0.12);
				snakesT[0].setPosition(w * j - 5, w * i + 20);
				window.draw(snakesT[0]);
			}
			else if (arr[i][j] == 22) {

				snakesT[1].setPosition(w * j - 10, w * i + 20);
				window.draw(snakesT[1]);
			}
			else if (arr[i][j] == 32) {

				snakesT[2].setPosition(w * j - 9, w * i + 25);
				window.draw(snakesT[2]);
			}
			else if (arr[i][j] == 13) {
				snakesT[3].setPosition(w * j, w * i + 25);
				window.draw(snakesT[3]);
			}
			else if (arr[i][j] == 64) {
				snakesT[4].setPosition(w * j, w * i + 20);
				window.draw(snakesT[4]);
			}
		}
	}
}
void Draw_Hard()
{

	srand(time(0));
	int w = 70;
	int sgrid[10][10];

	Texture board;;
	board.loadFromFile("block.jpg");
	Sprite s(board);
	s.setScale(0.8, 0.8);
	Texture ladders[5];
	Sprite laddersSpirit[5];
	for (int i = 0; i < 5; i++) {
		String lad = to_string(i + 1);
		ladders[i].loadFromFile("L" + lad + ".png");
		laddersSpirit[i].setTexture(ladders[i]);
		laddersSpirit[i].setScale(0.1, 0.08);
	}
	Texture snakes[5];
	Sprite snakesSpirit[5];
	for (int i = 0; i < 5; i++) {
		String sn = to_string(i + 1);
		snakes[i].loadFromFile("S" + sn + "Head.png");
		snakesSpirit[i].setTexture(snakes[i]);
		snakesSpirit[i].setScale(0.09, 0.09);
	}
	Texture snakesTails[5];
	Sprite snakesT[5];
	for (int i = 0; i < 5; i++) {
		String snt = to_string(i + 1);
		snakesTails[i].loadFromFile("S" + snt + "Tail.png");
		snakesT[i].setTexture(snakesTails[i]);
		snakesT[i].setScale(0.07, 0.07);
	}
	Text text;
	Font font;
	font.loadFromFile("BLKCHCRY.ttf");
	text.setFont(font);
	window.clear(Color::White);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
		{
			s.setScale(0.993, 0.9928);
			s.setTextureRect(IntRect(sgrid[i][j] * 0, 0, w, w));
			s.setPosition(i*w, j*w);
			window.draw(s);
		}

		Texture bomb;
		bomb.loadFromFile("bombbbb.png");
		Sprite s1(bomb);
		s1.setPosition(84, 68);
		s1.setScale(0.08, 0.1);
		window.draw(s1);

		Texture bomb1;
		bomb1.loadFromFile("bombbbb.png");
		Sprite s2(bomb1);
		s2.setPosition(152, 280);
		s2.setScale(0.08, 0.1);
		window.draw(s2);

		Texture bomb2;
		bomb2.loadFromFile("bombbbb.png");
		Sprite s3(bomb2);
		s3.setPosition(290, 550);
		s3.setScale(0.08, 0.1);
		window.draw(s3);

		Texture bomb3;
		bomb3.loadFromFile("bombbbb.png");
		Sprite s4(bomb3);
		s4.setPosition(10, 415);
		s4.setScale(0.08, 0.1);
		window.draw(s4);

		Texture bomb4;
		bomb4.loadFromFile("bombbbb.png");
		Sprite s5(bomb4);
		s5.setPosition(363, 140);
		s5.setScale(0.08, 0.1);
		window.draw(s5);
	}
	int arr[10][10];
	int x = 100, temp = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 != 0)
		{
			temp = x - 9;
			x -= 10;
		}
		for (int j = 0; j < 10; j++)
		{
			if (i % 2 != 0)
			{
				arr[i][j] = temp;
				temp++;
			}
			else
			{
				arr[i][j] = x;
				x--;
			}
			text.setFillColor(Color::White);
			String str = to_string(arr[i][j]);
			text.setString(str);
			text.setCharacterSize(30);
			text.setPosition(w * j + 15, w * i + 15);
			window.draw(text);
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (arr[i][j] == Ladder1) {
				laddersSpirit[0].setPosition(w * j + 5, w * i + 5);
				window.draw(laddersSpirit[0]);
			}
			else if (arr[i][j] == Ladder2) {
				laddersSpirit[1].setPosition(w * j + 7, w * i + 7);
				window.draw(laddersSpirit[1]);
			}
			else if (arr[i][j] == Ladder3) {
				laddersSpirit[2].setPosition(w * j + 12, w * i + 10);
				window.draw(laddersSpirit[2]);
			}
			else if (arr[i][j] == Ladder4) {
				laddersSpirit[3].setPosition(w * j + 15, w * i + 8);
				window.draw(laddersSpirit[3]);
			}
			else if (arr[i][j] == Ladder5) {
				laddersSpirit[4].setPosition(w * j + 10, w * i + 7);
				window.draw(laddersSpirit[4]);
			}
			else if (arr[i][j] == Snake1) {
				snakesSpirit[0].setScale(0.15, 0.15);
				snakesSpirit[0].setPosition(w * j, w * i + 5);
				window.draw(snakesSpirit[0]);
			}
			else if (arr[i][j] == Snake2) {
				snakesSpirit[1].setPosition(w * j + 4, w * i + 5);
				window.draw(snakesSpirit[1]);
			}
			else if (arr[i][j] == Snake3) {
				snakesSpirit[2].setScale(0.15, 0.1);
				snakesSpirit[2].setPosition(w * j + 3, w * i + 5);
				window.draw(snakesSpirit[2]);
			}
			else if (arr[i][j] == Snake4) {
				snakesSpirit[3].setPosition(w * j, w * i + 8);
				window.draw(snakesSpirit[3]);
			}
			else if (arr[i][j] == Snake5) {
				snakesSpirit[4].setPosition(w * j, w * i + 8);
				window.draw(snakesSpirit[4]);
			}
			else if (arr[i][j] == 37) {

				laddersSpirit[0].setPosition(w * j + 5, w * i + 5);
				window.draw(laddersSpirit[0]);
			}
			else if (arr[i][j] == 30) {
				laddersSpirit[1].setPosition(w * j + 7, w * i + 7);
				window.draw(laddersSpirit[1]);
			}
			else if (arr[i][j] == 85) {
				laddersSpirit[2].setPosition(w * j + 12, w * i + 10);
				window.draw(laddersSpirit[2]);
			}
			else if (arr[i][j] == 72) {
				laddersSpirit[3].setPosition(w * j + 15, w * i + 8);
				window.draw(laddersSpirit[3]);
			}
			else  if (arr[i][j] == 100) {
				laddersSpirit[4].setPosition(w * j + 10, w * i + 7);
				window.draw(laddersSpirit[4]);
			}
			else if (arr[i][j] == 4) {
				snakesT[0].setScale(0.12, 0.12);
				snakesT[0].setPosition(w * j - 5, w * i + 20);
				window.draw(snakesT[0]);
			}
			else if (arr[i][j] == 22) {

				snakesT[1].setPosition(w * j - 10, w * i + 20);
				window.draw(snakesT[1]);
			}
			else if (arr[i][j] == 32) {

				snakesT[2].setPosition(w * j - 9, w * i + 25);
				window.draw(snakesT[2]);
			}
			else if (arr[i][j] == 13) {
				snakesT[3].setPosition(w * j, w * i + 25);
				window.draw(snakesT[3]);
			}
			else if (arr[i][j] == 64) {
				snakesT[4].setPosition(w * j, w * i + 20);
				window.draw(snakesT[4]);
			}
		}
	}
}
void ONE_PLAYER_Hard() {
	int Playerturn = 0;
	dice.loadFromFile("d.png");
	imdice.setTexture(dice);
	imdice.setPosition(800, 580);
	imdice.setScale(0.3, 0.3);
	srand(time(NULL));
	window.draw(imdice);
	p1.loadFromFile("p1.png");
	ip1.setTexture(p1);
	ip1.setScale(0.08, 0.08);
	
	window.draw(ip1);

	srand(time(NULL));
	int computer[] = { 1,2,3,4,5,6 };
	int computer_score = 1;
	int comprand;
	Event ev_comp;
	while (window.pollEvent(ev_comp))
	{

		if (ev_comp.type == ev_comp.MouseButtonPressed) {
			if (ev_comp.mouseButton.x >= imdice.getPosition().x && ev_comp.mouseButton.y >= imdice.getPosition().y)
			{
				dise = 1 + rand() % 6;
				buffer.loadFromFile("roll.wav");
				sound.setBuffer(buffer);
				sound.play();
			}
			if (dise == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 460);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);
			}
			else if (dise == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 460);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (dise == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 460);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (dise == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 460);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (dise == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 460);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (dise == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 460);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}
			Number[Playerturn].score += dise;
			if (Number[Playerturn].score == Ladder1) {
				Number[Playerturn].score = 37;
			}
			if (Number[Playerturn].score == Ladder2) {
				Number[Playerturn].score = 30;
			}
			if (Number[Playerturn].score == Ladder3) {
				Number[Playerturn].score = 85;
			}
			if (Number[Playerturn].score == Ladder4) {
				Number[Playerturn].score = 72;
			}
			if (Number[Playerturn].score == Ladder5) {
				Number[Playerturn].score = 100;
			}
			if (Number[Playerturn].score == Snake1) {
				Number[Playerturn].score = 4;
			}
			if (Number[Playerturn].score == Snake2) {
				Number[Playerturn].score = 22;
			}
			if (Number[Playerturn].score == Snake3) {
				Number[Playerturn].score = 32;
			}
			if (Number[Playerturn].score == Snake4) {
				Number[Playerturn].score = 13;
			}
			if (Number[Playerturn].score == Snake5) {
				Number[Playerturn].score = 77;
			}
			if (Number[Playerturn].score == 16 || Number[Playerturn].score == 40 || Number[Playerturn].score == 58 || Number[Playerturn].score == 75 || Number[Playerturn].score == 82) {
				befo.loadFromFile("bomb.wav");
				soun.setBuffer(befo);
				soun.play();
				Number[Playerturn].score = 1;
			}
			if (Number[Playerturn].score == 1) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 640);
				}
			}
			if (Number[Playerturn].score == 2) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 640);
				}

			}
			if (Number[Playerturn].score == 3) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 640);
				}

			}
			if (Number[Playerturn].score == 4) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 640);
				}


			}

			if (Number[Playerturn].score == 5) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 640);
				}


			}

			if (Number[Playerturn].score == 6) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 640);
				}


			}

			if (Number[Playerturn].score == 7) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 640);
				}

			}
			if (Number[Playerturn].score == 8) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 640);
				}

			}

			if (Number[Playerturn].score == 9) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 640);
				}

			}

			if (Number[Playerturn].score == 10) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 640);
				}


			}
			if (Number[Playerturn].score == 11) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 560);
				}

			}

			if (Number[Playerturn].score == 12) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 560);
				}

			}



			if (Number[Playerturn].score == 13) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 560);
				}


			}



			if (Number[Playerturn].score == 14) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 560);
				}

			}
			if (Number[Playerturn].score == 15) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 560);
				}


			}

			if (Number[Playerturn].score == 16) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 560);
				}

			}


			if (Number[Playerturn].score == 17) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 560);
				}

			}

			if (Number[Playerturn].score == 18) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 560);
				}

			}




			if (Number[Playerturn].score == 19) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 560);
				}

			}

			if (Number[Playerturn].score == 20) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 560);
				}

			}
			if (Number[Playerturn].score == 21) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 490);
				}

			}
			if (Number[Playerturn].score == 22) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 490);
				}

			}
			if (Number[Playerturn].score == 23) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 490);
				}

			}
			if (Number[Playerturn].score == 24) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 490);
				}

			}
			if (Number[Playerturn].score == 25) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 490);
				}


			}
			if (Number[Playerturn].score == 26) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 490);
				}

			}
			if (Number[Playerturn].score == 27) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 490);
				}

			}
			if (Number[Playerturn].score == 28) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 490);
				}

			}
			if (Number[Playerturn].score == 29) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 490);
				}

			}
			if (Number[Playerturn].score == 30) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 490);
				}

			}
			if (Number[Playerturn].score == 31) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 420);
				}

			}
			if (Number[Playerturn].score == 32) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 420);
				}

			}
			if (Number[Playerturn].score == 33) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 420);
				}

			}
			if (Number[Playerturn].score == 34) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 420);
				}

			}
			if (Number[Playerturn].score == 35) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 420);
				}

			}
			if (Number[Playerturn].score == 36) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 420);
				}

			}
			if (Number[Playerturn].score == 37) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 420);
				}

			}
			if (Number[Playerturn].score == 38) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 420);
				}

			}
			if (Number[Playerturn].score == 39) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 420);
				}


			}
			if (Number[Playerturn].score == 40) {

				if (Playerturn == 0) {

					ip1.setPosition(0, 420);
				}

			}
			if (Number[Playerturn].score == 41) {
				if (Playerturn == 0) {

					ip1.setPosition(0, 350);
				}

			}
			if (Number[Playerturn].score == 42) {
				if (Playerturn == 0) {

					ip1.setPosition(70, 350);
				}

			}
			if (Number[Playerturn].score == 43) {
				if (Playerturn == 0) {

					ip1.setPosition(140, 350);
				}

			}
			if (Number[Playerturn].score == 44) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 350);
				}


			}
			if (Number[Playerturn].score == 45) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 350);
				}

			}
			if (Number[Playerturn].score == 46) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 350);
				}
			}
			if (Number[Playerturn].score == 47) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 350);
				}
			}
			if (Number[Playerturn].score == 48) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 350);
				}

			}
			if (Number[Playerturn].score == 49) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 350);
				}

			}
			if (Number[Playerturn].score == 50) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 350);
				}


			}
			if (Number[Playerturn].score == 51) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 280);
				}

			}
			if (Number[Playerturn].score == 52) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 280);
				}

			}
			if (Number[Playerturn].score == 53) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 280);
				}

			}
			if (Number[Playerturn].score == 54) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 280);
				}

			}
			if (Number[Playerturn].score == 55) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 280);
				}


			}
			if (Number[Playerturn].score == 56) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 280);
				}

			}
			if (Number[Playerturn].score == 57) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 280);
				}

			}
			if (Number[Playerturn].score == 58) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 280);
				}

			}
			if (Number[Playerturn].score == 59) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 280);
				}

			}
			if (Number[Playerturn].score == 60) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 280);
				}

			}
			if (Number[Playerturn].score == 61) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 210);
				}

			}
			if (Number[Playerturn].score == 62) {

				if (Playerturn == 0) {
					ip1.setPosition(75, 210);
				}

			}

			if (Number[Playerturn].score == 63) {

				if (Playerturn == 0) {
					ip1.setPosition(145, 210);
				}

			}
			if (Number[Playerturn].score == 64) {

				if (Playerturn == 0) {
					ip1.setPosition(215, 210);
				}

			}

			if (Number[Playerturn].score == 65) {

				if (Playerturn == 0) {
					ip1.setPosition(285, 210);
				}

			}
			if (Number[Playerturn].score == 66) {

				if (Playerturn == 0) {
					ip1.setPosition(355, 210);
				}

			}
			if (Number[Playerturn].score == 67) {

				if (Playerturn == 0) {
					ip1.setPosition(425, 210);
				}

			}
			if (Number[Playerturn].score == 68) {

				if (Playerturn == 0) {
					ip1.setPosition(495, 210);
				}

			}
			if (Number[Playerturn].score == 69) {

				if (Playerturn == 0) {
					ip1.setPosition(565, 210);
				}

			}
			if (Number[Playerturn].score == 70) {

				if (Playerturn == 0) {
					ip1.setPosition(635, 210);
				}

			}

			if (Number[Playerturn].score == 71) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 140);
				}

			}
			if (Number[Playerturn].score == 72) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 140);
				}
			}

			if (Number[Playerturn].score == 73) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 140);
				}


			}


			if (Number[Playerturn].score == 74) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 140);
				}


			}
			if (Number[Playerturn].score == 75) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 140);
				}

			}
			if (Number[Playerturn].score == 76) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 140);
				}

			}

			if (Number[Playerturn].score == 77) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 140);
				}

			}

			if (Number[Playerturn].score == 78) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 140);
				}
			}

			if (Number[Playerturn].score == 79) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 140);
				}

			}

			if (Number[Playerturn].score == 80) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 140);
				}
			}

			if (Number[Playerturn].score == 89) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 70);
				}
			}
			if (Number[Playerturn].score == 88) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 70);
				}

			}



			if (Number[Playerturn].score == 87) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 70);
				}

			}

			if (Number[Playerturn].score == 86) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 70);
				}
			}
			if (Number[Playerturn].score == 85) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 70);
				}

			}
			if (Number[Playerturn].score == 84) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 70);
				}
			}
			if (Number[Playerturn].score == 83) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 70);
				}
			}
			if (Number[Playerturn].score == 82) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 70);
				}

			}

			if (Number[Playerturn].score == 81) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 70);
				}


			}
			if (Number[Playerturn].score == 90) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}

			}

			if (Number[Playerturn].score == 100) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 0);
				}

			}
			if (Number[Playerturn].score == 99) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 0);
				}
			}

			if (Number[Playerturn].score == 98) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 0);
				}

			}

			if (Number[Playerturn].score == 97) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 0);
				}

			}

			if (Number[Playerturn].score == 96) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 0);
				}

			}


			if (Number[Playerturn].score == 95) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 0);
				}


			}


			if (Number[Playerturn].score == 94) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 0);
				}

			}


			if (Number[Playerturn].score == 93) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 0);
				}

			}


			if (Number[Playerturn].score == 92) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 0);
				}


			}


			if (Number[Playerturn].score == 91) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}
			}
			cout << "dice  " << dise << endl;
			cout << "Player  "
				<< Playerturn << "\t " << "PLace: " << Number[Playerturn].score << "   " << endl;
			Sleep(100);
			comprand = computer[rand() % 6];
			buffer.loadFromFile("roll.wav");
			sound.setBuffer(buffer);
			sound.play();
			if (comprand == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 260);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);
			}
			else if (comprand == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 260);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (comprand == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 260);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (comprand == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 260);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (comprand == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 260);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (comprand == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 260);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}
			computer_score += comprand;

			if (computer_score == Ladder1) {
				computer_score = 37;
			}
			if (computer_score == Ladder2) {
				computer_score = 30;
			}
			if (computer_score == Ladder3) {
				computer_score = 85;
			}
			if (computer_score == Ladder4) {
				computer_score = 72;
			}
			if (computer_score == Ladder5) {
				computer_score = 100;
			}
			if (computer_score == Snake1) {
				computer_score = 4;
			}
			if (computer_score == Snake2) {
				computer_score = 22;
			}
			if (computer_score == Snake3) {
				computer_score = 32;
			}
			if (computer_score == Snake4) {
				computer_score = 13;
			}
			if (computer_score == Snake5) {
				computer_score = 77;
			}
			if (computer_score == 16 || computer_score == 40 || computer_score == 58 || computer_score == 75 || computer_score == 82) {
				buffer.loadFromFile("bomb.wav");
				sound.setBuffer(buffer);
				sound.play();
				computer_score = 1;
			}
			scoreBoard_Comp(computer_score);
		}

	}

}
void convert(int n, players Number[], string s[])
{
	stringstream ss[5];
	for (int i = 0; i <= n; i++)
	{

		ss[i] << Number[i].score;
		ss[i] >> s[i];
	}
}
void scoreBoard2()
{
	int N = 2;
	players  arr[10];
	Texture texture;
	texture.loadFromFile("dark.JPG");
	Sprite  sprite;
	sprite.setTexture(texture);

	Texture texture2;
	texture2.loadFromFile("dark.JPG");
	Sprite  sprite2;
	sprite2.setTexture(texture2);
	//////
	Font font;
	font.loadFromFile("action.ttf");

	Text text;
	text.setFont(font);

	/////////////////////////////////////drawing shapes
	string s[5];
	convert(N, Number, s);

	for (int i = 0; i < N; i++)
	{
		string str = to_string(i + 1);
		Number[i].NameOfplayer = "Player " + str;
		arr[i].NameOfplayer = Number[i].NameOfplayer;
		arr[i].score = Number[i].score;
	}
	for (int i = 0; i < N; i++) {

		sprite.setTextureRect(IntRect(0, 0, 155, 50));
		sprite.setPosition(Vector2f(760, (i * 53.0)));

		sprite2.setTextureRect(IntRect(0, 0, 70, 50));
		sprite2.setPosition(Vector2f(920, (i * 53.0)));

		window.draw(sprite);
		window.draw(sprite2);
		/*
				text.setString("Players");
				text.setFillColor(sf::Color::Yellow);
				text.setCharacterSize(35);
				text.setPosition(Vector2f(760, 10));
				window.draw(text);

				text.setString("scores");
				text.setCharacterSize(20);
				text.setPosition(Vector2f(920, 20));
				window.draw(text);
				*/


		if (arr[i].score < 100)
		{
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Yellow);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(760, 10 + (i * 53.0)));
			window.draw(text);

			text.setString(s[i]);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(920, 10 + (i * 50.0)));
			window.draw(text);
		}
		else if (arr[i].score >= 100)
		{
			arr[i].score = 100;
			window.clear(Color::White);
			text.setString("Congratulations!!  ");
			text.setFillColor(sf::Color::Blue);
			text.setCharacterSize(70);
			text.setPosition(Vector2f(230, 300));
			window.draw(text);
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(250, 370));
			window.draw(text);
			text.setString(" is the winner");
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(430, 370));
			window.draw(text);
			gameover = true;
		}

	}

}
void Dice2() {
	int N = 2;
	//image of the dice 
	dice.loadFromFile("d.png");
	imdice.setTexture(dice);
	imdice.setPosition(800, 580);
	imdice.setScale(0.3, 0.3);
	srand(time(NULL));
	window.draw(imdice);



	p1.loadFromFile("p1.png");
	ip1.setTexture(p1);

	ip1.setScale(0.08, 0.08);
	window.draw(ip1);

	p2.loadFromFile("p2.png");

	ip2.setTexture(p2);
	ip2.setScale(0.08, 0.08);
	window.draw(ip2);

	Event ev;
	while (window.pollEvent(ev))
	{


		if (ev.type == ev.MouseButtonPressed) {
			if (ev.mouseButton.x >= imdice.getPosition().x && ev.mouseButton.y >= imdice.getPosition().y)
			{
				dise = 1 + rand() % 6;
				buffer.loadFromFile("roll.wav");
				sound.setBuffer(buffer);
				sound.play();
				Playerturn = (Playerturn + 1) % N;
			}
			if (dise == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 460);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);


			}
			else if (dise == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 460);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (dise == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 460);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (dise == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 460);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (dise == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 460);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (dise == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 460);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}

			Number[Playerturn].score += dise;
			if (Number[Playerturn].score == Ladder1) {
				Number[Playerturn].score = 37;
			}
			if (Number[Playerturn].score == Ladder2) {
				Number[Playerturn].score = 30;
			}
			if (Number[Playerturn].score == Ladder3) {
				Number[Playerturn].score = 85;
			}
			if (Number[Playerturn].score == Ladder4) {
				Number[Playerturn].score = 72;
			}
			if (Number[Playerturn].score == Ladder5) {
				Number[Playerturn].score = 100;
			}
			if (Number[Playerturn].score == Snake1) {
				Number[Playerturn].score = 4;
			}
			if (Number[Playerturn].score == Snake2) {
				Number[Playerturn].score = 22;
			}
			if (Number[Playerturn].score == Snake3) {
				Number[Playerturn].score = 32;
			}
			if (Number[Playerturn].score == Snake4) {
				Number[Playerturn].score = 13;
			}
			if (Number[Playerturn].score == Snake5) {
				Number[Playerturn].score = 77;
			}
			cout << dise << endl;
			cout << "Player" << Playerturn + 1 << ": " << Number[Playerturn].score << endl;

			if (Number[Playerturn].score == 1) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 640);
				}
			}
			if (Number[Playerturn].score == 2) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 640);
				}
			}
			if (Number[Playerturn].score == 3) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 640);
				}
			}
			if (Number[Playerturn].score == 4) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 640);
				}

			}

			if (Number[Playerturn].score == 5) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 640);
				}

				if (Playerturn == 1) {
					ip2.setPosition(280, 640);
				}
			}

			if (Number[Playerturn].score == 6) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 640);
				}

			}

			if (Number[Playerturn].score == 7) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 640);
				}
			}
			if (Number[Playerturn].score == 8) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 640);
				}
			}

			if (Number[Playerturn].score == 9) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 640);
				}
			}

			if (Number[Playerturn].score == 10) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 640);
				}
			}
			if (Number[Playerturn].score == 11) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 560);
				}
			}

			if (Number[Playerturn].score == 12) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 560);
				}
			}



			if (Number[Playerturn].score == 13) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 560);
				}

			}



			if (Number[Playerturn].score == 14) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 560);
				}
			}
			if (Number[Playerturn].score == 15) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 560);
				}

			}

			if (Number[Playerturn].score == 16) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 560);
				}
			}


			if (Number[Playerturn].score == 17) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 560);
				}
			}

			if (Number[Playerturn].score == 18) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 560);
				}
			}




			if (Number[Playerturn].score == 19) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 560);
				}
			}

			if (Number[Playerturn].score == 20) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 560);
				}
			}
			if (Number[Playerturn].score == 21) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 490);
				}
			}
			if (Number[Playerturn].score == 22) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 490);
				}
			}
			if (Number[Playerturn].score == 23) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 490);
				}
			}
			if (Number[Playerturn].score == 24) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 490);
				}
			}
			if (Number[Playerturn].score == 25) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 490);
				}
			}
			if (Number[Playerturn].score == 26) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 490);
				}

				if (Playerturn == 1) {
					ip2.setPosition(350, 490);
				}
			}
			if (Number[Playerturn].score == 27) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 490);
				}

			}
			if (Number[Playerturn].score == 28) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 490);
				}
			}
			if (Number[Playerturn].score == 29) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 490);
				}
			}
			if (Number[Playerturn].score == 30) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 490);
				}
			}
			if (Number[Playerturn].score == 31) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 420);
				}
			}
			if (Number[Playerturn].score == 32) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 420);
				}
			}
			if (Number[Playerturn].score == 33) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 420);
				}
			}
			if (Number[Playerturn].score == 34) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 420);
				}
			}
			if (Number[Playerturn].score == 35) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 420);
				}
			}
			if (Number[Playerturn].score == 36) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 420);
				}
			}
			if (Number[Playerturn].score == 37) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 420);
				}
			}
			if (Number[Playerturn].score == 38) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 420);
				}
			}
			if (Number[Playerturn].score == 39) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 420);
				}

			}
			if (Number[Playerturn].score == 40) {

				if (Playerturn == 0) {

					ip1.setPosition(0, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 420);
				}
			}
			if (Number[Playerturn].score == 41) {
				if (Playerturn == 0) {

					ip1.setPosition(0, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 350);
				}
			}
			if (Number[Playerturn].score == 42) {
				if (Playerturn == 0) {

					ip1.setPosition(70, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 350);
				}
			}
			if (Number[Playerturn].score == 43) {
				if (Playerturn == 0) {

					ip1.setPosition(140, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 350);
				}
			}
			if (Number[Playerturn].score == 44) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 350);
				}

			}
			if (Number[Playerturn].score == 45) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 350);
				}
			}
			if (Number[Playerturn].score == 46) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 350);
				}
			}
			if (Number[Playerturn].score == 47) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 350);
				}
			}
			if (Number[Playerturn].score == 48) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 350);
				}
			}
			if (Number[Playerturn].score == 49) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 350);
				}
			}
			if (Number[Playerturn].score == 50) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 350);
				}

			}
			if (Number[Playerturn].score == 51) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 280);
				}
			}
			if (Number[Playerturn].score == 52) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 280);
				}
			}
			if (Number[Playerturn].score == 53) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 280);
				}
			}
			if (Number[Playerturn].score == 54) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 280);
				}
			}
			if (Number[Playerturn].score == 55) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 280);
				}

			}
			if (Number[Playerturn].score == 56) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 280);
				}
			}
			if (Number[Playerturn].score == 57) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 280);
				}
			}
			if (Number[Playerturn].score == 58) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 280);
				}
			}
			if (Number[Playerturn].score == 59) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 280);
				}
			}
			if (Number[Playerturn].score == 60) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 280);
				}
			}
			if (Number[Playerturn].score == 61) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 210);
				}
			}
			if (Number[Playerturn].score == 62) {

				if (Playerturn == 0) {
					ip1.setPosition(75, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(75, 210);
				}
			}

			if (Number[Playerturn].score == 63) {

				if (Playerturn == 0) {
					ip1.setPosition(145, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(145, 210);
				}
			}
			if (Number[Playerturn].score == 64) {

				if (Playerturn == 0) {
					ip1.setPosition(215, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(215, 210);
				}
			}

			if (Number[Playerturn].score == 65) {

				if (Playerturn == 0) {
					ip1.setPosition(285, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(285, 210);
				}
			}
			if (Number[Playerturn].score == 66) {

				if (Playerturn == 0) {
					ip1.setPosition(355, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(355, 210);
				}
			}
			if (Number[Playerturn].score == 67) {

				if (Playerturn == 0) {
					ip1.setPosition(425, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 210);
				}
			}
			if (Number[Playerturn].score == 68) {

				if (Playerturn == 0) {
					ip1.setPosition(495, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(495, 210);
				}
			}
			if (Number[Playerturn].score == 69) {

				if (Playerturn == 0) {
					ip1.setPosition(565, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(565, 210);
				}
			}
			if (Number[Playerturn].score == 70) {

				if (Playerturn == 0) {
					ip1.setPosition(635, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(635, 210);
				}
			}

			if (Number[Playerturn].score == 71) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 140);
				}
			}
			if (Number[Playerturn].score == 72) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 140);
				}
			}

			if (Number[Playerturn].score == 73) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 140);
				}

			}


			if (Number[Playerturn].score == 74) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 140);
				}

			}
			if (Number[Playerturn].score == 75) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 140);
				}
			}
			if (Number[Playerturn].score == 76) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 140);
				}
			}

			if (Number[Playerturn].score == 77) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 140);
				}
			}

			if (Number[Playerturn].score == 78) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 140);
				}
			}

			if (Number[Playerturn].score == 79) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 140);
				}
			}

			if (Number[Playerturn].score == 80) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 140);
				}
			}

			if (Number[Playerturn].score == 89) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 70);
				}

				if (Playerturn == 1) {
					ip2.setPosition(560, 70);
				}
			}
			if (Number[Playerturn].score == 88) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 70);
				}
			}



			if (Number[Playerturn].score == 87) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 70);
				}
			}

			if (Number[Playerturn].score == 86) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 70);
				}
			}
			if (Number[Playerturn].score == 85) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 70);
				}
			}
			if (Number[Playerturn].score == 84) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 70);
				}
			}
			if (Number[Playerturn].score == 83) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 70);
				}
			}
			if (Number[Playerturn].score == 82) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 70);
				}
			}

			if (Number[Playerturn].score == 81) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 70);
				}

			}
			if (Number[Playerturn].score == 90) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 0);
				}
			}

			if (Number[Playerturn].score == 100) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 0);
				}

				if (Playerturn == 1) {
					ip2.setPosition(0, 0);
				}
			}
			if (Number[Playerturn].score == 99) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 0);
				}
			}

			if (Number[Playerturn].score == 98) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 0);
				}
			}

			if (Number[Playerturn].score == 97) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 0);
				}
			}

			if (Number[Playerturn].score == 96) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 0);
				}
			}


			if (Number[Playerturn].score == 95) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 0);
				}

			}


			if (Number[Playerturn].score == 94) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 0);
				}
			}


			if (Number[Playerturn].score == 93) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 0);
				}
			}


			if (Number[Playerturn].score == 92) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 0);
				}

			}
			if (Number[Playerturn].score == 91) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 0);
				}
			}
			scoreBoard2();
		}

	}
}
void Dice3() {
	int N = 3;
	//image of the dice 
	dice.loadFromFile("d.png");
	imdice.setTexture(dice);
	imdice.setPosition(800, 580);
	imdice.setScale(0.3, 0.3);
	srand(time(NULL));
	window.draw(imdice);



	p1.loadFromFile("p1.png");
	ip1.setTexture(p1);

	ip1.setScale(0.08, 0.08);
	window.draw(ip1);

	p2.loadFromFile("p2.png");
	ip2.setTexture(p2);

	ip2.setScale(0.08, 0.08);
	window.draw(ip2);

	p3.loadFromFile("p3.png");
	ip3.setTexture(p3);

	ip3.setScale(0.03, 0.03);
	window.draw(ip3);

	Event ev;
	while (window.pollEvent(ev))
	{


		if (ev.type == ev.MouseButtonPressed) {
			if (ev.mouseButton.x >= imdice.getPosition().x && ev.mouseButton.y >= imdice.getPosition().y)
			{
				dise = 1 + rand() % 6;
				buffer.loadFromFile("roll.wav");
				sound.setBuffer(buffer);
				sound.play();
				Playerturn = (Playerturn + 1) % N;
			}
			if (dise == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 460);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);


			}
			else if (dise == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 460);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (dise == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 460);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (dise == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 460);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (dise == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 460);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (dise == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 460);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}

			Number[Playerturn].score += dise;
			if (Number[Playerturn].score == Ladder1) {
				Number[Playerturn].score = 37;
			}
			if (Number[Playerturn].score == Ladder2) {
				Number[Playerturn].score = 30;
			}
			if (Number[Playerturn].score == Ladder3) {
				Number[Playerturn].score = 85;
			}
			if (Number[Playerturn].score == Ladder4) {
				Number[Playerturn].score = 72;
			}
			if (Number[Playerturn].score == Ladder5) {
				Number[Playerturn].score = 100;
			}
			if (Number[Playerturn].score == Snake1) {
				Number[Playerturn].score = 4;
			}
			if (Number[Playerturn].score == Snake2) {
				Number[Playerturn].score = 22;
			}
			if (Number[Playerturn].score == Snake3) {
				Number[Playerturn].score = 32;
			}
			if (Number[Playerturn].score == Snake4) {
				Number[Playerturn].score = 13;
			}
			if (Number[Playerturn].score == Snake5) {
				Number[Playerturn].score = 77;
			}
			cout << dise << endl;
			cout << "Player" << Playerturn + 1 << ": " << Number[Playerturn].score << endl;
			if (Number[Playerturn].score == 1) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 640);
				}

				if (Playerturn == 3) {
					ip4.setPosition(0, 640);
				}
			}
			if (Number[Playerturn].score == 2) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 640);
				}

				if (Playerturn == 3) {
					ip4.setPosition(70, 640);
				}

			}
			if (Number[Playerturn].score == 3) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 640);
				}

				if (Playerturn == 3) {
					ip4.setPosition(140, 640);
				}

			}
			if (Number[Playerturn].score == 4) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 640);
				}

			}

			if (Number[Playerturn].score == 5) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 640);
				}

			}

			if (Number[Playerturn].score == 6) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 640);
				}

			}

			if (Number[Playerturn].score == 7) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 640);
				}

			}
			if (Number[Playerturn].score == 8) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 640);
				}

			}

			if (Number[Playerturn].score == 9) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 640);
				}

			}

			if (Number[Playerturn].score == 10) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 640);
				}

			}
			if (Number[Playerturn].score == 11) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 560);
				}

			}

			if (Number[Playerturn].score == 12) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 560);
				}

			}



			if (Number[Playerturn].score == 13) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 560);
				}

			}



			if (Number[Playerturn].score == 14) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 560);
				}

			}
			if (Number[Playerturn].score == 15) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 560);
				}

			}

			if (Number[Playerturn].score == 16) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 560);
				}

			}


			if (Number[Playerturn].score == 17) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 560);
				}

			}

			if (Number[Playerturn].score == 18) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 560);
				}

			}




			if (Number[Playerturn].score == 19) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 560);
				}

			}

			if (Number[Playerturn].score == 20) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 560);
				}

			}
			if (Number[Playerturn].score == 21) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 490);
				}

			}
			if (Number[Playerturn].score == 22) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 490);
				}

			}
			if (Number[Playerturn].score == 23) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 490);
				}

			}
			if (Number[Playerturn].score == 24) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 490);
				}

			}
			if (Number[Playerturn].score == 25) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 490);
				}

			}
			if (Number[Playerturn].score == 26) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 490);
				}

			}
			if (Number[Playerturn].score == 27) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 490);
				}

			}
			if (Number[Playerturn].score == 28) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 490);
				}

			}
			if (Number[Playerturn].score == 29) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 490);
				}

			}
			if (Number[Playerturn].score == 30) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 490);
				}

			}
			if (Number[Playerturn].score == 31) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 420);
				}

			}
			if (Number[Playerturn].score == 32) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 420);
				}

			}
			if (Number[Playerturn].score == 33) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 420);
				}

			}
			if (Number[Playerturn].score == 34) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 420);
				}

			}
			if (Number[Playerturn].score == 35) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 420);
				}

			}
			if (Number[Playerturn].score == 36) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 420);
				}

			}
			if (Number[Playerturn].score == 37) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 420);
				}


			}
			if (Number[Playerturn].score == 38) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 420);
				}


			}
			if (Number[Playerturn].score == 39) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 420);
				}

			}
			if (Number[Playerturn].score == 40) {

				if (Playerturn == 0) {

					ip1.setPosition(0, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 420);
				}


			}
			if (Number[Playerturn].score == 41) {
				if (Playerturn == 0) {

					ip1.setPosition(0, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 350);
				}


			}
			if (Number[Playerturn].score == 42) {
				if (Playerturn == 0) {

					ip1.setPosition(70, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 350);
				}


			}
			if (Number[Playerturn].score == 43) {
				if (Playerturn == 0) {

					ip1.setPosition(140, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 350);
				}
			}
			if (Number[Playerturn].score == 44) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 350);
				}

			}
			if (Number[Playerturn].score == 45) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 350);
				}

			}
			if (Number[Playerturn].score == 46) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 350);
				}


			}
			if (Number[Playerturn].score == 47) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 350);
				}

			}
			if (Number[Playerturn].score == 48) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 350);
				}

			}
			if (Number[Playerturn].score == 49) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 350);
				}

			}
			if (Number[Playerturn].score == 50) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 350);
				}


			}
			if (Number[Playerturn].score == 51) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 280);
				}

			}
			if (Number[Playerturn].score == 52) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 280);
				}

			}
			if (Number[Playerturn].score == 53) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 280);
				}

			}
			if (Number[Playerturn].score == 54) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 280);
				}

			}
			if (Number[Playerturn].score == 55) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 280);
				}

			}
			if (Number[Playerturn].score == 56) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 280);
				}

			}
			if (Number[Playerturn].score == 57) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 280);
				}

			}
			if (Number[Playerturn].score == 58) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 280);
				}

			}
			if (Number[Playerturn].score == 59) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 280);
				}

			}
			if (Number[Playerturn].score == 60) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 280);
				}

			}
			if (Number[Playerturn].score == 61) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 240);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 240);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 240);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 240);
				}

			}
			if (Number[Playerturn].score == 62) {

				if (Playerturn == 0) {
					ip1.setPosition(75, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(75, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(75, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(75, 210);
				}

			}

			if (Number[Playerturn].score == 63) {

				if (Playerturn == 0) {
					ip1.setPosition(145, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(145, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(145, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(145, 210);
				}
			}
			if (Number[Playerturn].score == 64) {

				if (Playerturn == 0) {
					ip1.setPosition(215, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(215, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(215, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(215, 210);
				}

			}

			if (Number[Playerturn].score == 65) {

				if (Playerturn == 0) {
					ip1.setPosition(285, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(285, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(285, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(285, 210);
				}

			}
			if (Number[Playerturn].score == 66) {

				if (Playerturn == 0) {
					ip1.setPosition(355, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(355, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(355, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(355, 210);
				}

			}
			if (Number[Playerturn].score == 67) {

				if (Playerturn == 0) {
					ip1.setPosition(425, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(425, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(425, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(425, 210);
				}

			}
			if (Number[Playerturn].score == 68) {

				if (Playerturn == 0) {
					ip1.setPosition(495, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(495, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(495, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(495, 210);
				}

			}
			if (Number[Playerturn].score == 69) {

				if (Playerturn == 0) {
					ip1.setPosition(565, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(565, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(565, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(565, 210);
				}

			}




			if (Number[Playerturn].score == 70) {

				if (Playerturn == 0) {
					ip1.setPosition(635, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(635, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(635, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(635, 210);
				}

			}

			if (Number[Playerturn].score == 71) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 140);
				}

			}


			if (Number[Playerturn].score == 72) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 140);
				}

			}

			if (Number[Playerturn].score == 73) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 140);
				}

			}


			if (Number[Playerturn].score == 74) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 140);
				}

			}
			if (Number[Playerturn].score == 75) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 140);
				}

			}
			if (Number[Playerturn].score == 76) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 140);
				}

			}

			if (Number[Playerturn].score == 77) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 140);
				}

			}

			if (Number[Playerturn].score == 78) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 140);
				}

			}

			if (Number[Playerturn].score == 79) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 140);
				}

			}

			if (Number[Playerturn].score == 80) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 140);
				}

			}

			if (Number[Playerturn].score == 89) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 70);
				}

			}
			if (Number[Playerturn].score == 88) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 70);
				}

			}



			if (Number[Playerturn].score == 87) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 70);
				}

			}

			if (Number[Playerturn].score == 86) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 70);
				}

			}


			if (Number[Playerturn].score == 85) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 70);
				}

			}




			if (Number[Playerturn].score == 84) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 70);
				}

			}


			if (Number[Playerturn].score == 83) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 70);
				}

			}


			if (Number[Playerturn].score == 82) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 70);
				}

			}

			if (Number[Playerturn].score == 81) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 70);
				}

			}
			if (Number[Playerturn].score == 90) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 70);
				}

			}

			if (Number[Playerturn].score == 100) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 0);
				}

			}
			if (Number[Playerturn].score == 99) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 0);
				}

			}

			if (Number[Playerturn].score == 98) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 0);
				}

			}

			if (Number[Playerturn].score == 97) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 0);
				}

			}

			if (Number[Playerturn].score == 96) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 0);
				}

			}
			if (Number[Playerturn].score == 95) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 0);
				}

			}


			if (Number[Playerturn].score == 94) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 0);
				}

			}


			if (Number[Playerturn].score == 93) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 0);
				}

			}


			if (Number[Playerturn].score == 92) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 0);
						if (Playerturn == 1) {
							ip2.setPosition(560, 0);
						}
					if (Playerturn == 2) {
						ip3.setPosition(560, 0);
					}
					if (Playerturn == 3) {
						ip4.setPosition(560, 0);
					}

				}


				if (Number[Playerturn].score == 91) {

					if (Playerturn == 0) {
						ip1.setPosition(630, 0);
					}
					if (Playerturn == 1) {
						ip2.setPosition(630, 0);
					}
					if (Playerturn == 2) {
						ip3.setPosition(630, 0);
					}
					if (Playerturn == 3) {
						ip4.setPosition(630, 0);
					}

				}
				
			}
			scoreBoard3();
		}
	}
}
void Dice4() {
	int N = 4;
	//image of the dice 
	dice.loadFromFile("d.png");
	imdice.setTexture(dice);
	imdice.setPosition(800, 580);
	imdice.setScale(0.3, 0.3);
	srand(time(NULL));
	window.draw(imdice);



	p1.loadFromFile("p1.png");
	ip1.setTexture(p1);

	ip1.setScale(0.08, 0.08);
	window.draw(ip1);

	p2.loadFromFile("p2.png");
	ip2.setTexture(p2);

	ip2.setScale(0.08, 0.08);
	window.draw(ip2);

	p3.loadFromFile("p3.png");
	ip3.setTexture(p3);

	ip3.setScale(0.03, 0.03);
	window.draw(ip3);

	p4.loadFromFile("p4.png");
	ip4.setTexture(p4);

	ip4.setScale(0.25, 0.25);
	window.draw(ip4);



	Event ev;
	while (window.pollEvent(ev))
	{


		if (ev.type == ev.MouseButtonPressed) {
			if (ev.mouseButton.x >= imdice.getPosition().x && ev.mouseButton.y >= imdice.getPosition().y)
			{
				dise = 1 + rand() % 6;
				buffer.loadFromFile("roll.wav");
				sound.setBuffer(buffer);
				sound.play();
				Playerturn = (Playerturn + 1) % N;
			}
			if (dise == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 460);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);


			}
			else if (dise == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 460);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (dise == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 460);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (dise == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 460);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (dise == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 460);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (dise == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 460);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}

			Number[Playerturn].score += dise;
			if (Number[Playerturn].score == Ladder1) {
				Number[Playerturn].score = 37;
			}
			if (Number[Playerturn].score == Ladder2) {
				Number[Playerturn].score = 30;
			}
			if (Number[Playerturn].score == Ladder3) {
				Number[Playerturn].score = 85;
			}
			if (Number[Playerturn].score == Ladder4) {
				Number[Playerturn].score = 72;
			}
			if (Number[Playerturn].score == Ladder5) {
				Number[Playerturn].score = 100;
			}
			if (Number[Playerturn].score == Snake1) {
				Number[Playerturn].score = 4;
			}
			if (Number[Playerturn].score == Snake2) {
				Number[Playerturn].score = 22;
			}
			if (Number[Playerturn].score == Snake3) {
				Number[Playerturn].score = 32;
			}
			if (Number[Playerturn].score == Snake4) {
				Number[Playerturn].score = 13;
			}
			if (Number[Playerturn].score == Snake5) {
				Number[Playerturn].score = 77;
			}
			cout << dise << endl;
			cout << "Player" << Playerturn + 1 << ": " << Number[Playerturn].score << endl;
			if (Number[Playerturn].score == 1) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 640);
				}

				if (Playerturn == 3) {
					ip4.setPosition(0, 640);
				}
			}
			if (Number[Playerturn].score == 2) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 640);
				}

				if (Playerturn == 3) {
					ip4.setPosition(70, 640);
				}

			}
			if (Number[Playerturn].score == 3) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 640);
				}

				if (Playerturn == 3) {
					ip4.setPosition(140, 640);
				}

			}
			if (Number[Playerturn].score == 4) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 640);
				}

			}

			if (Number[Playerturn].score == 5) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 640);
				}

			}

			if (Number[Playerturn].score == 6) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 640);
				}

			}

			if (Number[Playerturn].score == 7) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 640);
				}

			}
			if (Number[Playerturn].score == 8) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 640);
				}

			}

			if (Number[Playerturn].score == 9) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 640);
				}

			}

			if (Number[Playerturn].score == 10) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 640);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 640);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 640);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 640);
				}

			}
			if (Number[Playerturn].score == 11) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 560);
				}

			}

			if (Number[Playerturn].score == 12) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 560);
				}

			}



			if (Number[Playerturn].score == 13) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 560);
				}

			}



			if (Number[Playerturn].score == 14) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 560);
				}

			}
			if (Number[Playerturn].score == 15) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 560);
				}

			}

			if (Number[Playerturn].score == 16) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 560);
				}

			}


			if (Number[Playerturn].score == 17) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 560);
				}

			}

			if (Number[Playerturn].score == 18) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 560);
				}

			}




			if (Number[Playerturn].score == 19) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 560);
				}

			}

			if (Number[Playerturn].score == 20) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 560);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 560);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 560);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 560);
				}

			}
			if (Number[Playerturn].score == 21) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 512);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 512);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 512);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 512);
				}

			}
			if (Number[Playerturn].score == 22) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 490);
				}

			}
			if (Number[Playerturn].score == 23) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 490);
				}

			}
			if (Number[Playerturn].score == 24) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 490);
				}

			}
			if (Number[Playerturn].score == 25) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 490);
				}

			}
			if (Number[Playerturn].score == 26) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 490);
				}

			}
			if (Number[Playerturn].score == 27) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 490);
				}

			}
			if (Number[Playerturn].score == 28) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 490);
				}

			}
			if (Number[Playerturn].score == 29) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 490);
				}

			}
			if (Number[Playerturn].score == 30) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 490);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 490);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 490);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 490);
				}

			}
			if (Number[Playerturn].score == 31) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 420);
				}

			}
			if (Number[Playerturn].score == 32) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 420);
				}

			}
			if (Number[Playerturn].score == 33) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 420);
				}

			}
			if (Number[Playerturn].score == 34) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 420);
				}

			}
			if (Number[Playerturn].score == 35) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 420);
				}

			}
			if (Number[Playerturn].score == 36) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 420);
				}

			}
			if (Number[Playerturn].score == 37) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 420);
				}


			}
			if (Number[Playerturn].score == 38) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 420);
				}


			}
			if (Number[Playerturn].score == 39) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 420);
				}

			}
			if (Number[Playerturn].score == 40) {

				if (Playerturn == 0) {

					ip1.setPosition(0, 420);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 420);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 420);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 420);
				}


			}
			if (Number[Playerturn].score == 41) {
				if (Playerturn == 0) {

					ip1.setPosition(0, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 350);
				}


			}
			if (Number[Playerturn].score == 42) {
				if (Playerturn == 0) {

					ip1.setPosition(70, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 350);
				}


			}
			if (Number[Playerturn].score == 43) {
				if (Playerturn == 0) {

					ip1.setPosition(140, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 350);
				}
			}
			if (Number[Playerturn].score == 44) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 350);
				}

			}
			if (Number[Playerturn].score == 45) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 350);
				}

			}
			if (Number[Playerturn].score == 46) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 350);
				}


			}
			if (Number[Playerturn].score == 47) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 350);
				}

			}
			if (Number[Playerturn].score == 48) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 350);
				}

			}
			if (Number[Playerturn].score == 49) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 350);
				}

			}
			if (Number[Playerturn].score == 50) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 350);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 350);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 350);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 350);
				}


			}
			if (Number[Playerturn].score == 51) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 280);
				}

			}
			if (Number[Playerturn].score == 52) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 280);
				}

			}
			if (Number[Playerturn].score == 53) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 280);
				}

			}
			if (Number[Playerturn].score == 54) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 280);
				}

			}
			if (Number[Playerturn].score == 55) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 280);
				}

			}
			if (Number[Playerturn].score == 56) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 280);
				}

			}
			if (Number[Playerturn].score == 57) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 280);
				}

			}
			if (Number[Playerturn].score == 58) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 280);
				}

			}
			if (Number[Playerturn].score == 59) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 280);
				}

			}
			if (Number[Playerturn].score == 60) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 280);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 280);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 280);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 280);
				}

			}
			if (Number[Playerturn].score == 61) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 210);
				}

			}
			if (Number[Playerturn].score == 62) {

				if (Playerturn == 0) {
					ip1.setPosition(75, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(75, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(75, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(75, 210);
				}

			}

			if (Number[Playerturn].score == 63) {

				if (Playerturn == 0) {
					ip1.setPosition(145, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(145, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(145, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(145, 210);
				}
			}
			if (Number[Playerturn].score == 64) {

				if (Playerturn == 0) {
					ip1.setPosition(215, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(215, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(215, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(215, 210);
				}
			}

			if (Number[Playerturn].score == 65) {

				if (Playerturn == 0) {
					ip1.setPosition(285, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(285, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(285, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(285, 210);
				}

			}
			if (Number[Playerturn].score == 66) {

				if (Playerturn == 0) {
					ip1.setPosition(355, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(355, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(355, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(355, 210);
				}

			}
			if (Number[Playerturn].score == 67) {

				if (Playerturn == 0) {
					ip1.setPosition(425, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(425, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(425, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(425, 210);
				}

			}
			if (Number[Playerturn].score == 68) {

				if (Playerturn == 0) {
					ip1.setPosition(495, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(495, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(495, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(495, 210);
				}
			}
			if (Number[Playerturn].score == 69) {

				if (Playerturn == 0) {
					ip1.setPosition(565, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(565, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(565, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(565, 210);
				}
			}

			if (Number[Playerturn].score == 70) {

				if (Playerturn == 0) {
					ip1.setPosition(635, 210);
				}
				if (Playerturn == 1) {
					ip2.setPosition(635, 210);
				}
				if (Playerturn == 2) {
					ip3.setPosition(635, 210);
				}
				if (Playerturn == 3) {
					ip4.setPosition(635, 210);
				}
			}

			if (Number[Playerturn].score == 71) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 140);
				}
			}

			if (Number[Playerturn].score == 72) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 140);
				}
			}

			if (Number[Playerturn].score == 73) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 140);
				}
			}

			if (Number[Playerturn].score == 74) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 140);
				}

			}
			if (Number[Playerturn].score == 75) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 140);
				}
			}
			if (Number[Playerturn].score == 76) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 140);
				}
			}

			if (Number[Playerturn].score == 77) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 140);
				}
			}

			if (Number[Playerturn].score == 78) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 140);
				}
			}

			if (Number[Playerturn].score == 79) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 140);
				}
			}

			if (Number[Playerturn].score == 80) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 140);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 140);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 140);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 140);
				}
			}

			if (Number[Playerturn].score == 89) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 70);
				}
			}
			if (Number[Playerturn].score == 88) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 70);
				}
			}

			if (Number[Playerturn].score == 87) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 70);
				}
			}

			if (Number[Playerturn].score == 86) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 70);
				}
			}

			if (Number[Playerturn].score == 85) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 70);
				}
			}

			if (Number[Playerturn].score == 84) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 70);
				}
			}

			if (Number[Playerturn].score == 83) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 70);
				}
			}
			if (Number[Playerturn].score == 82) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 70);
				}
			}

			if (Number[Playerturn].score == 81) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 70);
				}
			}
			if (Number[Playerturn].score == 90) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 70);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 70);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 70);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 70);
				}
			}

			if (Number[Playerturn].score == 100) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(0, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(0, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(0, 0);
				}
			}
			if (Number[Playerturn].score == 99) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(70, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(70, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(70, 0);
				}
			}

			if (Number[Playerturn].score == 98) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(140, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(140, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(140, 0);
				}

			}
			if (Number[Playerturn].score == 97) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(210, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(210, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(210, 0);
				}
			}
			if (Number[Playerturn].score == 96) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(280, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(280, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(280, 0);
				}
			}
			if (Number[Playerturn].score == 95) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(350, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(350, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(350, 0);
				}
			}
			if (Number[Playerturn].score == 94) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(420, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(420, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(420, 0);
				}
			}
			if (Number[Playerturn].score == 93) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(490, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(490, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(490, 0);
				}
			}
			if (Number[Playerturn].score == 92) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(560, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(560, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(560, 0);
				}
			}

			if (Number[Playerturn].score == 91) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}
				if (Playerturn == 1) {
					ip2.setPosition(630, 0);
				}
				if (Playerturn == 2) {
					ip3.setPosition(630, 0);
				}
				if (Playerturn == 3) {
					ip4.setPosition(630, 0);
				}
			}
			scoreBoard4();
		}
	}
}

void scoreBoard3()
{
	int N = 3;
	players  arr[10];
	Texture texture;
	texture.loadFromFile("dark.JPG");
	Sprite  sprite;
	sprite.setTexture(texture);

	Texture texture2;
	texture2.loadFromFile("dark.JPG");
	Sprite  sprite2;
	sprite2.setTexture(texture2);
	//////
	Font font;
	font.loadFromFile("action.ttf");

	Text text;
	text.setFont(font);

	/////////////////////////////////////drawing shapes
	string s[5];
	convert(N, Number, s);

	for (int i = 0; i < N; i++)
	{
		string str = to_string(i + 1);
		Number[i].NameOfplayer = "Player " + str;
		arr[i].NameOfplayer = Number[i].NameOfplayer;
		arr[i].score = Number[i].score;
	}
	for (int i = 0; i < N; i++) {

		sprite.setTextureRect(IntRect(0, 0, 155, 50));
		sprite.setPosition(Vector2f(760, (i * 53.0)));

		sprite2.setTextureRect(IntRect(0, 0, 70, 50));
		sprite2.setPosition(Vector2f(920, (i * 53.0)));

		window.draw(sprite);
		window.draw(sprite2);
		if (arr[i].score < 100)
		{
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Yellow);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(760, 10 + (i * 53.0)));
			window.draw(text);

			text.setString(s[i]);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(920, 10 + (i * 50.0)));
			window.draw(text);
		}
		else if (arr[i].score >= 100)
		{
			arr[i].score = 100;
			window.clear(Color::White);
			text.setString("Congratulations!!");
			text.setFillColor(sf::Color::Blue);
			text.setCharacterSize(70);
			text.setPosition(Vector2f(230, 300));
			window.draw(text);
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(250, 370));
			window.draw(text);
			text.setString("  is the winner");
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(430, 370));
			window.draw(text);
			gameover = true;
		}

	}

}
void scoreBoard4()
{
	int N = 4;
	players  arr[10];
	Texture texture;
	texture.loadFromFile("dark.JPG");
	Sprite  sprite;
	sprite.setTexture(texture);

	Texture texture2;
	texture2.loadFromFile("dark.JPG");
	Sprite  sprite2;
	sprite2.setTexture(texture2);
	//////
	Font font;
	font.loadFromFile("action.ttf");

	Text text;
	text.setFont(font);

	/////////////////////////////////////drawing shapes
	string s[5];
	convert(N, Number, s);

	for (int i = 0; i < N; i++)
	{
		string str = to_string(i + 1);
		Number[i].NameOfplayer = "Player " + str;
		arr[i].NameOfplayer = Number[i].NameOfplayer;
		arr[i].score = Number[i].score;
	}
	for (int i = 0; i < N; i++) {

		sprite.setTextureRect(IntRect(0, 0, 155, 50));
		sprite.setPosition(Vector2f(760, (i * 53.0)));

		sprite2.setTextureRect(IntRect(0, 0, 70, 50));
		sprite2.setPosition(Vector2f(920, (i * 53.0)));

		window.draw(sprite);
		window.draw(sprite2);
		if (arr[i].score < 100)
		{
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Yellow);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(760, 10 + (i * 53.0)));
			window.draw(text);

			text.setString(s[i]);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(920, 10 + (i * 50.0)));
			window.draw(text);
		}
		else if (arr[i].score >= 100)
		{
			arr[i].score = 100;
			window.clear(Color::White);
			text.setString("Congratulations!!");
			text.setFillColor(sf::Color::Blue);
			text.setCharacterSize(70);
			text.setPosition(Vector2f(230, 300));
			window.draw(text);
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(250, 370));
			window.draw(text);
			text.setString("  is the winner");
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(430, 370));
			window.draw(text);
			gameover = true;
		}

	}

}
void scoreBoard_Comp(int& a) {
	int N = 2;
	players  arr[10];
	Texture texture;
	texture.loadFromFile("dark.JPG");
	Sprite  sprite;
	sprite.setTexture(texture);

	Texture texture2;
	texture2.loadFromFile("dark.JPG");
	Sprite  sprite2;
	sprite2.setTexture(texture2);
	//////
	Font font;
	font.loadFromFile("action.ttf");

	Text text;
	text.setFont(font);

	/////////////////////////////////////drawing shapes
	string s[5];


	for (int i = 0; i < N; i++)
	{
		string str = to_string(i);
		Number[0].NameOfplayer = "Player ";
		Number[1].NameOfplayer = "Computer ";
		arr[0].NameOfplayer = Number[0].NameOfplayer;
		arr[1].NameOfplayer = Number[1].NameOfplayer;
		arr[0].score = Number[0].score;
		arr[1].score = a;

	}
	convert(N, arr, s);
	for (int i = 0; i < N; i++) {

		sprite.setTextureRect(IntRect(0, 0, 155, 50));
		sprite.setPosition(Vector2f(760, (i * 53.0)));

		sprite2.setTextureRect(IntRect(0, 0, 70, 50));
		sprite2.setPosition(Vector2f(920, (i * 53.0)));

		window.draw(sprite);
		window.draw(sprite2);
		if (arr[i].score < 100)
		{
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Yellow);
			text.setCharacterSize(30);
			text.setPosition(Vector2f(760, 10 + (i * 53.0)));
			window.draw(text);

			text.setString(s[i]);

			text.setCharacterSize(30);
			text.setPosition(Vector2f(920, 10 + (i * 50.0)));
			window.draw(text);
		}
		else if (arr[i].score >= 100)
		{
			arr[i].score = 100;
			window.clear(Color::White);
			text.setString("Congratulations!!");
			text.setFillColor(sf::Color::Blue);
			text.setCharacterSize(70);
			text.setPosition(Vector2f(230, 300));
			window.draw(text);
			text.setString(arr[i].NameOfplayer);
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(250, 370));
			window.draw(text);
			text.setString("  is the winner");
			text.setFillColor(sf::Color::Red);
			text.setCharacterSize(50);
			text.setPosition(Vector2f(430, 370));
			window.draw(text);
			gameover = true;
		}

	}

}
void ONE_PLAYER_Easy() {
	int Playerturn = 0;
	dice.loadFromFile("d.png");
	imdice.setTexture(dice);
	imdice.setPosition(800, 580);
	imdice.setScale(0.3, 0.3);
	srand(time(NULL));
	window.draw(imdice);
	p1.loadFromFile("p1.png");
	ip1.setTexture(p1);
	ip1.setScale(0.08, 0.08);
	window.draw(ip1);

	srand(time(NULL));
	int computer[] = { 1,2,3,4,5,6 };
	int computer_score = 1;
	int comprand;
	Event ev_comp;
	while (window.pollEvent(ev_comp))
	{

		if (ev_comp.type == ev_comp.MouseButtonPressed) {
			if (ev_comp.mouseButton.x >= imdice.getPosition().x && ev_comp.mouseButton.y >= imdice.getPosition().y)
			{
				dise = 1 + rand() % 6;
				buffer.loadFromFile("roll.wav");
				sound.setBuffer(buffer);
				sound.play();
			}
			if (dise == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 460);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);
			}
			else if (dise == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 460);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (dise == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 460);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (dise == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 460);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (dise == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 460);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (dise == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 460);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}
			Number[Playerturn].score += dise;
			if (Number[Playerturn].score == Ladder1) {
				Number[Playerturn].score = 37;
			}
			if (Number[Playerturn].score == Ladder2) {
				Number[Playerturn].score = 30;
			}
			if (Number[Playerturn].score == Ladder3) {
				Number[Playerturn].score = 85;
			}
			if (Number[Playerturn].score == Ladder4) {
				Number[Playerturn].score = 72;
			}
			if (Number[Playerturn].score == Ladder5) {
				Number[Playerturn].score = 100;
			}
			if (Number[Playerturn].score == Snake1) {
				Number[Playerturn].score = 4;
			}
			if (Number[Playerturn].score == Snake2) {
				Number[Playerturn].score = 22;
			}
			if (Number[Playerturn].score == Snake3) {
				Number[Playerturn].score = 32;
			}
			if (Number[Playerturn].score == Snake4) {
				Number[Playerturn].score = 13;
			}
			if (Number[Playerturn].score == Snake5) {
				Number[Playerturn].score = 77;
			}
			if (Number[Playerturn].score == 1) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 640);
				}
			}
			if (Number[Playerturn].score == 2) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 640);
				}

			}
			if (Number[Playerturn].score == 3) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 640);
				}

			}
			if (Number[Playerturn].score == 4) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 640);
				}


			}

			if (Number[Playerturn].score == 5) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 640);
				}


			}

			if (Number[Playerturn].score == 6) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 640);
				}


			}

			if (Number[Playerturn].score == 7) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 640);
				}

			}
			if (Number[Playerturn].score == 8) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 640);
				}

			}

			if (Number[Playerturn].score == 9) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 640);
				}

			}

			if (Number[Playerturn].score == 10) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 640);
				}


			}
			if (Number[Playerturn].score == 11) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 560);
				}

			}

			if (Number[Playerturn].score == 12) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 560);
				}

			}



			if (Number[Playerturn].score == 13) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 560);
				}


			}



			if (Number[Playerturn].score == 14) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 560);
				}

			}
			if (Number[Playerturn].score == 15) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 560);
				}


			}

			if (Number[Playerturn].score == 16) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 560);
				}

			}


			if (Number[Playerturn].score == 17) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 560);
				}

			}

			if (Number[Playerturn].score == 18) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 560);
				}

			}




			if (Number[Playerturn].score == 19) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 560);
				}

			}

			if (Number[Playerturn].score == 20) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 560);
				}

			}
			if (Number[Playerturn].score == 21) {
				if (Playerturn == 0) {
					ip1.setPosition(0, 490);
				}

			}
			if (Number[Playerturn].score == 22) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 490);
				}

			}
			if (Number[Playerturn].score == 23) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 490);
				}

			}
			if (Number[Playerturn].score == 24) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 490);
				}

			}
			if (Number[Playerturn].score == 25) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 490);
				}


			}
			if (Number[Playerturn].score == 26) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 490);
				}

			}
			if (Number[Playerturn].score == 27) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 490);
				}

			}
			if (Number[Playerturn].score == 28) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 490);
				}

			}
			if (Number[Playerturn].score == 29) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 490);
				}

			}
			if (Number[Playerturn].score == 30) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 490);
				}

			}
			if (Number[Playerturn].score == 31) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 420);
				}

			}
			if (Number[Playerturn].score == 32) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 420);
				}

			}
			if (Number[Playerturn].score == 33) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 420);
				}

			}
			if (Number[Playerturn].score == 34) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 420);
				}

			}
			if (Number[Playerturn].score == 35) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 420);
				}

			}
			if (Number[Playerturn].score == 36) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 420);
				}

			}
			if (Number[Playerturn].score == 37) {
				if (Playerturn == 0) {
					ip1.setPosition(210, 420);
				}

			}
			if (Number[Playerturn].score == 38) {
				if (Playerturn == 0) {
					ip1.setPosition(140, 420);
				}

			}
			if (Number[Playerturn].score == 39) {
				if (Playerturn == 0) {
					ip1.setPosition(70, 420);
				}


			}
			if (Number[Playerturn].score == 40) {

				if (Playerturn == 0) {

					ip1.setPosition(0, 420);
				}

			}
			if (Number[Playerturn].score == 41) {
				if (Playerturn == 0) {

					ip1.setPosition(0, 350);
				}

			}
			if (Number[Playerturn].score == 42) {
				if (Playerturn == 0) {

					ip1.setPosition(70, 350);
				}

			}
			if (Number[Playerturn].score == 43) {
				if (Playerturn == 0) {

					ip1.setPosition(140, 350);
				}

			}
			if (Number[Playerturn].score == 44) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 350);
				}


			}
			if (Number[Playerturn].score == 45) {
				if (Playerturn == 0) {
					ip1.setPosition(280, 350);
				}

			}
			if (Number[Playerturn].score == 46) {
				if (Playerturn == 0) {
					ip1.setPosition(350, 350);
				}
			}
			if (Number[Playerturn].score == 47) {
				if (Playerturn == 0) {
					ip1.setPosition(420, 350);
				}
			}
			if (Number[Playerturn].score == 48) {
				if (Playerturn == 0) {
					ip1.setPosition(490, 350);
				}

			}
			if (Number[Playerturn].score == 49) {
				if (Playerturn == 0) {
					ip1.setPosition(560, 350);
				}

			}
			if (Number[Playerturn].score == 50) {
				if (Playerturn == 0) {
					ip1.setPosition(630, 350);
				}


			}
			if (Number[Playerturn].score == 51) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 280);
				}

			}
			if (Number[Playerturn].score == 52) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 280);
				}

			}
			if (Number[Playerturn].score == 53) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 280);
				}

			}
			if (Number[Playerturn].score == 54) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 280);
				}

			}
			if (Number[Playerturn].score == 55) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 280);
				}


			}
			if (Number[Playerturn].score == 56) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 280);
				}

			}
			if (Number[Playerturn].score == 57) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 280);
				}

			}
			if (Number[Playerturn].score == 58) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 280);
				}

			}
			if (Number[Playerturn].score == 59) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 280);
				}

			}
			if (Number[Playerturn].score == 60) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 280);
				}

			}
			if (Number[Playerturn].score == 61) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 210);
				}

			}
			if (Number[Playerturn].score == 62) {

				if (Playerturn == 0) {
					ip1.setPosition(75, 210);
				}

			}

			if (Number[Playerturn].score == 63) {

				if (Playerturn == 0) {
					ip1.setPosition(145, 210);
				}

			}
			if (Number[Playerturn].score == 64) {

				if (Playerturn == 0) {
					ip1.setPosition(215, 210);
				}

			}

			if (Number[Playerturn].score == 65) {

				if (Playerturn == 0) {
					ip1.setPosition(285, 210);
				}

			}
			if (Number[Playerturn].score == 66) {

				if (Playerturn == 0) {
					ip1.setPosition(355, 210);
				}

			}
			if (Number[Playerturn].score == 67) {

				if (Playerturn == 0) {
					ip1.setPosition(425, 210);
				}

			}
			if (Number[Playerturn].score == 68) {

				if (Playerturn == 0) {
					ip1.setPosition(495, 210);
				}

			}
			if (Number[Playerturn].score == 69) {

				if (Playerturn == 0) {
					ip1.setPosition(565, 210);
				}

			}
			if (Number[Playerturn].score == 70) {

				if (Playerturn == 0) {
					ip1.setPosition(635, 210);
				}

			}

			if (Number[Playerturn].score == 71) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 140);
				}

			}
			if (Number[Playerturn].score == 72) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 140);
				}
			}

			if (Number[Playerturn].score == 73) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 140);
				}


			}


			if (Number[Playerturn].score == 74) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 140);
				}


			}
			if (Number[Playerturn].score == 75) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 140);
				}

			}
			if (Number[Playerturn].score == 76) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 140);
				}

			}

			if (Number[Playerturn].score == 77) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 140);
				}

			}

			if (Number[Playerturn].score == 78) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 140);
				}
			}

			if (Number[Playerturn].score == 79) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 140);
				}

			}

			if (Number[Playerturn].score == 80) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 140);
				}
			}

			if (Number[Playerturn].score == 89) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 70);
				}
			}
			if (Number[Playerturn].score == 88) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 70);
				}

			}



			if (Number[Playerturn].score == 87) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 70);
				}

			}

			if (Number[Playerturn].score == 86) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 70);
				}
			}
			if (Number[Playerturn].score == 85) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 70);
				}

			}
			if (Number[Playerturn].score == 84) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 70);
				}
			}
			if (Number[Playerturn].score == 83) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 70);
				}
			}
			if (Number[Playerturn].score == 82) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 70);
				}

			}

			if (Number[Playerturn].score == 81) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 70);
				}


			}
			if (Number[Playerturn].score == 90) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}

			}

			if (Number[Playerturn].score == 100) {

				if (Playerturn == 0) {
					ip1.setPosition(0, 0);
				}

			}
			if (Number[Playerturn].score == 99) {

				if (Playerturn == 0) {
					ip1.setPosition(70, 0);
				}
			}

			if (Number[Playerturn].score == 98) {

				if (Playerturn == 0) {
					ip1.setPosition(140, 0);
				}

			}

			if (Number[Playerturn].score == 97) {

				if (Playerturn == 0) {
					ip1.setPosition(210, 0);
				}

			}

			if (Number[Playerturn].score == 96) {

				if (Playerturn == 0) {
					ip1.setPosition(280, 0);
				}

			}


			if (Number[Playerturn].score == 95) {

				if (Playerturn == 0) {
					ip1.setPosition(350, 0);
				}


			}


			if (Number[Playerturn].score == 94) {

				if (Playerturn == 0) {
					ip1.setPosition(420, 0);
				}

			}


			if (Number[Playerturn].score == 93) {

				if (Playerturn == 0) {
					ip1.setPosition(490, 0);
				}

			}


			if (Number[Playerturn].score == 92) {

				if (Playerturn == 0) {
					ip1.setPosition(560, 0);
				}


			}


			if (Number[Playerturn].score == 91) {

				if (Playerturn == 0) {
					ip1.setPosition(630, 0);
				}
			}
			cout << "dice  " << dise << endl;
			cout << "Player  "
				<< Playerturn << "\t " << "PLace: " << Number[Playerturn].score << "   " << endl;
			Sleep(100);
			comprand = computer[rand() % 6];
			buffer.loadFromFile("roll.wav");
			sound.setBuffer(buffer);
			sound.play();
			if (comprand == 1) {
				dice1.loadFromFile("d1.png");
				imdice1.setTexture(dice1);
				imdice1.setPosition(850, 260);
				imdice1.setScale(0.2, 0.2);
				window.draw(imdice1);
			}
			else if (comprand == 2) {
				dice2.loadFromFile("d2.png");
				imdice2.setTexture(dice2);
				imdice2.setPosition(850, 260);
				imdice2.setScale(0.2, 0.2);
				window.draw(imdice2);
			}
			else if (comprand == 3) {
				dice3.loadFromFile("d3.png");
				imdice3.setTexture(dice3);
				imdice3.setPosition(850, 260);
				imdice3.setScale(0.2, 0.2);
				window.draw(imdice3);
			}
			else if (comprand == 4) {
				dice4.loadFromFile("d4.png");
				imdice4.setTexture(dice4);
				imdice4.setPosition(850, 260);
				imdice4.setScale(0.2, 0.2);
				window.draw(imdice4);
			}
			else if (comprand == 5) {
				dice5.loadFromFile("d5.png");
				imdice5.setTexture(dice5);
				imdice5.setPosition(850, 260);
				imdice5.setScale(0.2, 0.2);
				window.draw(imdice5);
			}
			else if (comprand == 6) {
				dice6.loadFromFile("d6.png");
				imdice6.setTexture(dice6);
				imdice6.setPosition(850, 260);
				imdice6.setScale(0.2, 0.2);
				window.draw(imdice6);
			}
			computer_score += comprand;

			if (computer_score == Ladder1) {
				computer_score = 37;
			}
			if (computer_score == Ladder2) {
				computer_score = 30;
			}
			if (computer_score == Ladder3) {
				computer_score = 85;
			}
			if (computer_score == Ladder4) {
				computer_score = 72;
			}
			if (computer_score == Ladder5) {
				computer_score = 100;
			}
			if (computer_score == Snake1) {
				computer_score = 4;
			}
			if (computer_score == Snake2) {
				computer_score = 22;
			}
			if (computer_score == Snake3) {
				computer_score = 32;
			}
			if (computer_score == Snake4) {
				computer_score = 13;
			}
			if (computer_score == Snake5) {
				computer_score = 77;
			}
			scoreBoard_Comp(computer_score);
		}

	}

}
