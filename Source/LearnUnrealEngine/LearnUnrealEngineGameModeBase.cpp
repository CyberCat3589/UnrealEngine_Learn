// Copyright Epic Games, Inc. All Rights Reserved.


#include "LearnUnrealEngineGameModeBase.h"
#include "SandboxPawn.h"

ALearnUnrealEngineGameModeBase::ALearnUnrealEngineGameModeBase()
{
	DefaultPawnClass = ASandboxPawn::StaticClass();
}