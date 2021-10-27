#pragma once
#include "Module.h"
#include "p2List.h"
#include "p2Point.h"
#include "Globals.h"

class PhysBody;
struct bumper_def
{
	int x;
	int y;
	int radius;
};
class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(Application* app, bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(PhysBody* bodyA, PhysBody* bodyB);

	int GetCenterX(SDL_Rect r)
	{
		return  r.x + r.w / 2;
	}
	int GetCenterY(SDL_Rect r)
	{
		return  r.y + r.h / 2;
	}

	

public:


	//audio
	bool masterAudioOn;
	bool MusicOn;
	bool SfxOn;

	uint sfx_flipper;
	uint bg_music;
	uint sfx_bumper;
	uint sfx_lateralBumper;
	//List of the different bodies

	PhysBody* pb_startExit;
	PhysBody* pb_startExitSensor;

	bool gamePaused = false;

	PhysBody* pb_currentBall;
	bool ballIsAlive;
	PhysBody* ballLauncherRectangle;
	float ballLauncherRecInitPosX;
	float ballLauncherRecInitPosY;

	p2List<PhysBody*> circles;
	p2List<PhysBody*> boxes;
	p2List<PhysBody*> ricks;

	p2List<PhysBody*> walls;
	p2List<PhysBody*> capsules;
	p2List<PhysBody*> bumpers;
	//p2List<b2RevoluteJoint*> flippers;
	//b2RevoluteJoint a;
	p2List<PhysBody*> leftFlipper_b;
	
	PhysBody* pb_leftFlipper;
	PhysBody* pb_rightFlipper;
	
	float angularSpeed;
	float maxAngle;
	float minAngle;
	float angleMargin;

	//Values for the bumpers
	//400, 250, 40
	bumper_def bumper01;
	bumper_def bumper02;
	bumper_def bumper03;

	PhysBody* pb_bumper01;
	PhysBody* pb_bumper02;
	PhysBody* pb_bumper03;

	PhysBody* pb_pinkCapsule;
	PhysBody* pb_blueCapsule;
	PhysBody* pb_greenCapsule;
	PhysBody* pb_yellowCapsule;

	PhysBody* pb_pinkCapsuleSensor;
	PhysBody* pb_blueCapsuleSensor;
	PhysBody* pb_greenCapsuleSensor;
	PhysBody* pb_yellowCapsuleSensor;


	float bumperForce;

	//rectangle sensor lateral bumpers
	//angle = 23 deg
	// 215 height
	// 5 width

	//activated when all 4 left sensor are activated
	bool leftMiniBumperActive;
	PhysBody* pb_leftMiniBumper;
	float leftMiniBumperForce;

	
	PhysBody* pb_rightLateralBumper;
	PhysBody* pb_leftLatearlBumper;

	float lateralBumperForce;

	

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
	696, 1695,
	972, 1580,
	970, 1398,
	980, 1376,
	990, 1390,
	988, 1598,
	718, 1728,
	686, 1700
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
	int alienIsland[60] = {
	405, 342,
	422, 338,
	442, 349,
	444, 373,
	443, 486,
	444, 558,
	455, 603,
	504, 655,
	548, 694,
	581, 751,
	601, 818,
	586, 860,
	557, 790,
	525, 747,
	473, 693,
	419, 640,
	382, 592,
	339, 591,
	302, 625,
	266, 681,
	240, 733,
	219, 794,
	212, 841,
	171, 773,
	179, 714,
	210, 651,
	250, 573,
	323, 467,
	369, 403,
	398, 350
	};

	int leftBallImpairer[6]
	{
		200,160,
		320,120,
		280,80
	};
	int rightBallImpairer[6]
	{
		850, 100,
		880,100,
		850,120
	};

	//Coordinates of the flippers
	int leftFlipper[20] ={
		 11, -21,
		-10, -22,
		-21, -7,
		-20, 12,
		-11, 21,
		126, 78,
		134, 78,
		140, 73,
		140, 65,
		136, 57

	};
	int rightFlipper[20] ={
		-11, -21,
		 10, -22,
		 21, -7,
		 20, 12,
		 11, 21,
		-126, 78,
		-134, 78,
		-140, 73,
		-140, 65,
		-136, 57

	};
	
	int sep = 10;

	// Coordinates of the capsules
	int blueCapsule[14] = {
	533, 260 + sep,
	513 + sep, 277,
	514 + sep, 356,
	535, 370 - sep,
	559 - sep, 351,
	559 - sep, 278,
	539, 261 + sep
	};
	int greenCapsule[14] = {
	648, 262 + sep,
	630 + sep, 280,
	631 + sep, 361,
	653, 372 - sep,
	675 - sep, 358,
	677 - sep, 273,
	657, 260 + sep
	};
	int yellowCapsule[14] = {
	764, 238 + sep,
	743 + sep, 250,
	743 + sep, 331,
	767, 347 - sep,
	789 - sep, 336,
	791 - sep, 252,
	770, 236 + sep
	};
	int pinkCapsule[14] = {
	430, 342 + sep,
	447 + sep, 326,
	445 + sep, 249,
	424, 230 - sep,
	399 - sep, 248,
	399 - sep, 322,
	412, 343 + sep
	};

	int blueCapsuleSensor[14] = {
	533, 260,
	513, 277,
	514, 356,
	535, 370,
	559, 351,
	559, 278,
	539, 261
	};
	int greenCapsuleSensor[14] = {
	648, 262,
	630, 280,
	631, 361,
	653, 372,
	675, 358,
	677, 273,
	657, 260
	};
	int yellowCapsuleSensor[14] = {
	764, 238,
	743, 250,
	743, 331,
	767, 347,
	789, 336,
	791, 252,
	770, 236
	};
	int pinkCapsuleSensor[14] = {
	440, 342,
	447, 316,
	445, 249,
	424, 230,
	399, 248,
	399, 322,
	412, 343
	};
	

	int margin = 20;

	/*bool blueCapsuleCounter = false;
	bool greenCapsuleCounter = false;
	bool yellowCapsuleCounter = false;*/

	int bumper01Counter = 0;
	int bumper02Counter = 0;
	int bumper03Counter = 0;

	int ballStartPositionerLeft[6]
	{	1050, 1771,
		1090 - margin, 1780,
		1050, 1780
	
	};
	int ballStartPositionerRight[6]
	{	1130, 1771,
		1130, 1780,
		1090 + margin, 1780
		
	};

	float startForce;

	

};
