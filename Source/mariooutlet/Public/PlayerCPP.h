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
	// �浹���� ��ü
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Body")
		class UBoxComponent* BoxComp;
	// �ܰ�
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Body")
		class UStaticMeshComponent* MeshComp;

	// ������� �Է¿����� �¿� �̵�
	// �ʿ�Ӽ� : �̵��ӵ�, ����
	float MoveSpeed = 500;
	// �����Ϲ���
	float h = 0;
	// �ʿ��� : �����Է��� �޴±��, �¿��Է��� �޴±��
	void InputHorizontal(float Value);

};
