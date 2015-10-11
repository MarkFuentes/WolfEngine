#include "MainGame.h"

MainGame::MainGame() :
	_windowWIDTH(800),
	_windowHeight(600),
	_gameState(GameState::PLAY),
	_maxFPS(120.0f)
{
	_colorProgram = new WolfEngine::GLSLProgram();
	_camera.init(_windowWIDTH, _windowHeight);
}


MainGame::~MainGame()
{
}

void MainGame::Run()
{
	initSystems();

	gameLoop();
}

void MainGame::initSystems()
{
	WolfEngine::Init();
	_window.create("Wolf Engine", _windowWIDTH, _windowHeight, 0);
	initShaders();
	_spriteBatch.init();
	_fpsLimiter.init(_maxFPS);

	pos = glm::vec4(0.0f, 0.0f, 50.0f, 50.0f);
	uv = glm::vec4(0.0f, 0.0f, 1.0f, 1.0f);
	posDelta = glm::vec4(0.5f, 0.0f, 0.0f, 0.0f);
	texture = WolfEngine::ResourceManager::getTexture("Textures/vader.png");
	color._red = 255;
	color._green = 255;
	color._blue = 255;
	color._alpha = 255;
}

void MainGame::gameLoop()
{
	while (_gameState != GameState::EXIT) {

		_fpsLimiter.begin();

		processInput();
		_camera.update();
		drawGame();

		_fps = _fpsLimiter.end();

		static int frameCounter = 0;
		frameCounter++;
		if (frameCounter == 10) {
			std::cout << _fps << std::endl;
			frameCounter = 0;
		}

	}
}

void MainGame::processInput()
{
	SDL_Event evt;
	const float CAMERA_SPEED = 2.0f;
	const float SCALE_SPEED = 0.1f;
	while (SDL_PollEvent(&evt))
	{
		switch (evt.type)
		{
		case SDL_JOYBUTTONDOWN:
			//std::cout << "Controller" << std::endl;
			break;
		case SDL_MOUSEMOTION:
			//std::cout << "Mouse x:" << evt.motion.x << "Mouse y:" << evt.motion.y << std::endl;
			break;
		case SDL_QUIT:
			_gameState = GameState::EXIT;
			break;
		case SDL_KEYDOWN:
			_inputManager.pressKey(evt.key.keysym.sym);
			break;
		case SDL_KEYUP:
			_inputManager.releaseKey(evt.key.keysym.sym);
			break;
		default:
			break;
		}
	}
	if (_inputManager.isKeyPressed(SDLK_w))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, CAMERA_SPEED));
	}
	if (_inputManager.isKeyPressed(SDLK_s))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(0.0f, -CAMERA_SPEED));
	}
	if (_inputManager.isKeyPressed(SDLK_a))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(-CAMERA_SPEED, 0.0f));
	}
	if (_inputManager.isKeyPressed(SDLK_d))
	{
		_camera.setPosition(_camera.getPosition() + glm::vec2(CAMERA_SPEED, 0.0f));
	}
	if (_inputManager.isKeyPressed(SDLK_q))
	{
		_camera.setScale(_camera.getScale() + SCALE_SPEED);
	}
	if (_inputManager.isKeyPressed(SDLK_e))
	{
		_camera.setScale(_camera.getScale() - SCALE_SPEED);
	}
}

void MainGame::drawGame()
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	_colorProgram->use();

	glActiveTexture(GL_TEXTURE0);

	GLint textureLocation = _colorProgram->getUniformLocation("mySampler");
	glUniform1i(textureLocation, 0);

	GLint pLocation = _colorProgram->getUniformLocation("P");
	glm::mat4 cameraMatrix = _camera.getCameraMatrix();

	glUniformMatrix4fv(pLocation, 1, GL_FALSE, &(cameraMatrix[0][0]));


	_spriteBatch.begin();

	pos += posDelta;

	_spriteBatch.draw(pos, uv, texture.id, 0.0f, color);

	_spriteBatch.end();

	_spriteBatch.renderBatch();

	glBindTexture(GL_TEXTURE_2D, 0);

	_colorProgram->unuse();
	_window.Swap();
}

void MainGame::initShaders()
{
	_colorProgram->compileShaders("Shaders/colorShading.vert", "Shaders/colorShading.frag");
	_colorProgram->addAttribute("vertexPosition");
	_colorProgram->addAttribute("vertexColor");
	_colorProgram->addAttribute("vertexUV");
	_colorProgram->linkShaders();
}


