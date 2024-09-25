// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CardInfo.h"
#include "Blueprint/UserWidget.h"
#include "CardHandWidget.generated.h"

/**
 * 
 */
UCLASS()
class ONLINECARDGAME_API UCardHandWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCardAddedSignature, const FCardInfo&, NewCard);

	UCardHandWidget(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(BlueprintAssignable, Category = "Card")
	FOnCardAddedSignature OnCardAdded;

	UFUNCTION(BlueprintCallable, Category = "Card Operations")
	void AddCard(FCardInfo NewCard);
};
