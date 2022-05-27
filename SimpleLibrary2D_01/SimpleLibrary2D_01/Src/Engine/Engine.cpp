﻿#include "Engine.h"

Engine* Engine::instance = nullptr;

bool Engine::Initialize()
{
	if (instance == nullptr)
	{
		instance = new Engine();
	}

	if (B_FAILED(instance->window.Initialize()))
	{
		return false;
	}
	if (B_FAILED(instance->graphics.Initialize()))
	{
		return false;
	}
	return true;
}

void Engine::Update()
{
	instance->window.Update();
}

void Engine::Finalize()
{
	instance->graphics.WaitForPreviousFrame();
	//delete instance;//問題点
}

//Windowクラス関係の関数
bool Engine::IsClosedWindow()
{
	return instance->window.IsClosed();
}

void Engine::SetWindowSize(int width_size, int height_size)
{
	if (instance == nullptr)
	{
		instance = new Engine();
	}

	return instance->window.SetWindowSize(width_size, height_size);
}

//Graphicsクラス関係の関数
void Engine::ClearScreen()
{
	instance->graphics.ClearScreen();
}

void Engine::ScreenFlip()
{
	instance->graphics.ScreenFlip();

	// フレーム後処理
	instance->graphics.WaitForPreviousFrame();
}