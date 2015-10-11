#pragma once
#include <WolfEngine\WolfEngine.h>
#include <WolfEngine\Sprite.h>
#include <WolfEngine\GLSLProgram.h>
#include <WolfEngine\ErrorHelper.h>
#include <WolfEngine\GLTexture.h>
#include <WolfEngine\ImageLoader.h>
#include <WolfEngine\Window.h>
#include <WolfEngine\Camera2D.h>
#include <WolfEngine\SpriteBatch.h>
#include <WolfEngine\ResourceManager.h>
#include <WolfEngine\Timing.h>
#include <WolfEngine\InputManager.h>
#include <string>
#include <SDL\SDL.h>
#include <GL\glew.h>
#include <iostream>
#include <vector>
enum class GameState {PLAY,EXIT};
class MainGame
{
public:
	MainGame();
	~MainGame();
	void Run();
	void initSystems();
	void gameLoop();
	void processInput();
	void drawGame();
	void initShaders();
private:
	int _windowWIDTH;
	int _windowHeight;
	float _fps;
	float _maxFPS;
	float _frameTime;
	WolfEngine::Window _window;
	WolfEngine::GLSLProgram* _colorProgram;
	WolfEngine::Camera2D _camera;
	WolfEngine::SpriteBatch _spriteBatch;
	WolfEngine::Timing _fpsLimiter;
	WolfEngine::InputManager _inputManager;

	WolfEngine::GLTexture texture;
	WolfEngine::Color color;
	glm::vec4 pos;
	glm::vec4 uv;
	glm::vec4 posDelta;

	GameState _gameState;

};

