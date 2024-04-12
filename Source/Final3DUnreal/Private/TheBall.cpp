// Fill out your copyright notice in the Description page of Project Settings.


#include "TheBall.h"

ATheBall::ATheBall()
{
	PrimaryActorTick.bCanEverTick = true;
	InitializeComponents();
	InitializeVariables();
}

void ATheBall::InitializeComponents()
{
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	BallMesh->SetupAttachment(RootComponent);
	RollingBallSFX = CreateDefaultSubobject<UAudioComponent>(TEXT("RollingSound"));
	RollingBallSFX->SetupAttachment(BallMesh);
}

void ATheBall::InitializeVariables()
{
	DidSoundPlay = false;
	DidBallFall = false;

	RollingVolumeMultiplier = 0.0f;
	BallSize = 0.3f;
}

void ATheBall::BeginPlay()
{
	Super::BeginPlay();
	BallMesh->SetRelativeScale3D(FVector(BallSize, BallSize, BallSize));
	BallMesh->SetMaterial(0,BallMaterial);
	BallMesh->SetSimulatePhysics(true);
}

void ATheBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/*if (GetVelocity().Y > 0 || GetVelocity().X > 0)
	{
		RollingVolumeMultiplier = (GetVelocity().Y + GetVelocity().X) * 0.05f;
		RollingBallSFX->SetVolumeMultiplier(RollingVolumeMultiplier);
	}
	else if (GetVelocity().Y < 0 || GetVelocity().X < 0)
	{
		RollingVolumeMultiplier = ((GetVelocity().Y + GetVelocity().X) * -1) * 0.05f;
		RollingBallSFX->SetVolumeMultiplier(RollingVolumeMultiplier);
	}*/

	UE_LOG(LogTemp, Warning, TEXT("%f"), GetVelocity().Y);

	if (GetVelocity() != FVector(0,0,0))
	{
		float yVolume;
		float xVolume;
		if (GetVelocity().Y < 0)
		{
			yVolume = GetVelocity().Y * -1;
		}
		else
		{
			yVolume = GetVelocity().Y;
		}
		if (GetVelocity().X < 0)
		{
			xVolume = GetVelocity().X * -1;
		}
		else
		{
			xVolume = GetVelocity().X;
		}
			
		RollingVolumeMultiplier = (xVolume + yVolume) * 0.005f;
		RollingBallSFX->SetVolumeMultiplier(RollingVolumeMultiplier);
		RollingBallSFX->SetPitchMultiplier(RollingVolumeMultiplier*-2);
		if (!RollingBallSFX->IsPlaying())
		{
			RollingBallSFX->Play();
			UE_LOG(LogTemp, Warning, TEXT("Playing Sound!"));
		}
	}
}

