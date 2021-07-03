// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Brick.generated.h"

UCLASS()
class MARIOOUTLET_API ABrick : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABrick();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	bool isHasItem = false;
	UPROPERTY(EditAnywhere)
	bool isActive = false;
	UPROPERTY(EditAnywhere)
	bool canDestroy = false;
	UPROPERTY(EditAnywhere)
	bool canChangedCoin = false;

	//벽돌에 숨어있는 아이탬 정보
	// 0 None, 1 Coin, 2 BigMush, 3 LifeMush, 4 FireFlower
	int itemIdx = 0;

	UFUNCTION()
	void OnCollisionEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
