// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlinePlayer.h"

#include "CardHandWidget.h"
#include "CardWidget.h"
#include "OnlinePlayerController.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetSystemLibrary.h"

class AOnlinePlayerController;
class UCardWidget;

AOnlinePlayer::AOnlinePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AOnlinePlayer::BeginPlay()
{
	Super::BeginPlay();
}

void AOnlinePlayer::AddCardToHand(UCard* Card)
{
	if(!IsValid(Card))
		return;
	
	Hand.Add(Card);

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Card->CardInfo.CardName);
	GetCardHand()->AddCard(Card->CardInfo);
}

void AOnlinePlayer::PlayCard(UCard* Card)
{
	Hand.Remove(Card);
	// Logique supplémentaire pour jouer la carte
}

UCardHandWidget* AOnlinePlayer::GetCardHand() const
{
	AOnlinePlayerController* OPC = Cast<AOnlinePlayerController>(GetController());
	if (!OPC)
	{
		UE_LOG(LogTemp, Error, TEXT("Invalid PlayerController"));
		return nullptr;
	}
    
	UCardHandWidget* Widget = OPC->GetCardHand();
	if (!Widget)
	{
		UE_LOG(LogTemp, Error, TEXT("CardHandWidget is null"));
	}
	return Widget;
}

