// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <Kismet/GameplayStatics.h>
#include "EnemyAMove.h"
#include "GameFramework/Actor.h"
#include "Turtle.generated.h"

UENUM(BlueprintType)
enum class TurtleState : uint8
{
	Idle,
	Down,
	Heard,
	Throw,
	Kick,
	Dead
};

UCLASS()
class MARIOOUTLET_API ATurtle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATurtle();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	class UEnemyAMove* enemyAMove;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	TurtleState mState = TurtleState::Idle;
	void SetState(TurtleState state)
	{
		mState = state;

		if (mState == TurtleState::Throw)
		{
			frontV = player->GetActorForwardVector();
		}
	}

	TurtleState GetState()
	{
		return mState;
	}

	UPROPERTY();
	AActor* player;

	FVector frontV;
	float throwSpeed = 800;
};
