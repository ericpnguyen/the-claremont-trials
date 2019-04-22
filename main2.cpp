#include "GameManager.hpp"

int main(int argc, char* argv[]) {

	GameManager* game = GameManager::Instance();

	game->Run();

	GameManager::Release();
	game = NULL;

	return 0;
}