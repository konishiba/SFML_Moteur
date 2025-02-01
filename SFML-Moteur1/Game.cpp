#include "Game.h"
#include "TimerManager.h"


Game::Game()
{
    window = RenderWindow();
}


void Game::Start()
{
    window.create(VideoMode({ 800, 400 }), "Angry");
    Update();
};

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
    //window.draw();
    window.display();
}

void Game::Stop()
{
    
}