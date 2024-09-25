// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardHandWidget.h"
#include "Blueprint/UserWidget.h"
#include "CardHandWidgetHUD.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECARDGAME_API UCardHandWidgetHUD : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CardHandWidget")
	UCardHandWidget* CardHand;

	UFUNCTION(BlueprintCallable)
	void SetCardHandWidget(UCardHandWidget* InCardHand);
};
