// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include <Kismet/GameplayStatics.h>
#include <Components/Button.h>
#include <Components/TextBlock.h>
#include "UI_Gameover.generated.h"

/**
 * 
 */
UCLASS()
class MARIOOUTLET_API UUI_Gameover : public UUserWidget
{
	GENERATED_BODY()
	
public:
	//생성자   BP 내부의 Event Construct에서 얘를 호출한다.
	virtual void NativeConstruct() override;

	UFUNCTION()
	void OnRestartClicked();
	UFUNCTION()
	void OnQuitClicked();

	//UI 위젯 가져오기
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Button_Restart;
	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	class UButton* Button_Quit;

	UFUNCTION(BlueprintCallable)
	void Restart();

	UFUNCTION(BlueprintCallable)
	void Quit();
};
