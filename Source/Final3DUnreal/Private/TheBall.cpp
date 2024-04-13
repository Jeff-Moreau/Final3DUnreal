// Fill out your copyright notice in the Description page of Project Settings.


#include "TheBall.h"

#include "AsyncTreeDifferences.h"
#include "Blueprint/UserWidget.h"

ATheBall::ATheBall()
{
	PrimaryActorTick.bCanEverTick = true;
	InitializeMyComponents();
	InitializeVariables();
}

void ATheBall::InitializeMyComponents()
{
	BallMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball"));
	BallMesh->SetupAttachment(RootComponent);
	RollingBallSFX = CreateDefaultSubobject<UAudioComponent>(TEXT("RollingSound"));
	RollingBallSFX->SetupAttachment(BallMesh);
	DroppedBallSFX = CreateDefaultSubobject<UAudioComponent>(TEXT("DroppedSound"));
	DroppedBallSFX->SetupAttachment(BallMesh);
}

void ATheBall::InitializeVariables()
{
	DidSoundPlay = false;
	DidBallFall = false;
	
	RollingVolumeMultiplier = 0.05f;
	BallSize = 0.3f;
}

void ATheBall::BeginPlay()
{
	Super::BeginPlay();
	
	BallMesh->SetRelativeScale3D(FVector(BallSize, BallSize, BallSize));
	BallMesh->SetMaterial(0,BallMaterial);
	BallMesh->SetSimulatePhysics(true);
}

void ATheBall::PlaySound(UAudioComponent* sound)
{
	if (!sound->IsPlaying())
	{
		sound->Play();
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Sound To Play!"));
	}
}

void ATheBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	UE_LOG(LogTemp, Warning, TEXT("%f"), GetVelocity().Z);
	
	if (BallMoving())
	{
		float YVolume;
		float XVolume;

		if (GetVelocity().Y < 0)
		{
			YVolume = GetVelocity().Y * -1;
		}
		else
		{
			YVolume = GetVelocity().Y;
		}
		
		if (GetVelocity().X < 0)
		{
			XVolume = GetVelocity().X * -1;
		}
		else
		{
			XVolume = GetVelocity().X;
		}
		float const TotalVolume  = (XVolume + YVolume) * RollingVolumeMultiplier;

		RollingBallSFX->SetVolumeMultiplier(TotalVolume);
		RollingBallSFX->SetPitchMultiplier(TotalVolume * -2);
		
		PlaySound(RollingBallSFX);
	}

	if (GetVelocity().Z <= -400)
	{
		DidBallFall = true;
		UE_LOG(LogTemp, Warning, TEXT("I fell"));
	}
}

bool ATheBall::BallMoving() const
{
	return (GetVelocity() != FVector(0,0,0));
}

void ATheBall::PlayDroppedSound()
{
	if (DidBallFall)
	{
		PlaySound(DroppedBallSFX);
		DidBallFall = false;
	}
}