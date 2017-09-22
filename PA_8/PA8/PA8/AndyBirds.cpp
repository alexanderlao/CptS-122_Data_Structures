#include "AndyBirds.h"

AndyBirds::AndyBirds ()
{
	andyIsFlying = false;
	fakeGravity = 0;
	headVertical = 20;
	counter = 0;
	attempts = 0;

	for (int i = 0; i <= 5; i++)
	{
		topPipeVeritcal[i] = i + 5;
		bottomPipeVeritcal[i] = i + 5;
	}

	attemptFont.loadFromFile ("arial.ttf");
	attemptCounter.setFont (attemptFont);
	attemptCounter.setCharacterSize (100);
	attemptCounter.setPosition (10, -10);
	attemptCounter.setColor (sf::Color::Red);
}

AndyBirds::~AndyBirds ()
{

}

void AndyBirds::createBackground (sf::RenderWindow &window, string fileName)
{
	sf::Texture backgroundImage;
	sf::Sprite background;

	// load the background image as a texture and set it as the texture
	// of the background sprite
	backgroundImage.loadFromFile (fileName);
	background.setTexture (backgroundImage);

	// set the background at the orgin
	background.setPosition (0, 0);

	window.draw (background);
}

void AndyBirds::createObstacles (sf::RenderWindow &window, int posX, int posY)
{
	// load the textures from the files
	bottomPipeTexture.loadFromFile ("bottomPipe.png");
	topPipeTexture.loadFromFile ("topPipe.png");

	// set the textures to the sprites and set their positions
	bottomPipe[counter].setTexture(bottomPipeTexture);
	bottomPipe[counter].setPosition (posX, posY);

	topPipe[counter].setTexture(topPipeTexture);
	topPipe[counter].setPosition (posX, -posY);
}

void AndyBirds::moveObstacles (sf::RenderWindow &window)
{
	for (int i = 0; i <= counter; i++)
	{
		// check for boundaries for the pipes
		// to determine when to move back down or back up
		if ((topPipe[i].getPosition ().y) <= TOP_PIPE_BOUNDARY) // to move down
		{
			topPipeVeritcal[i] = 5;
			bottomPipeVeritcal[i] = 5;
		}
		else if ((bottomPipe[i].getPosition ().y + PIPE_HEIGHT) >= BOTTOM_PIPE_BOUNDARY) // to move up
		{
			topPipeVeritcal[i] = -5;
			bottomPipeVeritcal[i] = -5;
		}

		// move the pipes
		topPipe[i].move (0, topPipeVeritcal[i]);
		bottomPipe[i].move (0, bottomPipeVeritcal[i]);
	

		window.draw (bottomPipe[i]);
		window.draw (topPipe[i]);
	}
}

void AndyBirds::createAndy (sf::RenderWindow &window)
{
	andyTexture.loadFromFile ("andyHead.png");

	andySprite.setOrigin ((ANDY_HEIGHT / 2), (ANDY_WIDTH / 2)); 
	andySprite.setTexture(andyTexture);
	andySprite.setPosition(100, APPLET_HEIGHT - 100);
}

void AndyBirds::moveAndy (sf::RenderWindow &window)
{
	double velocity = 0;//change value,until space bar is hit
	double theta = 0;//change value,until space bar is hit
	double v_x = 0;
	double v_y = 0;
	double distance = 0;

	sf::Clock clock;
	float speed = 1000.f ;
	
	int num_of_andy = 10;//ten andy
	
		// Get elapsed time
		float delta = 0.8f * clock.restart().asSeconds();

		sf::Event andyEvent;
		while (window.pollEvent(andyEvent))
		{
			switch (andyEvent.type)
			{
			case sf::Event::KeyPressed:
				if (sf::Keyboard::isKeyPressed (sf::Keyboard::Space))
				{
					andyIsFlying = true;
				}
				if (sf::Keyboard::isKeyPressed (sf::Keyboard::Q))
				{//initialize.
					andyIsFlying = false;

					fakeGravity = 0;
					andySprite.setPosition(0, APPLET_HEIGHT);
					//num_of_andy--;
				}
				if(sf::Mouse::isButtonPressed(sf::Mouse::Left));
				while(0) //mouse drag n release
				{
					v_x = velocity * cos(theta);
					v_y = velocity * sin(theta);
				}
			case sf::Event::KeyReleased:
				if (sf::Keyboard::isKeyPressed (sf::Keyboard::Space))
				{
					andyIsFlying = true;
				}
			}
		}

		if (andyIsFlying)
		{
			fakeGravity += 0.5;

			andySprite.move (20, -17 + fakeGravity);
			andySprite.rotate (15);
		}
		
		window.draw (andySprite);
}

