// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_Moteur01GameMode.h"
#include "TP_Moteur01Character.h"
#include "UObject/ConstructorHelpers.h"

ATP_Moteur01GameMode::ATP_Moteur01GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
