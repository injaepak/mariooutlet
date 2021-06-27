// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "mariooutlet.h"
#include <Kismet/GameplayStatics.h>
#include "Components/ActorComponent.h"
#include "GameStateControler.generated.h"


UENUM(BlueprintType)
enum class EGameState : uint8
{
	Intro,
	Ready,
	Start,
	GameOver
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MARIOOUTLET_API UGameStateControler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGameStateControler();

	UFUNCTION(BlueprintNativeEvent, Category = "PrintLog")
	void PrintEnumData(EGameState value);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	EGameState GetState()
	{
		return mState;
	}
	void SetState(EGameState value);

private:
	//  GameModeBase 이 컴포넌트를 소유하고 있는 객체
	//소유하고 있는 Actor 객체
	UPROPERTY()
	class ACPP_GameModeBase* gameModeBase;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GameState", meta = (AllowPrivateAccess = true))
	EGameState mState = EGameState::Intro;

	void IntroPage();
	void ReadyPage();
	void StartPage();
	void GameoverPage();
};
