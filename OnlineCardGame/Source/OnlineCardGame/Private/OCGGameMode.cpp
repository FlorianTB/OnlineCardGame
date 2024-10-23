// Fill out your copyright notice in the Description page of Project Settings.


#include "OCGGameMode.h"

#include "Cell.h"
#include "OnlinePlayer.h"
#include "Kismet/GameplayStatics.h"


AOCGGameMode::AOCGGameMode()
{
    
}

void AOCGGameMode::StartGame()
{
    AOnlinePlayer* Player = Cast<AOnlinePlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
    if (Player)
    {
        UE_LOG(LogTemp, Warning, TEXT("There is a player"));

        FVector Position = FVector(0, 0, 0);
        FRotator Rotation = FRotator(0, 0, 0);

        Player->SetActorLocation(Position);
        Player->SetActorRotation(Rotation);
        
        for (int32 i = 0; i < InitialHandSize; ++i)
        {
            UCard* NewCard = NewObject<UCard>();
            FCardInfo RandomCard = GetRandomCardInfo();
            NewCard->CardInfo = RandomCard;
            Player->AddCardToHand(NewCard);
        }
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("There is no player"));
    }
}

void AOCGGameMode::AddCard()
{
    AOnlinePlayer* Player = Cast<AOnlinePlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
    if (Player)
    {
        UE_LOG(LogTemp, Warning, TEXT("There is a player"));
        
        UCard* NewCard = NewObject<UCard>();
        FCardInfo RandomCard = GetRandomCardInfo();
        NewCard->CardInfo = RandomCard;
        Player->AddCardToHand(NewCard);
    }
    else
    {
        UE_LOG(LogTemp, Warning, TEXT("There is no player"));
    }
}

FCardInfo AOCGGameMode::GetRandomCardInfo()
{
    FCardInfo RandomCard;

    if (CardDataTable)
    {
        TArray<FCardInfo*> AllCards;
        CardDataTable->GetAllRows<FCardInfo>("", AllCards);

        if (AllCards.Num() > 0)
        {
            int32 RandomIndex = FMath::RandRange(0, AllCards.Num() - 1);
            RandomCard = *AllCards[RandomIndex];
        }
        else
        {
            UE_LOG(LogTemp, Warning, TEXT("DataTable empty"));
        }
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("DataTable empty"));
    }

    return RandomCard;
}

void AOCGGameMode::PlaceCardOnBoard(ACell* Cell, UCard* Card)
{
    ACardActor* CardActor = GetWorld()->SpawnActor<ACardActor>(CardActorClass);
    if (CardActor)
    {
        CardActor->SetCardInfo(Card->CardInfo);

        int CardsOnCellCount = Cell->Cards.Num();
        
        CardActor->AttachToActor(Cell, FAttachmentTransformRules::KeepRelativeTransform);
        
        FVector Position = Cell->GetActorLocation() + FVector::UpVector + (CardsOnCellCount * FVector::UpVector);
        CardActor->SetActorLocation(Position);

        Cell->Cards.AddUnique(CardActor);
    }
}