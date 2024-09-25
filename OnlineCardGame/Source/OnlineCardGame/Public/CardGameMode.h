// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CardInfo.h"
#include "CardGameMode.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECARDGAME_API ACardGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ACardGameMode();

	UPROPERTY(EditDefaultsOnly, Category = "Data")
	UDataTable* CardDataTable;

	UPROPERTY(EditDefaultsOnly, Category = "Game Rules")
	int32 InitialHandSize;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddCard();

private:
	FCardInfo GetRandomCardInfo();
};
