// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Blueprint/UserWidget.h>
#include <mariooutlet/Public/GameStateControler.h>
#include "UI_Ingame.h"
#include "Components/ActorComponent.h"
#include "WidgetControler.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MARIOOUTLET_API UWidgetControler : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UWidgetControler();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void OpenUI(EGameState state);
	void CloseUI(EGameState state);

	//TODO
	//void IsOpened();

	//  GameModeBase 이 컴포넌트를 소유하고 있는 객체
		//소유하고 있는 Actor 객체
	UPROPERTY()
	class ACPP_GameModeBase* gameModeBase;

	//  INTRO
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UUserWidget> introUIFactory;

	UPROPERTY()
	class UUserWidget* introUI;

	//  INGAME
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = true))
		TSubclassOf<class UUserWidget> ingameUIFactory;

	UPROPERTY()
	class UUI_Ingame* ingameUI;

	//  GAMEOVER
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "UI", meta = (AllowPrivateAccess = true))
	TSubclassOf<class UUserWidget> gameoverUIFactory;

	UPROPERTY()
	class UUserWidget* gameoverUI;
};
