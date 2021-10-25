#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleSceneIntro.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleAudio.h"
#include "ModulePhysics.h"
#include "ModulePlayer.h"
ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
	circle = box = rick = NULL;
	ray_on = false;
	sensed = false;
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;
	// TODO: Homework - create a sensor
	App->renderer->camera.x = App->renderer->camera.y = 0;

	circle = App->textures->Load("pinball/wheel.png"); 
	box = App->textures->Load("pinball/crate.png");
	rick = App->textures->Load("pinball/rick_head.png");
	bonus_fx = App->audio->LoadFx("pinball/bonus.wav");

	//load images
	if (true)
	{
		//load UI elements
		game_icon = App->textures->Load("pinball/UI_elements/icon.png");
		audio_icon = App->textures->Load("pinball/UI_elements/audio_icon.png");
		bestscore = App->textures->Load("pinball/UI_elements/bestscore.png");
		bg_menu = App->textures->Load("pinball/UI_elements/bg_menu.png");
		but_credits = App->textures->Load("pinball/UI_elements/but_credits.png");
		but_exit = App->textures->Load("pinball/UI_elements/but_exit.png");
		but_fullscreen = App->textures->Load("pinball/UI_elements/but_fullscreen.png");
		but_home = App->textures->Load("pinball/UI_elements/but_home.png");
		but_no = App->textures->Load("pinball/UI_elements/but_no.png");
		but_yes = App->textures->Load("pinball/UI_elements/but_yes.png");
		but_play = App->textures->Load("pinball/UI_elements/but_play.png");
		but_restart = App->textures->Load("pinball/UI_elements/but_restart.png");
		but_settings = App->textures->Load("pinball/UI_elements/but_settings.png");
		but_start = App->textures->Load("pinball/UI_elements/but_start.png");
		credits_panel = App->textures->Load("pinball/UI_elements/credits_panel.png");
		ctl_logo = App->textures->Load("pinball/UI_elements/ctl_logo.png");
		extra_ball = App->textures->Load("pinball/UI_elements/extra_ball.png");
		hand_anim = App->textures->Load("pinball/UI_elements/hand_anim.png");
		keys = App->textures->Load("pinball/UI_elements/keys.png");
		msg_box = App->textures->Load("pinball/UI_elements/msg_box.png");
		progress_bar = App->textures->Load("pinball/UI_elements/progress_bar.png");
		score_panel = App->textures->Load("pinball/UI_elements/score_panel.png");
		star = App->textures->Load("pinball/UI_elements/star.png");

		//load pinball elements
		pinball_bg = App->textures->Load("pinball/pinball_elements/pinball_bg.png");
		arrow_light_0 = App->textures->Load("pinball/pinball_elements/arrow_light_0.png");
		arrow_light_1 = App->textures->Load("pinball/pinball_elements/arrow_light_1.png");
		arrow_start = App->textures->Load("pinball/pinball_elements/arrow_start.png");
		ball = App->textures->Load("pinball/pinball_elements/ball.png");
		bumper = App->textures->Load("pinball/pinball_elements/bumper.png");
		bumper_button = App->textures->Load("pinball/pinball_elements/bumper_button.png");
		button_light_0 = App->textures->Load("pinball/pinball_elements/button_light_0.png");
		button_light_1 = App->textures->Load("pinball/pinball_elements/button_light_1.png");
		button_light_2 = App->textures->Load("pinball/pinball_elements/button_light_2.png");
		button_light_3 = App->textures->Load("pinball/pinball_elements/button_light_3.png");
		button_light_4 = App->textures->Load("pinball/pinball_elements/button_light_4.png");
		button_light_5 = App->textures->Load("pinball/pinball_elements/button_light_5.png");
		capsule_0 = App->textures->Load("pinball/pinball_elements/capsule_0.png");
		capsule_1 = App->textures->Load("pinball/pinball_elements/capsule_1.png");
		capsule_2 = App->textures->Load("pinball/pinball_elements/capsule_2.png");
		capsule_3 = App->textures->Load("pinball/pinball_elements/capsule_3.png");
		curve_light_button = App->textures->Load("pinball/pinball_elements/curve_light_button.png");
		curve_tunnel = App->textures->Load("pinball/pinball_elements/curve_tunnel.png");
		eye = App->textures->Load("pinball/pinball_elements/eye.png");
		flipper = App->textures->Load("pinball/pinball_elements/flipper.png");
		flipper_bumper = App->textures->Load("pinball/pinball_elements/flipper_bumper.png");
		gate = App->textures->Load("pinball/pinball_elements/gate.png");
		hole = App->textures->Load("pinball/pinball_elements/hole.png");
		jackpot = App->textures->Load("pinball/pinball_elements/jackpot.png");
		jumper = App->textures->Load("pinball/pinball_elements/jumper.png");
		letter_P = App->textures->Load("pinball/pinball_elements/letter_0.png");
		letter_I = App->textures->Load("pinball/pinball_elements/letter_1.png");
		letter_N = App->textures->Load("pinball/pinball_elements/letter_2.png");
		letter_B = App->textures->Load("pinball/pinball_elements/letter_3.png");
		letter_A = App->textures->Load("pinball/pinball_elements/letter_4.png");
		letter_L0 = App->textures->Load("pinball/pinball_elements/letter_5.png");
		letter_L1 = App->textures->Load("pinball/pinball_elements/letter_6.png");
		light_indicator_0 = App->textures->Load("pinball/pinball_elements/light_indicator_0.png");
		light_indicator_1 = App->textures->Load("pinball/pinball_elements/light_indicator_1.png");
		light_indicator_2 = App->textures->Load("pinball/pinball_elements/light_indicator_2.png");
		logo = App->textures->Load("pinball/pinball_elements/logo.png");
		multiplier_light = App->textures->Load("pinball/pinball_elements/multiplier_light.png");
		multiplier_toggle_light = App->textures->Load("pinball/pinball_elements/multiplier_toggle_light.png");
		router_light_0 = App->textures->Load("pinball/pinball_elements/router_light_0.png");
		router_light_1 = App->textures->Load("pinball/pinball_elements/router_light_1.png");
		router_light_2 = App->textures->Load("pinball/pinball_elements/router_light_2.png");
		router_light_3 = App->textures->Load("pinball/pinball_elements/router_light_3.png");
		router_light_4 = App->textures->Load("pinball/pinball_elements/router_light_4.png");
		router_light_5 = App->textures->Load("pinball/pinball_elements/router_light_5.png");
		router_light_6 = App->textures->Load("pinball/pinball_elements/router_light_6.png");
		safe_pin = App->textures->Load("pinball/pinball_elements/safe_pin.png");
		shield = App->textures->Load("pinball/pinball_elements/shield.png");
		spring = App->textures->Load("pinball/pinball_elements/spring.png");
		start_platform = App->textures->Load("pinball/pinball_elements/start_platform.png");
		tunnel_start = App->textures->Load("pinball/pinball_elements/tunnel_start.png");
	}

	//adapt walls to screen size
	if (true)
	{
		for (int i = 0; i < 102; i++)
		{
			mainWalls[i] *= SCREEN_SIZE;
		}

		for (int i = 0; i < 16; i++)
		{
			leftWall[i] *= SCREEN_SIZE;
			rightWall[i] *= SCREEN_SIZE;
		}


		for (int i = 0; i < 12; i++)
		{
			leftRedIsland[i] *= SCREEN_SIZE;
			rightRedIsland[i] *= SCREEN_SIZE;
		}

		for (int i = 0; i < 24; i++)
		{
			bigIsland[i] *= SCREEN_SIZE;
		}
		for (int i = 0; i < 18; i++)
		{
			littleIsland[i] *= SCREEN_SIZE;
		}

		for (int i = 0; i < 20; i++)
		{
			leftFlipper[i] *= SCREEN_SIZE;
			rightFlipper[i] *= SCREEN_SIZE;
		}

		for (size_t i = 0; i < 6; i++)
		{
			ballStartPositionerLeft[i] *= SCREEN_SIZE;
			ballStartPositionerRight[i] *= SCREEN_SIZE;
		}
		for (int i = 0; i < 60; i++)
		{
			alienIsland[i] *= SCREEN_SIZE;
		}
		for (int i = 0; i < 14; i++)
		{
			blueCapsule[i] *= SCREEN_SIZE;
			greenCapsule[i] *= SCREEN_SIZE;
			yellowCapsule[i] *= SCREEN_SIZE;
		}

		bumper01.x = 578 * SCREEN_SIZE;
		bumper01.y = 545 * SCREEN_SIZE;
		bumper01.radius = 77 * SCREEN_SIZE;

		bumper02.x = 800 * SCREEN_SIZE;
		bumper02.y = 504 * SCREEN_SIZE;
		bumper02.radius = 77 * SCREEN_SIZE;

		bumper03.x = 738 * SCREEN_SIZE;
		bumper03.y = 688 * SCREEN_SIZE;
		bumper03.radius = 77 * SCREEN_SIZE;
	}

	//Create all the walls, flippers, capsules, bumpers
	PhysBody* pb_mainWalls = App->physics->CreateStaticChain(0, 0, mainWalls, 102);
	PhysBody* pb_leftWall = App->physics->CreateStaticChain(0, 0, leftWall, 16);
	PhysBody* pb_rightWall = App->physics->CreateStaticChain(0, 0, rightWall, 16);
	PhysBody* pb_leftRedIsland = App->physics->CreateStaticChain(0, 0, leftRedIsland, 12);
	PhysBody* pb_rightRedIsland = App->physics->CreateStaticChain(0, 0, rightRedIsland, 12);
	PhysBody* pb_bigIsland = App->physics->CreateStaticChain(0, 0, bigIsland, 24);
	PhysBody* pb_littleIsland = App->physics->CreateStaticChain(0, 0, littleIsland, 18);
	PhysBody* pb_alienIsland = App->physics->CreateStaticChain(0, 0, alienIsland, 60);
	PhysBody* pb_ballStartPositionerLeft = App->physics->CreateStaticChain(0, 0, ballStartPositionerLeft, 6);
	PhysBody* pb_ballStartPositionerRight = App->physics->CreateStaticChain(0, 0, ballStartPositionerRight, 6);
	
	ballLauncherRectangle = App->physics->CreateKinematicRectangle(1090, 1771 + 25, 80, 50); //110 pixels until bottom
	ballLauncherRecInitPosX = ballLauncherRectangle->body->GetPosition().x;
	ballLauncherRecInitPosY = ballLauncherRectangle->body->GetPosition().y;

    pb_blueCapsule = App->physics->CreateStaticChain(0, 0, blueCapsule, 14);
	pb_blueCapsule->type = TYPE_SCORE;
    pb_greenCapsule = App->physics->CreateStaticChain(0, 0, greenCapsule, 14);
	pb_greenCapsule->type = TYPE_SCORE;
    pb_yellowCapsule = App->physics->CreateStaticChain(0, 0, yellowCapsule, 14);
	pb_yellowCapsule->type = TYPE_SCORE;

	pb_bumper01 = App->physics->CreateSensorCircle(bumper01.x, bumper01.y, bumper01.radius);
	pb_bumper02 = App->physics->CreateSensorCircle(bumper02.x, bumper02.y, bumper02.radius);
	pb_bumper03 = App->physics->CreateSensorCircle(bumper03.x, bumper03.y, bumper03.radius);

	PhysBody* pb_bumper01Interior = App->physics->CreateStaticCircle(bumper01.x, bumper01.y, bumper01.radius - 2);
	PhysBody* pb_bumper02Interior = App->physics->CreateStaticCircle(bumper02.x, bumper02.y, bumper02.radius - 2);
	PhysBody* pb_bumper03Interior = App->physics->CreateStaticCircle(bumper03.x, bumper03.y, bumper03.radius - 2);


	

	walls.add(pb_mainWalls);
	walls.add(pb_leftWall);
	walls.add(pb_rightWall);
	walls.add(pb_leftRedIsland);
	walls.add(pb_rightRedIsland);
	walls.add(pb_bigIsland);
	walls.add(pb_littleIsland);
	walls.add(pb_ballStartPositionerLeft);
	walls.add(pb_ballStartPositionerRight);
	walls.add(pb_alienIsland);

	capsules.add(pb_blueCapsule);
	capsules.add(pb_greenCapsule);
	capsules.add(pb_yellowCapsule);

	bumpers.add(pb_bumper01);
	bumpers.add(pb_bumper02);
	bumpers.add(pb_bumper03);

	pb_leftFlipper = App->physics->CreateKinematicChain(326, 1700, leftFlipper, 20);
	pb_rightFlipper = App->physics->CreateKinematicChain(718, 1700, rightFlipper, 20);

	//Set rects of multi-texture sprites

	if (true)
	{
		r_arrow_light_0[0] = { 0,0,230 / 2,140 };
		r_arrow_light_0[1] = { 230 / 2,0,230,140 };
		r_arrow_light_1[0] = { 0,0,230 / 2,140 };
		r_arrow_light_1[1] = { 230 / 2,0,230,140 };
		r_arrow_start[0] = { 0,0,148 / 2,67 };
		r_arrow_start[1] = { 148 / 2,0,148,67 };

		for (int i = 0; i < 7; i++)
		{
			r_bumper[i] = { 1218 / 7 * i,0, 1218 / 7, 348 / 2 };
		}
		for (int i = 0; i < 7; i++)
		{
			r_bumper[i + 7] = { 1218 / 7 * i, 348 / 2, 1218 / 7, 348 / 2 };
		}

		r_bumper_button[0] = { 0,0,46 / 2,74 };
		r_bumper_button[1] = { 46 / 2,0,46 / 2,74 };
		r_button_light_0[0] = { 0,0,188 / 2,94 };
		r_button_light_0[1] = { 188 / 2,0,188 / 2,94 };
		r_button_light_1[0] = { 0,0,188 / 2,94 };
		r_button_light_1[1] = { 188 / 2,0,188 / 2,94 };
		r_button_light_2[0] = { 0,0,188 / 2,94 };
		r_button_light_2[1] = { 188 / 2,0,188 / 2,94 };
		r_button_light_3[0] = { 0,0,188 / 2,94 };
		r_button_light_3[1] = { 188 / 2,0,188 / 2,94 };
		r_button_light_4[0] = { 0,0,188 / 2,94 };
		r_button_light_4[1] = { 188 / 2,0,188 / 2,94 };
		r_button_light_5[0] = { 0,0,188 / 2,94 };
		r_button_light_5[1] = { 188 / 2,0,188 / 2,94 };
		r_capsule_0[0] = { 0,0, 268 / 2,198 };
		r_capsule_0[1] = { 268 / 2,0,268 / 2,198 };
		r_capsule_1[0] = { 0,0, 268 / 2,198 };
		r_capsule_1[1] = { 268 / 2,0,268 / 2,198 };
		r_capsule_2[0] = { 0,0, 268 / 2,198 };
		r_capsule_2[1] = { 268 / 2,0,268 / 2,198 };
		r_capsule_3[0] = { 0,0, 268 / 2,198 };
		r_capsule_3[1] = { 268 / 2,0,268 / 2,198 };
		r_curve_light_button[0] = { 0,0, 234 / 2,107 };
		r_curve_light_button[1] = { 234 / 2,0,234 / 2,107 };
		r_flipper_bumper[0] = { 0,0, 256 / 2,264 };
		r_flipper_bumper[1] = { 256 / 2,0,256 / 2,264 };
		r_jackpot[0] = { 0,0, 230 / 2,197 };
		r_jackpot[1] = { 230 / 2,0,230 / 2,197 };
		r_jumper[0];
		r_jumper[1];
		r_letter_P[0] = { 0,0, 200 / 2,100 };
		r_letter_P[1] = { 200 / 2,0,200 / 2,100 };
		r_letter_I[0] = { 0,0, 200 / 2,100 };
		r_letter_I[1] = { 200 / 2,0,200 / 2,100 };
		r_letter_N[0] = { 0,0, 200 / 2,100 };
		r_letter_N[1] = { 200 / 2,0,200 / 2,100 };
		r_letter_B[0] = { 0,0, 200 / 2,100 };
		r_letter_B[1] = { 200 / 2,0,200 / 2,100 };
		r_letter_A[0] = { 0,0, 200 / 2,100 };
		r_letter_A[1] = { 200 / 2,0,200 / 2,100 };
		r_letter_L0[0] = { 0,0, 200 / 2,100 };
		r_letter_L0[1] = { 200 / 2,0,200 / 2,100 };
		r_letter_L1[0] = { 0,0, 200 / 2,100 };
		r_letter_L1[1] = { 200 / 2,0,200 / 2,100 };
		r_light_indicator_0[0] = { 0,0, 314 / 2,139 };
		r_light_indicator_0[1] = { 314 / 2,0,314 / 2,139 };
		r_light_indicator_1[0] = { 0,0, 314 / 2,139 };
		r_light_indicator_1[1] = { 314 / 2,0,314 / 2,139 };
		r_light_indicator_2[0] = { 0,0, 314 / 2,139 };
		r_light_indicator_2[1] = { 314 / 2,0,314 / 2,139 };
		r_logo[0] = { 0,0, 816 / 2,310 };
		r_logo[1] = { 816 / 2,0,816 / 2,310 };
		r_bultiplier_light[0] = { 0,0, 314 / 2,139 };
		r_bultiplier_light[1] = { 314 / 2,0,314 / 2,139 };
		r_multiplier_toggle_light[0] = { 0,0, 226 / 2,110 };
		r_multiplier_toggle_light[1] = { 226 / 2,0,226 / 2,110 };
		r_router_light_0[0] = { 0,0, 236 / 2,118 };
		r_router_light_0[1] = { 236 / 2,0,236 / 2,118 };
		r_router_light_1[0] = { 0,0, 236 / 2,118 };
		r_router_light_1[1] = { 236 / 2,0,236 / 2,118 };
		r_router_light_2[0] = { 0,0, 236 / 2,118 };
		r_router_light_2[1] = { 236 / 2,0,236 / 2,118 };
		r_router_light_3[0] = { 0,0, 236 / 2,118 };
		r_router_light_3[1] = { 236 / 2,0,236 / 2,118 };
		r_router_light_4[0] = { 0,0, 236 / 2,118 };
		r_router_light_4[1] = { 236 / 2,0,236 / 2,118 };
		r_router_light_5[0] = { 0,0, 236 / 2,118 };
		r_router_light_5[1] = { 236 / 2,0,236 / 2,118 };
		r_router_light_6[0] = { 0,0, 236 / 2,118 };
		r_router_light_6[1] = { 236 / 2,0,236 / 2,118 };
		r_shield[0] = { 0,0, 80 / 2,40 };
		r_shield[1] = { 80 / 2,0,80 / 2,40 };

		r_audio_icon[0] = { 0,0,184 / 2,100 };
		r_audio_icon[1] = { 184 / 2,0,184 / 2,100 };

		r_but_fullscreen[0] = { 0,0,184 / 2,100 };
		r_but_fullscreen[1] = { 184 / 2,0,184 / 2,100 };

		for (int i = 0; i < 5; i++)
		{
			r_hand_anim[i] = { 1010 / 5 * i, 0, 1010 / 5, 554 / 2 };
		}
		for (int i = 0; i < 5; i++)
		{
			r_hand_anim[i + 5] = { 1010 / 5 * i, 554 / 2, 1010 / 5, 554 };
		}

	}

	angleMargin = 10.0f;

	angularSpeed = 15.0f;
	minAngle = 0.0f;
	maxAngle = 60.0f;

	bumperForce = 5.0f;
	// TODO: Homework - create a sensor


	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	//if not paused not update elements but still draw them 

	if (App->input->GetKey(SDL_SCANCODE_P) == KEY_UP)
		gamePaused = !gamePaused;

	if (App->input->GetKey(SDL_SCANCODE_M) == KEY_DOWN)
	{
		App->player->RestartPlayer();

	}

	if (!gamePaused && (App->player->playerLives>0))
	{

		/*if (App->input->GetKey(SDL_SCANCODE_SPACE) == KEY_DOWN)
		{
			ray_on = !ray_on;
			ray.x = App->input->GetMouseX();
			ray.y = App->input->GetMouseY();
		}*/

		if (App->input->GetKey(SDL_SCANCODE_1) == KEY_DOWN)
		{
			pb_currentBall = App->physics->CreateCircle(App->input->GetMouseX(), App->input->GetMouseY(), 24 * SCREEN_SIZE);
			
			pb_currentBall->type == TYPE_BALL;
			// TODO 8: Make sure to add yourself as collision callback to the circle you creates
			circles.add(pb_currentBall);
		}

		if ((App->input->GetKey(SDL_SCANCODE_Q) == KEY_DOWN)&&(App->player->ballsInGame==0))
		{
			pb_currentBall = App->physics->CreateCircle(1090 * SCREEN_SIZE, 1730 * SCREEN_SIZE, 24 * SCREEN_SIZE);
			pb_currentBall->type == TYPE_BALL;
			App->player->ballsInGame++;
			// TODO 8: Make sure to add yourself as collision callback to the circle you creates
			circles.add(pb_currentBall);
		}
		
		if (App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		{
			App->player->playerLives--;
			circles.clear();
			App->player->ballsInGame = 0;
		
		}

		



		//MANAGE LEFT FLIPPER
		if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_STATE::KEY_REPEAT)
		{
			if (pb_leftFlipper->body->GetAngle() - DEGTORAD * angularSpeed > -DEGTORAD * maxAngle)
			{
				pb_leftFlipper->body->SetAngularVelocity(-angularSpeed);
				//LOG("go up");
			}

			if (pb_leftFlipper->body->GetAngle() - DEGTORAD * angularSpeed < -DEGTORAD * maxAngle)
			{
				//LOG("unacceptable");
				pb_leftFlipper->body->SetAngularVelocity(0.0f);
			}
		}
		else
		{

			if (pb_leftFlipper->body->GetAngle() < 0.0f)
			{
				if (pb_leftFlipper->body->GetAngle() < DEGTORAD * minAngle + DEGTORAD * angleMargin)
				{
					//LOG("go down");
					pb_leftFlipper->body->SetAngularVelocity(angularSpeed);
				}

			}

			if (pb_leftFlipper->body->GetAngle() + DEGTORAD * angularSpeed > DEGTORAD * minAngle + DEGTORAD * angleMargin)
			{
				//LOG("unacceptable");
				pb_leftFlipper->body->SetAngularVelocity(0.0f);
			}
		}

		//MANAGE RIGHT FLIPPER
		if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_STATE::KEY_REPEAT)
		{
			if (pb_rightFlipper->body->GetAngle() + DEGTORAD * angularSpeed < DEGTORAD * maxAngle)
			{
				pb_rightFlipper->body->SetAngularVelocity(angularSpeed);
				//LOG("go up");
			}

			if (pb_rightFlipper->body->GetAngle() + DEGTORAD * angularSpeed > DEGTORAD * maxAngle)
			{
				//LOG("unacceptable");
				pb_rightFlipper->body->SetAngularVelocity(0.0f);
			}
		}
		else
		{

			if (pb_rightFlipper->body->GetAngle() > 0.0f)
			{
				if (pb_rightFlipper->body->GetAngle() > DEGTORAD * minAngle - DEGTORAD * angleMargin)
				{
					//LOG("go down");
					pb_rightFlipper->body->SetAngularVelocity(-angularSpeed);
				}
			}

			if (pb_rightFlipper->body->GetAngle() - DEGTORAD * angularSpeed < DEGTORAD * minAngle - DEGTORAD * angleMargin)
			{
				//LOG("unacceptable");
				pb_rightFlipper->body->SetAngularVelocity(0.0f);
			}
		}

		//MANAGE START SPRING

		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_STATE::KEY_DOWN)
		{
			startForce = 0;
		}
		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_STATE::KEY_REPEAT)
		{
			if (startForce < 0.5f)
			{
				startForce += 0.005f;
			}
			b2Vec2 relativePos = { ballLauncherRecInitPosX , ballLauncherRecInitPosY + startForce };
			ballLauncherRectangle->body->SetTransform(relativePos, 0.0f);
		}
		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_STATE::KEY_UP)
		{
			//LOG("%i", METERS_TO_PIXELS(ballLauncherRectangle->body->GetPosition().y * SCREEN_SIZE));
			//LOG("%i", METERS_TO_PIXELS(ballLauncherRecInitPosY * SCREEN_SIZE));
			float y1 = METERS_TO_PIXELS(ballLauncherRecInitPosY );
			float y2 = METERS_TO_PIXELS(ballLauncherRectangle->body->GetPosition().y);

			//LOG("%f", (y2 - y1 + startForce * 2));

			b2Vec2 force = { 0,-( y2 - y1 + startForce * 2) };
			ballLauncherRectangle->body->SetLinearVelocity(force);

			//LOG("%f", (y2 - y1 + startForce * 2));
		}
		if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_STATE::KEY_IDLE)
		{
			//
			if (METERS_TO_PIXELS(ballLauncherRectangle->body->GetPosition().y) < 1850 * SCREEN_SIZE)
			{
				//LOG("%f", METERS_TO_PIXELS(ballLauncherRectangle->body->GetPosition().y))
				//b2Vec2 pos = { PIXEL_TO_METERS((1050 + 40) * SCREEN_SIZE),PIXEL_TO_METERS((1850 - 40) * SCREEN_SIZE) };
				//ballLauncherRectangle->body->SetTransform(pos, 0.0f * DEGTORAD);
				b2Vec2 zeroSpeed = { 0,0 };
				ballLauncherRectangle->body->SetLinearVelocity(zeroSpeed);
				b2Vec2 initPos = { ballLauncherRecInitPosX,ballLauncherRecInitPosY };
				ballLauncherRectangle->body->SetTransform(initPos, 0.0f);
			}
		}
	}



	//BUMPERS
	p2List_item <PhysBody*>* bumperPointer = bumpers.getFirst();
	while (bumperPointer != nullptr)
	{
		if (bumperPointer->data->body->GetContactList() != nullptr)

		{
			if (bumperPointer->data->body->GetContactList()->contact->IsTouching())
			{
				b2Body* ball = bumperPointer->data->body->GetContactList()->contact->GetFixtureB()->GetBody();

				b2Vec2 bumpForceVec = {
					ball->GetPosition().x - bumperPointer->data->body->GetPosition().x,
					ball->GetPosition().y - bumperPointer->data->body->GetPosition().y
				};

				bumpForceVec.Normalize();
				bumpForceVec *= bumperForce;
				b2Vec2 zero = { 0,0 };
				ball->SetLinearVelocity(zero);

				ball->SetLinearVelocity(bumpForceVec);

				bumperPointer->data->playAnimation = true;
				App->player->score += 100;
				LOG("SCORE: %i", App->player->score);
				//LOG("x: %f, y: %f", bumpForceVec.x, bumpForceVec.y);


			}
		}

		bumperPointer = bumperPointer->next;
	}
	p2List_item <PhysBody*>* capsulePointer = capsules.getFirst();
	while (capsulePointer != nullptr)
	{
		if (capsulePointer->data->body->GetContactList() != nullptr)

		{
			if (capsulePointer->data->body->GetContactList()->contact->IsTouching())
			{
				b2Body* ball = capsulePointer->data->body->GetContactList()->contact->GetFixtureB()->GetBody();
				
				/*b2Vec2 bumpForceVec = {
					ball->GetPosition().x - bumperPointer->data->body->GetPosition().x,
					ball->GetPosition().y - bumperPointer->data->body->GetPosition().y
				};

				bumpForceVec.Normalize();
				bumpForceVec *= bumperForce;
				b2Vec2 zero = { 0,0 };*/


				//Bumping force ignored (?)
				//ball->SetLinearVelocity(zero);
				//ball->SetLinearVelocity(bumpForceVec);

				App->player->score += 1000;
				capsulePointer->data->playAnimation = true;
				LOG("SCORE: %i", App->player->score);
				//LOG("x: %f, y: %f", bumpForceVec.x, bumpForceVec.y);


			}
		}
		capsulePointer = capsulePointer->next;
	}
	

	
		
	//END BUMPERS

		// Prepare for raycast ------------------------------------------------------

		fPoint mouse;
		mouse.x = App->input->GetMouseX();
		mouse.y = App->input->GetMouseY();
		float ray_hit = ray.DistanceTo(mouse);

		fVector normal(0.0f, 0.0f);
	
		// All draw functions ------------------------------------------------------
		

		//Background
		App->renderer->Blit(pinball_bg, 0, 0, nullptr);
		
		App->renderer->Blit(spring, 1069, (METERS_TO_PIXELS(ballLauncherRectangle->body->GetPosition().y) -3) / SCREEN_SIZE , nullptr);
		
		//LOG("startforce: %f", startForce);


		//Alien
		App->renderer->Blit(curve_tunnel, 166 , 301 , nullptr);
		App->renderer->Blit(eye, 354 , 511 , nullptr);


		//Capsules
		SDL_Rect r_temp = { 0 };

			//blue
		if (pb_blueCapsule->playAnimation == true)
		{
			r_temp = r_capsule_1[0];
		}
		else
		{
			r_temp = r_capsule_1[1];
		}

		App->renderer->Blit(capsule_1, 337 + 134 , 223 , &r_temp);

			//green
		if (pb_greenCapsule->playAnimation == true)
		{
			r_temp = r_capsule_2[0];
		}
		else
		{
			r_temp = r_capsule_2[1];
		}
		
		App->renderer->Blit(capsule_2, 454 + 134, 223, &r_temp);

			//yellow
		if (pb_yellowCapsule->playAnimation == true)
		{
			r_temp = r_capsule_3[0];
		}
		else
		{
			r_temp = r_capsule_3[1];
		}

		App->renderer->Blit(capsule_3, 566 + 134 , 200 , &r_temp);
			
		
		
		p2List_item<PhysBody*>* c = circles.getFirst();
		while (c != NULL)
		{
			int x, y;
			c->data->GetPosition(x, y);

			if (c->data->Contains(App->input->GetMouseX(), App->input->GetMouseY()))
			{
				//App->renderer->Blit(circle, x, y, NULL, 1.0f, c->data->GetRotation());
			}
			

			App->renderer->Blit(ball, x / SCREEN_SIZE, y / SCREEN_SIZE, NULL);

			


			c = c->next;
		}
		
		
		

		c = boxes.getFirst();

		while (c != NULL)
		{
			int x, y;
			c->data->GetPosition(x, y);
			App->renderer->Blit(box, x, y, NULL, 1.0f, c->data->GetRotation());
			if (ray_on)
			{
				int hit = c->data->RayCast(ray.x, ray.y, mouse.x, mouse.y, normal.x, normal.y);
				if (hit >= 0)
					ray_hit = hit;
			}
			c = c->next;
		}
		App->renderer->Blit(start_platform, SCREEN_WIDTH - 122, SCREEN_HEIGHT - 184, nullptr);

		
		
		//right: 726  left: 326  y: 1706		

		//App->renderer->Blit(flipper, 310, 1680, nullptr, 1, METERS_TO_PIXELS(pb_leftFlipper->body->GetAngle()), 0, 0, SDL_FLIP_HORIZONTAL);
		App->renderer->Blit(flipper, 300, 1675, nullptr, 1, pb_leftFlipper->body->GetAngle() / DEGTORAD , 30 * SCREEN_SIZE, 25 * SCREEN_SIZE, SDL_FLIP_HORIZONTAL);
		//App->renderer->Blit(flipper, 560, 1680, nullptr, 1, METERS_TO_PIXELS(pb_rightFlipper->body->GetAngle()), 176, 118, SDL_FLIP_NONE);
		App->renderer->Blit(flipper, 572, 1675, nullptr, 1, pb_rightFlipper->body->GetAngle() / DEGTORAD  , 145 * SCREEN_SIZE, 25 * SCREEN_SIZE, SDL_FLIP_NONE);
		
		
		
		//right: 840  left: 240  y: 1460
		App->renderer->Blit(flipper_bumper, 240 - GetCenterX(r_flipper_bumper[0]), 1460 - GetCenterY(r_flipper_bumper[0]), &r_flipper_bumper[1], 1, 0, NULL, NULL, SDL_FLIP_HORIZONTAL);
		App->renderer->Blit(flipper_bumper, 840 - GetCenterX(r_flipper_bumper[0]), 1460 - GetCenterY(r_flipper_bumper[0]), &r_flipper_bumper[1], 1, 0, NULL, NULL, SDL_FLIP_NONE);

		//Bumpers lighting


		//App->renderer->Blit(bumper, 490, 460, &r_bumper[0]);
		if (pb_bumper01->playAnimation == true)
		{
			
			int x = 490;
			int y = 460;
			if (bumper01Counter < 10)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[0]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 10 && bumper01Counter < 20)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[1]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 20 && bumper01Counter < 30)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[2]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 30 && bumper01Counter < 40)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[3]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 40 && bumper01Counter < 50)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[4]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 50 && bumper01Counter < 60)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[5]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 60 && bumper01Counter < 70)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[6]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 70 && bumper01Counter < 80)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[7]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 80 && bumper01Counter < 90)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[8]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 90 && bumper01Counter < 100)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[9]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 100 && bumper01Counter < 110)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[10]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 110 && bumper01Counter < 120)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[11]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 120 && bumper01Counter < 130)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[12]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 130 && bumper01Counter < 140)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[13]);
				bumper01Counter++;
			}
			if (bumper01Counter >= 140)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[0]);
				bumper01Counter=0;
				pb_bumper01->playAnimation = false;
			}
		}
		else App->renderer->Blit(bumper, 490, 460, &r_bumper[0]);
		


		//App->renderer->Blit(bumper, 710, 420, &r_bumper[0]);

		if (pb_bumper02->playAnimation == true)
		{

			int x = 710;
			int y = 420;
			if (bumper02Counter < 10)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[0]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 10 && bumper02Counter < 20)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[1]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 20 && bumper02Counter < 30)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[2]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 30 && bumper02Counter < 40)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[3]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 40 && bumper02Counter < 50)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[4]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 50 && bumper02Counter < 60)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[5]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 60 && bumper02Counter < 70)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[6]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 70 && bumper02Counter < 80)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[7]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 80 && bumper02Counter < 90)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[8]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 90 && bumper02Counter < 100)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[9]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 100 && bumper02Counter < 110)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[10]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 110 && bumper02Counter < 120)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[11]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 120 && bumper02Counter < 130)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[12]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 130 && bumper02Counter < 140)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[13]);
				bumper02Counter++;
			}
			if (bumper02Counter >= 140)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[0]);
				bumper02Counter = 0;
				pb_bumper02->playAnimation = false;
			}
		}
		else App->renderer->Blit(bumper, 710, 420, &r_bumper[0]);



		//App->renderer->Blit(bumper, 650, 600, &r_bumper[0]);

		if (pb_bumper03->playAnimation == true)
		{

			int x = 650;
			int y = 600;
			if (bumper03Counter < 10)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[0]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 10 && bumper03Counter < 20)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[1]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 20 && bumper03Counter < 30)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[2]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 30 && bumper03Counter < 40)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[3]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 40 && bumper03Counter < 50)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[4]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 50 && bumper03Counter < 60)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[5]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 60 && bumper03Counter < 70)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[6]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 70 && bumper03Counter < 80)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[7]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 80 && bumper03Counter < 90)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[8]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 90 && bumper03Counter < 100)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[9]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 100 && bumper03Counter < 110)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[10]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 110 && bumper03Counter < 120)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[11]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 120 && bumper03Counter < 130)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[12]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 130 && bumper03Counter < 140)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[13]);
				bumper03Counter++;
			}
			if (bumper03Counter >= 140)
			{
				App->renderer->Blit(bumper, x, y, &r_bumper[0]);
				bumper03Counter = 0;
				pb_bumper03->playAnimation = false;
			}
		}
		else App->renderer->Blit(bumper, 650, 600, &r_bumper[0]);

		/*
		if (bumper01Counter <= 20)
		{
		 App->renderer->Blit(bumper, 490 - 174*0, 460, &r_bumper[0]);
		 bumper01Counter++;
		}
		else if (bumper01Counter >= 20 && bumper01Counter < 40)
		{
			App->renderer->Blit(bumper, 490-174*1, 460, &r_bumper[1]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 40 && bumper01Counter < 60)
		{
			App->renderer->Blit(bumper, 490-174*2, 460, &r_bumper[2]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 60 && bumper01Counter < 80)
		{
			App->renderer->Blit(bumper, 490-174*3, 460, &r_bumper[3]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 100 && bumper01Counter < 120)
		{
			App->renderer->Blit(bumper, 490-174*4, 460, &r_bumper[4]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 120 && bumper01Counter < 140)
		{
			App->renderer->Blit(bumper, 490-174*5, 460, &r_bumper[5]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 140 && bumper01Counter < 160)
		{
			App->renderer->Blit(bumper, 490-174*6, 460, &r_bumper[6]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 160 && bumper01Counter < 180)
		{
			App->renderer->Blit(bumper, 490-174*7, 460, &r_bumper[7]);
			bumper01Counter++;
		}
		else if (bumper01Counter >= 180 && bumper01Counter < 200)
		{
			App->renderer->Blit(bumper, 490, 460, &r_bumper[8]);
			bumper01Counter++;
		}
		if(bumper01Counter == 200) bumper01Counter = 0;
		//*/
	return UPDATE_CONTINUE;
}

// TODO 8: Now just define collision callback for the circle and play bonus_fx audio
void ModuleSceneIntro::OnCollision(PhysBody* bodyA, PhysBody* bodyB)
{
	// Play Audio FX on every collision, regardless of who is colliding

	//App->audio->PlayFx(bonus_fx);
	

	// Do something else. You can also check which bodies are colliding (sensor? ball? player?)
	if ((bodyA->type == TYPE_BALL && bodyB->type == TYPE_SCORE) ||(bodyA->type == TYPE_SCORE && bodyB->type == TYPE_BALL))
	{
		
	}
}