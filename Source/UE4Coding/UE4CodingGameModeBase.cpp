// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4CodingGameModeBase.h"

void AUE4CodingGameModeBase::StartPlay()
{
	Super::StartPlay();

	UFloatProperty* FloatProp = FindField<UFloatProperty>(this->GetClass(), TEXT("BpFloat"));
	if (FloatProp != nullptr)
	{
		float FloatValue = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Float equals - %f"), FloatValue);

		FloatProp->SetPropertyValue_InContainer(this, 48.0f);

		FloatValue = FloatProp->GetPropertyValue_InContainer(this);
		UE_LOG(LogTemp, Warning, TEXT("Float equals - %f"), FloatValue);

	}
}