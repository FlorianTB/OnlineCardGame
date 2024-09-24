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
        for (int32 i = 0; i < InitialHandSize; ++i)
        {
            UCard* NewCard = NewObject<UCard>();
            NewCard->CardName = FString::Printf(TEXT("Card %d"), i + 1);
            Player->AddCardToHand(NewCard);
        }
        Player->DisplayHand();
    }
}
