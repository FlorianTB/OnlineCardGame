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
	DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnCellSelectedSignature, ACell*, SelectedCell);
	
	// Sets default values for this actor's properties
	ACell();

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 X;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Y;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Cards")
    TArray<ACardActor*> Cards;

	UPROPERTY(BlueprintAssignable, Category = "Cell")
	FOnCellSelectedSignature OnCellSelected;

	UFUNCTION(BlueprintCallable, Category = "Cell")
	void SelectCell(ACell* Cell);

	UFUNCTION(BlueprintCallable, Category = "Cell")
    void UpdateCardsPosition();
};
