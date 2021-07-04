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

	// Tick 을 계속 사용할 이유가 없다.
	PrimaryActorTick.bCanEverTick = false;

	// 1. Box Collider
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollider"));
	RootComponent = boxComp;

	headBoxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("HeadBoxCollider"));
	headBoxComp->SetupAttachment(boxComp);

	// 2. 외관
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	meshComp->SetupAttachment(boxComp);

	// meshComp 의 Collision 을 비활성화 한다.
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	// 3. 에너미 이동
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
	//GameStateControler 의 부모인 GameModeBase 를 가져온다
	//auto gameMode = Cast<ACPP_GameModeBase>(GetWorld()->GetAuthGameMode());
	// 플레이어를 불러온다.
	auto player = Cast<APlayerCPP>(OtherActor);
	

	if (player)
	{
		
		//gameMode->gameStateControler(EGameState::GameOver);
		//player->Destroy();
	}
}

void AEnemyA::OnHeadOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// 플레이어를 불러온다.
	auto player = Cast<APlayerCPP>(OtherActor);
	// Scale 을 낮출 수치
	FVector scaleDown = FVector(1,1, 0.2);
	// 만약 충돌한 물체가 Player라면
	if (player)
	{
		PRINTLOG(TEXT("Overlap"));
		// Scale을 설정값 만큼 Set 해준다.
		SetActorScale3D(scaleDown);
		// speed 를 0 으로
		enemyAMove->speed = 0;

		// Scale 이 줄어드는걸 보여주기 위해 DestroyActor 는 나중에 타이머와 함께 추가.
	}
}
