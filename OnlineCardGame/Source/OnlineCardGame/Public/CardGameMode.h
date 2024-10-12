// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardActor.h"
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

UPROPERTY(EditDefaultsOnly, Category = "Card")
	TSubclassOf<ACardActor> CardActorClass;

	UPROPERTY(EditDefaultsOnly, Category = "Game Rules")
	int32 InitialHandSize;

	UFUNCTION(BlueprintCallable, Category = "Game")
	void StartGame();

	UFUNCTION(BlueprintCallable, Category = "Game")
	void AddCard();

	UFUNCTION(BlueprintCallable, Category = "Gameplay")
	void PlaceCardOnBoard(ACell* Cell, UCard* Card);

private:
	FCardInfo GetRandomCardInfo();
};
