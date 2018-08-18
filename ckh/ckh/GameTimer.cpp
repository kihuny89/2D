#include <Windows.h>

#include "GameTimer.h"

GameTimer::GameTimer()
{
	__int64 countsPerSec;
	
		QueryPerformanceFrequency((LARGE_INTEGER*)&countsPerSec);
	_secondsPerCount = 1.0f / (double)countsPerSec;
}

GameTimer::~GameTimer()
{
}

void GameTimer::Init()
{

	__int64 currentTime;
	QueryPerformanceFrequency((LARGE_INTEGER*)&currentTime);
	_prevTime = currentTime;

	_deltaTime = 0.0f;
}

void GameTimer::Update()
{
	__int64 currentTime;
	QueryPerformanceFrequency((LARGE_INTEGER*)&currentTime);

	_deltaTime = (currentTime - _prevTime) * _secondsPerCount;
	_prevTime = currentTime;
}

float GameTimer::GetDeltaTime()
{
	return _deltaTime;
}
