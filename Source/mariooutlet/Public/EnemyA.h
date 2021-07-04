// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "EnemyA.generated.h"


UCLASS()
class MARIOOUTLET_API AEnemyA : public AActor
{
	GENERATED_BODY()

public:
	// 에너미의 몸체를 만들고 싶다.
	// 필요 속성 : boxComp, meshComp, 
	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* boxComp;
	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UStaticMeshComponent* meshComp;

	UPROPERTY(VisibleAnywhere, Category = "Component")
		class UBoxComponent* headBoxComp;

	// EnemyAMove 라는 레고블럭을 추가해야 한다.
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		class UEnemyAMove* enemyAMove;
	//UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Component")
		//class UEnemyAMove* enemyAMove;

public:
	// Sets default values for this actor's properties
	AEnemyA();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	

	UFUNCTION()
		void OnCollisionEnter(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	UFUNCTION()
		void OnHeadOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);


};
