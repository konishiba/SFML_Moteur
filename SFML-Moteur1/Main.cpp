#include "Game.h"

#include "Actor.h"
#include "RootComponent.h"

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

    //Actor _ac = Actor();
    //shared_ptr<RootComponent> _root = make_shared<RootComponent>();

    //_ac.AddComponent(_root);

    //shared_ptr<RootComponent> _pd = _ac.GetComponent<RootComponent>();


	return 0;
}