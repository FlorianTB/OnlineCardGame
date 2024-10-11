// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlinePlayer.h"

#include "CardGameMode.h"
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

	AOnlinePlayerController* OPC = Cast<AOnlinePlayerController>(GetController());

	if(OPC)
		OPC->OnlinePlayer = this;
}

void AOnlinePlayer::AddCardToHand(UCard* Card)
{
	if(!IsValid(Card))
		return;
	
	Hand.Add(Card);

	//UE_LOG(LogTemp, Warning, TEXT("%s"), *Card->CardInfo.CardName);
	GetCardHand()->AddCard(Card->CardInfo);
}

void AOnlinePlayer::PlayCards()
{
	for (UCardWidget* CardWidget : GetCardHand()->SelectedCards)
	{
		for (UCard* Card : Hand)
		{
			UE_LOG(LogTemp, Warning, TEXT("Card %s / Card %s"), *Card->CardInfo.Type, *CardWidget->CardInfo.Type);
		
			if(Card->CardInfo.Type == CardWidget->CardInfo.Type)
			{
				UE_LOG(LogTemp, Warning, TEXT("Play card %s"), *CardWidget->CardInfo.CardName);
				Hand.Remove(Card);

				ACardGameMode* GameMode = Cast<ACardGameMode>(GetWorld()->GetAuthGameMode());
				if (GameMode)
				{
					GameMode->PlaceCardOnBoard(Card);
				}
				break;
			}
		}
	}
		
	GetCardHand()->PlayCards();
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

