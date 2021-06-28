// Fill out your copyright notice in the Description page of Project Settings.


#include <Components/TextBlock.h>
#include "UI_Ingame.h"

void UUI_Ingame::NativeTick(const FGeometry& MyGeometry, float DeltaSeconds)
{
	Super::NativeTick(MyGeometry, DeltaSeconds);

	if (limitTime <= 0)
	{
		//GameOver
	}

	curTime += DeltaSeconds;

	if (curTime >= 1)
	{
		limitTime -= 1;
		PrintLimitTime();
		curTime = 0;
	}
}

void UUI_Ingame::PrintLimitTime()
{
	if (Time_Text)
	{
		FString timeStr = FString::Printf(TEXT("%000d"), limitTime);
		Time_Text->SetText(FText::FromString(timeStr));
	}
}

void UUI_Ingame::PrintLife(int life)
{
	if (Life_Text)
	{
		FString lifeStr = FString::Printf(TEXT("%00d"), life);
		Life_Text->SetText(FText::FromString(lifeStr));
	}
}

void UUI_Ingame::PrintCoin(int coin)
{
	if (Coin_Text)
	{
		FString coinStr = FString::Printf(TEXT("%000d"), coin);
		Coin_Text->SetText(FText::FromString(coinStr));
	}
}

void UUI_Ingame::PrintPoint(int point)
{
	if (Point_Text)
	{
		FString pointStr = FString::Printf(TEXT("%0000000000d"), point);
		Point_Text->SetText(FText::FromString(pointStr));
	}
}
