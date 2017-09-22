#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

#define ANDY_X_POSITION 0
#define ANDY_Y_POSITION 0
#define MAX_POWER 100
#define GRAVITY 9.8
#define MENU 4

class AndyBirds
{
	public:
		AndyBirds ();
		~AndyBirds ();

		void createBackground (sf::RenderWindow &window, string fileName);
		void createObstacles (sf::RenderWindow &window, int posX, int posY);
		void moveObstacles (sf::RenderWindow &window);
		void createAndy (sf::RenderWindow &window);
		void moveAndy (sf::RenderWindow &window);
		void createAndyBoss (sf::RenderWindow &window);
		void moveAndyBoss (sf::RenderWindow &window);
		bool checkForIntersections (sf::RenderWindow &window);
		void displayAttempts (sf::RenderWindow &window);
		void mainMenu ();
		void howToPlay();
		void runGame ();

		//josh's functions
		void emitSound(string fileName);

	private:
		//constants
		static const int APPLET_WIDTH = 1280;
		static const int APPLET_HEIGHT = 720;
		static const int ANDY_HEIGHT = 80;
		static const int ANDY_WIDTH = 95;
		static const int PIPE_HEIGHT = 200;
		static const int TOP_PIPE_BOUNDARY= -500;
		static const int BOTTOM_PIPE_BOUNDARY = 850;
		static const int TOP_HEAD_BOUNDARY = 250; // lower the number = greater the gap
		static const int HEAD_HEIGHT = 218;

		// textures and sprites for the bottom
		// and top pipes
		sf::Texture bottomPipeTexture;
		sf::Sprite bottomPipe[5];
		sf::Texture topPipeTexture;
		sf::Sprite topPipe[5];

		int counter;
		int attempts;

		// texture and sprite for the Andy character
		sf::Texture andyTexture;
		sf::Sprite andySprite;

		// texture and sprite for the Andy boss
		sf::Texture andyHeadTexture;
		sf::Sprite andyHeadSprite;

		sf::Texture andyBodyTexture;
		sf::Sprite andyBodySprite;

		sf::Texture andyBodyRightTexture;
		sf::Sprite andyBodyRightSprite;

		//sound buffer and sounds 
		sf::SoundBuffer buffer;
		sf::Sound sound;
		sf::Music gameMusic;

		sf::Text attemptCounter;
		sf::Font attemptFont;
		string attemptString;

		// variable for head movement
		float headVertical;

		bool andyIsFlying;
		float fakeGravity;

		// variables for pipe movement
		float topPipeVeritcal[5];
		float bottomPipeVeritcal[5];
};
