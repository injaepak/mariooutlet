// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyA.h"
#include "mariooutlet.h"
#include <Components/BoxComponent.h>
#include <Components/StaticMeshComponent.h>
#include <EnemyAMove.h>
#include "PlayerCPP.h"
#include "CPP_GameModeBase.h"



// Sets default values
AEnemyA::AEnemyA()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	// Tick �� ��� ����� ������ ����.
	PrimaryActorTick.bCanEverTick = false;

	// 1. Box Collider
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = boxComp;

	headBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HeadBoxCollider"));
	headBoxComp->SetupAttachment(boxComp);

	// 2. �ܰ�
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(boxComp);

	// meshComp �� Collision �� ��Ȱ��ȭ �Ѵ�.
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 3. ���ʹ� �̵�
	enemyAMove = CreateDefaultSubobject<UEnemyAMove>(TEXT("EnemyAMove"));

}
// Called when the game starts or when spawned
void AEnemyA::BeginPlay()
{
	Super::BeginPlay();

	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyA::OnCollisionEnter);
	headBoxComp->OnComponentBeginOverlap.AddDynamic(this, &AEnemyA::OnHeadOverlapBegin);
}

// Called every frame
void AEnemyA::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AEnemyA::OnCollisionEnter(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//GameStateControler �� �θ��� GameModeBase �� �����´�
	//auto gameMode = Cast<ACPP_GameModeBase>(GetWorld()->GetAuthGameMode());
	// �÷��̾ �ҷ��´�.
	auto player = Cast<APlayerCPP>(OtherActor);
	

	if (player)
	{
		
		//gameMode->gameStateControler(EGameState::GameOver);
		//player->Destroy();
	}
}

void AEnemyA::OnHeadOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// �÷��̾ �ҷ��´�.
	auto player = Cast<APlayerCPP>(OtherActor);
	// Scale �� ���� ��ġ
	FVector scaleDown = FVector(1,1, 0.2);
	// ���� �浹�� ��ü�� Player���
	if (player)
	{
		PRINTLOG(TEXT("Overlap"));
		// Scale�� ������ ��ŭ Set ���ش�.
		SetActorScale3D(scaleDown);
		// speed �� 0 ����
		enemyAMove->speed = 0;

		// Scale �� �پ��°� �����ֱ� ���� DestroyActor �� ���߿� Ÿ�̸ӿ� �Բ� �߰�.
	}
}
