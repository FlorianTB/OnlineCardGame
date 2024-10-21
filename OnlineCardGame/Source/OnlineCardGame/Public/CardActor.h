// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardInfo.h"
#include "GameFramework/Actor.h"
#include "CardActor.generated.h"

UCLASS()
class ONLINECARDGAME_API ACardActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ACardActor();

public:
	UPROPERTY(BlueprintReadWrite, Category = "Card Data")
	FCardInfo CardInfo;

	UFUNCTION(BlueprintCallable, Category = "Card Data")
	void SetCardInfo(const FCardInfo& NewCardInfo);

	UFUNCTION(BlueprintCallable, Category = "Card Data")
	void SetIsVisible(bool isVisible);
	
	UPROPERTY(BlueprintReadOnly, Category = "Card Data")
	bool IsVisible;
};
