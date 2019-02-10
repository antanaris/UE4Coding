// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CodingGameModeBase.h"
#include "ConstructorHelpers.h"

AUE4CodingGameModeBase::AUE4CodingGameModeBase()
{
	// Finding RandomNumber blueprint
	// My Blueprint reference: Blueprint'/Game/PZ1/BP_RandomNumber.BP_RandomNumber'
	static ConstructorHelpers::FClassFinder<AActor> RandomNumberBPClassFinder(TEXT("'/Game/PZ1/BP_RandomNumber'"));
	if (RandomNumberBPClassFinder.Class != nullptr)
	{
		RandomNumberBPClass = RandomNumberBPClassFinder.Class;
	}
}

void AUE4CodingGameModeBase::StartPlay()
{
	Super::StartPlay();

	// Showing if this GameMode is active
	UE_LOG(LogTemp, Warning, TEXT("Starting EU4Coding GameMode"));

	// *** ог 1 ***
	// 
	// accessing and changing a blueprint variable


	// Getting  a reference to blueprint integer RandomNumber variable
	UIntProperty* RandomNumber = FindField<UIntProperty>(RandomNumberBPClass, TEXT("RandomNumber"));
	if (RandomNumber != nullptr)
	{
		// Getting variable value and printing it
		int32 RandomValue = RandomNumber->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Random Number is - %i"), RandomValue);

		// Setting a new value and printing it
		RandomNumber->SetPropertyValue_InContainer(this, 4);

		RandomValue = RandomNumber->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Set Random Number is - %i"), RandomValue);

	} else {
		// if the variable is not fount, give us a warning
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find the RandomNumber blueprint variable :("));
	}
}