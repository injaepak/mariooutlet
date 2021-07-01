// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyAMove.h"
#include "EnemyA.h"
#include "mariooutlet.h"
#include "EnemyBackzone.h"

// Sets default values for this component's properties
UEnemyAMove::UEnemyAMove()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	
	// 계속 움직여야 하니까 True
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UEnemyAMove::BeginPlay()
{
	Super::BeginPlay();

	// ...
	// 플레이어가 왼쪽에서 오른쪽으로 이동하니까
	// 에너미도 왼쪽방향으로 먼저 움직이게 한다.
	dir = FVector::LeftVector;
	dir.Normalize();
}


// Called every frame
void UEnemyAMove::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FVector vel = dir * speed;

	FVector P0 = GetOwner()->GetActorLocation();
	FVector P = P0 + vel * DeltaTime;

	GetOwner()->SetActorLocation(P, true);
}
// Enemy 가 EnemyBackZone 에 부딪혔을 떄 dir * -1 을 해서 방향을 반대로 바꿔준다.
// 필요 속성 : EnemyBackZone
void UEnemyAMove::OnCollisionEnter(AActor * OtherActor)
{
	auto ebz = Cast<AEnemyBackZone>(OtherActor);
	if (ebz)
	{
		PRINTLOG(TEXT("111111111111111"));
		// 방향을 반대로 바꿔준다.
		dir = dir * -1;

		//// R = R0 + rt
		//FRotator R0 = GetOwner()->GetActorRotation();
		//FRotator r = FRotator();
		
		//for (int i = 1; i <= 180; ++i)
		//{
		//	r = FRotator(0, 0, i);
		//	PRINTLOG(TEXT("2222222222222"));
		//}
		//PRINTLOG(TEXT("3333333333333"));
		//GetOwner()->SetActorRotation(r);
	}
}

	
	

// 만약 부딪힌것이 EnemyBackZone 이라면 dir을 -로 주자.
