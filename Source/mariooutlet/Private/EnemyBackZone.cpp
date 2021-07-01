// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyBackZone.h"
#include <Components/StaticMeshComponent.h>
#include "CPP_GameModeBase.h"
#include "EnemyA.h"

// Sets default values
AEnemyBackZone::AEnemyBackZone()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 추가
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	RootComponent = meshComp;
}

// Called when the game starts or when spawned
void AEnemyBackZone::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AEnemyBackZone::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
