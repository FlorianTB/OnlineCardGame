// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardInfo.h"
#include "UObject/NoExportTypes.h"
#include "Card.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class ONLINECARDGAME_API UCard : public UObject
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FCardInfo CardInfo;
};
