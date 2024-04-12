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
}

void ATheBall::InitializeVariables()
{
	DidSoundPlay = false;
	DidBallFall = false;

	RollingVolumeMultiplier = 0.0f;
}

void ATheBall::BeginPlay()
{
	Super::BeginPlay();
	BallMesh->SetRelativeScale3D(FVector(0.2, 0.2, 0.2));
	BallMesh->SetMaterial(0,BallMaterial);
	BallMesh->SetSimulatePhysics(true);
}

void ATheBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

