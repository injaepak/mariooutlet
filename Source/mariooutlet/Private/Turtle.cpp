// Fill out your copyright notice in the Description page of Project Settings.


#include "Turtle.h"

// Sets default values
ATurtle::ATurtle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	enemyAMove = CreateDefaultSubobject<UEnemyAMove>(TEXT("EnemyAMove"));
}

// Called when the game starts or when spawned
void ATurtle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATurtle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (mState == TurtleState::Idle)
	{
		//enemyAMove ��Ʈ�� �̵�
	}
	else if (mState == TurtleState::Down)
	{
		//enemyAMove.speed = 0;
	}
	else if (mState == TurtleState::Heard)
	{
		//player ã��
		//UGameplayStatics::GetActorOfClass(GetWorld(), APlayerCPP::StaticClass(), player);
		if (player)
		{
			SetActorLocation(player->GetActorLocation()+10*player->GetActorForwardVector());
		}
	}
	else if (mState == TurtleState::Throw)
	{
		if (player)
		{
			//FrontVector �������� ���ư���
			auto p = GetActorLocation();
			auto p1 = p + frontV * throwSpeed * DeltaTime;
			SetActorLocation(p1);
		}
	}
	else if (mState == TurtleState::Kick)
	{
		//enemyAMove  Speed 
	}
	else if (mState == TurtleState::Dead)
	{
		//player���� �浹 ����. ������ �浹 ����

	}
}

