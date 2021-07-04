// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "mariooutlet.h"
#include <Kismet/GameplayStatics.h>
#include <Components/BoxComponent.h>
#include "Engine/Classes/GameFramework/ProjectileMovementComponent.h"
#include <Components/StaticMeshComponent.h>
#include "EnemyAMove.h"
#include "PlayerCPP.h"
#include "EnemyBackZone.h"
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

	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
	//class UEnemyAMove* enemyAMove;

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

	float speed = 500;
	FVector dir = FVector::LeftVector;
	float throwSpeed = 800;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UProjectileMovementComponent* projectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* bodyMesh;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UStaticMeshComponent* shellMesh;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UBoxComponent* boxComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
	class UBoxComponent* headBoxComp;

	bool isFloor = false;
	void SetisFloor(bool value);
	float height;

	UFUNCTION()
	void OnHitCollisionEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	UFUNCTION() 
	void OnHeadOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Move(float DeltaTime);

	bool bTurn = false;
	float curTime;
	float turnVelo = -160;
	FRotator oldRotate;

	void Turn();
	bool Turning(float DeltaTime);
};
