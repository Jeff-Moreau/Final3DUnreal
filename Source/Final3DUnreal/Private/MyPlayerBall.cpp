// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerBall.h"

// Sets default values
AMyPlayerBall::AMyPlayerBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	didSoundPlay = false;
	isBallFalling = false;
	RollingVolumeMultiplier = 0.0f;
	//RollingBallTest = CreateDefaultSubobject<UAudioComponent>(TEXT("RollingBallSound"));
}

// Called when the game starts or when spawned
void AMyPlayerBall::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyPlayerBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (GetVelocity().Z < -100)
	{
		isBallFalling = true;
	}

	if (GetVelocity().Y < 0)
	{
		RollingVolumeMultiplier = (GetVelocity().Y * -1) * 0.05f;
	}
	else if (GetVelocity().Y > 0)
	{
		RollingVolumeMultiplier = GetVelocity().Y * 0.05f;
	}

	
}