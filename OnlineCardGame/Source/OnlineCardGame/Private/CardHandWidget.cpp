// Fill out your copyright notice in the Description page of Project Settings.


#include "CardHandWidget.h"

UCardHandWidget::UCardHandWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OnCardAdded.Clear();
	OnCardPlayed.Clear();
}

void UCardHandWidget::AddCard(FCardInfo NewCard)
{
	if (!IsValid(this))
	{
		UE_LOG(LogTemp, Error, TEXT("CardHandWidget is not valid"));
		return;
	}
	
	UE_LOG(LogTemp, Warning, TEXT("AddCard"));
	
	if (OnCardAdded.IsBound())
	{
		OnCardAdded.Broadcast(NewCard);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnCardAdded is not bound to any functions"));
	}
}

void UCardHandWidget::PlayCard(UCardWidget* PlayedCard)
{
	UE_LOG(LogTemp, Warning, TEXT("CardHandWidget::PlayCard called with %s"), *PlayedCard->GetName());

	if (OnCardPlayed.IsBound())
	{
		OnCardPlayed.Broadcast(PlayedCard);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnCardPlayed is not bound"));
	}
}

void UCardHandWidget::MergeCards(UCardWidget* FirstMergedCard, UCardWidget* SecondMergedCard, FCardInfo NewCard)
{
	UE_LOG(LogTemp, Warning, TEXT("MergedCards"));

	if (OnCardsMerged.IsBound())
	{
		OnCardsMerged.Broadcast(FirstMergedCard, SecondMergedCard);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnCardsMerged is not bound"));
	}

	AddCard(NewCard);
}
