// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardHandWidgetHUD.h"
#include "GameFramework/PlayerController.h"
#include "OnlinePlayerController.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECARDGAME_API AOnlinePlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	
	UPROPERTY(EditDefaultsOnly, Category = "Card UI")
	TSubclassOf<UCardHandWidgetHUD> CardHandWidgetHUDClass;

	UPROPERTY()
	UCardHandWidgetHUD* CardHandHUD;

	UFUNCTION(Client, Reliable)
	void ClientCreateAndAddCardHandHUD();

	UFUNCTION(Server, Reliable, WithValidation)
	void ServerNotifyHUDCreated();

	// Fonction pour obtenir le UCardHand
	UFUNCTION(BlueprintCallable, Category = "Card Game")
	UCardHandWidget* GetCardHand() const;
};
