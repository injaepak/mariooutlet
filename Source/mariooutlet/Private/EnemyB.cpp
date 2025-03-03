// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyB.h"
#include "mariooutlet.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <EnemyBMove.h>
#include "PlayerCPP.h"
// Sets default values
AEnemyB::AEnemyB()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 1. Box Collider
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = boxComp;

	// 2. 외관
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(boxComp);

	// meshComp 의 Collision 을 비활성화 한다.
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 3. 에너미 이동
	enemyBMove = CreateDefaultSubobject<UEnemyBMove>(TEXT("EnemyBMove"));
}

// Called when the game starts or when spawned
void AEnemyB::BeginPlay()
{
	Super::BeginPlay();
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyB::OnCollisionEnter);
}

// Called every frame
void AEnemyB::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AEnemyB::OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 플레이어를 불러온다.
	auto player = Cast<APlayerCPP>(OtherActor);
	if (player)
	{
		PRINTLOG(TEXT("shittttttttttttttttttttttttttttttttttttt"))
		//player->Destroy
	}
}

