// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyBMove.generated.h"

// 에너미가 위 아래로 들어갔다 나왔다 하게 하고싶다.
// 필요 속성 : currentTime, MaxTime, DelayTime, speed, 방향

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MARIOOUTLET_API UEnemyBMove : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UEnemyBMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

public:
	UPROPERTY(BlueprintReadOnly, Category = "Stat")
		float currentTime;

	UPROPERTY(BlueprintReadOnly, Category = "Stat")
		float maxTime = 1;

	UPROPERTY(BlueprintReadOnly, Category = "Stat")
		float delayTime = 5;

	UPROPERTY()
		FTimerHandle createTimer;

	// 올라오는 속도
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
		float speed = 400;

	// 방향
	UPROPERTY(BlueprintReadOnly, Category = "Stat")
		FVector dir = FVector(0, 0, 0);
};
