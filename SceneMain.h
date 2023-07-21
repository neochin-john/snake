#pragma once
#include "Mat2D.h"
#include "Scene.h"
#include "Snake.h"

class SceneMain : public Scene
{
public:
    SceneMain();
    void Update() override;
    void Rende() override;

private:
    int frame;

    Snake snake;
    Mat2D map;
    Vector2 food;

    
};                      
