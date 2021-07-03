// Fill out your copyright notice in the Description page of Project Settings.


#include "ObjectPools.h"

// Sets default values for this component's properties
UObjectPools::UObjectPools()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UObjectPools::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UObjectPools::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UObjectPools::SpawnItem(int itemIdx, FVector location)
{
	//itemIdx에 따라서 location보다 좀 더 위에서 아이템이 스폰된다.
}

