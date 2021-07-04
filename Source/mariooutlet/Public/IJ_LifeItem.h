// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "IJ_LifeItem.generated.h"

UCLASS()
class MARIOOUTLET_API AIJ_LifeItem : public AActor
{
	GENERATED_BODY()
public:
	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxComp;
	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UStaticMeshComponent* meshComp;

	// ItemMove 로 수정해야함
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		class UEnemyAMove* enemyAMove;
	
public:	
	// Sets default values for this actor's properties
	AIJ_LifeItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