void AndyBirds::createAndyBoss (sf::RenderWindow &window)
{
	// load the textures
	andyHeadTexture.loadFromFile ("andyBossHead.png");
	andyBodyTexture.loadFromFile ("andyBossBody.png");
	andyBodyRightTexture.loadFromFile ("andyBossBodyRight.png");

	// set the textures to the sprite
	andyHeadSprite.setTexture (andyHeadTexture);
	andyBodySprite.setTexture (andyBodyTexture); 
	andyBodyRightSprite.setTexture (andyBodyRightTexture); 

	// set starting positions
	andyHeadSprite.setPosition (APPLET_WIDTH - 67, 400);
	andyBodySprite.setPosition (APPLET_WIDTH - 500, 400);
	andyBodyRightSprite.setPosition (APPLET_WIDTH - 387, 400); 

	// set the orgin of Andy's head to the bottom right
	// (Andy's head sprite is 341 x 218 pixels)
	andyHeadSprite.setOrigin (341, 218);
}

void AndyBirds::moveAndyBoss (sf::RenderWindow &window)
{
	// check for boundaries for the head
	// to determine when to move back down or back up
	if ((andyHeadSprite.getPosition ().y) <= TOP_HEAD_BOUNDARY) // to move down
	{
		headVertical = 5;
	}
	else if (andyHeadSprite.getGlobalBounds ().intersects (andyBodySprite.getGlobalBounds())) // to move up
	{
		headVertical = -5;
	}

	andyHeadSprite.move (0, headVertical);

	window.draw (andyBodySprite);
	window.draw (andyHeadSprite);
	window.draw (andyBodyRightSprite);
}

bool AndyBirds::checkForIntersections (sf::RenderWindow &window)
{
	bool didIntersect = false;

	for (int i = 0; i <= counter; i++)
	{
		// checking for intersections
		if (andySprite.getGlobalBounds ().intersects (topPipe[i].getGlobalBounds ()) ||
			andySprite.getGlobalBounds ().intersects (bottomPipe[i].getGlobalBounds ()) ||
			andySprite.getPosition ().x >= APPLET_WIDTH ||
			andySprite.getPosition ().y >= APPLET_HEIGHT)
		{
			didIntersect = true;
			andyIsFlying = false;
			fakeGravity = 0;
			attempts++;

			emitSound("andy_laughter.wav");

			// reset the postion back to the beginning
			andySprite.setPosition(100, APPLET_HEIGHT - 100);
		}
		else if (andySprite.getGlobalBounds ().intersects (andyHeadSprite.getGlobalBounds ()) &&
				 andySprite.getGlobalBounds ().intersects (andyBodyRightSprite.getGlobalBounds ()))
		{
			emitSound ("yeahYeahYeah.wav");
			andyIsFlying = false;
			fakeGravity = 0;
			counter++;
			attempts++;

			if (counter == 1)
			{
				createObstacles (window, (APPLET_WIDTH - 1000), 500);
				createObstacles (window, (APPLET_WIDTH - 900), 475);
			}
			else if (counter == 2)
			{
				createObstacles (window, (APPLET_WIDTH - 1000), 500);
				createObstacles (window, (APPLET_WIDTH - 900), 475);
				createObstacles (window, (APPLET_WIDTH - 800), 450);
			}
			else if (counter == 3)
			{
				createObstacles (window, (APPLET_WIDTH - 1000), 500);
				createObstacles (window, (APPLET_WIDTH - 900), 475);
				createObstacles (window, (APPLET_WIDTH - 800), 450);
				createObstacles (window, (APPLET_WIDTH - 700), 425);
			}
			else if (counter == 4)
			{
				createObstacles (window, (APPLET_WIDTH - 1000), 500);
				createObstacles (window, (APPLET_WIDTH - 900), 475);
				createObstacles (window, (APPLET_WIDTH - 800), 450);
				createObstacles (window, (APPLET_WIDTH - 700), 425);
				createObstacles (window, (APPLET_WIDTH - 600), 400);
			}

			// reset the postion back to the beginning
			andySprite.setPosition(100, APPLET_HEIGHT - 100);
		}
	}

	return didIntersect;
}

void AndyBirds::displayAttempts (sf::RenderWindow &window)
{
	attemptString = to_string (attempts);
	attemptCounter.setString (attemptString);

	window.draw (attemptCounter);
}

//josh's sound fuction
void AndyBirds::emitSound(string fileName)
{
	if(!buffer.loadFromFile(fileName))
	{
		cout << "Could not open " << fileName << "!" << endl;
	}
	else
	{
		sound.setBuffer(buffer);
		sound.play();
	}
}

