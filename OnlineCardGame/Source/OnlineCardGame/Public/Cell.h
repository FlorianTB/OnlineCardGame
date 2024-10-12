// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardActor.h"
#include "GameFramework/Actor.h"
#include "Cell.generated.h"

UCLASS()
class ONLINECARDGAME_API ACell : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACell();

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 X;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Y;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cards")
    TArray<ACardActor*> Cards;
};
