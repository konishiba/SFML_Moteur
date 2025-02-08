#include "Game.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
    InitConfig();
    shared_ptr<Game> _game = make_shared<Game>();

    _game.get()->Start();

    _game.reset();
	return 0;
}