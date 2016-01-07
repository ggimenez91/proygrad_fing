// Fill out your copyright notice in the Description page of Project Settings.

#include "LeapCodeExample.h"
#include "LeapMotionControllerPlugin.h"
#include "LeapMotionDevice.h"
#include "Leap.h"
#include "LeapMotionTypes.h"
#include "Engine.h"
#include "LeapMotionDebugInfo.h"


ALeapMotionDebugInfo::ALeapMotionDebugInfo(const class FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;

}

void ALeapMotionDebugInfo::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FLeapMotionDevice* Device = FLeapMotionControllerPlugin::GetLeapDeviceSafe();

	GEngine->ClearOnScreenDebugMessages();

	if (Device && Device->IsConnected())
	{
		Device->SetReferenceFrameOncePerTick();
		Leap::Frame frame = Device->Frame();

		for (Leap::Hand hand : frame.hands())
		{
			for (Leap::Finger finger : hand.fingers()){
				FString fingerLabel = FString::Printf(TEXT("        Finger %u: "), finger.id());
				fingerLabel += finger.tipPosition().toString().c_str();
				GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, fingerLabel);
			}

			FString handLabel = FString::Printf(TEXT("    Hand %u: "), hand.id());
			handLabel += hand.palmPosition().toString().c_str();
			GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, handLabel);
		}

		FString leapLabel = FString::Printf(TEXT("LeapController - Frame: %u"), frame.id());
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, leapLabel);
	}
	else{
		GEngine->AddOnScreenDebugMessage(-1, 0.5f, FColor::Green, FString(TEXT("LeapController - No Data")));
	}
}