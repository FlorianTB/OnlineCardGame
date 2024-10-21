// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Grid.generated.h"

UCLASS()
class ONLINECARDGAME_API AGrid : public AActor
{
	GENERATED_BODY()

public:
	AGrid();

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Width = 10;

	UPROPERTY(EditAnywhere, Category = "Grid")
	int32 Height = 10;

	UPROPERTY(EditAnywhere, Category = "Grid")
	float CellSize = 100.0f;
    
	UFUNCTION(CallInEditor, Category = "Grid")
	void GenerateGrid();

	UFUNCTION(BlueprintCallable, Category = "Grid")
	FVector GetWorldPositionFromGridPosition(int32 X, int32 Y) const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	void GetGridPositionFromWorldPosition(const FVector& WorldPosition, int32& OutX, int32& OutY) const;

	UFUNCTION(BlueprintCallable, Category = "Grid")
	bool IsValidGridPosition(int32 X, int32 Y) const;
	
	UPROPERTY(EditAnywhere, Category = "Grid")
    UBlueprint* cellBP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Grid")
	TArray<ACell*> GridCells;

	UPROPERTY(BlueprintReadOnly, Category = "Cell")
	TArray<ACell*> SelectedCells;
	
	UFUNCTION(BlueprintCallable, Category = "Cell")
    void SelectCell(ACell* SelectedCell);
    
    UFUNCTION(BlueprintCallable, Category = "Cell")
    void SwapSelectedCellsCards();
};
