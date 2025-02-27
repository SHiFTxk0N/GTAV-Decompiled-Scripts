#region Local Var
	var uLocal_0 = 0;
	var uLocal_1 = 0;
	int iLocal_2 = 0;
	int iLocal_3 = 0;
	int iLocal_4 = 0;
	int iLocal_5 = 0;
	int iLocal_6 = 0;
	int iLocal_7 = 0;
	int iLocal_8 = 0;
	int iLocal_9 = 0;
	int iLocal_10 = 0;
	int iLocal_11 = 0;
	var uLocal_12 = 0;
	var uLocal_13 = 0;
	float fLocal_14 = 0f;
	var uLocal_15 = 0;
	var uLocal_16 = 0;
	int iLocal_17 = 0;
	int iLocal_18 = 0;
	eCharacter echLocal_19 = CHAR_MICHAEL;
	Ped pedLocal_20 = 0;
#endregion

void main() // Position - 0x0
{
	iLocal_2 = 1;
	iLocal_3 = 134;
	iLocal_4 = 134;
	iLocal_5 = 1;
	iLocal_6 = 1;
	iLocal_7 = 1;
	iLocal_8 = 134;
	iLocal_9 = 1;
	iLocal_10 = 12;
	iLocal_11 = 12;
	fLocal_14 = 0.001f;
	iLocal_17 = -1;

	if (PLAYER::HAS_FORCE_CLEANUP_OCCURRED(2) || REPLAY::REPLAY_SYSTEM_HAS_REQUESTED_A_SCRIPT_CLEANUP())
		SCRIPT::TERMINATE_THIS_THREAD();

	func_1();
	return;
}

void func_1() // Position - 0x4F
{
	Vector3 entityCoords;
	int taskSequenceId;

	while (!func_9(&pedLocal_20))
	{
		SYSTEM::WAIT(0);
	}

	if (!PED::IS_PED_INJURED(pedLocal_20))
	{
		if (!Global_97176)
		{
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(pedLocal_20, true, true);
		
			if (TASK::GET_SCRIPT_TASK_STATUS(pedLocal_20, SCRIPT_TASK_ANY) != 7)
				TASK::CLEAR_PED_TASKS(pedLocal_20);
		
			entityCoords = { ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false) };
			PED::SET_BLOCKING_OF_NON_TEMPORARY_EVENTS(pedLocal_20, true);
			TASK::OPEN_SEQUENCE_TASK(&taskSequenceId);
		
			if (!PED::IS_PED_IN_ANY_VEHICLE(pedLocal_20, false))
				if (!PED::IS_PED_IN_COMBAT(pedLocal_20, 0) && !PED::IS_PED_IN_ANY_VEHICLE(pedLocal_20, false))
					TASK::TASK_TURN_PED_TO_FACE_COORD(0, entityCoords, 6000);
		
			TASK::TASK_LOOK_AT_COORD(0, entityCoords, 6000, 0, 2);
			TASK::CLOSE_SEQUENCE_TASK(taskSequenceId);
			TASK::TASK_PERFORM_SEQUENCE(pedLocal_20, taskSequenceId);
		}
	
		func_2(pedLocal_20);
	}

	while (!CAM::IS_SCREEN_FADED_OUT())
	{
		SYSTEM::WAIT(0);
	}

	if (ENTITY::DOES_ENTITY_EXIST(pedLocal_20))
	{
		if (!PED::IS_PED_INJURED(pedLocal_20))
			PED::SET_PED_KEEP_TASK(pedLocal_20, true);
	
		ENTITY::SET_PED_AS_NO_LONGER_NEEDED(&pedLocal_20);
	}

	Global_97176 = false;
	SCRIPT::TERMINATE_THIS_THREAD();
	return;
}

void func_2(Ped pedParam0) // Position - 0x13C
{
	int num;

	num = MISC::GET_GAME_TIMER() + 1000;

	while (MISC::GET_GAME_TIMER() < num && !CAM::IS_SCREEN_FADED_OUT())
	{
		SYSTEM::WAIT(0);
	}

	if (!PED::IS_PED_INJURED(pedParam0))
	{
		if (echLocal_19 == CHAR_FRANKLIN)
		{
			switch (_GET_PLAYER_CHARACTER_FROM_PED(PLAYER::PLAYER_PED_ID()))
			{
				case CHAR_TREVOR:
					func_3(pedParam0, "BUDDY_SEES_TREVOR_DEATH", "FRANKLIN_NORMAL", 3);
					break;
			
				case CHAR_MICHAEL:
					func_3(pedParam0, "BUDDY_SEES_MICHAEL_DEATH", "FRANKLIN_NORMAL", 3);
					break;
			}
		}
		else if (echLocal_19 == CHAR_TREVOR)
		{
			switch (_GET_PLAYER_CHARACTER_FROM_PED(PLAYER::PLAYER_PED_ID()))
			{
				case CHAR_FRANKLIN:
					func_3(pedParam0, "BUDDY_SEES_FRANKLIN_DEATH", "TREVOR_NORMAL", 3);
					break;
			
				case CHAR_MICHAEL:
					func_3(pedParam0, "BUDDY_SEES_MICHAEL_DEATH", "TREVOR_NORMAL", 3);
					break;
			}
		}
		else if (echLocal_19 == CHAR_MICHAEL)
		{
			switch (_GET_PLAYER_CHARACTER_FROM_PED(PLAYER::PLAYER_PED_ID()))
			{
				case CHAR_TREVOR:
					func_3(pedParam0, "BUDDY_SEES_TREVOR_DEATH", "MICHAEL_NORMAL", 3);
					break;
			
				case CHAR_FRANKLIN:
					func_3(pedParam0, "BUDDY_SEES_FRANKLIN_DEATH", "MICHAEL_NORMAL", 3);
					break;
			}
		}
	}

	return;
}

