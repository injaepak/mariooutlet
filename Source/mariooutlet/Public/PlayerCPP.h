// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PlayerCPP.generated.h"

UCLASS()
class MARIOOUTLET_API APlayerCPP : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCPP();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	// 충돌목적 몸체
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Body")
		class UBoxComponent* BoxComp;
	// 외관
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Body")
		class UStaticMeshComponent* MeshComp;

	// 사용자의 입력에따라 좌우 이동
	// 필요속성 : 이동속도, 방향
	float MoveSpeed = 500;
	// 움직일방향
	float h = 0;
	// 필요기능 : 상하입력을 받는기능, 좌우입력을 받는기능
	void InputHorizontal(float Value);

};
