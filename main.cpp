#include <SFML/Graphics.hpp>

int main() {

	const int fieldWidth = 10;
	const int fieldHeight = 20;

	enum class Type {
		None,
		O,
		I,
		L,
		J,
		Z,
		N,
		T,

	};
	//field mark
	Type field[fieldWidth][fieldHeight] = {};

	sf::Texture backgroundTexture;
	if (!backgroundTexture.loadFromFile("background.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture yellowTexture;
	if (!yellowTexture.loadFromFile("yellow.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture lightBlueTexture;
	if (!lightBlueTexture.loadFromFile("light_blue.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture orangeTexture;
	if (!orangeTexture.loadFromFile("orange.png")) {
		return EXIT_FAILURE;
	}

	sf::Texture blueTexture;
	if (!blueTexture.loadFromFile("blue.png")) {
		return EXIT_FAILURE;
	}
	sf::Texture purpleTexture;
	if (!purpleTexture.loadFromFile("purple.png")) {
		return EXIT_FAILURE;
	}
	sf::Texture greenTexture;
	if (!greenTexture.loadFromFile("green.png")) {
		return EXIT_FAILURE;
	}
	sf::Texture redTexture;
	if (!redTexture.loadFromFile("red.png")) {
		return EXIT_FAILURE;
	}
	std::map<Type, std::vector<std::vector<sf::Vector2i>>> shapes = {
		{
			Type::O,
			{
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				sf::Vector2i(0, -1),
				sf::Vector2i(1, -1),
				}

			},
		},
		{
			Type::I,					
			{
				// shpae_Is[0] oooo
				{
					sf::Vector2i(-1, 0),
					sf::Vector2i(0, 0),
					sf::Vector2i(1, 0),
					sf::Vector2i(2, 0),
				},
				// shpae_Is[1] 
				{
				sf::Vector2i(0, -2),
				sf::Vector2i(0, -1),
				sf::Vector2i(0,  0),
				sf::Vector2i(0,  1),
				},
			},
	    },
		{
			Type::L,
			{	
				//        O				 (0,-1)
				//    O O O (-2,0) (-1,0) (0,0)
				//  
				{
				sf::Vector2i(-2, 0),
				sf::Vector2i(-1, 0),
				sf::Vector2i( 0, 0),
				sf::Vector2i( 0,-1),
				},
				//L :	o	(0,-2)
				//		o	(0,-1)
				//		oo  (0, 0) (1,0)
				//
				{
				sf::Vector2i(0, -2),
				sf::Vector2i(0, -1),
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				},
				// o o o  (0,0) (1,0) (2,0)
 				// o      (0, 1)
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				sf::Vector2i(2, 0),
				sf::Vector2i(0, 1),
				},
				//  o o   (-1,0)(0,0)
				//	  o			(0,1)
				//	  o			(0,2)
				{
				sf::Vector2i(-1, 0),
				sf::Vector2i(0, 0),
				sf::Vector2i(0, 1),
				sf::Vector2i(0, 2),
				},

			},
		},
		{
			Type::J,
			{
			// o		 (0,-1)
			// o  o  o   (0,0) (1,0) (2,0)
				{
				sf::Vector2i(0,-1),
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				sf::Vector2i(2, 0),
				},
				//  o o
				//  o
				//  o
				{
				sf::Vector2i(0,0),
				sf::Vector2i(1, 0),
				sf::Vector2i(0, 1),
				sf::Vector2i(0, 2),
				},
				//  o o o
				//		o
				{
				sf::Vector2i(0,0),
				sf::Vector2i(-1, 0),
				sf::Vector2i(-2, 0),
				sf::Vector2i(0, 1),
				},
				//	  o
				//	  o
				//  o o
				{
				sf::Vector2i(0,0),
				sf::Vector2i(0, -1),
				sf::Vector2i(0, -2),
				sf::Vector2i(-1, 0),
				},

			},
		},
		{
			Type::Z,
			{
				//  o o
				//    o o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(0, -1),
				sf::Vector2i(-1, -1),
				sf::Vector2i(1, 0),
				},
				//     o
				//   o o
				//   o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(0, -1),
				sf::Vector2i(-1, 0),
				sf::Vector2i(-1, 1),
				}

			},
		},
		{
			Type::N,
			{
				//		o o
				//    o o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(0, -1),
				sf::Vector2i(1, -1),
				sf::Vector2i(-1, 0),
				},
				//   o
				//   o o
				//     o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(-1, 0),
				sf::Vector2i(-1, -1),
				sf::Vector2i(0, 1),
				}

			},
		},
		{
			Type::T,
			{
				//	   o
				//   o o o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				sf::Vector2i(-1, 0),
				sf::Vector2i(0, -1),
				},
				//	   o
				//	   o o
				//     o 
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				sf::Vector2i(0, 1),
				sf::Vector2i(0, -1),
				},
				//   o  o  o
				//		o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(1, 0),
				sf::Vector2i(-1, 0),
				sf::Vector2i(0, 1),
				},
				//       o
				//     o o
				//       o
				{
				sf::Vector2i(0, 0),
				sf::Vector2i(0, -1),
				sf::Vector2i(0, 1),
				sf::Vector2i(-1, 0),
				},

			},
		},
	};
	Type currentType = Type(rand() % 7+ 1 );
	int currentIndex = 0;


	const int blockWidth = yellowTexture.getSize().x;
	const int blockHeight = yellowTexture.getSize().y;

	const int windowWidth = blockWidth * fieldWidth;
	const int windowHeight = blockHeight * fieldHeight;

	std::map<Type, sf::Sprite> sprites = {
		{Type::O, sf::Sprite(yellowTexture)},
		{Type::I, sf::Sprite(lightBlueTexture)},
		{Type::L, sf::Sprite(orangeTexture)},
		{Type::J, sf::Sprite(blueTexture)},
		{Type::Z, sf::Sprite(purpleTexture)},
		{Type::N, sf::Sprite(greenTexture)},
		{Type::T, sf::Sprite(redTexture)},
	};
	backgroundTexture.setRepeated(true);
	sf::Sprite backgroundSprite(backgroundTexture, sf::IntRect(0,0,windowWidth,windowHeight));  //(,x) => given size

	std::vector<sf::Vector2i> currentShape;
	sf::Sprite currentSprite;

	const sf::Vector2i origin(fieldWidth / 2, 0);
	sf::Vector2i pos(origin);

	sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Tetris");
	
	sf::Clock clock;
	
	
	while (window.isOpen()) {	

		currentShape = shapes[currentType][currentIndex];
		currentSprite = sprites[currentType];
		
		enum class Action {
			Hold,
			MoveDown,
			MoveLeft,
			MoveRight,
			Rotate,
			Drop,
		};
		Action action = Action::Hold;

		sf::Event evt;
		if (window.pollEvent(evt)) {
			if (evt.type == sf::Event::Closed) {
				window.close();
			}
			if (evt.type == sf::Event::KeyPressed) {
				switch (evt.key.code) {
				case sf::Keyboard::Left:
					action = Action::MoveLeft;
					break;
				case sf::Keyboard::Right:
					action = Action::MoveRight;
					break;
				case sf::Keyboard::Up:
					action = Action::Rotate;
					break;
				case sf::Keyboard::Space:
					action = Action::Drop;
					break;
				}
			}
		}
		// collision detect
		
		if (clock.getElapsedTime().asSeconds() >= 0.1f) {
			action = Action::MoveDown;
			clock.restart();
		}

		sf::Vector2i nextPos(pos);
		int nextIndex = currentIndex;
		if (action == Action::Rotate) {
			// 0=> 1 =>0 =>1 ...
			nextIndex = (nextIndex + 1) % shapes[currentType].size();
		}
		std::vector<sf::Vector2i> nextShape = shapes[currentType][nextIndex];


		switch (action) {
		case Action::Hold:
			break;
		case Action::MoveDown:
			nextPos.y++;
			break;
		case Action ::MoveLeft:
			nextPos.x--;
			break;
		case Action ::MoveRight:
			nextPos.x++;
			break;
		case Action::Drop:
			while (nextPos.y > 0) {
				if (nextPos.y = 20) {
					break;
				}
				nextPos.y++;
			}
		}
		int countEmpty = 0;
		for (const sf::Vector2i d : nextShape) {
			sf::Vector2i np = nextPos + d;
			bool isEmpty = false;
			if (np.x >= 0 && np.x < fieldWidth && np.y < fieldHeight && (np.y<0 || field[np.x][np.y] == Type::None)) {
				countEmpty++;
			}

		}

		if (countEmpty == 4) {
			pos = nextPos;
			currentIndex = nextIndex;
			currentShape = nextShape;
		}
		else {
			if (action == Action::MoveDown) {
				for (const sf::Vector2i& d : currentShape) {
					sf::Vector2i np = pos + d;
					if (np.y >= 0) {
						field[np.x][np.y] = currentType;
					}
				}
				
				//check each line
				for (int y = 0; y < fieldHeight; y++) {
					bool isFull = true;
					for (int x = 0; x < fieldWidth; x++) {
						if (field[x][y] == Type::None) {
							isFull = false;
						}
					}
					if (isFull) {
						for (int ty = y; ty > 0; ty--) {
							for (int x = 0; x < fieldWidth; x++) {
								field[x][ty] = field[x][ty - 1]; //previous line copies to next line
							}
						}
						for (int x = 0; x < fieldWidth; x++) {
							field[x][0] = Type::None;
						}
					}
				}
				pos = origin;
				//after block touches the bottom change the shape randomly
				currentType = Type(rand() %7 +1 );
				currentIndex = 0;
			}
		
		}
		
		window.clear();
		window.draw(backgroundSprite);

		// draw background field
		for (int x = 0; x < fieldWidth; x++) {
			for (int y = 0; y < fieldHeight; y++) {
				if (field[x][y] == Type::None) continue;

				sf::Sprite& s = sprites[field[x][y]];

				s.setPosition(float(x* blockWidth), float(y* blockHeight));
				window.draw(s);
					
				
			}
		}
		// draw the controling object
		for (const sf::Vector2i& d : currentShape) {
			sf::Vector2i np = pos + d;
			currentSprite.setPosition(float(np.x* blockWidth), float(np.y* blockHeight));
			window.draw(currentSprite);
		}
		
		window.display();

	}
	return EXIT_SUCCESS;
}