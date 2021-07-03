// Fill out your copyright notice in the Description page of Project Settings.

#include "CPP_GameModeBase.h"
#include "Brick.h"

// Sets default values
ABrick::ABrick()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABrick::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABrick::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABrick::OnCollisionEnter(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	auto gameMode = Cast<ACPP_GameModeBase>(GetWorld()->GetAuthGameMode());

	//TODO
	//OtherActor Player ���� Ȯ���ϱ�
	//auto player = Cast<>(OtherActor);

	if (gameMode)
	{
		// Coin�� ��� ���� ��ȯ�ϱ�
		
		if (isHasItem == true && isActive == false)
		{
			// �������� �����Ѵ�.
			gameMode->objectPool->SpawnItem(itemIdx, GetActorLocation());
			isActive = true;
		}
	}

	if (canDestroy)
	{
		//������ �μ�����.
		Destroy();
	}
}
