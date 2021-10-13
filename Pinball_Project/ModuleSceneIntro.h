#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

public:
	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	PhysBody* sensor;
	bool sensed;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	uint bonus_fx;
	p2Point<int> ray;
	bool ray_on;

	//UI textures
	SDL_Texture* game_icon = nullptr;
	SDL_Texture* audio_icon = nullptr;
	SDL_Texture* bestscore = nullptr;
	SDL_Texture* bg_menu = nullptr;
	SDL_Texture* but_credits = nullptr;
	SDL_Texture* but_exit = nullptr;
	SDL_Texture* but_fullscreen = nullptr;
	SDL_Texture* but_home = nullptr;
	SDL_Texture* but_no = nullptr;
	SDL_Texture* but_yes = nullptr;
	SDL_Texture* but_play = nullptr;
	SDL_Texture* but_restart = nullptr;
	SDL_Texture* but_settings = nullptr;
	SDL_Texture* but_start = nullptr;
	SDL_Texture* credits_panel = nullptr;
	SDL_Texture* ctl_logo = nullptr;
	SDL_Texture* extra_ball = nullptr;
	SDL_Texture* hand_anim = nullptr;
	SDL_Texture* keys = nullptr;
	SDL_Texture* msg_box = nullptr;
	SDL_Texture* progress_bar = nullptr;
	SDL_Texture* score_panel = nullptr;
	SDL_Texture* star = nullptr;

	//pinball textures
	SDL_Texture* pinball_bg = nullptr;
	SDL_Texture* arrow_light_0 = nullptr;
	SDL_Texture* arrow_light_1 = nullptr;
	SDL_Texture* arrow_start = nullptr;
	SDL_Texture* ball = nullptr;
	SDL_Texture* bumper = nullptr;
	SDL_Texture* bumper_button = nullptr;
	SDL_Texture* button_light_0 = nullptr;
	SDL_Texture* button_light_1 = nullptr;
	SDL_Texture* button_light_2 = nullptr;
	SDL_Texture* button_light_3 = nullptr;
	SDL_Texture* button_light_4 = nullptr;
	SDL_Texture* button_light_5 = nullptr;
	SDL_Texture* capsule_0 = nullptr;
	SDL_Texture* capsule_1 = nullptr;
	SDL_Texture* capsule_2 = nullptr;
	SDL_Texture* capsule_3 = nullptr;
	SDL_Texture* curve_light_button = nullptr;
	SDL_Texture* curve_tunnel = nullptr;
	SDL_Texture* eye = nullptr;
	SDL_Texture* flipper = nullptr;
	SDL_Texture* flipper_bumper = nullptr;
	SDL_Texture* gate = nullptr;
	SDL_Texture* hole = nullptr;
	SDL_Texture* jackpot = nullptr;
	SDL_Texture* jumper = nullptr;
	SDL_Texture* letter_P = nullptr;
	SDL_Texture* letter_I = nullptr;
	SDL_Texture* letter_N = nullptr;
	SDL_Texture* letter_B = nullptr;
	SDL_Texture* letter_A = nullptr;
	SDL_Texture* letter_L0 = nullptr;
	SDL_Texture* letter_L1 = nullptr;
	SDL_Texture* light_indicator_0 = nullptr;
	SDL_Texture* light_indicator_1 = nullptr;
	SDL_Texture* light_indicator_2 = nullptr;
	SDL_Texture* logo = nullptr;
	SDL_Texture* multiplier_light = nullptr;
	SDL_Texture* multiplier_toggle_light = nullptr;
	SDL_Texture* router_light_0 = nullptr;
	SDL_Texture* router_light_1 = nullptr;
	SDL_Texture* router_light_2 = nullptr;
	SDL_Texture* router_light_3 = nullptr;
	SDL_Texture* router_light_4 = nullptr;
	SDL_Texture* router_light_5 = nullptr;
	SDL_Texture* router_light_6 = nullptr;
	SDL_Texture* safe_pin = nullptr;
	SDL_Texture* shield = nullptr;
	SDL_Texture* spring = nullptr;
	SDL_Texture* start_platform = nullptr;
	SDL_Texture* tunnel_start = nullptr;

	

};
