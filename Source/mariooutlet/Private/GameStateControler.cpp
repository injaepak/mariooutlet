// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_GameModeBase.h"
#include "GameStateControler.h"

// Sets default values for this component's properties
UGameStateControler::UGameStateControler()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGameStateControler::BeginPlay()
{
	Super::BeginPlay();

	gameModeBase = Cast<ACPP_GameModeBase>(GetOwner());
}


// Called every frame
void UGameStateControler::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (mState == EGameState::Intro)
	{
		IntroPage();
	}
}

void UGameStateControler::SetState(EGameState value)
{
	mState = value;

	//const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EGameState"), true);
	//PRINTLOG(TEXT("SetState : %s"), *enumPtr->GetNameStringByValue((uint8)value));
		
	if (gameModeBase)
	{
		gameModeBase->widgetControler->CloseUI(mState);
		gameModeBase->widgetControler->OpenUI(mState);
	}
	
	switch (mState)
	{
	case EGameState::Intro: 
		break;
	case EGameState::Ready:
		ReadyPage();
		break;
	case EGameState::Start:
		StartPage();
		break;
	case EGameState::GameOver:
		GameoverPage();
		break;
	default:
		break;
	}
}

void UGameStateControler::PrintEnumData_Implementation(EGameState value)
{
	const UEnum* enumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EGameState"), true);
	if (enumPtr)
	{
		PRINTLOG(TEXT("STATE : %s"), *enumPtr->GetNameStringByValue((uint8)value));
	}
}

void UGameStateControler::IntroPage()
{
	APlayerController* myController = GetWorld()->GetFirstPlayerController();

	if (myController && myController->WasInputKeyJustPressed(EKeys::AnyKey))
	{
		//PRINTLOG(TEXT("Any Key Pressed!!!!!!!!!!!!"));
		SetState(EGameState::Ready);
	}
}
void UGameStateControler::ReadyPage()
{
	gameModeBase->widgetControler->UpdateUI(mState);
}
void UGameStateControler::StartPage()
{

}
void UGameStateControler::GameoverPage()
{
	//UI 플레이어 컨트롤러 가져오기
	APlayerController* myController = GetWorld()->GetFirstPlayerController();

	//게임 일시정지
	UGameplayStatics::SetGamePaused(GetWorld(), true);

	//마우스 커서 나타내기
	myController->bShowMouseCursor = true;
}