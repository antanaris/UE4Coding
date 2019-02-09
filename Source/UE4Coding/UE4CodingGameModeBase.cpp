// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CodingGameModeBase.h"
#include "ConstructorHelpers.h"

void AUE4CodingGameModeBase::StartPlay()
{
	Super::StartPlay();

	// Showing if this GameMode is active
	UE_LOG(LogTemp, Warning, TEXT("Starting EU4Coding GameMode"));

	// *** ог 1 ***
	// 
	// accessing and changing a blueprint variable


	// Finding RandomNumber blueprint
	// My Blueprint reference: Blueprint'/Game/PZ1/BP_RandomNumber.BP_RandomNumber'
	ConstructorHelpers::FObjectFinder<UBlueprint> BlueprintObj(TEXT("Blueprint'/Game/PZ1/BP_RandomNumber.BP_RandomNumber'"));

	UBlueprint* blueprint = NULL;
	if (BlueprintObj.Succeeded()) {
		blueprint = BlueprintObj.Object;
		// if the blueprint is fount, congratulate
		UE_LOG(LogTemp, Warning, TEXT("The RandomNumber blueprint was found!"));
	} else {
		// if the blueprint is not fount, give us a warning
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find the RandomNumber blueprint :("));
	}


	// Getting  a reference to blueprint integer RandomNumber variable
	UIntProperty* RandomNumber = FindField<UIntProperty>(this->GetClass(), TEXT("RandomNumber"));
	if (RandomNumber != nullptr)
	{
		// Getting variable value and printing it
		int32 RandomValue = RandomNumber->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Random Number is - %i"), RandomValue);

		// Setting a new value and printing it
		RandomNumber->SetPropertyValue_InContainer(this, 48);

		RandomValue = RandomNumber->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Set Random Number is - %i"), RandomValue);

	} else {
		// if the variable is not fount, give us a warning
		UE_LOG(LogTemp, Warning, TEXT("Couldn't find the RandomNumber blueprint variable :("));
	}
}