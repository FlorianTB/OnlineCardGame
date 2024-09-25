// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlinePlayerController.h"

void AOnlinePlayerController::BeginPlay()
{
	Super::BeginPlay();

	if (IsLocalController())
	{
		ClientCreateAndAddCardHandHUD();
	}
}

void AOnlinePlayerController::ClientCreateAndAddCardHandHUD_Implementation()
{
	if (CardHandHUD == nullptr)
	{
		CardHandHUD = CreateWidget<UCardHandWidgetHUD>(this, CardHandWidgetHUDClass);
		if (CardHandHUD)
		{
			UE_LOG(LogTemp, Warning, TEXT("CardHandHUD added to viewport"));
			CardHandHUD->AddToViewport();
			ServerNotifyHUDCreated();
		}
	}
}

void AOnlinePlayerController::ServerNotifyHUDCreated_Implementation()
{
	// Le HUD a été créé côté client, vous pouvez effectuer des actions supplémentaires si nécessaire
}

bool AOnlinePlayerController::ServerNotifyHUDCreated_Validate()
{
	return true;
}

UCardHandWidget* AOnlinePlayerController::GetCardHand() const
{
	return CardHandHUD ? CardHandHUD->CardHand : nullptr;
}