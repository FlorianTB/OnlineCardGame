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

void AOnlinePlayer::PlayCard(UCardWidget* CardWidget)
{
	UE_LOG(LogTemp, Warning, TEXT("Card : %d"), CardWidget->CardInfo.Damage);
	
	for (UCard* Card : Hand)
	{
		UE_LOG(LogTemp, Warning, TEXT("Card %d / Card %d"), Card->CardInfo.Damage, CardWidget->CardInfo.Damage);
		
		if(Card->CardInfo.Damage == CardWidget->CardInfo.Damage)
		{
			UE_LOG(LogTemp, Warning, TEXT("Play card %s"), *CardWidget->CardInfo.CardName);
			Hand.Remove(Card);
			UCardHandWidget* CardHand = GetCardHand();
			if (CardHand)
			{
				CardHand->PlayCard(CardWidget);
			}
			else
			{
				UE_LOG(LogTemp, Error, TEXT("CardHand is null in AOnlinePlayer::PlayCard"));
			}
			return;
		}
	}
}

void AOnlinePlayer::MergeCards(TArray<UCardWidget*> MergedCards)
{
	UE_LOG(LogTemp, Warning, TEXT("[OnlinePlayer] MergeCards"));

	UCard* NewCard = NewObject<UCard>();
	NewCard->CardInfo.CardName = "MergedCard";
	NewCard->CardInfo.BackgroundColor = FColor::Black;
	
	for (UCardWidget* MergedCard : MergedCards)
	{
		NewCard->CardInfo.Damage += MergedCard->CardInfo.Damage;

		for (UCard* c : Hand)
		{
			if(c->CardInfo.Damage == MergedCard->CardInfo.Damage)
			{
				Hand.Remove(c);
				break;
			}
		}
	}

	Hand.Add(NewCard);

	UCardHandWidget* CardHand = GetCardHand();
	if (CardHand)
	{
		CardHand->MergeCards(MergedCards[0], MergedCards[1], NewCard->CardInfo);
	}
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

