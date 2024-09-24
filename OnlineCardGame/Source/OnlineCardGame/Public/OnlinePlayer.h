// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Card.h"
#include "Components/WidgetComponent.h"
#include "Camera/CameraComponent.h"
#include "OnlinePlayer.generated.h"

UCLASS()
class ONLINECARDGAME_API AOnlinePlayer : public APawn
{
	GENERATED_BODY()

public:
	AOnlinePlayer();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TArray<UCard*> Hand;

	UPROPERTY(EditDefaultsOnly, Category = "Card UI")
	TSubclassOf<UUserWidget> CardWidgetClass;

	UPROPERTY(VisibleAnywhere, Category = "Card UI")
	TArray<UWidgetComponent*> CardWidgets;

	UFUNCTION(BlueprintCallable)
	void AddCardToHand(UCard* Card);

	UFUNCTION(BlueprintCallable)
	void PlayCard(UCard* Card);

	UFUNCTION(BlueprintCallable)
	void DisplayHand();

private:
	void UpdateCardWidgets();
};
