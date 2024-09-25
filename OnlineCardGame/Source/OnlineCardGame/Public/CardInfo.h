// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "CardInfo.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCardInfo : public FTableRowBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FString CardName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FLinearColor BackgroundColor;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int Damage;
};
