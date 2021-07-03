// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameModeBase.h"

ACPP_GameModeBase::ACPP_GameModeBase()
{
	// Tick �Լ��� ��� ȣ��ǵ��� ����.
	PrimaryActorTick.bCanEverTick = false;

	//UE���� BP_Player�� �־��ְ� �ִ�.
	DefaultPawnClass = NULL;

	//������Ʈ ����
	gameStateControler = CreateDefaultSubobject<UGameStateControler>(TEXT("GameStateControler"));
	widgetControler = CreateDefaultSubobject<UWidgetControler>(TEXT("WidgetControler"));
	objectPool = CreateDefaultSubobject<UObjectPools>(TEXT("ObjectPool"));
}

void ACPP_GameModeBase::InitGameState()
{
	Super::InitGameState();


	// ���� �������� ����۽�
	if (gameStateControler->GetState() == EGameState::GameOver)
	{
		/*if (widgetControler->gameoverUI)
		{
			widgetControler->CloseUI(EGameState::Intro);
		}*/
	}

	gameStateControler->SetState(EGameState::Intro);
}

void ACPP_GameModeBase::BeginPlay()
{
	Super::BeginPlay();
}

void ACPP_GameModeBase::Tick(float DeltaSeconds)
{
}