void AndyBirds::mainMenu ()
{
	//tracker for hilighed menu piece
	int whereAt = 0;

	sf::Music music;
	if (!music.openFromFile("Let Go.wav"))
		cout << "didnt load" << endl;
	//return -1;
	music.setVolume(50);
	music.play();

	sf::RenderWindow window(sf::VideoMode(APPLET_WIDTH, APPLET_HEIGHT), "Andy Birds Main Menu");

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")){
	}

	sf::Text title;
	title.setFont(font);
	title.setColor(sf::Color::White);
	title.setScale(3.9f,3.9f);
	title.setStyle(sf::Text::Bold);
	title.setString("Andy Birds The Game!");

	sf::Text text[MENU];
	for (int i = 0; i < 4; i++){
		text[i].setFont(font);
		text[i].setColor(sf::Color::Cyan);
		text[i].setStyle(sf::Text::Bold);
	}
	text[0].setString("Play");
	text[0].setPosition(640.f - 30, 390.f - 218.5);
	text[0].setColor(sf::Color::White);

	text[1].setString("How to play");
	text[1].setPosition(640.f - 75, 390.f - 118.5);

	text[2].setString("Multiplayer");
	text[2].setPosition(640.f - 70, 390.f - 18.5);

	text[3].setString("Exit");
	text[3].setPosition(640.f - 30, 390.f + 81.5);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					//updates position of whereAt in menu

					if (whereAt <= 0){}
					else{
						text[whereAt].setColor(sf::Color::Cyan);
						whereAt--;
						text[whereAt].setColor(sf::Color::White);
					}
					break;
				case sf::Keyboard::Down:
					//updates position of whereAt in menu
					if (whereAt + 1 >= MENU){}
					else{
						text[whereAt].setColor(sf::Color::Cyan);
						whereAt++;
						text[whereAt].setColor(sf::Color::White);
					}
					break;
				case sf::Keyboard::Return: // or Space
					cout << "Enter" << endl;
					//go to said action
					if (whereAt == 0){
						//play
						music.stop();
						runGame ();
					}
					else if (whereAt == 1){
						//how to play
						howToPlay();
					}
					else if (whereAt == 2){
						//multiplayer
					}
					else
						//exit or credits
						exit(0);
					break;
				}
				cout << "whereAt " << whereAt << endl;
			}

			window.clear();
			createBackground (window, "nightBackground.jpg");
			window.draw(title);
			window.draw(text[0]);
			window.draw(text[1]);
			window.draw(text[2]);
			window.draw(text[3]);

			window.display();
		}
	}
}

void AndyBirds::howToPlay(){

	sf::RenderWindow window(sf::VideoMode(APPLET_WIDTH, APPLET_HEIGHT), "How To Play!");

	sf::Font font;
	if (!font.loadFromFile("arial.ttf")){
	}
	sf::Color boble(120, 0, 0, 2);
	sf::Text text;
	text.setFont(font);
	text.setColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);

	while (window.isOpen()){

		sf::Event event2;
		while (window.pollEvent(event2)){
			switch (event2.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				switch (event2.key.code)
				{
				case sf::Keyboard::Escape:
					return;
				}
			}
		}

		window.clear();
		createBackground (window, "nightBackground.jpg");

		text.setString("Objective: FEED ANDY!!!!");
		text.setPosition(680.f / 2, 100.f);
		window.draw(text);

		text.setString("1. Use the spacebar (SPACE!!)\n\t to make Andy Fly.");
		text.setPosition(680.f / 2, 200.f);
		window.draw(text);

		text.setString("2. Launch the little head into\n\t the big head the least amount of time.");
		text.setPosition(680.f / 2, 300.f);
		window.draw(text);

		text.setString("3. There are 5 levels.");
		text.setPosition(680.f / 2, 400.f);
		window.draw(text);

		text.setString("4. And Have A Blast!");
		text.setPosition(680.f / 2, 480.f);
		window.draw(text);

		window.display();
	}

}

void AndyBirds::runGame ()
{
	// create the applet window and set the framerate
	sf::RenderWindow window(sf::VideoMode(APPLET_WIDTH, APPLET_HEIGHT), "Andy Birds");
	window.setFramerateLimit (120);

	gameMusic.openFromFile("gameMusic.wav");
	gameMusic.setVolume(65);
	gameMusic.play();

	createAndy (window);
	createAndyBoss (window);

	// create the first set of obstacles
	createObstacles (window, (APPLET_WIDTH - 1000), 500);

	while (window.isOpen ())
	{
		sf::Event event;
        while (window.pollEvent(event))
        {
			switch (event.type)
			{
			case sf::Event::Closed:
				window.close ();
				break;
			}
		}

		window.clear ();

		createBackground (window, "background.png");
		displayAttempts (window);
		moveObstacles (window);
		moveAndy (window);
		moveAndyBoss (window);
		checkForIntersections (window);

		if (counter == 5)
		{
			cout << "YOU WIN!" << endl;
			cout << "Attempts: " << attempts << endl;
			gameMusic.stop ();
			emitSound ("yeahEndGame.ogg");
			break;
		}

		window.display ();
	}
}