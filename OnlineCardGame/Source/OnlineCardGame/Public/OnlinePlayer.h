// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Card.h"
#include "CardHandWidget.h"
#include "CardWidget.h"
#include "OnlinePlayer.generated.h"

UCLASS()
class ONLINECARDGAME_API AOnlinePlayer : public APawn
{
	GENERATED_BODY()

public:
	AOnlinePlayer();

	virtual void BeginPlay() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UCard*> Hand;
	
	UFUNCTION(BlueprintCallable, Category = "Card Game")
	UCardHandWidget* GetCardHand() const;

	UFUNCTION(BlueprintCallable)
	void AddCardToHand(UCard* Card);

	UFUNCTION(BlueprintCallable)
	void PlayCards();
};
