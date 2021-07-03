// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPP.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

// Sets default values
APlayerCPP::APlayerCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// �Ӽ��� �ʿ��� ������Ʈ �߰�(����)
	// �����ο��� ������ �߰�
	// ��ü ������Ʈ �߰�
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxComp;

	// �ܰ� ������Ʈ �߰�
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	MeshComp->SetupAttachment(BoxComp);
}

// Called when the game starts or when spawned
void APlayerCPP::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerCPP::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	//����ڰ� �Է��� �������� �̵��ϰ� �ʹ�
	// 1. ������ �־���Ѵ�
	FVector Dir(0, h, 0);

	// 2. �̵��ϰ� �ʹ�. ��ӿ P=P0+Vt
	SetActorLocation(GetActorLocation() + Dir * MoveSpeed * DeltaTime);

}

// Called to bind functionality to input
void APlayerCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Ű �Է¿� ���� ó�� �Լ��� ���ε� ����
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerCPP::InputHorizontal);

}

	// ����ڰ� �¿�Ű�� ������ ����Ǵ� �Լ�
void APlayerCPP::InputHorizontal(float Value)
{
	h = Value;
}