void func_3(Ped pedParam0, char* sParam1, char* sParam2, int iParam3) // Position - 0x234
{
	AUDIO::PLAY_PED_AMBIENT_SPEECH_WITH_VOICE_NATIVE(pedParam0, sParam1, sParam2, func_4(iParam3), false);
	return;
}

char* func_4(int iParam0) // Position - 0x24D
{
	char* str;

	switch (iParam0)
	{
		case 0:
			return "SPEECH_PARAMS_STANDARD";
	
		case 1:
			return "SPEECH_PARAMS_ALLOW_REPEAT";
	
		case 2:
			return "SPEECH_PARAMS_BEAT";
	
		case 3:
			return "SPEECH_PARAMS_FORCE";
	
		case 4:
			return "SPEECH_PARAMS_FORCE_FRONTEND";
	
		case 5:
			return "SPEECH_PARAMS_FORCE_NO_REPEAT_FRONTEND";
	
		case 6:
			return "SPEECH_PARAMS_FORCE_NORMAL";
	
		case 7:
			return "SPEECH_PARAMS_FORCE_NORMAL_CLEAR";
	
		case 8:
			return "SPEECH_PARAMS_FORCE_NORMAL_CRITICAL";
	
		case 9:
			return "SPEECH_PARAMS_FORCE_SHOUTED";
	
		case 10:
			return "SPEECH_PARAMS_FORCE_SHOUTED_CLEAR";
	
		case 11:
			return "SPEECH_PARAMS_FORCE_SHOUTED_CRITICAL";
	
		case 12:
			return "SPEECH_PARAMS_FORCE_PRELOAD_ONLY";
	
		case 13:
			return "SPEECH_PARAMS_MEGAPHONE";
	
		case 14:
			return "SPEECH_PARAMS_HELI";
	
		case 15:
			return "SPEECH_PARAMS_FORCE_MEGAPHONE";
	
		case 16:
			return "SPEECH_PARAMS_FORCE_HELI";
	
		case 17:
			return "SPEECH_PARAMS_INTERRUPT";
	
		case 18:
			return "SPEECH_PARAMS_INTERRUPT_SHOUTED";
	
		case 19:
			return "SPEECH_PARAMS_INTERRUPT_SHOUTED_CLEAR";
	
		case 20:
			return "SPEECH_PARAMS_INTERRUPT_SHOUTED_CRITICAL";
	
		case 21:
			return "SPEECH_PARAMS_INTERRUPT_NO_FORCE";
	
		case 22:
			return "SPEECH_PARAMS_INTERRUPT_FRONTEND";
	
		case 23:
			return "SPEECH_PARAMS_INTERRUPT_NO_FORCE_FRONTEND";
	
		case 24:
			return "SPEECH_PARAMS_ADD_BLIP";
	
		case 25:
			return "SPEECH_PARAMS_ADD_BLIP_ALLOW_REPEAT";
	
		case 26:
			return "SPEECH_PARAMS_ADD_BLIP_FORCE";
	
		case 27:
			return "SPEECH_PARAMS_ADD_BLIP_SHOUTED";
	
		case 28:
			return "SPEECH_PARAMS_ADD_BLIP_SHOUTED_FORCE";
	
		case 29:
			return "SPEECH_PARAMS_ADD_BLIP_INTERRUPT";
	
		case 30:
			return "SPEECH_PARAMS_ADD_BLIP_INTERRUPT_FORCE";
	
		case 31:
			return "SPEECH_PARAMS_FORCE_PRELOAD_ONLY_SHOUTED";
	
		case 32:
			return "SPEECH_PARAMS_FORCE_PRELOAD_ONLY_SHOUTED_CLEAR";
	
		case 33:
			return "SPEECH_PARAMS_FORCE_PRELOAD_ONLY_SHOUTED_CRITICAL";
	
		case 34:
			return "SPEECH_PARAMS_SHOUTED";
	
		case 35:
			return "SPEECH_PARAMS_SHOUTED_CLEAR";
	
		case 36:
			return "SPEECH_PARAMS_SHOUTED_CRITICAL";
	
		default:
		
	}

	str = 0;
	return str;
}

