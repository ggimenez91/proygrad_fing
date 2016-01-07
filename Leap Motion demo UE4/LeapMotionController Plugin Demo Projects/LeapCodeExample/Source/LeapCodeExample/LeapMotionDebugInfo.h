// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "LeapMotionDebugInfo.generated.h"

/**
 *
 */
UCLASS()
class LEAPCODEEXAMPLE_API ALeapMotionDebugInfo : public AActor 
{
	GENERATED_BODY()

	ALeapMotionDebugInfo(const FObjectInitializer& ObjectInitializer);

	virtual void Tick(float DeltaTime);
};
