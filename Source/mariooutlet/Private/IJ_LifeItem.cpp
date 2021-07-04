// Fill out your copyright notice in the Description page of Project Settings.


#include "IJ_LifeItem.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <EnemyAMove.h>
#include "mariooutlet.h"

// Sets default values
AIJ_LifeItem::AIJ_LifeItem()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = boxComp;

	// 2. �ܰ�
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(boxComp);

	// meshComp �� Collision �� ��Ȱ��ȭ �Ѵ�.
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 3. ���ʹ� �̵�
	enemyAMove = CreateDefaultSubobject<UEnemyAMove>(TEXT("EnemyAMove"));
}

// Called when the game starts or when spawned
void AIJ_LifeItem::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AIJ_LifeItem::OnOverlapBegin);
}

// Called every frame
void AIJ_LifeItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIJ_LifeItem::OnOverlapBegin(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Life �� 1 �ø���.
	PRINTLOG(TEXT("Life ++"))
}

	


