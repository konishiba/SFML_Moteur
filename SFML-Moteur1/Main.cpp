#include <iostream>
#include "TimerManager.h"
#include "Game.h"

using namespace std;

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
}

int main()
{
    InitConfig();
    shared_ptr<Game> _game = make_shared<Game>();

    TimerManager::GetInstance().SetTimer(true, 1.0f, false, [&]() { cout << "pd" << endl; });

    _game.get()->Start();

	return 0;
}