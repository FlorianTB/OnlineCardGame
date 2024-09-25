// Fill out your copyright notice in the Description page of Project Settings.


#include "CardHandWidget.h"

UCardHandWidget::UCardHandWidget(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	OnCardAdded.Clear();
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
		UE_LOG(LogTemp, Warning, TEXT("About to broadcast OnCardAdded"));
		OnCardAdded.Broadcast(NewCard);
		UE_LOG(LogTemp, Warning, TEXT("OnCardAdded broadcasted"));
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnCardAdded is not bound to any functions"));
	}
}
