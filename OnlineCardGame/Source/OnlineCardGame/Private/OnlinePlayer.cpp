// Fill out your copyright notice in the Description page of Project Settings.


#include "OnlinePlayer.h"
#include "Components/WidgetComponent.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/KismetSystemLibrary.h"

AOnlinePlayer::AOnlinePlayer()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AOnlinePlayer::AddCardToHand(UCard* Card)
{
	Hand.Add(Card);
	UpdateCardWidgets();
}

void AOnlinePlayer::PlayCard(UCard* Card)
{
	Hand.Remove(Card);
	UpdateCardWidgets();
	// Logique supplémentaire pour jouer la carte
}

void AOnlinePlayer::DisplayHand()
{
	UpdateCardWidgets();
}

void AOnlinePlayer::UpdateCardWidgets()
{
	// Supprimer les anciens widgets de cartes
	for (UWidgetComponent* Widget : CardWidgets)
	{
		Widget->DestroyComponent();
	}
	CardWidgets.Empty();

	// Créer de nouveaux widgets de cartes
	for (UCard* Card : Hand)
	{
		UUserWidget* CardWidget = CreateWidget<UUserWidget>(GetWorld(), CardWidgetClass);
		
		if (CardWidget)
		{
			UWidgetComponent* WidgetComponent = NewObject<UWidgetComponent>(this);
			WidgetComponent->SetWidget(CardWidget);
			WidgetComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
			WidgetComponent->RegisterComponent();
			CardWidgets.Add(WidgetComponent);
			
			UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Created card widget: %s"), *CardWidget->GetName()));
		}
	}
}

