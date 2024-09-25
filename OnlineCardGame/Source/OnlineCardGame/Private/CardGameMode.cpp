// Fill out your copyright notice in the Description page of Project Settings.


#include "CardGameMode.h"
#include "OnlinePlayer.h"
#include "Kismet/GameplayStatics.h"

ACardGameMode::ACardGameMode()
{
    InitialHandSize = 5;
}

void ACardGameMode::StartGame()
{
    AOnlinePlayer* Player = Cast<AOnlinePlayer>(UGameplayStatics::GetPlayerPawn(this, 0));
    if (Player)
    {
        UE_LOG(LogTemp, Warning, TEXT("There is a player"));
        
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

void ACardGameMode::AddCard()
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


FCardInfo ACardGameMode::GetRandomCardInfo()
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
