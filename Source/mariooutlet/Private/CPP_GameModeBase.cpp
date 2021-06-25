// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameModeBase.h"

ACPP_GameModeBase::ACPP_GameModeBase()
{
	// Tick 함수가 계속 호출되도록 설정.
	PrimaryActorTick.bCanEverTick = false;

	//UE에서 BP_Player를 넣어주고 있다.
	DefaultPawnClass = NULL;

	//컴포넌트 부착
	gameStateControler = CreateDefaultSubobject<UGameStateControler>(TEXT("GameStateControler"));
	widgetControler = CreateDefaultSubobject<UWidgetControler>(TEXT("WidgetControler"));
}

void ACPP_GameModeBase::InitGameState()
{
	Super::InitGameState();
}

void ACPP_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_GameModeBase::Tick(float DeltaSeconds)
{
}