eCharacter _GET_PLAYER_CHARACTER_FROM_PED(Ped pedParam0) // Position - 0x43C
{
	eCharacter i;
	Hash entityModel;

	if (ENTITY::DOES_ENTITY_EXIST(pedParam0))
	{
		entityModel = ENTITY::GET_ENTITY_MODEL(pedParam0);
	
		for (i = CHAR_MICHAEL; i <= CHAR_TREVOR; i = i + 1)
		{
			if (_GET_CHARACTER_MODEL(i) == entityModel)
				return i;
		}
	}

	return _CHAR_NULL;
}

Hash _GET_CHARACTER_MODEL(eCharacter character) // Position - 0x479
{
	if (func_8(character))
		return func_7(character);
	else
		character != _CHAR_NULL;

	return 0;
}

Hash func_7(eCharacter echParam0) // Position - 0x49E
{
	return Global_2028[echParam0 /*29*/];
}

BOOL func_8(eCharacter echParam0) // Position - 0x4AD
{
	return echParam0 < CHAR_MULTIPLAYER;
}

BOOL func_9(var uParam0) // Position - 0x4B9
{
	Vehicle vehiclePedIsIn;

	for (iLocal_18 = 0; iLocal_18 < 9; iLocal_18 = iLocal_18 + 1)
	{
		if (ENTITY::DOES_ENTITY_EXIST(Global_98050[iLocal_18]) && !PED::IS_PED_INJURED(Global_98050[iLocal_18]))
		{
			if (Global_98050[iLocal_18] != PLAYER::PLAYER_PED_ID())
			{
				if (!ENTITY::IS_ENTITY_A_MISSION_ENTITY(Global_98050[iLocal_18]))
				{
					if (PED::IS_PED_IN_ANY_VEHICLE(Global_98050[iLocal_18], false) || !ENTITY::IS_ENTITY_ATTACHED(Global_98050[iLocal_18]))
					{
						if (MISC::GET_DISTANCE_BETWEEN_COORDS(ENTITY::GET_ENTITY_COORDS(Global_98050[iLocal_18], true), ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), false), true) < 10f)
						{
							echLocal_19 = _GET_PLAYER_CHARACTER_FROM_PED(Global_98050[iLocal_18]);
						
							if (echLocal_19 == CHAR_MICHAEL || echLocal_19 == CHAR_TREVOR || echLocal_19 == CHAR_FRANKLIN)
							{
								if (echLocal_19 != _GET_CURRENT_PLAYER_CHARACTER())
								{
									if (ENTITY::HAS_ENTITY_CLEAR_LOS_TO_ENTITY(Global_98050[iLocal_18], PLAYER::PLAYER_PED_ID(), 17))
									{
										if (PED::IS_PED_IN_ANY_VEHICLE(Global_98050[iLocal_18], false))
											vehiclePedIsIn = PED::GET_VEHICLE_PED_IS_IN(Global_98050[iLocal_18], false);
									
										if (ENTITY::DOES_ENTITY_EXIST(vehiclePedIsIn) && VEHICLE::IS_VEHICLE_DRIVEABLE(vehiclePedIsIn, false) || !ENTITY::DOES_ENTITY_EXIST(vehiclePedIsIn))
										{
											*uParam0 = Global_98050[iLocal_18];
											return true;
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}

	if (CAM::IS_SCREEN_FADED_OUT())
		return true;

	return false;
}

eCharacter _GET_CURRENT_PLAYER_CHARACTER() // Position - 0x5FE
{
	func_11();
	return Global_113648.f_2365.f_539.f_4321;
}

void func_11() // Position - 0x617
{
	eCharacter character;

	if (ENTITY::DOES_ENTITY_EXIST(PLAYER::PLAYER_PED_ID()))
	{
		if (_GET_CHARACTER_MODEL(Global_113648.f_2365.f_539.f_4321) != ENTITY::GET_ENTITY_MODEL(PLAYER::PLAYER_PED_ID()))
		{
			character = _GET_PLAYER_CHARACTER_FROM_PED(PLAYER::PLAYER_PED_ID());
		
			if (func_8(character) && !func_12(14) || Global_112599)
			{
				if (Global_113648.f_2365.f_539.f_4321 != character && func_8(Global_113648.f_2365.f_539.f_4321))
					Global_113648.f_2365.f_539.f_4322 = Global_113648.f_2365.f_539.f_4321;
			
				Global_113648.f_2365.f_539.f_4323 = character;
				Global_113648.f_2365.f_539.f_4321 = character;
				return;
			}
		}
		else
		{
			if (Global_113648.f_2365.f_539.f_4321 != _CHAR_NULL)
				Global_113648.f_2365.f_539.f_4323 = Global_113648.f_2365.f_539.f_4321;
		
			return;
		}
	}

	Global_113648.f_2365.f_539.f_4321 = 145;
	return;
}

BOOL func_12(int iParam0) // Position - 0x714
{
	return Global_43257 == iParam0;
}

