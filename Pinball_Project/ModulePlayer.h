#pragma once
#include "Module.h"
#include "Globals.h"
#include "p2Point.h"

class ModulePlayer : public Module
{
public:
	ModulePlayer(Application* app, bool start_enabled = true);
	virtual ~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	int playerLives = 3;
	int ballsInGame = 0;
	int score = 0;
	uint ballStart = 0;
	uint ballCollider = 0;
	uint ballRefill = 0;
	uint ballDeath = 0;

	void RestartPlayer()
	{
		score = 0;
		playerLives = 3;
		ballsInGame = 0;
	}
};