#include "Game.h"
#include "CoreMinimal.h"
#include "RootComponent.h"
#include "Actor.h"

Game::Game()
{
    window = RenderWindow();
}

void Game::Start()
{
    window.create(VideoMode({ 800, 400 }), "Angry");
    
    M_TIMER.SetTimer(true, 0.5f, false, [&]() {cout << "PD" << endl; },"test PD timer");

    InitGarbageCollector();

    Update();
}

void Game::InitGarbageCollector()
{
    GarbageCollector* _GC = &GarbageCollector::GetInstance();
    M_TIMER.SetTimer(true, 2.0f, true, [_GC]() {_GC->DestroyGarbages(); });
}

bool Game::Update()
{
    while (!IsOver())
    {
        while (const optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                window.close();
            }
        }       
        TimerManager::GetInstance().Update();
        UpdateWindow();
    }

    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear(Color::Black);
    DrawElement();
    //window.draw();
    window.display();
}

void Game::DrawElement()
{
    set<shared_ptr<Actor>> _actors = M_ACTOR.GetAllActors();

    for (shared_ptr<Actor> _actor : _actors)
    {
        shared_ptr<RootComponent> _root = _actor->GetComponent<RootComponent>();
        if (!_root) continue;

        window.draw(*_root->GetShape());
    }
}

void Game::Stop()
{
    
}

