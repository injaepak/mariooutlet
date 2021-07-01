// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "EnemyAMove.generated.h"

// 필요속성 : 이동속도, 이동방향, OnTriggerEnter 


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MARIOOUTLET_API UEnemyAMove : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UEnemyAMove();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 이동속도
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stat")
		float speed = 500;
	// 방향
	UPROPERTY(BlueprintReadOnly, Category = "Stat")
		FVector dir = FVector(0, 0, 0);


	// 충돌
	UFUNCTION(BlueprintCallable, Category = "Code")
		void OnCollisionEnter(AActor* OtherActor);
};
