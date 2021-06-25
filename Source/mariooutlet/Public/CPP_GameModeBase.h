// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStateControler.h"
#include "WidgetControler.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_GameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MARIOOUTLET_API ACPP_GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACPP_GameModeBase();

	virtual void InitGameState() override;

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UGameStateControler* gameStateControler;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UWidgetControler* widgetControler;

};
