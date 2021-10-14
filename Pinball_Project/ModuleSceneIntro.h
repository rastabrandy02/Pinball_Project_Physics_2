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

	//List of the different bodies


	bool gamePaused = false;


	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	p2List<PhysBody*> walls;

	

	PhysBody* sensor;
	bool sensed;

	SDL_Texture* circle;
	SDL_Texture* box;
	SDL_Texture* rick;
	uint bonus_fx;
	p2Point<float> ray;
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
	SDL_Texture* flipper = nullptr;		   //right: 726  left: 326  y: 1706
	SDL_Texture* flipper_bumper = nullptr; //right: 840  left: 240  y: 1460
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


	//image rects
	SDL_Rect r_arrow_light_0[2];
	SDL_Rect r_arrow_light_1[2];
	SDL_Rect r_arrow_start[2];
	SDL_Rect r_bumper[14];
	SDL_Rect r_bumper_button[2];
	SDL_Rect r_button_light_0[2];
	SDL_Rect r_button_light_1[2];
	SDL_Rect r_button_light_2[2];
	SDL_Rect r_button_light_3[2];
	SDL_Rect r_button_light_4[2];
	SDL_Rect r_button_light_5[2];
	SDL_Rect r_capsule_0[2];
	SDL_Rect r_capsule_1[2];
	SDL_Rect r_capsule_2[2];
	SDL_Rect r_capsule_3[2];
	SDL_Rect r_curve_light_button[2];
	SDL_Rect r_flipper_bumper[2];
	SDL_Rect r_jackpot[2];
	SDL_Rect r_jumper[2];
	SDL_Rect r_letter_P[2];
	SDL_Rect r_letter_I[2];
	SDL_Rect r_letter_N[2];
	SDL_Rect r_letter_B[2];
	SDL_Rect r_letter_A[2];
	SDL_Rect r_letter_L0[2];
	SDL_Rect r_letter_L1[2];
	SDL_Rect r_light_indicator_0[2];
	SDL_Rect r_light_indicator_1[2];
	SDL_Rect r_light_indicator_2[2];
	SDL_Rect r_logo[2];
	SDL_Rect r_bultiplier_light[2];
	SDL_Rect r_multiplier_toggle_light[2];
	SDL_Rect r_router_light_0[2];
	SDL_Rect r_router_light_1[2];
	SDL_Rect r_router_light_2[2];
	SDL_Rect r_router_light_3[2];
	SDL_Rect r_router_light_4[2];
	SDL_Rect r_router_light_5[2];
	SDL_Rect r_router_light_6[2];
	SDL_Rect r_shield[2];

	SDL_Rect r_audio_icon[2];
	SDL_Rect r_but_fullscreen[2];
	SDL_Rect r_hand_anim[10];

	//The coordinates of all the walls to create the chains
	int mainWalls[102] = {
	695, 1848,
	1020, 1701,
	1045, 1638,
	1043, 1350,
	923, 1216,
	926, 945,
	1023, 681,
	993, 588,
	888, 821,
	850, 808,
	981, 516,
	928, 303,
	860, 300,
	858, 203,
	895, 200,
	965, 281,
	1015, 365,
	1040, 446,
	1053, 576,
	1053, 688,
	1053, 815,
	1058, 1873,
	1121, 1871,
	1118, 521,
	1098, 375,
	1056, 275,
	995, 195,
	913, 118,
	796, 55,
	653, 26,
	518, 31,
	398, 58,
	298, 105,
	190, 188,
	105, 278,
	53, 388,
	31, 485,
	20, 1186,
	96, 1261,
	100, 1295,
	28, 1365,
	21, 1685,
	35, 1711,
	335, 1855,
	336, 1916,
	-1, 1913,
	0, -1,
	1146, 1,
	1148, 1913,
	691, 1915,
	695, 1856
	};
	int rightWall[16] = {
	696, 1685,
	961, 1580,
	970, 1398,
	980, 1376,
	990, 1390,
	988, 1598,
	718, 1728,
	686, 1693
	};
	int leftWall[16] = {
	348, 1688,
	101, 1585,
	105, 1398,
	96, 1381,
	86, 1401,
	82, 1602,
	330, 1728,
	348, 1702
	};
	int rightRedIsland[12] = {
	772, 1570,
	798, 1593,
	896, 1556,
	903, 1340,
	869, 1363,
	784, 1553
	};
	int leftRedIsland[12] = {
	300, 1570,
	208, 1368,
	180, 1340,
	172, 1556,
	273, 1597,
	301, 1578
	};
	int bigIsland[24] = {
	146, 597,
	182, 508,
	224, 442,
	277, 372,
	336, 286,
	338, 212,
	288, 194,
	165, 326,
	126, 393,
	105, 470,
	114, 542,
	128, 580
	};
	int littleIsland[18] = {
	296, 804,
	465, 802,
	479, 794,
	473, 769,
	370, 668,
	346, 672,
	316, 724,
	296, 769,
	295, 791
	};
};
