// Fill out your copyright notice in the Description page of Project Settings.


#include "Cell.h"

// Sets default values
ACell::ACell()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	OnCellSelected.Clear();
}

void ACell::SelectCell(ACell* Cell)
{
	if (OnCellSelected.IsBound())
	{
        UE_LOG(LogTemp, Warning, TEXT("OnCellSelected is bound"));
		OnCellSelected.Broadcast(Cell);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("OnCellSelected not bound"));
	}
}

void ACell::UpdateCardsPosition()
{
	for (ACardActor* Card : Cards)
	{
        Card->DetachFromActor(FDetachmentTransformRules::KeepWorldTransform);
		Card->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
		
		FVector Position = FVector(this->GetActorLocation().X, this->GetActorLocation().Y, Card->GetActorLocation().Z);
		Card->SetActorLocation(Position);
	}
}

void ACell::SetCardsVisible()
{
	int VisibleCardCount = 0;
	int InvisibleCardCount = 0;

	for (ACardActor* Card : Cards)
	{
		if (Card->IsVisible)
			VisibleCardCount++;
		else
			InvisibleCardCount++;
	}
	
	for (int i = Cards.Num() - 1; i >= 0; i--)
	{
		if (!Cards[i]->IsVisible)
		{
			Cards[i]->SetIsVisible(true);
			FVector Position = GetActorLocation() + FVector::UpVector + (VisibleCardCount * FVector::UpVector);
			InvisibleCardCount--;
			VisibleCardCount++;
		}
	}

	Cards.Sort([](const ACardActor& A, const ACardActor& B) {
		return A.GetActorLocation().Z < B.GetActorLocation().Z;
	});
}

