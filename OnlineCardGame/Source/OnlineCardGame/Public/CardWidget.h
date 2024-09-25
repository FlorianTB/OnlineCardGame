// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardInfo.h"
#include "CardWidget.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECARDGAME_API UCardWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Card Data")
	FCardInfo CardInfo;

	UFUNCTION(BlueprintCallable, Category = "Card Data")
	void SetCardInfo(const FCardInfo& NewCardInfo);
};
