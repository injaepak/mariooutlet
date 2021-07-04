// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameStateControler.h"
#include "WidgetControler.h"
#include "ObjectPools.h"
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

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UObjectPools* objectPool;

	UPROPERTY(EditAnyWhere)
	int life = 5;
	int coin = 0;
	int point = 0;

	void AddPoint(int num)
	{
		point += num;
	}
	void AddCoin(int num)
	{
		coin += num;
	}
	void AddLife()
	{
		life++;
	}
	void MinusLife()
	{
		life--;
	}


};
