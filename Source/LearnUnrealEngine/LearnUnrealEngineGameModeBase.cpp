// Copyright Epic Games, Inc. All Rights Reserved.


#include "LearnUnrealEngineGameModeBase.h"
#include "SandboxPawn.h"
#include "SandboxPlayerController.h"

ALearnUnrealEngineGameModeBase::ALearnUnrealEngineGameModeBase()
{
	DefaultPawnClass = ASandboxPawn::StaticClass();
	PlayerControllerClass = ASandboxPlayerController::StaticClass();
}