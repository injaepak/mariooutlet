// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCPP.h"
#include <Components/StaticMeshComponent.h>
#include <Components/BoxComponent.h>

// Sets default values
APlayerCPP::APlayerCPP()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 속성에 필요한 컴포넌트 추가(선언)
	// 구현부에서 실제로 추가
	// 몸체 컴포넌트 추가
	BoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));
	RootComponent = BoxComp;

	// 외관 컴포넌트 추가
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


	//사용자가 입력한 방향으로 이동하고 싶다
	// 1. 방향이 있어야한다
	FVector Dir(0, h, 0);

	// 2. 이동하고 싶다. 등속운동 P=P0+Vt
	SetActorLocation(GetActorLocation() + Dir * MoveSpeed * DeltaTime);

}

// Called to bind functionality to input
void APlayerCPP::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// 키 입력에 따른 처리 함수를 바인딩 하자
	PlayerInputComponent->BindAxis("Horizontal", this, &APlayerCPP::InputHorizontal);

}

	// 사용자가 좌우키를 누르면 실행되는 함수
void APlayerCPP::InputHorizontal(float Value)
{
	h = Value;
}