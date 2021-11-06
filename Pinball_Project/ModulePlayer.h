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
	int playerLifes = 3;
	int ballsInGame = 0;
	int score = 0;
	uint ballStart;
	uint ballCollider;
	uint ballRefill;
	uint ballDeath;

	void RestartPlayer()
	{
		score = 0;
		playerLifes = 3;
		ballsInGame = 0;
	}
};