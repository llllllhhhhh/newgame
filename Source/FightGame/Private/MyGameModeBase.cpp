// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"
#include "MyCharacter.h"
#include "MyPlayerController.h"
#include "MyHUD.h"
#include "MyGameStateBase.h"
#include "MyPlayerState.h"

AMyGameModeBase::AMyGameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();
	PlayerControllerClass = AMyPlayerController::StaticClass();
	HUDClass = AMyHUD::StaticClass();
	//GameState = AMyGameStateBase::StaticClass();
	PlayerStateClass = AMyPlayerState::StaticClass();
}

void AMyGameModeBase::BeginPlay()
{
	
}

void AMyGameModeBase::SetGableTime(float Timer)
{
	
}
