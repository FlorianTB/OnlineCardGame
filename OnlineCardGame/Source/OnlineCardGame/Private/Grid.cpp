// Fill out your copyright notice in the Description page of Project Settings.


#include "Grid.h"

#include "Cell.h"

class UCard;

AGrid::AGrid()
{
    PrimaryActorTick.bCanEverTick = false;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));

    OnGridInitialized.Clear();
}

void AGrid::GenerateGrid()
{
    for (const auto& Cell : GridCells)
    {
        Cell->Destroy();
    }
    GridCells.Empty();

    for (int32 X = 0; X < Width; ++X)
    {
        for (int32 Y = 0; Y < Height; ++Y)
        {
            FVector SpawnLocation = GetWorldPositionFromGridPosition(X, Y);
            FActorSpawnParameters SpawnParams;
            FRotator SpawnRotation = FRotator(0, 0, 0);
            ACell* newCell = GetWorld()->SpawnActor<ACell>(cellBP->GeneratedClass, SpawnLocation, SpawnRotation, SpawnParams);
            newCell->AttachToActor(this, FAttachmentTransformRules::SnapToTargetIncludingScale);
            newCell->SetActorLocation(SpawnLocation);
            newCell->X = X;
            newCell->Y = Y;
#if WITH_EDITOR
            newCell->SetActorLabel(FString::Printf(TEXT("Cell%d_%d"), static_cast<int>(X), static_cast<int>(Y)));
#endif
            newCell->SetActorScale3D(FVector(1, 1, 1));
            GridCells.Add((newCell));
        }
    }

    this->SetActorLocation(FVector((-Width * CellSize - CellSize) / 2, (-Height * CellSize - CellSize) / 2, 0));

    if (OnGridInitialized.IsBound())
        OnGridInitialized.Broadcast();
}

FVector AGrid::GetWorldPositionFromGridPosition(int32 X, int32 Y) const
{
    return GetActorLocation() + FVector(X * CellSize + CellSize, Y * CellSize + CellSize, 0.0f);
}

void AGrid::GetGridPositionFromWorldPosition(const FVector& WorldPosition, int32& OutX, int32& OutY) const
{
    FVector LocalPosition = WorldPosition - GetActorLocation();
    OutX = FMath::FloorToInt(LocalPosition.X / CellSize);
    OutY = FMath::FloorToInt(LocalPosition.Y / CellSize);
}

bool AGrid::IsValidGridPosition(int32 X, int32 Y) const
{
    return X >= 0 && X < Width && Y >= 0 && Y < Height;
}

void AGrid::SelectCell(ACell* SelectedCell)
{
    UE_LOG(LogTemp, Warning, TEXT("SelectCell"));
    
    SelectedCells.AddUnique(SelectedCell);

    if (SelectedCells.Num() == 2)
        SwapSelecetedCellsCards();
}

void AGrid::SwapSelecetedCellsCards()
{
    TArray<ACardActor*> FirstCellCards = SelectedCells[0]->Cards;
    TArray<ACardActor*> SecondsCellCards = SelectedCells[1]->Cards;

    SelectedCells[0]->Cards = FirstCellCards;
    SelectedCells[0]->UpdateCardsPosition();
    
    SelectedCells[1]->Cards = SecondsCellCards;
    SelectedCells[1]->UpdateCardsPosition();

    SelectedCells.Empty();
}



