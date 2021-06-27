// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_GameModeBase.h"
#include "WidgetControler.h"

// Sets default values for this component's properties
UWidgetControler::UWidgetControler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UWidgetControler::BeginPlay()
{
	Super::BeginPlay();

	gameModeBase = Cast<ACPP_GameModeBase>(GetOwner());

	if (introUIFactory)
	{
		introUI = CreateWidget<UUserWidget>(GetWorld(), introUIFactory);
		// viewport에 보이도록 하기
		introUI->AddToViewport();
	}

	if (ingameUIFactory)
	{
		ingameUI = CreateWidget<UUI_Ingame>(GetWorld(), ingameUIFactory);
	}

	if (gameoverUIFactory)
	{
		gameoverUI = CreateWidget<UUserWidget>(GetWorld(), gameoverUIFactory);
	}
	
}


// Called every frame
void UWidgetControler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UWidgetControler::OpenUI(EGameState state)
{
	if (state == EGameState::Intro)
	{
		if (introUI && introUI->IsInViewport() == false)
		{
			introUI->AddToViewport();
		}
	}
	else if (state == EGameState::Ready)
	{
		ingameUI->AddToViewport();
	}
	else if (state == EGameState::Start)
	{

	}
	else if (state == EGameState::GameOver)
	{
		gameoverUI->AddToViewport();
	}
}

void UWidgetControler::CloseUI(EGameState state)
{
	if (state == EGameState::Intro)
	{
		//if (introUI->IsInViewport() == false)
		//{
		//	//introUI->AddToViewport();
		//}
		// 
		//재시작시 이전 화면을 닫아준다.
		if (ingameUI && ingameUI->IsInViewport())
		{
			ingameUI->RemoveFromViewport();
		}
	}
	else if (state == EGameState::Ready)
	{
		if (introUI)
		{
			introUI->RemoveFromViewport();
		}
	}
	else if (state == EGameState::Start)
	{

	}
	else if (state == EGameState::GameOver)
	{
		
	}
}


