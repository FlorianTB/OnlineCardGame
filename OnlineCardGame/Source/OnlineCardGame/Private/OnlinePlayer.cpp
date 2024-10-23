// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlinePlayer.h"

#include "CardGameMode.h"
#include "CardHandWidget.h"
#include "CardWidget.h"
#include "OCGGameMode.h"
#include "OnlinePlayerController.h"

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

void AOnlinePlayer::PlayCards(ACell* Cell)
{
	for (UCardWidget* CardWidget : GetCardHand()->SelectedCards)
	{
		for (UCard* Card : Hand)
		{
			if(Card->CardInfo.Type == CardWidget->CardInfo.Type)
			{
				UE_LOG(LogTemp, Warning, TEXT("Play card %s"), *CardWidget->CardInfo.CardName);
				Hand.Remove(Card);

				AOCGGameMode* GameMode = Cast<AOCGGameMode>(GetWorld()->GetAuthGameMode());
				if (GameMode)
				{
					GameMode->PlaceCardOnBoard(Cell, Card);
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

