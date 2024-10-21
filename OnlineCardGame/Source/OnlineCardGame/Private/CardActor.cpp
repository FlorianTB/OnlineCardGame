// Fill out your copyright notice in the Description page of Project Settings.


#include "CardActor.h"

// Sets default values
ACardActor::ACardActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

void ACardActor::SetCardInfo(const FCardInfo& NewCardInfo)
{
	CardInfo = NewCardInfo;
}

void ACardActor::SetIsVisible(bool isVisible)
{
	IsVisible = isVisible;

	FRotator Rotation = FRotator(0, 0, 0);
	
	if (IsVisible)
		Rotation = FRotator(0, 0, 180);
		
	this->SetActorRotation(Rotation);
}

